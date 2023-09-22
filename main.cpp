#include <iostream>
#include "Stack.h"
#include <string>

using namespace std;

void Tower(int N,Stack<int> Source, Stack<int> Target, Stack<int> Aux,int &moves)// the towers of hanoi recursive function
{
    int temp;// used to help with moving a disk from one peg to another
    
    if(N==1)// its the base condtion for the recursive function and it works when you move directly from source to target
    {
        temp=Source.pop();
        Target.push(temp);
        Source.display("Source");
        Aux.display("Aux");
        Target.display("Target");
        cout<<endl;
        moves++;
    }
    else // this condition is when there is more than one disk
    {
        Tower(N-1,Source,Aux,Target,moves);// moves from source to auxiliary via target
        temp=Source.pop();
        Aux.push(temp);
        Target.push(Source.pop());
        Source.display("Source");
        Aux.display("Aux");
        Target.display("Target");
        cout<<endl;
        Tower(N-1,Aux,Target,Source,moves);// moves from auxiliary to target via source
        moves++;
        
    }
}

int main()
{
    int Num,moves;
    
    cout<<"Enter the number of disks you want to play with"<<endl;// prompts the user to say the number of disks they want to play with
    cin>>Num;
    cout<<endl;
    Stack<int> Source(Num),Target(Num),Aux(Num);
    
    for(int i=Num; i>0; i--)// fills the source stack
    {
        Source.push(i);
    }
    
    Source.display("Source");// displays the three pegs
    Aux.display("Aux");
    Target.display("Target");
    cout<<endl;
    
    Tower(Num ,Source, Target,Aux,moves);// calls the function
    cout<<"The number of moves needed are "<<moves<<endl;
    
    return 0;
    
}
