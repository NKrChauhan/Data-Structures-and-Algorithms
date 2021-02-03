#include <iostream>
#include <bits/stdc++.h> //cpp stl functions like sort not work without it so be careful guys
#include <queue>
#include <math.h>       /* floor */
#include <vector> 
#include <map> 
#include <climits> 

using namespace std;

// *Terminologies
// Greedy choice property   : choosing local optimal solution and go further so as to find global optimal solution.
// Optimal Substrate        : breaking problem into subproblems and finding optimal solution of all to find global optimal solution.

// *Greedy algo examples :
// selection sort, topological sort, heap sort, huffman coding compression, dijkstra's algo, coin change, fractional knapsack, disjoint set: union by size and height, job scheduling 

// *Huffman coding Algo:
// take min heap->enter all elements
// pick the two min and make binary tree and reinsert in min heap
// repeat step 2 until one left standing,,,thats the huffmann coding tree.

// *K-Way merging Algo:
// lets say filesSize[]={100,123,156...} we need to merge all
// to decrease the intermediate files made in the process we merge k-files at a time
//  creating n/k intermediate files after every step.

// *Merging of n files optimally is best done by the huffman coding algorithm than random k-way merging algo

// Function decleration

bool sortingRule_para1(vector<int> &v1,vector<int> &v2);
bool sortingRule_para1_desc(vector<int> &v1,vector<int> &v2);
bool sortingRule_para2(vector<int> &v1,vector<int> &v2);
bool sortingRule_para2_float(vector<float> &v1,vector<float> &v2);
vector<vector<int>> timeScheduling(vector<vector<int>> v);
vector<vector<vector<int>>> roomScheduling(vector<vector<int>> v);
vector<vector<vector<int>>> roomScheduling_optimized(vector<vector<int>> v);
float fractionalKnapsack(vector<int> v, vector<int> w, vector<int> n, int w_limit);
int jobSchedulingWithDeadline(vector<vector<int>> v);

// Function definition

bool sortingRule_para2(vector<int> &v1,vector<int> &v2){
    return v1[1]<v2[1];
}

bool sortingRule_para1(vector<int> &v1,vector<int> &v2){
    return v1[0]<v2[0];
}

bool sortingRule_para2_float(vector<float> &v1,vector<float> &v2){
    return v1[1]>v2[1];
}

bool sortingRule_para1_desc(vector<int> &v1,vector<int> &v2){
    return v1[0]>v2[0];
}

// the time scheduler is has process time as {start,end}
// Earliest Activity First:
//     Repeatedly  select  the  activity  with  the  earliest  start  time,  pro-vided that it does not overlap any of the previously scheduled activities.
// Shortest Activity First:
//     Repeatedly select the activity with the smallest duration (fi−si),provided that it does not conflict with any previously scheduled activities.
// Lowest Conflict Activity First:
//     Repeatedly  select  the  activity  that  conflicts  with  the smallest number of remaining activities, provided that it does not conflict with of the previously scheduled activities.
vector<vector<int>> timeScheduling(vector<vector<int>> v){
    // sorting on the basis of end time and then comparison
    vector<vector<int>> res;
    sort(v.begin(),v.end(),sortingRule_para2);
    int f=INT_MIN; //check finish time of prev with current
    for(auto x:v){
        if(f<x[0]){
            f=x[1];
            res.push_back(x);
        }
    }
    return res;
}

// Multiple rooms and multiple processes :Special case of general graph coloring problem (NP-completeness/hard)
vector<vector<vector<int>>> roomScheduling(vector<vector<int>> v){
    vector<vector<vector<int>>> res;
    sort(v.begin(),v.end(),sortingRule_para1);
    for(auto x:v){
        int flag=0;
        for(int i=0;i<res.size();i++){
            if((res[i].back())[1]<x[0]){
                res[i].push_back(x);
                flag=1;
                break;
            }
        }
        if(flag==0){
            vector<vector<int>> temp;
            temp.push_back(x);
            res.push_back(temp);
        }
    }
    return res;
} 

// the algo can be optimized further to O(n) by breaking the start finish time
vector<vector<vector<int>>> roomScheduling_optimized(vector<vector<int>> v){
    vector<vector<vector<int>>> res;
    vector<vector<int>> activityAssociation;
    int i=0;
    for(auto x:v){
        // {activity name , start/finish time, start/finish flag}
        // refer number of railway platform problem. 
        activityAssociation.push_back({x[0],1,i});
        activityAssociation.push_back({x[1],-1,i});
        i++;
    }
    sort(activityAssociation.begin(),activityAssociation.end(),sortingRule_para1);
    i=0;
    for(auto x:activityAssociation){
        if(x[1]==1){
            if(i<res.size()) res[i].push_back(v[x[2]]);
            else res.push_back({v[x[2]]});
            i++;
        }else{
            i--;
        }
    }
    return res;
}

