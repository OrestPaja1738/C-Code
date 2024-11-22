#include <iostream>
#include <vector>
#include <algorithm>

/*
The approach would be to first sort the array and then to create an unordered set vector
which i can copy(?). Afterwards a nested for loop where the goal is to check if difference
between array[j] - array[i] == 1 and if so,both indexes will be saved in another array i suppose
*/

void getDataAndSort(std::vector<int>& array){

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

    auto last = std::unique(array.begin(),array.end());
    //basically shifts duplicates on the right aka the end of the vector
    //last serves as a ppinter to this "bridge" part
    array.erase(last,array.end());
}

int findSequenceCnt(std::vector<int>& array){

int cnt = 1; //because the sequence at its basis level should start with 1 element
//there is no sequence with 0 elements
int maxCnt = -1000;

    for (int i = 1; i < array.size(); i++)
    {
        if (array[i] - array[i - 1] == 1)
        {
            cnt++;
        }
        else{
            cnt = 1;
        }
        
        if (cnt > maxCnt)
        {
            maxCnt = cnt;
        }
        
    }
    
    return maxCnt;
}

int main(){

std::vector<int>array;

    getDataAndSort(array);

int fnOutput = findSequenceCnt(array);

std::cout<<fnOutput;

    return 0;
}