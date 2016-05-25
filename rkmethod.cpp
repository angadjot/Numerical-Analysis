#include <iostream>
using namespace std;

float func(float x,float y){
    return (y*y-x*x)/(y*y+x*x);
}

int main(){
    float K, K1, K2, K3, K4;
    float x0 , y0, x, y;
    int j, n;
    float i, H;
    cout<<"Enter initial value of x: ";
    cin>>x0;
    cout<<"Enter initial value of y: ";
    cin>>y0;
    cout<<"Enter no iteration: ";
    cin>>n;
    cout<<"Enter the interval: ";
    cin>>H;
    x = x0;
    y = y0;
    for(i = x+H, j = 0; j < n; i += H, j++){
        K1 = H * func(x , y);
        K2 = H * func(x+H/2, y+K1/2);
        K3 = H * func(x+H/2, y+K2/2);
        K4 = H * func(x+H, y+K3);
        K = (K1 + 2*K2 + 2*K3 + K4)/6;
        x = i;
        y = y + K;
        cout<<"At  x = "<<x<<", y = "<<y<<endl;
    }

    return 0;
}