#include <iostream>
using namespace std;
class IStack {
   public:
    virtual ~IStack() {}
    virtual int top() = 0;
    virtual void push(int) = 0;
    virtual void pop() = 0;
    virtual void display() = 0;
};

// array version
class Stack : IStack {
   private:
    int data[100];
    int len = 0;

   public:
    // top
    int top() {
        return data[len - 1];
    }
    // push
    void push(int value) {
        data[len] = value;
        len++;
    }
    // pop
    void pop() {
        len--;
    }

    void display() {
        for (unsigned int i = 0; i < len; i++) {
            cout << data[i] << ",";
        }
        cout << "\n";
    }
};

int main(void) {
    Stack stack;
    stack.push(1);
    stack.pop();
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.display();
    stack.pop();
    stack.push(4);
    stack.display();

    return 0;
}