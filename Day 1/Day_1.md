# Data Structure and Algorithm

## Day 1 

### The functions aplied in day 1 :
```sh
    struct node *LeastCommonAncestor(struct node *head,struct node *a,struct node *b);

    struct node *makeBinarySearchTreeIN_PRE(int inorder[],int pre[],int i_i,int i_j,int pre_i);

    bool allAncestorNodes(struct node *root,struct node *head);
    
    void zigZagTraversal(struct node *head);
    
    void verticalSum(struct node *head,int column);
    
    struct node *buildPreorderChar(char *a,int *i);

    void fillNextSibbling(struct node * head);

```
### The functions used from day 0 :
```sh
    struct node *makeBinarySearchTree(int a[],int l);
 
    struct node *getNewNode(int data);
 
    void printNodesInorder(struct node *head);
```

## Output:
```sh
    Inorder print: 1, 2, 3, 5, 6, 8, 
    2 is the parent in example
    <- 6<- 2
    the zigZag traversal: 
    2, 1, 6, 8, 3, 5, 
    -1 1, 0 5, 1 11, 2 8, 
    Inorder print in & pre given : 1, 2, 3, 5, 6, 8, 
    Inorder print of leaf and internal where preorder given : 2, 1, 2, 1, 2, 
    the structure has sibbling address so you can traverse to that : 1

```