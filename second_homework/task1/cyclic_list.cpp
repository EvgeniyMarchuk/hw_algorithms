#include <iostream>
#include <cstdint>


class IncorrectIndexException {
public:
    int64_t index;
    IncorrectIndexException(int64_t value): index(value) {}
};

class SizeOfCycleException {
public:
    int64_t index;
    int64_t len;
    SizeOfCycleException(int64_t ind, int64_t l): index(ind), len(l) {}
};


template <typename T>
struct Node {
    Node<T>* prev = nullptr;
    Node<T>* next = nullptr;
    T value;

    Node() = default;

    Node(T x): value(x) {}
};

template <typename T>
class List {
private:
    Node<T>* head;
    int64_t size = 0;
public:
    List() {
        head = new Node<T>;
        head->prev = head;
        head->next = head;
    }

    int64_t Size() const {
        return size;
    }


    void Insert(int64_t index, T value) {
        if (index > size || index < 0) {
            throw IncorrectIndexException(index);
        }

        Node<T>* current = head;
        for ( ; index >= 0; --index) {
            current = current->next;
        }

        Node<T>* new_node = new Node(value);
        
        (current->prev)->next = new_node;
        new_node->prev = current->prev;
        new_node->next = current;
        current->prev = new_node;
        
        ++size;
    }
    
    void PushBack(T value) {
        try {
            Insert(size, value);
        } catch (const IncorrectIndexException& ex) {
            std::cerr << "Index is not correct: " << ex.index << '\n';
        } 
    }
    void PushFront(T value) {
        try {
            Insert(0, value);
        } catch (const IncorrectIndexException& ex) {
            std::cerr << "Index is not correct: " << ex.index << '\n';
        } 
    }


    T look_at(int64_t index) const {
        if (index + 1 > size || index < 0) {
            throw IncorrectIndexException(index);
        }

        Node<T>* current = head;
        for ( ; index >= 0; --index) {
            current = current->next;
        }
        
        return current->value;
    }
    

    bool is_cyclic();

    void make_cycle(int64_t first_index_of_cycle, int64_t len_of_cycle);
    
    void PrintList() const;


    ~List() {
        Node<T>* current = head;
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
    for (int64_t i = 0; i != this->Size(); ++i) { 
        std::cout << this->look_at(i) << ' ';
    } std::cout << "\n";
}


template <typename T>
bool List<T>::is_cyclic() {
    if (head->next == nullptr) {
        return false;
    }

    Node<int64_t>* fast_pointer = head->next;
    Node<int64_t>* slow_pointer = head;

    while (fast_pointer->next != head && fast_pointer->next->next != head && fast_pointer != slow_pointer) {
        fast_pointer = fast_pointer->next->next;
        slow_pointer = slow_pointer->next;
    }

    if (fast_pointer == slow_pointer) {
        return true;
    }

    return false;
}

template <typename T>
void List<T>::make_cycle(int64_t first_index_of_cycle, int64_t len_of_cycle) {
    if (first_index_of_cycle >= size || first_index_of_cycle < 0 || len_of_cycle < 0 || len_of_cycle > size - first_index_of_cycle) {
        throw SizeOfCycleException(first_index_of_cycle, len_of_cycle);
    }
    
    if (len_of_cycle == 0) {    //remain current List without changes
        return;
    }

    Node<T>* start = head->next;
    while (first_index_of_cycle > 0) {
         start = start->next;
         --first_index_of_cycle;
    }

    Node<T>* finish = start;
    --len_of_cycle;
    while (len_of_cycle > 0) {
        finish = finish->next;
        --len_of_cycle;
    }

    finish->next = start;
}


int main() {
    int64_t n;
    while (std::cin >> n) {
        if (n < 0) {
            std::cout << "Incorrect input data\n";
            break;
        }
        
        List<int64_t> l;
        int64_t elem;
        for (int64_t i = 0; i != n; ++i) {
            std::cin >> elem;
            l.PushBack(elem);
        }
        
        l.PrintList();
        
        int64_t begin, len;
        std::cin >> begin >> len;
        std::cout << "index of starting cycle = " << begin << "\tlen of cycle = " << len << '\n';
        try {
          l.make_cycle(begin, len);
        } catch (const SizeOfCycleException& ex) {
            std::cerr << "Size of cycle is not correct: " << "\nindex = " << ex.index << "\tlen = " << ex.len << '\n';
        }
        

        if (l.is_cyclic()) {
            std::cout << "List has cycle\n\n";
        } else {
            std::cout << "List hasn't cycle\n\n";
        }
    }
}
