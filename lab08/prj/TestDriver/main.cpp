#include <iostream>
#include <cmath>
#include "ModulesKaras.h"

using namespace std;

void test_s_calculation()
{
    system("chcp 1251 && cls");

    float possibleresult[7] = {-0.453831,-0.161521,-0.0885473, 0,
                                0.078321, -0.000104685, 0};

    float x[7] = {5, 5, 2.5, 0, 1000000, -5, 1.79769e+10};
    float y[7] = {10, 10, 1.2, 0, 1000000, 10, 1.79769e+10};
    float z[7] = {3, 3, 1.5, 0, 1000000, 10, 1.79769e+10};

    for (short int i = 0; i < 7; i++)
    {
        cout << round(s_calculation(x[i], y[i], z[i])*10000)/10000.0 << " = " << possibleresult[i] << endl;
        if (round(s_calculation(x[i], y[i], z[i])*10000)/10000.0 == round(possibleresult[i]*10000)/10000.0)
        {
            cout << "Test #[" << i + 1 << "]: PASSED\n";
        }
        else
        {
            cout << "Test #[" << i + 1 << "]: FAILED\n";
        }
    }
}

int main()
{
    test_s_calculation();
}
