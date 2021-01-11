#include <iostream>
#include <bits/stdc++.h> //cpp stl functions like sort not work without it so be careful guys
#include <queue>
#include <math.h>       /* floor */
#include <vector> 
#include <map> 
#include <climits> //to use the INT_MIN or other limits.

using namespace std;

// *try to select the size of the bloom filter according to the #elements you insert
// bloom filter structure
struct bloomNode{
    int *pres;
    int *dele;
    int bSize;
};

// Function decleration
struct bloomNode *createBloom(int s);
void insertBloom(struct bloomNode *a, int x);
void deleteBloom(struct bloomNode *a, int x);
int searchBloom(struct bloomNode *a, int x);

// *the prolem of searching in the two arrays whether the set of element are the same .
// Ans: for normal approach swap the visited element in the end and move farward to keep track.

// *if there is an problem where char involve and the hash map is used
// Ans: the hash map used can be array counter[256] as the range of ascii is 0-256

// Function definition
struct bloomNode *createBloom(int s){
    struct bloomNode *bloom=(struct bloomNode *)malloc(sizeof(struct bloomNode));
    bloom->bSize=s;
    bloom->pres=(int *)calloc(s,sizeof(int));
    bloom->dele=(int *)calloc(s,sizeof(int));
    return bloom;
}

void insertBloom(struct bloomNode *a,int x){
    hash<int> val;
    int y=val(x);
    // nhashfunction n=7 and 100 bits were taken
    for(int i=0;i<7;i++){
        a->pres[y%a->bSize]=1;
        y/=a->bSize;
    }
}

void deleteBloom(struct bloomNode *a, int x){
    hash<int> val;
    int y=val(x);
    // *nhashfunction n=7 and 100 bits were taken
    if(searchBloom(a,x)){
        for(int i=0;i<7;i++){
            a->dele[y%a->bSize]=1;
            y/=a->bSize;
        }
    }
}

// a is the insertion bit set and the b is the deletion bit set
int searchBloom(struct bloomNode *a, int x){
    hash<int> val;
    int y=val(x);
    int z=val(x);
    int count=0;
    // nhashfunction n=7 and 100 bits were taken
    for(int i=0;i<7;i++){
        if(a->pres[y%a->bSize]==0) return 0;
        y/=a->bSize;
    }
    for(int i=0;i<7;i++){
        if(a->dele[z%a->bSize]==1) count++;
        z/=a->bSize;
    }
    if(count==7) return 0;
    return 1;
}

int main(int argc, char const *argv[]) {
    struct bloomNode *bloom=createBloom(100);
    insertBloom(bloom,23);
    insertBloom(bloom,28);
    insertBloom(bloom,22);
    insertBloom(bloom,20);
    insertBloom(bloom,1);
    deleteBloom(bloom,24);
    deleteBloom(bloom,21);
    deleteBloom(bloom,23);
    deleteBloom(bloom,30);
    cout<<"if the following integer is present in the bloom filter or not: "<<searchBloom(bloom,23)<<endl;
    cout<<"if the following integer is present in the bloom filter or not: "<<searchBloom(bloom,20)<<endl;
    return 0;
}
