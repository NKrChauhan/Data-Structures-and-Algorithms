# Data Structure and Algorithm

## Day 6

#### Mostly it has functions for AVL/BST trees problems

### The functions applied in day 6 :
```sh
    struct avlnode *treeCompressionNonRec(struct avlnode *head);
    
    struct avlnode *treeCompressionRec(struct avlnode *head, int *prev_data);
    
    struct avlnode *removeHalfNodes(struct avlnode *head);
    
    struct avlnode *removeleafNodes(struct avlnode *head);
    
    struct avlnode *pruneTree(struct avlnode *head,int a,int b);

```

### The funtion applied from day 5:
```sh   
    void printNodesInorder(struct avlnode *head);
    
    struct avlnode *getNewNode(int data,int height);
    
    struct avlnode *generateAVL(int h);

```

### The funtion applied from day 3:
```sh   
    struct avlnode *findMax(struct avlnode *head);
    
    struct avlnode *findMin(struct avlnode *head);
    
    struct avlnode *deleteNode(struct avlnode *head,int data);

```

## Output:
```sh
    The data of head after generating the AVL tree giving only height: 5
    Inorder print: 1, 2, 3, 4, 5, 6, 7, 
    Inorder print after the tree being pruned: 2, 3, 4, 5, 6, 
    Inorder print before the tree's leaves removed: 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 
    Inorder print after the tree's leaves removed: 9, 10, 12, 14, 15, 17, 18, 20, 22, 23, 25, 27, 
    Inorder print before the tree's half nodes removed: 28, 29, 30, 31, 32, 33, 34, 
    Inorder print after the tree's half nodes removed: 28, 30, 31, 32, 33,  

```