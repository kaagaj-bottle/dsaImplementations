#include <iostream>
#include <cassert>

//here the this->mNext is the head
template<class T>
class Queue
{
private:
//mData contains the data in the node
//mNext contains the address of the next node
    T mData;
    Queue* mNext;
public:
    Queue()
    {
        //when a Queue is initialized the first mNext points to a null pointer
        mNext=nullptr;
    }
    //checks if the queue is empty or not
    bool empty();
    //inserts node at the rear end of the list
    void insert(T value);
    //removes the element from the front end of the list and returns it 
    T remove();
    //just return the element in the front end of the list
    T front();
};

template<class T>
bool Queue<T>::empty()
{
    return (mNext==nullptr);
}


template<class T>
void Queue<T>::insert(T value)
{
    //when the queue is empty
    if(mNext==nullptr)
    {
        Queue* temp=new Queue;
        temp->mData=value;
        temp->mNext=mNext;
        mNext=temp;
        return;
    }
    //first we traverse the last node in the queue using a temp pointer
    //temp points to the last node in the last so that temp->mNext points to nullptr
    Queue* temp=mNext;
    while(temp->mNext!=nullptr)
    {
        temp=temp->mNext;
    }
    //then we create a new node and set its mNext to nullptr
    Queue* newQueue=new Queue;
    newQueue->mData=value;
    newQueue->mNext=nullptr;
    //the ex-last last node then points to new node which now becomes the last node
    temp->mNext=newQueue;
}

template<class T>
T Queue<T>::remove()
{
    //first we assert that the queue is not empty
    assert(!empty()&&"Error: the queue is empty nothing to remove");
    //temp points to the node pointed by the head i.e. mNext
    Queue* temp=mNext;
    //the head then points to the node pointed by temp->mNext i.e. the node at the 1st position 
    //in this way the node at zeroth position is detached
    //the data in detached node is then stored the zeroth node deleted and then the data is simply returned
    mNext=temp->mNext;
    int value=temp->mData;
    delete temp;
    return value;
}

template<class T>
T Queue<T>::front()
{
    return mNext->mData;
}
int main()
{
    Queue<int> q;
    q.insert(1);
    std::cout<<q.remove();
    q.insert(3);
    q.insert(2);
    std::cout<<q.front();
    std::cout<<q.remove();
    std::cout<<q.remove();
    std::cin.get();
    return 0;
}