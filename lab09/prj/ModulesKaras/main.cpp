#include <cmath>

const double pi = 3.14159;
const double e = 2.71828;

struct population_flow{
    int population;
    int flow;
};

float s_calculation(float x, float y,float z){
    return 0.5*((pow(y,2)+ 2*z)/sqrt(7*pi + x)) - sqrt(pow(e,abs(x))+ (sqrt(abs(y-z)))/sin(z*y));
}

population_flow changes(int population,int death,int birth,int emigraation,int imigration){
    struct population_flow changes;
    changes.flow = birth - death + imigration - emigraation;
    changes.population = population + changes.flow;
    return changes;
}

short int bal_boforta(float wind[24]){
    float Min = wind[0];
    for(int i = 1;i<24;i++){
        if (wind[i] < Min){
            Min = wind[i];
        }
    }
    if (Min < 0.3){
        return 0;
    }
    else if (Min < 1.5){
        return 1;
    }
    else if (Min < 3.4){
        return 2;
    }
    else if (Min < 5.4){
        return 3;
    }
    else if (Min < 7.9){
        return 4;
    }
    else if (Min < 10.7){
        return 5;
    }
    else if (Min < 13.8){
        return 6;
    }
    else if (Min < 17.1){
        return 7;
    }
    else if (Min < 20.7){
        return 8;
    }
    else if (Min < 24.4){
        return 9;
    }
    else if (Min < 28.4){
        return 10;
    }
    else if (Min < 32.6){
        return 11;
    }
    else {
        return 12;
    }
}

short int binary_func(unsigned int num){
    int zeros = 0;
    int ones = 0;
    bool return_zeros = false;
    for (int i = 0; num > 0;i++){
        if (i == 7){
            if (num%2 == 0){
                return_zeros = true;
           }
        }
        if (num%2 == 1){
            ones++;
        }
        else {
            zeros++;
        }
        num >>= 1;
    }
    if (return_zeros){
        return zeros;
    }
    else{
        return ones;
    }
}
