#include <iostream>
#include <string>
#include <cstdint>


int main() {
    std::string a, b;
    
    while (std::cin >> a >> b) {
        size_t p1 = 0;
        size_t p2 = 0;
        if (a.size() > b.size()) {
            std::cout << a << " is not subsequence of " << b << "\n\n";
        }
        
        bool flag = false;
        while (p1 != a.size()) {
            while (b[p2] != a[p1] && p2 < b.size()) {
                ++p2;
            }

            if (p2 == b.size()) {
                flag = true;
                break;
            }
            ++p1;
        }
        
        if (flag) {
            std::cout << a << " is not subsequence of " << b << "\n\n";
        } else {
            std::cout << a << " is subsequence of " << b << "\n\n";
        }
    }
}
