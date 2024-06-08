#include <iostream>
using namespace std;


int main(){
    int arr[]={1,5,2,6,8,9};
    int size = sizeof(arr)/sizeof(int);

    int start = 0;
    int end = size -1;
    while (start <end){
        swap(arr[start++],arr[end--]);

    }

    for(int i=0; i<size ; i++){
        cout <<arr[i] << " ";
    }
    return 0;
}

//two sum