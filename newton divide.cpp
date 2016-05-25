/*input
4
0
1
3
5
1
2
6
7
1
*/
#include<iostream>
using namespace std;

int main(){

    int n,k=0;
    float x[100],fun[100][100],sum=0,mul=1,input;
    cout<<"Enter the Number of Values of x"<<endl;
    cin>>n;

    cout<<"Enter the value of x"<<endl;
    for(int i=0;i<n;i++){
        cout<<"x("<<i<<") : ";
        cin>>x[i];
    }
    cout<<endl;

    cout<<"Enter the corresponding Values of function f(x):"<<endl;
    for(int i=0;i<n;i++){
        cout<<"f(x"<<i<<") :";
        cin>>fun[k][i];
    }
    cout<<endl;

    for(int i=1;i<n;i++){
        k=i;
        for(int j=0;j<n-i;j++){
            fun[i][j]=(fun[i-1][j+1]-fun[i-1][j])/(x[k]-x[j]);
            k++;
        }
    }

    for(int i=0;i<n;i++){
        printf("\n %.3f",x[i]);
        for(int j=0;j<n-i;j++){
            cout<<"  ";
            printf(" %.3f",fun[j][i]);
        }
    }
    sum = fun[0][0];
    cout<<"Enter the value of x to find P(x): ";
    cin>>input;
    cout<<endl;
    for(int i=0;i<n-1;i++){
        mul=mul*(input - x[i]);
        sum=sum+mul*fun[0][i];
    }

    cout<<"P("<<input<<") : "<<sum;

    return 0;
}