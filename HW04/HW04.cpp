#include "BookManager.h"
#include "BorrowManager.h"

using namespace std;

int main()
{
    BookManager manager;
	BorrowManager borrowManager;
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
        cout << "5. 책 대여" << endl;
        cout << "6. 책 반납" << endl;
        cout << "7. 재고 현황 출력" << endl;
        cout << "8. 종료" << endl;
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
			Book* book = manager.getBookByTitle(title, choice);
            borrowManager.initializeStock(book);
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
            manager.getBookByTitle(title, choice);
        }
        else if (choice == 4)
        {
            string author;
            cout << "검색할 저자명: ";
            cin.ignore();
            getline(cin, author);
            manager.getBookByAuthor(author, choice);
		}
        else if (choice == 5)
        {
            string title;
            cout << "대여할 책 제목 또는 저자: ";
            cin.ignore();
            getline(cin, title);
            borrowManager.borrowBook(title);
        }
        else if (choice == 6)
        {
            string author;
            cout << "반납할 책 제목 또는 저자: ";
            cin.ignore();
            getline(cin, author);
            borrowManager.returnBook(author);
        }
        else if (choice == 7)
        {
            borrowManager.displayStock();
		}
        else if (choice == 8)
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
