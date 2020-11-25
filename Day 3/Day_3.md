# Data Structure and Algorithm

## Day 3 

#### mostly it has functions for binary search trees

### The functions applied in day 3 :
```sh
    struct node *deleteNode(struct node *head,int data);
    
    struct node *findMin(struct node *head);
    
    struct node *LCAbst(struct node *head,struct node *a,struct node *b);
    
    bool isBST(struct node *head);
    
    struct node *BST2DLL(struct node *head);
    
    struct node *concatDoublyLinkedLists(struct node *l,struct node *r);
    
    void printDLL(struct node *head);
    
    struct node *DLL2BBST(struct node *head);
    
    struct node *findMidNodeLL(struct node *head);

```
### The functions used from day 0 :
```sh
    struct node *makeBinarySearchTree(int a[],int l);
 
    struct node *getNewNode(int data);
 
    void printNodesInorder(struct node *head);

    void levelOrderTraversal(struct node *head);

```

## Output:
```sh
    Inorder print: 1, 2, 3, 5, 6, 8, 9, 
    Is the tree binary or not : True
    Inorder print after deletion: 1, 3, 5, 6, 8, 9, 
    Inorder print converting into DLL : 1, 3, 5, 6, 8, 9, 
    Level Order print converting DLL into B-BST: 6, 3, 9, 1, 5, 8,

```