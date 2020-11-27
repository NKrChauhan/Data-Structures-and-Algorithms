#include <iostream>
#include <queue>
#include <vector> 
#include <map> 

using namespace std;

// structure 

struct node{
    int data;
    struct node *left;
    struct node *right;
};
// previously made function reused decleration

struct node *makeBinarySearchTree(int a[],int l);
struct node *getNewNode(int data);
void printNodesInorder(struct node *head);

// previous definitions

struct node *getNewNode(int data){
    struct node *head=(struct node*)malloc(sizeof(struct node));
    head->data=data;
    head->left=NULL;
    head->right=NULL;
    return head;
}

struct node *makeBinarySearchTree(int a[],int l){
    struct node *head=getNewNode(a[0]);
    for(int i=1;i<l;i++){
        struct node *newN=getNewNode(a[i]);
        struct node *point=head;
        while(1){
            if(point->data>=a[i]){
                if(!point->left){
                    point->left=newN;
                    break;
                }
                else point=point->left;
            }else{
                if(!point->right){
                    point->right=newN;
                    break;
                }
                else point=point->right;
            }
        }
    }
    return head;
}

void printNodesInorder(struct node *temp){
    if(!temp) return;
    printNodesInorder(temp->left);
    cout<<temp->data<<", ";
    printNodesInorder(temp->right);
    return;
}

// Function decleration
struct node *floorBST(struct node *head,struct node *prev,int data);
struct node *ceilBST(struct node *head,struct node *prev,int data);
void PrintRange(struct node *head,int i,int k);

// Function definition
struct node *floorBST(struct node *head,struct node *prev,int data){
    if(!head) return prev;
    struct node *temp=floorBST(head->left,prev,data);
    if(head->data==data) return head;
    if(head->data>data) return temp;
    if(head->data<data){
        prev=head;
        return floorBST(head->right,prev,data);
    }
}

struct node *ceilBST(struct node *head,struct node *prev,int data){
    if(!head) return prev;
    if(head->data == data) return head;
    struct node *temp=ceilBST(head->right,prev,data);
    if(head->data <data)return temp;
    else{
        prev=head;
        return ceilBST(head->left,head,data);
    }
}

void PrintRange(struct node *head,int i,int k){
    if(!head) return;
    if(head->data<=k && head->data>=i){
        PrintRange(head->left,i,k);
        cout<<head->data<<", ";
        PrintRange(head->right,i,k);
    }else if(head->data<k && head->data<i)PrintRange(head->right,i,k);
    else PrintRange(head->left,i,k);
}

int main(int argc, char const *argv[]) {
    int a[]={2,6,3,5,1,8,9};
    struct node *head=makeBinarySearchTree(a,7);
    cout<<"Inorder print: ";
    printNodesInorder(head);
    cout<<endl;
    cout<<"Range Printing from i to j is : ";
    PrintRange(head,4,7);
    cout<<endl;
    struct node *flr=floorBST(head,NULL,4);
    if(flr)cout<<"The floor value of data passd in bst is : "<<flr->data<<endl;
    else cout<<"The floor value of data passd in bst is : DoesNotExist"<<endl;
    struct node *cl=ceilBST(head,NULL,10);
    if(cl)cout<<"The floor value of data passd in bst is : "<<cl->data<<endl;
    else cout<<"The ceil value of data passd in bst is : DoesNotExist"<<endl;
    return 0;
}