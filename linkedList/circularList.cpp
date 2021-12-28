#include <iostream>

class Node{
    int mData;
    Node* mNext;


    //creates a node inserts the data returns the pointer to node 
    Node* getNode(int data){
        Node* newNode=new Node;
        newNode->mData=data;
        newNode->mNext=nullptr;
        return newNode;
    }
public:
    Node(){
        this->mNext=nullptr;
    }
    bool empty(){
        return (this->mNext==nullptr);
    }

    void insertFront(int data){
        Node* temp1=getNode(data);
        if(empty()){
            this->mNext=temp1;
            temp1->mNext=this->mNext;
            return;
        }
        Node* temp2=mNext;
        temp1->mNext=temp2->mNext;
        temp2->mNext=temp1;
    }

    void insertRear(int data){
        Node* temp1=getNode(data);
        temp1->mNext=this->mNext->mNext;
        this->mNext->mNext=temp1;
        this->mNext=temp1;
    }

    void reverseList(){
        Node* temp1=this->mNext;
        
    }

    void printList(){
        Node* temp=this->mNext->mNext;
        while(temp!=this->mNext){
            std::cout<<temp->mData<<'\t';
            temp=temp->mNext;
        }
        std::cout<<this->mNext->mData;
    }
};
int main(){


    Node n;
    n.insertFront(1);
    n.insertFront(2);
    n.insertFront(3);
    n.insertFront(4);
    n.insertRear(0);
    n.insertRear(-1);
    n.printList();
    std::cin.get();
    return 0;
}