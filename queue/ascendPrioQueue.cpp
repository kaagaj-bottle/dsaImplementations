#include <iostream>
#include <cassert>
//1 .here i have used concept of stack to implement ascending priority queue
//2 .the last element in the stack is always the smallest one
//3 .condition 2 can be implemented by sorting the stack every time an element is inserted into the stack
//4 .pretty sure it is not the most efficient solution but should work for now
template<class T, int size>
class AscendPrioQueue
{
private:
    int mIndex;
    T* mData;
public:
    AscendPrioQueue()
    {
        assert(size>0&&"size of the stack too small");
        //allocation of size amount of T datatype if the size is greater than 0
        mData=new T[size];
        //value of -1 for index is used to denote that the stack is empty
        mIndex=-1;
    }

    ~AscendPrioQueue()
    {
        delete[] mData;
    }
    //insertes the value of type T into the stack if stack size is not exceeded
    void insert(T value);
    //returns true if the stack if empty
    bool empty();
    //delete the samlllest element inside the queue and returns it to the user
    T minDelete();
    //returs the retrieve minimum element of the stack but does not delete
    T retrieve();
    //sorts the element inside the array
    //as we need the smallest element to retrieved first the mData is sorted in descending order
    void sortDescending();
};

template<class T,int size>
void AscendPrioQueue<T,size>::insert(T value)
{
    assert((mIndex<=size-1)&&"Error: size of the stack exceeded\n");
    mData[++mIndex]=value;
    sortDescending();
}

//returns true if the stack is empty
template<class T,int size>
bool AscendPrioQueue<T,size>::empty()
{
    if(mIndex==-1)
        return true;
    else
        return false;
}

template<class T,int size>
T AscendPrioQueue<T,size>::minDelete()
{
    assert(!empty()&&"Error: stack is empty can't minDelete\n");
    T returnValue;
    returnValue=mData[mIndex--];
    return returnValue;
}

template<class T,int size>
T AscendPrioQueue<T,size>::retrieve()
{
    assert(!empty()&&"Error: stack is empty");
    return mData[mIndex];
}
//just sorts the element insidemData in descending order
template<class T,int size>
void AscendPrioQueue<T,size>::sortDescending()
{
    int dummyValue;
    bool switched=true;
    for(int i=0;((i<mIndex)&&(switched==true));++i)
    {
        switched=false;
        for(int j=0;j<mIndex-i;++j)
        {
            if(mData[j]<mData[j+1])
            {
                switched=true;
                dummyValue=mData[j];
                mData[j]=mData[j+1];
                mData[j+1]=dummyValue;    
            }
        }
    }
}
int main()
{

    AscendPrioQueue<int,10> q;
    std::cout<<q.empty();
    q.insert(10);
    q.insert(12);
    q.insert(15);
    std::cout<<q.retrieve();
    std::cout<<q.minDelete();
    std::cout<<q.minDelete();
    std::cout<<q.minDelete();
    std::cin.get();
    return 0;
}