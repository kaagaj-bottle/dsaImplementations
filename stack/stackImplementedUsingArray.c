#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 100
#define TRUE 1
#define FALSE 0


struct Stack
{
    //size value of -1 corresponds to empty stack 
    //if the value of size is 0 it means there is 1 element inside the stack
    int size;
    int stackElement[STACKSIZE];
};

//returns true if the stack is empty
int empty(struct Stack* s)
{

    //here -1 has been used to point to the end of the stack 

    if(s->size==-1)
        {
            printf("the stack is empty\n");
            return TRUE;
        }
    else 
        return FALSE;
}
//function to push element onto the stack
int push(struct Stack* s,int value)
{
    if(s->size>(STACKSIZE-1))
        return FALSE;
    s->stackElement[++(s->size)]=value;
    return TRUE;
    //if the push operation is successful then the function returns a true value

}
//pops the topmost element of the stack and returns it to the user
int pop(struct Stack* s)
{
    if(empty(s))
    {
        exit(0);
    }
    else
    {
        int topElement=s->stackElement[s->size--];
        return topElement;
    }

}

//return sthe first element of the stack
int top(struct Stack* s)
{
    return s->stackElement[s->size];
}

int main()
{
    struct Stack s;
    for(int i=0;i<10;++i)
    {
        if(!push(&s,i))
            {
            	//pushing into the stack
                printf("failure of push operation ");
                exit(0);
            }
    }

    for (int i = 0; i < 10; ++i)
    {
    	//popping from the stack
        printf("%d\n",pop(&s));
    }


    
    return 0;
}
