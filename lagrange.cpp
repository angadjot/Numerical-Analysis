#include <iostream>
using namespace std;

void poly(float *poly_x,float *poly_fx,float val,float size);
void printline();
int main(){
    
    int n;
    cout<<"Enter the Number of Values"<<endl;
    cin>>n;
    float x[n],fx[n],input;
    
    printline();
    cout<<"Enter the values of x"<<endl;
    for (int i=0;i<n; i++) {
        cin>>x[i];
    }
    
    printline();
    cout<<"Enter the values of f(x)"<<endl;
    for (int i=0;i<n; i++) {
        cin>>fx[i];
    }
    printline();
    cout<<"\tCorresponding Table :"<<endl;
    printline();
    cout<<"\t    x \t f(x)"<<endl;
    printline();
    for (int i=0;i<n; i++) {
        cout<<"\t    "<<x[i]<<"\t "<<fx[i]<<endl;
    }
    printline();
    
    cout<<"Enter the Input"<<endl;
    cin>>input;
    
    printline();
    poly(x,fx,input,n);
    
    return 0;
}

void poly(float *poly_x,float *poly_fx,float val,float size){
    
    float pn=0;
    
    for (int i=0; i<size; i++) {
        float mul=1,div=1;
        
        for (int j=0;j<size; j++) {
            if (i==j) {
                continue;
            }
            else{
                mul=mul*(val - poly_x[j]);
                div=div*(poly_x[i]-poly_x[j]);
            }
        }
        
        pn=pn+(mul * (poly_fx[i]) / div);
    }
    
    cout<<pn<<endl;
    
}

void printline(){
    for (int i=0; i<50; i++) {
        cout<<"-";
    }
    cout<<endl;
}