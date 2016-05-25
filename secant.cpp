#include<iostream>
#include<math.h>
using namespace std;

void printline();
float f(float x);
void secant(float ,float ,float);

int main(){

  	float a,h,xn,b,err;

	cout<<"Enter the initial guess for finding root"<<endl;
	cin>>a;
	cout<<"Enter the increment value"<<endl;
	cin>>h;
	cout<<"Enter the acceptable error"<<endl;
	cin>>err;

	for(int i=0;;i++){
		if((f(a)*f(a+h))<=0){
			cout<<"Roots of the function lies in interval ["<<a<<","<<a+h<<"]"<<endl;
			xn=a;
			b=a+h;
			break;
		}
		else{
			a=a+h;
		}
	}

  	secant(xn,b,err);
	return 0;
}

void printline(){

	for(int i=0;i<50;i++){
		cout<<"-";
	}
	cout<<endl;
}

float f(float x){
	float result;
	result = (pow(x,3)-pow(x,2)-x-1);
	return(result);
}

void secant(float x1,float x2,float error){

    float x3,f1,f2;
	printline();
  	cout<<"x1\t  x2\t  x3\t     f(x1)\t f(x2)"<<endl;
 	printline();

	do{
        f1=f(x1);
        f2=f(x2);
	 	x3=x2-((f2*(x2-x1))/(f2-f1));
  		cout<<x1<<"   "<<x2<<"   "<<x3<<"   "<<f1<<"   "<<f2<<endl;
  		x1=x2;
  		x2=x3;
  	}while(fabs(f2)>error);

	printline();
	cout<<"App.root = "<<x3<<endl;
}
