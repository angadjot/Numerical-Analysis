#include <iostream>
#include <math.h>
using namespace std;

#define ESP 0.0001
#define F(x) (x)*(exp(x)) = 1
#define X(x) (exp(-x))
#define G(x) -(exp(x))


int main(){
  float x1,x2,x;
  int i=1;

  do
  {
    cout<<"\nEnter the value of x: ";
    cin>>x;
  }while(fabs(G(x)) > 1);

  x1=X(x);
  cout<<"\n x = "<<x1<<endl<<endl;
  do
  {
   x2=X(x1);
   if(fabs(x1-x2)<ESP)
   {
    cout<<"\n\nREAL ROOT = "<<x1;
    i=0;
   }
   else
   {
    x1=x2;
   }
  if(i==1){
    cout<<endl<<" x = "<<x1;
  }
  }while(i!=0);

  return 0;
}