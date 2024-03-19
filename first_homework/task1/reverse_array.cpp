#include <iostream>
#include <vector>
#include <cstdint>
#include <fstream>



int main() {
    int64_t n;
    while (std::cin >> n) {
        std::cout << "original array: ";
        
        if (n <= 0) {
            std::cout << "\n";
            std::cout << "reversed array: " << "\n\n";
            continue;
        }
    
        std::vector<int64_t> vec(n);
        for (int64_t& elem : vec) {
            std::cin >> elem;
            std::cout << elem << ' ';
        }
        std::cout << "\n";
        
        size_t left = 0;
        size_t right = n-1;
    
        while (right > left) {
            std::swap(vec[left], vec[right]);
            ++left; --right;
        }
        
        std::cout << "reversed array: ";
        for (int64_t elem : vec) {
            std::cout << elem << ' ';
        }
        
        std::cout << "\n\n";
    }
}

