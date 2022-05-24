#include <iostream>

using namespace std;

template <typename typeInfo>
class List {
private:
    class Node {
    public:
        Node* next;
        Node* prev;
        typeInfo info;
    };

    size_t size;
    Node* head;
    Node* tail;

public:
    List() {
        head = tail = NULL;
        size = 0;
    };

    ~List() {
        clear();
    };

    void push_back(typeInfo info) {
        Node* cur = new Node;
        cur->info = info;
        if (head == NULL) {
        //    cur->prev = NULL;
        //    cur->next = NULL;
            head = tail = cur;
            size++;
        }
        else {
            tail->next = cur;
            cur->prev = tail;
        //    cur->next = NULL;
            tail = cur;
            size++;
        }
    };

    void push_front(typeInfo info) {
        Node* cur = new Node;
        cur->info = info;
        cur->next = NULL;
        cur->prev = NULL;
        if (head == NULL) { //the list is empty
            head = tail = cur;
            size++;
        }
        else {
            cur->next = head;
            head->prev = cur;
            head = cur;
            size++;
        }
    };

    void pop_back() {
        if (isEmpty() == 0)
            throw "The list is already empty";
        else {
            Node* del = new Node;
            if (head != NULL) { //the list is not empty
                if (head == tail) { //there is one item in the list
                    head = tail = NULL;
                    size--;
                }
                else {
                    del = tail;
                    tail = tail->prev;
                    delete del;
                    tail->next = NULL;
                    size--;
                }
            }
        }
    };

    void pop_front() {
        if (isEmpty() == true)
            throw "The list is already empty";
        else {
            Node* del = new Node;
            if (head != NULL) { //the list is not empty
                if (head == tail) { //there is one item in the list
                    head = tail = NULL;
                    size--;
                }
                else {
                    del = head;
                    head = head->next;
                    delete del;
                    head->prev = NULL;
                    size--;
                }
            }
        }
    };

    size_t get_size() {
        if (size >= 0)
            return size;
        else throw invalid_argument("Empty List");
    };

    void clear() {
        while (size != 0) {
            pop_front();
        }
    };

    bool isEmpty() { return get_size() == 0; };

    void push_back(List& list) {
        Node* newNode = list.head;
        for (int i = 0; i < (int)list.get_size(); i++) {
            this->push_back(newNode->data);
            newNode = newNode->pNext;
        }
    };

    friend std::ostream& operator<< (std::ostream& out, List& list) {
        size_t listSize = list.get_size();
        for (size_t i = 0; i < listSize; i++) {
            cout << list.at(i) << endl;
        }
        return out;
    }

    typeInfo at(int index) { //getting an item by index
        if (index < 0 || index > size) {
            throw out_of_range("Incorrect index");
        }
        else {
            int i = 0;
            Node* buf = head;
            while (i < index) {
                buf = buf->next;
                i++;
            }
            return buf->info;
        }
    }
};
