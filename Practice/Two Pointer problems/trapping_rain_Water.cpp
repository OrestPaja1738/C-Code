#include <iostream>
#include <vector>

void getData(std::vector<int>& heights){

    int n;

    while (1)
    {
        std::cin>>n;
        if (n == -1)
        {
            break;
        }
        else{
            heights.push_back(n);
        }
    }
}

int trappedWater(std::vector<int>& arr){

int left = 0,right = arr.size() - 1;
int maxLeft = 0,maxRight = 0;
int sum = 0;

    while (left <= right)
    {
        if (arr[left] <= arr[right])
        {
            if (arr[left] >= maxLeft)
            {
                maxLeft = arr[left];
            }
            else{
                sum += maxLeft - arr[left];
            }
            left++;
        }
        else{
            if (arr[right] >= maxRight)
            {
                maxRight = arr[right];
            }
            else{
                sum += maxRight - arr[right];
            }
            right--;
        }
    }
    
    return sum;
}

int main(){

std::vector<int>heights;

    getData(heights);

int fnOutput = trappedWater(heights);

std::cout<<fnOutput;

    return 0;
}