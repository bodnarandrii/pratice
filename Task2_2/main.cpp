#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

void printVector(const std::string& name, const std::vector<int>& v) {
    std::cout << name << ": ";
    for (int val : v) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

void task2_1() {
    std::cout << "\n--- Task 2_1 ---" << std::endl;
    int A, B;
    
    std::cout << "Enter number A: ";
    std::cin >> A;
    std::cout << "Enter number B: ";
    std::cin >> B;

    std::vector<int> V1(12, 0); 
    std::vector<int> V2(12, 0);

    std::cout << "\nInitial vectors:" << std::endl;
    printVector("V1", V1);
    printVector("V2", V2);


    std::fill(V1.begin(), V1.begin() + 5, A);
    std::fill(V1.end() - 5, V1.end(), B);


    std::fill_n(V2.begin(), 5, A);
    std::fill_n(V2.end() - 5, 5, B);

    std::cout << "\nModified vectors:" << std::endl;
    printVector("V1", V1);
    printVector("V2", V2);
}

void task2_2() {
    std::cout << "\n--- Task 2_2 ---" << std::endl;
    int A, B;
    
    std::cout << "Enter number A: ";
    std::cin >> A;
    std::cout << "Enter number B: ";
    std::cin >> B;

    std::vector<int> V1 = {1, 2, 3}; 
    std::vector<int> V2 = {4, 5, 6};

    std::cout << "\nInitial vectors:" << std::endl;
    printVector("V1", V1);
    printVector("V2", V2);

    std::fill_n(std::inserter(V1, V1.begin()), 5, A);
    std::fill_n(std::back_inserter(V1), 5, B);

    V2.insert(V2.begin(), 5, A);
    V2.insert(V2.end(), 5, B);

    std::cout << "\nModified vectors:" << std::endl;
    printVector("V1", V1);
    printVector("V2", V2);
}

int main() {
    int choice;
    
    do {
        std::cout << "\n=== MAIN MENU ===" << std::endl;
        std::cout << "1. Run Task 2_1" << std::endl;
        std::cout << "2. Run Task 2_2" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Select an option: ";
        
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear(); 
            std::cin.ignore(10000, '\n'); // Очищаємо буфер
            continue;
        }

        switch (choice) {
            case 1:
                task2_1();
                break;
            case 2:
                task2_2();
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