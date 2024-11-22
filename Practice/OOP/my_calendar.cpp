#include <iostream>
#include <vector>
#include <string>

/*
vector of objects and each object has a size 2 array as an attribute
public methods - beside constructor i need a method that initialises a range
based on values [0] and [1] of attribute
*/

class MyCalendar{

private:
    int checkIn;
    int checkOut;
public:
        MyCalendar(int checkIn,int checkOut){
            this->checkIn = checkIn;
            this->checkOut = checkOut;
        }
    
    std::vector<int>dates_of_stay;

        void create_list(){
            dates_of_stay[0] = checkIn;
            for (int i = 1; i < (checkOut - checkIn) ; i++)
            {
                dates_of_stay[i] = dates_of_stay[0]++;
            }
        }
};

void getData(std::vector<MyCalendar>& myObjects){

    int n;

    while (1)
    {
        int objValue1,objValue2;
        std::cin>>n;
        if (n == -1)
        {
            break;
        }
        else{
            std::cout<<"Enter check in and check out date\n";
            std::cin>>objValue1>>objValue2;
            MyCalendar booking(objValue1,objValue2);
            myObjects.push_back(booking);
        }
    }
}

void initialise_list_data(std::vector<MyCalendar>& myObjects){
    for (int i = 0; i < myObjects.size(); i++)
    {
        myObjects[i].create_list();
    }
}

bool getStatus(std::vector<MyCalendar>& myObjects){
    
    for (int i = 0; i < myObjects[0].dates_of_stay.size(); i++)
    {
        int key = myObjects[0].dates_of_stay[i];
        int cnt = i++;
        for (int j = (i + 1); j < myObjects[cnt].size(); i++)
        {
            /* quit at this point*/
        }          
    }
}

int main(){

std::vector<MyCalendar>myObjects;

    getData(myObjects);

    initialise_list_data(myObjects);

std::vector<bool>bookingStatus(myObjects.size());

bookingStatus[0] = true;

    for (int i = 1; i < bookingStatus.size(); i++)
    {
        bookingStatus[i] = getStatus(myObjects);
    }
    
//Prolly will be left unfinished
    return 0;
}