#include <iostream>
#include <algorithm>
#include <queue>
// methods available in the following binary tree
// ---------------------------------------------------------------
// bool insert(T data);
// int getHeight();
// void preTrav();
// void inTrav();
// void postTrav();
//----------------------------------------------------------------

template<class Type>
struct Node{
    Type mData;
    Node* mLeft;
    Node* mRight;

    Node (Type data):mData{data},mLeft{nullptr},mRight{nullptr}
    {}
    Node():mLeft{nullptr},mRight{nullptr}{}

};


template<class T>
class BST{
private:
    Node<T>* mNode;
    Node<T>* getNodeAddData(T data);
    T freeNodeExtractData(Node<T>* temp);
    //------------------
    int recurHeight(Node<T>* ptr);

    void recurPreTrav(Node<T>* root);

    void recurInTrav(Node<T>* root);

    void recurPostTrav(Node<T>* root);

    void recurLevelTrav(Node<T>* root);
public:
    BST();
       
    bool insert(T data);

    int getHeight();

    void preTrav();

    void inTrav();
    
    void postTrav();

    void levelTrav();

    bool search(T data);

};

template<class T>
Node<T>* BST<T>::getNodeAddData(T data){
    Node<T>* temp=new Node{data};
    return temp;
}

template<class T>
T BST<T>::freeNodeExtractData(Node<T>* temp){
    T data=temp->mData;
    delete temp;
    return data;
}

template<class T>
BST<T>::BST():mNode{nullptr}{
    }

template<class T>
bool BST<T>::insert(T data){
    if(mNode==nullptr){
        mNode=getNodeAddData(data);
        return true;
    }
    Node<T>* ptr=mNode;
    Node<T>* parent=mNode;
    while((ptr!=nullptr)&&(data!=ptr->mData)){
        parent=ptr;
        if(data>ptr->mData){
            ptr=ptr->mRight;
        }
        else{
            ptr=ptr->mLeft;
        }
    }
    
    if(data<parent->mData){
        parent->mLeft=getNodeAddData(data);
        std::cout<<"data inserted to the left\n";
        return true;
    }
    else if(data>parent->mData){
        parent->mRight=getNodeAddData(data);
        std::cout<<"data inserted to the right\n";
        return false;
    }
    else
    {
        std::cout<<"data to be inserted is already present there\n";
        return false;
    }
}

template<class T>
int BST<T>::getHeight(){
  return recurHeight(mNode);
}   

template<class T>
int BST<T>::recurHeight(Node<T>* ptr){
    if(ptr==nullptr){
        return -1;
    }
    else{
        return (std::max(recurHeight(ptr->mLeft),recurHeight(ptr->mRight))+1);
    }
}
  
template<class T>
void BST<T>::preTrav(){
    Node<T>* temp=mNode;
    recurPreTrav(temp);
    std::cout<<'\n';
}

template<class T>
void BST<T>::inTrav(){
    Node<T>* temp=mNode;
    recurInTrav(temp);
    std::cout<<'\n';
}

template<class T>
void BST<T>::postTrav(){
    Node<T>* temp=mNode;
    recurPostTrav(temp);
    std::cout<<'\n';
}

template<class T>
void BST<T>::levelTrav(){
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
void BST<T>::recurPreTrav(Node<T>* root){
    if(root==nullptr){
        return;
    }
    std::cout<<root->mData<<'\t';
    recurPreTrav(root->mLeft);
    recurPreTrav(root->mRight);
}

template<class T>
void BST<T>::recurInTrav(Node<T>* root){
    if(root==nullptr){
        return;
    }
    recurInTrav(root->mLeft);
    std::cout<<root->mData<<'\t';
    recurInTrav(root->mRight);
}

template<class T>
void BST<T>::recurPostTrav(Node<T>* root){
    if(root==nullptr){
        return;
    }
    recurPostTrav(root->mLeft);
    recurPostTrav(root->mRight);
    std::cout<<root->mData<<'\t';
}

template<class T>
bool BST<T>::search(T data){
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





int main(){
    BST<int> t;
    t.insert(234);
    t.insert(3);
    t.insert(9);
    t.insert(4);
    t.insert(922);
    std::cout<<"LevelTraversal:\t\t";
    t.levelTrav();
    std::cout<<"PreTraversal:\t\t";
    t.preTrav();
    std::cout<<"InTraversal:\t\t";
    t.inTrav();
    std::cout<<"PostTraversal:\t\t";
    t.postTrav();
    std::cout<<t.search(922)<<t.search(8)<<t.search(9);
    std::cin.get();
    return 0;
}