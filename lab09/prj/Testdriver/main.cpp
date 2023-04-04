#include <iostream>
#include "Modules-karas.h"

using namespace std;

void test_binary_func()
{
    unsigned int possibleresult[5] = {13,11,10,5,4};

    unsigned int numm[5] = {655304,500403,40378,1688,3264};
    cout << "binary function test" << endl;

    for (short int i = 0; i < 5; i++)
    {
        if (binary_func(numm[i]) == possibleresult[i]){
            cout << "Test #[" << i + 1 << "]: PASSED\n";
        }
        else{
            cout << "Test #[" << i + 1 << "]: FAILED\n";
        }
    }
}
void test_bofort_ball()
{
    int expected_res[5] = {4,0,5,2,1};
    float wind_power0[24] = {14.1,8.3,6.2,7.2,32.1,8.1,7.5,8.9,12.7,16.4,29.2, 15.7, 26.6, 8.5, 36.1, 18.8, 20.7, 31.7, 17.9, 34.3, 27.9, 26.5, 15.8, 16.2};
    float wind_power1[24] = {0.6, 6.1, 7.4, 9.1, 11.4, 11.6, 11.8, 13.8, 15.0, 0.2, 20.9, 24.7, 25.0, 25.4, 26.3, 27.3, 28.7, 29.6, 30.2, 31.7, 32.5, 33.4, 36.8, 38.1};
    float wind_power2[24] = {25.1, 33.7, 23.4, 27.2, 29.5, 36.9, 39.1, 16.2, 32.8, 33.6, 31.7, 37.6, 36.3, 36.6, 40.0, 19.9, 21.9, 25.8, 13.2, 11.8, 21.3, 9.5, 33.1, 18.9};
    float wind_power3[24] = {12.6, 34.4, 10.7, 9.0, 13.0, 7.2, 7.9, 18.0, 10.0, 33.0, 35.2, 26.8, 10.4, 22.2, 28.4, 20.0, 24.3, 18.8, 22.5, 21.1, 1.5, 9.3, 27.7, 33.5};
    float wind_power4[24] = {32.2, 5.0, 1.2, 3.0, 9.8, 3.4, 23.2, 24.0, 32.3, 22.3, 27.7, 27.4, 7.5, 37.7, 0.4, 30.2, 15.1, 25.8, 14.4, 27.3, 37.2, 23.0, 0.3, 13.3};

    cout << "Bafort ball test" << endl;

    if (bal_boforta(wind_power0) == expected_res[0]){
        cout << "Test #[1]: PASSED\n";
    }
    else{
        cout << "Test #[1]: FAILED\n";
    }
    if (bal_boforta(wind_power1) == expected_res[1]){
        cout << "Test #[2]: PASSED\n";
    }
    else{
        cout << "Test #[2]: FAILED\n";
    }if (bal_boforta(wind_power2) == expected_res[2]){
        cout << "Test #[3]: PASSED\n";
    }
    else{
        cout << "Test #[3]: FAILED\n";
    }if (bal_boforta(wind_power3) == expected_res[3]){
        cout << "Test #[4]: PASSED\n";
    }
    else{
        cout << "Test #[4]: FAILED\n";
    }if (bal_boforta(wind_power4) == expected_res[4]){
        cout << "Test #[5]: PASSED\n";
    }
    else{
        cout << "Test #[5]: FAILED\n";
    }
}

void test_population_flow()
{
    int population[5] = {1000,3500,8000,16000,8432};
    int death[5] = {121,567,221,168,632};
    int birth[5] = {100,344,567,872,888};
    int imigration[5] = {500,400,342,343,200};
    int emigration[5] = {577,880,901,457,789};

    population_flow possibleres[5] = {{1056,56},{3757,257},{8905,905},{16818,818},{9277,845}};

    cout << "Population flow function test" << endl;
    for (short int i = 0; i < 5; i++)
    {
        if (changes(population[i],death[i],birth[i],imigration[i],emigration[i]).population == possibleres[i].population &&
            changes(population[i],death[i],birth[i],imigration[i],emigration[i]).flow == possibleres[i].flow){
            cout << "Test #[" << i + 1 << "]: PASSED\n";
        }
        else{
            cout << "Test #[" << i + 1 << "]: FAILED\n";
        }
    }
}

int main()
{
    test_population_flow();
    test_bofort_ball();
    test_binary_func();
}
