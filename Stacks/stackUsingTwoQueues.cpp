#include <iostream>
#include <queue>
using namespace std;

class stackUsingTwoQueus{
    queue<int> q1, q2;

    public:

        void push(int x){
            //In push operation, we will first push the element in q2 and then push all the elements of q1 in q2 and then swap the names of q1 and q2
            //ex: q1 = 1,2,3,4,5
            //    q2 = empty
            //    push(7)
            //    q2 = 7
            //    q1 = 1,2,3,4,5
            //    q2 = 7,1,2,3,4,5
            //    q1 = empty
            //    swap(q1, q2)
            //    q1 = 7,1,2,3,4,5
            //    q2 = empty
            
            q2.push(x);

            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }

            swap(q1, q2);
        }

        void pop(){
            //In pop operation, we will pop the front element of q1
            if(q1.empty()){
                cout<<"Stack is empty"<<endl;
                return;
            }
            q1.pop();
        }

        int top(){
            //In top operation, we will return the front element of q1
            if(q1.empty()){
                cout<<"Stack is empty"<<endl;
                return -1;
            }
            return q1.front();
        }

        bool isEmpty(){
            //In empty operation, we will return whether q1 is empty or not
            return q1.empty();
        }

        void display(){
            //In display operation, we will print all the elements of q1
            queue<int> temp = q1;
            while(!temp.empty()){
                cout<<temp.front()<<" ";
                temp.pop();
            }
            cout<<endl;

            delete &temp;
        }


        
};

int main(){

    stackUsingTwoQueus stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    cout<<stack.top()<<endl;

    stack.display();

    stack.pop();

    cout<<stack.top()<<endl;

    stack.display();


    return 0;
}