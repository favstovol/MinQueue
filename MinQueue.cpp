#include <iostream>
#include <utility>

struct Node {
 public:
    int element;
    int min;
    Node *next;
};

class MinStack {
 public:
    int topElement() {
        return head->element;
    }

    int topMin() {
        return head->min;
    }

    void push(int value) {
        if (head == NULL) {
            head = new Node();
            head->element = value;
            head->min = value;
            head->next = NULL;
        } else {
            Node* tmp = new Node();
            tmp->element = value;
            if (head->min < value)
                tmp->min = head->min;
            else
                tmp->min = value;
            tmp->next = head;
            head = tmp;
        }
    }

    void pop() {
        Node* tmp = head->next;
        delete head;
        head = tmp;
    }

    bool empty() {
        return (head == NULL);
    }

 private:
    Node* head = NULL;
};

class MinQueue {
 public:
    int GetMin() {
        if (first.empty() || second.empty())
            return first.empty() ? second.topMin() : first.topMin();
        else if (first.topMin() < second.topMin())
            return first.topMin();
        else
            return second.topMin();
    }

    void push(int value) {
        first.push(value);
    }

    void pop() {
        if (second.empty()) {
            while (!first.empty()) {
                second.push(first.topElement());
                first.pop();
            }
        }
        second.pop();
    }

    bool empty() {
        return (first.empty() && second.empty());
    }

 private:
    MinStack first, second;
};

int main() {
    int number_of_elements, size_of_window;
    std::cin >> number_of_elements >> size_of_window;
    MinQueue queue;
    for (int i = 0; i < size_of_window - 1; ++i) {
        int element;
        std::cin >> element;
        queue.push(element);
    }

    for (int i = size_of_window; i <= number_of_elements; ++i) {
        int element;
        std::cin >> element;
        queue.push(element);
        std::cout << queue.GetMin() << "\n";
        queue.pop();
    }

    while (!queue.empty()) {
        queue.pop();
    }
}

