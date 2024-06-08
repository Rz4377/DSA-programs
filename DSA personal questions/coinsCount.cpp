#include<iostream>
#include<algorithm>
using namespace std;

int countCoins(int arr[] , int target , int size){
    if(target<0){
        return INT_MIN;
    }
    else if(target == 0){
        return 0;
    }

    int mini = INT_MAX;

    for(int i=0 ; i<size ; ++i){
        int ans = countCoins(arr , target - arr[i] , size);
        if(ans != INT_MIN){
            mini = min(mini , ans + 1);
        }
    }
    return mini;
}

int main(){
    int arr[] ={1,10,25};
    int target = 99;

    int size = sizeof(arr)/sizeof(int);

    int ans = countCoins(arr, target , size);
    cout << ans << endl;
    return 0;
}