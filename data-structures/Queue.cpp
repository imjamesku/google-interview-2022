#include <iostream>
using namespace std;

class IQueue {
   public:
    virtual ~IQueue() {}
    virtual void enqueue(int) = 0;
    virtual void dequeue() = 0;
    virtual int getFront() = 0;
};
static const int QUEUE_SIZE = 1000;
class Queue : IQueue {
   public:
    Queue() : front(0), back(0) {}
    void enqueue(int val) {
        if ((back + 1) % 1000 == front) {
            throw "queue is full";
        }
        data[back] = val;
        back = (back + 1) % QUEUE_SIZE;
    }

    void dequeue() {
        if (front == back) {
            throw "Cannot dequeue empty queue";
        }
        front++;
    }

    int getFront() {
        if (front != back) {
            return data[front];
        }
        throw "Queue is empty";
    }

    void display() {
        for (int i = front; i < back; i++) {
            cout << data[i] << ",";
        }
        cout << "\n";
    }

   private:
    int data[QUEUE_SIZE];
    int front;
    int back;
};

int main(void) {
    Queue q;
    q.enqueue(1);
    q.display();
    q.dequeue();
    // q.dequeue();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    q.display();
    return 0;
}