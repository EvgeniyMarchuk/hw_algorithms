#include <iostream>
#include <cstdint>

class IncorrectIndexException {
public:
    int64_t index;
    IncorrectIndexException(int64_t value): index(value) {}
};


template <typename T>
struct Node {
    Node<T> *next = nullptr;
    T value;

    Node() = default;

    Node(T x): value(x) {}
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
    
    void DeleteNode(int64_t val);

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
void List<T>::DeleteNode(int64_t val) {
    Node<T> *prev = head;
    Node<T> *current = head->next;
    while (current != head) {
        if (current->value == val) {
            prev->next = current->next;
            delete current;
            break;
        }

        prev = prev->next;
        current = current->next;
    }
}


int main() {
    int64_t n;
    while (std::cin >> n) {
        if (n <= 0) {
            std::cout << "Incorrect input data\n\n";
            continue;
        }

        List<int64_t> l;
        int64_t x;
        for (int64_t i = 0; i != n; ++i) {
            std::cin >> x;
            l.PushBack(x);
        }

        std::cout << "original list:\n";
        l.PrintList();

        int64_t deleted_value;
        std::cin >> deleted_value;
        std::cout << "deleted value = " << deleted_value << '\n';
        l.DeleteNode(deleted_value);

        std::cout << "modified list:\n";
        l.PrintList();
        std::cout << "\n";
    }
}

