#include "hw06.h"

void popList(BookEntry* loop)
{
    ofstream fout;
    fout.open("booksdb.txt");
    while(loop != nullptr)
    {
        fout << loop ->data ->isbn << endl;
        fout << loop -> data ->author << endl;
        fout << loop ->data ->title << endl;
        fout << endl;
        loop = loop->next;
    }
    cout << endl;
}
