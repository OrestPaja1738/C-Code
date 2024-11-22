#include <iostream>
#include <vector>
#include <algorithm>

void getData(std::vector<int>& height,int n){

    for (int i = 0; i < n; i++)
    {
        std::cout<<"Enter value for array\n";
        std::cin>>height[i];
    }
}

int fnArea(const std::vector<int>& height,int n){

int left = 0,right = n - 1;
int maxArea = -1000;

    while (left < right)
    {
        int width = right - left;
        int length = std::min(height[left],height[right]);

        int area = width * length;

        if (area > maxArea)
        {
            maxArea = area;
        }

        if (height[left] < height[right])
        {
            left++;
            /*Pointers move accordingly to the "weight" of the value they point to
            It makes sense in this case because the greater the height,the greater area it
            will encompass
            */
        }
        else{
            right--;
        }
        
    }
    

    return maxArea;
}

int main(){

int n;

std::cout<<"Enter n value\n";
std::cin>>n;

std::vector<int>height(n);

    getData(height,n);

    int output = fnArea(height,n);

    std::cout<<output;

    return 0;
}