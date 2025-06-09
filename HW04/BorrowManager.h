#pragma once

#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>
#include "Book.h"

using namespace std;

class BorrowManager
{
private:
	unordered_map<Book*, int> stock;
	unordered_map<string, Book*> titleMap;
	unordered_map<string, Book*> authorMap;
	int bookStockLimit = 3;

private:
	unordered_map<Book*, int>::iterator findBook(const string& value);

public:
	void initializeStock(Book* book, int quantity = 3);
	void borrowBook(const string& title);
	void returnBook(const string& title);
	void displayStock() const;

};