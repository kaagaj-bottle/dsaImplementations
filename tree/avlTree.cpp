#include <iostream>
#include <algorithm>
#include <queue>
#include <cassert>

//avl tree
template<class Type>
struct Node{
    Type mData;
    Node* mLeft;
    Node* mRight;
    int mHeight;

    Node (Type data):mData{data},mLeft{nullptr},mRight{nullptr},mHeight{0}{

    }
    
    Node():mLeft{nullptr},mRight{nullptr},mHeight{0}{

    }

};
//this->mNode is the root of the BBST
template<class T>
class BBST{
private:
    Node<T>* mNode;
private: //private methods

    Node<T>* getNodeAddData(T data);

    T freeNodeExtractData(Node<T>* temp);

    Node<T>* findMinInternal(Node<T>* node);

    Node<T>* findMaxInternal(Node<T>* node);

    int recurHeight(Node<T>* ptr);

    int getBF(Node<T>* node);

    Node<T>* findMinForDeletion(Node<T>* node);

    Node<T>* findMaxForDeletion(Node<T>* node);

    Node<T>* recurInsert(Node<T>* node, T data);

    Node<T>* rightRotate(Node<T>* y);

    Node<T>* leftRotate(Node<T>* x);

    Node<T>* recurDelete(Node<T>* root, T data);
    
public:
    BBST(){
        mNode=nullptr;
    }

    

    bool search(T data);

    void levelTrav();

    int getHeight();

    void insert(T data);

    void deleteData(T data);



};

template<class T>
Node<T>* BBST<T>::getNodeAddData(T data){
    Node<T>* temp=new Node{data};
    return temp;
}

template<class T>
T BBST<T>::freeNodeExtractData(Node<T>* temp){
    T data=temp->mData;
    delete temp;
    return data;
}

template<class T>
Node<T>* BBST<T>::findMinInternal(Node<T>* node){
    while(node->mLeft!=nullptr){
        node=node->mLeft;
    }
    return node;
}

template<class T>
Node<T>* BBST<T>::findMaxInternal(Node<T>* node){
    while(node->mRight!=nullptr){
        node=node->mRight;
    }
    return node;
}

template<class T>
int BBST<T>::recurHeight(Node<T>* ptr){
    if(ptr==nullptr){
        return -1;
    }
    
    return (std::max(recurHeight(ptr->mLeft),recurHeight(ptr->mRight))+1);

}

template<class T>
int BBST<T>::getBF(Node<T>* node){
    if(node==nullptr){
        return 0;
    }
    else{
        return (recurHeight(node->mRight)-recurHeight(node->mLeft));
    }
}

template<class T>
Node<T>* BBST<T>::rightRotate(Node<T>* y){
    Node<T>* x = y->mLeft;
    Node<T>* T2 = x->mRight;
 
    // Perform rotation
    x->mRight = y;
    y->mLeft = T2;
 
    // Update heights
    y->mHeight = recurHeight(y);
    x->mHeight = recurHeight(x);
 
    // Return new root
    return x;
}

template<class T>
Node<T>* BBST<T>::leftRotate(Node<T>* x){
    Node<T>* y = x->mRight;
    Node<T>* T2 = y->mLeft;
 
    // Perform rotation
    y->mLeft = x;
    x->mRight = T2;
 
    // Update heights
    x->mHeight = recurHeight(x);
    y->mHeight = recurHeight(y);
 
    // Return new root
    return y;
}

template<class T>
Node<T>* BBST<T>::recurInsert(Node<T>* node, T data){

    assert(!search(data)&&"error: duplicate data");
    if(node==nullptr){
        return getNodeAddData(data);
    }

    if(data>node->mData){
        node->mRight=recurInsert(node->mRight,data);
    }
    else if(data<node->mData){
        node->mLeft=recurInsert(node->mLeft,data);
    }
    else{
        return node;
    }

    node->mHeight=recurHeight(node);

    int bf=getBF(node);

    //left left case
    if(bf<-1 && (data<node->mLeft->mData)){
        return rightRotate(node);
    }
    //left right case
    if(bf<-1 && (data>node->mLeft->mData)){
        leftRotate(node->mLeft);
        return rightRotate(node);
    }
    //right right case
    if(bf>1 && (data>node->mRight->mData)){
        return leftRotate(node);
    }
    //right left case
    if(bf>1 && (data<node->mRight->mData)){
        rightRotate(node->mRight);
        return leftRotate(node);
    }
    
    return node;
}

