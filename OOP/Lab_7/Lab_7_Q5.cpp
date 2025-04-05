#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Media
{
protected:
    string title;
    string publicationDate;
    string uniqueID;
    string publisher;

public:
    Media(string t, string p, string id, string pub) : title(t), publicationDate(p), uniqueID(id), publisher(pub) {}
    string getPublicationDate() const { return publicationDate; }
    string getTitle() const { return title; }

    virtual void displayInfo()
    {
        cout << "Title: " << title << endl
             << "Publication Date: " << publicationDate << endl
             << "Publisher: " << publisher << endl;
    }

    virtual void checkout(string title)
    {
        cout << title << " has been asked for lending." << endl;
        cout << "Enter 'Y' to proceed..." << endl;
        char opt;
        cin >> opt;
        switch (opt)
        {
        case 'Y':
        case 'y':
            cout << "Lending procedure in progress..." << endl;
            cout << title << " checked out for the user." << endl;
            break;
        default:
            cout << "Lending process has been cancelled!" << endl;
            cout << title << " has been sent back to the stock!" << endl;
            break;
        }
    }

    virtual void returnItem(string title)
    {
        cout << "User returned the " << title << endl;
        cout << "Adding the returned item to stock" << endl;
    }
};

// Book Class
class Book : public Media
{
private:
    string author;
    int numOfPages;
    string ISBN;

public:
    Book(string t, string p, string id, string pub, string a, int np, string isbn)
        : Media(t, p, id, pub), author(a), numOfPages(np), ISBN(isbn) {}

    void displayInfo() override
    {
        Media::displayInfo();
        cout << "Author: " << author << endl
             << "Number of Pages: " << numOfPages << endl
             << "ISBN: " << ISBN << endl;
    }
};

// DVD Class
class DVD : public Media
{
private:
    string director;
    float duration;
    float rating;

public:
    DVD(string t, string p, string id, string pub, string dir, float dur, float rat)
        : Media(t, p, id, pub), director(dir), duration(dur), rating(rat) {}

    void displayInfo() override
    {
        Media::displayInfo();
        cout << "Director: " << director << endl
             << "Duration: " << duration << " mins" << endl
             << "Rating: " << rating << "/10" << endl;
    }
};

// CD Class
class CD : public Media
{
private:
    string artist;
    int numOfTracks;
    string genre;

public:
    CD(string t, string p, string id, string pub, string a, int nt, string g)
        : Media(t, p, id, pub), artist(a), numOfTracks(nt), genre(g) {}

    void displayInfo() override
    {
        Media::displayInfo();
        cout << "Artist: " << artist << endl
             << "Number of Tracks: " << numOfTracks << endl
             << "Genre: " << genre << endl;
    }
};

// Magazine Class
class Magazine : public Media
{
private:
    string editor;
    int issueNumber;

public:
    Magazine(string t, string p, string id, string pub, string e, int iNum)
        : Media(t, p, id, pub), editor(e), issueNumber(iNum) {}

    void displayInfo() override
    {
        Media::displayInfo();
        cout << "Editor: " << editor << endl
             << "Issue Number: " << issueNumber << endl;
    }
};
vector<Media *> library;
int extractYear(string date)
{
    return stoi(date.substr(0, 4));
}

void searchMedia(const string &title)
{
    cout << "\nSearching by Title: " << title << endl;
    for (Media *item : library)
    {
        Book *b = dynamic_cast<Book *>(item);
        DVD *d = dynamic_cast<DVD *>(item);
        CD *c = dynamic_cast<CD *>(item);
        Magazine *m = dynamic_cast<Magazine *>(item);

        if (item->getTitle() == title)
        {
            item->displayInfo();
            cout << "------------------------\n";
            return;
        }
    }
    cout << "No item with title \"" << title << "\" is found!" << endl;
}

void searchMedia(const string &author, bool isAuthor)
{
    if (!isAuthor)
        return;
    cout << "\nSearching Books by Author: " << author << endl;
    for (Media *item : library)
    {
        Book *b = dynamic_cast<Book *>(item);
        if (b)
        {
            b->displayInfo();
            cout << "------------------------\n";
        }
    }
}

