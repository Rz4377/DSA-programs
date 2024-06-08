#include <iostream>
#include <vector>
#include<algorithm>
#include<climits>

using namespace std;

void solve(vector<int>& arr , int i , int sum , int& maxi){
    if(arr.size() <= i){
        maxi = max(sum , maxi);
        return ;
    }

    solve(arr , i+2 , sum+arr[i] , maxi);
    solve(arr , i+1 , sum , maxi);
}

int main(){
    vector<int> arr {2,1,4,9};
    
    int maxi = INT_MIN;
    solve(arr ,0 , 0 , maxi);

    cout << "maximum sum for adjacent number can be : " << maxi << endl;
    return 0;
}