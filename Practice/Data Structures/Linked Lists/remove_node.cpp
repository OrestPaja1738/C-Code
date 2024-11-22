#include <iostream>
typedef struct Node* ptr;

struct Node
{
    int data;

    ptr next;
};

int getValue(){
    int value;
    std::cout<<"Enter value\n";
    std::cin>>value;

    return value;
}

ptr createNode(int node_data){
    
    ptr temp = new Node();
    temp->data = node_data;

    temp->next = NULL;
    return temp;
}

void createList(ptr *Head,ptr node){

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

void deleteNode(ptr *Head,int key){

    ptr current = *Head,previous = NULL;

    for (int i = 0; i <= (key - 1); i++)
    {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    delete current;
}

void printList(ptr Head){
    ptr current = Head;
    while (current != NULL)
    {
        std::cout<<current->data<<"\n";
        current = current->next;
    }
}

int main(){

ptr Head = NULL;
int n;

    while (true)
    {
        std::cout<<"Enter option\n";
        std::cin>>n;
        if (n == -1)
        {
            break;
        }
        else{
            int node_data = getValue();
            ptr node = createNode(node_data);
            createList(&Head,node);
        }
    }
    
int key;

std::cout<<"Enter which node to be deleted!\n";
std::cin>>key;

    deleteNode(&Head,key);

    printList(Head);

    return 0;
}