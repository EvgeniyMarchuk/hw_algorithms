#include <iostream>
#include <vector>


int main() {
    int n;
    while (std::cin >> n) {
        if (n < 0) {
            std::cout << "Incorrect input data\n";
            return 0;
        }

        int mark;
        std::vector<int> marks(n);
        for (int i = 0; i != n; ++i) {
            std::cin >> mark;
            if (mark < 0)
                continue;
            marks[i] = mark;
        }

        std::cout << "original array:\n";
        for (int mark : marks) {
            std::cout << mark << ' ';
        } std::cout << '\n';


        size_t pointer = marks.size() - 1;
    
        for (int i = marks.size() - 1; i != -1; --i) {
            if (marks[i] == 0) {
                std::swap(marks[i], marks[pointer]);
                --pointer;
            }
        }
        
        std::cout << "modified array:\n";
        for (size_t i = 0; i != marks.size(); ++i) {
            std::cout << marks[i] << ' ';
        }
        std::cout << "\n\n";
    }
}
