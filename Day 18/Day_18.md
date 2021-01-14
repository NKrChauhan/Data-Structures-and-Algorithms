# Data Structure and Algorithm

## Day 18

#### Mostly it has functions for Disjoint Sets ADT

### The functions applied in day 18 :
```sh
    void makeSet_SF(int a[], int s);
    int find_SF(int a[], int s, int x);
    void union_SF(int a[], int s, int r1, int r2);

    void makeSet_QF(int a[], int s);
    int find_QF(int a[], int s, int x);
    void union_QF_bySize(int a[], int s, int r1, int r2);
    void union_QF_byHeight(int a[], int s, int r1, int r2);

```

## Output:
```sh
    Making a fresh disjoint set (slow find) will look as: 0->0, 1->1, 2->2, 3->3, 4->4, 5->5, 6->6, 7->7, 8->8, 9->9, 
    Performing operation like union(4,6): 0->0, 1->1, 2->2, 3->3, 4->6, 5->5, 6->6, 7->7, 8->8, 9->9, 
    Performing operation like union(5,3): 0->0, 1->1, 2->2, 3->3, 4->6, 5->3, 6->6, 7->7, 8->8, 9->9, 
    Performing operation like union(1,6): 0->0, 1->6, 2->2, 3->3, 4->6, 5->3, 6->6, 7->7, 8->8, 9->9, 
    Performing operation like union(1,9): 0->0, 1->6, 2->2, 3->3, 4->6, 5->3, 6->9, 7->7, 8->8, 9->9, 
    Finally we get the following set: 0->0, 1->6, 2->2, 3->3, 4->6, 5->3, 6->9, 7->7, 8->8, 9->9, 
    Making a fresh disjoint set (quick find) will look as: 0->-1, 1->-1, 2->-1, 3->-1, 4->-1, 5->-1, 6->-1, 7->-1, 8->-1, 9->-1, 
    Performing operation like union(4,6) by size: 0->-1, 1->-1, 2->-1, 3->-1, 4->-2, 5->-1, 6->4, 7->-1, 8->-1, 9->-1, 
    Performing operation like union(5,3) by size: 0->-1, 1->-1, 2->-1, 3->5, 4->-2, 5->-2, 6->4, 7->-1, 8->-1, 9->-1, 
    Performing operation like union(1,6) by size: 0->-1, 1->4, 2->-1, 3->5, 4->-3, 5->-2, 6->4, 7->-1, 8->-1, 9->-1, 
    Performing operation like union(1,9) by size: 0->-1, 1->4, 2->-1, 3->5, 4->-4, 5->-2, 6->4, 7->-1, 8->-1, 9->4, 
    Finally we get the following set: 0->-1, 1->4, 2->-1, 3->5, 4->-4, 5->-2, 6->4, 7->-1, 8->-1, 9->4, 
    Making a fresh disjoint set (quick find) will look as: 0->-1, 1->-1, 2->-1, 3->-1, 4->-1, 5->-1, 6->-1, 7->-1, 8->-1, 9->-1, 
    Performing operation like union(4,6) by height: 0->-1, 1->-1, 2->-1, 3->-1, 4->-2, 5->-1, 6->4, 7->-1, 8->-1, 9->-1, 
    Performing operation like union(5,3) by height: 0->-1, 1->-1, 2->-1, 3->5, 4->-2, 5->-2, 6->4, 7->-1, 8->-1, 9->-1, 
    Performing operation like union(1,6) by height: 0->-1, 1->4, 2->-1, 3->5, 4->-2, 5->-2, 6->4, 7->-1, 8->-1, 9->-1, 
    Performing operation like union(1,9) by height: 0->-1, 1->4, 2->-1, 3->5, 4->-2, 5->-2, 6->4, 7->-1, 8->-1, 9->4, 
    Finally we get the following set: 0->-1, 1->4, 2->-1, 3->5, 4->-2, 5->-2, 6->4, 7->-1, 8->-1, 9->4, 

```