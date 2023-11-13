// Name: Michel B
// Project: 04
// Date: 11/12/23
// Description: 
// To write a class EvenStack that implements a
// stack of integers that contains only even numbers.


#include <iostream>
#include <stack>
#include "EvenStack.h"

using namespace std;

#include "EvenStack.h"

int EvenStack::top() const
{
    return evenStack.top();
}

size_t EvenStack::size() const
{
    return evenStack.size();
}


void EvenStack::push(int value)
{
    if (value % 2 == 0)
    
    {
        evenStack.push(value);
    }
    
    else
    {
      cout << "Error - can only push even numbers" << endl;
    }
}


void EvenStack::pop()
{
    evenStack.pop();
}

void EvenStack::getEvenNumbers(stack<int>& inStack)

{
    while (!inStack.empty())
    {
        int value = inStack.top();
        inStack.pop();
        if (value % 2 == 0)
        {
            evenStack.push(value);
        }
    }
}

void EvenStack::emptyStack()
{
    while (!evenStack.empty())
    {
        cout << evenStack.top() << "  ";
        evenStack.pop();
    }
}



int main()

{
    EvenStack myStack;
    myStack.push(44);
    myStack.push(66);
    myStack.push(99);
    myStack.push(88);
    myStack.pop();
    myStack.emptyStack();

    stack<int> aStack;

    aStack.push(2);
    aStack.push(9);
    aStack.push(6);
    aStack.push(2);
    aStack.push(3);
    aStack.push(5);
    aStack.push(4);

    EvenStack newStack;
    newStack.push(32);
    newStack.getEvenNumbers(aStack);

    cout << endl;
    cout << "aStack has " << aStack.size() << " elements" << endl;
    cout << "myStack has " << myStack.size() << " elements" << endl;
    cout << "newStack has " << newStack.size() << " elements" << endl;

    cout << endl;
    {
        cout << newStack.top() << "  ";
        newStack.pop();
    }
    cout << endl;

    return 0;
}
