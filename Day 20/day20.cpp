#include <iostream>
#include <bits/stdc++.h> //cpp stl functions like sort not work without it so be careful guys
#include <queue>
#include <math.h>       /* floor */
#include <vector> 
#include <map> 
#include <climits> 

using namespace std;

// *String matching algorithms
// Brute-force 
// Rabin-karp
// With finite automata *as have not studied automata so lets skip this one , kuch important hai nhi vaise.
// KMP
// Boyer-moore
// suffix trees

//* IMPLEMETATION OF TIRES.

struct trienode{
    char data;
    int isEnd;
    struct trienode *ch[26];
};

// Function decleration
int bruteForceStringMatching(char a[],int n,char b[], int m);
int rabinKarpStringMatching(char a[],int n,char sub[], int m);
void fill_longest_prefix_also_suffix_table(int *table, char *sub, int s);
int kmpStringMatching(char a[],int n,char sub[], int m);
int boyerMooreStringMatching(char a[], int n, char sub[], int m);
struct trienode *findTrieNode(struct trienode* head,char c);
struct trienode *insertionTrie(struct trienode *head, char *w);
int searchingTrie(struct trienode *head, char *w);

// Function definition
// sub-string matching taking char array as string.
int bruteForceStringMatching(char a[],int n,char sub[], int m){
    for(int i=0;i<n-m;i++){
        int res=0;
        while(res<m && a[res+i]==sub[res]) res++;
        if(res==m) return i;
    }
    return -1;
}

// easiest algorithm for string matching O(mn)
int rabinKarpStringMatching(char a[],int n,char sub[], int m){
// hashing used as a1C+a2C^2+a3C^3+....
    int x=0,y=0;
    // making resultant hash value that we want to find
    for(int i=0;i<m;i++){ 
        x+=(int)sub[i]*(int)pow(10.0,(double)i);
        y+=(int)a[i]*(int)pow(10.0,(double)i);
    }
    // searching the hash in the following string/char array
    for(int i=0;i<n-m;i++){
        if(x==y) return i;
        // updating hash if the match not found
        y-=(int)a[i];
        y/=10;
        y+=(int)a[m+i]*(int)pow(10.0,(double)(m-1));
    }
    return -1;
}

void fill_longest_prefix_also_suffix_table(int *table, char *sub, int s){
    int i=1,j=0;
    while(i<s){
        if(sub[i]==sub[j]){
            table[i++]=++j;     
        }else{
            if(j!=0){
                j=table[j-1];
            }else{
                table[i++]=0;
            }
        }
    }
}

// knuth morris pratt 
int kmpStringMatching(char a[],int n,char sub[], int m){
    int *longest_prefix_also_suffix_table = (int *)calloc(m,sizeof(int));
    // table will hold the value of max length prefix 
    // eg: ONIONS in ONIONIONS when "onion"ions matched then s does not then the table will hold the value to max matched part 
    //* here we will conpute the longest_prefix_also_suffix_table
    fill_longest_prefix_also_suffix_table(longest_prefix_also_suffix_table,sub,m);
    int j=0,i=0; //this will keep track string we want to find
    while(i<n){
        if(a[i]==sub[j]){
            j++;
            i++;
        }else{
            //we need position unchanged
            if(j!=0) j=longest_prefix_also_suffix_table[j-1];
            else i++;
        }
        if(j==m) return i-j;
    }
    return -1;
}

// nice explaination in the : https://www.youtube.com/watch?v=4Xyhb72LCX4
int boyerMooreStringMatching(char a[], int n, char sub[], int m){
    int j=m-1,i=0;
    while(i<n-m){
        if (a[i+j]==sub[j]){
            j--;
        }else{
            int x=j;
            while(a[i+j]!=sub[x] && x>=0) x--;
            i+=(j-x);
            j=m-1;
        }
        if(j==-1) return i;
    }
    return -1;
}

struct trienode *findTrieNode(struct trienode* head,char c){
    if(head) 
        for(int i=0;i<26;i++) 
            if(head->ch[i]->data==c) 
                return head->ch[i];
    return NULL;
}

struct trienode *insertionTrie(struct trienode *head, char *w){
    if(!*w) return NULL;
    if(!head){
        struct trienode *temp=(struct trienode *)malloc(sizeof(struct trienode));
        temp->data = *w;
        for(int i=0;i<26;i++) 
            temp->ch[i]=NULL;
        if(!*(w+1)) head->isEnd=1;
        else insertionTrie(head->ch[*w],w+1);
        return temp;     
    }
    return insertionTrie(head->ch[*w],w+1);
}

int searchingTrie(struct trienode *head, char *w){
    // check way 
    // check if the root null if not then check if word left is null if true then check if its string end then true else false;
    if(!head) return -1;
    if(!*w){
        if(head->isEnd==1) return 1;
        else return -1;
    }
    // now check if the char is desirable 
    if(head->data==*w) return searchingTrie(head->ch[*w],w+1);
    else return -1;
}

int main(int argc, char const *argv[]) {
    char a[]={'g','c','t','t','c','t','g','c','t','a','c','t','t','t'};
    char pat[]={'g','c','t','a','c','t'};
    cout<<"The Text and pattern are as follows:"<<endl;
    cout<<"Text: ";
    for(auto x : a) cout<<x<<", ";
    cout<<endl;
    cout<<"Pattern: ";
    for(auto x : pat) cout<<x<<", ";
    cout<<endl;
    cout<<"The bruteforce method will give the result as: "<<bruteForceStringMatching(a,14,pat,6)<<endl;
    cout<<"The rabin-karp method will give the result as: "<<rabinKarpStringMatching(a,14,pat,6)<<endl;
    cout<<"The kmp method will give the result as: "<<kmpStringMatching(a,14,pat,6)<<endl;
    cout<<"The boyer-moore method will give the result as: "<<boyerMooreStringMatching(a,14,pat,6)<<endl;
    // struct trienode *head;
    // head=insertionTrie(head,a);
    // cout<<head->data<<endl;
    return 0;
}
