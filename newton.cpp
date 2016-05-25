//newton raphson method
#include <iostream>
using namespace std;

float f(float x);
float g(float y);
void newton(float a);

int main(){

	float a,h,xn;
	a=-10;
	h=0.1;

	while(true){
		if((f(a)*f(a+h))<=0){
			cout<<"Roots of the function lies in interval ["<<a<<","<<a+h<<"]"<<endl;
			xn=a;
			break;
		}
		else{
			a=a+h;
		}
	}

	newton(xn);

	return(0);
}

float f(float x){
	float result;
	result = ((x*x)-5);
	return(result);
}

float g(float y){
	float result;
	result=2*y;

	return(result);

}
void newton(float a){

	float xn, xn_1,fun,der;
	xn = a;
	while(true){

		fun = f(xn);
		der = g(xn);

		xn_1 = xn - (fun/der);

		xn = xn_1;

		if((xn_1 - xn) <= 0.005){
			break;
		}
		else
			continue;
	}

	cout<<"Root of function = "<<xn_1<<endl;

}
