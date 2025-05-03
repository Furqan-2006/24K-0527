#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class crypt
{
public: // ceaser cipher
    void encrypt(string &text)
    {
        for (auto &c : text)
        {
            c += 2;
        }
        // cout << text << endl;
    };
    void decrypt(string &text)
    {
        for (auto &c : text)
        {
            c -= 2;
        }
        cout << text << endl;
    };
};

class Handler : public crypt
{
    string fname;
    fstream file;

public:
    Handler(string fn) : fname(fn) {}

    void readFromFile()
    {
        file.open(fname, ios::in);
        if (!file)
        {
            cerr << "Failed to open file for reading!" << endl;
            return;
        }
        string line;
        while (getline(file, line))
        {
            decrypt(line);
        }
        file.close();
    }
    void appendToFile()
    {
        file.open(fname, ios::app);
        if (!file)
        {
            cerr << "Failed to open file for appending!" << endl;
            return;
        }
        string line;
        cout << "Enter text to encrypt: ";
        cin.ignore();
        getline(cin, line);

        encrypt(line);
        file << line << endl;
        file.close();
    }
    void overwriteFile()
    {
        file.open(fname, ios::out);
        if (!file)
        {
            cerr << "Failed to open file for overwriting!";
            return;
        }
        string line;
        cout << "Enter new text to overwrite previous text: ";
        cin.ignore();
        getline(cin, line);

        encrypt(line);
        file << line << endl;
        file.close();
    }
};

int main()
{
    Handler fileHandler("encry.txt");

    cout << "Options:\n1. Read data\n2. Append data\n3. Overwrite data\nEnter Your Choice: ";
    int opt;
    cin >> opt;
    switch (opt)
    {
    case 1:
        fileHandler.readFromFile();
        break;
    case 2:
        fileHandler.appendToFile();
        break;
    case 3:
        fileHandler.overwriteFile();
        break;
    default:
        cerr << "Invalid Option Chosen!!" << endl;
        break;
    }
    return 0;
}