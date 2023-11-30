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

//iterative pre order traversal
void iterativePreOrder(Node* root){
    stack<Node*> s;
    if(root == NULL) return;
    s.push(root);
    while(!s.empty()){
        Node* temp = s.top();
        s.pop();
        cout << temp->value << " ";
        if(temp->right != NULL) s.push(temp->right);
        if(temp->left != NULL) s.push(temp->left);
    }
}

//Post Order = Left Right Root
void postOrder(Node * root){
    if(root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->value << " ";
}

//iterative post order
void iterativePostOrder(Node* root){
    if(root == NULL) return;
    stack<Node*> s1;
    vector<int> s2;
    s1.push(root);
    while(!s1.empty()){
        Node *temp = s1.top();
        s2.push_back(temp->value);
        s1.pop();
        if(temp->left != NULL){
            s1.push(temp->left);
        }
        if(temp->right != NULL){
            s1.push(temp->right);
        }
    }
    for(int i = s2.size()-1; i >= 0; i--){
        cout << s2[i] << " ";
    }
}


//inorder = Left Root Right
void inOrder(Node * root){
    if(root == NULL) return;

    inOrder(root->left);
    cout << root->value << " ";
    inOrder(root->right);
}

//iterative inorder
void iterativeInOrder(Node* root){
    if(root == NULL) return;
    stack<Node*> s;
    Node* temp = root;
    while(true){
        if(temp != NULL){
            s.push(temp);
            temp = temp->left;
        }
        else{
            if(s.empty()) break;
            temp = s.top();
            s.pop();
            cout << temp->value << " ";
            temp = temp->right;
        }
    }
}

//level order traversal
vector<vector<int>> BFS(Node* root){
    vector<vector<int>> A;
    if(root == NULL) return A;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        vector<int> ans;
        int size = q.size();
        for(int i = 0; i < size; i++){
            Node* temp = q.front();
            q.pop();
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
            ans.push_back(temp->value);
        }
        A.push_back(ans);
    }

    return A;

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

    // preOrder(root);
    // cout << endl;
    // inOrder(root);
    // cout << endl;
    // postOrder(root);
    // cout << endl;
    //BFS

    // vector<vector<int>> ans = BFS(root);
    // for(int i = 0; i < ans.size(); i++){
    //     for(int j = 0; j < ans[i].size(); j++){
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // iterativePreOrder(root);
    iterativePostOrder(root);
}