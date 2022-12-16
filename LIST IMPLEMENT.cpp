#include <iostream>

class List {
public:
    struct Node {
        int value;
        Node* next;
        Node* prev;

        Node(int value = 0, Node* next = nullptr, Node* prev = nullptr): value(value), next(next), prev(prev) {}
    };

private:
    int _size;
    Node* _head;
    Node* _tail;
    
    static void _connect(Node* left, Node* right) {
        left->next = right;
        right->prev = left;
    }

    void _increment_size() {
        ++_size;
    }

    void _decrement_size() {
        --_size;
    }

public:
    List()
        : _size(0), _head(new Node), _tail(new Node)
    {
        _connect(_head, _tail);
    }

    Node* insert(Node* pos, int value) {
        Node* tmp = new Node(value);
        _connect(pos->prev, tmp);
        _connect(tmp, pos);
        _increment_size();
        return tmp;
    }

    Node* push_front(int value) {
        insert(begin(), value);
    }

    Node* erase(Node* pos) {
        _connect(pos->prev, pos->next);
        
        Node* tmp = pos->next;
        delete pos;
        _decrement_size();

        return tmp;        
    }

    int size() const {
        return _size;
    }

    int& front() {
        return _head->next->value;
    }

    const int& front() const {
        return _head->next->value;
    }

    Node* begin() {
        return _head->next;
    }

    Node* end() {
        return _tail;
    }
};

int main() {
    List l;

    l.insert(l.end(), 1);
    l.insert(l.end(), 2);
    l.insert(l.end(), 3);
    l.insert(l.end(), 4); // 1 2 3 4

    for(List::Node* it = l.begin(); it != l.end(); it = it->next) {
        std::cout << it->value << " ";
    }
    std::cout << std::endl;

    List::Node* node = l.begin();
    while(node != l.end()) {
       if(node->value % 2 == 0) {
         node = l.erase(node);
       } else {
         node = node->next;
       }
    }
    for(List::Node* it = l.begin(); it != l.end(); it = it->next) {
        std::cout << it->value << " ";
    }
    std::cout << std::endl;
    
}



