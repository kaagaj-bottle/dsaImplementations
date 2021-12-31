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
//5.    insertAtPos()==>position starts with zero
//6.    removeAtPos()==position starts with zero
//n-1.    printListF()
//n.    printListR()
//Note: this mData keeps the track of size of the list
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
        this->mData=0;
        this->mPrev=nullptr;
    }

    bool empty();
    void insertFront(T data);
    void insertRear(T data);
    T removeFront();   
    T removeRear();
    void insertAtPos(T data, int pos);
    T removeAtPos(int pos);

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
        ++this->mData;
        return;
    }
    temp1->mNext=this->mNext;
    temp1->mPrev=nullptr;
    this->mNext->mPrev=temp1;
    this->mNext=temp1;
    ++this->mData;
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
    ++this->mData;
}

template<class T>
T DLNode<T>::removeFront(){
    assert(!empty()&&"Error: removal invalid as the list is empty\n");
    if(this->mNext->mNext==nullptr){
        DLNode* temp1=this->mNext;
        mNext=nullptr;
        mPrev=nullptr;
        --this->mData;
        return freeNodeExtractData(temp1);
    }
    DLNode* temp1=this->mNext;
    this->mNext->mNext->mPrev=nullptr;
    this->mNext=this->mNext->mNext;
    --this->mData;
    return freeNodeExtractData(temp1);
}

template<class T>
T DLNode<T>::removeRear(){
    assert(!empty()&&"Error: removal invalid as the list is empty\n");
    if(this->mNext->mNext==nullptr){
        --this->mData;
        return removeFront();
    }
    DLNode* temp1=this->mPrev;
    this->mPrev->mPrev->mNext=nullptr;
    this->mPrev=this->mPrev->mPrev;
    --this->mData;
    return freeNodeExtractData(temp1);
}

template<class T>
void DLNode<T>::insertAtPos(T data,int pos){
    if(empty()&&(pos!=0)){
        std::cout<<"Error: the list is empty so no position other than 0 is available\n";
        return;
    }
    if(pos>this->mData){
        std::cout<<"Error: list size exceeded\n";
        return;
    }
    if(pos==0){
        insertFront(data);
        return;
    }
    if(pos==this->mData){
        insertRear(data);
        return;
    }
    DLNode* temp1=this->mNext;
    for(int i=0;i<pos;++i){
        temp1=temp1->mNext;
    }
    DLNode* temp2=getNodeAddData(data);
    temp2->mNext=temp1;
    temp2->mPrev=temp1->mPrev;
    temp2->mPrev->mNext=temp2;
    temp1->mPrev=temp2;
    ++this->mData;

}

template<class T>
T DLNode<T>::removeAtPos(int pos){
    assert(!empty()&&"Error: invalid removal as the list is empty");
    assert(!(pos>=this->mData)&&"Error: invalid removal as pos > size of list");
    if(pos==0){
        return removeFront();
    }

    if(pos==mData-1){
        return removeRear();
    }
    DLNode* temp1=this->mNext;
    for(int i=0;i<pos;++i){
        temp1=temp1->mNext;
    }

    temp1->mNext->mPrev=temp1->mPrev;
    temp1->mPrev->mNext=temp1->mNext;
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

    
    return 0;
}