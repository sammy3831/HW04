#pragma once

#include <iostream>
#include <vector>
#include "Book.h"

using namespace std;

class BookManager
{
private:
    vector<Book*> books;

private:
    Book* findBookByTitle(const string& title, int choice);
	Book* findBookByAuthor(const string& author, int choice);

public:
    void addBook(const string& title, const string& author);
    void displayAllBooks() const;
    Book* getBookByTitle(const string& title, int choice);
    Book* getBookByAuthor(const string& author, int choice);
    ~BookManager();
};