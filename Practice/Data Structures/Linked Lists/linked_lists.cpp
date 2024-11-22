#include <iostream>

typedef struct Node* ptr;

struct Node
{
    int data;
    ptr next;
};


int main(){

    ptr Head = NULL;
    int n,cnt = 0;

    std::cin>>n;

    while (1)
    {
        if (n == cnt)
        {
            break;
        }
        else{
        ptr newNode = new Node();
        if (Head == NULL)
        {
            Head = newNode;
            newNode->next = NULL;
        }
        else{
            ptr temp = Head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = NULL;
        }
        }

        cnt++;
    }
    
    return 0;
}