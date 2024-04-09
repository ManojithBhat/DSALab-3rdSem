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


Tree* constructBinaryTree(Tree* root){
    int val;
    cout<<"Enter the data  (to enter null : -1)\n";
    cin>>val;
    if(val==-1) return NULL;
    root = new Tree(val);
    cout<<"Enter the value to the right of "<<val<<endl;
    root->left = constructBinaryTree(root->left);
    cout<<"Enter the value to the right of "<<val<<endl;
    root->right = constructBinaryTree(root->right);
    return root;    
}

int leaf_nodes(Tree* root){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) return 1;
    return leaf_nodes(root->left)+leaf_nodes(root->right);
}

int non_leaf_nodes(Tree* root){
    if(root==NULL || root->left==NULL && root->right==NULL) return 0;
    return non_leaf_nodes(root->left) + non_leaf_nodes(root->right)+1;
}

int height(Tree* root){
    if(root==NULL) return -1;
    int left_height = height(root->left);
    int right_height = height(root->right);
    if(left_height>right_height) return left_height+1;
    else return right_height+1;
}



int main() {
    Tree* root = nullptr;
    int choice;

    do {
        cout << "\nMenu: \n1. Create tree \n2. Display tree (inorder) \n3. Count nodes \n4. Calculate height \n5. Count leaf nodes \n6. Count non-leaf nodes \n7. Exit \nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                root = constructBinaryTree(root);
                cout << "Tree created successfully." << endl;
                break;
            case 2:
                cout << "\nDisplaying tree (inorder): ";
                inOrder(root);
                cout << endl;
                break;
            case 3:
                cout << "\nTotal number of nodes: " << non_leaf_nodes(root)+leaf_nodes(root) << endl;
                break;
            case 4:
                cout << "\nHeight of the tree: " << height(root) << endl;
                break;
            case 5:
                cout << "\nTotal number of leaf nodes: " << leaf_nodes(root) << endl;
                break;
            case 6:
                cout << "\nTotal number of non-leaf nodes: " << non_leaf_nodes(root) << endl;
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}