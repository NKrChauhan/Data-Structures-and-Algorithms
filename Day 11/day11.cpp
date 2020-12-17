#include <iostream>
#include <bits/stdc++.h> //cpp stl functions like sort not work without it so be careful guys
#include <queue>
#include <math.h>       /* floor */
#include <vector> 
#include <map> 

using namespace std;

// Function decleration
int linearSearch(int a[],int n, int x);
int orderedLinearSearch(int a[], int n, int x);
int binarySearchIterative(int a[], int n, int x);
int binarySearchRecursive(int a[],int x, int s, int e);
int interpolationSearch(int a[], int n, int x);
bool checkDuplicateBruteForce(int a[],int n);
bool checkDuplicateSorted(int a[],int n);
bool checkDuplicateHash(int a[], int n);
bool checkDuplicateNegate(int a[],int n);
int maxRepetitionBrute(int a[], int n);
int maxRepetitionRange(int a[], int n);
int firstRepetitionHash(int a[], int n);

// Function definition
int linearSearch(int a[], int n, int x){
    for(int i=0;i<n;i++)
        if(a[i]==x) return i;
    return -1;
}

int orderedLinearSearch(int a[], int n, int x){
    for(int i=0;i<n;i++){
        if(a[i]==x) return i;
        if(a[i]>x) break;
    }
    return -1;
}

int binarySearchIterative(int a[], int n, int x){
    int start=0,end=n-1;
    while(end>start){
        int mid=start+floor((end-start)/2);
        if(a[mid]==x) return mid;
        else if(a[mid]<x) start=mid+1;
        else end=mid-1;
    }
    return -1;
}

int binarySearchRecursive(int a[],int x, int s, int e){
    if(e>s){
        int mid=s+floor((e-s)/2);
        if(a[mid]==x) return mid;
        else if(a[mid]>x)  return binarySearchRecursive(a,x,s,mid-1);
        else  return binarySearchRecursive(a,x,mid+1,e);
    }
    return -1;
}

int interpolationSearch(int a[], int n, int x){
    int start=0,end=n-1;
    while(end>=start){
        int k=start+((end-start)*(x-a[start])/(a[end]-a[start]));
        if(a[k]==x) return k;
        else if(a[k]<x) start=k+1;
        else end=k-1;
    }
    return -1;
}

//hashing and string searching algorithem will be considered later days to come.

bool checkDuplicateBruteForce(int a[],int n){
    for(int i=0;i<n;i++)
        for(int j=0;j<i;j++)
            if(a[i]==a[j])
                return true;
    return false;
}

bool checkDuplicateSorted(int a[],int n){
    sort(a,a+n);
    for(int i=0;i<n-1;i++)
        if(a[i]==a[i+1])
            return true;
    return false;
}

bool checkDuplicateHash(int a[], int n){
    map<int,int> m;
    for(int i=0;i<n;i++){
        if((m.find(a[i])->second)==0) m[a[i]]=1;
        else return true;
    }
        return false;
}

bool checkDuplicateNegate(int a[],int n){
    for(int i=0;i<n;i++){
        if(a[abs(a[i])]<0) return true;
        else a[abs(a[i])]-=(2*a[abs(a[i])]);
    }
    return false;
}

int maxRepetitionBrute(int a[], int n){
    int max_counter=0,res=0;
    for(int i=0;i<n-1;i++){
        int counter=0;
        for(int j=i+1;j<n;j++){
            if(a[j]==a[i]) counter++;
        }
        if(counter>max_counter){
            max_counter=counter;
            res=i;
        }
    }
    return a[res];
}

// Alternative: proper way is sorting the array and swooping the array once and do the counter.
// Another Alternative: use hash map to make counter of every element.

int maxRepetitionRange(int a[], int n){
    int max=0;;
    for(int i=0;i<n;i++)
        a[a[i]%n]+=n;
    for(int i=0;i<n;i++)
        if(a[a[i]]%n>max) max=a[a[i]]%n;
    return max;
}

// first reocurring element eg:- 3,2,1,2,2,3 ans=>"3"
// Bruteforce is an option  and sorting won't work in this problem.
// Normal hashing will not work as it will result repetition occured first.

int firstRepetitionHash(int a[], int n){
    map<int,int> m;
    for(int i=0;i<n;i++){
        if((m.find(a[i])->second)<0) continue;
        if((m.find(a[i])->second)>0) m[a[i]]-=(2*m[a[i]]);
        else m[a[i]]=i;
    }
    map<int, int>::iterator itr;
    int first=-9999;
    for(itr=m.begin();itr!=m.end();itr++)
        if(itr->second<0 && itr->second>first) first=itr->second;
    return a[abs(first)];
}

int main(int argc, char const *argv[]){
    int a[]={1,5,6,7,8,9,2,0};
    cout<<"The linear search gives the output of: ";
    int res=linearSearch(a,8,6);
    cout<<res<<endl;
    
    cout<<"The ordered linear search gives the output of: ";
    res=orderedLinearSearch(a,8,6);
    cout<<res<<endl;
    int b[]={2,3,4,4,5,6,7};
    
    cout<<"The binary search iterative gives the output of: ";
    res=binarySearchIterative(b,7,6);
    cout<<res<<endl;
    
    cout<<"The binary search recurssive gives the output of: ";
    res=binarySearchRecursive(b,6,0,7);
    cout<<res<<endl;
    
    cout<<"The interpolation search gives the output of: ";
    res=interpolationSearch(b,7,6);
    cout<<res<<endl;
    
    cout<<"The check duplication bruteforce method gives the output of: ";
    res=checkDuplicateBruteForce(b,7);
    cout<<res<<endl;
    
    cout<<"The check duplication in sorted method gives the output of: ";
    res=checkDuplicateSorted(b,7);
    cout<<res<<endl;
    
    cout<<"The check duplication in hashmap method gives the output of: ";
    res=checkDuplicateHash(b,7);
    cout<<res<<endl;
    
    int c[]={6,2,8,4,9,5,9,9,8,7};
    cout<<"The check duplication negation method gives the output of: ";
    res=checkDuplicateNegate(c,10);
    cout<<res<<endl;
    
    cout<<"The max repetition bruteforce present in array gives the output of: ";
    res=maxRepetitionBrute(b,7);
    cout<<res<<endl;
    
    int d[]={6,2,8,4,9,5,9,9,8,7};
    cout<<"The max repetition range present in array gives the output of: ";
    res=maxRepetitionRange(d,10);
    cout<<res<<endl;
    
    int e[]={6,2,8,4,9,5,9,9,8,7};
    cout<<"The first repetition element present in array gives the output of: ";
    res=firstRepetitionHash(e,10);
    cout<<res<<endl;
    
    return 0;
}
