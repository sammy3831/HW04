#include "BorrowManager.h"

unordered_map<Book*, int>::iterator BorrowManager::findBook(const string& value)
{
	unordered_map<string, Book*>::iterator iter = titleMap.find(value);

	if (iter == titleMap.end())
	{
		iter = authorMap.find(value);
		if (iter == authorMap.end())
		{
			cout << "책을 찾을 수 없습니다." << endl;
		}
	}
	unordered_map<Book*, int>::iterator iter2 = stock.find(iter->second);

	return iter2;
}

void BorrowManager::initializeStock(Book* book, int quantity)
{
	stock.insert({ book, quantity });
	titleMap.insert({ book->title, book });
	authorMap.insert({ book->author, book });
}

void BorrowManager::borrowBook(const string& value)
{
	unordered_map<Book*, int>::iterator iter = findBook(value);

	if (iter->second > 0)
	{
		iter->second--;
		cout << "책을 빌렸습니다:" << iter->first->title << endl;
	} 
	else
	{
		cout << "책이 전부 대출 중입니다:" << iter->first->title << endl;
	}
}

void BorrowManager::returnBook(const string& value)
{
	unordered_map<Book*, int>::iterator iter = findBook(value);

	if (iter->second < bookStockLimit)
	{
		iter->second++;
		cout << "책을 반납했습니다:" << iter->first->title << endl;
	}
	else
	{
		cout << "책이 이미 최대 수량입니다:" << iter->first->title << endl;
	}
}

void BorrowManager::displayStock() const
{
	for (unordered_map<Book*, int>::const_iterator iter = stock.begin(); iter != stock.end(); iter++)
	{
		cout << "제목: " << iter->first->title << ", 저자: " << iter->first->author << ", 재고: " << iter->second  << "권" << endl;
	}
}
