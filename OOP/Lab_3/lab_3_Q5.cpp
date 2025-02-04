#include <iostream>
using namespace std;

class Book
{
private:
    long int ISBNnum;

public:
    string bookName;
    string author;
    string publisher;

    string getBookInfo() const
    {
        return "BOOK INFO: \nBook Name: " + this->bookName +
               "\nISBN #: " + to_string(this->ISBNnum) +
               "\nAuthor: " + this->author +
               "\nPublisher: " + this->publisher + "\n";
    }

    void setISBNnum(long int ISBN)
    {
        ISBNnum = ISBN;
    }

    long int getISBNnum()
    {
        return ISBNnum;
    }
};

int main()
{
    Book books[5];
    long int isbn[5];

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter details of book " << i + 1 << ":" << endl;
        cout << "Book Name: ";
        cin.ignore();
        getline(cin, books[i].bookName);
        cout << "Author: ";
        getline(cin, books[i].author);
        cout << "Publisher: ";
        getline(cin, books[i].publisher);
        cout << "ISBN #: ";
        cin >> isbn[i];
    }

    for (int i = 0; i < 5; i++)
    {
        books[i].setISBNnum(isbn[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        books[i].getBookInfo();
        cout << "\n";
    }

    return 0;
}
