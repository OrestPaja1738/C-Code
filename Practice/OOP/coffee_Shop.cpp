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

    int get_ID() const{
        return ID;
    }
    int get_total_price() const{
        return totalPrice;
    }
};

void getData(std::queue<Order>& myOrders){
    
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
        }
        else if (n == -1)//deleting order
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
        else if (n == 2)//displaying orders
        {
            if (myOrders.size() == 0)
            {
                std::cout<<"There are no orders to be displayed!\n";
            }
            else{
                std::cout<<"List of ORDERS:\n";
                while (!myOrders.empty())
                {
                    Order obj = myOrders.front();
                    std::cout<<obj.get_ID()<<" "<<obj.get_total_price();
                    std::cout<<"\n";
                    myOrders.pop();
                }
                std::cout<<"\n";
            }
        }
        else{
            break;
        }
    }
} 

int main(){

std::queue<Order>myOrders;
    getData(myOrders);

    return 0;
}