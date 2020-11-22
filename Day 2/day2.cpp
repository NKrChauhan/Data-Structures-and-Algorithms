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

// threaded tree node
struct t_node{
    struct t_node *left;
    int ltag;
    int data;
    int rtag;
    struct t_node *right;
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

int isQuasiIsomeric(struct node *head,struct node *head1);
struct t_node *findInorderSucessor(struct t_node *head);
void inorderTraversalThreadedBT(struct t_node *head);
struct t_node *findPreorderSucessor(struct t_node *head);
void preorderTraversalThreadedBT(struct t_node *head);
void insertionThreadedBTRight(struct t_node *head1,struct t_node *head2);
struct node *inOrderSucessorBT(struct node *head);

// Function definition

// the data does not matter but the structure becomes the same or isomeric when swapping the left and righr node 
int isQuasiIsomeric(struct node *head,struct node *head1){
    if(!head&&!head1) return 1;
    if(!head&&head1 || !head1&&head) return 0;
    return (isQuasiIsomeric(head->left,head1->left)||isQuasiIsomeric(head->right,head1->right)||isQuasiIsomeric(head->left,head1->right)||isQuasiIsomeric(head->right,head1->left));
}

// inorder sucessor in inorder threaded binary tree
struct t_node *findInorderSucessor(struct t_node *head){
    struct t_node *temp;
    if(head->rtag==0) return head->right;
    temp=head->right;
    while(temp->ltag==1) temp=temp->left;
    return temp;
}

// we give dummy node as the paremeter so all node can be traversed
void inorderTraversalThreadedBT(struct t_node *head){
    struct t_node *temp=head;
    while(1){
        temp=findInorderSucessor(temp);
        if(temp==head) break;
        cout<<temp->data<<", ";
    }
    cout<<endl;
}

struct t_node *findPreorderSucessor(struct t_node *head){
    if(head->ltag==1) return head->left;
    else{
        struct t_node *temp=head;
        // if nodes have no right child then automatically goes to top and then to next right.
        while(temp->rtag==0) temp=temp->right;
        return temp->right;
    }
}

void preorderTraversalThreadedBT(struct t_node *head){
    struct t_node *temp=findPreorderSucessor(head);
    while(1){
        if(temp==head) return ;
        cout<<temp->data<<", ";
        temp=findPreorderSucessor(temp);
    }
}

// insertion of head in the right of root
void insertionThreadedBTRight(struct t_node *head,struct t_node *root){
    head->right=root->right;
    root->right=head;
    if(root->rtag==0){
        head->rtag=0;
        root->rtag=1;
    }else{ 
        //if the root has a right child so we need inorder successor of its right
        struct t_node *temp=findInorderSucessor(root);
        temp->left=head;
    }
}

// iterative non threaded tree algorithm
struct node *inOrderSucessorBT(struct node *root,struct node *head){
    struct node *temp=root;
    vector<struct node *> v;
    int flag=0;
    v.push_back(root);
    while(!v.empty()){
        while(temp->left){ 
            v.push_back(temp);
            temp=temp->left;
        }
        if(flag==1) break;
        temp=v[v.size()-1];
        v.pop_back();
        if(temp==head) flag=1;
        if(temp->right) temp=temp->right;
    }
    return temp;
}

int main(int argc, char const *argv[]) {
    int a[]={2,6,3,5,1,8};
    struct node *head=makeBinarySearchTree(a,6);
    cout<<"Inorder print: ";
    printNodesInorder(head);
    cout<<endl;
    int b[]={3,7,4,6,2,9};
    struct node *head1=makeBinarySearchTree(b,6);
    string s=isQuasiIsomeric(head,head1)?"True":"False";
    cout<<"The following trees are quasi-isomeric in nature: "+s<<endl;
    // iterative inorder successor detection so lets test
    cout<<"The inorder successor of the node given has data : "<<inOrderSucessorBT(head,head)->data<<endl;
    return 0;
}
