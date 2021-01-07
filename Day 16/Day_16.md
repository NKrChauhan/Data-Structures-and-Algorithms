# Data Structure and Algorithm

## Day 16

#### Mostly it has functions for Hashing
##### specifically: saperate chaining

### The functions applied in day 16 :
```sh
    int hashFunction(int data, int size);
    
    struct HashTable *createHashTable(int size);
    
    int searchHashTable(struct HashTable *h,int data);
    
    int insertHashTable(struct HashTable *h,int data);
    
    int deleteHashTable(struct HashTable *h,int data);
    
    void rehashHashTable(struct HashTable *h);

```
## The Structure used :
```sh
    struct node{
        int data;
        struct node *next;
    };

    struct HashTableNode{
        int block_size;  
        struct node *next;
    };

    struct HashTable{
        int hSize;      
        int count;      
        struct HashTableNode **table;
    };
    
```

## Output:
```sh
    N/A <Program terminated with signal SIGSEGV, Segmentation fault>
    *will be debugged and updated soon.*
    Note:
    source of error is at h->table[index]->next
```