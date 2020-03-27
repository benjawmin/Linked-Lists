#pragma once

#include<iostream>
#include<fstream>

using namespace std;

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
    BookList* lst;
    BookEntry* next;
    BookEntry* pre;
    BookData* data;
};

struct BookData
{
    string isbn;
    string author;
    string title;
};

BookEntry* delBook(BookEntry* loop, BookList* lst, int number);
void showBooks(BookEntry* loop);
void showBook(BookEntry* loop, int number);
int menu();
BookEntry* addBook(BookEntry* loop, BookList* lst, BookEntry* rec);
void popList(BookEntry* loop);
