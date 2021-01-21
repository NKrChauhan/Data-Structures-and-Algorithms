# Data Structure and Algorithm

## Day 20

#### Mostly it has functions for String Matching Algorithms

### The functions applied in day 20 :
```sh
    int bruteForceStringMatching(char a[],int n,char b[], int m);
    
    int rabinKarpStringMatching(char a[],int n,char sub[], int m);
    
    void fill_longest_prefix_also_suffix_table(int *table, char *sub, int s);
    
    int kmpStringMatching(char a[],int n,char sub[], int m);
    
    int boyerMooreStringMatching(char a[], int n, char sub[], int m);
    
    struct trienode *findTrieNode(struct trienode* head,char c);
    
    void insertionTrie(struct trienode *head, char *w);
    
    int searchingTrie(struct trienode *head, char *w);
```

## The structure used for trie node :
```sh
    struct trienode{
        char data;
        int isEnd;
        struct trinode *ch[26];
    };
```

## Output:
```sh
    The Text and pattern are as follows:
    Text: g, c, t, t, c, t, g, c, t, a, c, t, t, t, 
    Pattern: g, c, t, a, c, t, 
    The bruteforce method will give the result as: 6
    The rabin-karp method will give the result as: 6
    The kmp method will give the result as: 6
    The boyer-moore method will give the result as: 6
    *Note: The Trie Data Structure is incomplete for now*
```