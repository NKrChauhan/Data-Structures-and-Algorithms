#include <iostream>
#include <queue>
#include <math.h>       /* floor */
#include <vector> 
#include <map> 

#define BUCKETS 10

using namespace std;

// Function decleration
void swaping(int *a,int *b);
void bubbleSort_improved(int a[],int n);
void selectionSort(int a[],int n);
void insertionSort(int a[],int n);
void shellSort(int a[] ,int n);
void merge(int l[],int l_size, int r[], int r_size, int a[]);
void mergeSort(int a[] ,int n);
int partition(int a[],int l, int r);
void quickSort(int a[], int l, int r);
void countingSort(int a[] ,int n, int b[], int k);
void bucketSort(int a[] ,int n);
// Note: "HeapSort" is already been implemented in the heaps and priority queues.
void printArray(int a[],int n);

// Function definition
void swaping(int *a,int *b){
    int temp;
    temp=(*a);
    *a=(*b);
    *b=temp;
}

void bubbleSort_improved(int a[],int n){
    for(int i=0;i<n;i++){
        int swaps=0;
        for(int j=0;j<n-1;j++)
            if(a[j]>a[j+1]){
                swaping(&a[j],&a[j+1]);
                swaps++;
            }
        if(swaps==0) break;
    }
}

// in-place sorting technique
void selectionSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int min_i=i;
        for(int j=i+1;j<n;j++){
            if(a[min_i]>a[j]) 
                min_i=j;
        }
        swaping(&a[i],&a[min_i]);
    }
}

void insertionSort(int a[], int n){
    for (int i=0;i<n;i++)
        for(int j=0;j<i;j++)
            if(a[j]>a[i]) 
                swaping(&a[i],&a[j]);
}

// generalized way of doing insertion sorting where gap/=2 after every pass
void shellSort(int a[] ,int n){
    int gap=floor(n/2);
    while(gap>0){
        for(int i=0;i<(n-gap);i+=gap)
            for(int j=i;j<n;j+=gap)
                if(a[i]>a[j])
                    swaping(&a[i],&a[j]);
        gap/=2;
    }
}

//Note : do not use sizeof in functions other than main as it will do sizeof(int*)/sizeof(int) which gives 1/2 based on 32bit/64bit machine.
void merge(int l[],int l_size, int r[], int r_size, int a[]){
    int l_i=0,r_i=0;
    int i=0;
    while(l_i<l_size&&r_i<r_size){
        if(l[l_i]<r[r_i]) a[i++]=l[l_i++];
        else a[i++]=r[r_i++];
    }
    while(l_i<l_size)
        a[i++]=l[l_i++];
    while(r_i<r_size)
        a[i++]=r[r_i++];
}

void mergeSort(int a[] ,int n){
    if(n==1)return;
    int mid=floor(n/2);
    int l[mid],r[n-mid];
    for(int i=0;i<mid;i++)
        l[i]=a[i];
    for(int i=mid;i<n;i++)
        r[i-mid]=a[i];
    mergeSort(l,mid);
    mergeSort(r,n-mid);
    merge(l,mid,r,n-mid,a);
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

void quickSort(int a[], int l, int r){
    if(r>l){
        int pivot=partition(a,l,r);
        // pivot returned by partition will be at the sorted place.
        quickSort(a,l,pivot-1);
        quickSort(a,pivot+1,r);
    }
}
// to improve complexity random pivot is decided using swap of pivot at the end to any index so it will work better for worst case scenario also.

void countingSort(int a[] ,int n, int b[], int k){
    int c[k];
    // intitialize
    for(int i=0;i<k;i++) c[i]=0;
    // cout number of elements in the array of a[i]
    for(int i=0;i<n;i++) c[a[i]]++;
    // count number of elements in array <= i
    for(int i=1;i<k;i++) c[i]=c[i]+c[i-1];
    // sorting each index from right to left c storing the index position of sorted array elements
    for(int i=n-1;i>=0;i--){
        // index of a[i] has sorted index stored in "c[a[i]]-1"  "-1" coz there it stores the number of element till i index 
        b[c[a[i]]-1]=a[i];
        c[a[i]]--;
    }
}

void bucketSort(int a[] ,int n){
    int bin[BUCKETS];
    for(int i=0;i<BUCKETS;i++) bin[i]=0;
    for(int i=0;i<n;i++) bin[a[i]]++;
    for(int i=0,j=0;j<BUCKETS;j++)
        for(int k=bin[j];k>0;--k)
            a[i++]=j;
}

void printArray(int a[],int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<", ";
    cout<<endl;
}

int main(int argc, char const *argv[]){
    int a[]={6,5,8,7,3,1,0,2,4};
    cout<<"Sample array given as input : ";
    printArray(a,9);
    bubbleSort_improved(a,9);
    cout<<"Bubble Sort gives the output as: ";
    printArray(a,9);
    
    int b[]={6,5,8,7,3,1,0,2,4};
    selectionSort(b,9);
    cout<<"Selection Sort gives the output as: ";
    printArray(b,9);
    
    int c[]={6,5,8,7,3,1,0,2,4};
    insertionSort(c,9);
    cout<<"Insertion Sort gives the output as: ";
    printArray(c,9);
    
    int d[]={6,5,8,7,3,1,0,2,4};
    shellSort(d,9);
    cout<<"Shell Sort gives the output as: ";
    printArray(d,9);
    
    int e[]={6,5,8,7,3,1,0,2,4};
    int ans[9];
    countingSort(e,9,ans,10);
    cout<<"Count Sort gives the output as: ";
    printArray(ans,9);
    
    int f[]={6,5,8,7,3,1,0,2,4};
    bucketSort(f,9);
    cout<<"Bucket Sort gives the output as: ";
    printArray(f,9);
    
    int g[]={6,5,8,7,3,1,0,2,4};
    mergeSort(g,9);
    cout<<"Merge Sort gives the output as: ";
    printArray(g,9);
    
    int h[]={6,5,8,7,3,1,0,2,4};
    quickSort(h,0,8);
    cout<<"Quick Sort gives the output as: ";
    printArray(h,9);
    
    return 0;
}
