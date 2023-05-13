#include <iostream>
#include <fstream>
#include <vector>

#include <struct_type_project_2.h>

using namespace std;

void saveDatabase(vector<entry> &database, string filename) {
    ofstream bout (filename, ios::out | ios::binary);
    if (bout.is_open()) {
        for (int i = 0, len; i < database.size(); i++) {
            // X - bout.write((char*)&structTest, sizeof(test));
            bout.write((char*)&database[i], sizeof(date));

            bout.write((char*)&database[i].regNum, sizeof(int));
            bout.write((char*)&database[i].id, sizeof(int));

            bout.write(&database[i].gender, sizeof(char));
            bout.write(&database[i].typeOfWork, sizeof(char));

            len = int(database[i].fullName.size());
            bout.write((char*)&len, sizeof(int));
            bout.write(&database[i].fullName[0], len);

            bout.write((char*)&database[i].birthDate, sizeof(date));

            len = int(database[i].citizenship.size());
            bout.write((char*)&len, sizeof(int));
            bout.write(&database[i].citizenship[0], len);

            char numOfEd = 0;
            for (; numOfEd < 4 && database[i].placeOfEducation[numOfEd] != ""; numOfEd++);
            bout.write((char*)&numOfEd, sizeof(char));

            for (int j = 0; j < numOfEd; j++) {
                bout.write((char*)&database[i].education[j], sizeof(int));

                len = int(database[i].placeOfEducation[j].size());
                bout.write((char*)&len, sizeof(int));
                bout.write(&database[i].placeOfEducation[j][0], len);
            }

            len = int(database[i].lastPlaceOfWork.size());
            bout.write((char*)&len, sizeof(int));
            bout.write(&database[i].lastPlaceOfWork[0], len);
            len = int(database[i].lastJob.size());
            bout.write((char*)&len, sizeof(int));
            bout.write(&database[i].lastJob[0], len);

            bout.write((char*)&database[i].workingExp, sizeof(short)*3);

            len = int(database[i].placeOfLiving.size());
            bout.write((char*)&len, sizeof(int));
            bout.write(&database[i].placeOfLiving[0], len);
            len = int(database[i].passportInfo.size());
            bout.write((char*)&len, sizeof(int));
            bout.write(&database[i].passportInfo[0], len);
            len = int(database[i].additionalInfo.size());
            bout.write((char*)&len, sizeof(int));
            bout.write(&database[i].additionalInfo[0], len);

            bout.write((char*)&database[i].dateOfFiring.day, sizeof(date));

            len = int(database[i].reasonOfFiring.size());
            bout.write((char*)&len, sizeof(int));
            bout.write(&database[i].reasonOfFiring[0], len);
        }
        bout.close();
    }
    else {
        cerr << "\nНеможливо завантажити файл '" << filename << "'.";
        exit(1);
    }
}

void loadDatabase(vector<entry> &database, string filename) {
    ofstream bout(filename, ios::app);
    bout.close();
    ifstream bin (filename, ios::in | ios::binary);
    if (bin.is_open()) {
        int fileLen = int(bin.seekg(0, ios::end).tellg());
        bin.seekg(0, ios::beg);
        while (bin.tellg() < fileLen) {
            entry* tmpEntry = new entry;
            int len;
            bin.read((char*)&*tmpEntry, sizeof(date));

            bin.read((char*)&tmpEntry->regNum, sizeof(int));
            bin.read((char*)&tmpEntry->id, sizeof(int));

            bin.read((char*)&tmpEntry->gender, sizeof(char));
            bin.read((char*)&tmpEntry->typeOfWork, sizeof(char));

            bin.read((char*)&len, sizeof(int));
            tmpEntry->fullName.resize(len);         //instead of dynamic buffer
            bin.read((char*)&tmpEntry->fullName[0], len);

            bin.read((char*)&tmpEntry->birthDate, sizeof(date));

            bin.read((char*)&len, sizeof(int));
            tmpEntry->citizenship.resize(len);
            bin.read((char*)&tmpEntry->citizenship[0], len);

            char numOfEd = 0;
            bin.read((char*)&numOfEd, sizeof(char));
            for (int i = 0; i < numOfEd; i++) {
                bin.read((char*)&tmpEntry->education[i], sizeof(int));

                bin.read((char*)&len, sizeof(int));
                tmpEntry->placeOfEducation[i].resize(len);
                bin.read((char*)&tmpEntry->placeOfEducation[i][0], len);
            }

            bin.read((char*)&len, sizeof(int));
            tmpEntry->lastPlaceOfWork.resize(len);
            bin.read((char*)&tmpEntry->lastPlaceOfWork[0], len);

            bin.read((char*)&len, sizeof(int));
            tmpEntry->lastJob.resize(len);
            bin.read((char*)&tmpEntry->lastJob[0], len);

            bin.read((char*)&tmpEntry->workingExp, sizeof(short)*3);

            bin.read((char*)&len, sizeof(int));
            tmpEntry->placeOfLiving.resize(len);
            bin.read((char*)&tmpEntry->placeOfLiving[0], len);

            bin.read((char*)&len, sizeof(int));
            tmpEntry->passportInfo.resize(len);
            bin.read((char*)&tmpEntry->passportInfo[0], len);

            bin.read((char*)&len, sizeof(int));
            tmpEntry->additionalInfo.resize(len);
            bin.read((char*)&tmpEntry->additionalInfo[0], len);

            bin.read((char*)&tmpEntry->dateOfFiring, sizeof(date));

            bin.read((char*)&len, sizeof(int));
            tmpEntry->reasonOfFiring.resize(len);
            bin.read((char*)&tmpEntry->reasonOfFiring[0], len);

            database.push_back(*tmpEntry);
            delete tmpEntry;
        }
        bin.close();
    }
    else {
        cerr << "\nНеможливо завантажити файл '" << filename << "'.";
        exit(1);
    }
}
