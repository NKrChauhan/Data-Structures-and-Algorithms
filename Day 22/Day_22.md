# Data Structure and Algorithm

## Day 22

#### Mostly it has functions for String Problems

### The functions applied in day 22 :
```sh

    void permutationString(vector<char> s, int n);

    void printAllCombinationsString(char s[],int l);

    void combinationString(char s[], int count[],vector<char> res, int n, int l);

    int reccursivelyRemoveRepetition(char s[], int l);

    void findMinimumWindow(char s[], char c[], int l, int c_l);

    int findPatternAt(int x, int y, char a[][5], char p[],int **v,int mat_size[],int l, int depth);

    int findPatternNeighbour(char a[][5], char p[], int p_l , int a_size[]);

    void printIner(vector<char> s1,vector<char> s2, vector<char> res);

    void printInterLeaving(char s1[], char s2[], int s1_l, int s2_l);

```

## Output:
```sh
    The permutation patterns of the string 'abe' are given as: abe, aeb, bae, bea, eab, eba, 
    The combination patterns of the string 'aabc' are given as: , a, aa, aab, aabc, aac, ab, abc, ac, b, bc, c, 
    The continuously removing the pair of similar chars occuring consecutively gives: ad
    Find min window in the array abbacbaa of aab: Start and End indices of Window that is minimum is: 5, 7
    The inter-leaving of the two strings 'ab' and 'cd' will give the solution as: abcd, acbd, acdb, cabd, cadb, cdab, 
    The pattern present in the 2D matrix or not is given as: 1
```