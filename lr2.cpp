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

#include <iostream>
#include <string>
#include <windows.h>  

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

class Sales {
protected:
    float sales[3];

public:
    void getdata() {
        cout << "Введите продажи за последние три месяца:" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "Месяц " << i + 1 << ": ";
            cin >> sales[i];
        }
    }

    void putdata() const {
        cout << "Продажи за последние три месяца:" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "Месяц " << i + 1 << ": " << sales[i] << " руб." << endl;
        }
    }
};

class Book : public Publication, public Sales {
private:
    int pages;

public:
    void getdata() override {
        Publication::getdata();
        cout << "Введите количество страниц: ";
        cin >> pages;
        Sales::getdata();
    }

    void putdata() const override {
        Publication::putdata();
        cout << "Количество страниц: " << pages << endl;
        Sales::putdata();
    }
};

class Type : public Publication, public Sales {
private:
    float recordingTime;

public:

    void getdata() override {
        Publication::getdata();
        cout << "Введите время записи (в минутах): ";
        cin >> recordingTime;
        Sales::getdata();
    }

    void putdata() const override {
        Publication::putdata();
        cout << "Время записи: " << recordingTime << " минут" << endl;
        Sales::putdata();
    }
};

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

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
