#include "hw06.h"

int main()
{
    int choice;
    int number;
    while(true)
    {
        cout << "What would you like to do" << endl;
        cout << "1. Add a book" << endl;
        cout << "2. Delete a book" << endl;
        cout << "3. Show a book" << endl;
        cout << "4. Show all books" << endl;
        cout << "5. Save and exit" << endl;

        cin >> choice;
        //ofstream fout("booksdb.txt");
        ifstream fin("booksdb.txt");
        string one, two, three, space;

        BookList *lst = nullptr;
        BookEntry *loop = nullptr;
        BookEntry *rec = nullptr;

        lst = new BookList;
        lst->r = 0;
        lst->head = nullptr;
        lst->tail = nullptr;

        while(getline(fin, one) && getline(fin, two) && getline(fin, three) && getline(fin, space))
        {
            loop = new BookEntry;
            loop ->next= nullptr;
            loop ->pre = nullptr;
            loop ->data = new BookData;
            //on first iteration the tail needs to point to null
            if(lst->head == nullptr)
            {
                lst ->head =loop;
                loop ->pre = nullptr;
            }
            else
            {
                loop ->pre = rec;
                rec ->next = loop;
            }
            lst ->tail = loop;
            rec = loop;
            rec -> data -> isbn = one;
            rec -> data -> author = two;
            rec -> data -> title = three;
            ++lst ->r;
            number = lst->r;
        }
        loop = lst ->head;
        
        if(choice == 1)
        {
            addBook(BookEntry* loop, BookList* lst);
        }
    /*
        if(choice == 2)
        {
            cout <<"There are " << number <<" books, which book would you like to delete." << endl;
            delBook(loop, lst, number);
        }
        */
        if(choice == 3)
        {
            cout << "There are " << number << " books, which book would you like to see." << endl;
            showBook(loop, number);
        }

        if(choice == 4)
        {
            showBooks(loop);
        }
        
        if(choice == 5)
        {
            break;
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
    }

    return 0;
}

