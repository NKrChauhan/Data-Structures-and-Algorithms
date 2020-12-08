# Data Structure and Algorithm

## Day 8

#### Mostly it has functions for Priority Queues &Heaps problems

### The functions applied in day 8 :
```sh
    struct Heap *createHeapArray(int s,int type);
    
    int getParent(struct Heap *h, int index);
    
    int getRChild(struct Heap *h, int index);
    
    int getLChild(struct Heap *h, int index);
    
    int getMaximum(struct Heap *h);
    
    void percolateDown(struct Heap *h, int i);
    
    int deleteMax(struct Heap * h);
    
    void insertHeap(struct Heap *h, int data);
    
    void resizeHeap(struct Heap *h);
    
    struct Heap *destroyHeap(struct Heap *h);
    
    void buildHeap(struct Heap *h, int b[], int n);
    
    void heapSort(int a[], int n);

```
### The Heap structure applied :
```sh   
    struct Heap{
    int *a;
    int hSize;
    int count;      //number of element in a heap
    int hType;      //min=0 or max=1
};
```

## Output:
```sh
    The HeapSort of the array gives the result as : 12, 11, 10, 9, 7, 6, 5, 4, 2, 
    Performing operation on newly created heap and then printing the root node or the  maximum: 15
    Resizing Heap form size 15 to 30
    The Heap is deleted !        

```
