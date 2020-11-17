#include <iostream>
#include <queue>
#include <vector> 

using namespace std;

// structure 

struct node{
    int data;
    struct node *left;
    struct node *right;
};

// decleration

struct node *makeBinarySearchTree(int a[],int l);
struct node *getNewNode(int data);
void printNodesInorder(struct node *head);
void levelOrderTraversal(struct node *head);
int heightNonRecurssive(struct node *head);
int noOfLeafNodes(struct node *head);
int diameterOfBinaryTree(struct node *head);
int binaryTreeDiameterWithoutGlobalVar(struct node *head);
void printAllPathRootToLeaf(struct node *head,vector<int> v);
void mirrorBinarySearchTree(struct node **head);
bool isSumPresent(struct node *head,int sum);
bool isTreesMirror(struct node *head1,struct node *head2);

// definition of functions

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

void mirrorBinarySearchTree(struct node **head){
    if(*head){
        mirrorBinarySearchTree(&((*head)->left));
        mirrorBinarySearchTree(&((*head)->right));
        struct node *temp=(*head)->left;
        (*head)->left=(*head)->right;
        (*head)->right=temp;
    }
}

void printNodesInorder(struct node *temp){
    if(!temp) return;
    printNodesInorder(temp->left);
    cout<<temp->data<<", ";
    printNodesInorder(temp->right);
    return;
}

// Level order traversal BT
void levelOrderTraversal(struct node *head){
    queue<struct node *> q;
    q.push(head);
    while(!q.empty()){
        struct node *temp=q.front();
        q.pop();
        cout<<temp->data<<", ";
        if(temp->left)  q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

// finding height non-recursive
int heightNonRecurssive(struct node *head){
    queue<struct node *> q;
    int h=0;
    q.push(head);
    q.push(NULL);
    while(!q.empty()){
        struct node *temp=q.front();
        q.pop();
        if(!temp){
            h++;
            if(!q.front()) break;
            q.push(NULL);
        }else{
            if(temp->left) q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
    }
    return h;
}

// number of leaf nodes that are present in the BT 
int noOfLeafNodes(struct node *head){
    if(!head) return 0;
    if(!head->left && !head->right) return 1;
    return noOfLeafNodes(head->left) + noOfLeafNodes(head->right);
}

// diameter of the tree (londest path between leaf nodes)
int diameter=0;
int diameterOfBinaryTree(struct node *head){
    if(!head) return 0;
    int l=diameterOfBinaryTree(head->left);
    int r=diameterOfBinaryTree(head->right);
    if(l+r>diameter)diameter=l+r;
    return max(l,r)+1; 
}

int binaryTreeDiameterWithoutGlobalVar(struct node *head){
    if(!head) return 0;
    int l=binaryTreeDiameterWithoutGlobalVar(head->left);
    int r=binaryTreeDiameterWithoutGlobalVar(head->right);
    int lh=heightNonRecurssive(head->left);
    int rh=heightNonRecurssive(head->right);
    if(lh+rh>max(l,r)) return lh+rh;
    else return max(l,r);
}

// print all possible path from root to leaf
void printAllPathRootToLeaf(struct node *head,vector<int> v){
    if(!head) return;
    v.push_back(head->data);
    if(!head->left && !head->right){
        for(auto i=v.begin();i!=v.end();i++) cout<<" -> "<<*i;
        cout<<endl;
    }else{
        printAllPathRootToLeaf(head->left,v);
        printAllPathRootToLeaf(head->right,v);
    }
}

// sum is present or not in a branch of a tree
bool isSumPresent(struct node *head,int sum){
    if(!head) return sum==0;
    sum-=head->data;
    if(sum<0)return false;
    return (isSumPresent(head->left,sum) || isSumPresent(head->right,sum));    
}

// check if two trees are mirror of each other
bool isTreesMirror(struct node *head1,struct node *head2){
    if(!head1 && !head2) return true;
    if(head1==NULL || head2==NULL) return false;
    else return (head1->data==head2->data && isTreesMirror(head1->left,head2->right) && isTreesMirror(head1->right,head2->left));
}

int main() {
    int a[]={2,6,3,5,1,8};
    struct node *head=makeBinarySearchTree(a,6);
    cout<<"Inorder print: ";
    printNodesInorder(head);
    cout<<endl;
    cout<<"Level order print: ";
    levelOrderTraversal(head);
    cout<<endl;
    cout<<"The height:"<<heightNonRecurssive(head)<<endl;
    cout<<"Number of leaf nodes: "<<noOfLeafNodes(head)<<endl;
    diameter=diameterOfBinaryTree(head);
    cout<<"Diameter of the binary tree: "<<diameter<<endl;
    cout<<"Diameter of the binary tree not using the global variable: "<<binaryTreeDiameterWithoutGlobalVar(head)<<endl;
    // mirrorBinarySearchTree(&head);
    cout<<"Path present from root node to the leaf node totally: "<<endl;
    vector<int> v;
    printAllPathRootToLeaf(head,v);
    string s=isSumPresent(head,3)?"True":"False";
    cout<<"Is sum present in the following tree : "<<s<<endl;
    struct node *head1=makeBinarySearchTree(a,6);
    mirrorBinarySearchTree(&head1);
    cout<<"Level order print: ";
    levelOrderTraversal(head1);
    cout<<endl;
    s=isTreesMirror(head1,head)?"True":"False";
    cout<<"the trees 1 and 2 are mirror or not : "<<s<<endl;
    return 0;
}
