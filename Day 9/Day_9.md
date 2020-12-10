# Data Structure and Algorithm

## Day 9
#### (it is merged with the day8.cpp code due to lack of number of problems it has to code.) 

#### Mostly it has functions for Priority Queues & Heaps problems

### The functions applied in day 9 :
```sh
    int kthMax(struct Heap *h,int k);
    
    int getKthMax(struct Heap *h,int k);
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

### The functions applied in day 8 :
```sh
    struct Heap *createHeapArray(int s,int type);
    
    void buildHeap(struct Heap *h, int b[], int n);
    
    int deleteMax(struct Heap * h);
    
    void percolateDown(struct Heap *h, int i);

    void resizeHeap(struct Heap *h);

    int getParent(struct Heap *h, int index);

    int getRChild(struct Heap *h, int index);

    int getLChild(struct Heap *h, int index);
```

## Output:
```sh
    N/A
```
