#include <iostream>
#include <windows.h>
#include <cstring>
#include <fstream>
#include <ctime>
#include "ModulesIsachenkov.h"

using namespace std;

void testdriver_1(void);
void testdriver_2(void);
void testdriver_3(void);
string ReadFile(string path_file);
string clearText(string out_path);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    testdriver_1();
    testdriver_2();
    testdriver_3();
    system("pause");

    return 0;
}

void testdriver_1(void){

    char in_path[] = "C:\\Users\\user\\Desktop\\GitHub\\Isachenkov-Eduard-KB-21\\lab10\\TextFile\\in-text.txt";
    char in_path_ENG[] = "C:\\Users\\user\\Desktop\\GitHub\\Isachenkov-Eduard-KB-21\\lab10\\TextFile\\in-text-ENG.txt";
    char out_path[] = "C:\\Users\\user\\Desktop\\GitHub\\Isachenkov-Eduard-KB-21\\lab10\\TextFile\\out-text.txt";
    string out_path2 = "C:\\Users\\user\\Desktop\\GitHub\\Isachenkov-Eduard-KB-21\\lab10\\TextFile\\out-text.txt";
    string expected_test_10_1_1 = "C:\\Users\\user\\Desktop\\GitHub\\Isachenkov-Eduard-KB-21\\lab10\\TextFile\\Expected Task_10_1\\expected_test_10_1_1.txt";
    string expected_test_10_1_2 = "C:\\Users\\user\\Desktop\\GitHub\\Isachenkov-Eduard-KB-21\\lab10\\TextFile\\Expected Task_10_1\\expected_test_10_1_2.txt";
    string reader, result_task_10_1_1, Rexpected_test_10_1_1, Rexpected_test_10_1_2;

    clearText(out_path2);
    Task_10_1(in_path, out_path);
    Rexpected_test_10_1_1 = ReadFile(expected_test_10_1_1);
    reader = ReadFile(out_path2);
    cout << "<<<< Test_10_1 >>>>" << endl;
    if(reader == Rexpected_test_10_1_1) cout << "\nTest case #01 PASSED.\n";
    else cout << "\nTest case #01 FAILED.\n";

    clearText(out_path2);
    Task_10_1(in_path_ENG, out_path);
    Rexpected_test_10_1_2 = ReadFile(expected_test_10_1_2);
    reader = ReadFile(out_path2);
    if(reader == Rexpected_test_10_1_2) cout << "\nTest case #02 PASSED.\n";
    else cout << "\nTest case #02 FAILED.\n";
}

void testdriver_2(void){

    time_t rawtime;
    time(&rawtime);
    char in_path[] = "C:\\Users\\user\\Desktop\\GitHub\\Isachenkov-Eduard-KB-21\\lab10\\TextFile\\in-text.txt";
    string in_path2 = "C:\\Users\\user\\Desktop\\GitHub\\Isachenkov-Eduard-KB-21\\lab10\\TextFile\\in-text.txt";
    char in_path_ENG[] = "C:\\Users\\user\\Desktop\\GitHub\\Isachenkov-Eduard-KB-21\\lab10\\TextFile\\in-text-ENG.txt";
    string in_path_ENG2 = "C:\\Users\\user\\Desktop\\GitHub\\Isachenkov-Eduard-KB-21\\lab10\\TextFile\\in-text-ENG.txt";
    string expected_path_10_2_1 = "C:\\Users\\user\\Desktop\\GitHub\\Isachenkov-Eduard-KB-21\\lab10\\TextFile\\Expected Task_10_2\\expected_test_10_2_1.txt";
    string expected_path_10_2_2 = "C:\\Users\\user\\Desktop\\GitHub\\Isachenkov-Eduard-KB-21\\lab10\\TextFile\\Expected Task_10_2\\expected_test_10_2_2.txt";
    string reader, Rexpected_test_10_2_1, Rexpected_test_10_2_2;
    Task_10_2(in_path);
    Rexpected_test_10_2_1 = ReadFile(expected_path_10_2_1);
    Rexpected_test_10_2_1 += ctime(&rawtime);
    reader = ReadFile(in_path2);
    cout << "\n<<<< Test_10_2 >>>>" << endl;
    if(reader == Rexpected_test_10_2_1) cout << "\nTest case #01 PASSED.\n";
    else cout << "\nTest case #01 FAILED.\n";

    Task_10_2(in_path_ENG);
    Rexpected_test_10_2_2 = ReadFile(expected_path_10_2_2);
    Rexpected_test_10_2_2 += ctime(&rawtime);
    reader = ReadFile(in_path_ENG2);
    if(reader == Rexpected_test_10_2_2) cout << "\nTest case #02 PASSED.\n";
    else cout << "\nTest case #02 FAILED.\n";
}

void testdriver_3(void){

    char in_path[] = "C:\\Users\\user\\Desktop\\GitHub\\Isachenkov-Eduard-KB-21\\lab10\\TextFile\\in-text-UKR.txt";
    char out_path[] = "C:\\Users\\user\\Desktop\\GitHub\\Isachenkov-Eduard-KB-21\\lab10\\TextFile\\out-text.txt";
    string out_path2 = "C:\\Users\\user\\Desktop\\GitHub\\Isachenkov-Eduard-KB-21\\lab10\\TextFile\\out-text.txt";
    string expected_path_10_3_1 = "C:\\Users\\user\\Desktop\\GitHub\\Isachenkov-Eduard-KB-21\\lab10\\TextFile\\Expected Task_10_3\\expected_test_10_3_1.txt";
    string expected_path_10_3_2 = "C:\\Users\\user\\Desktop\\GitHub\\Isachenkov-Eduard-KB-21\\lab10\\TextFile\\Expected Task_10_3\\expected_test_10_3_2.txt";
    string reader, Rexpected_test_10_3_1, Rexpected_test_10_3_2;
    int number1[2] = {1, 3};
    int number2[2] = {2, 2};
    int number3[2] = {3, 1};
    int b[2] = {36, 63};
    Task_10_3(number1[0], number2[0], number3[0], b[0], out_path);
    Rexpected_test_10_3_1 = ReadFile(expected_path_10_3_1);
    reader = ReadFile(out_path2);
    cout << "\n<<<< Test_10_3 >>>>" << endl;
    if(reader == Rexpected_test_10_3_1) cout << "\nTest case #01 PASSED.\n";
    else cout << "\nTest case #01 FAILED.\n";

    clearText(out_path2);
    Task_10_1(in_path, out_path);
    Task_10_3(number1[1], number2[1], number3[1], b[1], out_path);
    Rexpected_test_10_3_2 = ReadFile(expected_path_10_3_2);
    reader = ReadFile(out_path2);
    if(reader == Rexpected_test_10_3_2) cout << "\nTest case #02 PASSED.\n";
    else cout << "\nTest case #02 FAILED.\n";
}

string ReadFile(string path_file){
    ifstream file(path_file);
    if(!file.is_open()) return "ERROR";
    string text = "";
    string line;
    while (getline(file, line)){
        text += line + '\n';
    }
    file.close();
    return text;
}

string clearText(string out_path){
    ofstream fout;
    fout.open(out_path);
    fout << "";
    fout.close();
    return out_path;
}
