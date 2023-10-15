#include <iostream>
#include <string>
#include <stack>
#include <fstream>

class exc
{
public:
    exc(std::string wr, int i) : wrong{ wr }, index{ i } {}
    std::string wrong;
    int index;
    void get_wrong() { std::cerr << wrong << " " << index << "\n"; }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                                                                                                // проверки выхода за предел
void move_input_iterator_right(std::ofstream& ofs)
{
    ofs << "{\n"
        << "if (input_iterator >= input.end())\n"
        << "{\n"
        << "throw exc(\"OUT OF RANGE INPUT ITERATOR number element of code - \", index);\n"
        << "}\n"
        << "input_iterator++;\n"
        << "}\n";
}

void move_code_pointer_right(std::string::iterator& code_pointer, std::string::iterator end_code_pointer, int i)
{

    if (code_pointer >= end_code_pointer)
    {
        throw exc("code p wrong! number element of code - ", i);
    }
    code_pointer++;
}

void move_code_pointer_left(std::string::iterator& code_pointer, std::string::iterator begin_code_pointer, int i)
{

    if (code_pointer <= begin_code_pointer)
    {
        throw exc("code p wrong! number element of code - ", i);
    }
    code_pointer--;
}

void move_data_pointer_right(std::ofstream& ofs)
{
    ofs << "\n{\n"
        << "if (data_pointer >= &mass[SIZE])\n"
        << "{\n"
        << "throw exc(\"data p wrong! number element of code - \", index);\n"
        << "}\n"
        << "data_pointer++;\n"
        << "}\n\n";
}

void move_data_pointer_left(std::ofstream& ofs)
{
    ofs << "\n{\n"
        << "if (data_pointer <= &mass[0])\n"             // проверка выхода за пределы
        << "{\n"
        << "throw exc(\"data p wrong! number element of code - \",index);\n"
        << "}\n"
        << "else\n"
        << "data_pointer--;\n"
        << "}\n\n";
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int translate(std::string name, std::string& code, std::string input = "")
{
    std::ofstream ofs(name); // файл для вывода 
    /////////////////////////////////////////////////////////////////////////////
    ofs << "#include <iostream>\n"
        << "#include <string>\n"
        << "#include <stack>\n\n";

    ofs << "class exc\n"
        << "{\n"
        << "public:\n"
        << "exc(std::string wr, int i) : wrong{ wr }, index{ i } {}\n"
        << "std::string wrong;\n"                                                                               // создание программы и переменных
        << "int index;\n"
        << "void get_wrong() { std::cerr << wrong << \" \" << index << \"\"; }\n"
        << "};\n";

    ofs << "int main()\n{\n";
    ofs << "std::string code = \"" << code << "\";\n";
    ofs << "std::string input = \"" << input << "\";\n";
    ofs << "auto input_iterator = input.begin();\n";
    ofs << "const int SIZE = 30000;\n";
    ofs << "unsigned char* const mass = new unsigned char[SIZE] {};\n";
    ofs << "unsigned char* data_pointer = &mass[SIZE/2];\n";
    ofs << "std::string res = \"\";\n";
    ofs << "std::stack<int> stack;\n";
    ofs << "int index = 1;\n";
    /////////////////////////////////////////////////////////////////////////////////////////////////////

    std::stack<int> here;  // стек начала цикла, нужен для правильной обработки вложенных циклов
    int i = 2;
    int number = 0;      // номер начала цикла
    auto code_pointer = code.begin();

    while (code_pointer != code.end())
    {
        switch (*code_pointer) // проверка символа кода
        {
        case '+':                       // увеличиваем значение указателя на элемент массива mass на 1
            ofs << "*data_pointer += 1;\n";
            move_code_pointer_right(code_pointer, code.end(), i);
            ofs << "//----------------------------------------------------\n";
            ofs << "\nindex++; " << "// " << i << "\n\n";
            i++;
            break;
        case '-':                       // уменьшаем значение указателя на элемент массива mass на 1
            ofs << "*data_pointer -= 1;\n";
            move_code_pointer_right(code_pointer, code.end(), i);
            ofs << "//----------------------------------------------------\n";
            ofs << "\nindex++; " << "// " << i << "\n\n";
            i++;
            break;
        case '>':                       // перемещаем указатель на элемент враво на 1 массива mass
            move_data_pointer_right(ofs);
            move_code_pointer_right(code_pointer, code.end(), i);
            ofs << "//----------------------------------------------------\n";
            ofs << "\nindex++; " << "// " << i << "\n\n";
            i++;
            break;
        case '<':                     // перемещаем указатель на элемент влево на 1 массива mass
            move_data_pointer_left(ofs);
            move_code_pointer_right(code_pointer, code.end(), i);
            ofs << "//----------------------------------------------------\n";
            ofs << "\nindex++; " << "// " << i << "\n\n";
            i++;
            break;
        case ',':                      // записываем значение элемента с строки input в значение указателя на элемент массива mass 
            ofs << "if (input_iterator == input.end())"
                << "throw exc(\"empty input! number of code element - \");\n";
            ofs << "*data_pointer = *input_iterator;\n";
            move_code_pointer_right(code_pointer, code.end(), i);
            move_input_iterator_right(ofs);
            ofs << "//----------------------------------------------------\n";
            ofs << "\nindex++; " << "// " << i << "\n\n";
            i++;
            break;
        case '.':                   //выводим значение указателя на элемент в res
            ofs << "res.push_back(*data_pointer);\n";
            move_code_pointer_right(code_pointer, code.end(), i);
            ofs << "//----------------------------------------------------\n";
            ofs << "\nindex++; " << "// " << i << "\n\n";
            i++;
            break;
        case '[':
        {
            ofs << "if(*data_pointer != 0)";
            ofs << "{\n";                           // начало цикла
            number++;
            here.push(number);
            ofs << "\nhere" << std::to_string(number) << ":\n";
            ofs << "//----------------------------------------------------\n";
            ofs << "\nindex++; " << "// " << i << "\n\n";
            i++;
            move_code_pointer_right(code_pointer, code.end(), i);
            break;
        }
        case ']':
            if (here.empty())
                throw exc("Not found [", 0);
            ofs << "}\n";                           // конец цикла
            ofs << "if(*data_pointer != 0)\n";
            ofs << "goto here" << here.top() << ";\n"; // прыгаем в начало цикла последнего необратанного цикла
            here.pop();
            ofs << "//----------------------------------------------------\n";
            ofs << "\nindex++; " << "// " << i << "\n\n";
            i++;
            move_code_pointer_right(code_pointer, code.end(), i);
            break;
        default:            // пропускаем все лишние символы
            if(!isspace(*code_pointer))
                throw exc("Invalid Expression", i);
            move_code_pointer_right(code_pointer, code.end(), i);
            i++;
            break;
        }
    }
    if (!here.empty())
        throw exc("Not found " + std::to_string(here.size()) + " ]", i);
    ofs << "delete[] mass;\n";
    ofs << "//std::cout<<res;\n";
    ofs << "return 0;\n"; // заверешение программы
    ofs << "}";
    ofs.close();
    return 1;
}

int main()
{
    std::string code = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++."; // выводит Helo world!
    std::string file_name = "check.cpp";
    //std::string code = "+[-->-[>>+>-----<<]<--<---]>-.>>>+.>>..+++[.>]<<<<.+++.------.<<-.>>>>+."; // выводит Helo world! краткая версия
    try
    {
        std::cout << translate(file_name, code);
    }
    catch (exc& e)
    {
        e.get_wrong();
    }
    catch (...)
    {
        std::cout << "some wrong\n";
    }

    return 0;

}