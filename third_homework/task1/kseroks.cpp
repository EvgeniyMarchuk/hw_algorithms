#include <iostream>
#include <cstdint>


int main() {
    int64_t N, x, y;
    while (std::cin >> N >> x >> y) {
        if (N < 0 || x <= 0 || y <= 0) {
            std::cout << "Incorrect input data\n\n";
            continue;
        }
        
        std::cout << "input data:\n";
        std::cout << "N = " << N << "\tx = " << x << "\ty = " << y << '\n';
        int64_t maxim = std::max(x, y);
        int64_t lbound = 0;
        int64_t hbound = (N-1) * maxim;
        int64_t middle = (hbound + lbound) / 2;
    
        while (hbound - lbound > 1) {
            if (middle/x + middle/y == N-1) {
                break;
            }
    
            if (middle/x + middle/y > N-1) {
                hbound = middle;
            } else {
                lbound = middle;
            }
            middle = (hbound + lbound) / 2;
        }
        
        std::cout << "answer = " << middle + (middle == lbound) + std::min(x, y) << "\n";
    }
}
