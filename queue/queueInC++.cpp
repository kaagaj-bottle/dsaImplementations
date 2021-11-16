#include <iostream>
#include <cassert>
template<class T,int size>
class Queue
{
private:
    int mFront,mRear;
    T* mData;
public:
    Queue(){
        assert(size>0&&"size of the queue has to be greater than zero\n");
        mData=new T[size];
        //mFront points the front element of the queue
        mFront=0;
        //mRear points to the rear element of the queue
        mRear=-1;
    }

    ~Queue(){
        delete[] mData;
    }

    //if mFront is greater than mRear then this function returns true
    bool empty()
    {
        if(mFront>mRear){
            return true;
        }
        else{
            return false;
        }
    }

    //if mRear points to a position which exceeds size then it returns true
    bool full()
    {
        if(mRear>=(size-1)){
            return true;
        }
        else{
            return false;
        }
    }
    
    //just inserts value to the stack in the rear end by checking if it is full or not
    void insert(T value)
    {
        if(!full()){
            mRear++;
            mData[mRear]=value;
        }
        else{
            std::cout<<"the queue is full: overflow\n";
        }
    }
   
    //removes the front element of the queue after checking if the queue is empty or not 
    //returns the removed element to the user
    T remove() 
    {
        if(!empty()){
            return mData[mFront++];
        }
        else{
            std::cout<<"can't remove: underflow\n";
            return 0;
        }
    }

    //just returns the front element of the stack
    T front() 
    {
        if(!empty()){
            return mData[mFront];
        }
        else{
            std::cout<<"can't return value: underflow";
            return 0;
        }
    }
};

int main()
{
    Queue<int,5> q;
    q.insert(5);
    std::cout<<q.front();
    std::cout<<q.remove();
    q.remove();
    std::cin.get();

    return 0;

}
