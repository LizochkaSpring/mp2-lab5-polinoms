#include <iostream>
#include "TList.h"
#include "TPolinom.h"
using namespace std;

void Menu() {
    cout << "Меню:\n";
    cout << "1. Ввести\n";
    cout << "2. Вывести\n";
    cout << "3. Добавить второй\n";
    cout << "4. Умножить на константу\n";
    cout << "5. Выход\n";
    cout << "Выверите, пожалуйста, опцию: ";
}


TPolinom ReadPolinom() {
    cout << "Введите тут: ";
    string str;
    getline(cin, str);
    return TPolinom(str);
}


int main()
{
    setlocale(LC_ALL, "Russian");
    TPolinom p1, p2, result;
    int choice;
    double coef;
    while (true) {
        Menu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) {
        case 1:
            p1 = ReadPolinom();
            break;
        case 2:
            cout << "Моном/Полином: " << p1.ToString() << endl;
            break;
        case 3:
            cout << "Введите второй  для сложения:\n";
            p2 = ReadPolinom();
            result = p1 + p2;
            cout << "Результат: " << result.ToString() << endl;
            break;
        case 4:
            cout << "Введите константу для умножения: ";
            cin >> coef;
            result = p1 * coef;
            cout << "Результат: " << result.ToString() << endl;
            break;
        case 5:
            cout << "Выход" << endl;
            return 0;
        default:
            cout << "Неправильный выбор. Пробовать снова.\n";
        }
    }
}