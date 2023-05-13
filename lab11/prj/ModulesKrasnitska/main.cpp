#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

#include "struct_type_project_2.h"

using namespace std;

void printPersonalCard(entry personalCard, int i){
    cout << "|" << setw(6) << i+1 << "|" << setw(25) << left << "Дата створення:" << "|" << setw(45)
                 << (personalCard.creationDate.day < 10 ? "0" : "") + to_string(personalCard.creationDate.day) + "." +
                    (personalCard.creationDate.month < 10 ? "0" : "") + to_string(personalCard.creationDate.month) + "." +
                    to_string(personalCard.creationDate.year) << "|" << endl << resetiosflags(ios::left);
    int edc = 0;
    for(int k = 0; k < 17; k++){
        cout << "|" << setw(7) << "|" << setw(25) << left;
        switch(k) {
        case 0:
            cout << "Реєстраційний номер:" << "|" << setw(45) << personalCard.regNum;
            break;
        case 1:
            cout << "Ідентифікаційний номер:" << "|" << setw(45) << personalCard.id;
            break;
        case 2:
            cout << "Стать:" << "|" << setw(45) << (personalCard.gender == 'm' ? "чоловіча" : "жіноча");
            break;
        case 3:
            cout << "Вид роботи:" << "|" << setw(45) << (personalCard.typeOfWork == 'f' ? "основна" : "за суміцниством");
            break;
        case 4:
            cout << "ПІБ працівника:" << "|" << setw(45) << personalCard.fullName;
            break;
        case 5:
            cout << "Дата народження:" << "|" << setw(45) << (personalCard.birthDate.day < 10 ? "0" : "") +
            to_string(personalCard.birthDate.day) + "." + (personalCard.birthDate.month < 10 ? "0" : "") +
            to_string(personalCard.birthDate.month) + "." + to_string(personalCard.birthDate.year);
            break;
        case 6:
            cout << "Громадянство:" << "|" << setw(45) << personalCard.citizenship;
            break;
        case 7:
            cout << "Освіта " + to_string(edc+1) + ":" << "|" << setw(45) << (personalCard.placeOfEducation[edc] == "" ? "-" :
                                                    (personalCard.education[edc] == entry::basicSecondary ? "базова середня" :
                                                    personalCard.education[edc] == entry::compSecondary ? "повна середня" :
                                                    personalCard.education[edc] == entry::vocational ? "професійно-технічна" :
                                                    personalCard.education[edc] == entry::incompHigher ? "неповна вища" :
                                                    personalCard.education[edc] == entry::basicHigher ? "базова вища" : "вища"));
            break;
        case 8:
            cout << " " << "|" << setw(45) << personalCard.placeOfEducation[edc];
            for(int j = 0; j < 4; j++){
                if (personalCard.placeOfEducation[++edc] != "") {
                    j -= 2; // repeat writing educations` info
                }
            }
            break;
        case 9:
            cout << "Останнє місце роботи:" << "|" << setw(45)
                 << (personalCard.lastPlaceOfWork == "" ? "-" : personalCard.lastPlaceOfWork);
            break;
        case 10:
            cout << resetiosflags(ios::left) << "посада:    " << left << "|" << setw(45)
                 << (personalCard.lastJob == "" ? "-" : personalCard.lastJob);
            break;
        case 11:
            cout << "Стаж роботи:" << "|" << setw(45) << (personalCard.workingExp.days != 0 ?
            to_string(personalCard.workingExp.days) + " днів " : "") + (personalCard.workingExp.months != 0 ?
            to_string(personalCard.workingExp.months) + " місяців " : "") + (personalCard.workingExp.years != 0 ?
            to_string(personalCard.workingExp.years) + " років" : "");
            break;
        case 12:
            cout << "Місце проживання:" << "|" << setw(45) << personalCard.placeOfLiving;
            break;
        case 13:
            cout << "Паспортні дані:" << "|" << setw(45) << personalCard.passportInfo;
            break;
        case 14:
            cout << "Додаткові відомості:" << "|" << setw(45)
                << (personalCard.additionalInfo == "" ? "-" : personalCard.additionalInfo);
            break;
        case 15:
            cout << "Дата звільнення:" << "|" << setw(45) << (personalCard.dateOfFiring.day != 0 &&
                         personalCard.dateOfFiring.month != 0 && personalCard.dateOfFiring.year != 0 ?
                        (personalCard.dateOfFiring.day < 10 ? "0" : "") + to_string(personalCard.dateOfFiring.day) + "." +
                        (personalCard.dateOfFiring.month < 10 ? "0" : "") + to_string(personalCard.dateOfFiring.month) +
                         "." + to_string(personalCard.dateOfFiring.year) : "-");
            break;
        case 16:
            cout << resetiosflags(ios::left) << "причина:         " << left << "|" << setw(45)
                 << (personalCard.reasonOfFiring  == "" ? "-" : personalCard.reasonOfFiring);
            break;
        }
        cout << "|" << endl << resetiosflags(ios::left);
    }
}

