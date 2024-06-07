#include<iostream>
using namespace std; 

int armstrong(int number){
    if(number == 0){
        return 0;
    }

    int cube_carry = number % 10;
    number = number / 10;

    int cube = cube_carry * cube_carry * cube_carry;

    return armstrong(number) + cube;
}

int main(){
    int number = 407;
    int ans = armstrong(number);

    if(ans == number){
        cout << "number is armstrong" << endl;
    } else {
        cout << "number is not an armstrong" << endl;
    }

    return 0;
}