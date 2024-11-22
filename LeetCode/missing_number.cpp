#include <iostream>
#include <vector>

void getData(std::vector<int>& arr,int n){

    for (int i = 0; i < n; i++)
    {
        std::cin>>arr[i];
    }
}

int findMissingNumber(std::vector<int>& arr,int n){

    int totalSum = n * (n + 1) / 2;
    int arrSum = 0;

    for (int i = 0; i < n; i++)
    {
        arrSum += arr[i];
    }
    
    return totalSum - arrSum;
}

int main(){

int n;
std::cin>>n;

std::vector<int>arr(n);

getData(arr,n);
int output = findMissingNumber(arr,n);

std::cout<<output;

    return 0;
}