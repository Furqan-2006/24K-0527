#include <iostream>
using namespace std;

class Books
{
protected:
    string genre;

public:
    Books(string g) { genre = g; };
    virtual void showDetails() = 0;
};

class Novel : public Books
{
protected:
    string title, author;

public:
    Novel(string t, string a) : Books("Novel")
    {
        title = t;
        author = a;
    }
    void showDetails() override
    {
        cout << "Title: " << title << endl
             << "Author: " << author << endl
             << "Genre: " << genre << endl;
    }
};

class StoryBook : public Books
{
protected:
    string title, author;

public:
    StoryBook(string t, string a) : Books("Story Book")
    {
        title = t;
        author = a;
    }
    void showDetails() override
    {
        cout << "Title: " << title << endl
             << "Author: " << author << endl
             << "Genre: " << genre << endl;
    }
};

int main()
{
    Novel book1("Pride and Prejudice", "Jane Austen");
    StoryBook book2("The BOT: Robot life", "John Hilton");

    book1.showDetails();
    book2.showDetails();
    return 0;
}