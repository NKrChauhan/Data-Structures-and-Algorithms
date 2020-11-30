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

// Global variable for generation of AVL of height h with minimum node 
int g_data=1;

// previously made function reused decleration

void printNodesInorder(struct avlnode *head);

// Function previous definition
void printNodesInorder(struct avlnode *temp){
    if(!temp) return;
    printNodesInorder(temp->left);
    cout<<temp->data<<", ";
    printNodesInorder(temp->right);
    return;
}

// Functions Decleration
int heightAVL(struct avlnode *head);
struct avlnode *getNewNode(int data,int height);
struct avlnode *singleLRotation(struct avlnode *head);
struct avlnode *singleRRotation(struct avlnode *head);
struct avlnode *doubleLRRotation(struct avlnode *head);
struct avlnode *doubleRLRotation(struct avlnode *head);
struct avlnode *insertNode(struct avlnode *head,int data);
struct avlnode *generateAVL(int h);
struct avlnode *HB0(int h);
int isAVL(struct avlnode* head);
int closeInBST(struct avlnode *head,int data);

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

struct avlnode *insertNode(struct avlnode *head,int data){
    if(!head) return getNewNode(data,0);
    if(head->data>=data){
        head->left=insertNode(head->left,data);
        if((heightAVL(head->left)-heightAVL(head->right))>1){
            if(head->left->data>data) head=singleLRotation(head);
            else head=doubleLRRotation(head);   
        }
    }else{
        head->right=insertNode(head->right,data);
        if((heightAVL(head->left)-heightAVL(head->right))>1){
            if(head->right->data<data) head=singleRRotation(head);
            else head=doubleRLRotation(head);
        }
    }
    // height manipulation
    head->height=max(heightAVL(head->left),heightAVL(head->right))+1;
    return head;
}

struct avlnode *generateAVL(int h){
    struct avlnode *temp;
    if(h<=0) return NULL;
    temp=getNewNode(0,0);
    temp->left=generateAVL(h-1);
    temp->data=g_data++;
    temp->right=generateAVL(h-2);
    temp->height=heightAVL(temp);
    return temp;
}

// HB0 is the binary tree where number of nodes at height h is (2^(h+1))-1
// in this we will not use the height data-point of avlnode treating it as BST
struct avlnode *HB0(int h){
    struct avlnode *temp;
    if(h<=0) return NULL;
    temp=getNewNode(0,0);
    temp->left=HB0(h-1);
    temp->data=g_data++;
    temp->right=HB0(h-2);
    return temp;
}

// check if BST is AVL so height not used in this
int isAVL(struct avlnode* head){
    if(!head) return 0;
    int l=isAVL(head->left);
    int r=isAVL(head->right);
    if(l==-1||r==-1) return -1;
    if(abs(l-r)<=1) return max(l+1,r+1);
    else return -1;
}

// closest value in the BST in the given value...
int closeInBST(struct avlnode *head,int data){
    if(!head) return 99999;
    int res;
    int l=closeInBST(head->left,data);
    int r=closeInBST(head->right,data);
    if(abs(l-data)<=abs(r-data)) res=l;
    else res=r;
    if(abs(head->data-data)<abs(res-data)) res=head->data;
    return res;
}

int main(int argc, char const *argv[]) {
    int a[]={5,4,3,2,1,8};
    struct avlnode *head=generateAVL(4);
    cout<<"The data of head after generating the AVL tree giving only height: "<<head->data<<endl;
    cout<<"Inorder print: ";
    printNodesInorder(head);
    cout<<endl;
    string s=isAVL(head)>0?"True":"False";
    cout<<"The tree generated above is avl or not: "<<s<<endl;
    cout<<"The closest value in the Acting-BST Avl tree to 10 is: "<<closeInBST(head,10)<<endl;
    head=NULL;
    for(int x:a){
        head=insertNode(head,x);
    }
    cout<<"Inorder print of the AVL tree created using array is given: ";
    printNodesInorder(head);
    cout<<endl;
    s=isAVL(head)>0?"True":"False";
    cout<<"The tree generated above is avl or not: "<<s<<endl;
    return 0;
}
