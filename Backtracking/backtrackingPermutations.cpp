#include<iostream>
#include<vector>
using namespace std;

void solve(vector<string>& ans , string str , int index){
    if(index >= str.size()){
        ans.push_back(str);
        return ;
    }

    for(int i=index ; i<str.size() ; i++){
        swap(str[index], str[i]);
        solve(ans , str , index+1);
        swap(str[index], str[i]);
    }
}

int main(){
    string s="abc";
    vector<string> ans;
    int index =0;
    solve(ans , s , index);
    for(int i=0  ; i< ans.size() ; ++i){
        cout << ans[i] << " ";
    }
    return 0;
}
