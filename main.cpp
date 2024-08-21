#include <iostream>
#include "calculator_of_electric_field.h"
int main(){
    calculator c;
    vector v = c.calculate(10,20,2,10);
    v.print();
    /*int k = 30;
    std::vector<double> v3(1),v4(1);
    for(double x = 0.2;x<0.2+k*0.05;x+=0.05){
        vector v = ((c.calculate_h(0.1,x,x,1))*x*x);
        v3.push_back(x);
        v4.push_back(v.arr[0]);
    }
    for(auto el:v3){
        std::cout<<el<<',';
    }
    std::cout<<'\n';
    for(auto el:v4){
        std::cout<<el<<',';
    }*/
}
