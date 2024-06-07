#include <iostream>
using namespace std;

int partition(int arr[] ,  int start , int end){
    int pivot = arr[start];
    int count = 0;

    for(int i=start ; i<=end ; i++){
        if(pivot > arr[i]){
            count++;
        }
    }

    int pivotIndex = count + start;
    swap(arr[pivotIndex],arr[start]);

    int i=start , j= end;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<=arr[pivotIndex]){
            i++;
        }
        while(arr[j]>=arr[pivotIndex]){
            j--;
        }
        if(i<pivotIndex){
            swap(arr[i], arr[j]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[] , int start , int end){
    if(start>=end){
        return ; 
    }

    int p = partition(arr , start , end);

    quickSort(arr , start , p-1);
    quickSort(arr , p+1 , end);
}

int main(){
    int arr[] = {8,1,4,3,20,9,17};
    int start = 0;
    int size = sizeof(arr)/sizeof(int);
    int end = size - 1;
    quickSort(arr , start , end);
    for(int i=0 ; i<size ; i++){
        cout << arr[i] << " ";
    }
}