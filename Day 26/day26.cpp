#include <iostream>
#include <bits/stdc++.h> //cpp stl functions like sort not work without it so be careful guys
#include <queue>
#include <math.h> // floor
#include <vector>
#include <map>
#include <climits>

using namespace std;

// Function decleration
void reverse(int a[], int s, int e);
void rotateTheArray(int a[], int n, int d);
void swap(char a[], int i, int j);
void shiftSpacesInTheFront_M1(char a[],int s);
void shiftSpacesInTheFront_M2(char a[],int s);
void shiftSpacesInTheBack_M1(char a[],int s);
void shiftSpacesInTheBack_M2(char a[],int s);
int countNumberOf1ton(int n);
int numberOfPathsUsingRec(int m, int n);

// Function definition
void reverse(int a[], int s, int e){
    while(e>s){
        int temp=a[s];
        a[s]=a[e];
        a[e]=temp;
        s++;
        e--;
    }
}

void rotateTheArray(int a[], int n, int d){
    // this can be done by 2 methods ,
    // 1 make a new array and insert in order of rotation space=> O(n)
    
    // int res[];
    // int i=0;
    // for(;i<n-d;i++)
    //     res[i]=a[d+i];
    // for(int j=0;j<d;j++)
    //     res[i++]=a[j];
    // return res;

    // for space O(1) time will be more reverse(reverse(0-d-1)+reverse(d-n))
    reverse(a,0,d-1);
    reverse(a,d,n-1);
    reverse(a,0,n-1);
}

void swap(char a[], int i, int j){
    if(i<0 || j<0) return;
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}

/* 
    ! the basic motive is to use 2 methods for this type of problems
    ! only difference is shifting like a[i--]=a[s]; and swapping like swap(a,i,j--);
*/

// inplace
void shiftSpacesInTheFront_M1(char a[],int s){
    int i=s-1,j=s-1;
    for(;i>=0;i--)
        if(a[i]!=' ') swap(a,i,j--);
    while(j>=0) a[j--]=' ';
}

// focus on space rather than which space
void shiftSpacesInTheFront_M2(char a[],int s){
    s-=1;
    int i=s;
    for(;s>=0;s--)
        if(a[s]!=' ') a[i--]=a[s];
    while(i>=0)
        a[i--]=' ';
}

// inplace shorter method
void shiftSpacesInTheBack_M1(char a[],int s){
    int i=0,j=0;
    for(;i<s;i++)
        if(a[i]!=' ') swap(a,i,j++);
    while(j<s) a[j++]=' ';
}

// focus on space rather than which space
void shiftSpacesInTheBack_M2(char a[],int s){
    int i=0,j=0;
    for(;i<s;i++)
        if(a[i]!=' ') a[j++]=a[i];
    while(j<s)
        a[j++]=' ';
}

int countNumberOf1ton(int n){
    int count=0;
    for(unsigned int i=1;i<=n;i++){
        unsigned int temp=i;
        for(;temp>0;temp>>=1) count+=(temp & 1);
    }
    return count;
}

// using reccursion 2nd method is to use pascal's triangle.
int numberOfPathsUsingRec(int m, int n){
    // considering them as the mesh 1,1 is the top-left most 
    if(m==1 || n==1) return 1;
    return numberOfPathsUsingRec(m-1,n)+numberOfPathsUsingRec(m,n-1);
}

int main(int argc, char const *argv[]) {
    int x[]={1,2,3,4,5,6,7,8,9,10,11};
    cout<<"The roation of the array: ";
    for(int i=0;i<11;i++)
        cout<<x[i]<<", ";
    cout<<"is now rotated to as 4 to: ";
    rotateTheArray(x,11,4);
    for(int i=0;i<11;i++)
        cout<<x[i]<<", ";
    cout<<endl;
    cout<<"The number of 1 bit from 0 to 10 is: "<<countNumberOf1ton(10)<<endl;
    char s[]={'a','b','c',' ','k','i','t','t',' ','p','a',' ',' '};
    cout<<"The original array with spaces is given as: '";
    for(int i=0;i<13;i++) cout<<s[i];
    cout<<"'"<<endl;
    cout<<"After Front shift method 2: >'";
    shiftSpacesInTheFront_M2(s,13);
    for(int i=0;i<13;i++) cout<<s[i];
    cout<<"'"<<endl;
    shiftSpacesInTheBack_M2(s,13);
    cout<<"After Back shift method 2: >'";
    for(int i=0;i<13;i++) cout<<s[i];
    cout<<"'"<<endl;
    cout<<"After Front shift method 1: >'";
    shiftSpacesInTheFront_M1(s,13);
    for(int i=0;i<13;i++) cout<<s[i];
    cout<<"'"<<endl;
    cout<<"After Back shift method 1: >'";
    shiftSpacesInTheBack_M1(s,13);
    for(int i=0;i<13;i++) cout<<s[i];
    cout<<"'"<<endl;
    cout<<"The possible paths in matrix from top-left to bottom-right: ";
    cout<<numberOfPathsUsingRec(3,2)<<endl;
    return 0;
}
