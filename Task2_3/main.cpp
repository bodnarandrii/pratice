#include <iostream>
#include <vector>
#include <map>
#include <algorithm>


std::vector<int> inputVector() {
    int size;
    std::cout << "Enter the number of elements in the vector: ";
    std::cin >> size;

    if (size <= 0) {
        std::cout << "Vector size must be greater than 0. Creating an empty vector." << std::endl;
        return std::vector<int>();
    }

    std::vector<int> V;
    std::cout << "Enter " << size << " integers (separated by spaces or Enters):" << std::endl;
    
    for (int i = 0; i < size; ++i) {
        int element;
        std::cin >> element;
        V.push_back(element); 
    }
    
    return V;
}

void task3_1() {
    std::cout << "\n--- Task 3_1 ---" << std::endl;
    
    std::vector<int> V = inputVector();
    
    if (V.empty()) return; 

    std::map<int, int> M;

    for (std::vector<int>::iterator it = V.begin(); it != V.end(); ++it) {
        M[*it]++;
    }

    std::cout << "\nElements and their occurrences:" << std::endl;
    for (std::map<int, int>::iterator it = M.begin(); it != M.end(); ++it) {
        std::cout << "Element " << it->first << " : " << it->second << " times" << std::endl;
    }
}


void task3_2() {
    std::cout << "\n--- Task 3_2 ---" << std::endl;
    
    std::vector<int> V = inputVector();
    
    if (V.empty()) return;

    std::map<int, int> M;
    
    for (int val : V) {
        M[val]++;
    }

    std::cout << "\nElements and their occurrences:" << std::endl;
    for (const auto& pair : M) {
        std::cout << "Element " << pair.first << " : " << pair.second << " times" << std::endl;
    }
}


int main() {
    int choice;
    
    do {
        std::cout << "\n=== MAIN MENU ===" << std::endl;
        std::cout << "1. Run Task 3_1 (Iterators)" << std::endl;
        std::cout << "2. Run Task 3_2 (C++11 Range-based for)" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Select an option: ";
        
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear(); 
            std::cin.ignore(10000, '\n'); 
            continue;
        }

        switch (choice) {
            case 1:
                task3_1();
                break;
            case 2:
                task3_2();
                break;
            case 0:
                std::cout << "Exiting the program..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
        }
    } while (choice != 0);

    return 0;
}