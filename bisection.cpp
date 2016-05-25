#include <iostream>
using namespace std;

float f(float x);
void bisection(float a,float b,float error);

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

	bisection(xn,b,err);

	return(0);
}

float f(float x){
	float result;
	result = ((x*x)-29);
	return(result);
}

void bisection(float a,float b,float error){

	float c;
	c=(a+b)/2;
	while(f(c)!=0 || (b-a)>error){
		c=(a+b)/2;
		if((f(a)*f(c))<0){
			b=c;
		}
		else if((f(c)*f(b))<0){
			a=c;
		}
		else if(f(c)==0){
			cout<<"Root : "<<c<<endl;
		}
	}

	cout<<"Root of function lies in [ "<<a<<","<<b<<"]"<<endl;

}
