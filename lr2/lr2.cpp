#include <iostream>
#include <string>

using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    virtual void getdata() {
        cout << "Введите название: ";
        cin.ignore();
        getline(cin, title);

        cout << "Введите цену: ";
        cin >> price;
    }

    virtual void putdata() const {
        cout << "Название: " << title << endl;
        cout << "Цена: " << price << " руб." << endl;
    }

    virtual ~Publication() {}
};

class Book : public Publication {
private:
    int pages;

public:
    void getdata() override {
        Publication::getdata();
        cout << "Введите количество страниц: ";
        cin >> pages;
    }

    void putdata() const override {
        Publication::putdata();
        cout << "Количество страниц: " << pages << endl;
    }
};

class Type : public Publication {
private:
    float recordingTime;

public:
    void getdata() override {
        Publication::getdata();
        cout << "Введите время записи (в минутах): ";
        cin >> recordingTime;
    }

    void putdata() const override {
        Publication::putdata();
        cout << "Время записи: " << recordingTime << " минут" << endl;
    }
};

int main() {

    setlocale(LC_ALL, "Russian");
    Book book;
    Type audioBook;

    cout << "Ввод данных для книги:" << endl;
    book.getdata();

    cout << "\nВвод данных для аудиозаписи:" << endl;
    audioBook.getdata();

    cout << "\nДанные для книги:" << endl;
    book.putdata();

    cout << "\nДанные для аудиозаписи:" << endl;
    audioBook.putdata();

    return 0;
}

