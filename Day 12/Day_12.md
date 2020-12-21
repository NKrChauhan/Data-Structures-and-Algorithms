# Data Structure and Algorithm

## Day 12

#### Mostly it has functions for Searching and related Problems

### The functions applied in day 12 :
```sh
    bool existSum(int a[], int b[], int n, int k);
    
    void printLL(struct node *head);
    
    struct node *makeLinkedList(int a[], int n);
    
    struct node *quickSortLinkedList(struct node *head);
    
    struct node *mergeSortLinkedList(struct node *head);
    
    struct node *mergeLinkedList(struct node *head1,struct node *head2);  

```

## The structure of linked list node used:
```sh
    struct node {
    int data;
    struct node *next=NULL;
};
```

## The function used from day 11:
```sh
    int binarySearchIterative(int a[], int n, int x);
```

## Output:
```sh
    The number given is available as sum or not : 1
    This is the unsorted linked list : 5, 6, 1, 9, 7, 3, 2, 
    This is the sorted linked list using merge sort algorithm: 1, 2, 3, 5, 6, 7, 9, 
    This is the unsorted linked list : 9, 6, 1, 3, 4, 7, 0, 
    This is the sorted linked list using quick sort algorithm: 0, 1, 3, 4, 6, 7, 9, 

```
