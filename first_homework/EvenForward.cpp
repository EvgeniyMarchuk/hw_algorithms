#include <iostream>
#include <vector>
#include <cstdint>


std::vector<int64_t>& EvenForward(std::vector<int64_t>& arr) {
    size_t evenIndex = 0;

    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] % 2 == 0) {
            std::swap(arr[i], arr[evenIndex]);
            ++evenIndex;
        }
    }
    
    return arr;
}

int main() {
    int64_t n;
    while (std::cin >> n) {
        if (n < 0) {
            std::cout << "Incorrect input data\n";
            return 0;
        }

        std::vector<int64_t> arr(n);
        for (int64_t i = 0; i != n; ++i) {
            std::cin >> arr[i];
        }

        std::cout << "original array:\n";
        for (int64_t i = 0; i != n; ++i) {
            std::cout << arr[i] << ' ';
        } std::cout << '\n';


        arr = EvenForward(arr);

        std::cout << "modified array:\n";
        for (int64_t i = 0; i != n; ++i) {
            std::cout << arr[i] << ' ';
        } std::cout << "\n\n";

    }
}


