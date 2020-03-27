#include "hw06.h"

int menu()
{
    int choice;
    cout << "What would you like to do" << endl;
    cout << "1. Add a book" << endl;
    cout << "2. Delete a book" << endl;
    cout << "3. Show a book" << endl;
    cout << "4. Show all books" << endl;
    cout << "5. Save and exit" << endl;
    cin >> choice;

    return choice;
}
