#include <iostream>
#include <math.h>
using namespace std;

float fun(float x,float y){
  return x+sqrt(y);
}

int main(){

  float y0,x0,y1,x1,y1_0,n,h;
  int j=1,count,flag;

  cout<<"Enter the value of x0: ";
  cin>>x0;
  cout<<"Enter the value of y0: ";
  cin>>y0;
  cout<<"Enter the value of h: ";
  cin>>h;
  cout<<"Enter the value of last point of the interval: ";
  cin>>n;
  for(x1=x0+h; x1<=n; x1=x1+h){

    count=0;
    flag=0;
    y1_0 = y0 + (h * fun(x0,y0));
    cout<<"y"<<j<<"(0) = "<<y1_0<<endl;
    do{
      count++;
      y1 = y0 + h/2 * ( fun(x0,y0) + fun(x1,y1_0));
      cout<<" x = "<<x1<<" => y"<<j<<"("<<count<<") = "<<y1<<endl;
      if(fabs(y1-y1_0)<0.0001){
        cout<<" y"<<j<<" = "<<y1<<endl;
        flag=1;
      }
      else
        y1_0 = y1;
      }while(flag!=1);
    y0 = y1;
    x0 = x1;
    j++;
  }

    return 0;
}