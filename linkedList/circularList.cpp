#include <iostream>
#include <cassert>
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

    int freeNodeExtractData(Node* node){
        int data=node->mData;
        delete node;
        return data;
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
        if(empty()){
            this->mNext=temp1;
            temp1->mNext=this->mNext;
            return;
        }
        
        Node* temp1=getNode(data);
        temp1->mNext=this->mNext->mNext;
        this->mNext->mNext=temp1;
        this->mNext=temp1;
    }

    int removeFront(){
        assert(!empty()&&"Error: the list is empty nothing to remove\n");
        if(this->mNext==this->mNext->mNext){
            Node* temp1=this->mNext;
            mNext=nullptr;
            return freeNodeExtractData(temp1);
        }
        Node* temp1=this->mNext->mNext;
        this->mNext->mNext=temp1->mNext;
        return freeNodeExtractData(temp1);
    }
    
    int removeRear(){
        if(this->mNext==this->mNext->mNext){
            return removeFront();
        }
        Node* temp1=this->mNext->mNext;
        while(temp1->mNext!=this->mNext){
            temp1=temp1->mNext;
        }
        Node* temp2=this->mNext;
        temp1->mNext=this->mNext->mNext;
        mNext=temp1;
        return freeNodeExtractData(temp2);
    }
    
    void insertAfter(int data, int key){
        if(key==this->mNext->mData){
            Node* temp1=getNode(data);
            temp1->mNext=this->mNext->mNext;
            this->mNext->mNext=temp1;
            this->mNext=temp1;
            return;
        }

        Node* temp1=this->mNext->mNext;
        while((temp1->mData!=key)&&(temp1!=mNext)){
            temp1=temp1->mNext;
        }
        if(temp1==mNext){
            std::cout<<"key unavailable, insert unsuccessful \n";
            return;
        }
        Node* temp2=getNode(data);
        temp2->mNext=temp1->mNext;
        temp1->mNext=temp2;
    }

    int removeAfter(int key){

    }
    void printList(){
        if(empty()){
            return;
        }
        Node* temp=this->mNext->mNext;
        while(temp!=this->mNext){
            std::cout<<temp->mData<<'\t';
            temp=temp->mNext;
        }
        std::cout<<temp->mData;
        
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
    n.insertAfter(-2,-1);
    n.insertAfter(99,-2);
    n.printList();
    std::cin.get();
    return 0;
}