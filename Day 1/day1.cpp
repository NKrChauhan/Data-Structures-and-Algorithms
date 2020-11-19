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
    struct node *sib=NULL;
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

struct node *LeastCommonAncestor(struct node *head,struct node *a,struct node *b);
struct node *makeBinarySearchTreeIN_PRE(int inorder[],int pre[],int i_i,int i_j,int pre_i);
bool allAncestorNodes(struct node *root,struct node *head);
void zigZagTraversal(struct node *head);
void verticalSum(struct node *head,int column);
struct node *buildPreorderChar(int *a,int *i);
void fillNextSibbling(struct node *head);

// Function definition 

struct node *LeastCommonAncestor(struct node *head,struct node *a,struct node *b){
    if(!head) return head;
    if(head==a) return a;
    if(head==b) return b;
    struct node *l=LeastCommonAncestor(head->left,a,b);
    struct node *r=LeastCommonAncestor(head->right,a,b);
    if(l&&r) return head;
    else return l?l:r;
}

struct node *makeBinarySearchTreeIN_PRE(int inorder[],int pre[],int i_i,int i_j,int pre_i){
    if(i_i>i_j) return NULL;
    struct node *temp=getNewNode(pre[pre_i]);
    // the indices is what we want to manipulate basically, as that is the one piece in the puzzle
    int x=i_i;
    for(;x<i_j;x++) if(inorder[x]==temp->data) break; 
    temp->left=makeBinarySearchTreeIN_PRE(inorder,pre,i_i,x-1,pre_i+1);
    temp->right=makeBinarySearchTreeIN_PRE(inorder,pre,x+1,i_j,pre_i+i_j+1);
    return temp;
}

bool allAncestorNodes(struct node *root,struct node *head){
    if(!root) return false;
    if (root->left==head || root->right==head || allAncestorNodes(root->left,head) || allAncestorNodes(root->right,head)){
        cout<<"<- "<<root->data;
        return true;
    }
    return false;
}

void zigZagTraversal(struct node *head){
    int flag=0;
    vector<struct node *> x;
    vector<struct node *> y;
    x.push_back(head);
    while(1){
        if(x.empty()&&y.empty()) break;
        if(flag==0){
            while(!x.empty()){
                struct node *temp=x.back();
                x.pop_back();
                cout<<temp->data<<", ";
                if(temp->right) y.push_back(temp->right);
                if(temp->left) y.push_back(temp->left);
            }
            flag=1;
        }else{
            while(!y.empty()){
                struct node *temp=y.back();
                y.pop_back();
                cout<<temp->data<<", ";
                if(temp->left) x.push_back(temp->left);
                if(temp->right) x.push_back(temp->right);
            }
            flag=0;
        }
    }
    cout<<endl;
}

map<int,int> m;
void verticalSum(struct node *head,int column){
    if(!head) return;
    m[column]+=head->data;
    verticalSum(head->left,column-1);
    verticalSum(head->right,column+1);
}

// int 2 means leaf node and 1 means internal node so the tree can have only 0 or 2 child
struct node *buildPreorderChar(int *a,int *i){
    struct node *temp=getNewNode(-1);
    if(!a) {
        free(temp);
        return NULL;
    }
    temp->data=a[*i];
    if(a[*i]==2) return temp;
    else{
    (*i)=(*i)+1;
    temp->left=buildPreorderChar(a,i);
    (*i)=(*i)+1;
    temp->right=buildPreorderChar(a,i);
    }
    return temp;
}

// filling the sibling thinking its null initially 
void fillNextSibbling(struct node *head){
    if(!head) return;
    if(head->left) head->left->sib=head->right;
    if(head->right) head->right->sib=head->left;
    fillNextSibbling(head->left);
    fillNextSibbling(head->right);
}

int main(int argc, char const *argv[]) {
    int a[]={2,6,3,5,1,8};
    struct node *head=makeBinarySearchTree(a,6);
    cout<<"Inorder print: ";
    printNodesInorder(head);
    cout<<endl;
    cout<<LeastCommonAncestor(head,head->left,head->right->left)->data<<" is the parent in example"<<endl;
    bool x=allAncestorNodes(head,head->right->left);
    cout<<endl<<"the zigZag traversal: "<<endl;
    zigZagTraversal(head);
    verticalSum(head,0);
    for(auto i=m.begin();i!=m.end();i++) cout<<i->first<<" "<<i->second<<", ";
    cout<<endl;
    int in[]={4,2,5,1,6,3};
    int pre[]={1,2,4,5,3,6};
    struct node *root=makeBinarySearchTreeIN_PRE(in,pre,0,5,0);
    cout<<"Inorder print in & pre given : ";
    printNodesInorder(head);
    int b[]={1,2,1,2,2};
    int i=0;
    struct node *BPO=buildPreorderChar(b,&i);
    cout<<endl;
    cout<<"Inorder print of leaf and internal where preorder given : ";
    printNodesInorder(BPO);
    cout<<endl;
    cout<<"the structure has sibbling address so you can traverse to that : ";
    fillNextSibbling(head);
    cout<<head->right->sib->data<<endl;
    return 0;
}