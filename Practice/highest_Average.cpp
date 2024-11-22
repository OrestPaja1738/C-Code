#include <iostream>
#include <string>
#include <vector>

struct Student{

    std::string name;
    std::string surname;
    float avg;
};

void getData(std::vector<Student>& studentVector,int n){

    studentVector.resize(n);

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        int cnt = 0;
        int grade = 0;

        std::cout<<"Enter name and surname of student\n";
        std::cin>>studentVector[i].name>>studentVector[i].surname;

        while (1)
        {
            std::cout<<"Enter student grade\n";
            std::cin>>grade;

            if (grade == -1)
            {
                break;
            }
            else{
            sum += grade;
            cnt++;   
            }
        }
        
        if (cnt >= 4)
        {
            studentVector[i].avg = sum / static_cast<float>(cnt);
        }
        else{
            studentVector[i].avg = sum / 4.0;
        }
    }
}

void displayMaxInfo(std::vector<Student>& studentVector,int n){

    float max = -10000.0;
    std::string maxName;
    std::string maxSurname;

    for (int i = 0; i < n; i++)
    {
        if (studentVector[i].avg > max)
        {
            max = studentVector[i].avg;
            maxName = studentVector[i].name;
            maxSurname = studentVector[i].surname;
        }
    }


    std::cout<<maxName<<maxSurname<<max;    
}

int main(){

int n;

std::cout<<"Enter value for n\n";
std::cin>>n;

std::vector<Student>studentVector;

    getData(studentVector,n);

    displayMaxInfo(studentVector,n);

    return 0;
}