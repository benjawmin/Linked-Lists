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
//void delBook(BookEntry* loop, BookList* lst, int number);
void showBooks(BookEntry* loop);
void showBook(BookEntry* loop, int number);
void addBook(BookEntry* loop, BookList* lst);
