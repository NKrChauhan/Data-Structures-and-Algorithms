# Data Structure and Algorithm

## Day 21

#### Mostly it has functions for String Problems

### The functions applied in day 21 :
```sh
    struct tstnode *insertTST(struct tstnode *head, char *w,int n, int l);
    
    int searchTSTReccursive(struct tstnode *head, char *w);
    
    int searchTSTNonReccursive(struct tstnode *head, char *w);
    
    void displayAllWordsTST(struct tstnode *head, vector<char> v);
    
    int maxLengthTST(struct tstnode *head);
    
    void reverseStringUsingXOR(char s[],int l);
    
    int matchPatternInText(char *s, char *p);
    
    void reverseStringTexualReverse(char s[],int start,int end);
    
    void reverseWordsInText(char *text, int l);

```

## The structure used for trie node :
```sh
    struct tstnode{
        char data;
        int isEnd;
        struct tstnode *prev; //alphabetically smaller 
        struct tstnode *eq;   //in the same string
        struct tstnode *next; //alphabetically larger
    };
```

## Output:
```sh
    Reversing the string star into using XOR method: rats
    Matching the pattern if it is in the form lets say 'ra*':1
    The reversing of the text is now tested on 'this is a ball' :ball a is this
    The element in the tst insertion check is: a
    The searching of the string in tst is: -1
    All the strings in the TST is given as : rats
    rat
    The max length string present is given as: 4
```