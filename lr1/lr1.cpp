﻿#include <iostream>  

int main() {
    setlocale(LC_ALL, "Russian");

    int n;

    std::cout << "Введите количество элементов массива: ";
    std::cin >> n;

    int* arr = new int[n];

    std::cout << "Введите " << n << " целых чисел:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    std::cout << "Содержимое массива:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Адрес начала массива: " << static_cast<void*>(arr) << "\n";

    std::cout << "Расстояние каждого элемента от начала массива:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Элемент " << i << " (значение " << arr[i] << ") на расстоянии "
            << (reinterpret_cast<uintptr_t>(&arr[i]) - reinterpret_cast<uintptr_t>(arr)) << " байт\n";
    }

    delete[] arr;

    return 0;
}

#include <iostream>

using namespace std;

enum BookType {
    FICTION = 1,
    TECHNICAL = 2
};

void displayBookCounts(const BookType* books, int size) {
    int fictionCount = 0;
    int technicalCount = 0;

    for (int i = 0; i < size; ++i) {
        switch (books[i]) {
        case FICTION:
            fictionCount++;
            break;
        case TECHNICAL:
            technicalCount++;
            break;
        default:
            cout << "Неизвестный тип книги!" << endl;
            break;
        }
    }

    cout << "Количество художественной литературы: " << fictionCount << endl;
    cout << "Количество технической литературы: " << technicalCount << endl;
}

int main() {

    setlocale(LC_CTYPE, "Russian");

    int n;

    cout << "Введите количество книг: ";
    cin >> n;

    BookType* books = new BookType[n];

    cout << "Введите тип каждой книги (1 - художественная, 2 - техническая):" << endl;
    for (int i = 0; i < n; ++i) {
        int type;
        cin >> type;

        switch (type) {
        case 1:
            books[i] = FICTION;
            break;
        case 2:
            books[i] = TECHNICAL;
            break;
        default:
            cout << "Неправильный тип книги. Пожалуйста, введите 1 для художественной литературы или 2 для технической." << endl;
            --i;
            break;
        }
    }

    displayBookCounts(books, n);

    delete[] books;

    return 0;
}

