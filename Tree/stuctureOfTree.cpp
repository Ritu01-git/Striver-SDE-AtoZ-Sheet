#include<bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    struct Node* left;
    struct Node* right;

    Node(int data){
        value = data;
        left = right = NULL;
    }
};

//Pre Order = Root Left Right
void preOrder(Node* root){
    if(root == NULL) return;

    cout << root->value << " ";
    preOrder(root->left);
    preOrder(root->right);
}

//Post Order = Left Right Root
void postOrder(Node * root){
    if(root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->value << " ";
}



//inorder = Left Root Right
void inOrder(Node * root){
    if(root == NULL) return;

    inOrder(root->left);
    cout << root->value << " ";
    inOrder(root->right);
}



int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    /*
        1
       / \
      2   3
     / \ / \ 
    4  5 6  7
    */

    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);
}