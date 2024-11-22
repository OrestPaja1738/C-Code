#include <iostream>
#include <string>
#include <stack>

class Package{
private:
    int code;
    float weight;
    std::string address;
public:
    Package(int code,float weight,std::string address){
        this->code = code;
        this->weight = weight;
        this->address = address;
    }
};

class package_information{
private:
    int package_code;
    float package_weight;
    std::string address;
public:
    package_information(int package_code,float package_weight,std::string address){
        this->package_code = package_code;
        this->package_weight = package_weight;
        this->address = address;
    }
    void printValues(){
        std::cout<<package_code<<" "<<package_weight<<" "<<address;
    }
};

void getData(std::stack<Package>& myPackages,std::stack<package_information>& storer){

    int n;

    while (true)
    {
        std::cout<<"Enter input\n";
        std::cin>>n;
        switch (n)
        {
        case 1://adding package
            int code;
            float weight;
            std::string address;
            std::cout<<"Enter code , weight and address!\n";
            std::cin>>code>>weight>>address;

            Package myPackage(code,weight,address);
            myPackages.push(myPackage);

            package_information information(code,weight,address);
            storer.push(information);
            break;
        case -1://deliver aka delete
            if (myPackages.size() == 0)
            {
                std::cout<<"There aren´t any packages to be ordered!\n";
                break;
            }
            else{
                myPackages.pop();
                storer.pop();
            }
            break;
        case 2://print current packages
            if (myPackages.size() == 0)
            {
                std::cout<<"There are no packages left to be displayed!\n";
                break;
            }
            else{
                while (!storer.empty())
                {
                    package_information temp = storer.top();
                    temp.printValues();
                    storer.pop();
                }   
            }
            break;
        case 0:
            return;
        default:
            break;
        }
    }
} 

int main(){

std::stack<Package>myPackages;
std::stack<package_information>storer;

    getData(myPackages,storer);

/*
Could be optimised better with having only one class and two objects from same class
the one responsible for printing will be estabilished only in case 2

getters and setters...
*/
    return 0;
}