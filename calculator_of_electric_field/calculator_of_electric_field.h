#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <string>
#include <array>
#include "vector.h"
double roundToNDecimals(double value, int n) {
    double scale = std::pow(10, n);
    return std::round(value * scale) / scale;
}
struct calculator{
    vector calculate_h(double a, double x, double y, int N){
        double delta = a/N;
        vector E{0,0};
        for (double x1 = delta/2; x1 < a; x1+=delta) {
            for (double y1 = delta/2; y1 < a; y1+=delta) {
                E+= calculate(x1,y1,x,y,double(1)/(N*N));
            }
        }
        return E;
    }
    vector calculate(double a, double x, double y, int d)//погрешность до d ого знака после запятой
    {
        vector E1{0,0};
        vector E2{0,0};
        int N = 10;
        do{
            E1 = E2;
            E2 = calculate_h(a,x,y,N);
            N*=2;
        } while (std::abs(E2.arr[0] - E1.arr[0]) > pow(10,-d) || std::abs(E2.arr[1] - E1.arr[1]) > pow(10,-d));
        E2.arr[0] = roundToNDecimals(E2.arr[0],d);
        E2.arr[1] = roundToNDecimals(E2.arr[1],d);
        return E2;
    }
    vector calculate(double x1, double y1, double x2, double y2, double q) //поле заряда (x1,y1) в точке (x2,y2)
    {
        vector v{x2-x1,y2-y1};
        double k = q/pow(v.module(),3);
        return v*=k;
    }
};

