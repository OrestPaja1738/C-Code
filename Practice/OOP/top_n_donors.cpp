#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  

class Donor{

private:
    std::string Name;
    std::string Surname;
    int value;
public:
    
    Donor(std::string Name,std::string Surname,int value){
        this->Name = Name;
        this->Surname = Surname;
        this->value = value;
    }
    Donor(){
        this->Name = "Default";
        this->Surname = "Default";
        this->value = 0;
    }

    void printValue(){
        std::cout<<Name<<" "<<Surname<<" "<<value<<"\n";
    }

    //getters
    std::string getName(){
        return Name;
    }
    std::string getSurname(){
        return Surname;
    }
    int getValue(){
        return value;
    }
};

void getData(std::vector<Donor>& myObjects,int n){

    for (int i = 0; i < n; i++)
    {
        std::string donorName;
        std::string donorSurname;
        int donorValue;

        std::cout<<"Enter name surname and value\n";
        std::cin>>donorName>>donorSurname>>donorValue;
        Donor object(donorName,donorSurname,donorValue);

        myObjects.push_back(object);
    }
}

void sortObjects(std::vector<Donor>& arr){

    for (int i = 0; i < arr.size(); i++)
    {
        Donor temp;
        for (int j = (i + 1); j < arr.size(); j++)
        {
            if (arr[i].getValue() > arr[j].getValue())
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void print_m_donors(std::vector<Donor>& arr,int m){

    std::cout<<"\n";

    for (int i = arr.size() - 1; i >= arr.size() - m; i--)
    {
        arr[i].printValue();
    }
}

int main(){

int n,m;

std::cout<<"Enter value for n and m\n";
std::cin>>n>>m;

std::vector<Donor>myObjects(n);

    getData(myObjects,n);

    sortObjects(myObjects);

    print_m_donors(myObjects,m);

    return 0;
}