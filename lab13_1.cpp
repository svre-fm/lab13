#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double num[],int N ,double ans[]){
    double sum = 0;
    for(int i = 0; i < N ; i++){
        sum += num[i];
    }
    ans[0] = sum/N;

    double suminsqr = 0;
    for(int i = 0; i < N; i++){
        suminsqr += pow(num[i]-ans[0],2);
    }
    ans[1] = sqrt(suminsqr/N);

    double sumGM = 1;
    for(int i = 0; i < N;i++){
        sumGM *= num[i];
    }
    ans[2] = pow(sumGM,1.00/N);

    double sumHM = 0;
    for(int i = 0; i < N;i++){
        sumHM += 1.0/num[i];
    }
    ans[3] = N/sumHM;

    double max = num[0],min = num[0];
    for(int i = 0; i < N;i++){
        if(num[i] >= max) max = num[i];
        if(num[i] < min) min = num[i];
    }
    ans[4] = max;
    ans[5] = min;
}