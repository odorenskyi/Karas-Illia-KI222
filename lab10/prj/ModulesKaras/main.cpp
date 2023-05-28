#include <cmath>
#include <iostream>
#include <bitset>

#include <fstream>
#include <locale.h>
#include <Windows.h>
#include <ctime>
#include <cstring>

using namespace std;

float s_calculation(int x, int y, int z){
    return (pow((2 * z + 1), x)) - (sqrt(abs(y - 0.5 * z))) + z + 3.141592653589793;
}

int Task_9_1(int posadOklad, int zarobPlata, int year){
    int nadbavka, number1;
    if (year >= 3 && year < 5){
        nadbavka = (posadOklad*10)/100;
        number1 = zarobPlata+posadOklad+nadbavka;
    }
    if (year >= 5 && year < 7){
        nadbavka = (posadOklad*15)/100;
        number1 = zarobPlata+posadOklad+nadbavka;
    }
    if (year >= 7 && year < 15){
        nadbavka = (posadOklad*20)/100;
        number1 = zarobPlata+posadOklad+nadbavka;
    }
    if (year >= 15){
        nadbavka = (posadOklad*25)/100;
        number1 = zarobPlata+posadOklad+nadbavka;
    }
    return number1;
}

int Task_9_2_1(int one, int two, int three, int four, int five, int six){
    int celsia;
    celsia = (one+two+three+four+five+six)/6;
    return celsia;
}

int Task_9_2_2(int celsia){
    int farangeit;
    farangeit = (32 + 1.8 * celsia);
    return farangeit;
}

int Task_9_3(int N){
    bitset<32>b_number(N);
    if (N >= 0 && N < 10008000){
        if (b_number[10] == 0){
            return 32-b_number.count();
        }
        else if (b_number[10] == 1){
            return b_number.count();
        }
    }
    else{
        return 0;
    }
}

char Task_10_1(char in_path[], char out_path[]){

    string annotationsUkr = {"|---------------------------------------------------------------------------------------|\n|Ісаченков Едуард Віталійович,                                                        |\n|Центральноукраїнського національного технічного університету,|\n|Кропивницький, Україна, Рік розробки - 26.03.2022                     |\n|---------------------------------------------------------------------------------------|\n"};
    string annotationsEng = {"|---------------------------------------------------------------------------------------|\n|Isachenkov Eduard Vitaliyovych,                                                       |\n|Central Ukrainian National Technical University,                                 |\n|Kropyvnytskyi, Ukraine, Year of construction  - 26.03.2022                |\n|---------------------------------------------------------------------------------------|\n"};
    ofstream fout;
    ifstream fin;

    fout.open(out_path, ofstream::app);
    fin.open(in_path);

    if(!fin.is_open()){
        cout << "Помилка вiдкривання файлу №1" << endl;
    }
    else{
        char ch;
        string str1, str2, str3, str4;
        int num1, num2, num3, k = 0;
        while(fin.get(ch)){
            if(ch >= 'а' && ch <= 'я') k++;
            if(ch != '@') str1 += ch;
            else {
                num1 = fin.tellg();
                break;
            }
        }
        fin.seekg(num1, ios_base::beg);
        while(fin.get(ch)){
            if(ch != '@') str2 += ch;
            else {
                num2 = fin.tellg();
                break;
            }
        }
        fin.seekg(num2, ios_base::beg);
        while(fin.get(ch)){
            if(ch != '@') str3 += ch;
            else {
                num3 = fin.tellg();
                break;
            }
        }
        if(k >= 1) num3 -= 2;
        fin.seekg(num3, ios_base::beg);
        while(fin.get(ch)){
            if(ch != '@') str4 += ch;
            else break;
        }
        if(k > 2) {
            fout << annotationsUkr;
            fout << "Текст написаний Українською мовою\n\n";
            fout << '\t';
            fout << str4;
            fout << '\n';
            fout << '\t';
            fout << str3;
            fout << str2;
            fout << '\n';
            fout << str1;
        }
        else {
            fout << annotationsEng;
            fout << "The text is written in English\n\n";
            fout << '\t';
            fout << str4;
            fout << '\n';
            fout << '\t';
            fout << str3;
            fout << str2;
            fout << '\n';
            fout << str1;;
        }
    }
    fin.close();
    fout.close();
}

char Task_10_2(char in_path[]){

    ifstream fin;
    ofstream fout;

    time_t rawtime;
    time(&rawtime);
    fin.open(in_path);
    fout.open(in_path, ofstream::app);
    if(!fin.is_open()){
        cout << "Помилка вiдкривання файлу №2 " << endl;
    }
    else{
        int koma, krapka, k;
        char ch;
        while(fin.get(ch)){
            if(ch >= 'а' && ch <= 'я') k++;
            if(ch == ',') koma++;
            if(ch == '.') krapka++;
        }
        if (k >= 2) {
            fout << '\n';
            fout << "В данному тексті ком: = ";
            fout << koma;
            fout << '\n';
            fout << "В данному тексті крапок: = ";
            fout << krapka;
            fout << '\n';
            fout << ctime(&rawtime);
        }
        else {
            fout << '\n';
            fout << "In this text com: = ";
            fout << koma;
            fout << '\n';
            fout << "In this text dots: = ";
            fout << krapka;
            fout << '\n';
            fout << ctime(&rawtime);
        }
    }
    fin.close();
    fout.close();
}

void Task_10_3(int x, int y, int z, int b, char out_path[]){

    ofstream fout;
    int bin = 0, k = 1;
    while (b){
        bin += (b % 2) * k;
        k *= 10;
        b /= 2;
    }
    fout.open(out_path, ofstream::app);
    fout << endl;
    fout << "S: = ";
    fout << s_calculation(x,y,z);
    fout << endl;
    fout << "Число b, в двійкомову коді: = ";
    fout << bin;
    fout.close();
}




