#include <iostream>
#include <queue>
using namespace std;

int main()
{
queue<int> q; //creating a queue of integers
string command;
int value;
while (cin>>command && command!="#")
{
    if (command == "PUSH")
    {
        cin>>value;
        q.push(value); //pushing the value into queue
    }
    else if (command == "POP")
    {
        if (q.empty()) //checking if queue is empty
        {
            cout<<"NULL"<<endl;
        }
        else
        {
            cout<<q.front()<<endl; //removing and printing the front value
            q.pop(); //removing the front value
        }
    }
}

return 0;
}