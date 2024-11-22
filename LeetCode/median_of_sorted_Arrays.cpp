#include <iostream>
#include <vector>

void getData(std::vector<int>& arr1,int n1,std::vector<int>& arr2,int n2){


    std::cout<<"First Array\n";

    for (int i = 0; i < n1; i++)
    {
        std::cout<<"Enter value for (first) array\n";
        std::cin>>arr1[i];
    }

    std::cout<<"\nSecond Array\n";

    for (int i = 0; i < n2; i++)
    {
        std::cout<<"Enter value for (second) array\n";
        std::cin>>arr2[i];
    }   
}

void sortMergedArray(std::vector<int>& arr,int n){

    int temp;

    for (int i = 0; i < (n - 1); i++)
    {
        for (int j = 0; j < (n - i - 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            } 
        }
    }
}

float findMedian(std::vector<int>& arr,int n){

float fnOutput;

    if (n % 2 != 0)
    {
        fnOutput = arr[n / 2];

    }
    else{
        fnOutput = (arr[(n / 2) - 1] + arr[n / 2]) / 2.0;
    }    
    
    return fnOutput;
}

int main(){

int n1,n2;

std::cout<<"Enter value for n1 and n2\n";
std::cin>>n1>>n2;

std::vector<int>arr1(n1);
std::vector<int>arr2(n2);

getData(arr1,n1,arr2,n2);

arr1.insert(arr1.end(),arr2.begin(),arr2.end());

sortMergedArray(arr1,n1);

int n = n1 + n2;

float output = findMedian(arr1,n);
std::cout<<output;

    return 0;
}