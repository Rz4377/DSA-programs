#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int solve(int target , int arr[] , int size , vector<string>& answer , string str){
    if(target == 0){
        answer.push_back(str);
        return 0;
    }
    else if(target<0){
        return INT_MIN;
    }
    int maxi = INT_MIN;

    for(int i=0 ; i<size ; ++i){
        int ans = solve(target - arr[i], arr , size , answer, str+to_string(arr[i]));
        if(ans != INT_MIN){
            maxi = max(maxi, ans + 1);
        }
    }
    cout <<"maxi : " << maxi << endl;
    return maxi;
}

int main(){
    int arr[]={7,2,2};
    int target = 7;
    vector<string> ans;
    int size = sizeof(arr)/sizeof(int);
    int max_segment = solve(target , arr , size , ans , "");
    cout << max_segment << endl;

    for(int i=0 ; i<size ;++i){
        cout << ans[i] << endl;
    }
    return 0;
}