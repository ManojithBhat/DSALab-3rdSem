#include<iostream>
#define SIZE 10
using namespace std;

class Stack{
    public:
    int data[SIZE];
    int top;

    Stack(){
        top=-1;
    }

    void push(int val){
        if(top==SIZE-1){
            cout<<"Stack is full\n";
            return;
        }
        data[++top] = val;
    }

    int pop(){
        if(top==-1){
            cout<<"Stack is empty\n";
            return -1;
        }
        return data[top--];
    }

    int stop(){
        if(top==-1){
            cout<<"Stack is empty\n";
            return -1;
        }
        return data[top];
    }
};

int prefixEval(string exp){
    Stack st;
    for(int i=exp.size()-1;i>=0;i--){
        char var = exp[i];
        if(isalnum(var)){
            st.push(var-'0');
        }
        else{
            //it is an operator 
            int operand1 = st.pop();
            int operand2 = st.pop();

            switch (var)
            {
            case '+':
                st.push(operand1 + operand2);
                break;
            case '-':
                st.push(operand1-operand2);
                break;
            case '*':
                st.push(operand1*operand2);
                break;
            case '/':
                st.push(operand1/operand2);
                break;
            default:
                break;
            }
        }
    }
    st.pop();
}


int main(){
    string prefix;
    int num;
    cout<<"Enter the postfix expression\n";
    cin>>prefix;
    num = prefixEval(prefix);
    cout<<"The prefix evaluation is :\n";
    cout<<num<<endl;
    return 0;

}