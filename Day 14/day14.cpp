#include <iostream>
#include <bits/stdc++.h> //cpp stl functions like sort not work without it so be careful guys
#include <queue>
#include <math.h>       /* floor */
#include <vector> 
#include <map> 
#include <climits> //to use the INT_MIN or other limits.

using namespace std;

// Function decleration
int findElemant_OccouringIn2NArray_Ntimes(int a[], int n);
int findIn2DAsscendingArray(int a[][3], int n, int k);
void dutchNationalFlagProblem_01(int a[],int n);
void dutchNationalFlagProblem_012(int a[],int n);
void shuffleArrayIterative(int a[],int n);
void shuffleArrayReccursive(int a[],int n, int s, int e);
int maxIndexDif(int a[], int n);

// Function definition

// element majority check present more than n/2 times 
// method 1:brute force with two loops
// method 2:using bst insertion and keep track of count using count as the extra node data  
// method 3:sorting and traversing 
// method 4:median method as the element has to be a median, than calculate the number of times median occur >n/2 true
// *method 4 is the most appropriate method which use linear selection algo to find median in O(n) will be implemented in the coming days. 

// also known as the majority element problem 
int findElemant_OccouringIn2NArray_Ntimes(int a[], int n){
// there can be only two possibilities 
// 1. pattern (a x c x d x ...)
// 2. pattern (a c d x x x ...) or (x x a b d ...)
// they will be together or far apart by 2 at most
// all the other elements are unique
    for(int i=0;i<n-2;i++)
        if(a[i]==a[i+2]) return a[i];
    for(int i=0;i<n-1;i++)
        if(a[i]==a[i+1]) return a[i];
    return -1;
}

int findIn2DAsscendingArray(int a[][3], int n, int k){
    int i=0,j=n-1;
    while(i<n || j>=0){
        if(a[i][j]==k) return 1;
        else if(a[i][j]<k) i++;
        else j--;
    }
    return -1;
}

// more like a modified quick sort pivot technique in this
void dutchNationalFlagProblem_01(int a[],int n){
    int l=0,r=n-1;
    while(r>l){
        while(a[l]==0) l++;
        while(a[r]==1) r--;
        if(l<r){
            int temp=a[r];
            a[r]=a[l];
            a[l]=temp;
            // or you can simply do reinitialize to 0/1
        }
    }
}

void dutchNationalFlagProblem_012(int a[],int n){
    int low=0,mid=0,high=n-1;
    //so the concept is that focus on mid and as proceeds swap mid with low and high values
    while(mid<=high){
        if(a[mid]==0){
            int temp=a[mid];
            a[mid]=a[low];
            a[low]=temp;
            low++;
        }else if(a[mid]==1){
            mid++;
        }else{
            int temp=a[mid];
            a[mid]=a[high];
            a[high]=temp;
            high--;
        }
    } 
}

// condition: space complexity to be O(1) and shuffle eg: (1,3,5,7,9,2,4,6,8,10) => (1,2,3,4,5,6,7,8,9,10)
void shuffleArrayIterative(int a[],int n){
    // array is of 2n type
    // the simple process of swapping as we move from right to left one at a time in iteration
    // time complexity is O(n^2)
    int k=n/2;
    for(int i=0,q=1;i<n;i++,k++,q++){
        for(int j=k;j>i+q;j--){
            int temp=a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
        }
    }
}

//  it will only work for the n=2^i. for eg 2,4,8,16,32 sizes
void shuffleArrayReccursive(int a[],int n, int s, int e){
    if(n==1) return;
    int s_left=s+n/4;
    int s_right=s_left+n/4;
    int mid=s_right;
    while(s_left<n/2){
        int temp=a[s_left];
        a[s_left]=a[s_right];
        a[s_right]=temp;
        s_right++;s_left++;
    }
    shuffleArrayReccursive(a,n/2,s,mid-1);
    shuffleArrayReccursive(a,n/2,mid,e);
}

// max index in O(n) time means A[i]<A[j] for j>i and max = j-i 
int maxIndexDif(int a[], int n){
    // 2 array needed 1st contains min from left to right
    // 2 array needed 2nd contains max from right to left
    int mins[n],maxs[n];
    mins[0]=a[0];
    maxs[n-1]=a[n-1];
    for(int i=1,j=n-2;i<n;i++,j--){
        mins[i]=min(a[i],mins[i-1]);
        maxs[j]=max(a[j],a[j+1]);
    }
    int i=0,j=0,maxdif=-1;
    while(j<n||i<n){
        if(mins[i]<maxs[j]) maxdif=max(maxdif,(j++)-i);
        else i++;
    }
    return maxdif;
}

void print_array(int a[],int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<", ";
    cout<<endl;
}

int main(int argc, char const *argv[]){
//  the 2D array was given col size as 100 in function but changes can be done.
    int a[]={1,0,1,0,1,0,1,0,1,0};
    cout<<"The array result before the dutch national flag algo: ";
    print_array(a,10);
    cout<<"The array result after  the dutch national flag algo: ";
    dutchNationalFlagProblem_01(a,10);
    print_array(a,10);
    int b[]={1,0,2,0,1,0,1,2,0,2,0};
    cout<<"The array result before the dutch national flag algo: ";
    print_array(b,11);
    dutchNationalFlagProblem_012(b,11);
    cout<<"The array result after  the dutch national flag algo: ";
    print_array(b,11);
    cout<<"The majority element in the array: ";
    int c[]={5,1,5,2,5,5,3,4};
    cout<<findElemant_OccouringIn2NArray_Ntimes(c,8)<<endl;
    int e[]={1,3,5,7,2,4,6,8};
    cout<<"The array result before the shuffle iterative algo: ";
    print_array(e,8);
    cout<<"The array result after  the shuffle iterative algo: ";
    shuffleArrayIterative(e,8);
    print_array(e,8);
    int f[]={1,3,5,7,2,4,6,8};
    cout<<"The array result before the shuffle reccursive algo: ";
    print_array(f,8);
    cout<<"The array result after  the shuffle reccursive algo: ";
    shuffleArrayReccursive(f,8,0,7);
    print_array(f,8);
    int g[]={1,3,5,7,2,4,6,8};
    cout<<"The array on which max dif index algo is applied: ";
    print_array(g,8);
    cout<<"The array result after  the algo: ";
    cout<<maxIndexDif(g,8)<<endl;    
    int d[][3]={{2,3,4},{5,6,7},{8,9,10}};
    cout<<"Finding element in the 2D asscending array: ";
    cout<<findIn2DAsscendingArray(d,3,11);
    return 0;
}
