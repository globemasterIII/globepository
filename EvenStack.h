#ifndef EVENSTACK_H
#define EVENSTACK_H

#include <stack>

using namespace std;

class EvenStack

{
private:
    
    stack<int> evenStack;

public:
    size_t size() const;
    int top() const;
    void push(int value);
    void pop();
    void getEvenNumbers(stack<int> & inStack);
    void emptyStack();
};

#endif
