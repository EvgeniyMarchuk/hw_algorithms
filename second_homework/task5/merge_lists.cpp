#include <iostream>
#include <cstdint>

class IncorrectIndexException {
public:
    int64_t index;
    IncorrectIndexException(int64_t value): index(value) {}
};


template <typename T>
class Node {
public:
    Node<T> *next = nullptr;
    T value;

    Node() = default;

    Node(T x): value(x) {}

    /*Node<T> *operator ++() {
        return this->next;
    }*/

};

template <typename T>
class List {
private:
    Node<T> *head;
    int64_t size = 0;
public:
    List() {
        head = new Node<T>;
        head->next = head;
    }

    int64_t Size() const {
        return size;
    }
    
    Node<T> *begin() {
        if (head->next == head) {
            return nullptr;
        }
        return head->next;
    }

    Node<T> *end() {
        return head;
    }

    void Insert(int64_t index, T value) {
        if (index > size || index < 0) {
            throw IncorrectIndexException(index);
        }

        Node<T> *current = head->next;
        Node<T> *before_current = head;
        for ( ; index > 0; --index) {
            before_current = current;
            current = current->next;
        }

        Node<T> *new_node = new Node(value);
        
        before_current->next = new_node;
        new_node->next = current;

        ++size;
    }
    
    void PushBack(T value) {
        try {
            Insert(size, value);
        } catch (const IncorrectIndexException& ex) {
            std::cerr << "Index is not correct: " << ex.index << '\n';
        } 
    }


    T &look_at(int64_t index) const {
        if (index + 1 > size || index < 0) {
            throw IncorrectIndexException(index);
        }

        Node<T> *current = head;
        for ( ; index >= 0; --index) {
            current = current->next;
        }
        
        return current->value;
    }

        

    void PrintList() const;
    
    ~List() {
        Node<T> *current = head;
        while (current != head) {
            delete current;
            if (current->next != nullptr) {
                current = current->next;
            } else { break; }
        }
    }
};

template <typename T>
void List<T>::PrintList() const {
    Node<T> *pointer = head->next;
    while (pointer != head) {
        std::cout << pointer->value << ' ';
        pointer = pointer->next;
    } std::cout << "\n";
}


template <typename T>
List<T> MergeLists(List<T> &l1, List<T> &l2) {
    Node<T> *p1 = l1.begin();
    Node<T> *p2 = l2.begin();
    if (p1 == nullptr) {
        return l2;
    } else if (p2 == nullptr) {
        return l1;
    }
    Node<T> *res_node, *side_node;
    Node<T> *res_end, *side_end;
    bool flag = false;
    if (p1->value > p2->value) {
        res_node = p2;
        side_node = p1;
        res_end = l2.end();
        side_end = l1.end();
        flag = true;
    } else {
        res_node = p1;
        side_node = p2;
        res_end = l1.end();
        side_end = l2.end();
    }

    Node<T> *prev_res = res_node;
    while (res_node != res_end && side_node != side_end) {
        if (res_node->value <= side_node->value) {
            if (prev_res != res_node) {
                prev_res = res_node;
            }
            res_node = res_node->next;   
        } else {
            Node<T> *put_node2 = side_node;
            side_node = side_node->next;
            prev_res->next = put_node2;
            put_node2->next = res_node;
            prev_res = put_node2;
        }
    }

    if (res_node == res_end) {
        prev_res->next = side_node;
        while (side_node->next != side_end) {
            side_node = side_node->next;
        }
        side_node->next = res_end;
    }

    if (flag) {
        return l2;
    }
    return l1;
}


int main() {
    int64_t n, m;
    while (std::cin >> n >> m) {
        if (n < 0 || m < 0) {
            std::cout << "Incorrect input data\n";
            break;
        }

        List<int64_t> l1, l2;
        int64_t x;
        for (int64_t i = 0; i != n; ++i) {
            std::cin >> x;
            l1.PushBack(x);
        } 
        std::cout << "first list:\n";
        l1.PrintList();
        
        for (int64_t i = 0; i != m; ++i) {
            std::cin >> x;
            l2.PushBack(x);
        } 
        std::cout << "second list:\n";
        l2.PrintList();

        List<int64_t> result = MergeLists(l1, l2);
    
        std::cout << "resulted list:\n";
        result.PrintList();
        std::cout << "\n";
    }
}

