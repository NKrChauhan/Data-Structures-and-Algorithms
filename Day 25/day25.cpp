#include <iostream>
#include <bits/stdc++.h> //cpp stl functions like sort not work without it so be careful guys
#include <queue>
#include <math.h> // floor
#include <vector>
#include <map>
#include <climits>

using namespace std;

// Function decleration
int checkIsBitSet(int n, int k);
int setKthBit(int n, int k);
int clearingKthBit(int n, int k);
int toggleKthBit(int n, int k);
int toggleRightmost1bit(int n);
int isolationRightmost1bit(int n);
int checkPower2(int n);
unsigned int reverseBinary(unsigned int n);
int countNumberof1_(unsigned int n, int m);
int swapOddEvenBits(int n);
void printMatrixSpiralOrder(int a[][5],int m,int n);
vector<int> shuffledCards();

// Function definition
int checkIsBitSet(int n, int k){
    if(n&(1<<k-1)) return 1;
    // 1<<k will move one to kth location, 1<<(k-1) means since the bit activation starts from 0 power to ...so on
    return 0;
}

int setKthBit(int n, int k){
    if(n==0 || k==0) return n;
    return n|(1<<k-1);
}

int clearingKthBit(int n, int k){
    if(n==0 || k==0) return n;
    return n&(~(1<<k-1));
}

int toggleKthBit(int n, int k){
    if(n==0 || k==0) return n;
    return n^(1<<k-1);
}

int toggleRightmost1bit(int n){
    if(n==0) return n;
    // it means preserve the rightmost 1 bit at whichever position it maybe in
    return n&(n-1);
}

int isolationRightmost1bit(int n){
    if(n==0) return n;
    return n&(~(n-1));
}

int isolationRightmost0bit(int n){
    if(n==0) return n;
    // negate the number and then isolate the one in the negated number.
    return ~n&((n+1));
}

int checkPower2(int n){
    if(toggleRightmost1bit(n)==0) return 1;
    return 0;
}

unsigned int reverseBinary(unsigned int n){
    int sizeOfN=sizeof(n);
    unsigned int rev=0;
    while(n>0){
        rev<<=1;
        rev|=(n&1);
        n>>=1;
        sizeOfN--;
    }
    rev<<=sizeOfN;
    return rev;
}

int countNumberof1_(unsigned int n, int m){
    if(m==1){
        unsigned int t=n;
        int x=0;
        while(t){
            x+=(t&1);
            t>>=1;
        }
        return x;
    }else if(m==2){
        unsigned int t=n;
        int x=0;
        while(t){
            if(t%2==1) x++;
            t/=2;
        }
        return x;
    }else if(m==3){
        // toggle rightmost 1 bit reccursively
        unsigned int t=n;
        int x=0;
        while(t){
            x++;
            t&=(t-1);
        }
        return x;
    }else{
        unsigned int t=n;
        // make 4 bit group 0000->0 0001->1 0010->1 0011->2 0100->1 0101->2 ... 1111->4
        int table[]={0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
        int x=0;
        while(t){
            x+=(table[t&(0x1f)]); //means mod32 (0x1f)
            t>>=4;
        }
        return x;
    }
}

int swapOddEvenBits(int n){
    // saperate all odds 0x55 5=0101 so => 01010101
    unsigned int tempO=n&(0x55555555);
    // saperate all evens 0xAA A=1010 so => 10101010
    unsigned int tempE=n&(0xAAAAAAAA);
    // shift them odd<<1 even>>1 then OR them
    tempO<<=1;
    tempE>>=1;
    return tempO|tempE;
}

void printMatrixSpiralOrder(int a[][5],int m,int n){
    // ________
    //|  ____  |
    //| |e___| |
    //s |______|
    int s_row=0,e_row=m-1,s_col=0,e_col=n-1;
    while(e_row-s_row>=0 && e_col-s_col>=0){
        int i=s_row,j=s_col;
        for(;i<e_row;i++)
            cout<<a[i][j]<<", ";
        for(;j<e_col;j++)
            cout<<a[i][j]<<", ";
        for(;i>s_row;i--)
            cout<<a[i][j]<<", ";
        for(;j>s_col;j--)
            cout<<a[i][j]<<", ";
        s_row+=1;
        s_col+=1;
        e_row-=1;
        e_col-=1;
        // cout<<s_row<<e_row<<s_col<<e_col<<endl;
    }
    if(m==n && n%2!=0) cout<<a[n/2][n/2]<<", ";
    cout<<endl;
}

vector<int> shuffledCards(){
    // assuming the 52 card have 0-51 numbers.
    vector<int> cards;
    srand(time(0));
    for(int i=0;i<52;i++)
        cards.push_back(i);
    for(int i=0;i<52;i++){
        int x=rand()%52;
        int y=(x+rand())%52;
        cards[x]+=cards[y];
        cards[y]=cards[x]-cards[y];
        cards[x]-=cards[y];
    }
    return cards;
}

int main(int argc, char const *argv[]) {
    cout<<"Checking if bit is 1 or not: "<<checkIsBitSet(8,4)<<endl;
    cout<<"Making kth bit 1: "<<setKthBit(5,2)<<endl;
    cout<<"Making kth bit 0: "<<clearingKthBit(7,1)<<endl;
    cout<<"Toggling kth bit: "<<toggleKthBit(8,2)<<endl;
    cout<<"Toggling rightmost bit: "<<toggleRightmost1bit(21)<<endl;
    cout<<"Saving the rightmost 1 bit: "<<isolationRightmost1bit(20)<<endl;
    cout<<"Checking Power 2: "<<checkPower2(8)<<endl;
    cout<<"Reversing the binary: "<<reverseBinary(20)<<endl;
    cout<<"Counting number of 1's using Method 1: "<<countNumberof1_(9,1)<<endl;
    cout<<"Counting number of 1's using Method 2: "<<countNumberof1_(9,2)<<endl;
    cout<<"Counting number of 1's using Method 3: "<<countNumberof1_(9,3)<<endl;
    cout<<"Counting number of 1's using Method 4: "<<countNumberof1_(9,4)<<endl;
    cout<<"Swaping the even and odd bits: "<<swapOddEvenBits(23)<<endl;
    int a[][5]={{1,12,11,10,0},{2,13,16,9,0},{3,14,15,8,0},{4,5,6,7,0}};
    cout<<"Spiral printing of the matrix: ";
    printMatrixSpiralOrder(a,4,5);
    vector<int> cards=shuffledCards();
    cout<<"Shuffled cards print from 0-51: ";
    for(int i=0;i<52;i++)
        cout<<cards[i]<<", ";
    cout<<endl;
    return 0;
}
