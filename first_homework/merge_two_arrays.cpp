#include <iostream>
#include <vector>
#include <cstdint>


void merge(std::vector<int64_t> &arr1, std::vector<int64_t> &arr2) {
    if (arr1.size() == 0 || arr2.size() == 0) {
        if (arr1.size() == 0) {
            arr1 = arr2;
        }
        return;
    }

    int64_t p1 = arr1.size() - arr2.size() - 1;
    int64_t p2 = arr2.size() - 1;
    int64_t p3 = arr1.size() - 1;

    while (p1 >= 0 && p2 >= 0) {
        if (arr1[p1] > arr2[p2]) {
            arr1[p3] = arr1[p1];
            --p1;
        } else {
            arr1[p3] = arr2[p2];
            --p2;
        }
        --p3;
    }
    
    if (p2 == -1) {}
    else { 
        for (int64_t i = 0; i != p2 + 1; ++i) { 
            arr1[i] = arr2[i]; 
        }
    }
}


int main() {
    int64_t n, m;
    while (std::cin >> n >> m) {
    
        if (n < 0 || m < 0) {
            std::cout << "Incorrect input data\n";
            return 0;
        }

        std::vector<int64_t> arr1(n + m);
        for (int64_t i = 0; i != n; ++i) {
            std::cin >> arr1[i];
        }

        std::cout << "first array:\n";
        for (int64_t i = 0; i != n; ++i) {
            std::cout << arr1[i] << ' ';
        } std::cout << '\n';

        std::vector<int64_t> arr2(m);
        for (int64_t i = 0; i != m; ++i) {
            std::cin >> arr2[i];
        }
        
        std::cout << "second array:\n"; 
        for (int64_t i = 0; i != m; ++i) {
            std::cout << arr2[i] << ' ';
        } std::cout << '\n';

        merge(arr1, arr2);

        std::cout << "resulted array:\n";
        for (int64_t i = 0; i != n + m; ++i) {
            std::cout << arr1[i] << ' ';
        }
        std::cout << "\n\n";
    }
}
