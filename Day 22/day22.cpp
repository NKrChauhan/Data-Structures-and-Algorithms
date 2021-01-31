#include <iostream>
#include <bits/stdc++.h> //cpp stl functions like sort not work without it so be careful guys
#include <queue>
#include <math.h>       /* floor */
#include <vector> 
#include <map> 
#include <climits> 

using namespace std;

// Function decleration
void permutationString(vector<char> s, int n);
void printAllCombinationsString(char s[],int l);
void combinationString(char s[], int count[],vector<char> res, int n, int l);
int reccursivelyRemoveRepetition(char s[], int l);
void findMinimumWindow(char s[], char c[], int l, int c_l);
int findPatternAt(int x, int y, char a[][5], char p[],int **v,int mat_size[],int l, int depth);
int findPatternNeighbour(char a[][5], char p[], int p_l , int a_size[]);
void printIner(vector<char> s1,vector<char> s2, vector<char> res);
void printInterLeaving(char s1[], char s2[], int s1_l, int s2_l);

// Function definition
// basic solution as swap the value fixing the values till that lower swap index and move farward and so on.
void permutationString(vector<char> s, int n){
    int l=s.size();
    if(n==l-1){
        for(int i=0;i<l;i++) cout<<s[i];
        cout<<", ";
        return;
    }
    for(int i=n;i<l;i++){
        char temp=s[i];
        s[i]=s[n];
        s[n]=temp;
        permutationString(s,n+1);
    }
}

// the space is not optimized as i used alot just for nothing
void printAllCombinationsString(char s[],int l){
    vector<char> r;
    int *ch=(int *)calloc(126,sizeof(int)); //all char range
    for(int i=0;i<l;i++) ch[(int)s[i]]++;
    int count[l];
    l=0;
    for(int i=0;i<126;i++){
        if(ch[i]>0){
            s[l]=(char)i;
            count[l++]=ch[i];
        }
    }
    combinationString(s,count,r,0,l);
}

// better explaination : https://www.youtube.com/watch?v=xTNFs5KRV_g
void combinationString(char s[], int count[],vector<char> res, int n, int l){
    if(n==l) return;
    for(auto x:res) cout<<x;
    cout<<", ";
    for(int i=n;i<l;i++){
        count[i]--;
        if(count[i]>=0){
            res.push_back(s[i]); 
            combinationString(s,count,res,i,l);
            res.pop_back();
        }
        count[i]++;
    }
}

// return the length that is left after the operation is being performed.
int reccursivelyRemoveRepetition(char s[], int l){
    // cancel pair method
    for(int i=0;i<l-1;i++){
        int j=i+1,p=i;
        while(s[p]==s[j] && j<l-1){
            int temp=s[p];
            s[p]=s[j+1];
            s[j+1]=temp;
            p++;j++;
        }
        if(s[p]==s[j]){
            i=-1;
            l-=2;
        }
    }
    return l;
}

// input string is : ABBCBBA and char we want is : BBA
// movement will be [ABBCB]BA then amother one will be ABBC[BBA](minimum window) O(n) 
void findMinimumWindow(char s[], char c[], int l, int c_l){
    int start=0,end=0,f_len=0;
    int *needChars=(int *)calloc(256,sizeof(int));
    int *presentChars=(int *)calloc(256,sizeof(int));
    for(int i=0;i<c_l;i++) needChars[(int)c[i]]++;
    int win_s=0,win_size=INT_MAX;
    for(int win_e=0;win_e<l;win_e++){
        if(!needChars[(int)s[win_e]]) continue;
        presentChars[(int)s[win_e]]++;
        // track how many chars found so you can find window.
        if(needChars[(int)s[win_e]]>=presentChars[(int)s[win_e]]) f_len++; 
        // if once the length is acquired the window that is made everytime contains all the char
        if(f_len==c_l){
            // remove the extra chars not required or those are extra.
            while(needChars[s[win_s]]==0 || needChars[s[win_s]]<presentChars[s[win_s]]){
                if(needChars[s[win_s]]<presentChars[s[win_s]]) presentChars[s[win_s]]--;
                win_s++;
            } 
            if(win_size>win_e-win_s+1){
                win_size=win_e-win_s+1;
                start=win_s;
                end=win_e;
            }
        }
    }
    cout<<"Start and End indices of Window that is minimum is: "<<start<<", "<<end<<endl;
}

