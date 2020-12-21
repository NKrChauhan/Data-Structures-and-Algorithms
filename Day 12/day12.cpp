#include <iostream>
#include <bits/stdc++.h> //cpp stl functions like sort not work without it so be careful guys
#include <queue>
#include <math.h>       /* floor */
#include <vector> 
#include <map> 

using namespace std;

// THE LINKED LIST STRUCT 
struct node {
    int data;
    struct node *next=NULL;
};

// previously made function reused decleration
int binarySearchIterative(int a[], int n, int x);

// Function previous definition
int binarySearchIterative(int a[], int n, int x){
    int start=0,end=n-1;
    while(end>start){
        int mid=start+floor((end-start)/2);
        if(a[mid]==x) return mid;
        else if(a[mid]<x) start=mid+1;
        else end=mid-1;
    }
    return -1;
}

// Function decleration
bool existSum(int a[], int b[], int n, int k);
void printLL(struct node *head);
struct node *makeLinkedList(int a[], int n);
struct node *quickSortLinkedList(struct node *head);
struct node *mergeSortLinkedList(struct node *head);
struct node *mergeLinkedList(struct node *head1,struct node *head2);

// Function definition
bool existSum(int a[], int b[], int n, int k){
    // problem is to make the function in o(nlogn) type.
    // sorting algo used can be heapsort but for simplicity the sort function is to be used here.
    sort(a,a+n);                //O(nlogn) assume
    for(int i=0;i<n;i++){       //O(n)
        int c=k-b[i];
        if(binarySearchIterative(a,n,c)!=-1) return true; //O(logn)
    }
    return false;

}

void printLL(struct node *head){
    struct node *temp=head;
    while(temp){
        cout<<temp->data<<", ";
        temp=temp->next;
    }
    cout<<endl;
}

struct node *makeLinkedList(int a[], int n){
    struct node *head=NULL,*tail=NULL;
    for(int i=0;i<n;i++){
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        temp->data=a[i];
        temp->next=NULL;
        if(!head) head=tail=temp;
        else{
            tail->next=temp;
            tail=tail->next;
            tail->next=NULL;
        }
    }
    return head;
}

struct node *quickSortLinkedList(struct node *head){
    struct node *head1=NULL,*head2=NULL,*tail1=NULL,*tail2=NULL;
    if(!head||!head->next) return head;
    struct node *pivot=head;
    head=head->next;
    while(head){
        if(head->data<=pivot->data){
            if(!head1){
                head1=tail1=head;
            }else{
                tail1->next=head;
                tail1=tail1->next;
            }
        }else{
            if(!head2){
                head2=tail2=head;
            }else{
                tail2->next=head;
                tail2=tail2->next;
            }
        }
        head=head->next;        
    }
    if(tail1) tail1->next=NULL;
    if(tail2) tail2->next=NULL;
    head1=quickSortLinkedList(head1);
    if(head1){
        struct node *temp=head1;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=pivot;
    } 
    else head1=pivot;
    pivot->next=quickSortLinkedList(head2);
    return head1;
}

// we do the split in a creative way that is in one swoop how? even/odd split
struct node *mergeSortLinkedList(struct node *head){
    struct node *head1=NULL,*head2=NULL,*tail1=NULL,*tail2=NULL;
    int i=1;
    if(!head||!head->next) return head;
    while(head){
        if(i%2!=0){
            if(head1==NULL) tail1=head1=head;
            else{
                tail1->next=head;
                tail1=tail1->next;    
            }
        }else{
            if(head2==NULL) tail2=head2=head;
            else{
                tail2->next=head;
                tail2=tail2->next;
            }
        }
        head=head->next;
        i++;
    }
    if(tail1) tail1->next=NULL;
    if(tail2) tail2->next=NULL;
    head1=mergeSortLinkedList(head1);
    head2=mergeSortLinkedList(head2);
    return mergeLinkedList(head1,head2);
}

struct node *mergeLinkedList(struct node *head1,struct node *head2){
    struct node *root=NULL,*temp;
    while(head1&&head2){
        if(head1->data<head2->data){
            if(!root){ 
                root=head1;
                temp=head1;
            }else{
                temp->next=head1;
                temp=temp->next;
            }
            head1=head1->next;
        }
        else{
            if(!root){ 
                root=head2;
                temp=head2;
            }else{
                temp->next=head2;
                temp=temp->next;
            }
            head2=head2->next;
        }
    }
    while(head1){
        temp->next=head1;
        temp=temp->next;
        head1=head1->next;
    }
    while(head2){
        temp->next=head2;
        temp=temp->next;
        head2=head2->next;
    }
    if(temp) temp->next=NULL;
    return root;
}

int main(int argc, char const *argv[]){
    int e1[]={9,5,3,7,6,0,1};
    int e2[]={8,6,7,2,3,4,1};
    cout<<"The number given is available as sum or not : ";
    cout<<existSum(e1,e2,7,10)<<endl;
    int a[]={5,6,1,9,7,3,2};
    struct node *head=makeLinkedList(a,7);
    cout<<"This is the unsorted linked list : ";
    printLL(head);
    head=mergeSortLinkedList(head);
    cout<<"This is the sorted linked list using merge sort algorithm: ";
    printLL(head);
    int b[]={9,6,1,3,4,7,0};
    struct node *head1=makeLinkedList(b,7);
    cout<<"This is the unsorted linked list : ";
    printLL(head1);
    head1=quickSortLinkedList(head1);
    cout<<"This is the sorted linked list using quick sort algorithm: ";
    printLL(head1);
    return 0;
}
