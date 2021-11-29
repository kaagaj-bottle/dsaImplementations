#include <iostream>
#include <cassert>
//implementation of linked list with following features
//1.    void insertFront(T value);
//2.    void insertRear(T value);
//3.    void insertAtPos(T value,int pos);
//4.    T removeFront();
//5.    T removeRear();
//6.    T removeAtPos(int pos);
template<class T>
class Node
{
private:
//mData contains the data in the node
//mNext contains the address of the next node

    T mData;
    Node* mNext;
public:
    Node()
    {
        //when a Node is initialized the first mNext points to a null pointer
        mNext=nullptr;
    }
    //checks if the list is empty or not
    bool empty();
    //inserts element at the front end of the list
    void insertFront(T value);
    //inserts element at the rear end of the list
    void insertRear(T value);
    //inserts element at the desired end of the list
    void insertAtPos(T value,int pos);

    //removes the element from the front end of the list and returns it 
    T removeFront();
    //removes the element from the rear end of the list and returns it 
    T removeRear();
    //removes the element from the desired position of the list and returns it 
    T removeAtPos(int pos);

    //just prints the whole list
    void print();
};

template<class T>
bool Node<T>::empty()
{
    return (mNext==nullptr);
}

template<class T>
void Node<T>::insertFront(T value)
{

    Node* temp=new Node;
    temp->mData=value;
    temp->mNext=mNext;
    mNext=temp;
}

template<class T>
void Node<T>::insertRear(T value)
{
    if(mNext==nullptr)
    {
        Node* temp=new Node;
        temp->mData=value;
        temp->mNext=mNext;
        mNext=temp;
        return;
    }
    Node* temp=mNext;
    while(temp->mNext!=nullptr)
    {
        temp=temp->mNext;
    }

    Node* newNode=new Node;
    newNode->mData=value;
    newNode->mNext=nullptr;
    temp->mNext=newNode;
}

template<class T>
void Node<T>::insertAtPos(T value, int pos)
{
    if(pos==0)
    {
        insertFront(value);
        return;
    }
    Node* temp1=new Node;
    temp1->mData=value;
    Node* temp2=mNext;
    for(int i=0;i<pos-1;++i)
    {
        temp2=temp2->mNext;
    }
    temp1->mNext=temp2->mNext;
    temp2->mNext=temp1;

}
template<class T>
T Node<T>::removeFront()
{
    assert(!empty()&&"Error: the list is empty nothing to remove");
    Node* temp=mNext;
    mNext=temp->mNext;
    int value=temp->mData;
    delete temp;
    return value;
}

template<class T>
T Node<T>::removeRear()
{
    assert(!empty()&&"Error: the list is empyt nothing to remove");
    
    Node* temp=mNext;
    if(temp->mNext==nullptr)
    {
        mNext=nullptr;
        int value=temp->mData;
        delete temp;
        return value;
    }
    Node* temp2;
    while(temp->mNext!=nullptr)
    {
        temp2=temp;
        temp=temp->mNext;
    }
    temp2->mNext=nullptr;
    int value=temp->mData;
    delete temp;
    return value;
}

template<class T>
T Node<T>::removeAtPos(int pos)
{
    assert(!empty()&&"Error: the list is empyt nothing to remove");
    if(pos==0)
    {
        return removeFront();
    }
    else
    {
        Node* temp1=mNext;
        for(int i=0;i<pos-1;++pos)
        {
            temp1=temp1->mNext;
        }
        Node* temp2=temp1->mNext;
        temp1->mNext=temp2->mNext;
        int value=temp2->mData;
        delete temp2;
        return value;
    }
}
template<class T>
void Node<T>::print()
{
    Node* temp=mNext;
    while(temp!=NULL)
    {
        printf("%d ",temp->mData);
        temp=temp->mNext;
    }
    printf("\n");
}


int main()
{
    Node<int> list;
    std::cout<<list.empty()<<'\n';
    list.insertFront(3);
    std::cout<<list.removeRear();
   
    list.print();
    std::cin.get();
    return 0;
}