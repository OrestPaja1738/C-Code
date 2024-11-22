#include <iostream>
#include <vector>

int main(){

int n;
std::vector<int> valueStorer(2);

std::cout<<"Enter value for n!\n";
std::cin>>n;

std::vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        std::cout<<"Enter array value\n";
        std::cin>>arr[i];
    }
    

int key,pathFinder;

std::cout<<"Enter value for key\n";
std::cin>>key;

bool pairFound = false;

    for (int i = 0; i < n; i++)
    {
        pathFinder = key - arr[i];

            for (int j = i + 1; j < n ; j++)
            {
                if (arr[j] == pathFinder)
                {
                    valueStorer[0] = i;
                    valueStorer[1] = j;
                    pairFound = true;
                    break;
                }
            }

        if (pairFound)
        {
            break;
        }
    }

    if (pairFound) {
        std::cout << "Pair found at indices: " << valueStorer[0] << " and " << valueStorer[1] << "\n";
    } else {
        std::cout << "No pair found that adds up to " << key << "\n";
    }
    

    return 0;
}