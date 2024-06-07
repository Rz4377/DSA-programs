#include <iostream>
using namespace std; 

void merge(int arr[] , int start , int end){
    int mid = start + (end - start)/2;

    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *left = new int [len1];
    int *right = new int [len2];

    int k = start;

    for(int i=0 ; i<len1 ; ++i){
        left[i] = arr[start + i];
    }

    for(int i=0 ; i<len2 ; ++i){
        right[i] = arr[mid+1+i];
    }

    int leftIndex = 0;
    int rightIndex = 0;
    int mainIndex = start;

    while((leftIndex < len1) && (rightIndex <len2)){
        if(left[leftIndex] <= right[rightIndex]){
            arr[mainIndex++] = left[leftIndex++];
        }
        else{
            arr[mainIndex++] = right[rightIndex++];
        }
    }

    while(leftIndex <len1){
        arr[mainIndex++] = left[leftIndex++];
    }

    while(rightIndex < len2){
        arr[mainIndex++] = right[rightIndex++];
    }

    delete[] left;
    delete[] right;
}

void mergeSort(int arr[] , int start , int end){
    if(start>=end){
        return ;
    }
    
    int mid = start + (end-start)/2;

    mergeSort(arr , start , mid);
    mergeSort(arr , mid+1 , end);

    merge(arr , start , end);
}

int main(){
    int arr[] ={1,25,2,11,89,66};
    int size = sizeof(arr)/sizeof(int);
    int start = 0;
    int end = size - 1;
    mergeSort(arr , start , end);
    for(int i=0 ; i<size ; ++i){
        cout << arr[i] << " ";
    }
    return 0;
}