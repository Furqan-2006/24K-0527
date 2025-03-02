#include <iostream>
#include <vector>
using namespace std;

class Book
{
public:
    string title;
    string author;
    string isbn;

    Book(string t, string a, string i) : title(t), author(a), isbn(i) {}

    void display() const
    {
        cout << "Book: " << title << " by " << author << " (ISBN: " << isbn << ")\n";
    }
};

class Catalog
{
private:
    vector<Book *> bookIndex;

public:
    void addBook(Book *book)
    {
        bookIndex.push_back(book);
    }

    Book *findBook(string isbn)
    {
        for (Book *book : bookIndex)
        {
            if (book->isbn == isbn)
                return book;
        }
        return nullptr;
    }

    void displayCatalog() const
    {
        cout << "Library Catalog:\n";
        for (Book *book : bookIndex)
        {
            book->display();
        }
    }
};

class Library
{
private:
    string name;
    string address;
    Catalog catalog;
    vector<Book *> books;

public:
    Library(string n, string a) : name(n), address(a)
    {
        cout << "Library \"" << name << "\" created at " << address << ".\n";
    }

    void addBook(Book *book)
    {
        books.push_back(book);
        catalog.addBook(book);
    }

    void findBookInCatalog(string isbn)
    {
        Book *book = catalog.findBook(isbn);
        if (book)
        {
            cout << "Book found in catalog: ";
            book->display();
        }
        else
        {
            cout << "Book with ISBN " << isbn << " not found in catalog.\n";
        }
    }

    void displayLibraryBooks() const
    {
        cout << "\nBooks available in \"" << name << "\" Library:\n";
        for (Book *book : books)
        {
            book->display();
        }
    }
};

int main()
{

    Book book1("1984", "George Orwell", "123456789");
    Book book2("Brave New World", "Aldous Huxley", "987654321");
    Book book3("Fahrenheit 451", "Ray Bradbury", "111213141");

    Library myLibrary("Central Library", "123 Main St");

    myLibrary.addBook(&book1);
    myLibrary.addBook(&book2);

    myLibrary.displayLibraryBooks();

    myLibrary.findBookInCatalog("123456789");
    myLibrary.findBookInCatalog("111213141");

    Library branchLibrary("Branch Library", "456 Side St");
    branchLibrary.addBook(&book2);
    branchLibrary.addBook(&book3);

    branchLibrary.displayLibraryBooks();

    return 0;
}
