/*give input for array values,find smallest stock value and its day,then find biggest stock value
for the following days (max value) but on condition that index_day_small value < index_day_max
value 
*/

#include <iostream>
#include <vector>

void getArrayData(std::vector<int>& arr,int n){

    for (int i = 0; i < n; i++)
    {
        std::cout<<"Enter value for array\n";
        std::cin>>arr[i];
    }
}

void findMinStockPricing(std::vector<int>& arr,int n,int *x,int *y){

    *x = 10000;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < *x)
        {
            *x = arr[i];
            *y = (i + 1); //updating it with new value each time condit. satis.
        }  
    }

    //test std::cout<<"minimum value x is "<<*x<<" and minimum day index is "<<*y;
    
}

int findInvestmentDay(std::vector<int>& arr,int n,int min,int day_min){

int max = -10000;
bool cause;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max && day_min < (i + 1))
        {
            max = arr[i];
            cause = true;
        }
    }
    
    if (!cause)
    {
        std::cout<<"In this case, no transactions are done and the max profit = 0\n";
        return 0;
    }
    

    return (max - min);
}


int main(){

int n;
int min,day_index_small_value;

std::cout<<"Enter value for n\n";
std::cin>>n;

std::vector<int>prices(n);

getArrayData(prices,n);

findMinStockPricing(prices,n,&min,&day_index_small_value);

int output = findInvestmentDay(prices,n,min,day_index_small_value);

std::cout<<output;

    return 0;
}