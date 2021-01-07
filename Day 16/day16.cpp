#include <iostream>
#include <bits/stdc++.h> //cpp stl functions like sort not work without it so be careful guys
#include <queue>
#include <math.h>       /* floor */
#include <vector> 
#include <map> 
#include <climits> //to use the INT_MIN or other limits.
#define LOAD_FACTOR 20 //for the hash table implementation.

using namespace std;

// *Hashing components:
// Hash table, Hash function, Collisions, Collision resolution techniques

// *Collision resolution techniques:
// Linear probing, Quadratic probing,  Double Hashing, Open Addressing, Saperate Chaining

// *Hashing Techniques: Static and Dynamic

// *Hashing limitations dataStructure level:
// rigid data-type to be saved.
// not ordered way of aranging.
// prefix search is not possible.
// multi-dimensional data cannot be stored.
// unique keys.

// *Bloom filter : bit vector to say if an element is maybe in the set or not
// the bit set cannot be unset as it may be belong to another element.
// to remove an element you can use another bloom filter with removed set of bits but you cannot re-insert them in the bloom filter

// Other declerations & definition
struct node{
    int data;
    struct node *next;
};

struct HashTableNode{
    int block_size;   //no. of elements in a block
    struct node *next;
};

struct HashTable{
    int hSize;        //table size
    int count;        //no. of elements in a table
    struct HashTableNode **table;
};

// *Basically, HashTable -> HashTableNode ->node->node...
// *                     -> HashTableNode ->node->node...

// *Function decleration
// Saperate chaining implementation functions
int hashFunction(int data, int size);
struct HashTable *createHashTable(int size);
int searchHashTable(struct HashTable *h,int data);
int insertHashTable(struct HashTable *h,int data);
int deleteHashTable(struct HashTable *h,int data);
void rehashHashTable(struct HashTable *h);

// *Function definition
// Saperate chaining implementation functions
int hashFunction(int data, int size){
    return data%size;
}

struct HashTable *createHashTable(int size){     //only this will take O(n) time
    struct HashTable *h=(struct HashTable *)malloc(sizeof(struct HashTable));
    if(!h) return NULL;
    h->hSize=size/LOAD_FACTOR;
    h->count=0;
    h->table=(struct HashTableNode **)malloc(sizeof(struct HashTableNode*)*h->hSize);
    if(!h->table) return NULL;
    for(int i=0;i<h->hSize;i++){
        h->table[i]->next=NULL;
        h->table[i]->block_size=0;
    }
    return h;
}

int searchHashTable(struct HashTable *h,int data){
    struct node *temp;
    temp=h->table[hashFunction(data,h->hSize)]->next;
    while(temp){ 
        if(temp->data==data ) return 1; 
        temp=temp->next;
    }
    return 0;
}

int insertHashTable(struct HashTable *h,int data){
    struct node *temp,*newNode;
    if(searchHashTable(h,data)) return 0;
    newNode=(struct node *)malloc(sizeof(struct node));
    int index = hashFunction(data,h->hSize);
    if(!newNode) return -1;
    newNode->data=data;
    temp = h->table[index]->next;
    newNode->next=temp;
    h->table[index]->next=newNode;
    h->table[index]->block_size++;
    h->count++;
    if(h->count/h->hSize>LOAD_FACTOR) rehashHashTable(h);
    return 1;
}

int deleteHashTable(struct HashTable *h,int data){
    struct node *temp,*prev;
    int index = hashFunction(data,h->hSize);
    temp=prev=h->table[index]->next;
    while(temp){
        if(temp->data==data){
            prev->next=temp->next;
            free(temp);
            h->count--;
            h->table[index]->block_size--;
            return 1;
        }
        prev=temp;
        temp=temp->next;
    }
    return 0;
}

void rehashHashTable(struct HashTable *h){
    // saving the old info as we need it later
    struct HashTableNode **oldTable=h->table;
    int oldSize= h->hSize;
    // count will remain the same
    h->hSize=h->hSize*2;
    h->table=(struct HashTableNode **)malloc(sizeof(struct HashTableNode*)*h->hSize);
    if(!h->table){ 
        cout<<"Reallocation Error"<<endl;
        return;
    }
    for(int i=0;i<oldSize;i++){
        struct node *temp=oldTable[i]->next;
        while(temp){
            int new_index=hashFunction(temp->data,h->hSize);
            struct node *temp2=temp;
            temp=temp->next;
            temp2->next=h->table[new_index]->next;
            h->table[new_index]->next=temp2;
        }
    }
}

int main(int argc, char const *argv[]) {
    struct HashTable *h=createHashTable(10);
    cout<<"The insertion in the hash table is done ? "<<insertHashTable(h,4)<<endl;
    cout<<"The searching in the hash table gives the result :  ";
    cout<<searchHashTable(h,4)<<endl;
    cout<<"The deletion in the hash table gives the result: "<<deleteHashTable(h,4)<<endl;
    cout<<"The searching in the hash table gives the result :  "<<searchHashTable(h,4)<<endl;
    return 0;
}
