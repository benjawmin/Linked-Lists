#include "hw06.h"

int main()
{
    int choice;
    int number;
    ifstream fin("booksdb.txt");
    string one, two, three, space;

    BookList *lst = nullptr;
    BookEntry *loop = nullptr;
    BookEntry *rec = nullptr;

    lst = new BookList;
    lst->r = 0;
    lst->head = nullptr;
    lst->tail = nullptr;

    while(true)
    {
        choice = menu();
        int counter = 0;
        while(getline(fin, one) && getline(fin, two) && getline(fin, three) && getline(fin, space) && counter ==0)
        {
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
                loop ->pre = rec;
                rec ->next = loop;
            }
            lst->tail = loop;
            rec = loop;
            rec->data->isbn = one;
            rec->data->author = two;
            rec->data->title = three;
            ++lst->r;
        }
        loop = lst->head;
        ++counter;
        number = lst->r;

        if(choice == 1)
        {
            loop = addBook(loop, lst, rec);
        }
        if(choice == 2)
        {
            cout <<"There are " << lst->r <<" books, which book would you like to delete." << endl;
            delBook(loop, lst, number);
        }
        if(choice == 3)
        {
            cout << "There are " << lst->r << " books, which book would you like to see." << endl;
            showBook(loop, number);
        }
        if(choice == 4)
        {
            showBooks(loop);
        }
        if(choice == 5)
        {
            popList(loop);
            break;
        }
    }
    BookEntry *todel = loop;
    while(loop)
    {
        loop = loop ->next;
        delete todel ->data;
        delete todel;
        todel = loop;
    }
    delete lst;

    return 0;
}
