#include <iostream>
#include <string>
#include <assert.h>
#include <stack>

std::string translate(std::string& code, std::string input)
{
    auto code_pointer = code.begin();
    auto input_iterator = input.begin();
    const int SIZE = 10000;
    unsigned char mass[SIZE]{};
    unsigned char* data_pointer = mass;
    std::string res = "";
    std::stack<int> stack;
    int index = 0;
    while (code_pointer < code.end())
    {
        //////////////////////////////////////////////////////////
        if (code_pointer >= code.end())
            std::cout << "OUT OF RANGE CODE POINTER\n";
        else if (data_pointer >= &mass[SIZE])             // проверка выхода за пределы
            std::cout << "OUT OF RANGE DATA POINTER\n";
        else if (input_iterator >= input.end())
            std::cout << "OUT OF RANGE INPUT POINTER\n";
        //////////////////////////////////////////////////////////
        switch (*code_pointer) // проверка символа кода
        {
        case '+':                       // увеличиваем значение указателя на элемент массива mass на 1
            *data_pointer += 1;
            code_pointer++;
            index++;
            break;
        case '-':                       // уменьшаем значение указателя на элемент массива mass на 1
            *data_pointer -= 1;
            code_pointer++;
            index++;
            break;
        case '>':                       // перемещаем указатель на элемент враво на 1 массива mass
            data_pointer++;
            code_pointer++;
            index++;
            break;
        case '<':                     // перемещаем указатель на элемент влево на 1 массива mass
            data_pointer--;
            code_pointer++;
            index++;
            break;
        case ',':                      // записываем значение элемента с строки input в значение указателя на элемент массива mass 
            *data_pointer = *input_iterator;
            code_pointer++;
            input_iterator++;
            index++;
            break;
        case '.':                   //выводим значение указателя на элемент в res
            res.push_back(*data_pointer);
            code_pointer++;
            index++;
            break;
        case '[':                           // начало цикла 
            if (*data_pointer == 0)
            {
                while (*code_pointer != ']') // пропускаем цикл []
                {
                    code_pointer++;
                    index++;
                }
                code_pointer++;
                index++;
                break;                      // выходим из кейса '['
            }
            // если попали сюда значит сработал цикл []
            if (stack.empty() || stack.top() != index)
                stack.push(index);
            code_pointer++;
            index++;

            break;
        case ']':
            if (*data_pointer != 0)
            {

                while (*code_pointer != '[') // возвращаемся в начало цикла
                {
                here:
                    code_pointer--;
                    index--;
                }
                if (stack.top() != index)
                    goto here;              // для того чтобы пропускать уже обработанный цикл [] в цикле []
                code_pointer++;
                index++;
                break;                      // выходим из кейса ']'
            }
            // если попали сюда значит цикл [] закончен
            if (!stack.empty())
                stack.pop();
            code_pointer++;
            index++;
            break;

        default:            // пропускаем все лишние символы
            code_pointer++;
            index++;
            break;
        }
    }
    return res;
}

int main()
{
    std::string code = "+[-->-[>>+>-----<<]<--<---]>-.>>>+.>>..+++[.>]<<<<.+++.------.<<-.>>>>+.";
    std::string input = "112";
    std::cout << translate(code, input);
    

    return 0;

}