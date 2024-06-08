#include <iostream>
#include <vector>
using namespace std;

void substringOfString(string str, vector<string>& answer , string value , int index){
    if(str.size() == index){
        answer.push_back(value);
        return ;
    }

    substringOfString(str ,answer, value , index+1);
    value.push_back(str[index]);
    substringOfString(str ,answer, value , index+1);
}

int main(){
    int arr[3];
    for(int i=0 ; i<3 ; ++i){
        cin>> arr[i];
    }
    for(int i=0 ; i<3 ; ++i){
        cout << arr[i];
    }

    vector<string> answer;
    string str = "abc";
    int index = 0;

    substringOfString(str , answer , "" , index);

    for(int i=0 ; i<answer.size() ; ++i){
        cout << i+1 << ". " << answer[i] << endl;
    }

    return 0;
}