// findPatternNeighbour driver function
int findPatternAt(int x, int y, char a[][5], char p[],int **v,int mat_size[],int l, int depth){
    if(x<0 || y<0 || y>=mat_size[1] ||x>=mat_size[0]) return 0;
    if(v[x][y]==1) return 0;
    if(a[x][y]==p[depth]){
        v[x][y]=1;
        depth++;
        if(depth==l) return 1;
        // check 8 neighbours and the finding the result.
        if( findPatternAt(x-1,y-1,a,p,v,mat_size,l,depth)||
            findPatternAt(x-1,y,a,p,v,mat_size,l,depth)  ||
            findPatternAt(x-1,y+1,a,p,v,mat_size,l,depth)  ||
            findPatternAt(x+1,y-1,a,p,v,mat_size,l,depth)  ||
            findPatternAt(x+1,y,a,p,v,mat_size,l,depth)  ||
            findPatternAt(x+1,y+1,a,p,v,mat_size,l,depth)||
            findPatternAt(x,y+1,a,p,v,mat_size,l,depth)  ||
            findPatternAt(x,y-1,a,p,v,mat_size,l,depth)   ) return 1;
        else v[x][y]=0;
    }
    return 0;
}

// finding pattern in the 2D matrix and such that next char must be in neighbouring 8 cells else false
int findPatternNeighbour(char a[][5], char p[], int p_l , int a_size[]){
    if(a_size[1]>50) return -1;
    int **visit=(int **)calloc(a_size[0],sizeof(int *));
    for(int i=0;i<a_size[0];i++)
        visit[i]=(int *)calloc(a_size[1],sizeof(int));
    for(int i=0;i<a_size[0];i++)
        for(int j=0;j<a_size[1];j++)
            if(findPatternAt(i,j,a,p,visit,a_size,p_l,0)==1) return 1;
    return 0;
}

// printInterLeaving driver function;
void printIner(vector<char> s1,vector<char> s2, vector<char> res){
    if(s1.empty() && s2.empty()){
        if(!res.empty()){
            for(auto x:res) cout<<x;
            cout<<", ";
        }else return;
    }
    if(!s1.empty()){
        char x=s1.back();
        res.push_back(x);
        s1.pop_back();
        printIner(s1,s2,res);
        res.pop_back();
        s1.push_back(x);
    }
    if(!s2.empty()){
        char x=s2.back();
        res.push_back(x);
        s2.pop_back();
        printIner(s1,s2,res);
        res.pop_back();
        s2.push_back(x);
    }
}

// the string S1=AB and S2=CD gives : ABCD,ACBD, ACDB, CABD, CDAB & CADB
void printInterLeaving(char s1[], char s2[], int s1_l, int s2_l){
    vector<char> s1_v,s2_v,res_v;
    for(int i=s1_l-1;i>=0;i--) s1_v.push_back(s1[i]);
    for(int i=s2_l-1;i>=0;i--) s2_v.push_back(s2[i]);
    printIner(s1_v,s2_v,res_v);
    cout<<endl;
}

int main(int argc, char const *argv[]){
    vector<char> st;
    st.push_back('a');
    st.push_back('b');
    st.push_back('e');
    cout<<"The permutation patterns of the string 'abe' are given as: ";
    permutationString(st,0);
    cout<<endl;
    char s[]={'a','a','b','c'};
    cout<<"The combination patterns of the string 'aabc' are given as: ";
    printAllCombinationsString(s,4);
    cout<<endl;
    char s2[]={'a','b','c','c','b','d'};
    int l=reccursivelyRemoveRepetition(s2,6);
    cout<<"The continuously removing the pair of similar chars occuring consecutively gives: ";
    for(int i=0;i<l;i++) cout<<s2[i];
    cout<<endl;
    char s3[]={'a','b','b','a','c','b','a','a'};
    char ch[]={'a','a','b'};
    cout<<"Find min window in the array abbacbaa of aab: "; 
    findMinimumWindow(s3,ch,8,3);
    char l1[]={'a','b'};
    char l2[]={'c','d'};
    cout<<"The inter-leaving of the two strings 'ab' and 'cd' will give the solution as: ";
    printInterLeaving(l1,l2,2,2);
    char matrix[5][5]={{'a','c','p','r','c'},{'x','s','o','p','c'},{'v','o','v','n','i'},{'w','g','f','m','n'},{'q','a','t','i','t'}};
    char p[]={'m','i','c','r','o','s','o','f','t'};
    int size_m[]={5,5};
    cout<<"The pattern present in the 2D matrix or not is given as: "<<findPatternNeighbour(matrix,p,9,size_m)<<endl;
    return 0;
}
