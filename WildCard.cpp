#include<iostream>
using namespace std;

bool isMatcher(string s,string p,int i,int j){
    if(s.size() == i && p.size() == j){
        return true;
    }
    bool a1 = false;
    bool a2 = false;

    if(s[i] == p[i] || p[i] == '?' && s.size()-i!= 0){
        a1 = isMatcher(s,p,i+1,j+1);
    }
    else if(p[i] == '*'){
        while((s.size()>=i && a2 == false) && p.size()>j){
            a2 = isMatcher(s,p,i,j+1);
            i++;
        }
    }
    return a1 ||a2;
}

int main(){

    string s = "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba";
    string p = "a*******b";
    int i = 0,j = 0;
    bool ans = isMatcher(s,p,i,j);
    if(ans){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    return 0;
}


