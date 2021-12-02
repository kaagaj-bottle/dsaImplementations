#include <iostream>
#include <cassert>
//the correct implementation of queue using linked list

template<class T>
class Queue;

template<class T>
class Node{
private:
    T mData;
    Node* mNext;
public:
    Node(){
        mNext=nullptr;
    }
    friend class Queue<T>;
};

template<class T>
class Queue{
private:
    Node<T>* mFront;
    Node<T>* mRear;
public:
    Queue(){
        mFront=nullptr;
        mRear=nullptr;
    }
    bool empty();
    void enQueue(T data);
    T deQueue();
    T front();
    }
};

template<class T>
bool Queue<T>::empty(){
    return ((mFront==nullptr)&&(mRear==nullptr));
}

template<class T>
void Queue<T>::enQueue(T data){
    
    Node<T>* temp=new Node<T>;
    temp->mData=data;
    temp->mNext=nullptr;
    if(empty()){
        mFront=temp;
        mRear=temp;
        return;
    }
    mRear->mNext=temp;
    mRear=temp;
}

template<class T>
T Queue<T>::deQueue(){
    assert(!empty()&&"Error: the queue is empty nothing to remove\n");
    Node<T>* temp=mFront;
    T data=temp->mData;
    mFront=temp->mNext;
    delete temp;
    return data;
}

template<class T>
T Queue<T>::front(){
    return mFront->mData;
}

int main(){

    Queue<int> q;
    q.enQueue(3);
    q.enQueue(5);
    q.enQueue(19);
    std::cout<<q.front()<<'\n';
    std::cout<<q.deQueue()<<'\n';

    std::cin.get();
    return 0;
}