float fractionalKnapsack(vector<int> v, vector<int> w, vector<int> n, int w_limit){
    float total_benefit=0;
    vector<vector<float>> vTow;
    for(int i=0;i<v.size();i++)
        vTow.push_back({(float)i,(float)v[i]/(float)w[i]});
    sort(vTow.begin(),vTow.end(),sortingRule_para2_float);
    int i=0;
    while(w_limit>0 && i<v.size()){
        int x=vTow[i][0];
        if(w[x]*n[x]<=w_limit){
            w_limit-=(w[x]*n[x]);
            total_benefit+=(v[x]*n[x]);
        }else{
            float f=(float)w_limit/(float)w[x];
            w_limit=0;
            total_benefit+=((float)v[x]*f);
        }
        i++;
    }
    return total_benefit;
}

// the deadline is given as {profit,deadline} and maximize profit.
int jobSchedulingWithDeadline(vector<vector<int>> v){
    int profit=0,max_time=INT_MIN;
    sort(v.begin(),v.end(),sortingRule_para1_desc);
    for(auto x: v)
        if(x[1]>max_time)
            max_time=x[1];
    vector<int> allocation;
    for(int i=0;i<max_time;i++) allocation.push_back(0);
    for(auto x: v){
        for(int i=0;i<max_time;i++){ 
            if(allocation[i]==0 && i<x[1]){
                profit+=x[0];
                allocation[i]=1;
                break;
            }
        }
    }
    return profit;
}

int main(int argc, char const *argv[]) {
    vector<vector<int>> v;
    v.push_back({1,13});
    v.push_back({2,4});
    v.push_back({5,7});
    v.push_back({8,10});
    v.push_back({7,9});
    v.push_back({3,6});
    v.push_back({11,12});
    //---------------------------------------------------------
    cout<<"The jobs: ";
    for(auto x:v) cout<<"{"<<x[0]<<","<<x[1]<<"}"<<",";
    cout<<" after time scheduled gives: ";
    vector<vector<int>> res = timeScheduling(v);
    for(auto x:res) cout<<"{"<<x[0]<<","<<x[1]<<"}"<<"->";
    cout<<"\\O"<<endl;
    //---------------------------------------------------------
    cout<<"The jobs: ";
    for(auto x:v) cout<<"{"<<x[0]<<","<<x[1]<<"}"<<",";
    cout<<" after room scheduled gives: "<<endl;
    vector<vector<vector<int>>> res2 = roomScheduling(v);
    cout<<"{"<<endl;
    for(auto y:res2){ 
        for(auto x:y){
            cout<<"{"<<x[0]<<","<<x[1]<<"}"<<"->";
        }
        cout<<"\\O"<<endl;
    }
    cout<<"}"<<endl;
    //--------------------------------------------------------
    cout<<"The jobs: ";
    for(auto x:v) cout<<"{"<<x[0]<<","<<x[1]<<"}"<<",";
    cout<<" after room scheduled optimized gives: "<<endl;
    vector<vector<vector<int>>> res3 = roomScheduling_optimized(v);
    cout<<"{"<<endl;
    for(auto y:res3){ 
        for(auto x:y){
            cout<<"{"<<x[0]<<","<<x[1]<<"}"<<"->";
        }
        cout<<"\\O"<<endl;
    }
    cout<<"}"<<endl;
    // --------------------------------------------------------
    vector<vector<int>> PD{{20,2},{15,2},{10,1},{5,3},{1,3}};    
    cout<<"The jobs with {profit,deadlines}: ";
    for(auto x:PD) cout<<"{"<<x[0]<<","<<x[1]<<"}"<<",";
    cout<<" after time scheduled gives max profit as: ";
    cout<<jobSchedulingWithDeadline(PD)<<endl;
    //---------------------------------------------------------
    cout<<"The fractional knapsack will give the following output for data ";
    cout<<"{value,weight,number}:{20,20,2},{23,65,3},{46,78,1},{10,31,5},{5,30,6},{9,55,7} with max limit = 200 Max Profit is: ";
    float max_p=fractionalKnapsack({20,23,46,10,5,9},{20,65,78,31,30,55},{2,3,1,5,6,7},200);
    cout<<max_p<<endl;
    return 0;
}
