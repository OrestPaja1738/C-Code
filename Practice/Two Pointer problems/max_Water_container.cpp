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

int maxArea(std::vector<int>& arr){

    int left = 0,right = arr.size() - 1;
    int maxArea = 0;

    while (left <= right)
    {
        int width = right - left;
        if (arr[left] <= arr[right])
        {
            int area = width * arr[left];

            if (area >= maxArea)
            {
                maxArea = area;
            }
            left++;
        }
        else{
            int area = width * arr[right];

            if (area >= maxArea)
            {
                maxArea = area;
            }
            right--;
        }
    }
    
    return maxArea;
}

int main(){

std::vector<int>heights;

    getData(heights);

int fnOutput = maxArea(heights);

std::cout<<fnOutput;

    return 0;
}