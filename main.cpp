#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main(int argc, char **argv) {
    std::ifstream f(argv[1]);

    if (f.is_open()) {
        std::string str((std::istreambuf_iterator(f)), std::istreambuf_iterator<char>());

        std::vector<std::string> words;

        std::string current_word;

        for (const char ch : str) {
            if (ch == ' ') {
                if (!current_word.empty()) {
                    words.push_back(current_word);
                    current_word.clear();
                }
            } else {
                current_word.push_back(ch);
            }
        }

        if (!current_word.empty()) {
            words.push_back(current_word);
        }

        std::sort(words.begin(), words.end());

        for (const auto word : words) {
            std::cout << word << std::endl;
        }
    } else {
        std::cerr << "Error opening file: " << argv[1] << std::endl;
    }

    return 0;
}