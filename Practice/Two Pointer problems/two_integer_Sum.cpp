#include <iostream>
#include <vector>
#include <algorithm>

void getDataSort(std::vector<int>& array){

    int n;

    while (1)
    {
        std::cin>>n;
        if (n == -1)
        {
            break;
        }
        else{
            array.push_back(n);
        }
        
    }
    
    std::sort(array.begin(),array.end());
}

void twoSum(std::vector<int>& array,int target){

std::vector<int>outputArray(2);
int left = 0,right = array.size() - 1;

    while (left < right)
    {
        int sum = array[left] + array[right];
        if (sum == target)
        {
            outputArray[0] = array[left];
            outputArray[1] = array[right];
            break;
        }
        else if (sum < target)
        {
            left++;
        }
        else{
            right--;
        }
    }

    for (const int&val : outputArray)
    {
        std::cout<<val<<"\n";
    }
}

int main(){

std::vector<int>array;

    getDataSort(array);

int target;
std::cin>>target;

    twoSum(array,target);

    return 0;
}