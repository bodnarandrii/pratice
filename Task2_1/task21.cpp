#include <iostream>
#include <algorithm> // Для алгоритму count
#include "pt4.h"     // Бібліотека задачника з ptin_iterator

int main() 
{

    int zeroCount = std::count(ptin_iterator<int>(), ptin_iterator<int>(), 0);
    std::cout << zeroCount << "\n";

    return 0;
}