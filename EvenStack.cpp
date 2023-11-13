#include "EvenStack.h"

using namespace std;

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
