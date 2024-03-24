#include <iostream>
#include <string>


int main() {
    std::string a, b;
    
    while (std::cin >> a >> b) {
        size_t i = 0;
        bool next = false;
        for (char c1 : a) {
            bool found = false;
            for (; i < b.size(); ++i) {
                if (c1 == b[i]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << a << " is not source string for " << b << "\n\n";
                next = true;
                break;
            }
        }
    
        if (next) { continue; }
        std::cout << a << " is source string for " << b << "\n\n";
    }
}
