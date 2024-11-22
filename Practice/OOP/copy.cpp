#include <iostream>
#include <vector>
#include <queue>

class Order{
private:
    int ID;
    int totalPrice;
public:
    Order(int ID,int totalPrice){
        this->ID = ID;
        this->totalPrice = totalPrice;
    }
};

class Holder{
private:
    int storedID;
    int stored_total_price;
public:
    Holder(int storedID,int stored_total_price){
        this->storedID = storedID;
        this->stored_total_price = stored_total_price;
    }
    void print_stored_values(){
        std::cout<<"\n";
        std::cout<<storedID<<" "<<stored_total_price;
        std::cout<<"\n";
    }
};

void getData(std::queue<Order>& myOrders,std::queue<Holder>& order_storer){
    
    int n;

    while (true)
    {
        std::cout<<"Enter value!\n";
        std::cin>>n;
        if (n == 1) //adding order
        {
            int id,totalPrice;
            std::cout<<"Enter id and total price\n";
            std::cin>>id>>totalPrice;
            Order order(id,totalPrice);
            myOrders.push(order);

            Holder storer(id,totalPrice);
            order_storer.push(storer);
        }
        else if (n == -1)
        {
            if (myOrders.size() == 0)
            {
                std::cout<<"There aren't any orders left that can be deleted!\n";
                break;
            }
            else{
                myOrders.pop();
            }
        }
        else if (n == 2)
        {
            if (order_storer.size() == 0)
            {
                std::cout<<"There are no orders to be displayed!\n";
            }
            else{
                
            }
        }
        else{
            break;
        }
    }
} 

int main(){

std::queue<Order>myOrders;
std::queue<Holder>order_storer;
    getData(myOrders,order_storer);

    return 0;
}