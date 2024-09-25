#include <iostream>
using namespace std;

class Stack{
    private:
        int size;
        int top;
        char *s;
    public:
        Stack(){
            size = 10;
            top = 0;
            s = new char[size];
        }
        Stack(int size){
            this->size = size;
            top = 0;
            s = new char[size];
        }
        void push(char x){
            if(top == size){
                cout << "Stack Overflow" << endl;
            }else{
                s[top++] = x;
            }
        }

        char pop(){
            char x = -1;
            if(top == 0){
                cout << "Stack Underflow" << endl;
            }else{
                x = s[top--];
            }
            return x;
        }

        void display(){
            for(int i = top-1; i >= 0; i--){
                cout << s[i] << " ";
            }
            cout << endl;
        }

        void checkParantheses(char *exp){
            for(int i = 0; exp[i] != '\0'; i++){
                if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
                    push(exp[i]);
                }else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
                    if(top == 0){
                        cout << "Stack is empty or parantehsis are not balanced" << endl;
                        return;
                    }
                    pop();
                }
            }
            if(top == 0){
                cout << "Balanced" << endl;
            }else{
                cout << "Unbalanced" << endl;
            }
        }
};

int main(){

    Stack st(10);
    char exp[] = "((a+b)*(c-d)){";
    st.checkParantheses(exp);

    return 0;
}