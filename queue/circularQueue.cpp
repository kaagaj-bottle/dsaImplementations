#include <iostream>
#include <cassert>
//complete implementation of circular queue
template<class T,int size>
class CirQueue{

private:
    int mFront,mRear;
    T* mData;
public:
    CirQueue(){
        assert(size>0&&"insufficient size of queue");
        mData=new T[size];
        mFront=size-1;
        mRear=size-1;
    }
    //returns true if the queue is empty
    //the queue being empty is denoted by front and rear pointing to the same position
    bool empty(){
        return (mFront==mRear);
    }
    //removes the front element and returns it to the user
    int remove(){
        //checking for underflow condition
        assert(!empty()&&"Error: underflow\n");
        //if mFront points to the end of the array then it is set to the 0th position after removal as 
        if(mFront==size-1){
            mFront=0;
        }
        else{
            //if mFront points to position other than the end of the array it is simply returned
            ++mFront;
        }
        //returns the removes element
        return mData[mFront];
    }
    //returns true if the mData is full
    bool full(){
        //when mRear points to the end of the queue
        //the condition is true if mFront is zero
        if(mRear==size-1){
            return (mFront==0);
        }
        else{
            //self explanator i guess
            return ((mRear+1)==mFront);
        }
    }
    void insert(int value){
        if(full()){
            std::cout<<"Error: can't insert the queue is full\n";
        }
        //when queue not full and mRear points to the end of mData
        //mRear is pointed to zero and element is inserted
        else if(mRear==size-1){
            mRear=0;
            mData[mRear]=value;
        }
        //when the queue is not full and mRear points any other poisition other than size-1
        //it is simply increased i.e. room is made for the value and inserted
        else{
            mData[++mRear]=value;
        }
    
    }
};


int main(){

    CirQueue<int,3> q;
    std::cout<<q.empty()<<'\n';
    q.insert(5);
    q.insert(2);
    std::cout<<q.full()<<'\n';
    std::cout<<q.empty()<<'\n';
    std::cout<<q.remove()<<'\n';
    std::cout<<q.remove()<<'\n';
    std::cout<<q.empty()<<'\n';
    std::cin.get();

    return 0;
}