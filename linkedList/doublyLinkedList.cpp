#include <iostream>
#include <cassert>
//doubly linked list
//this->mNext points to the this->mNext of the list
//this->mPrev points to the this->mPrev of the list
//its functionalities
//1.    insertFront()
//2.    insertRear()
//3.    removeFront()
//4.    removeRear()
//n-1.    printListF()
//n.    printListR()

template<class T>
class DLNode{
private:
    T mData;
    DLNode* mNext;
    DLNode* mPrev;

    DLNode* getNodeAddData(T data);
    T freeNodeExtractData(DLNode* temp);
public:
    DLNode(){
        this->mNext=nullptr;
        this->mPrev=nullptr;
    }

    bool empty();
    void insertFront(T data);
    void insertRear(T data);
    T removeFront();   
    T removeRear();
    void printListF();
    void printListR();

};


template<class T>
DLNode<T>* DLNode<T>::getNodeAddData(T data){
    DLNode* temp=new DLNode;
    temp->mData=data;
    temp->mNext=nullptr;
    temp->mPrev=nullptr;
    return temp;
}

template<class T>
T DLNode<T>::freeNodeExtractData(DLNode* temp){
    T data=temp->mData;
    delete temp;
    return data;
}

template<class T>
bool DLNode<T>::empty(){
    return ((this->mNext==nullptr)&&(this->mPrev==nullptr));
}

template<class T>
void DLNode<T>::insertFront(T data){
    DLNode* temp1=getNodeAddData(data);
    if(empty()){
        this->mNext=temp1;
        this->mPrev=temp1;
        return;
    }
    temp1->mNext=this->mNext;
    temp1->mPrev=nullptr;
    this->mNext->mPrev=temp1;
    this->mNext=temp1;
}

template<class T>
void DLNode<T>::insertRear(T data){
    if(empty()){
        insertFront(data);
        return;
    }
    DLNode* temp1=getNodeAddData(data);
    temp1->mNext=nullptr;
    temp1->mPrev=this->mPrev;
    this->mPrev->mNext=temp1;
    this->mPrev=temp1;
}

template<class T>
T DLNode<T>::removeFront(){
    assert(!empty()&&"Error: removal invalid as the list is empty\n");
    if(this->mNext->mNext==nullptr){
        DLNode* temp1=this->mNext;
        mNext=nullptr;
        mPrev=nullptr;
        return freeNodeExtractData(temp1);
    }
    DLNode* temp1=this->mNext;
    this->mNext=temp1->mNext;
    this->mNext->mPrev=nullptr;
    return freeNodeExtractData(temp1);
}

template<class T>
T DLNode<T>::removeRear(){
    assert(!empty()&&"Error: removal invalid as the list is empty\n");
    if(this->mNext->mNext=nullptr){
       return removeFront();
    }
    DLNode* temp1=this->mPrev;
    this->mPrev=temp1->mPrev;
    this->mPrev->mNext=nullptr;
    return freeNodeExtractData(temp1);

}
template<class T>
void DLNode<T>::printListF(){
    DLNode* temp=this->mNext;
    while(temp!=nullptr){
        std::cout<<temp->mData<<'\t';
        temp=temp->mNext;
    }
    std::cout<<std::endl;
}

template<class T>
void DLNode<T>::printListR(){
    DLNode* temp=this->mPrev;
    while(temp!=nullptr){
        std::cout<<temp->mData<<'\t';
        temp=temp->mPrev;
    }
    std::cout<<std::endl;
}
int main(){

    DLNode<int> list;
    list.insertFront(1);
    list.insertFront(2);
    list.insertFront(3);
    list.insertFront(4);
    list.insertFront(5);
    list.insertFront(6);
    list.insertFront(7);
    list.printListF();
    list.printListR();
    std::cout<<list.removeFront()<<std::endl;
    std::cout<<list.removeRear()<<std::endl;
    
    list.printListF();
    list.printListR();
    std::cin.get();
    return 0;
}