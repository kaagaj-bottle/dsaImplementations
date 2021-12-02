#include <iostream>
#include <cassert>
//linked stack implementation of stack
template<class T>
class Stack
{
private:
//mData contains the data in the node
//mNext contains the address of the next node

    T mData;
    Stack* mNext;
public:
    Stack()
    {
        //when a Stack is initialized the first mNext points to a null pointer
        mNext=nullptr;
    }
    //checks if the stack is empty or not
    bool empty();
    //inserts node at the front end of the stack
    void push(T value);
    //removes the node from the front end of the stack and returns the data inside it
    T pop();
    //returns the data in the top most node in the stack
    T top();
};

template<class T>
bool Stack<T>::empty()
{
    return (mNext==nullptr);
}

template<class T>
void Stack<T>::push(T value)
{
//a new node is created data is set for it
//temp->mNext points to the node pointed by first node
//head then points to the newly created node
    Stack* temp=new Stack;
    temp->mData=value;
    temp->mNext=mNext;
    mNext=temp;
}

template<class T>
T Stack<T>::pop()
{
    //first we assert that the stack is not empty
    assert(!empty()&&"Error: the stack is empty nothing to pop");
    //temp points to the node pointed by the head i.e. mNext
    Stack* temp=mNext;
    //the head then points to the node pointed by temp->mNext i.e. the node at the 1st position 
    //in this way the node at zeroth position is detached
    //the data in detached node is then stored the zeroth node deleted and then the data is simply returned
    mNext=temp->mNext;
    int value=temp->mData;
    delete temp;
    return value;
}

template<class T> 
T Stack<T>::top()
{
    return mNext->mData;
}

int main()
{
    Stack<int> s;
    s.push(1);
    s.push(34);
    std::cout<<s.pop();
    std::cout<<s.pop();
    std::cin.get();
    return 0;
}