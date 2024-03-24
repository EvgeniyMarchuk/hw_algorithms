#include <iostream>
#include <vector>


int main() {
    size_t N, x, y;
    std::cin >> N >> x >> y;

    size_t maxim = std::max(x, y);
    size_t lbound = 0;
    size_t hbound = (N-1) * maxim;
    size_t middle = (hbound + lbound) / 2;

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
    
    std::cout << middle + (middle == lbound) + std::min(x, y) << '\n';
}
