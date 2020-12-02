#include <iostream>
#include <queue>
#include <vector> 
#include <map> 

#define INT_MAX 999999

using namespace std;

// structure 

struct avlnode{
    int data;
    int height=0;
    struct avlnode *left;
    struct avlnode *right;
};

int g_data=1;

// previously made function reused decleration

void printNodesInorder(struct avlnode *head);
struct avlnode *getNewNode(int data,int height);
struct avlnode *generateAVL(int h);
struct avlnode *findMax(struct avlnode *head);
struct avlnode *findMin(struct avlnode *head);
int heightAVL(struct avlnode *head);
struct avlnode *deleteNode(struct avlnode *head,int data);

// Function previous definition
void printNodesInorder(struct avlnode *temp){
    if(!temp) return;
    printNodesInorder(temp->left);
    cout<<temp->data<<", ";
    printNodesInorder(temp->right);
    return;
}

struct avlnode *getNewNode(int data,int height){
    struct avlnode *temp=(struct avlnode *)malloc(sizeof(struct avlnode));
    temp->data=data;
    temp->height=height;
    temp->left=temp->right=NULL;
    return temp;
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

struct avlnode *deleteNode(struct avlnode *head,int data){
    if(head==NULL) return NULL;
    struct avlnode *temp=NULL;
    if(head->data>data) head->left=deleteNode(head->left,data);
    else if(head->data<data) head->right=deleteNode(head->right,data);
    else{
        if(head->left&&head->right){
            temp=findMin(head->right);
            head->data=temp->data;
            head->right=deleteNode(head->right,head->data);
        }
        else{
            temp=head;
            if(!head->left&&!head->right) head = NULL;
            else head= head->left?head->left:head->right;
            free(temp);
        }
    }
    return head;
}

int heightAVL(struct avlnode *head){
    if(!head) return -1;
    else return head->height;
}

// Function Decleration
struct avlnode *treeCompressionNonRec(struct avlnode *head);
struct avlnode *treeCompressionRec(struct avlnode *head, int *prev_data);
struct avlnode *removeHalfNodes(struct avlnode *head);
struct avlnode *removeleafNodes(struct avlnode *head);
struct avlnode *pruneTree(struct avlnode *head,int a,int b);

// Function Definition

struct avlnode *findMax(struct avlnode *head){
    if(!head) return NULL;   
    while(head->left) head=head->left;
    return head;
}

struct avlnode *findMin(struct avlnode *head){
    if(!head) return NULL;   
    while(head->right) head=head->right;
    return head;
}

// the tree compression is done by filling the height part which contains the number of nodes below the node with prev inorder data and removing that node from the tree
// solving by recurssion will be in next day code maybe :)
struct avlnode *treeCompressionNonRec(struct avlnode *head){
    if(!head) return NULL;
    struct avlnode *temp;
    vector<struct avlnode *> q;
    q.push_back(head);
    while(!q.empty()){
        struct avlnode *temp2;
        temp=q[0];
        q.erase(q.begin());
        if(temp->right&&temp->left&&temp->left->height>temp->right->height)
            temp2=findMax(temp->left);
        else temp2=findMin(temp->right);
        temp->height=temp2->data;
        temp=deleteNode(temp,temp2->data);
        if(head->left) q.push_back(head->left);
        if(head->right) q.push_back(head->right);
    }
    return head;
}

struct avlnode *treeCompressionRec(struct avlnode *head, int *prev_data){
    struct avlnode *temp;
    if(!head) return NULL;
    temp=treeCompressionRec(head->left,prev_data);
    if(*prev_data==INT_MAX){ 
        *prev_data=head->data;
        free(head);
    }else{
        head->height=(*prev_data);
        (*prev_data)=INT_MAX;
    }
    return treeCompressionRec(head->right,prev_data);
}

struct avlnode *removeHalfNodes(struct avlnode *head){
    if(!head) return NULL;
    head->left=removeHalfNodes(head->left);
    head->right=removeHalfNodes(head->right);
    if((head->left && head->right) || (!head->left && !head->right)) return head;
    else if(!head->left) return head->right;
    else return head->left;
}

struct avlnode *removeleafNodes(struct avlnode *head){
    if(!head) return NULL;
    if(!head->left&&!head->right){
        free(head);
        return NULL;
    }
    head->left=removeleafNodes(head->left);
    head->right=removeleafNodes(head->right);
    return head;
}

struct avlnode *pruneTree(struct avlnode *head,int a,int b){
    if(!head) return NULL;
    head->left=pruneTree(head->left,a,b);
    head->right=pruneTree(head->right,a,b);
    if(head->data<a || head->data>b){
        if (head->data<a && head->right) return head->right;
        if(head->data>b && head->left) return head->left;
        return NULL;
    }
    return head;
}

int main(int argc, char const *argv[])
{
    struct avlnode *head=generateAVL(4);
    cout<<"The data of head after generating the AVL tree giving only height: "<<head->data<<endl;
    cout<<"Inorder print: ";
    printNodesInorder(head);
    cout<<endl;
    head=pruneTree(head,2,6);
    cout<<"Inorder print after the tree being pruned: ";
    printNodesInorder(head);
    cout<<endl;
    
    head=generateAVL(6);
    cout<<"Inorder print before the tree's leaves removed: ";
    printNodesInorder(head);
    cout<<endl;
    head=removeleafNodes(head);
    cout<<"Inorder print after the tree's leaves removed: ";
    printNodesInorder(head);
    cout<<endl;
    
    head=generateAVL(4);
    cout<<"Inorder print before the tree's half nodes removed: ";
    printNodesInorder(head);
    cout<<endl;
    head=removeHalfNodes(head);
    cout<<"Inorder print after the tree's half nodes removed: ";
    printNodesInorder(head);
    cout<<endl;

    return 0;
}
