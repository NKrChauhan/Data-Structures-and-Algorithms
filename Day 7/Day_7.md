# Data Structure and Algorithm

## Day 7

#### Mostly it has functions for trees problems

### The functions applied in day 7 :
```sh
    struct node *connectLevelNonRecWithQs(struct node *head);
    
    void connectLevelNonRecWithoutQs(struct node *head);
    
    int maxPathSum(struct node *head);

```
### The node structure is a bit different used in the problems
```sh 
    struct node{
        int data;
        struct node *left=NULL;
        struct node *right=NULL;
        struct node *next=NULL;
    };
```
### The funtion applied from day 3:
```sh   
    void printNodesInorder(struct node *head);
    
    struct node *getNewNode(int data,int height);
    
    struct node *makeBinarySearchTree(int a[],int l);

```

## Output:
```sh
    Inorder print: 1, 2, 3, 4, 5, 6, 8, 9, 
    This proves that non recurrsive function works fine to connect levels: 6
    Maximum path sum is given as follows: 35
    This proves that recurrsive function works fine to connect levels: 9

```
