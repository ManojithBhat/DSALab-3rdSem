#include<iostream>
#include <string.h>
using namespace std;

class Node{
    public:
        char data;
        Node* left;
        Node* right;
    
    Node(char val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Stack{
    public:
        Node* ele[20];
        int top;
    
    Stack(){
        this->top = -1;
    }

    //push function 
    void push(Node* node){
        ele[++top] = node;
    }

    //pop function 
    Node* pop(){
        return ele[top--];
    }

    //top function 
    char stop(){
        return ele[top]->data;
    }

};

//for displaying 
void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<"\t";
    inorder(root->right);
}

void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<"\t";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<"\t";
}

int precedence(char op){
    if(op=='^') return 3;
    else if(op=='*' || op=='/')return 2;
    else if(op=='+'|| op=='-') return 1;
    else return 0;
}

Node* create_expression_tree(string exp){
    //get an instance of stack 
    Stack op,on;

    for(int i=0;i<exp.size();i++){
        char var = exp[i];
        //create a node 
        Node* node = new Node(var);
        if(isalnum(var)){
            //if it is an operand 
            on.push(node);
        }
        else{
            //if it is an operator 
            while(op.top!=-1 && precedence(op.stop())>=precedence(var)){
                Node* temp = op.pop();
                temp->right = on.pop();
                temp->left = on.pop();
                on.push(temp);
            }
            op.push(node);
        }
    }

    while(op.top!=-1){
        Node* temp = op.pop();
        temp->right = on.pop();
        temp->left = on.pop();
        on.push(temp);
    }
    return on.pop();
}

int main()
{
char infix[25];
Node* root=NULL;
cout<<"\nRead the infix expression :";
cin>>infix;
cout<<"The entered infix expression is : \n";
cout<<infix<<endl;
root=create_expression_tree(infix);
cout<<"The inorder traversal is: \n";
inorder(root);
cout<<"\nThe preorder traversal is: \n";
preorder(root);
cout<<"\nThe postorder traversal is: \n";
postorder(root);
return 0;
}