#include <iostream>
#include <bits/stdc++.h> //cpp stl functions like sort not work without it so be careful guys
#include <queue>
#include <math.h>       /* floor */
#include <vector> 
#include <map> 
#include <climits> //to use the INT_MIN or other limits.

using namespace std;

// previously made function reused decleration
void swaping(int *a,int *b);
int partition(int a[],int l, int r);
void print_array(int a[],int l,int r);

// Function previous definition
void swaping(int *a,int *b){
    int temp;
    temp=(*a);
    *a=(*b);
    *b=temp;
}

int partition(int a[],int l, int r){
    int p=r;
    int start=l;
    int end=r-1;
    while(start<end){
        while(a[start]<=a[p] && start<r) start++;
        while(a[end]>a[p] && end>l) end--;
        if(end>start)
            swaping(&a[start],&a[end]);
    }
    swaping(&a[p],&a[start]);
    return start;
}

// Function decleration
void findGreatestSmallest(int a[], int n);
void kSmallestElements(int a[], int n, int k);
int kthSmallestElement(int a[], int n, int k);
int findMedian2Array(int a[], int a_l, int a_h, int b[], int b_l, int b_h );

// Function definition

// for result showing
void print_array(int a[],int l,int r){
    for(int i=l;i<r;i++) cout<<a[i]<<", ";
    cout<<endl;
}

void findGreatestSmallest(int a[], int n){
    int maxim=INT_MIN, minim=INT_MAX;
    // this algorithm will take almost (3n/2 -2) comparisions
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            if(maxim<a[i]) maxim=a[i];
            if(minim>a[i+1]) minim=a[i+1];
        }else{
            if(maxim<a[i+1]) maxim=a[i+1];
            if(minim>a[i]) minim=a[i];
        }
    }
    cout<<minim<<", "<<maxim<<endl;
}

// if we want to find the k smallest number in an array
// method 1: search in array k times 
// method 2: sort the array and find the first k
// method 3: insert the elements in binary tree then k inorder traversal *similar to method 2 basically*
// method 4: make balanced tree of k node and rest n-k will be added one by one.
//           if element>(largest element in tree) return 
//           else if element<(largest element in tree) replce it with the element.
// method 5: partition technique *implemented below*

// also known as form of seletion
void kSmallestElements(int a[], int n, int k){
    int low=0,high=n-1;
    if(k<n){
        while(high>=low){
            int pivot = partition(a,low,high);
            if(k==pivot+1)print_array(a,0,k);
            if(k<pivot+1) high = pivot-1;
            else low = pivot+1;
        }
    }else cout<<"ERROR"<<endl;
}

// also a form of selection
int kthSmallestElement(int a[], int n, int k){
    int low=0,high=n-1;
    if(k<n){
        while(high>low){
            int pivot = partition(a,low,high);
            if(k==pivot+1) return a[pivot];
            else if(k<pivot+1) high = pivot-1;
            else low = pivot+1;
        }
    }
    return -1;
}

int findMedian2Array(int a[], int a_l, int a_h, int b[], int b_l, int b_h ){
    int a_mid=a_l+(a_h-a_l)/2;
    int b_mid=b_l+(b_h-b_l)/2;
    // the array are of same size n so the case
    if (a_h-a_l+b_h-b_l == 0) return (a[a_l] + b[b_l])/2; 
    if (a_h-a_l+b_h-b_l == 2) return (max(a[a_l], b[b_l]) + min(a[a_h], b[b_h])) / 2;
    if(a[a_mid]==b[b_mid]) return a[a_mid];
    else if(a[a_mid]<b[b_mid]) return findMedian2Array(a,a_mid,a_h,b,b_l,b_mid);
    else return findMedian2Array(a,a_l,a_mid,b,b_mid,b_h);
}

int main(int argc, char const *argv[]) {
    int a[]={4,6,2,6,1,7,8,9,0};
    cout<<"The Smallest and the greatest numbers in the array are: ";
    findGreatestSmallest(a,9);
    cout<<"The smallest k=5 elements in a given array are: ";
    kSmallestElements(a,9,5);
    cout<<"The kth smallest number also called as median problem is given for array is: ";
    cout<<kthSmallestElement(a,9,7)<<endl;
    int s1[]={1,12,15,26,38};
    int s2[]={2,13,17,30,45};
    cout<<"The median of the two arrays of same size is given as: ";
    cout<<findMedian2Array(s1,0,4,s2,0,4)<<endl;
    return 0;
}
