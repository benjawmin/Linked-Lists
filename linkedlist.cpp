#include <iostream>

    struct node
    {
        int data;
        node* next;
        node* prev;
    };

    void PrintForward(node* head)
    {
        node* temp = head;
        while(temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void PrintBackwards(node* tail)
    {
        node* temp = tail;
        while(temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->prev;
        }
    }

using namespace std;

int main()
{

    node* tail;
    node* head;
    node* n;

    n = new node;
    n->data = 1;
    //first node of prev must be NULL
    n->prev = nullptr;
    head = n;
    tail = n;

    n = new node;
    n->data = 2;
    n->prev = tail;
    //makes the first node link to the second node via the first nodes next pointer
    tail->next = n;
    tail = n;

    n = new node;
    n->data = 3;
    n->prev = tail;
    tail->next = n;
    tail = n;

    n = new node;
    n->data = 4;
    n->prev = tail;
    tail->next = n;
    tail = n;
    //last node of next must always be NULL
    tail->next = nullptr;

    //PrintForward(head);
    //PrintBackwards(tail);

    return 0;
}
