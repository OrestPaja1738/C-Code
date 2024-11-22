#include <iostream>
#include <algorithm>  
#include <vector>

void getData(std::vector<int>& array){

    int n;

    while (1)
    {
        std::cin>>n;
        if (n == -1)
        {
            break;;
        }
        else{
            array.push_back(n);
        }
    }
}

int binarySearch(std::vector<int>& array){

    std::sort(array.begin(),array.end());

    int target;

    std::cin>>target;

    int left = 0,right = array.size() - 1;

    while (left <= right)
    {
        int middle = left + (right - left)/ 2;

        if (array[middle] == target)
        {
            return middle;
        }
        else if (array[middle] < target)
        {
            left = middle + 1;
        }
        else{
            right = middle - 1;
        }
    }

    return -1;
}

int main(){

std::vector<int>array;

    getData(array);

int fnOutput = binarySearch(array);

std::cout<<fnOutput;

    return 0;
}