#include <iostream>
#include "TList.h"
#include "TPolinom.h"
using namespace std;

void Menu() {
    cout << "����:\n";
    cout << "1. ������\n";
    cout << "2. �������\n";
    cout << "3. �������� ������\n";
    cout << "4. �������� �� ���������\n";
    cout << "5. �����\n";
    cout << "��������, ����������, �����: ";
}


TPolinom ReadPolinom() {
    cout << "������� ���: ";
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
            cout << "�����/�������: " << p1.ToString() << endl;
            break;
        case 3:
            cout << "������� ������  ��� ��������:\n";
            p2 = ReadPolinom();
            result = p1 + p2;
            cout << "���������: " << result.ToString() << endl;
            break;
        case 4:
            cout << "������� ��������� ��� ���������: ";
            cin >> coef;
            result = p1 * coef;
            cout << "���������: " << result.ToString() << endl;
            break;
        case 5:
            cout << "�����" << endl;
            return 0;
        default:
            cout << "������������ �����. ��������� �����.\n";
        }
    }
}