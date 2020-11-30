# Data Structure and Algorithm

## Day 5

#### Mostly it has functions for AVL trees

### The functions applied in day 5 :
```sh
    int heightAVL(struct avlnode *head);
    
    struct avlnode *getNewNode(int data,int height);
    
    struct avlnode *singleLRotation(struct avlnode *head);
    
    struct avlnode *singleRRotation(struct avlnode *head);
    
    struct avlnode *doubleLRRotation(struct avlnode *head);
    
    struct avlnode *doubleRLRotation(struct avlnode *head);
    
    struct avlnode *insertNode(struct avlnode *head,int data);
    
    struct avlnode *generateAVL(int h);
    
    struct avlnode *HB0(int h);
    
    int isAVL(struct avlnode* head);
    
    int closeInBST(struct avlnode *head,int data);

```

### The funtion applied from day 0:
```sh
    void printNodesInorder(struct avlnode *temp);
```

## Output:
```sh
    The data of head after generating the AVL tree giving only height: 5
    Inorder print: 1, 2, 3, 4, 5, 6, 7, 
    The tree generated above is avl or not: True
    The closest value in the Acting-BST Avl tree to 10 is: 7
    Inorder print of the AVL tree created using array is given: 1, 2, 3, 4, 5, 8, 
    The tree generated above is avl or not: True
```