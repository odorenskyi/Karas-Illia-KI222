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
    cout << "© Карась Ілля" << endl << endl;
}

void expression(char a, char b)
{
    bool expression =  a + 1 <= b;
    cout << noboolalpha << "Результат a + 1 <= b: " << expression << endl << endl;
}

void DecHexFunc(int x, int y, int z)
{
    cout << "'x' В десятковій: " << dec << x << endl;
    cout << "'y' В десятковій: " << dec << y << endl;
    cout << "'z' В десятковій: " << dec << z << endl;
    cout << "'x' В шістнадцятковій: " << hex << x << endl;
    cout << "'y' В шістнадцятковій: " << hex << y << endl;
    cout << "'z' В шістнадцятковій: " << hex << z << endl << endl;
}

int x, y, z;
char a, b;

int main()
{
    system("chcp 65001 && cls");
    copyright();

    cout << "Введіть x: ";
    cin >> x;
    cout << "Введіть y: ";
    cin >> y;
    cout << "Введіть z: ";
    cin >> z;
    cout << "Введіть символи 'a' та 'b': ";
    cin >> a >> b;

    cout << endl;

    expression(a, b);
    DecHexFunc(x, y, z);

    cout << "Результат обчислення виразу: S = " << s_calculation(x, y, z) << endl;
    getch();

    return 0;
}
