#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node *right;
    struct node *next;
};
struct node* Makenode(int x){
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    p->next=NULL;
    return p;
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
int search(int In[],int s,int e,int cur){
    for(int i=s; i<=e ; i++){
        if(In[i]==cur){
            return i;
        }
    }
}
struct node*Build_Tree_In_Pre(int pre[] , int In[] , int s , int e){
    static int i=0;
    if(s>e){
        return NULL;
    }
    int cur=pre[i];
    i++;
    struct node*p=Makenode(cur);
    if(s==e){
        return p;
    }
    int pos=search(In,s,e,cur);
    p->left=Build_Tree_In_Pre(pre,In,s,pos-1);
    p->right=Build_Tree_In_Pre(pre,In,pos+1,e);
    return p;
}
int main(){
    // struct node *root=NULL;
    // int x;
    // cout<<"Enter the Root node Data :- ";
    // cin>>x;
    // root=Makenode(x);
    // CreateTree(&root);
    // PreorderTraversal(root);
    // cout<<endl;
    // inorderTraversal(root);
    // cout<<endl;
    // postorderTraversal(root);
    // cout<<endl;

    int In[]={3,12,6,4,7,10,11,5,2,8};
    int pre[]={10,12,3,4,6,7,5,11,2,8};
    struct node*p=Build_Tree_In_Pre(pre,In,0,9);
    postorderTraversal(p);
    return 0;
}