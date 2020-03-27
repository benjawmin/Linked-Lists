#include "hw06.h"

BookEntry* delBook(BookEntry* loop, BookList* lst, int number)
{
    int num;
    int old = lst->r;
    int choose;
    string choice;
    while (true)
    {
        num = 0;
        ++lst->r;
        cin >> choose;
        if(choose == 1)
        {
            lst->head = loop->next;
            loop->next->pre = nullptr;
            --lst->r;
            ++num;
        }
        else if(choose == number)
        {
            while(loop->next != nullptr)
            {
                loop = loop->next;
            }
            lst->tail = loop->pre;
            loop->pre->next = nullptr;
            --lst->r;
            ++num;
        }
        else
        {
            lst->r = 1;
            while(lst->r < choose)
            {
                ++lst->r;
                loop = loop->next;
            }
            loop->pre->next = loop->next;
            loop->next->pre = loop->pre;
            lst->r = old-1;
            ++num;
        }
        loop = loop->next;
        if(num > 0)
        {
            cout << "Delete another y/n ";
            cin >> choice;
            if(choice == "n")
            {
                return loop;
            }
        }
    }
}
