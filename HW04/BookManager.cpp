#include "BookManager.h"

Book* BookManager::findBookByTitle(const string& title, int choice)
{
	if (books.empty())
	{
		cout << "현재 등록된 책이 없습니다." << endl;
		return nullptr;
	}

	for (size_t i = 0; i < books.size(); i++)
	{
		if (books[i]->title == title)
		{
			if (choice == 3)
			{
				cout << "책 제목:" << books[i]->title << " by " << books[i]->author << endl;
			}
			return books[i];
		}
	}
	cout << title << " 제목의 책이 없습니다." << endl;
	return nullptr;
}

Book* BookManager::findBookByAuthor(const string& author, int choice)
{
	if (books.empty())
	{
		cout << "현재 등록된 책이 없습니다." << endl;
		return nullptr;
	}

	for (size_t i = 0; i < books.size(); i++)
	{
		if (books[i]->author == author)
		{
			if (choice == 4)
			{
				cout << "책 저자:" << books[i]->author << "의 책 제목은 " << books[i]->title << "입니다." << endl;
			}
			return books[i];
		}
	}
	cout << author << " 저자와 관련된 책이 없습니다." << endl;
	return nullptr;
}

void BookManager::addBook(const string& title, const string& author)
{
	Book* newBook = new Book(title, author);
	books.push_back(newBook);
	cout << "책이 추가되었습니다: " << title << " by " << author << endl;
}

void BookManager::displayAllBooks() const
{
	if (books.empty())
	{
		cout << "현재 등록된 책이 없습니다." << endl;
		return;
	}

	cout << "현재 도서 목록:" << endl;
	for (size_t i = 0; i < books.size(); i++)
	{
		cout << "- " << books[i]->title << " by " << books[i]->author << endl;
	}
}

Book* BookManager::getBookByTitle(const string& title, int choice)
{
    return findBookByTitle(title, choice);
}

Book* BookManager::getBookByAuthor(const string& author, int choice)
{
    return findBookByAuthor(author, choice);
}

BookManager::~BookManager()
{
	for (size_t i = 0; i < books.size(); i++)
	{
		delete books[i];
	}
	books.clear();
}
