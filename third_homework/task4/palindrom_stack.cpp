#include <iostream>
#include <string>
#include <stack>


int main() {
    std::string s;
    while (std::cin >> s) {
        std::stack<char> st;
        bool flag = false;
        for (size_t i = 0; i != s.size(); ++i) {
            if (i < s.size() / 2) {
                st.push(s[i]);
            } else if (s.size() % 2 != 0 && i == s.size() / 2) {
                continue;
            } else if (st.top() != s[i]) {
                std::cout << s << " is not palindrom\n";
                flag = true;
                break;
            } else {
                st.pop();
            }
        }
        
        if (flag) {
            continue;
        } else if (st.empty()) {
            std::cout << s << " is palindrom\n";
        } else {
            std::cout << s << " is not palindrom\n";
        }
        /*
        for (char c : s) {
            st.push(c);
        }

        bool flag = false;
        for (char c : s) {
            if (c != st.top()) {
                std::cout << s << " is not palindrom\n";
                flag = true;
                break;
            }
            st.pop();
        }
        
        if (flag) {
            continue;
        } else {
            std::cout << s << " is palindrom\n";
        }
        */
    }
}
