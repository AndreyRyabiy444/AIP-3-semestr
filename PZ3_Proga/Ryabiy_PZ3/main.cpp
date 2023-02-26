#include <iostream>
#include <fstream>
#include <math.h>
//var 6
using namespace std;

float t = 0.0;
float tf = 10.0;
float h = 0.001;

float x0[2] = { 1.8, -0.5 };
float xEul[2];


float solution(float t) {
    return exp(t)+exp(-t)-0.5*sin(t)-0.2*cos(2*t);
}

void func(float t, const float* x, float* f) {
    f[0] = x[1];
    f[1] =(sin(t)+cos(2*t)+x[0]) ;
    // f[1] = (11 - 2 * log(t) + 4 * t - 2 * x[0]) / (t * t);
}

void trapez(float* x, float t, float h) {
    float f[2];
    func(t, x, f);

    x[0] = x[0] + h * f[0];
    x[1] = x[1] + h * f[1];
}


float err(float a, float b) {
    return (a - b) * (a - b);
}

int main()
{
    ofstream f;
    f.open("data.csv");

    xEul[0] = x0[0];
    xEul[1] = x0[1];

    while (t < tf) {
        trapez(xEul, t, h);
        f << t << "," << solution(t) << "," << xEul[0] <<","<< xEul[1] << "," << err(solution(t), xEul[0]) << endl;
        t += h;
    }
    f.close();
 }

