#include <iostream>
#include <cassert>

//stack with desired data type and desired size can be created
template< class T,int size>
class Stack
{
private:
    int mIndex;
    T* mData;
public:
    Stack()
    {
        assert(size>0&&"size of the stack too small");
        //allocation of size amount of T datatype if the size is greater than 0
        mData=new T[size];
        //value of -1 for index is used to denote that the stack is empty
        mIndex=-1;
    }

    ~Stack()
    {
        delete[] mData;
    }
    //pushes the value of type T into the stack if stack size is not exceeded
    void push(T value);
    //returns true if the stack if empty
    bool empty();
    //pops the top most element of the stack and returns it to the user
    T pop();
    //returs the top most element of the stack
    T top();
    

};

template<class T,int size>
void Stack<T,size>::push(T value)
{
    assert((mIndex<=size-1)&&"Error: size of the stack exceeded\n");
    mData[++mIndex]=value;
}

//returns true if the stack is empty
template<class T,int size>
bool Stack<T,size>::empty()
{
    if(mIndex==-1)
        return true;
    else
        return false;
}

template<class T,int size>
T Stack<T,size>::pop()
{
    assert(!empty()&&"Error: stack is empty can't pop\n");
    T returnValue;
    returnValue=mData[mIndex--];
    return returnValue;
}

template<class T,int size>
T Stack<T,size>::top()
{
    assert(empty()&&"Error: stack is empty");
    return mData[mIndex];
}



int main()
{
    Stack<double,10> s;
    for(int i=0;i<10;++i)
    {
        s.push(i);
    }
    for(int i=0;i<10;++i)
    {
        std::cout<<s.pop();
    }

    std::cout<<"\n"<<s.empty();
    std::cin.get();
    return 0;
}