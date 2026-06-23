#include <iostream>
#include <fstream>
#include <string>
#include <iterator>

int main() 
{

    std::string name1;
    std::string name2;

    std::cin >> name1 >> name2;

    std::ifstream inFile(name1);
    std::ofstream outFile(name2);

    std::ostream_iterator<int> out(outFile, "\n");

    for (std::istream_iterator<int> in(inFile); in != std::istream_iterator<int>(); in++) 
    {
        if (*in != 0) 
        {
            out = *in; 
        }
    }

    return 0;
}