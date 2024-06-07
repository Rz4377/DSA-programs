#include<iostream>
using namespace std;

int sumOfDigits(int number){
    if(number == 0){
        return 0;
    }
    int carry = number % 10;
    number = number / 10;

    return sumOfDigits(number) + carry;

}

int main(){
    int number = 123456;
    int sum = sumOfDigits(number);
    cout << sum << endl; 
    return 0;
}