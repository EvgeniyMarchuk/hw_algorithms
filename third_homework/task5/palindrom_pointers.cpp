#include <iostream>
#include <string>
#include <cstdint>


int main() {
    std::string s;
    while (std::cin >> s) {
        int64_t start = 0;
        int64_t finish = s.size() - 1;

        bool flag = false;
        while (finish > start) {
            if (s[start] == s[finish]) {
                ++start; --finish;
            } else { 
                flag = true;
                break;
            }
        }
        if (flag) {
            std::cout << s << " is not palindrom\n\n";
        } else {
            std::cout << s << " is palindrom\n\n";
        }
    }
}
