#include <iostream>
#include <stdexcept>
using namespace std;
/*template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;

    Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class Queue {
private:
    Node<T>* head;
    Node<T>* tail;
    size_t size;   

public:
    Queue() : head(nullptr), tail(nullptr), size(0) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        ++size;
    }

 
    void dequeue() {
        if (isEmpty()) {
            throw underflow_error("empty.");
        }

        Node<T>* temp = head;
        if (head == tail) { 
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        --size;
    }

    T& front() const {
        if (isEmpty()) {
            throw underflow_error("empty..");
        }
        return head->data;
    }

    bool isEmpty() const {
        return size == 0;
    }

    size_t getSize() const {
        return size;
    }

    void print() const {
        Node<T>* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Queue<int> queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Queue : ";
    queue.print();

    cout << "Front element: " << queue.front() << std::endl;

    queue.dequeue();
    cout << "After: ";
    queue.print();

    queue.enqueue(40);
    cout << "After (40): ";
    queue.print();

    std::cout << "Queue size: " << queue.getSize() << endl;

    return 0;
}


template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;

    Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class Queue {
private:
    Node<T>* head;
    Node<T>* tail;
    size_t size;

public:
    Queue() : head(nullptr), tail(nullptr), size(0) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        ++size;
    }

    void dequeue() {
        if (isEmpty()) {
            throw underflow_error("Queue is empty.");
        }
        Node<T>* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        --size;
    }

    T& front() const {
        if (isEmpty()) {
            throw underflow_error("Queue is empty.");
        }
        return head->data;
    }

    bool isEmpty() const {
        return size == 0;
    }

    size_t getSize() const {
        return size;
    }

    void print() const {
        Node<T>* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    Queue<T> clone() const {
        Queue<T> newQueue;
        Node<T>* current = head;
        while (current) {
            newQueue.enqueue(current->data);
            current = current->next;
        }
        return newQueue;
    }


    Queue<T> operator+(const Queue<T>& other) const {
        Queue<T> newQueue = this->clone();
        Node<T>* current = other.head;
        while (current) {
            newQueue.enqueue(current->data);
            current = current->next;
        }
        return newQueue;
    }


    Queue<T> operator*(const Queue<T>& other) const {
        Queue<T> newQueue;
        Node<T>* current = head;
        while (current) {
            Node<T>* otherCurrent = other.head;
            while (otherCurrent) {
                if (current->data == otherCurrent->data) {
                    newQueue.enqueue(current->data);
                    break;
                }
                otherCurrent = otherCurrent->next;
            }
            current = current->next;
        }
        return newQueue;
    }
};

int main() {
    Queue<int> queue1;
    queue1.enqueue(10);
    queue1.enqueue(20);
    queue1.enqueue(30);

    Queue<int> queue2;
    queue2.enqueue(20);
    queue2.enqueue(40);
    queue2.enqueue(30);

    cout << "Queue 1: ";
    queue1.print();

    cout << "Queue 2: ";
    queue2.print();


    Queue<int> clonedQueue = queue1.clone();
    cout << "Cloned Queue 1: ";
    clonedQueue.print();


    Queue<int> mergedQueue = queue1 + queue2;
    cout << "Merged Queue: ";
    mergedQueue.print();


    Queue<int> common = queue1 * queue2;
    cout << "Common elements: ";
    common.print();

    return 0;
} */

template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;

    Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class Array {
private:
    Node<T>* head; 
    Node<T>* tail; 
    size_t size;  

public:
    
    Array() : head(nullptr), tail(nullptr), size(0) {}

    ~Array() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }

    void Add(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        ++size;
    }

    T& Get(size_t index) const {
        Node<T>* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    size_t GetSize() const {
        return size;
    }

    void Print() const {
        Node<T>* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Array<int> arr;

    arr.Add(10);
    arr.Add(20);
    arr.Add(30);

    cout << "array elements: ";
    arr.Print();

    cout << "array size: " << arr.GetSize() << endl;

    cout << "element at index 1: " << arr.Get(1) << endl;

    return 0;
}
