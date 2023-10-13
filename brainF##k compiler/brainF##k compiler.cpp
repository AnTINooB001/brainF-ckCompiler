#include <iostream>
#include <string>
#include <stack>

class exc
{
public:
    exc(std::string wr, int i) : wrong{ wr }, index{ i } {}
    std::string wrong;
    int index;
    void get_wrong() { std::cerr << wrong << " " << index << "\n"; }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                                                                                                // проверки выхода за пределы
void move_input_iterator_right(std::string::iterator& input_iterator, std::string::iterator end_input_iterator, int index)
{
    if (input_iterator >= end_input_iterator)
    {
        std::cout << "\n";
        throw exc("OUT OF RANGE INPUT ITERATOR number element of code - ", index);
    }
    input_iterator++;
}

void move_code_pointer_right(std::string::iterator& code_pointer, std::string::iterator end_code_pointer, int index)
{
    if (code_pointer >= end_code_pointer)
    {
        std::cout << "OUT OF RANGE CODE POINTER > \n";
        throw exc("code p wrong! number element of code - ", index);
    }
    code_pointer++;
}
void move_code_pointer_left(std::string::iterator& code_pointer, std::string::iterator begin_code_pointer, int index)
{
    if (code_pointer <= begin_code_pointer)
    {
        std::cout << "OUT OF RANGE CODE POINTER  < \n";
        throw exc("code p wrong! number element of code - ", index);
    }
    code_pointer--;
}
void move_data_pointer_right(unsigned char*& data_pointer, unsigned char* end_data_pointer, int index)
{
    if (data_pointer >= end_data_pointer)
    {
        std::cout << "OUT OF RANGE DATA POINTER > \n";
        throw exc("data p wrong! number element of code - ", index);
    }
    data_pointer++;
}

void move_data_pointer_left(unsigned char*& data_pointer, unsigned char* begin_data_pointer, int index)
{
    if (data_pointer <= begin_data_pointer)             // проверка выхода за пределы
    {
        //std::cout << "OUT OF RANGE DATA POINTER < \n";
        //throw exc("data p wrong! number element of code - ",index);
    }
    else
        data_pointer--;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::string translate(std::string& code, std::string input = "")
{
    auto code_pointer = code.begin();
    auto input_iterator = input.begin();
    const int SIZE = 1000;
    unsigned char* const mass = new unsigned char[SIZE] {};
    unsigned char* data_pointer = &mass[5];
    std::string res = "";
    std::stack<int> stack;
    int index = 1;
    while (code_pointer != code.end())
    {
        switch (*code_pointer) // проверка символа кода
        {
        case '+':                       // увеличиваем значение указателя на элемент массива mass на 1
            *data_pointer += 1;
            move_code_pointer_right(code_pointer, code.end(), index);
            index++;
            break;
        case '-':                       // уменьшаем значение указателя на элемент массива mass на 1
            *data_pointer -= 1;
            move_code_pointer_right(code_pointer, code.end(), index);
            index++;
            break;
        case '>':                       // перемещаем указатель на элемент враво на 1 массива mass
            move_data_pointer_right(data_pointer, &mass[SIZE], index);
            move_code_pointer_right(code_pointer, code.end(), index);
            index++;
            break;
        case '<':                     // перемещаем указатель на элемент влево на 1 массива mass
            move_data_pointer_left(data_pointer, &mass[0], index);
            move_code_pointer_right(code_pointer, code.end(), index);
            index++;
            break;
        case ',':                      // записываем значение элемента с строки input в значение указателя на элемент массива mass 
            if (input_iterator == input.end())
                throw exc("empty input! number of code element - ", index);
            *data_pointer = *input_iterator;
            move_code_pointer_right(code_pointer, code.end(), index);
            move_input_iterator_right(input_iterator, input.end(), index);
            index++;
            break;
        case '.':                   //выводим значение указателя на элемент в res
            res.push_back(*data_pointer);
            move_code_pointer_right(code_pointer, code.end(), index);
            index++;
            break;
        case '[':                           // начало цикла 
            if (*data_pointer == 0)
            {
                while (*code_pointer != ']') // пропускаем цикл []
                {
                    move_code_pointer_right(code_pointer, code.end(), index);
                    index++;
                }
                move_code_pointer_right(code_pointer, code.end(), index);
                index++;
                break;                      // выходим из кейса '['
            }
            // если попали сюда значит сработал цикл []
            if (stack.empty() || stack.top() != index)
                stack.push(index);
            move_code_pointer_right(code_pointer, code.end(), index);
            index++;
            break;
        case ']':
            if (*data_pointer != 0)
            {

                while (*code_pointer != '[') // возвращаемся в начало цикла
                {
                here:
                    move_code_pointer_left(code_pointer, code.begin(), index);
                    index--;
                }
                if (stack.top() != index)
                    goto here;              // для того чтобы пропускать уже обработанный цикл [] в цикле []
                move_code_pointer_right(code_pointer, code.end(), index);
                index++;
                break;                      // выходим из кейса ']'
            }
            // если попали сюда значит цикл [] закончен
            if (!stack.empty())
                stack.pop();
            move_code_pointer_right(code_pointer, code.end(), index);
            index++;
            break;

        default:            // пропускаем все лишние символы
            move_code_pointer_right(code_pointer, code.end(), index);
            index++;
            break;
        }
    }

    delete[] mass;
    data_pointer = nullptr;
    return res;
}

int main()
{
    //std::string code = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++."; // выводит Helo world!

    std::string code = "+[-->-[>>+>-----<<]<--<---]>-.>>>+.>>..+++[.>]<<<<.+++.------.<<-.>>>>+.,"; // выводит Helo world! краткая версия
    try
    {
        std::cout << translate(code);
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