#include <iostream>
#include <vector>
using namespace std; 

int diceProblem(int target  , vector<string>& answer , string str){
    if(target == 0){
        answer.push_back(str);
        return 1;
    }
    if(target < 0){
        return -1;
    }
    int count = 0;

    for(int i=1 ; i<=6 ; i++){
        int ans = diceProblem(target - i , answer, str+to_string(i));
        if(ans != -1){
            count = count + ans;
        }
    }

    return count;
}

int main(){
    int target = 3;
    vector<string> answer;

    cout << diceProblem(target , answer , "");
    cout << "vector size is " << answer.size() << endl;
    for(int i=0 ; i< answer.size(); ++i){
        cout << i+1 << ". " << answer[i] << endl; 
    }
    return 0;
}