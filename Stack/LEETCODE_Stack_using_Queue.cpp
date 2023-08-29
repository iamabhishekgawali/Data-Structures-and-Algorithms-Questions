
#include<iostream>
#include<queue>
using namespace std;

class MyStack {

    queue<int> Queue1;  // Supporting Queue
    queue<int> Queue2;  // Main Queue

public:
    MyStack() {
        
    }
    
    void push(int x) {
        Queue2.push(x);
    }
    
    int pop() {

        // Copy all elements in Queue 1 except last element
        while(Queue2.size()!=1)
        {
            Queue1.push(Queue2.front());
            Queue2.pop();
        }
        // Remove the last element from the Queue 2
        int temp = Queue2.front();
        Queue2.pop();

        // Push back all the elements in the Queue 2 from Queue 1
        while(Queue1.size() != 0){
            Queue2.push(Queue1.front());
            Queue1.pop();
        }

        return temp;
    }
    
    int top() {

        // Copy all elements in Queue 1 except last element
        while(Queue2.size()!=1)
        {
            Queue1.push(Queue2.front());
            Queue2.pop();
        }
        // return the last element from the Queue 2
       int temp = Queue2.front();
       Queue2.pop();

        // Push back all the elements in the Queue 2 from Queue 1
        while(Queue1.size() != 0){
            Queue2.push(Queue1.front());
            Queue1.pop();
        }
        Queue2.push(temp);
        return temp;

    }
    
    bool empty() {
        return Queue2.size() == 0;
    }
};
int main(){

}