#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

class vector{
public:
    int dim;
    double* arr;
public:
    vector():dim(0), arr(nullptr){}
    explicit vector(int dim):dim(dim){
        arr = new double[dim];
    }
    vector(int dim,double* arr1):dim(dim), arr(new double[dim]){
        std::memcpy(arr, arr1, dim*sizeof(double));
    }
    vector(const vector& v):vector(v.dim, v.arr){}
    vector(std::initializer_list<double> list):dim(list.size()),arr(new double[dim]){
        std::memcpy(arr,list.begin(),sizeof(double)*list.size());
    }
    ~vector(){
        delete[] arr;
    }
public:
    vector& operator=(std::initializer_list<double> list){
        if(arr!= nullptr){
            delete[] arr;
        }
        dim = list.size();
        arr = new double[dim];
        std::memcpy(arr, list.begin(),sizeof(double)*list.size());
        return *this;
    }
    vector& operator=(const vector& v){
        if(arr!= nullptr){
            delete[] arr;
        }
        if(this == &v){
            return *this;
        }
        dim = v.dim;
        arr = new double[dim];
        memcpy(arr, v.arr, sizeof(double)*v.dim);
        return *this;
    }
    vector operator+()const{
        return *this;
    }
    vector operator-()const{
        vector copy = *this;
        for (int i = 0; i < dim; ++i) {
            copy.arr[i] = -arr[i];
        }
        return copy;
    }
    vector& operator+=(const vector& v){
        if(dim!=v.dim){
            throw std::invalid_argument("Vectors are must be same dimension");
        }
        for (int i = 0; i < dim; ++i) {
            arr[i]+=v.arr[i];
        }
        return *this;
    }
    vector& operator-=(const vector& v){
        return *this+=(-v);
    }
    vector& operator*=(const vector& v){
        if((*this).dim!=3||v.dim!=3){
            throw std::invalid_argument("Vectors dimension are must be 3");
        }
        vector copy(*this);
        for (int i = 0; i < 3; ++i) {
            (*this).arr[i] = copy.arr[(i+1)%3]*v.arr[(i+2)%3]-copy.arr[(i+2)%3]*v.arr[(i+1)%3];
        }
        return *this;
    }
    vector& operator*=(double k){
        for (int i = 0; i < dim; ++i) {
            arr[i]*=k;
        }
        return *this;
    }
    vector& operator/=(double k){
        for (int i = 0; i < dim; ++i) {
            arr[i]/=k;
        }
    }
    bool operator==(const vector& v)const{
        if(dim == v.dim){
            for (int i = 0; i < dim; ++i) {
                if(arr[i] != v.arr[i]){
                    return false;
                }
            }
            return true;
        }
        else{
            return false;
        }
    }
    bool operator!=(const vector& v)const{
        return !(*this == v);
    }
public:
    double module()const{
        double answer = 0;
        for (int i = 0; i < dim; ++i) {
            answer+=arr[i]*arr[i];
        }
        return sqrt(answer);
    }
    void print()const{
        for (int i = 0; i < dim; ++i) {
            std::cout<<arr[i]<<" ";
        }
        std::cout<<'\n';
    }

};
vector operator+(const vector& v1, const vector& v2){
    if(v1.dim!=v2.dim){
        throw std::invalid_argument("Vectors are must be same dimension");
    }
    double* arr = new double[v1.dim];
    for (int i = 0; i < v1.dim; ++i) {
        arr[i]=v1.arr[i]+v2.arr[i];
    }
    return vector(v1.dim,arr);
}
vector operator-(const vector& v1, const vector& v2){
    if(v1.dim!=v2.dim){
        throw std::invalid_argument("Vectors are must be same dimension");
    }
    double* arr = new double[v1.dim];
    for (int i = 0; i < v1.dim; ++i) {
        arr[i]=v1.arr[i]-v2.arr[i];
    }
    return {v1.dim,arr};
}
vector operator*(const vector& v1, const vector& v2){
    if((v1).dim!=3||v2.dim!=3){
        throw std::invalid_argument("Vectors dimension are must be 3");
    }
    vector copy(v1.dim);
    for (int i = 0; i < 3; ++i) {
        (copy).arr[i] = v1.arr[(i+1)%3]*v2.arr[(i+2)%3]-v1.arr[(i+2)%3]*v2.arr[(i+1)%3];
    }
    return copy;
}
vector operator*(const vector& v, double k){
    vector copy(v);
    return copy*=k;
}
double operator,(const vector& v1, const vector& v2){
    if(v1.dim!=v2.dim){
        throw std::invalid_argument("Vectors are must be same dimension");
    }
    double answer = 0;
    for (int i = 0; i < v1.dim; ++i) {
        answer+=v1.arr[i]*v2.arr[i];
    }
    return answer;
}
