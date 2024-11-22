#include <iostream>
#include <vector>

void getData(std::vector<int>& array,int n){

    for (int i = 0; i < n; i++)
    {
        std::cin>>array[i];
    }
}

bool findOccurrence(std::vector<int>& array,int n){

    for (int i = 0; i < n; i++)
    {
        for (int j = (i + 1); j < n; j++)
        {
            if(array[i] == array[j]){
                return true;
            }
        }
        
    }
    
    return false;
}

int main(){

int n;
std::cin>>n;

std::vector<int>array(n);

    getData(array,n);

bool fnOutput = findOccurrence(array,n);

std::cout<<fnOutput;

    return 0;
}