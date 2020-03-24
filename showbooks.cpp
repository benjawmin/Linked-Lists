#include "hw06.h"

void showBooks(BookEntry* loop)
{
    while(loop != nullptr)
    {
        cout << endl << "ISBN: "<< loop ->data ->isbn;
        cout << endl << "Author: " << loop -> data ->author;
        cout << endl << "Title: " << loop ->data ->title << endl;
        loop = loop->next;
    }
    cout << endl;
}
