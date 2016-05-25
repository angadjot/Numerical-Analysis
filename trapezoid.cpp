#include <iostream>
using namespace std;

void printline(){
    for(int i=0;i<50;i++)
        cout<<"-";
    cout<<endl;
}

float fun(float  x){
    return 1/(1+x);
}

int main(){

    float a,b,h,s;
    int n;

    printline();
    cout<<"Enter the Interval [a,b] and number of Intervals(n)"<<endl;
    printline();
    cout<<"Enter the value of a: ";
    cin>>a;
    cout<<"Enter the Value of b: ";
    cin>>b;
    cout<<"Enter the Value of n: ";
    cin>>n;

    h=(b-a)/n;
    s=fun(a)+fun(b);

    for(int i=1;i<=n-1;i++){
        s += 2*fun(a+i*h);
    }

    cout<<"The Value of Intergaral is: "<<(h/2)*s<<endl;
    return 0;
}