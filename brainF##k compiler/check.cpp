#include <iostream>
#include <string>
#include <stack>

class exc
{
public:
exc(std::string wr, int i) : wrong{ wr }, index{ i } {}
std::string wrong;
int index;
void get_wrong() { std::cerr << wrong << " " << index << ""; }
};
int main()
{
std::string code = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";
std::string input = "";
auto input_iterator = input.begin();
const int SIZE = 30000;
unsigned char* const mass = new unsigned char[SIZE] {};
unsigned char* data_pointer = &mass[SIZE/2];
std::string res = "";
std::stack<int> stack;
int index = 1;
*data_pointer += 1;
//----------------------------------------------------

index++; // 2

*data_pointer += 1;
//----------------------------------------------------

index++; // 3

*data_pointer += 1;
//----------------------------------------------------

index++; // 4

*data_pointer += 1;
//----------------------------------------------------

index++; // 5

*data_pointer += 1;
//----------------------------------------------------

index++; // 6

*data_pointer += 1;
//----------------------------------------------------

index++; // 7

*data_pointer += 1;
//----------------------------------------------------

index++; // 8

*data_pointer += 1;
//----------------------------------------------------

index++; // 9

if(*data_pointer == 0){

here1:

index++; // 10


{
if (data_pointer >= &mass[SIZE])
{
throw exc("data p wrong! number element of code - ", index);
}
data_pointer++;
}

//----------------------------------------------------

index++; // 11

*data_pointer += 1;
//----------------------------------------------------

index++; // 12

*data_pointer += 1;
//----------------------------------------------------

index++; // 13

*data_pointer += 1;
//----------------------------------------------------

index++; // 14

*data_pointer += 1;
//----------------------------------------------------

index++; // 15

if(*data_pointer == 0){

here2:

index++; // 16


{
if (data_pointer >= &mass[SIZE])
{
throw exc("data p wrong! number element of code - ", index);
}
data_pointer++;
}

//----------------------------------------------------

index++; // 17

*data_pointer += 1;
//----------------------------------------------------

index++; // 18

*data_pointer += 1;
//----------------------------------------------------

index++; // 19


{
if (data_pointer >= &mass[SIZE])
{
throw exc("data p wrong! number element of code - ", index);
}
data_pointer++;
}

//----------------------------------------------------

index++; // 20

*data_pointer += 1;
//----------------------------------------------------

index++; // 21

*data_pointer += 1;
//----------------------------------------------------

index++; // 22

*data_pointer += 1;
//----------------------------------------------------

index++; // 23


{
if (data_pointer >= &mass[SIZE])
{
throw exc("data p wrong! number element of code - ", index);
}
data_pointer++;
}

//----------------------------------------------------

index++; // 24

*data_pointer += 1;
//----------------------------------------------------

index++; // 25

*data_pointer += 1;
//----------------------------------------------------

index++; // 26

*data_pointer += 1;
//----------------------------------------------------

index++; // 27


{
if (data_pointer >= &mass[SIZE])
{
throw exc("data p wrong! number element of code - ", index);
}
data_pointer++;
}

//----------------------------------------------------

index++; // 28

*data_pointer += 1;
//----------------------------------------------------

index++; // 29


{
if (data_pointer <= &mass[0])
{
throw exc("data p wrong! number element of code - ",index);
}
else
data_pointer--;
}

//----------------------------------------------------

index++; // 30


{
if (data_pointer <= &mass[0])
{
throw exc("data p wrong! number element of code - ",index);
}
else
data_pointer--;
}

//----------------------------------------------------

index++; // 31


{
if (data_pointer <= &mass[0])
{
throw exc("data p wrong! number element of code - ",index);
}
else
data_pointer--;
}

//----------------------------------------------------

index++; // 32


{
if (data_pointer <= &mass[0])
{
throw exc("data p wrong! number element of code - ",index);
}
else
data_pointer--;
}

//----------------------------------------------------

index++; // 33

*data_pointer -= 1;
//----------------------------------------------------

index++; // 34

}
if(*data_pointer != 0)goto here2;

index++; // 35


{
if (data_pointer >= &mass[SIZE])
{
throw exc("data p wrong! number element of code - ", index);
}
data_pointer++;
}

//----------------------------------------------------

index++; // 36

*data_pointer += 1;
//----------------------------------------------------

index++; // 37


{
if (data_pointer >= &mass[SIZE])
{
throw exc("data p wrong! number element of code - ", index);
}
data_pointer++;
}

//----------------------------------------------------

index++; // 38

*data_pointer += 1;
//----------------------------------------------------

index++; // 39


{
if (data_pointer >= &mass[SIZE])
{
throw exc("data p wrong! number element of code - ", index);
}
data_pointer++;
}

//----------------------------------------------------

index++; // 40

*data_pointer -= 1;
//----------------------------------------------------

index++; // 41


{
if (data_pointer >= &mass[SIZE])
{
throw exc("data p wrong! number element of code - ", index);
}
data_pointer++;
}

//----------------------------------------------------

index++; // 42


{
if (data_pointer >= &mass[SIZE])
{
throw exc("data p wrong! number element of code - ", index);
}
data_pointer++;
}

//----------------------------------------------------

index++; // 43

*data_pointer += 1;
//----------------------------------------------------

index++; // 44

if(*data_pointer == 0){

here3:

index++; // 45


{
if (data_pointer <= &mass[0])
{
throw exc("data p wrong! number element of code - ",index);
}
else
data_pointer--;
}

//----------------------------------------------------

index++; // 46

}
if(*data_pointer != 0)goto here3;

index++; // 47


{
if (data_pointer <= &mass[0])
{
throw exc("data p wrong! number element of code - ",index);
}
else
data_pointer--;
}

//----------------------------------------------------

index++; // 48

*data_pointer -= 1;
//----------------------------------------------------

index++; // 49

}
if(*data_pointer != 0)goto here1;

index++; // 50


{
if (data_pointer >= &mass[SIZE])
{
throw exc("data p wrong! number element of code - ", index);
}
data_pointer++;
}

//----------------------------------------------------

index++; // 51


{
if (data_pointer >= &mass[SIZE])
{
throw exc("data p wrong! number element of code - ", index);
}
data_pointer++;
}

//----------------------------------------------------

index++; // 52

res.push_back(*data_pointer);
//----------------------------------------------------

index++; // 53


{
if (data_pointer >= &mass[SIZE])
{
throw exc("data p wrong! number element of code - ", index);
}
data_pointer++;
}

//----------------------------------------------------

index++; // 54

*data_pointer -= 1;
//----------------------------------------------------

index++; // 55

*data_pointer -= 1;
//----------------------------------------------------

index++; // 56

*data_pointer -= 1;
//----------------------------------------------------

index++; // 57

res.push_back(*data_pointer);
//----------------------------------------------------

index++; // 58

*data_pointer += 1;
//----------------------------------------------------

index++; // 59

*data_pointer += 1;
//----------------------------------------------------

index++; // 60

*data_pointer += 1;
//----------------------------------------------------

index++; // 61

*data_pointer += 1;
//----------------------------------------------------

index++; // 62

*data_pointer += 1;
//----------------------------------------------------

index++; // 63

*data_pointer += 1;
//----------------------------------------------------

index++; // 64

*data_pointer += 1;
//----------------------------------------------------

index++; // 65

res.push_back(*data_pointer);
//----------------------------------------------------

index++; // 66

res.push_back(*data_pointer);
//----------------------------------------------------

index++; // 67

*data_pointer += 1;
//----------------------------------------------------

index++; // 68

*data_pointer += 1;
//----------------------------------------------------

index++; // 69

*data_pointer += 1;
//----------------------------------------------------

index++; // 70

res.push_back(*data_pointer);
//----------------------------------------------------

index++; // 71


{
if (data_pointer >= &mass[SIZE])
{
throw exc("data p wrong! number element of code - ", index);
}
data_pointer++;
}

//----------------------------------------------------

index++; // 72


{
if (data_pointer >= &mass[SIZE])
{
throw exc("data p wrong! number element of code - ", index);
}
data_pointer++;
}

//----------------------------------------------------

index++; // 73

res.push_back(*data_pointer);
//----------------------------------------------------

index++; // 74


{
if (data_pointer <= &mass[0])
{
throw exc("data p wrong! number element of code - ",index);
}
else
data_pointer--;
}

//----------------------------------------------------

index++; // 75

*data_pointer -= 1;
//----------------------------------------------------

index++; // 76

res.push_back(*data_pointer);
//----------------------------------------------------

index++; // 77


{
if (data_pointer <= &mass[0])
{
throw exc("data p wrong! number element of code - ",index);
}
else
data_pointer--;
}

//----------------------------------------------------

index++; // 78

res.push_back(*data_pointer);
//----------------------------------------------------

index++; // 79

*data_pointer += 1;
//----------------------------------------------------

index++; // 80

*data_pointer += 1;
//----------------------------------------------------

index++; // 81

*data_pointer += 1;
//----------------------------------------------------

index++; // 82

res.push_back(*data_pointer);
//----------------------------------------------------

index++; // 83

*data_pointer -= 1;
//----------------------------------------------------

index++; // 84

*data_pointer -= 1;
//----------------------------------------------------

index++; // 85

*data_pointer -= 1;
//----------------------------------------------------

index++; // 86

*data_pointer -= 1;
//----------------------------------------------------

index++; // 87

*data_pointer -= 1;
//----------------------------------------------------

index++; // 88

*data_pointer -= 1;
//----------------------------------------------------

index++; // 89

res.push_back(*data_pointer);
//----------------------------------------------------

index++; // 90

*data_pointer -= 1;
//----------------------------------------------------

index++; // 91

*data_pointer -= 1;
//----------------------------------------------------

index++; // 92

*data_pointer -= 1;
//----------------------------------------------------

index++; // 93

*data_pointer -= 1;
//----------------------------------------------------

index++; // 94

*data_pointer -= 1;
//----------------------------------------------------

index++; // 95

*data_pointer -= 1;
//----------------------------------------------------

index++; // 96

*data_pointer -= 1;
//----------------------------------------------------

index++; // 97

*data_pointer -= 1;
//----------------------------------------------------

index++; // 98

res.push_back(*data_pointer);
//----------------------------------------------------

index++; // 99


{
if (data_pointer >= &mass[SIZE])
{
throw exc("data p wrong! number element of code - ", index);
}
data_pointer++;
}

//----------------------------------------------------

index++; // 100


{
if (data_pointer >= &mass[SIZE])
{
throw exc("data p wrong! number element of code - ", index);
}
data_pointer++;
}

//----------------------------------------------------

index++; // 101

*data_pointer += 1;
//----------------------------------------------------

index++; // 102

res.push_back(*data_pointer);
//----------------------------------------------------

index++; // 103


{
if (data_pointer >= &mass[SIZE])
{
throw exc("data p wrong! number element of code - ", index);
}
data_pointer++;
}

//----------------------------------------------------

index++; // 104

*data_pointer += 1;
//----------------------------------------------------

index++; // 105

*data_pointer += 1;
//----------------------------------------------------

index++; // 106

res.push_back(*data_pointer);
//----------------------------------------------------

index++; // 107

delete[] mass;
return 0;
}