#include <iostream>
#include <queue>
#include <vector> 
#include <map> 

using namespace std;

// structure 

struct node{
    int data;
    struct node *left=NULL;
    struct node *right=NULL;
    struct node *next=NULL;
};

// previously made function reused decleration
struct node *getNewNode(int data);
struct node *makeBinarySearchTree(int a[],int l);
void printNodesInorder(struct node *head);

// Function previous definition
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

// Function Decleration
struct node *connectLevelNonRecWithQs(struct node *head);
void connectLevelNonRecWithoutQs(struct node *head);
int maxPathSum(struct node *head);

// Function Definition
//approch :- using the concept from level order traversal
struct node *connectLevelNonRecWithQs(struct node *head){
    queue<struct node *> q;
    deque<struct node *> res; 
    if(!head) return NULL;
    q.push(head);
    q.push(getNewNode(-1));
    while(!q.empty()){
        struct node *temp=q.front();
        q.pop();
        if(temp->data==-1) {
            // enter all res to make linked list
            int i=0;
            while(i<res.size()-1){ res[i]->next=res[i+1];i++;}
            res.back()->next=res.front();
            // empty the queue res (reset)
            while(!res.empty()) res.pop_front();
            // enter the -1 to the queue q for pointing
            if(q.empty()) break; 
            q.push(getNewNode(-1));
        }
        else res.push_back(temp);   
        if(temp->left)  q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    return head;
}

// increased space complexity and more difficult to understand
void connectLevelNonRecWithoutQs(struct node *head){
    if(!head) return ;
    struct node *temp,*leftmostNode,*rightmostNode;
    temp=head;
    leftmostNode=rightmostNode=NULL;
    while(temp!=NULL){
        // try to make conditions of left and right child in this kind of case instead of using variable condition and inside left right condition
        if(temp->left){
            if(leftmostNode==NULL){ //condition can also means same if rightmostNode==NULL as both NULL at same time at this phase
                leftmostNode=temp->left;
                rightmostNode=temp->left;
            }else {
                // this is when second iteration of temp
                rightmostNode->next=temp->left;
                rightmostNode=rightmostNode->next;
            }
        }
        if(temp->right){
            if(rightmostNode==NULL){
                leftmostNode=temp->right;
                rightmostNode=temp->right;
            }
            else{
                // second iteration of temp
                rightmostNode->next=temp->right;
                rightmostNode=rightmostNode->next;
            }
        }
    temp=temp->next;
    }
    connectLevelNonRecWithoutQs(leftmostNode);
}

// the global variable will be used probably.
int maxim=-99999;
int maxPathSum(struct node *head){
    if(!head) return 0;
    int l=maxPathSum(head->left);
    int r=maxPathSum(head->right);
    if(l<0 && r<0) return head->data;
    else {
        int up,path;
        path=l+r+head->data;
        up=max(l,r)+head->data;
        if(maxim<path) maxim=path;
        return up;
    }

    return 0;
}

int main(int argc, char const *argv[]){
    int a[]={5,6,3,4,2,1,9,8};
    struct node *head=makeBinarySearchTree(a,8);
    cout<<"Inorder print: ";
    printNodesInorder(head);
    cout<<endl;
    head=connectLevelNonRecWithQs(head);
    cout<<"This proves that non recurrsive function works fine to connect levels: "<<head->left->next->data<<endl;
    int x=maxPathSum(head);
    cout<<"Maximum path sum is given as follows: "<<maxim<<endl;
    head=makeBinarySearchTree(a,8);
    connectLevelNonRecWithoutQs(head);
    cout<<"This proves that recurrsive function works fine to connect levels: "<<head->left->right->next->data<<endl;
    return 0;
}
