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
void levelOrderTraversal(struct node *head);

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

void levelOrderTraversal(struct node *head){
    queue<struct node *> q;
    int i=0;
    q.push(head);
    while(!q.empty()){
        struct node *temp=q.front();
        q.pop();
        cout<<temp->data<<", ";
        if(temp->left)  q.push(temp->left);
        if(temp->right) q.push(temp->right);
        i++;
        if(i>15)break;//as debugger for there is some error in refrencing pointer in DLL2BBST
    }
}

// Function decleration
struct node *deleteNode(struct node *head,int data);
struct node *findMin(struct node *head);
struct node *LCAbst(struct node *head,struct node *a,struct node *b);
bool isBST(struct node *head);
struct node *BST2DLL(struct node *head);
struct node *concatDoublyLinkedLists(struct node *l,struct node *r);
void printDLL(struct node *head);
struct node *DLL2BBST(struct node *head);
struct node *findMidNodeLL(struct node *head);

// Function definition
struct node *findMin(struct node *head){
    struct node *temp;
    if(!head) return NULL;
    else if(!head->left)
        return head;
    else{
        temp=findMin(head->left);
    }
    return temp;
}

struct node *deleteNode(struct node *head,int data){
    if(head==NULL) return NULL;
    struct node *temp=NULL;
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

struct node *LCAbst(struct node *head,struct node *a,struct node *b){
    if(!head) return NULL;
    if((head->data<a->data && head->data>b->data)||(head->data<a->data && head->data>b->data)) return head;
    else if(head->data<a->data && head->data<b->data) return LCAbst(head->right,a,b);
    else return LCAbst(head->left,a,b);
}

bool isBST(struct node *head){
    if(!head) return true;
    bool flag=true;
    if(head->right) flag=head->data<head->right->data?true:false;
    if(head->left) flag=(head->data>head->left->data?true:false && flag);
    return flag&&isBST(head->left)&&isBST(head->right);
}

struct node *concatDoublyLinkedLists(struct node *l,struct node *r){
    if(!l) return r;
    if(!r) return l;
    struct node *lLast=l->left;
    struct node *rLast=r->left;
    // pointers manipulation
    lLast->right=r;
    r->left=lLast;
    rLast->right=l;
    l->left=rLast;
    return l;
}

struct node *BST2DLL(struct node *head){
    struct node *left,*right;
    if(!head) return NULL;
    left=BST2DLL(head->left);
    right=BST2DLL(head->right);
    head->left=head->right=head;
    return concatDoublyLinkedLists(concatDoublyLinkedLists(left,head),right);
}

void printDLL(struct node *head){
    struct node *temp=head;
    do{
        cout<<temp->data<<", ";
        temp=temp->right;
    }while(temp!=head); 
    cout<<endl;
}

struct node *findMidNodeLL(struct node *head){
    if(!head) return NULL;
    vector<struct node *> v;
    struct node *temp;
    temp=head;
    v.push_back(temp);
    while(1){
        if(!temp->right||temp->right==head)break;
        temp=temp->right;
        v.push_back(temp);
    }
    int s=v.size();
    s=s%2==0?(s/2):(s-1)/2;
    temp=v[s];
    return temp;
}

// prev pointer is left and next pointer is right 
struct node *DLL2BBST(struct node *head){
    if(!head || !head->right) return head;
    struct node *pmid,*nmid,*mid;
    mid=findMidNodeLL(head);
    pmid=head;
    if(head!=mid)
        while(pmid->right!=mid) 
            pmid=pmid->right;
    if(head->left){
        struct node *temp=head->left;
        temp->right=NULL;
        head->left=NULL;
    }
    nmid=mid->right;
    pmid->right=NULL;
    if(nmid)nmid->left=NULL;
    mid->left=DLL2BBST(head);
    mid->right=DLL2BBST(nmid);
    // cout<<mid->left->data<<" "<<mid->data <<" ";
    // if(mid->right)cout<<mid->right->data<<endl;
    // else cout<<endl;
    return mid;
}

int main(int argc, char const *argv[]) {
    int a[]={2,6,3,5,1,8,9};
    struct node *head=makeBinarySearchTree(a,7);
    cout<<"Inorder print: ";
    printNodesInorder(head);
    cout<<endl;
    string s=(isBST(head)==1)?"True":"False";
    cout<<"Is the tree binary or not : "<<s<<endl;
    head=deleteNode(head,2);
    cout<<"Inorder print after deletion: ";
    printNodesInorder(head);
    cout<<endl;
    cout<<"Inorder print converting into DLL : ";
    head=BST2DLL(head);
    printDLL(head);
    cout<<"Level Order print converting DLL into B-BST: ";
    head=DLL2BBST(head);
    levelOrderTraversal(head);
    return 0;
}
