#include<bits/stdc++.h>
using namespace std ;

class Node{
public:
    int val ;
    Node * left ;
    Node * right ;
    Node(int x){
        this->val = x ;
        this->left = NULL;
        this->right = NULL;
    }
};


Node * insertBST(Node * root , int val){
    if(root == NULL) return new Node(val);
    if(val > root -> val){
        root->right = insertBST(root->right , val);
    }
    else{
        root->left = insertBST(root->left , val);
    }

    return root ;
}

void inorder(Node * root){
    if(root == NULL){
        // cout <<"No data available here !!\n"; 
        return;
    }

    //inorder ldr
    inorder(root -> left );
    cout << root-> val <<" ";
    inorder(root->right);
}


void preorder(Node * root){
    if(root == NULL){
        return;
    }

    //inorder ldr
    cout << root-> val <<" ";
    inorder(root -> left);
    inorder(root->right);
}

void postorder(Node * root){
    if(root == NULL){
        return;
    }

    //inorder ldr
    inorder(root -> left);
    inorder(root->right);
    cout << root-> val <<" ";
}

int main(){
    // we have to create  a bst
    int n ;
    cin >> n ;
    vector<int> arr (n);
    Node * root = NULL;
    for(auto &x : arr) {
        cin>> x;
        
    }
    root = insertBST(root , arr[0]);
    for(int i = 1; i < n ; i ++) {
        insertBST(root , arr[i]) ;
    }

    cout << "Inorder is : " ;
    inorder(root);
    cout << endl;
    cout << "Preorder is : " ;
    preorder(root);
    cout << "Postorder is : " ;
    postorder(root);
    return 0;

}