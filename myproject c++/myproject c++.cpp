#include <iostream>
#include <string>
#include <array>

int main()
{
    int number=1;
    int value=0;
    int value2=0;
    std::cout<<"please enter a number that is bigger than 0-  "
    std::cin >> value;
    value2 = value;
    do
    {
        value2 / 10;
        number++;
    } while (value2>0);
    const int number_of = number;
    std::string collection[number_of]
    {