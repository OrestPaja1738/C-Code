#include <iostream>
#include <vector>
#include <unordered_set>

/*
Standard array.Use nested for loop. K is most important and another vector is needed to save
most repeated (based on k) array values. first : if arr[i] == arr[j] -> cnt ++ -> if cnt == k
->save value on special array
*/

void getData(std::vector<int>& array,int n){

    for (int i = 0; i < n; i++)
    {
        std::cin>>array[i];
    }
    
}

void checkForDuplicates(const std::vector<int>& arr,int n,int k){

std::unordered_set<int>output;
std::vector<int>result;

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                cnt++;
            }
            
        }
        if (cnt >= k && output.find(arr[i]) == output.end())
        {
            output.insert(arr[i]); //inserts the element of array into output in order for it to not be unique anymore
            result.push_back(arr[i]);
        } 
    }
    
    for (const int&val :result)
    {
        std::cout<<val<<"\n";
    }
        
}

int main(){

int n,k;
std::cin>>n>>k;

std::vector<int>array(n);

    getData(array,n);

    checkForDuplicates(array,n,k);

    return 0;
}
