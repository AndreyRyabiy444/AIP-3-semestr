#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;



/*Для варианта 6

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
}

*/


/*Для варианта 16

float t = 1.0;
float tf = 30.0;
float h = 0.001;

float x0[2] = { 5, -1 };
float xEul[2];

float solution(float t) {
    return 5-log(t);
}

void func(float t, const float* x, float* f) {
    f[0] = x[1];
    f[1] =((-x[0]*t)/(t*t)) ;
}

// или

float t = 1.0;
float tf = 30.0;
float h = 0.001;

float x0[2] = { 5, -1 };
float xEul[2];

float solution(float t) {
    return 5-log(t);
}

void func(float t, const float* x, float* f) {
    f[0] = x[1];
    //f[1] =((-x[0]*t)/(t*t)) ;
    f[1] =-t*x[0]/(t*t);
}

*/


float t = 1.0;
float tf = 30.0;
float h = 0.0001;

float x0[2] = { 5, -1 };
float xEul[2];

float solution(float t) {
    return 5-log(t);
}

void func(float t, const float* x, float* f) {
    f[0] = x[1];
    f[1] =((-x[0]*t)/(t*t)) ;
}

void euler(float* x, float t, float h) {
    float f[2];
    func(t, x, f);

    x[0] = x[0] + h * f[0];
    x[1] = x[1] + h * f[1];
}

void trapez(float* x, float t, float h) {

    float f[2];
    func(t, x, f);

    float xz[2];
    xz[0] = x[0] + h * f[0];
    xz[1] = x[1] + h * f[1];

    float fh[2];
    func(t + h, xz, fh);

    x[0] = x[0] + h * 0.5 * (f[0] + fh[0]);
    x[1] = x[1] + h * 0.5 * (f[1] + fh[1]);


    /*
    float f[2];
    func(t, x, f);

    float fh[2];
    float xz[1];
    xz[0]=x[0] + h*f[0];
    xz[1]= x[1] + h*f[1];

    func(t+h,xz,fh);

    x[0] = x[0] + h *0.5*(f[0]+fh[0]);
    x[1] = x[1] + h *0.5*(f[1]+fh[1]);*/
}

void rungeCutt(float *x,float t, float h){
    float f[2];
    func (t,x,f);

    float k1[2],k2[2],k3[2],k4[2],sum[2],xv[2];
    k1[0] = f[0];
    k1[1] = f[1];

    xv[0] = x[0] + k1[0] / 2.0;
    xv[1] = x[1] + k1[1] / 2.0;

    func(t+h/2.0,xv,f);

    k2[0] = f[0];
    k2[1] = f[1];

    xv[0] = x[0] +k2[0] /2.0;
    xv[1] = x[1] +k2[1] /2.0;

    func(t+h/2.0,xv,f);

    k3[0] = f[0];
    k3[1] = f[1];

    xv[0] = x[0] +k3[0] /2.0;
    xv[1] = x[1] +k3[1] /2.0;

    func(t+h,xv,f);

    k4[0] = f[0];
    k4[1] = f[1];

    sum[0] = k1[0] +2 *k2[0] + 2*k3[0] +k4[0];
    sum[1] = k1[1] +2 *k2[1] + 2*k3[1] +k4[1];

    x[0]= x[0] +1.0 /6.0 * h * sum[0];
    x[1]= x[1] +1.0 /6.0 * h * sum[1];
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
        rungeCutt(xEul, t, h);
        f << t << "," << solution(t)
          << "," << xEul[0] <<","<< xEul[1]
          << "," << err(solution(t), xEul[0])
          << endl;
        t += h;
    }
    f.close();
 }

