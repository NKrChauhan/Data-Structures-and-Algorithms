#include <iostream>
#include <bits/stdc++.h> //cpp stl functions like sort not work without it so be careful guys
#include <queue>
#include <math.h>       /* floor */
#include <vector> 
#include <map> 
#include <climits> //to use the INT_MIN or other limits.

using namespace std;

// previously made function reused decleration
int binarySearchRecursive(int a[],int x, int s, int e);

// Function previous definition
int binarySearchRecursive(int a[],int x, int s, int e){
    if(e>=s){
        int mid=s+floor((e-s)/2);
        if(a[mid]==x) return mid;
        else if(a[mid]>x)  return binarySearchRecursive(a,x,s,mid-1);
        else  return binarySearchRecursive(a,x,mid+1,e);
    }
    return -1;
}

// Function decleration
void printRepetedElements_XOR(int a[], int n);
void elementsSumClosesetToZero(int a[], int n);
void threeElementSumSearch_useSorting(int a[], int n, int k);
void threeElementSumSearch_useHashTable(int a[], int n, int k);
int findPivot(int a[],int start,int end);
int searchingRotatedSortedArray(int a[], int n, int k);
int bitonicArrayMax(int a[],int s,int e);
int firstOccuranceSortedArray(int a[], int s, int e, int x);
int lastOccuranceSortedArray(int a[], int s, int e, int x);
int numberOfOccurance(int a[], int n, int k);

// Function definition

// FOR FINDING ELEMENT REPETITION OR DETECTING REPETITION:
// method 1:Brute force -- O(N^2)
// method 2:Sorting and travercing once -- O(N)
// method 3:Mapping or hash maps -- O(N)
// method 4:Summation of possible range n(n+1)/2 and subtract with the existing sum -- O(N)
// method 5:Using XOR (A^A=0 and A^A^A=A) if one repeted value to find xor all A[i] = X then xor the entire range 1 to n = Y  X^Y= Repeted element -- O(N)

void printRepetedElements_XOR(int a[], int n){
    // considering n is the reange and the size of array aswell
    int XOR=a[0];
    for(int i=1;i<n;i++)    XOR^=a[i];
    for(int i=1;i<=n-2;i++)   XOR^=i;
    int rightmost_set_bit_number=XOR&(~(XOR-1));
    int x=0,y=0;
    for(int j=1;j<=n-2;j++){
        if(j & rightmost_set_bit_number) x^=j;
        else y^=j;
    }
    for(int j=0;j<n;j++){
        if(a[j] & rightmost_set_bit_number) x^=a[j];
        else y^=a[j];
    }
    cout<<x<<" , "<<y<<endl;
}
// Alternate Mathematical method to find 2 repeted elements: get the sum of 1 to n by n(n+1)/2 and product as n! 2 equations we got now solve

// other than the Bruteforce method.
void elementsSumClosesetToZero(int a[], int n){
    int sum=INT_MAX;
    int l=0,r=n-1;
    sort(a,a+n);
    while(l<r){
        int temp=a[r]+a[l];
        if(temp<0){
            if(abs(temp)<sum) sum=abs(temp);
            l++;
        }else if(temp>0){
            if(abs(temp)<sum) sum=abs(temp);
            r--;
        }else break;
    }
    cout<<"|"<<sum<<"|"<<endl;
}

// fixing the first element i and taversing like above j from i+1 toward n and c form n-1 towaard 0
// Hence : O(n^2)+O(nlogn) = O(n^2)
void threeElementSumSearch_useSorting(int a[], int n, int k){
    sort(a,a+n);
    for(int i=0;i<n;i++){
        int j=i+1,c=n-1;
        while(j<c){
            int temp=a[i]+a[j]+a[c];
            if(temp==k){
                cout<<a[i]<<", "<<a[j]<<", "<<a[c]<<endl;
                return;
            }else if(temp>k) c--;
            else j++;
        }
    }
    cout<<"NOT FOUND!"<<endl;
}

void threeElementSumSearch_useHashTable(int a[], int n, int k){
    map<int,int> m;
    for(int i=0;i<n;i++){
        int temp=k-a[i];
        if(m.find(temp)->second==0) m.insert(pair<int,int>(temp,i+1));
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int temp=a[i]+a[j];
            if(m.find(temp)->second!=0 && m.find(temp)->second-1!=i && m.find(temp)->second-1!=j){
                cout<<a[i]<<", "<<a[j]<<", "<<a[m.find(temp)->second-1]<<endl;
                return;
            }
        }
    }
}

