#include <iostream>
#include <vector>

/*
firstly - a while loop that inserts value based on an element,broken only by -1
2nd - create a basis vector
3rd - create a copy vector each for loop iteration where in the copy the value with the index
    of outer loop gets deleted
4th - with resultant vector find the product which will be saved in a final vector
*/

void getData(std::vector<int>& array){

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
}

void product_of_Array(std::vector<int>& array,std::vector<int>& outputArray){

std::cout<<"\nproduct_of_Array\n";

    for (int i = 0; i < array.size(); i++)
    {
        int product = 1;

        std::vector<int>copy = array;
        copy.erase(copy.begin() + i);

            for (int j = 0; j < copy.size(); j++)
            {
                product *= copy[j];
            }
        
        outputArray[i] = product;
    }
}

int main(){

std::vector<int>array;

    getData(array);

std::vector<int>outputArray(array.size());

    product_of_Array(array,outputArray);


for (int i = 0; i < outputArray.size(); i++) {
    std::cout << outputArray[i] << "\n";
}

    return 0;
}