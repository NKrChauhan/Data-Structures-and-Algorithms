#include <iostream>
#include <queue>
#include <vector> 
#include <map> 

using namespace std;

// structure 

struct avlnode{
    int data;
    int height;
    struct avlnode *left;
    struct avlnode *right;
};

// Functions Decleration
int heightAVL(struct avlnode *head);
struct avlnode *getNewNode(int data,int height);
struct avlnode *singleLRotation(struct avlnode *head);
struct avlnode *singleRRotation(struct avlnode *head);
struct avlnode *doubleLRRotation(struct avlnode *head);
struct avlnode *doubleRLRotation(struct avlnode *head);
struct avlnode *insertNode(struct avlnode *head,struct avlnode *parent,int data);

// Function Definition
int heightAVL(struct avlnode *head){
    if(!head) return -1;
    else return head->height;
}

struct avlnode *getNewNode(int data,int height){
    struct avlnode *temp=(struct avlnode *)malloc(sizeof(struct avlnode));
    temp->data=data;
    temp->height=height;
    temp->left=temp->right=NULL;
    return temp;
}

struct avlnode *singleLRotation(struct avlnode *head){
    struct avlnode *newN=head->left; //temp node to store pointer of  the left node
    head->left=newN->left;
    newN->left=newN->right;
    newN->right=head->right;
    head->right=newN;
    newN->data=head->data+newN->data; //swapping of values.
    head->data=newN->data-head->data;
    newN->data=newN->data-head->data;
    head->height=max(heightAVL(head->left),heightAVL(head->right))+1;
    newN->height=max(heightAVL(newN->left),heightAVL(newN->right))+1;
    return head;
}

struct avlnode *singleRRotation(struct avlnode *head){
    // another method of doing this is by not doing swap values. (for LL or RR rotation)
    struct avlnode *temp=head->right;
    head->left=temp->left;
    temp->left=head;
    head->height=max(heightAVL(head->left),heightAVL(head->right))+1;
    temp->height=max(heightAVL(temp->left),heightAVL(temp->right))+1;
    return temp;
}

struct avlnode *doubleLRRotation(struct avlnode *head){
    // LR rotation is the right followed by left rotation at node left then head(root)
    struct avlnode *temp=singleRRotation(head->left);
    return singleLRotation(temp);
}

struct avlnode *doubleRLRotation(struct avlnode *head){
    // RL rotation is the left followed by right rotation at node right then head(root)
    struct avlnode *temp=singleLRotation(head->right);
    return singleRRotation(temp);
}

struct avlnode *insertNode(struct avlnode *head,struct avlnode *parent,int data){
    if(!head) root=getNewNode(data,0);
    if(head->data>=data){
        head->left=insertNode(head->left,root,data);
        if((heightAVL(head->left)-heightAVL(head->right))>1){
            if(head->left->data>data) head=singleLRotation(head);
            else head=doubleLRRotation(head);   
        }
    }else{
        head->right=insertNode(head->right,root,data);
        if((heightAVL(head->left)-heightAVL(head->right))>1){
            if(head->right->data<data) head=singleRRotation(head);
            else head=doubleRLRotation(head);
        }
    }
    // height manipulation
    head->height=max(heightAVL(newN->left),heightAVL(newN->right))+1;
    return head;
}



int main(int argc, char const *argv[]) {

    return 0;
}
