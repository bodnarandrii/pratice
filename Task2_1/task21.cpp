#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <limits>

void clear_input() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void task1_1() {
    std::cout << "\n--- Task 1.1: Count Zeros ---\n";
    std::cout << "Enter a sequence of integers \n> ";


    std::istream_iterator<int> input_it(std::cin);
    std::istream_iterator<int> eof;

    int zero_count = std::count(input_it, eof, 0);

    std::cout << "Result: The number of zeros is " << zero_count << "\n";
    
    clear_input(); 
}

void task1_2() {
    std::cout << "\n--- Task 1.2: Count Positive Numbers in File ---\n";
    
    std::string filename;
    std::cout << "Enter the file name (e.g., numbers.txt): ";
    std::cin >> filename;

    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "Error: Could not open file '" << filename << "'!\n";
        return;
    }

    std::istream_iterator<double> file_it(file);
    std::istream_iterator<double> eof;

    int positive_count = std::count_if(file_it, eof, [](double val) {
        return val > 0.0;
    });

    std::cout << "Result: The number of positive values in the file is " << positive_count << "\n";

    file.close();
}

int main() {
    int choice;
    
    while (true) {
        std::cout << "             MAIN MENU (C++)\n";
        std::cout << "1. Task 1.1\n";
        std::cout << "2. Task 1.2\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";
        
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Exiting...\n";
            break;
        }

        switch (choice) {
            case 1:
                task1_1();
                break;
            case 2:
                task1_2();
                break;
            case 0:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}