#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node* Makenode(int x){
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}
void CreateTree(struct node**T){
    int choice,x;
    struct node*p;
    cout<<"Whether left of "<<(*T)->data<<" exists or not (1/0) :- ";
    cin>>choice;
    if(choice==1){
        cout<<"Input Data of left of "<<(*T)->data<<" :- ";
        cin>>x;
        p=Makenode(x);
        (*T)->left=p;
        CreateTree(&p);
    }
    cout<<"Whether right of "<<(*T)->data<<" exists or not (1/0) :- ";
    cin>>choice;
    if(choice==1){
        cout<<"Input Data of right of "<<(*T)->data<<" :- ";
        cin>>x;
        p=Makenode(x);
        (*T)->right=p;
        CreateTree(&p);
    }
}
void PreorderTraversal(struct node *T){
    if(T!=NULL){
        cout<<T->data<<" ";
        PreorderTraversal(T->left);
        PreorderTraversal(T->right);
    }
}
void inorderTraversal(struct node *T){
    if(T!=NULL){
        inorderTraversal(T->left);
        cout<<T->data<<" ";
        inorderTraversal(T->right);
    }
}
void postorderTraversal(struct node *T){
    if(T!=NULL){
        postorderTraversal(T->left);
        postorderTraversal(T->right);
        cout<<T->data<<" ";
    }
}
bool isBST(struct node* root , struct node*prev){
    if(root!=NULL){
        if(isBST(root->left,prev)==NULL){
            return false;
        }
        if(prev!=NULL && root->data <= prev->data){
            return false;
        }
        prev=root;
        return isBST(root->right,prev);
    }
    return true;
}
int main(){
    struct node *root=NULL;
    int x;
    cout<<"Enter the Root node Data :- ";
    cin>>x;
    root=Makenode(x);
    CreateTree(&root);
    // PreorderTraversal(root);
    // cout<<endl;
    inorderTraversal(root);
    cout<<endl;
    // postorderTraversal(root);
    // cout<<endl;
    //
    struct node*prev=NULL;
    cout<<isBST(root,prev);
    return 0;
}