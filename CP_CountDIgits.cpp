#include <iostream> 
using namespace std;

int countDigit(int number){
    if(number == 0){
        return 0; 
    }
    
    number  = number / 10;
    
    return countDigit(number) + 1;
    
}

int main(){
    int number = 54329574;
    int digitCount = countDigit(number );
    cout << digitCount << endl;
    return 0;
}