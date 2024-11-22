#include <iostream>
#include <vector>

int main(){

int n;

std::cout<<"Enter value for n!\n";
std::cin>>n;

std::vector<int>arr(n);

for (int i = 0; i < n; i++)
{
    std::cout<<"Enter value of array\n";
    std::cin>>arr[i];
}

//sorting

int temp;

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {
            
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }

        }

    }
    
//seaching for index

int key,left = 0,right = n - 1,middle;
bool indexFind = false;
int indexOutput;

std::cout<<"Enter value for key!\n";
std::cin>>key;

/*Instead do binary search and indexTarget = right - left*/

while (left <= right)
{
    middle = (left + right) / 2;

    if (arr[middle] > key)
    {
        right = middle - 1;
    }
    else if (arr[middle] < key)
    {
        left = middle + 1;
    }
    else{
        indexFind = true;
        std::cout<<"Index found!\n"<<middle;
        break;
    }
}
    
    if (!indexFind) //what index the key element should be in the array if it wasnt
    {
    std::cout << "Index not found, insertion point is " << left << "\n";
    }
    
    return 0;
}