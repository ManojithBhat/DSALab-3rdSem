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

int precedence(char op){
    if(op=='^') return 3;
    else if(op=='*' || op=='/')return 2;
    else if(op=='+'|| op=='-') return 1;
    else return 0;
}

string convertToPostfix(string exp){
    Stack st;
    char postfix[20];
    int j=0;
    for(int i=0;i<exp.size();i++){
        char var = exp[i];
        if(isalnum(var)){
            postfix[j++] = var;
        }
        else if(var=='(') st.push(var);
        else if(var==')'){
            while(st.top!=-1 && st.stop()!='('){
                postfix[j++] = st.pop();
            }
            st.pop();
        }
        else{
            while(st.top!=-1 && precedence(st.stop())>=precedence(var)){
                postfix[j++] = st.pop();
            }
            st.push(var);
        }
    }

    while(st.top!=-1){
        postfix[j++] = st.pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int main(){
    string infix,postfix;
    cout<<"Enter the infix expression\n";
    cin>>infix;
    postfix = convertToPostfix(infix);
    cout<<"The postfix expression is :\n";
    cout<<postfix;
    return 0;
}