# Data Structure and Algorithm

## Day 17

#### Mostly it has functions for Hashing:Bloom filters

### The functions applied in day 17 :
```sh
    struct bloomNode *createBloom(int s);
    void insertBloom(struct bloomNode *a, int x);
    void deleteBloom(struct bloomNode *a, int x);
    int searchBloom(struct bloomNode *a, int x);
    
```
## The Structure used :
```sh
    struct bloomNode{
    int *pres;
    int *dele;
    int bSize;
    };
```

## Output:
```sh
    if the following integer is present in the bloom filter or not: 0
    if the following integer is present in the bloom filter or not: 1

```