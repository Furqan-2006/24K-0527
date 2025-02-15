#include <iostream>

using namespace std;

class Book
{
    string author, title, publisher;
    double price;
    int stock;

public:
    Book(string a, string t, double pr, string pub, int s) : author(a), title(t), price(pr), publisher(pub), stock(s) {};

    bool searchBook(string t, string a)
    {
        return (title == t && author == a);
    }
    void showBook()
    {

        cout << "Title: " << title << "\nAuthor: " << author << "\nPublisher: " << publisher << "\nPrice: $" << price << "\nStock: " << stock << "copies available" << endl;
    }
    void buyBook(int copies)
    {
        if (copies > stock)
        {
            cout << "Insufficient Amount! stock available: " << stock << " copies." << endl;
        }
        else
        {
            cout << "Total cost: $" << price * copies << endl;
            stock -= copies;
        }
    }
};

int main()
{
    Book books[] = {
        Book("Paulo Coelho", "The Alchemist", 12.99, "HarperOne", 10),
        Book("George Orwell", "1984", 9.99, "Penguin", 5),
        Book("Harper Lee", "To Kill a Mockingbird", 14.99, "J.B. Lippincott & Co.", 2)};

    string title, author;
    cout << "Enter the title and author of book." << "\nTitle: ";
    cin.ignore();
    getline(cin, title);
    cout << "Author: ";
    getline(cin, author);

    bool found = false;
    for (Book &b : books)
    {
        if (b.searchBook(title, author))
        {
            found = true;
            b.showBook();
            int copies;
            cout << "Enter the number of copies to buy: ";
            cin >> copies;
            b.buyBook(copies);
            break;
        }
    }
    if (!found)
    {
        cout << "Book Unavailable!" << endl;
    }

    return 0;
}