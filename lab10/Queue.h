#ifndef QUEUE_H
#define QUEUE_H

#include <stack>

class Queue {
    public:
        Queue();
        ~Queue();
        void enqueue(int x);
        void dequeue();
        int front();
        bool empty(); 

    private:
        std::stack<int> stack1;
        std::stack<int> stack2;
};


#endif