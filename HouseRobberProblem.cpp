#include<iostream>
using namespace std;

void HouseRobberProblem(int arr[],int size,int index,int& maxi,int sumx){
    if(index >= size){
        maxi = max(maxi,sumx);
        return ;
    }

    HouseRobberProblem(arr,size,index+2,maxi,sumx+arr[index]);
    HouseRobberProblem(arr,size,index+1,maxi,sumx);
}

int main(){
    int arr[] = {5, 3, 4, 11, 2};
    int size = sizeof(arr)/sizeof(int);

    int index = 0;
    int maxi = 0;

    HouseRobberProblem(arr,size,index,maxi,0);
    cout << maxi << endl;
    return 0;
}