int findPivot(int a[],int start,int end){
    if(start == end) return start;
    else if (start+1==end) return a[start]>=a[end]?start:end;
    else{
        int mid = start+(end-start)/2;
        if(a[start]>=a[mid]) return findPivot(a,start,mid);
        else return findPivot(a,mid,end);
    }
}

// This operation will take not more than O(logn)
// rotation like: (6,7,8,9,10,1,2,3,4,5) and index of 3 in this is to be found.
int searchingRotatedSortedArray(int a[], int n, int k){
    // first we will find the pivot means where the rotation action occurs
    // function used is findPivot(int a[], start, end);
    int pivot=findPivot(a,0,n-1);
    if(a[pivot]==k) return pivot;
    else if(a[pivot]>=k) return binarySearchRecursive(a,k,pivot+1,n-1);
    else return binarySearchRecursive(a,k,0,pivot-1);
}

// for eg: 0,2,4,5,3,1 should return 5 *peak point of array*
int bitonicArrayMax(int a[],int s,int e){
    while(e>=s){
        if(e==s) return a[s];
        else if(e==1+s) return a[e]>a[s]?a[e]:a[s];
        else{
            int mid=s+(e-s)/2;
            if(a[mid]>a[mid-1] && a[mid]>a[mid+1]) return a[mid];
            else if(a[mid]>a[mid-1] && a[mid]<a[mid+1]) s=mid+1;
            else if(a[mid]<a[mid-1] && a[mid]>a[mid+1]) e=mid-1;
            else return INT_MIN;
        }
    }
    return INT_MIN;
}

// O(logn)
int firstOccuranceSortedArray(int a[], int s, int e, int x){
    if(s<=e){
        int mid=s+(e-s)/2;
        if(a[mid]==x){
            // using the base cases as condition if data == a[mid]
            if(a[s]==x) return s;
            if(a[mid-1]<x) return mid;
            return firstOccuranceSortedArray(a,s,mid-1,x);
        }
        else if(a[mid]>x) return firstOccuranceSortedArray(a,s,mid-1,x);
        else return firstOccuranceSortedArray(a,mid+1,e,x);
    }
    return -1;
}

// O(logn)
int lastOccuranceSortedArray(int a[], int s, int e, int x){
    if(s<=e){
        int mid=s+(e-s)/2;
        if(a[mid]==x){
            // using the base cases as condition if data == a[mid]
            if(a[e]==x) return e;
            if(a[mid+1]>x) return mid;
            return lastOccuranceSortedArray(a,mid+1,e,x);
        }
        else if(a[mid]>x) return lastOccuranceSortedArray(a,s,mid-1,x);
        else return lastOccuranceSortedArray(a,mid+1,e,x);
    }
    return -1;
}

// other than the good old brute force technique using binary search concept
// O(logn)
int numberOfOccurance(int a[], int n, int k){
    int r=lastOccuranceSortedArray(a,0,n-1,k);
    int l=firstOccuranceSortedArray(a,0,n-1,k);
    return r-l+1; 
}
// alternate method: binary search the element then traverse left + traverse right +1 
// it will take O(logn+S(size of re-occurance))

int main(int argc, char const *argv[]) {
    int x[]={1,2,3,3,4,4,5};
    cout<<"The repeted element present in an array using xor method: ";
    printRepetedElements_XOR(x,7);
    int a[]={-1,-2,3,-4,5,6,-7,8,-9};
    cout<<"The min sum close to zero is given as : ";    
    elementsSumClosesetToZero(a,9);
    int b[]={9,4,3,1,5,6,2,7,9};
    cout<<"Three element that makes the sum given using sorted array method are: ";
    threeElementSumSearch_useSorting(b,10,22);
    int c[]={9,8,3,0,6,6,2,7,9};
    cout<<"Three element that makes the sum given using hash table method are: ";
    threeElementSumSearch_useHashTable(c,10,15);
    int d[]={2,3,5,5,5,5,7,8,9};
    cout<<"The number of times the element occured in sorted array: "<<numberOfOccurance(d,9,5)<<endl;
    int e[]={8,9,10,11,12,1,2,3,4,5,6};
    cout<<"The element index in rotated array is given as: "<<searchingRotatedSortedArray(e,11,5)<<endl;
    int f[]={1,3,5,7,10,8,4,6,2,0};
    cout<<"The bitonic array maximum value is given as: ";
    cout<<bitonicArrayMax(f,0,9)<<endl;
    return 0;
}
