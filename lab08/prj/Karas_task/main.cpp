#include <iostream>
#include <cmath>
#include <iomanip>
#include <conio.h>

#include "ModulesKaras.h"

void copyright();
void expression(char a, char b);
void DecHexFunc(int x, int y, int z);

using namespace std;

void copyright()
{
    cout << "� ������ ����" << endl << endl;
}

void expression(char a, char b)
{
    bool expression =  a + 1 <= b;
    cout << noboolalpha << "��������� a + 1 <= b: " << expression << endl << endl;
}

void DecHexFunc(int x, int y, int z)
{
    cout << "'x' � ���������: " << dec << x << endl;
    cout << "'y' � ���������: " << dec << y << endl;
    cout << "'z' � ���������: " << dec << z << endl;
    cout << "'x' � ��������������: " << hex << x << endl;
    cout << "'y' � ��������������: " << hex << y << endl;
    cout << "'z' � ��������������: " << hex << z << endl << endl;
}

int x, y, z;
char a, b;

int main()
{
    system("chcp 65001 && cls");
    copyright();

    cout << "������ x: ";
    cin >> x;
    cout << "������ y: ";
    cin >> y;
    cout << "������ z: ";
    cin >> z;
    cout << "������ ������� 'a' �� 'b': ";
    cin >> a >> b;

    cout << endl;

    expression(a, b);
    DecHexFunc(x, y, z);

    cout << "��������� ���������� ������: S = " << s_calculation(x, y, z) << endl;
    getch();

    return 0;
}