void searchPersonalCard(vector<entry> &database, string surname){
    string lastName;
    vector<int> result;
    cout << "+" << setfill('—') << setw(79) << "+" << endl << setfill(' ')
         << "|" << setw(45) << "КАРТКИ З ПРІЗВИЩЕМ " << setw(33) << left << surname << resetiosflags(ios::left) << "|" << endl
         << "+" << setfill('—') << setw(79) << "+" << endl << setfill(' ');
    for(int i = 0; i < database.size(); i++){
        istringstream(database[i].fullName) >> lastName;
        if(lastName == surname){
            result.push_back(i);
        }
    }
    for(int i = 0; i < result.size(); i++){
        printPersonalCard(database[result[i]], result[i]);
        if(i+1 == result.size())
            cout << "+" << setfill('—') << setw(79) << "+" << endl << setfill(' ');
        else
            cout << "+" << setfill('—') << setw(7) << "+" << setw(26) << "+" << setw(46) << "+" << setfill(' ') << endl;
    }
}

void showDatabase(vector<entry> &database){
    ofstream fout;
    #define OUT(option) ((option) == 'c' ? cout : fout)

    char option;
    do {
        cout << "+==============================================================+" << endl
             << " Ви хочете вивести базу даних на консоль (c) або у файл (t) - ";
        cin >> option;
        cout << "+==============================================================+" << endl;
    }while (option != 'c' && option != 't' && option != 'C' && option != 'T' && option != 'е' && option != 'Е');
    do {
        string filename = "";
        if (option == 't' || option == 'T' || option == 'е' || option == 'Е') {
            cout << " Введіть назву файлу: ";
            cin >> filename;
            cout << "+==============================================================+" << endl;
            fout.open(filename, ios::out);
        }
        if (option == 'c' || fout.is_open()) {
            OUT(option) << "+" << setfill('—') << setw(79) << "+" << endl << setfill(' ')
                        << "|" << setw(63) << "ВІДДІЛ КАДРІВ: ОСОБОВА КАРТКА ПРАЦІВНИКА, Ф. П-2" << setw(16) << "|" << endl
                        << "+" << setfill('—') << setw(79) << "+" << endl << setfill(' ');
            for (int i = 0; i < database.size(); i++) {
                OUT(option) << "|" << setw(6) << i+1 << "|" << setw(25) << left << "Дата створення:" << "|" << setw(45)
                                   << (database[i].creationDate.day < 10 ? "0" : "") + to_string(database[i].creationDate.day) + "." +
                                      (database[i].creationDate.month < 10 ? "0" : "") + to_string(database[i].creationDate.month) + "." +
                                      to_string(database[i].creationDate.year) << "|" << endl << resetiosflags(ios::left);
                int edc = 0;
                for (int j = 0; j < 17; j++) {
                    OUT(option) << "|" << setw(7) << "|" << setw(25) << left;
                    switch(j) {
                    case 0:
                        OUT(option) << "Реєстраційний номер:" << "|" << setw(45) << database[i].regNum;
                        break;
                    case 1:
                        OUT(option) << "Ідентифікаційний номер:" << "|" << setw(45) << database[i].id;
                        break;
                    case 2:
                        OUT(option) << "Стать:" << "|" << setw(45) << (database[i].gender == 'm' ? "чоловіча" : "жіноча");
                        break;
                    case 3:
                        OUT(option) << "Вид роботи:" << "|" << setw(45) << (database[i].typeOfWork == 'f' ? "основна" : "за суміцниством");
                        break;
                    case 4:
                        OUT(option) << "ПІБ працівника:" << "|" << setw(45) << database[i].fullName;
                        break;
                    case 5:
                        OUT(option) << "Дата народження:" << "|" << setw(45) << (database[i].birthDate.day < 10 ? "0" : "") +
                                        to_string(database[i].birthDate.day) + "." + (database[i].birthDate.month < 10 ? "0" : "") +
                                        to_string(database[i].birthDate.month) + "." + to_string(database[i].birthDate.year);
                        break;
                    case 6:
                        OUT(option) << "Громадянство:" << "|" << setw(45) << database[i].citizenship;
                        break;
                    case 7:
                        OUT(option) << "Освіта " + to_string(edc+1) + ":" << "|" << setw(45) << (database[i].placeOfEducation[edc] == "" ? "-" :
                                                                  (database[i].education[edc] == entry::basicSecondary ? "базова середня" :
                                                                   database[i].education[edc] == entry::compSecondary ? "повна середня" :
                                                                   database[i].education[edc] == entry::vocational ? "професійно-технічна" :
                                                                   database[i].education[edc] == entry::incompHigher ? "неповна вища" :
                                                                   database[i].education[edc] == entry::basicHigher ? "базова вища" : "вища"));
                        break;
                    case 8:
                        OUT(option) << " " << "|" << setw(45) << database[i].placeOfEducation[edc];
                        if (database[i].placeOfEducation[++edc] != "") {
                            j -= 2;     // repeat writing educations` info
                        }
                        break;
                    case 9:
                        OUT(option) << "Останнє місце роботи:" << "|" << setw(45)
                                    << (database[i].lastPlaceOfWork == "" ? "-" : database[i].lastPlaceOfWork);
                        break;
                    case 10:
                        OUT(option) << resetiosflags(ios::left) << "посада:    " << left << "|" << setw(45)
                                    << (database[i].lastJob == "" ? "-" : database[i].lastJob);
                        break;
                    case 11:
                        OUT(option) << "Стаж роботи:" << "|" << setw(45) << (database[i].workingExp.days != 0 &&
                                        database[i].workingExp.months != 0 && database[i].workingExp.years != 0 ?
                                        (database[i].workingExp.days != 0 ? to_string(database[i].workingExp.days) + " днів " : "") +
                                        (database[i].workingExp.months != 0 ? to_string(database[i].workingExp.months) + " місяців " : "") +
                                        (database[i].workingExp.years != 0 ? to_string(database[i].workingExp.years) + " років" : "") : "-");
                        break;
                    case 12:
                        OUT(option) << "Місце проживання:" << "|" << setw(45) << database[i].placeOfLiving;
                        break;
                    case 13:
                        OUT(option) << "Паспортні дані:" << "|" << setw(45) << database[i].passportInfo;
                        break;
                    case 14:
                        OUT(option) << "Додаткові відомості:" << "|" << setw(45)
                                    << (database[i].additionalInfo == "" ? "-" : database[i].additionalInfo);
                        break;
                    case 15:
                        OUT(option) << "Дата звільнення:" << "|" << setw(45) << (database[i].dateOfFiring.day != 0 &&
                                        database[i].dateOfFiring.month != 0 && database[i].dateOfFiring.year != 0 ?
                                        (database[i].dateOfFiring.day < 10 ? "0" : "") + to_string(database[i].dateOfFiring.day) + "." +
                                        (database[i].dateOfFiring.month < 10 ? "0" : "") + to_string(database[i].dateOfFiring.month) +
                                        "." + to_string(database[i].dateOfFiring.year) : "-");
                        break;
                    case 16:
                        OUT(option) << resetiosflags(ios::left) << "причина:         " << left << "|" << setw(45)
                                    << (database[i].reasonOfFiring == "" ? "-" : database[i].reasonOfFiring);
                        break;
                    }
                    OUT(option) << "|" << endl << resetiosflags(ios::left);
                }
                if (i+1 != database.size())
                    OUT(option) << "+" << setfill('—') << setw(7) << "+" << setw(26) << "+" << setw(46) << "+" << setfill(' ') << endl;
                else
                    OUT(option) << "+" << setfill('—') << setw(79) << "+" << endl << setfill(' ');
            }
            if (fout.is_open()) fout.close();
            break;
        }
        else {
            cerr << "Сталася помилка під час написання " << filename << ". Спробуйте ще раз." << endl;
        }
    }while (true);

    #undef OUT(option)
}
