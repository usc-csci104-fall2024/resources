#include "Queue.h"

// empty constructor
Queue::Queue() {

}

// empty destructor
Queue::~Queue() {

}

// do not change
void Queue::enqueue(int x) {
    stack1.push(x);
}

// you implement this!!!
void Queue::dequeue() {

}

// you implement this!!!
int Queue::front() {
    return 0;
}

// do not change
bool Queue::empty() {
    return stack1.empty() && stack2.empty();
}