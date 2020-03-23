#include "hw06.h"

typedef struct BookList BookList;
typedef struct BookEntry BookEntry;
typedef struct BookData BookData;

struct BookList
{
    int r;
    BookEntry* head;
    BookEntry* tail;
};

struct BookEntry
{
    BookList* list;
    BookEntry* next;
    BookEntry* pre;
    BookData* data;
};

struct BookData
{
    string isdn;
    string author;
    string title;
};

int main()
{
    ifstream fin("booksdb.txt");
    string one, two, three, space;

    BookList *list = nullptr;
    BookEntry *loop = nullptr;
    BookEntry *rec = nullptr;

    list = new BookList;
    list->r = 0;
    list->head = nullptr;
    list->tail = nullptr;

    int i = 0;
    cout << i << endl;

    while(getline(fin, one) && getline(fin, two) && getline(fin, three) && getline(fin, space))
    {
	++i;
	cout<<i<<endl;

	loop = new BookEntry;
	loop ->next= nullptr;
        loop ->pre = nullptr;
	loop ->data = new BookData;
	//on first iteration the tail needs to point to null
	if(list->head == nullptr)
	{
	    list ->head =loop;
	    loop ->pre = nullptr;
	}
        else
	{
	    loop ->pre = rec;
	    rec ->next = loop;
	}
	list ->tail = loop;
	rec = loop;
	rec -> data -> isdn = one;
	rec -> data -> author = two;
	rec -> data -> title = three;
	++list ->r;
    }
    loop = list ->head;

    while(loop != nullptr)
    {
	cout << endl << "Isdn: "<< loop ->data ->isdn;
	cout << endl << "Author: " << loop -> data ->author;
	cout << endl << "Title: " << loop ->data ->title << endl;
	loop = loop->next;
    }

    loop = list -> head;
    BookEntry *todel = loop;
    while(loop)
    {
	loop = loop ->next;
	delete todel ->data;
	delete todel;
	todel = loop;
    }
    delete list;

    return 0;
}


