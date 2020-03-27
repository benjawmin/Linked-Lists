#include "hw06.h"

BookEntry* addBook(BookEntry* loop, BookList* lst, BookEntry* rec)
{
    while (true)
    {
        string choice;
        loop = new BookEntry;
        loop->next= nullptr;
        loop->pre = nullptr;
        loop->data = new BookData;
        if(lst->head == nullptr)
        {
            lst->head =loop;
            loop->pre = nullptr;
        }
        else
        {
            loop->pre = rec;
            rec->next = loop;
        }
        lst->tail = loop;
        rec = loop;
        ++lst->r;
        cout << "ISBN: ";
        cin >> rec->data->isbn;
        cout << "Author: ";
        cin >> rec->data->author;
        cout << "Title: ";
        cin >> rec->data->title;
        cout << "Add another? y/n ";
        cin >> choice;
        if(choice == "n")
        {
            //loop = lst->head;
            return loop;
        }
    }
}

