#include <iostream>
class Node {
   public:
    int val;
    Node* next;

    Node(int val) : val(val), next(nullptr) {}
};
class ILinkedList {
   public:
    virtual ~ILinkedList() {}
    virtual void add(int) = 0;
    virtual void remove() = 0;
};

class LinkedList {
   private:
    Node* head = nullptr;

   public:
    void addNode(int value) {
        if (head == nullptr) {
            head = new Node(value);
        } else {
            auto newNode = new Node(value);
            newNode->next = head;
            head = newNode;
        }
    }
    void removeNode() {
        auto tmp = head;
        head = head->next;
        delete tmp;
    }
    int getHeadValue() {
        return head->val;
    }
    void display() {
        for (auto cur = head; cur != nullptr; cur = cur->next) {
            std::cout << cur->val << ",";
        }
        std::cout << "\n";
    }
};

int main(void) {
    LinkedList list;
    list.addNode(3);
    list.addNode(2);
    list.addNode(1);
    list.display();
    list.removeNode();
    list.display();

    // std::cout << list.getHeadValue() << std::endl;
}