#include <iostream>
#include <cstdlib>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    // constructor
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

// function to do enqueue operation - adding element to the circular linked list to perform operations of circular queue like enqueue and dequeue
Node *enqueue(Node *tail, int val)
{
    // we will have access to the tail pointer of the linkedlist
    // create a node to insert at end
    Node *newNode = new Node(val);

    // check if this is first node
    if (tail == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }

    newNode->next = tail->next;
    tail->next = newNode;
    return newNode;
}

Node* dequeue(Node* tail){
    //check if atleast one node is present or not 
    Node* del=NULL;
    if(tail==NULL){
        cout<<"No node to delete\n";
        return NULL;
    }
    if(tail->next==tail){
        //thre is a single node in the linked list 
        del = tail;
        cout<<"the deleted node is "<<del->data<<"\n";
        delete del;
        return NULL;
    }
    //if there is more than one node 
    //point to the head node which is to be deleted 
    del = tail->next;
    tail->next = del->next;
    cout<<"the deleted node is "<<del->data<<"\n";
    delete del;
    return tail;
}

void display(Node* tail){
    if(tail==NULL){
        cout<<"No node to display\n";
        return;
    }
    Node* curr = tail->next;
    while(curr!=tail){
        cout<<curr->data<<"\t";
        curr = curr->next;
    }
    cout<<curr->data<<"\n";
}

int main(){
    //create an instance of the class 
    Node* tail=NULL;
    int item,choice;
    cout<<"1.Insert\n2.Delete\n3.Display\n4.Exit\n";
    while(true){
        cout<<"Read Choice :\n";
        cin>>choice;

        switch(choice)
     {
        case 1:cout<<"Read data to be inserted:";
        cin>>item;
        tail=enqueue(tail,item);
        break;
        case 2:tail=dequeue(tail);
        break;
        case 3:display(tail);
        break;
        default:exit(0);
     }

    }

    return 0;
}

