#include <iostream>

using namespace std;

class Book
{
public:
    string title, author;
    double price;

    Book()
    {
        author = "unknown";
        title = "unknown";
        price = 0;
    }

    Book(string t, string a, double pr)
    {
        author = a;
        title = t;
        price = pr;
    }

    Book(const Book &other)
    {
        this->author = other.author;
        this->title = other.title;
        this->price = other.price;
    }

    ~Book() {};

    Book &operator=(const Book &other)
    {
        if (this != &other)
        {
            this->author = other.author;
            this->title = other.title;
            this->price = other.price;
        }
        return *this;
    }

    void display()
    {
        cout << "Author: " << author << endl
             << "Title: " << title << endl
             << "Price: " << price << endl;
    }
};

int main()
{
    Book b1;
    Book b2("Let us C", "Yashwant", 100);
    Book b3 = b2;

    b1.display();
    b2.display();
    b3.display();
}