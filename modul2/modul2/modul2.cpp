#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Book {
private:
    string title;
    string author;

public:
    Book(string title, string author) : title(title), author(author) {}

    string getTitle() const {
        return title;
    }

    string toString() const {
        return "\"" + title + "\" (Автор: " + author + ")";
    }
};

class Reader {
private:
    string fullname;
    int ticketNum;
    string faculty;
    string birthday;
    string phone;

public:
    Reader() : fullname("Невiдомий"), ticketNum(0), faculty("Немає"), birthday("2000.01.01"), phone("0000000000") {}

    Reader(string fn, int tn, string fac, string bd, string ph)
        : fullname(fn), ticketNum(tn), faculty(fac), birthday(bd), phone(ph) {}

    string getName() const {
        return fullname;
    }

    string toString() const {
        stringstream ss;
        ss << "ПIБ: " << fullname << ", Чит. квиток: " << ticketNum
            << ", Факультет: " << faculty << ", Дата нар.: " << birthday
            << ", Телефон: " << phone;
        return ss.str();
    }

    void takeBook(int bookNum) const {
        cout << fullname << " взяв " << bookNum << " книги." << endl;
    }

    void takeBook(const vector<string>& bookTitles) const {
        cout << fullname << " взяв книги: ";
        for (size_t i = 0; i < bookTitles.size(); ++i) {
            cout << bookTitles[i];
            if (i < bookTitles.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }

    void takeBook(const vector<Book>& books) const {
        cout << fullname << " взяв книги: ";
        for (size_t i = 0; i < books.size(); ++i) {
            cout << books[i].getTitle();
            if (i < books.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }

    void returnBook(int bookNum) const {
        cout << fullname << " повернув " << bookNum << " книги." << endl;
    }

    void returnBook(const vector<string>& bookTitles) const {
        cout << fullname << " повернув книги: ";
        for (size_t i = 0; i < bookTitles.size(); ++i) {
            cout << bookTitles[i];
            if (i < bookTitles.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }

    void returnBook(const vector<Book>& books) const {
        cout << fullname << " повернув книги: ";
        for (size_t i = 0; i < books.size(); ++i) {
            cout << books[i].getTitle();
            if (i < books.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
};

void saveReadersToFile(const vector<Reader>& readers, const string& filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& reader : readers) {
            outFile << reader.toString() << "\n";
        }
        outFile.close();
        cout << "\nзаписано у файл True" << filename << endl;
    }
    else {
        cerr << "\nзаписано у файл False" << filename << endl;
    }
}


int main() {
    setlocale(LC_ALL, "Ukrainian");

    vector<Reader> readers;

    Reader reader1("Петров В. В.", 1001, "Iнформатика", "1995.10.25", "0501234567");
    Reader reader2("Iванова О. С.", 1002, "Фiлологiя", "2001.03.15", "0677654321");

    readers.push_back(reader1);
    readers.push_back(reader2);

    cout << "takebook for " << reader1.getName() << " ---" << endl;

    reader1.takeBook(3);

    vector<string> titles = { "Пригоди", "Словник", "Енциклопедiя" };
    reader1.takeBook(titles);

    vector<Book> bookObjects;
    bookObjects.push_back(Book("Пригоди", "Жуль Верн"));
    bookObjects.push_back(Book("Словник", "А. П. С."));
    bookObjects.push_back(Book("Енциклопедiя", "Колектив авторiв"));
    reader1.takeBook(bookObjects);

    cout << "\nreturnbook for " << reader2.getName() << " ---" << endl;

    reader2.returnBook(2);

    vector<string> returnTitles = { "Математика", "Фiзика" };
    reader2.returnBook(returnTitles);

    vector<Book> returnBookObjects;
    returnBookObjects.push_back(Book("Iсторiя України", "М. С."));
    reader2.returnBook(returnBookObjects);


    saveReadersToFile(readers, "info.txt");

    return 0;
}