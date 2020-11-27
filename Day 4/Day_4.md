# Data Structure and Algorithm

## Day 4 

#### mostly it has functions for binary search trees: (some which were left in day 3 and other that i did not write because i need not feel to implement as it was pretty understandable and not much new to implement.)

### The functions applied in day 4 :
```sh
    struct node *floorBST(struct node *head,struct node *prev,int data);
    
    struct node *ceilBST(struct node *head,struct node *prev,int data);
    
    void PrintRange(struct node *head,int i,int k);

```
### The functions used from day 0 :
```sh
    struct node *makeBinarySearchTree(int a[],int l);
 
    struct node *getNewNode(int data);
 
    void printNodesInorder(struct node *head);

```

## Output:
```sh
    Inorder print: 1, 2, 3, 5, 6, 8, 9, 
    Range Printing from i to j is : 5, 6, 
    The floor value of data passd in bst is : 3
    The ceil value of data passd in bst is : DoesNotExist

```