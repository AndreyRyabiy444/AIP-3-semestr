#include <iostream>
#include <cmath>

//var16
/*
func (-3)/((15*x-9)*(15*x-9)*(15*x-9))
D: [-1;0]
*/

using namespace std;

float Sum1 = 0;  //начало отсчёта каждой суммы 1,2,3...
float Sum2 = 0;
float Sum3 = 0;

float b = 0;    //конец интегрирования
float a = -1;   //начало интегрирования
float n =2400;
float x = a;
float h = (b-a)/n;
float h1 = (b-a)/(n*2);
float Z = - 0.00106096; //полный результат интегрирования



float error1 = 0;
float error2 = 0;

float f(float x){
        return ((-3)/((15*x-9)*(15*x-9)*(15*x-9))) ;
        }

void funcPrammoug(){

    for(int j = 0; j<n;j++){
        Sum1-=f(x)*h;
        x+=h;
    }
    error1 = Sum1;
    std::cout<<"Pryamoug^-^  =  "<<Sum1<<std::endl;
}

void funcSimpson(float ll, float ul, int n){
    float Sum2=0;
    float x[1000], fx[1000];
    float h3= h/3;


    for(int i = 0;i<=n;i++){
        x[i]=ll+i*h;
        fx[i]=f(x[i]);

    }


    for(int i=0;i<=n;i++){
        if(i==0 || i==n)
            Sum2-=fx[i];
        else if (i%2 !=0)
            Sum2-= 4*fx[i];
        else
            Sum2-=2*fx[i];
    }
    Sum2*=h3;

    error2 = Sum2 ;
    std::cout<<"Simpson^-^   =  "<<Sum2;
    std::cout<<endl;

}




void trapeciya(){
    float Sum3 =0;
    for(int i =0; i<n; i++){
        float x1 = a + i*h;
        float x2= a+(i+1)*h;

        Sum3-= 0.5*(x2-x1)*(f(x1)+f(x2));

    }

    std::cout<<"Trapeciya^-^ =  "<<Sum3;
    std::cout<<endl;

}


float runge(float s1, float s2)
{
    s1 = (fabs(s1 - s2))/15;
    return s1;
}

int main()
{
   funcPrammoug();
   funcSimpson(0,-1,384);    //(0,-1,384);
   trapeciya();


   std::cout<<endl;
   std::cout <<"Runge *_*  =   " << runge(Sum1, Sum2) << std::endl;
   std::cout<<endl;

   //формулы вычисления разности методов и результата калькулятора
   error1 = fabs(Z - error1);
   error2 = fabs(Z - error2);
   //вывод ошибок
   std::cout << "ERROR_1: " << error1 << std::endl;
   std::cout << "ERROR_2: " << error2  << std::endl;

    return 0;
}
