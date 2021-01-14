#include <iostream>
#include <bits/stdc++.h> //cpp stl functions like sort not work without it so be careful guys
#include <queue>
#include <math.h>       /* floor */
#include <vector> 
#include <map> 
#include <climits> //to use the INT_MIN or other limits.

using namespace std;

// *Function decleration
// Fast union implementation (slow find)
void makeSet_SF(int a[], int s);
int find_SF(int a[], int s, int x);
void union_SF(int a[], int s, int r1, int r2);

// Fast union implementation (quick find)
void makeSet_QF(int a[], int s);
int find_QF(int a[], int s, int x);
void union_QF_bySize(int a[], int s, int r1, int r2);
void union_QF_byHeight(int a[], int s, int r1, int r2); // also called by rank

// path compression will only work with size and not the height union

// *Function definition
// Fast union implementation (slow find)
void makeSet_SF(int a[], int s){
    for(int i=0;i<s;i++) a[i]=i;
}

int find_SF(int a[], int s, int x){
    if(x>=s || x<0) return -1;
    if(a[x]==x) return x;
    else return find_SF(a,s,a[x]);
}

void union_SF(int a[], int s, int r1, int r2){
    int r_r1=find_SF(a,s,r1);
    int r_r2=find_SF(a,s,r2);
    if(r_r2==r_r1) return ;
    // if r1 and r2 are within the range then union the two of them
    if((r1>=s || r1<0)||(r2>=s || r2<0)) return ;
    a[r_r1]=r_r2;
}

// Fast union implementation (quick find)
void makeSet_QF(int a[], int s){
    for(int i=0;i<s;i++) a[i]=-1;
}

int find_QF(int a[], int s, int x){
    if(x>=s || x<0) return -1;
    if(a[x] <=0) return x;
    else return find_QF(a,s,a[x]);
}

void union_QF_bySize(int a[], int s, int r1, int r2){
    int r_r1=find_QF(a,s,r1);
    int r_r2=find_QF(a,s,r2);
    // here -1 not only means the error but can be the root representation
    if((r_r1==r_r2) && r_r1!=-1) return;
    //if the ans is -1 then it should go further
    if(a[r_r1]>a[r_r2]){
        // assign the smaller sized set the root and increase the size of parent.
        int temp=a[r_r1];
        a[r_r1]=r_r2;
        a[r_r2]+=temp;
    }else{
        int temp=a[r_r2];
        a[r_r2]=r_r1;
        a[r_r1]+=temp;
    }
}

void union_QF_byHeight(int a[], int s, int r1, int r2){
    int r_r1=find_QF(a,s,r1);
    int r_r2=find_QF(a,s,r2);
    // here -1 not only means the error but can be the root representation
    if((r_r1==r_r2) && r_r1!=-1) return;
    //if the ans is -1 then it should go further
    if(a[r_r1]>a[r_r2]) a[r_r1]=r_r2;
    else{
        if(a[r_r1]==a[r_r2]) a[r_r1]--;  
        a[r_r2]=r_r1;
    }
}

int main(int argc, char const *argv[]) {
    int a[10];
    cout<<"Making a fresh disjoint set (slow find) will look as: ";
    makeSet_SF(a,10);
    for(int i=0 ;i<10;i++) cout<<i<<"->"<<a[i]<<", ";
    cout<<endl;
    cout<<"Performing operation like union(4,6): ";
    union_SF(a,10,4,6);
    for(int i=0 ;i<10;i++) cout<<i<<"->"<<a[i]<<", ";
    cout<<endl;
    cout<<"Performing operation like union(5,3): ";
    union_SF(a,10,5,3);
    for(int i=0 ;i<10;i++) cout<<i<<"->"<<a[i]<<", ";
    cout<<endl;
    cout<<"Performing operation like union(1,6): ";
    union_SF(a,10,1,6);
    for(int i=0 ;i<10;i++) cout<<i<<"->"<<a[i]<<", ";
    cout<<endl;
    cout<<"Performing operation like union(1,9): ";
    union_SF(a,10,1,9);
    for(int i=0 ;i<10;i++) cout<<i<<"->"<<a[i]<<", ";
    cout<<endl;
    cout<<"Finally we get the following set: ";
    for(int i=0 ;i<10;i++) cout<<i<<"->"<<a[i]<<", ";
    cout<<endl;
    int b[10];
    cout<<"Making a fresh disjoint set (quick find) will look as: ";
    makeSet_QF(b,10);
    for(int i=0 ;i<10;i++) cout<<i<<"->"<<b[i]<<", ";
    cout<<endl;
    cout<<"Performing operation like union(4,6) by size: ";
    union_QF_bySize(b,10,4,6);
    for(int i=0 ;i<10;i++) cout<<i<<"->"<<b[i]<<", ";
    cout<<endl;
    cout<<"Performing operation like union(5,3) by size: ";
    union_QF_bySize(b,10,5,3);
    for(int i=0 ;i<10;i++) cout<<i<<"->"<<b[i]<<", ";
    cout<<endl;
    cout<<"Performing operation like union(1,6) by size: ";
    union_QF_bySize(b,10,1,6);
    for(int i=0 ;i<10;i++) cout<<i<<"->"<<b[i]<<", ";
    cout<<endl;
    cout<<"Performing operation like union(1,9) by size: ";
    union_QF_bySize(b,10,1,9);
    for(int i=0 ;i<10;i++) cout<<i<<"->"<<b[i]<<", ";
    cout<<endl;
    cout<<"Finally we get the following set: ";
    for(int i=0 ;i<10;i++) cout<<i<<"->"<<b[i]<<", ";
    cout<<endl;
    int c[10];
    cout<<"Making a fresh disjoint set (quick find) will look as: ";
    makeSet_QF(c,10);
    for(int i=0 ;i<10;i++) cout<<i<<"->"<<c[i]<<", ";
    cout<<endl;
    cout<<"Performing operation like union(4,6) by height: ";
    union_QF_byHeight(c,10,4,6);
    for(int i=0 ;i<10;i++) cout<<i<<"->"<<c[i]<<", ";
    cout<<endl;
    cout<<"Performing operation like union(5,3) by height: ";
    union_QF_byHeight(c,10,5,3);
    for(int i=0 ;i<10;i++) cout<<i<<"->"<<c[i]<<", ";
    cout<<endl;
    cout<<"Performing operation like union(1,6) by height: ";
    union_QF_byHeight(c,10,1,6);
    for(int i=0 ;i<10;i++) cout<<i<<"->"<<c[i]<<", ";
    cout<<endl;
    cout<<"Performing operation like union(1,9) by height: ";
    union_QF_byHeight(c,10,1,9);
    for(int i=0 ;i<10;i++) cout<<i<<"->"<<c[i]<<", ";
    cout<<endl;
    cout<<"Finally we get the following set: ";
    for(int i=0 ;i<10;i++) cout<<i<<"->"<<c[i]<<", ";
    cout<<endl;
    return 0;
}