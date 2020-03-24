#include "hw06.h"

void showBook(BookEntry* loop, int number)
{
    int equality=0;
    int choose;
    cin >> choose;
    while(true)
    {
        ++equality;
        if(choose == equality)
        {
            cout << endl << "ISBN: "<< loop ->data ->isbn;
            cout << endl << "Author: " << loop -> data ->author;
            cout << endl << "Title: " << loop ->data ->title << endl;
            break;
        }
        loop = loop->next;
    }
    cout << endl;
}