void searchMedia(int year)
{
    cout << "\nSearching by Publication Year: " << year << endl;
    for (Media *item : library)
    {
        int y = extractYear(item->getPublicationDate());
        if (y == year)
        {
            item->displayInfo();
            cout << "------------------------\n";
        }
    }
}
int main()
{
    vector<Media *> library;
    int choice;

    do
    {
        cout << "\n--- Digital Library Menu ---\n";
        cout << "1. Add Book\n";
        cout << "2. Add DVD\n";
        cout << "3. Add CD\n";
        cout << "4. Add Magazine\n";
        cout << "5. Search Media\n";
        cout << "6. Checkout Item\n";
        cout << "7. Return Item\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            string title, date, id, pub, author, isbn;
            int pages;
            cout << "Enter Book Title: ";
            getline(cin, title);
            cout << "Enter Publication Date (YYYY-MM-DD): ";
            getline(cin, date);
            cout << "Enter Unique ID: ";
            getline(cin, id);
            cout << "Enter Publisher: ";
            getline(cin, pub);
            cout << "Enter Author: ";
            getline(cin, author);
            cout << "Enter Number of Pages: ";
            cin >> pages;
            cin.ignore();
            cout << "Enter ISBN: ";
            getline(cin, isbn);
            library.push_back(new Book(title, date, id, pub, author, pages, isbn));
            cout << "Book added!\n";
        }
        else if (choice == 2)
        {
            string title, date, id, pub, director;
            float duration, rating;
            cout << "Enter DVD Title: ";
            getline(cin, title);
            cout << "Enter Publication Date: ";
            getline(cin, date);
            cout << "Enter Unique ID: ";
            getline(cin, id);
            cout << "Enter Publisher: ";
            getline(cin, pub);
            cout << "Enter Director: ";
            getline(cin, director);
            cout << "Enter Duration (in mins): ";
            cin >> duration;
            cout << "Enter Rating (out of 10): ";
            cin >> rating;
            cin.ignore();
            library.push_back(new DVD(title, date, id, pub, director, duration, rating));
            cout << "DVD added!\n";
        }
        else if (choice == 3)
        {
            string title, date, id, pub, artist, genre;
            int tracks;
            cout << "Enter CD Title: ";
            getline(cin, title);
            cout << "Enter Publication Date: ";
            getline(cin, date);
            cout << "Enter Unique ID: ";
            getline(cin, id);
            cout << "Enter Publisher: ";
            getline(cin, pub);
            cout << "Enter Artist: ";
            getline(cin, artist);
            cout << "Enter Number of Tracks: ";
            cin >> tracks;
            cin.ignore();
            cout << "Enter Genre: ";
            getline(cin, genre);
            library.push_back(new CD(title, date, id, pub, artist, tracks, genre));
            cout << "CD added!\n";
        }
        else if (choice == 4)
        {
            string title, date, id, pub, editor;
            int issue;
            cout << "Enter Magazine Title: ";
            getline(cin, title);
            cout << "Enter Publication Date: ";
            getline(cin, date);
            cout << "Enter Unique ID: ";
            getline(cin, id);
            cout << "Enter Publisher: ";
            getline(cin, pub);
            cout << "Enter Editor: ";
            getline(cin, editor);
            cout << "Enter Issue Number: ";
            cin >> issue;
            cin.ignore();
            library.push_back(new Magazine(title, date, id, pub, editor, issue));
            cout << "Magazine added!\n";
        }
        else if (choice == 5)
        {
            int opt;
            cout << "Search by:\n1. Title\n2. Author\n3. Publication Year\nChoice: ";
            cin >> opt;
            cin.ignore();
            if (opt == 1)
            {
                string title;
                cout << "Enter Title: ";
                getline(cin, title);
                searchMedia(title);
            }
            else if (opt == 2)
            {
                string author;
                cout << "Enter Author: ";
                getline(cin, author);
                searchMedia(author, true);
            }
            else if (opt == 3)
            {
                int year;
                cout << "Enter Year: ";
                cin >> year;
                searchMedia(year);
            }
            else
            {
                cout << "Invalid search option.\n";
            }
        }
        else if (choice == 6)
        {
            string title;
            cout << "Enter title to checkout: ";
            getline(cin, title);
            for (Media *m : library)
            {
                m->checkout(title);
            }
        }
        else if (choice == 7)
        {
            string title;
            cout << "Enter title to return: ";
            getline(cin, title);
            for (Media *m : library)
            {
                m->returnItem(title);
            }
        }

    } while (choice != 0);

    for (Media *m : library)
        delete m;

    cout << "Exiting Library System.\n";
    return 0;
}
