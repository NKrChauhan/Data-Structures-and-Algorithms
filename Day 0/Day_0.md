# Data Structure and Algorithm

## Day 0 

### The functions aplied in day 0 :
```sh
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
```

## Output:
```sh
    Inorder print: 1, 2, 3, 5, 6, 8, 
    Level order print: 2, 1, 6, 3, 8, 5, 
    The height:4
    Number of leaf nodes: 3
    Diameter of the binary tree: 4
    Diameter of the binary tree not using the global variable: 4
    Path present from root node to the leaf node totally: 
    -> 2 -> 1
    -> 2 -> 6 -> 3 -> 5
    -> 2 -> 6 -> 8
    Is sum present in the following tree : True
    Level order print: 2, 6, 1, 8, 3, 5, 
    the trees 1 and 2 are mirror or not : True
```