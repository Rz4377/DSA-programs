#include<iostream>
using namespace std;

void AddStringRecursively(string& sumx , string str1 , string str2 , int i , int j , int carry){
    // base cond
    if(((0>i) && (0>j)) && carry == 0){
        return ;
    }

    int last1 = 0 , last2 = 0;
    if(0<=i){
        last1 = str1[i] - '0';
    }
    if(0<=j){
        last2 = str2[j] - '0';
    }

    int sum = (last1 + last2 + carry);
    cout << "sum : " << sum  << endl;

    carry = sum/10;
    sum = sum %10;

    char x = sum + '0';

    sumx.push_back(x);

    AddStringRecursively(sumx , str1 , str2, i-1 , j-1 , carry);
}

int main(){
    string str1 = "1234";
    string str2 = "321";
    int i = str1.size() -1;
    int j = str2.size() -1;
    string sumx = "";
    int carry = 0;
    AddStringRecursively(sumx , str1 , str2 , i , j , carry);
    reverse(sumx.begin(),sumx.end());

    cout << sumx << endl;
    return 0;
}