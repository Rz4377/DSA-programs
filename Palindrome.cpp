#include<iostream>
#include<cmath>
using namespace std; 

int palindrome(int number , int size){
    if(number == 0){
        return 0;
    }
    else if(size == 0){
        return number;
    }
    
    int palindrome_number = (number%10) * pow(10 , size);
    number = number / 10;

    return palindrome(number , size -1) + palindrome_number; 
}

int main(){
    int number = 1234;
    int size = sizeof(number)/sizeof(int);
    int palindrome_check = palindrome(number , size -1);
    cout << "Palindrome number : " << palindrome_check << endl;
    return 0;
}