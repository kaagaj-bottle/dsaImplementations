#include <iostream>
#include <cassert>
#include <string>
template<class T>
class Node{
    T mData;
    Node* mNext;


    //creates a node inserts the data returns the poTer to node 
    Node* getNode(T data){
        Node* newNode=new Node;
        newNode->mData=data;
        newNode->mNext=nullptr;
        return newNode;
    }

    T freeNodeExtractData(Node* node){
        T data=node->mData;
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

    void insertFront(T data){
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

    void insertRear(T data){
        Node* temp1=getNode(data);
        if(empty()){
            this->mNext=temp1;
            temp1->mNext=this->mNext;
            return;
        }
        
        temp1->mNext=this->mNext->mNext;
        this->mNext->mNext=temp1;
        this->mNext=temp1;
    }

    T removeFront(){
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
    
    T removeRear(){
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
    
    void insertAfter(T data, T key){
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

    T removeAfter(T key){

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
        std::cout<<temp->mData<<'\n';
        
    }

    T josephusProblemSolution(){
        
        int n;
        Node* temp=mNext;
        Node* prev=this->mNext;
        Node* current=this->mNext->mNext;
        printList();
        while(temp->mNext!=this->mNext){
            std::cout<<"Enter a number: ";
            std::cin>>n;
            std::cin.ignore(32767,'\n');
            for(int i=0;i<n-1;++i){
                prev=current;
                current=current->mNext;
            }
            if(current==this->mNext)
            {
                std::cout<<removeRear()<<" has been removed"<<'\n';
                printList();
                continue;
            }
            Node* temp=current;
            current=current->mNext;
            prev->mNext=current;
            std::cout<<freeNodeExtractData(temp)<<" has been removed"<<'\n';
            printList();
        }

        return this->mNext->mData;
    }
};



int main(){

    Node<std::string> n;
    n.insertRear("a");
    n.insertRear("b");
    n.insertRear("c");
    n.insertRear("d");
    n.insertRear("e");
    std::cout<<n.josephusProblemSolution()<<" will ride the horse\n";
    std::cin.get();
    return 0;
}