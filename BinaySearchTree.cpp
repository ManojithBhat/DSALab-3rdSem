#include<iostream>
using namespace std;

class Tree{
    public:
    int data;
    Tree* left;
    Tree* right;

    Tree(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Tree* predecessor(Tree* node){
    if(node->right==NULL) return node;
    node = node->right;
}

Tree* delete_in_bst(Tree* root,int val){
    if(root==NULL){
        return NULL;
    }

    if(root->data > val){
        root->left = delete_in_bst(root->left,val);
    }
    else if(root->data<val){
        root->right = delete_in_bst(root->right,val);
    }
    else{
        Tree* curr = NULL;
        if(root->left == NULL){
            curr = root->right;
            delete root;
            return curr;
        }
        if(root->right == NULL){
            curr = root->left;
            delete root;
            return curr;
        }

        curr = predecessor(root->left);
        root->data = curr->data;
        root->left = delete_in_bst(root->left,curr->data);
    }
    return root;
}

Tree* insert_into_bst(Tree* root, int val){
    if(root==NULL){
        Tree* newNode = new Tree(val);
        return newNode;
    }
    if(root->data<val){
        root->right = insert_into_bst(root->right,val);
    }
    else if(root->data>val){
        root->left = insert_into_bst(root->left,val);
    }
    return root;
}

Tree* create_bst(Tree* root){
    int val;
    cout<<"Enter the data to be inserted in the bst (Enter -1 to stop):\t";
    cin>>val;
    while(val!=-1){
        root = insert_into_bst(root,val);
        cout<<"Enter the data to be inserted in the bst (Enter -1 to stop):\t";
        cin>>val;
    }
    return root;
}

void inOrder(Tree* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<"\t";
    inOrder(root->right);
}

void preOrder(Tree* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<"\t";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Tree* root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<"\t";
}

int main() {
    Tree* root = nullptr;
    int ch, item, key;
    for (;;) {
        cout << "\n 1.Create\n 2. Insert\n 3. Preorder\n 4. Inorder\n 5. Postorder\n 6. Delete\n 7. Exit\n Read your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout<<"\nCreate bst:";
                root = create_bst(root);\
                break;
            case 2:
                cout << "\n Read element to be inserted :";
                cin >> item;
                root = insert_into_bst(root, item);
                break;
            case 3:
                cout << "\n The Preorder traversal is\n";
                preOrder(root);
                break;
            case 4:
                cout << "\n The Inorder traversal is\n";
                inOrder(root);
                break;
            case 5:
                cout << "\n The Postorder traversal is\n";
                postOrder(root);
                break;
            case 6:
                cout << "\n Read node to be deleted : ";
                cin >> key;
                root = delete_in_bst(root, key);
                break;
            default:
                exit(0);
        }
    }
    return 0;
}