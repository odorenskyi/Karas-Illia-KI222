#ifndef STRUCT_TYPE_PROJECT_2_H_INCLUDED
#define STRUCT_TYPE_PROJECT_2_H_INCLUDED

using namespace std;

struct date{
    short day = 0;      //1...
    short month = 0;    //1...
    short year = 0;
};

struct entry {
    date creationDate;
    int regNum = -1;
    int id = -1;
    char gender = 'm';
    char typeOfWork = 'f';
    string fullName = "";
    date birthDate;
    string citizenship = "";
    enum {basicSecondary, compSecondary, vocational,
          incompHigher, basicHigher, higher} education[4];
    string placeOfEducation[4] = {"", "", "", ""};
    string lastPlaceOfWork = "";
    string lastJob = "";
    struct {
        short days = 0;
        short months = 0;
        short years = 0;
    } workingExp;
    string placeOfLiving = "";
    string passportInfo = "";
    string additionalInfo = "";
    date dateOfFiring;
    string reasonOfFiring = "";
};

#endif // STRUCT_TYPE_PROJECT_2_H_INCLUDED
