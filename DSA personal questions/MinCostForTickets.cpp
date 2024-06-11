#include<iostream>
#include<vector>
#include<climits>

using namespace std;

void solve(vector<int>& days, vector<int>& costs ,int i,int& mini ,int currSum){
        // base case
        if(i>=days.size()){
            cout << currSum << " ";
            mini = min(mini,currSum);
            return ;
        }

        // case 1
        solve(days,costs,i+1,mini,currSum+costs[0]);

        // case 2
        int count = 1;
        int finalDay7 = days[i]+7-1;
        while(i+count <days.size() && days[i+count]<=finalDay7){
            count++;
        }
        solve(days,costs,i+count,mini,currSum+costs[1]);

        // case 3
        int count2 = 1;
        int finalDay30 = days[i]+30-1;
        while(i+count2 <days.size() && days[i+count2] <= finalDay30){
            count2++;
        }
        solve(days,costs,i+count2,mini,currSum+costs[2]);
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
        int i = 0,mini = INT_MAX,currSum = 0;
        solve(days,costs,i,mini,currSum);
        return mini;
}

int main(){
    vector<int> days;
    days = {1,2,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,20,21,24,25,27,28,29,30,31,34,37,38,39,41,43,44,45,47,48,49,54,57,60,62,63,66,69,70,72,74,76,78,80,81,82,83,84,85,88,89,91,93,94,97,99};
    vector<int> costs = {9,38,134};
    cout << mincostTickets(days,costs);
}