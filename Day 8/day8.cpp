#include <iostream>
#include <queue>
#include <vector> 
#include <map> 

using namespace std;

// structure 
// for implementation of heap in array form
struct Heap{
    int *a;
    int hSize;
    int count; //number of element in a heap
    int hType; //min=0 or max=1
};

// Function decleration
struct Heap *createHeapArray(int s,int type);
int getParent(struct Heap *h, int index);
int getRChild(struct Heap *h, int index);
int getLChild(struct Heap *h, int index);
int getMaximum(struct Heap *h); //for max-heap
void percolateDown(struct Heap *h, int i);
int deleteMax(struct Heap * h);
void insertHeap(struct Heap *h, int data);
void resizeHeap(struct Heap *h);
struct Heap* destroyHeap(struct Heap *h);
void buildHeap(struct Heap *h, int b[], int n);
void heapSort(int a[], int n);
// Day 9
int kthMax(struct Heap *h,int k);
int getKthMax(struct Heap *h,int k);

// Function definition
struct Heap *createHeapArray(int s,int type){
    struct Heap *temp=(struct Heap *)malloc(sizeof(struct Heap));
    if(!temp){
        cout<<"The size not available"<<endl;
        return NULL;
    }    
    temp->hSize=s;
    temp->hType=type;
    temp->count=0;
    temp->a=(int*)malloc(sizeof(int)*s);
    if(!temp->a){
        cout<<"Memmory aint enough"<<endl;
        return NULL;
    }
    return temp;
}

int getParent(struct Heap *h,int index){
    if(index<=0 || index>=h->count) return -1;
    return (index-1)/2;
}

int getRChild(struct Heap *h, int index){
    int rc=index*2+2;
    if(rc<=0 || rc>=h->count) return -1;
    return rc;
}

int getLChild(struct Heap *h, int index){
    int lc=index*2+1;
    if(lc<=0 || lc>=h->count) return -1;
    return lc;
}

int getMaximum(struct Heap *h){
    if(h->hType==1 && h->count>0) return h->a[0];
    return -1;
}

// heapify is turning heap into heap again after insertion
// heapify from bottom to top is PERCOLATE-UP.
// heapify from top to bottom is PERCOLATE-DOWN.

void percolateDown(struct Heap *h, int i){
    int l,r,maxim,res_i;
    if(i==-1) return;
    r=getRChild(h,i);
    l=getLChild(h,i);
    if(r!=-1 && h->a[r]>h->a[l]) res_i=r;
    else res_i=-1;
    if(l!=-1 && h->a[r]<h->a[l]) res_i=l;
    if(res_i!=-1){
        // swaping
        h->a[i]+=h->a[res_i];
        h->a[res_i]=h->a[i]-h->a[res_i];
        h->a[i]-=h->a[res_i];
    }
    percolateDown(h,res_i);
}

int deleteMax(struct Heap * h){
    if(h->count==0) return -1;
    int data=h->a[0];
    // easy is to insert last element again and then percolate down
    h->a[0]=h->a[h->count-1];
    h->count-=1;
    percolateDown(h,0);
    return data;
}

void insertHeap(struct Heap *h, int data){
    if(h->hSize-h->count==0) resizeHeap(h);
    h->a[h->count++]=data;
    int i=h->count-1;
    while(i>=0){
        int x=getParent(h,i);
        if(h->a[x]>h->a[i] || x==-1) break;
        //swaping
        h->a[x]+=h->a[i];
        h->a[i]=h->a[x]-h->a[i];
        h->a[x]-=h->a[i];
        i=x;
    }
}

void resizeHeap(struct Heap *h){
    int *b=(int *)malloc(sizeof(int)*h->hSize*2);
    if(!b){
        cout<<"memory error: Full Capacity"<<endl;
        return;
    }
    for(int x=0;x<h->count;x++) b[x]=h->a[x];
    h->hSize*=2;
    free(h->a);
    h->a=b;
}

struct Heap* destroyHeap(struct Heap *h){
    if(!h) return h;
    free(h->a);
    free(h);
    return NULL;
}

// O(n) => complexity
void buildHeap(struct Heap *h, int b[], int n){
    if(!h) return;
    if(h->hSize<n) resizeHeap(h);
    h->count=0;
    // percolate down take small node and propogate it down so at each level if we do that we will be acomplished in our task
    // lets skip the leaf nodes as they will not be processed any way
    while(h->count<n){ 
        h->a[h->count]=b[h->count];
        h->count++;
    }
    h->count++;
    for(int i=getParent(h,n-1);i>=0;i--) percolateDown(h,i);
}

void heapSort(int a[], int n){
    struct Heap *h=createHeapArray(15,1);
    if(!h) return;
    buildHeap(h,a,n);
    for(int i=n-1;i>=0;i--) cout<<deleteMax(h)<<", ";
}

// Day 9 
// delete the heap max k-1 times and we get kth at last
int kthMax(struct Heap *h,int k){
    // O(logn) complexity
    for(int i=0;i<k-1;i++)
        deleteMax(h);
    return h->a[0];
}

// this is to not let the deletion of data from the heap
int getKthMax(struct Heap *h,int k){
    struct Heap *temp=createHeapArray(h->hSize,h->hType);
    buildHeap(temp,h->a,h->count);
    return kthMax(temp,k);
}


int main(int argc, char const *argv[]){
    int b[]={2,4,6,9,5,10,7,11,12};
    cout<<"The HeapSort of the array gives the result as : ";
    heapSort(b,9);
    cout<<endl;
    struct Heap *h=createHeapArray(15,1);
    buildHeap(h,b,9);
    insertHeap(h,15);
    cout<<"Performing operation on newly created heap and then printing the root node or the  maximum: "<<getMaximum(h)<<endl;
    cout<<"Resizing Heap form size "<<h->hSize;
    resizeHeap(h);
    cout<<" to "<<h->hSize<<endl;
    h=destroyHeap(h);
    if(h==NULL) cout<<"The Heap is deleted !"<<endl;
    else cout<<"The Heap is still here !"<<endl;
    return 0;
}
