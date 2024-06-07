#include<iostream>
#include<climits>
using namespace std;

int main(){
    int arr[]={1,23,11,16};
    int maxi = INT_MIN;
    int size = sizeof(arr)/sizeof(int);
    
    for(int i=0 ; i<size ; ++i){
        if(arr[i]>maxi){
            maxi = arr[i];
        }
    }

    cout << maxi <<endl;
}