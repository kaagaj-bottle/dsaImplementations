#include <iostream>
#include <cassert>
#include <string>
//implementation of linked list with following features
//1.    void insertFront(T value);
//2.    void insertRear(T value);
//3.    void insertAtPos(T value,int pos);
//4.    T removeFront();
//5.    T removeRear();
//6.    T removeAtPos(int pos);

//here the this->mNext is the head
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
//a new node is created data is set for it
//temp->mNext points to the node pointed by first node
//head then points to the newly created node
    Node* temp=new Node;
    temp->mData=value;
    temp->mNext=mNext;
    mNext=temp;
}

template<class T>
void Node<T>::insertRear(T value)
{
    //when the list is empty the mechanism for inserting to the rear is the same as insertFront
    if(mNext==nullptr)
    {
        Node* temp=new Node;
        temp->mData=value;
        temp->mNext=mNext;
        mNext=temp;
        return;
    }
    //first we traverse the last node in the list using a temp pointer
    //temp points to the last node in the last so that temp->mNext points to nullptr
    Node* temp=mNext;
    while(temp->mNext!=nullptr)
    {
        temp=temp->mNext;
    }
    //then we create a new node and set its mNext to nullptr
    Node* newNode=new Node;
    newNode->mData=value;
    newNode->mNext=nullptr;
    //the ex-last last node then points to new node which now becomes the last node
    temp->mNext=newNode;
}

template<class T>
void Node<T>::insertAtPos(T value, int pos)
{
    //if the insert position in zero then simply insertFront
    if(pos==0)
    {
        insertFront(value);
        return;
    }
    //for position other than zero
    //a new node is created
    //then another node pointer is created which is used to traverse pos-1 position
    //example: ^^if we want to insert at 1st position then we traverse such that temp2 points to zeroth positioned node
    Node* temp1=new Node;
    temp1->mData=value;
    Node* temp2=mNext;
    for(int i=0;i<pos-1;++i)
    {
        temp2=temp2->mNext;
    }
    //temp1->mNext then points node after the temp2 which is temp2->mNext
    temp1->mNext=temp2->mNext;
    //temp2->mNext then simply points to temp1 completing the operation
    temp2->mNext=temp1;
    //^^the new node's mNext points to the node which was initially in 1st position
    //^^zeroth positioned node's mNext points to new node 
}
template<class T>
T Node<T>::removeFront()
{
    //first we assert that the list is not empty
    assert(!empty()&&"Error: the list is empty nothing to remove");
    //temp points to the node pointed by the head i.e. mNext
    Node* temp=mNext;
    //the head then points to the node pointed by temp->mNext i.e. the node at the 1st position 
    //in this way the node at zeroth position is detached
    //the data in detached node is then stored the zeroth node deleted and then the data is simply returned
    mNext=temp->mNext;
    T value=temp->mData;
    delete temp;
    return value;
}

template<class T>
T Node<T>::removeRear()
{
    //first we assert that the list is not empty
    assert(!empty()&&"Error: the list is empyt nothing to remove");
    //the deletion of rearNode when there is just one node is same as removal of the front node
    Node* temp=mNext;
    if(temp->mNext==nullptr)
    {
        mNext=nullptr;
        T value=temp->mData;
        delete temp;
        return value;
    }
    //first we traverse such that temp points to last node and temp2 points the second last node
    Node* temp2;
    while(temp->mNext!=nullptr)
    {
        temp2=temp;
        temp=temp->mNext;
    }
    //temp2->mNext then is set to null ptr causing the last node to get detached
    temp2->mNext=nullptr;
    //the value in the last node is stored for returning and the node itself is deleted
    T value=temp->mData;
    delete temp;
    return value;
}

template<class T>
T Node<T>::removeAtPos(int pos)
{
    //first we assert that the list is not empty
    assert(!empty()&&"Error: the list is empyt nothing to remove");
    //for pos zero same as removeFront()
    if(pos==0)
    {
        return removeFront();
    }
    else
    {
        //traverse such that temp1 points node to position just before the position at which node is to be removed
        //for example ^^if we want to remove node at 1st position we traverse such that temp1 points to node at zeroth position
        Node* temp1=mNext;
        for(int i=0;i<pos-1;++i)
        {
            temp1=temp1->mNext;
        }
        //temp2 points the node pointed by the temp1->mNext which the node we want to remove
        //^^temp2 points to the node at 1st position
        Node* temp2=temp1->mNext;
        //then temp1 points the node just after the node we want to remove
        //^^temp to points to the node at 2nd position causing the node at 1st position to be detached
        temp1->mNext=temp2->mNext;
        //data is stored to return and node at 1st position is deleted
        T value=temp2->mData;
        delete temp2;
        return value;
    }
}
template<class T>
void Node<T>::print()
{
    //simply for printing the data in the list from first to last 
    Node* temp=mNext;
    while(temp!=NULL)
    {
        std::cout<<temp->mData<<' ';
        temp=temp->mNext;

    }
    printf("\n");
}


int main()
{
    Node<std::string> list;
    list.insertFront("zishan");
    list.insertAtPos("siddique",0);
    list.insertAtPos("life",2);
    list.removeAtPos(0);
    list.print();
    std::cin.get();
    return 0;
}