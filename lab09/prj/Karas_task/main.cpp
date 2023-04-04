#include <iostream>
#include <conio.h>
#include "Modules-karas.h"

using namespace std;

int main()
{
    system("chcp 1251 & cls");
    int x,y,z;
    float wind_power[24];
    int population,death,birth,imigration,emigration;
    int numm;

    cout << "d - calls a function s_calculation" << endl
         << "j - calls a binary function" << endl
         << "h - calls a bofort_bal function" << endl
         << "g - calls a population_flow function" << endl
         << "'k','K' and '�' terminate the program" << endl;
    getchar();

    while(true) {
        cout << "Enter symbol (d/j/h/g/k/K/�): ";
        switch (getch()) {
            case 'd': cout << endl;
                      cout << "Enter x value: ";
                      cin >> x;
                      cout << "Enter y value: ";
                      cin >> y;
                      cout << "Enter z value: ";
                      cin >> z;
                      cout << "the result of expression S = " << s_calculation(x,y,z) << endl;
                      break;
            case 'j': cout << endl;
                      cout << "Enter number in range 0 - 500700: ";
                      cin >> numm;
                      cout << "Tne amount of binary zeros or onces is " << binary_func(numm) << endl;
                      cout << endl;
                      break;
            case 'h': cout << endl;
                      for(int i = 0;i<24;i++){
                        cout << "Enter wind power per hour of 24 hours: ";
                        cin >> wind_power[i];
                      }
                      cout << "Beafort bal of the weakest wind power in 24 hours is " << bal_boforta(wind_power);
                      cout << endl;
                      break;
            case 'g': cout << endl;
                      cout << "Enter population of the region: ";
                      cin >> population;
                      cout << "Enter number of birth on the region: ";
                      cin >> birth;
                      cout << "Enter number of death cases of the region: ";
                      cin >> death;
                      cout << "Enter number of emigration cases in the region: ";
                      cin >> emigration;
                      cout << "Enter number of imigration cases in the region: ";
                      cin >> imigration;
                      cout << "Curent number of population in the region is " << changes(population,birth,death,emigration,imigration).population << endl;
                      cout << "Curent number of changes in the region is " << changes(population,birth,death,emigration,imigration).flow << endl;
                      cout << endl;
                      break;
            case 'k': return 0; break;
            case 'K': return 0; break;
            case '�': return 0; break;
            default: cout << "\a" << endl << endl; continue;
        }
    }
}
