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
float n =2400;  //2400
float x = a;
float h = (b-a)/n;

float Z = - 0.00106096; //полный результат интегрирования


float error1 = 0;
float error2 = 0;
float error3 = 0;

float f(float x){
        return ((-3)/((15*x-9)*(15*x-9)*(15*x-9))) ;
        }

void funcPrammoug(){
/*
    for(int j = 0; j<n;j++){
        Sum1-=f(x)*h;
        x+=h;
    }

    std::cout<<"Pryamoug^-^(Integral)  =  "<<Sum1<<"\t";
    error1 = Sum1-(- 0.00106096);
    std::cout<<"Error = "<<error1;
*/

    for(int j = 0; j<n;j++){
        while(a<=0){
            a=a+h;
            Sum1-=f(x)*h;
            x+=h;

        }
        std::cout<<"Pryamoug^-^(Integral)  =  "<<Sum1<<"\t";
        error1 = Sum1-(- 0.00106096);
        a=-3;
        Sum1=0;
        h=h/2;
        std::cout<<"h/2 shag = = "<<j+1<<"h= "<<h<<"\t"<<"Error1 ="<<error1<<"\n";

    }


}


void funcSimpson(){
    float x1,x2;
    for (int i =0; i<n; i++){
        x1 = a + i * h;
        x2 = a + (i+1)*h;

        Sum2 -= (x2-x1)/6.0*(f(x1)+4.0*f(0.5*(x1+x2))+f(x2));
    }

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
    std::cout<<"n = "<<n<<std::endl;
   funcPrammoug();
   /*
   funcSimpson();
  // funcSimpson(0,-1,384);    //(0,-1,384);
   trapeciya();


   std::cout<<endl;
   std::cout <<"Runge *_*  =   " << runge(Sum1, Sum2) << std::endl;
   std::cout<<endl;

   //формулы вычисления разности методов и результата калькулятора
   //error1 = fabs(Z - error1);
   //error2 = fabs(Z - error2);

   //вывод ошибок
   //std::cout << "ERROR_1: " << error1 << std::endl;
   //std::cout << "ERROR_2: " << error2  << std::endl;
*/
    return 0;
}
