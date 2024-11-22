#include <iostream>
#include <string>
typedef struct Employee* ptr;

struct Employee
{
    std::string name;
    float salary;//hourly wage
    float paycheck;

    ptr next;
};

ptr Head;

ptr createNode(std::string temp_name,float temp_salary,float hours){

    ptr node = new Employee();
    node->name = temp_name;
    node->salary = temp_salary;
    
    if (hours > 40)
    {
        float overtime_hours = hours - 40;

        node->paycheck = (40 * node->salary) + (overtime_hours * (1.5 * node->salary));
    }
    else{
        node->paycheck = node->salary * hours;
    }
    
    node->next = NULL;
    return node;
}

void linkNode(ptr *Head,ptr node){

    if (*Head == NULL)
    {
        *Head = node;
    }
    else{
        ptr temp = *Head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node;
    }
}

void printPaychecks(ptr Head){

    ptr current = Head;

    while (current != NULL)
    {
        std::cout<<current->name<<" "<<current->paycheck<<"\n";
        current = current->next;
    }
}

int main(){

int n;
Head = NULL;

    while (true)
    {
        std::cout<<"Enter n\n";
        std::cin>>n;

        if (n == -1 || n == 0)
        {
            break;
        }
        else{
            std::string temp_name;
            float temp_salary,hours;
            std::cout<<"Enter name salary hours\n";
            std::cin>>temp_name>>temp_salary>>hours;

            ptr node = createNode(temp_name,temp_salary,hours);
            linkNode(&Head,node); 
        }
    }

    printPaychecks(Head);
    
    return 0;
}