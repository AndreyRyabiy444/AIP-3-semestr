#include <iostream>
#include <cmath>

using namespace std;

double func(double x) {
    return ((x * x) + 4/x);

}
int main()
{
//Условия
    double a = 0.5;
    double b = 3.5;
//Точность
    double E = 0.01;
//Шаг
    double del = 0.001;
    int k=1;
    std::cout<< "Volume"<< '\t' <<"a" << '\t'<< "b"<<'\t'<< "Metod" << '\t' << "Tochnoe" << '\t'<< std::endl;
    std::cout<< k <<'\t'<< a <<'\t'<< b <<'\t'<< "2" << '\t' << "6" << '\t'<< std::endl;
    while (b - a > E) {
        k++;

        double x1 = (a + b- del) / 2 ;
        double x2 = (a + b+ del) / 2 ;
        if (func(x1) < func(x2)) {
            b = x2;
        }
        else {
            a = x1;
        }
        double x = (a + b) / 2;

//вывод:кол-во итераций /значение методом/значение Х точное/ ошибка

        std::cout<< k <<'\t'<< a <<'\t'<< b <<'\t'<< x << '\t' << func(x) << '\t'<< std::endl;

    }
    return 0;
}


