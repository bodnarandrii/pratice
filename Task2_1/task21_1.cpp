#include <iostream>
#include <fstream>
#include <iterator>
#include <string>

void process_files(const std::string& name1, const std::string& name2) {
    std::ifstream file_in(name1);
    if (!file_in.is_open()) {
        std::cerr << "Помилка відкриття файлу: " << name1 << std::endl;
        return;
    }

    std::ofstream file_out(name2);
    if (!file_out.is_open()) {
        std::cerr << "Помилка відкриття файлу: " << name2 << std::endl;
        return;
    }

    std::ostream_iterator<int> out(file_out, "\n");

    std::istream_iterator<int> end_in;

    for (std::istream_iterator<int> in(file_in); in != end_in; in++) {
        if (*in != 0) {
            *out = *in; 
        }
    }

    std::cout << "Обробка завершена успішно!" << std::endl;
}

int main() {
    std::string name1 = "input.txt";  
    std::string name2 = "output.txt"; 
    process_files(name1, name2);

    return 0;
}