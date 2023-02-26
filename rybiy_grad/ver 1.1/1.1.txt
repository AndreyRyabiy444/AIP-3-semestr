#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
//функция по условию    ((x1+ x2 ^2)^2)

//запись градиента
float gradient(float* x, float* g)
{
        g[0]= 2 * (x[0] + x[1] * x[1]);
        g[1]= 4 * x[1] * (x[0] + x[1] * x[1]);
}


float func(float* x)
{
    return (x[0] + x[1] * x[1]) * (x[0] + x[1] * x[1]);
}

int main()
{
        ofstream f;
        f.open("data.csv");
        float g[2]={0,0};
        float k=1;
    //условие по варианту
        float x[2] = { -1, 5 };
     f<<k<< "\t" << x[0] <<"\t"<< x[1]<<"\t"<< func(x)<<"\t"<<"\n";
    //обьявление переменных лямбда(шаг), экспонента(точность), норма
        float lambda=0.01;
        float eps = 0.001;
        float xp[2] = { 0,0 };

        while(sqrt((x[1]-xp[1])*(x[1]-xp[1])+(x[0]-xp[0])*(x[0]-xp[0]))>eps){

            xp[0]=x[0];
            xp[1]=x[1];

            gradient(x,g);
            x[0]-=lambda*g[0];
            x[1]-=lambda*g[1];
//            VOLUME          COORDINATA        ZNACHENIE FUNC В ДАННОЙ ТОЧКЕ
            f<<k<< "\t" << x[0] <<"\t"<< x[1]<<"\t"<< func(x)<<"\t"<<"\n";
            k++;
        }
            f.close();
}

/*
//условие по варианту
float x[2] = { -1, 5 };
//обьявление переменных лямбда(шаг), экспонента(точность), норма
float lambda=0.01;
float eps = 0.001;
float norm = 1;
float xp[2] = { 0,0 };

int k = 1;
std::cout<< "Volume  " << '\t'<< "  Metod 1  " << '\t' << "Metod 2" << '\t'<< "                Norma  " << std::endl;
while (norm > eps)
{

    xp[0] = x[0];
    xp[1] = x[1];

    x[0] -= lambda * gradient(x, 0);
    x[1] -= lambda * gradient(x, 1);

    norm = func(xp)-func(x);

    cout << k << '\t' << '\t'
         << x[0] << '\t ' << '\t'
         << x[1] << '\t' << '\t'
         << func(x) << endl;
    k++;
}
*/
