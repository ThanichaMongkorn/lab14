#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}

void updateImage(bool image[N][M],int s,int x,int y){
    int i=0;
    int j=0;
    while(i<30){
        j=0;
        while(j<70){
            if(sqrt(pow((i-x),2)+pow((j-y),2))<=s-1){
                image[i][j]=1;
            }
            j++;
        }

    i++;
    }
}

void showImage(const bool image[N][M]){
    cout << "------------------------------------------------------------------------\n";
    int i=0;
    int j=0;
    while(i<30){
        cout <<"|";
        j=0;
        while(j<70){

            if(image[i][j]==1){
                cout <<"*";
            }else{
                cout <<" ";
            }
            j++;
        }
        cout <<"|\n";
    i++;
    }
    cout << "------------------------------------------------------------------------\n";
}