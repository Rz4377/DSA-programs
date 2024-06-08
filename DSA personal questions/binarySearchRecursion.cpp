#include<iostream>
using namespace std;

int binarySearch(int arr[] , int start , int end, int target){
    if(start>end){
        return -1;
    }
    int mid = start+(end-start)/2;

    if(target == arr[mid]){
        return mid;
    }
    else if(arr[mid]>target){
        return binarySearch(arr , start , mid-1 ,target );
    }
    else{
        return binarySearch(arr ,mid+1 , end,target );
    }
}

int main(){
    int arr[] = {1,3,5,7,8,10,11,12};
    int size = sizeof(arr)/sizeof(int);
    int start = 0;
    int end = size -1;
    int target = 11;

    int index = binarySearch(arr , start , end , target);

    if(index!= -1){
        cout << arr[index] << endl;
    } else{
        cout << "number not found" << endl;
    }

    return 0;
}