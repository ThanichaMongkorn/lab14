#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    int i=0;
    double sumM=0;
    while(i<N){
        sumM = A[i]+sumM;
        i++;
    }
    B[0]=sumM/N;
    
    //หาส่วนเบี่ยงเบนมาตรฐาน
    double sumSD=0;
    i=0;
    while(i<N){
        sumSD=(A[i]*A[i])+sumSD;
        i++;
    }
    B[1]=pow(((sumSD/N)-(B[0]*B[0])),0.5);
    

    double sumGM=1;
    i=0;
    while(i<N){
        sumGM=A[i]*sumGM;
        i++;
    }
    B[2]=pow(sumGM,1.0/N);
    
    
    double sumHM=0;
    i=0;
    while(i<N){
        sumHM=(1/A[i])+sumHM;
        i++;
    }
    B[3]=N/sumHM;
    
    
    double max=A[0];
    i=0;
    while(i<N){
        if(A[i]>max){
        max=A[i];
        }
        i++;
    }
    B[4]=max;
    
    
    double min=A[0];
    i=0;
    while(i<N){
        if(min>A[i]){
            min=A[i];
        }
        i++;
    }
    B[5]=min;
    
}