#include <iostream>
using namespace std;

void removeSubstr(string &str , string substr){
    int index = str.find(substr);
    while(index!= string::npos){
        str = str.substr(0,index)+ str.substr(index + substr.length(),str.length());
        index = str.find(substr);
    }
}

int main(){
    string str = "maha dev har har";
    string substr = "har";
    removeSubstr(str , substr);
    cout << str << endl;
    return 0;
}