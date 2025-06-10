#include "BorrowManager.h"

unordered_map<Book*, int>::iterator BorrowManager::findBook(const string& value)
{
	if (titleMap.empty() && authorMap.empty())
	{
		cout << "책이 등록되어 있지 않습니다." << endl;
		return stock.end();
	}
	unordered_map<string, Book*>::iterator iter = titleMap.find(value);

	if (iter == titleMap.end())
	{
		iter = authorMap.find(value);
		if (iter == authorMap.end())
		{
			cout << "검색한 제목 또는 저자로 책을 찾을 수 없습니다." << endl;
			return stock.end();
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

	if (iter == stock.end())
	{
		return;
	}

	if (iter->second > 0)
	{
		iter->second--;
		cout << iter->first->title << "책을 빌렸습니다" <<  endl;
	} 
	else
	{
		cout << iter->first->title << "책이 전부 대출 중입니다" << endl;
	}
}

void BorrowManager::returnBook(const string& value)
{
	unordered_map<Book*, int>::iterator iter = findBook(value);

	if (iter == stock.end())
	{
		return;
	}

	if (iter->second < bookStockLimit)
	{
		iter->second++;
		cout << iter->first->title << "책을 반납했습니다" << endl;
	}
	else
	{
		cout << iter->first->title << "책이 이미 최대 수량입니다" << endl;
	}
}

void BorrowManager::displayStock() const
{
	if (stock.empty())
	{
		cout << "현재 등록된 책과 재고가 없습니다." << endl;
		return;
	}
	for (unordered_map<Book*, int>::const_iterator iter = stock.begin(); iter != stock.end(); iter++)
	{
		cout << "제목: " << iter->first->title << ", 저자: " << iter->first->author << ", 재고: " << iter->second  << "권" << endl;
	}
}
