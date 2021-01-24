#include <iostream>
#include <bits/stdc++.h> //cpp stl functions like sort not work without it so be careful guys
#include <queue>
#include <math.h>       /* floor */
#include <vector> 
#include <map> 
#include <climits> 

using namespace std;

struct tstnode{
    char data;
    int isEnd;
    struct tstnode *prev; //alphabetically smaller 
    struct tstnode *eq;   //in the same string
    struct tstnode *next; //alphabetically larger
};

// Function decleration
struct tstnode *insertTST(struct tstnode *head, char *w,int n, int l);
int searchTSTReccursive(struct tstnode *head, char *w);
int searchTSTNonReccursive(struct tstnode *head, char *w);
void displayAllWordsTST(struct tstnode *head, vector<char> v);
int maxLengthTST(struct tstnode *head);
void reverseStringUsingXOR(char s[],int l);
int matchPatternInText(char *s, char *p);
void reverseStringTexualReverse(char s[],int start,int end);
void reverseWordsInText(char *text, int l);

// Function definition
// Tries has speed and BST has memory efficiency TST is combination of both.
struct tstnode *insertTST(struct tstnode *head, char w[],int n, int l){
    if(!head){
        head=(struct tstnode *)malloc(sizeof(struct tstnode));
        head->data=*w;
        head->isEnd=0;
        head->prev=NULL;
        head->eq=NULL;
        head->next=NULL;
    }
    if((*w)<(head->data)) head->prev=insertTST(head->prev,w,n,l+1);
    else if((*w)==head->data){
        if(l<n) head->eq=insertTST(head->eq,w+1,n,l+1);
        else head->isEnd=1;
    }
    else head->next=insertTST(head->next,w,n,l+1);
    return head;
}

int searchTSTReccursive(struct tstnode *head, char *w){
    if(!head) return -1;
    if(head->data==*w){
        if(head->isEnd==1 && !*(w+1)) return 1;
        else return searchTSTReccursive(head->eq,w+1);
    }else if(head-> data < *w) return searchTSTReccursive(head->next,w);
    else return searchTSTReccursive(head->prev,w);
}

int searchTSTNonReccursive(struct tstnode *head, char *w){
    struct tstnode *temp=head;
    while(temp){
        if(temp->data==*w){
            if(temp->isEnd==1 && !*(w+1)) return 1;
            w++; 
            temp=temp->eq;
        }
        else if(temp->data<*w) temp=temp->next;
        else temp=temp->prev;
    }
    return -1;
}

void displayAllWordsTST(struct tstnode *head, vector<char> v){
    if(!head) return;
    v.push_back(head->data);
    displayAllWordsTST(head->prev,v);
    displayAllWordsTST(head->eq,v);
    displayAllWordsTST(head->next,v);
    if(head->isEnd==1){ 
        for(auto x:v) cout<<x;
        cout<<endl;
    }
}

int maxLengthTST(struct tstnode *head){
    if(!head) return 0;
    int a=maxLengthTST(head->prev);
    int b=maxLengthTST(head->eq)+1;
    int c=maxLengthTST(head->next);
    return c>=max(a,b)?c:max(a,b);
}

//* we will be considering the suffix tree in later days to come.

void reverseStringUsingXOR(char s[],int l){
    int end=l-1,start=0;
    while(end>start){
        s[end]^=s[start]; // E=E^S
        s[start]^=s[end]; // S=S^E^S=E
        s[end]^=s[start]; // E=E^E^S=S
        end--;start++;
    }
}

// uses the wildcard chars like ? and * so the pattern length is not fixed sometimes , it doesn't work on terminal letters
int matchPatternInText(char *s, char *p){
    if(!*p) return 1;
    if(!*s) return *p=='*'?1:*p==0;
    if(*p=='?') return matchPatternInText(s+1,p+1);
    if(*p=='*'){
     if(!*s) return 1;
     else return matchPatternInText(s+1,p);
    }
    return matchPatternInText(s+1,p+1);
}

// for text reverse process
void reverseStringTexualReverse(char s[],int start,int end){
    while(end>start){
        s[end]^=s[start]; // E=E^S
        s[start]^=s[end]; // S=S^E^S=E
        s[end]^=s[start]; // E=E^E^S=S
        end--;start++;
    }
}
// this is a car -> car a is this
void reverseWordsInText(char *text, int l){
    reverseStringUsingXOR(text,l);
    int start=0,end=0;
    while(start<l && end<l){
        while(text[end]!=' ') end++;
        if(end>l) end=l;
        reverseStringTexualReverse(text,start,end-1);
        start=end+1;
        end=start;
    }    
}

int main(int argc, char const *argv[]){
    char s[]={'s','t','a','r'};
    cout<<"Reversing the string ";
    for(auto x:s)cout<<x;
    cout<<" into using XOR method: ";
    reverseStringUsingXOR(s,4);
    for(auto x:s)cout<<x;
    cout<<endl;
    cout<<"Matching the pattern if it is in the form lets say 'ra*':";
    char p[]={'r','a','*'};
    cout<<matchPatternInText(s,p)<<endl;
    cout<<"The reversing of the text is now tested on 'this is a ball' :";
    char text[]={'t','h','i','s',' ','i','s',' ','a',' ','b','a','l','l'};
    reverseWordsInText(text,14);
    for(auto x:text)cout<<x;
    cout<<endl;
    struct tstnode *head=NULL;
    char s1[]={'r','a','t','s'};
    char s2[]={'r','a','t'};
    head=insertTST(head,s1,3,0);
    cout<<"The element in the tst insertion check is: "<<head->eq->data<<endl;
    cout<<"The searching of the string in tst is: "<<searchTSTReccursive(head,s2)<<endl;
    head=insertTST(head,s2,2,0);
    vector<char> v;
    cout<<"All the strings in the TST is given as : ";
    displayAllWordsTST(head,v);
    int ma=maxLengthTST(head);
    cout<<"The max length string present is given as: "<<ma<<endl;
    return 0;
}