template<class T>
Node<T>* BBST<T>::recurDelete(Node<T>* root, T data){
    if(root==nullptr){
        return root;
    }
    else if(data>root->mData){
        root->mRight=recurDelete(root->mRight,data);
    }
    else if(data<root->mData){
        root->mLeft=recurDelete(root->mLeft,data);
    }
    else{
        //if both the right as well as left sub tree is null
        if((root->mLeft==nullptr)&&(root->mRight==nullptr)){
            delete root;
            root=nullptr;
            return root;
        }
        //if one of the sub tree is null
        else if(root->mLeft==nullptr){
            Node<T>* temp=root->mRight;
            delete root;
            root=nullptr;
            return root;
        }
        else if(root->mRight==nullptr){
            Node<T>* temp=root->mLeft;
            delete root;
            root=nullptr;
            return root;
        }
        //if none of the subtree is null
        else{
            Node<T>* temp1=findMaxForDeletion(root->mLeft); 
            root->mData=temp1->mData;
            root->mLeft=recurDelete(root->mLeft,temp1->mData);
            return root;
        }
       
    }

    root->mHeight=recurHeight(root);

    int bf=getBF(root);

    //left left case
    if(bf<-1 && (data>root->mLeft->mData)){
        return rightRotate(root);
    }
    //left right case
    if(bf<-1 && (data<root->mLeft->mData)){
        leftRotate(root->mLeft);
        return rightRotate(root);
    }
    //right right case
    if(bf>1 && (data<root->mRight->mData)){
        return leftRotate(root);
    }
    //right left case
    if(bf>1 && (data>root->mRight->mData)){
        rightRotate(root->mRight);
        return leftRotate(root);
    }

    return root;
}


template<class T>
Node<T>* BBST<T>::findMinForDeletion(Node<T>* node){
    while(node->mLeft!=nullptr){
        node=node->mLeft;
    }
    return node;
}

template<class T>
Node<T>* BBST<T>::findMaxForDeletion(Node<T>* node){
    while(node->mRight!=nullptr){
        node=node->mRight;
    }
    return node;
}

template<class T>
void BBST<T>::levelTrav(){
    Node<T>* temp=mNode;
    if(temp==nullptr){
        return;
    }
    std::queue<Node<T>*> q;
    q.push(temp);
    while(!q.empty()){
        Node<T>* cur=q.front();
        std::cout<<cur->mData<<'\t';
        if(cur->mLeft!=nullptr)
            q.push(cur->mLeft);
        if(cur->mRight!=nullptr)
            q.push(cur->mRight);
        q.pop();
    }
    std::cout<<'\n';
}

template<class T>
int BBST<T>::getHeight(){
    return mNode->mHeight;
}

template<class T>
void BBST<T>::insert(T data){
    mNode=recurInsert(mNode,data);
}

template<class T>
bool BBST<T>::search(T data){
    Node<T>* ptr=mNode;
    while(ptr!=nullptr){
        if(data==ptr->mData){
            return true;
        }
        if(data>ptr->mData){
            ptr=ptr->mRight;
        }
        else if(data<ptr->mData){
            ptr=ptr->mLeft;
        }
       
    }
    return false;
}

template<class T>
void BBST<T>::deleteData(T data){
    if(!(this->search(data))){
        std::cout<<"Error: the data entered doesn't exist \n";
    }

    mNode=recurDelete(mNode,data);

}
int main(){
  
    BBST<int> t;
    t.insert(10);
    t.insert(20);
    t.insert(30);
    t.insert(40);
    t.insert(50);
    t.insert(60);
    t.insert(70);
    t.insert(80);
    t.levelTrav();
    t.deleteData(30);
    t.levelTrav();
    t.deleteData(10);
    t.levelTrav();
    t.deleteData(60);
    t.levelTrav();
    std::cin.get();
    return 0;
}