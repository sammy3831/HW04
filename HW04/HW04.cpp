#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book
{
public:
    string title;
    string author;

    Book(const string& title, const string& author)
        : title(title), author(author) {
    }
};

class BookManager
{
private:
    vector<Book> books;

public:
    void addBook(const string& title, const string& author)
    {
        books.push_back(Book(title, author));
        cout << "책이 추가되었습니다: " << title << " by " << author << endl;
    }

    void displayAllBooks() const
    {
        if (books.empty())
        {
            cout << "현재 등록된 책이 없습니다." << endl;
            return;
        }

        cout << "현재 도서 목록:" << endl;
        for (size_t i = 0; i < books.size(); i++)
        {
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }
    void searchByTitle(const string& title)
    {
        if (books.empty())
        {
            cout << "현재 등록된 책이 없습니다." << endl;
            return;
		}

        for (size_t i = 0; i < books.size(); i++)
        {
            if (books[i].title == title)
            {
                cout << "책 제목:" << books[i].title << " by " << books[i].author << endl;
                return;
            }
		}
		cout << title << " 제목의 책이 없습니다." << endl;
    }
    void searchByAuthor(const string& author)
	{
        if (books.empty())
        {
            cout << "현재 등록된 책이 없습니다." << endl;
            return;
		}

		for (size_t i = 0; i < books.size(); i++)
		{
			if (books[i].author == author)
			{
				cout << "책 저자:" << books[i].author << "의 책 제목은 " << books[i].title << "입니다." << endl;
                return;
			}
		}
		cout << author << " 저자와 관련된 책이 없습니다." << endl;
	}
};

int main()
{
    BookManager manager;
	bool isRunning = true;

    // 도서관 관리 프로그램의 기본 메뉴를 반복적으로 출력하여 사용자 입력을 처리합니다.
    // 프로그램 종료를 선택하기 전까지 계속 동작합니다.
    while (isRunning)
    {
        cout << "\n도서관 관리 프로그램" << endl;
        cout << "1. 책 추가" << endl;
        cout << "2. 모든 책 출력" << endl;
		cout << "3. 제목으로 책 검색" << endl;
		cout << "4. 저자로 책 검색" << endl;
        cout << "5. 종료" << endl;
        cout << "선택: ";

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            string title, author;
            cout << "책 제목: ";
            cin.ignore();
            getline(cin, title);
            cout << "책 저자: ";
            getline(cin, author);
            manager.addBook(title, author);
        }
        else if (choice == 2)
        {
            manager.displayAllBooks();
        }
        else if (choice == 3)
        {
            string title;
            cout << "검색할 책 제목: ";
            cin.ignore();
            getline(cin, title);
            manager.searchByTitle(title);
        }
        else if (choice == 4)
        {
            string author;
            cout << "검색할 저자명: ";
            cin.ignore();
            getline(cin, author);
            manager.searchByAuthor(author);
		}
        else if (choice == 5)
        {
            cout << "프로그램을 종료합니다." << endl;
            isRunning = false;
        }
        else
        {
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
			cin.clear();
            cin.ignore();
        }
    }

    return 0;
}
