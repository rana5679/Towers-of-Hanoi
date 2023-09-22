#include <iostream>
#include <string>
using namespace std;

#ifndef Stack_h
#define Stack_h

template <class T>

class Stack
{
    
private:
    int Maxtop;
    int top;
    T* content;
    
public:
    Stack(int N)// a default constructor initailzes all the private data members
    {
        Maxtop=N-1;
        top=-1;
        content= new T[N];
    }
    bool isEmpty()// checks if the stack is empty
    {
        if(top==-1)
            return true;
        return false;
    }
    bool isFull()// checks if the stack is full
    {
        if(top==Maxtop)
            return true;
        return false;
            
    }
    void push(T s)// pushes a new element to the top of the stack
    {
        if(isFull())
        {
            cout<<"The peg is full"<<endl;
        }
        else
        {
            content[++top]=s;
        }
    }
    T pop()// pops an element from the top of the stack
    {
        if(isEmpty())
        {
            cout<<"The peg is empty"<<endl;
            return 0;
        }
            return content[top--];
    }
    void display(string peg)// prints out the values stored in the stack
    {
        cout<<peg<<"-->"<<endl;
        for(int i=top; i>=0 ; i--)
        {
            cout<<"\t"<<content[i]<<endl;
        }
    }
    
};


#endif
