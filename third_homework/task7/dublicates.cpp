#include <iostream>
#include <string>
#include <deque>


int main() {
    std::string s;
    while (std::cin >> s) {
        std::deque<char> deq;
        for (char c : s) {
            bool flag  = false;
            while (deq.size() != 0 && deq[deq.size() - 1] == c) {
                deq.pop_back();
                flag = true;
                break;
            }
            if (flag) { continue; }
            deq.push_back(c);
        }
       
        for (size_t i = 0; i != deq.size(); ++i) {
            std::cout << deq[i];
        } std::cout << "\n\n";
   }
}
