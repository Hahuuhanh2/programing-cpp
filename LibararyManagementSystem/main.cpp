#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <cctype>
using namespace std;

struct Book
{
    string title;
    string author;
    int year;
};

class Library
{
private:
    vector<Book> books;
public:

    bool isEqualIgnoreCase(const string& str1, const string& str2)
    {
        if(str1.length() != str2.length())
        {
            return false;
        }
        for(size_t i = 0; i <str1.length(); i++)
        {
            if(towlower(str1[i]) != towlower(str2[i]))
            {
                return false;
            }
        }
        return true;
    }
    void addBook(const Book& book)
    {
        books.push_back(book);
    }

    void deleteBook(const string& title)
    {
        for(auto it = books.begin(); it != books.end(); ++it)
        {
            if(isEqualIgnoreCase(it->title, title))
            {
                books.erase(it);
                break;
            }
        }
    }

    void displayBooks()
    {
        for(const auto& book : books )
        {
            cout <<"Title  : " << book.title << endl;
            cout <<"Author : " << book.author << endl;
            cout <<"Year   : " << book.year << endl;
            cout << "-----------------------" << endl;
        }
    }
};

int main()
{
    Library library;
    bool exitProgram = false;

    while (!exitProgram)
    {
        cout << "1. Add book to library" << endl;
        cout << "2. Delete book from library" << endl;
        cout << "3. Display library" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
        {
            cout << "Enter book details: " << endl;
            Book book;
            cout << "Title: ";
            getline(cin, book.title);
            cout << "Author: ";
            getline(cin, book.author);
            cout << "Year: ";
            cin >> book.year;
            cin.ignore();

            library.addBook(book);
            cout << "Book added to library." << endl;
            break;
        }
        case 2:
        {
            cout << "Enter the title of the book to delete: ";
            string bookTitle;
            getline(cin, bookTitle);

            library.deleteBook(bookTitle);
            cout << "Book deleted from library." << endl;
            break;
        }
        case 3:
        {
            cout << "Library contents:" << endl;
            library.displayBooks();
            break;
        }
        case 0:
        {
            exitProgram = true;
            break;
        }
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }

        cout << endl;
    }

    return 0;
}
