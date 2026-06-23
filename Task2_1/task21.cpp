#include <iostream>
#include <algorithm> 
#include <iterator> 

int main() 
{
    std::cout << "Enter an array of integers (press Ctrl+Z on Windows or Ctrl+D on Linux to finish input):\n";

    int zeroCount = std::count(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), 0);

    std::cout << "Number of zeros: " << zeroCount << "\n";

    return 0;
}