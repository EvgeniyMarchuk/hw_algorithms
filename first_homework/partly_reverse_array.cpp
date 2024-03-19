#include <iostream>
#include <vector>
#include <cstdint>


std::vector<int64_t>& reverse_array(std::vector<int64_t>& arr, size_t left, size_t right) {
    while (right > left) {
        std::swap(arr[left], arr[right]);
        ++left; --right;
    }

    return arr;
}


int main() {
    int64_t n, k;
    while (std::cin >> n >> k) {
        std::cout << "n = " << n << '\t' << "k = " << k << '\n';
        std::cout << "original array: " << '\n';
        if (n <= 0) {
            std::cout << "partly reversed array: " << "\n\n";
            continue;
        }
    
        std::vector<int64_t> arr(n);
        for (int64_t& elem : arr) {
            std::cin >> elem;
            std::cout << elem << ' ';
        } 
        std::cout << '\n';
    
        if (k <= 0) {}
        else {
            arr = reverse_array(arr, 0, n-1);
            arr = reverse_array(arr, 0, (n - k - 1 + (n == k)) % n);
            arr = reverse_array(arr, (n - k - 1 + (n == k)) % n + 1 - (n == k), n-1);
        }
    
        std::cout << "partly reversed array: " << '\n';
        for (int64_t elem : arr) {
            std::cout << elem << ' ';
        }
    
        std::cout << "\n\n";
    }
}
