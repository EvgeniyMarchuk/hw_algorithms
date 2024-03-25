#include <iostream>
#include <cstdint>


int main() {
    int64_t n;
    while(std::cin >> n) {
        if (n < 0) {
            std::cout << "Incorrect input data\n\n";
            continue;
        }
        
        int64_t lbound = 0;
        int64_t rbound = n;
        int64_t middle = 0;
        bool found = false;
        
        while (rbound > lbound + 1) {
            middle = (rbound + lbound) / 2;
            if (middle * middle == n) {
                found = true;
                break;
            }

            if (middle * middle > n)
                rbound = middle;
            else 
                lbound = middle;
        }
        
        std::cout << "n = " << n << '\n';
        if (found) {
            std::cout << "answer = " << middle << "\n\n"; 
            continue;
        }
        std::cout << "answer = " << rbound - (std::abs(n - rbound * rbound) > std::abs(n - (rbound - 1) * (rbound - 1))) << "\n\n";
    }
}
