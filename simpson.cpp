#include <iostream>
using namespace std;

void printline(){
    for(int i=0;i<50;i++)
        cout<<"-";
    cout<<endl;
}

float fun(float  x){
    return x*x - 4;
}

int main(){

    float a,b,h,s,sum1=0,sum2=0;
    int n,count;

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


    for(int i=1;i<= (n/2)-1;i++){
        sum1 += 2*fun(a+(2*i*h));
    }
    for(int i=1;i<=n/2;i++){
        count = (2*i)-1;
        sum2 += 4*fun(a+count*h);
    }

    cout<<"The Value of Intergaral is: "<<(h/3)*(s+sum1+sum2)<<endl;
    return 0;
}