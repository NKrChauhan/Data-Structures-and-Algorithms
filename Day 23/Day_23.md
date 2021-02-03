# Data Structure and Algorithm

## Day 23

#### Mostly it has functions for Greedy Algorithms

### The functions applied in day 23 :
```sh

    bool sortingRule_para1(vector<int> &v1,vector<int> &v2);

    bool sortingRule_para1_desc(vector<int> &v1,vector<int> &v2);

    bool sortingRule_para2(vector<int> &v1,vector<int> &v2);
    
    bool sortingRule_para2_float(vector<float> &v1,vector<float> &v2);
    
    vector<vector<int>> timeScheduling(vector<vector<int>> v);
    
    vector<vector<vector<int>>> roomScheduling(vector<vector<int>> v);
    
    vector<vector<vector<int>>> roomScheduling_optimized(vector<vector<int>> v);
    
    float fractionalKnapsack(vector<int> v, vector<int> w, vector<int> n, int w_limit);
    
    int jobSchedulingWithDeadline(vector<vector<int>> v);


```

## Output:
```sh
    The jobs: {1,13},{2,4},{5,7},{8,10},{7,9},{3,6},{11,12}, after time scheduled gives: {2,4}->{5,7}->{8,10}->{11,12}->\O
    The jobs: {1,13},{2,4},{5,7},{8,10},{7,9},{3,6},{11,12}, after room scheduled gives: 
    {
    {1,13}->\O
    {2,4}->{5,7}->{8,10}->{11,12}->\O
    {3,6}->{7,9}->\O
    }
    The jobs: {1,13},{2,4},{5,7},{8,10},{7,9},{3,6},{11,12}, after room scheduled optimized gives: 
    {
    {1,13}->\O
    {2,4}->{7,9}->{11,12}->\O
    {3,6}->{5,7}->{8,10}->\O
    }
    The jobs with {profit,deadlines}: {20,2},{15,2},{10,1},{5,3},{1,3}, after time scheduled gives max profit as: 40
    The fractional knapsack will give the following output for data {value,weight,number}:{20,20,2},{23,65,3},{46,78,1},{10,31,5},{5,30,6},{9,55,7} with max limit = 200 Max Profit is: 115.015
```