/*input
3
6
2
2
2
0.6667
0.3333
1
2
-1
-2
1
0
*/
#include <iostream>
using namespace std;

int main(){

    int size;
    float a[50][50],b[50],h,x[50];

    cout<<"Enter the size of matrix"<<endl;
    cin>>size;

    cout<<"Enter the Co-efficients of equations"<<endl;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cin>>a[i][j];
        }
    }

    cout<<"Enter the Right hand Side matrix"<<endl;
    for (int i = 0; i < size; i++)
    {
        cin>>b[i];
    }

    cout<<"Co-efficients of equations"<<endl;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout<<a[i][j]<<"  ";
        }
        cout<<endl;
    }

    cout<<"Right hand Side matrix"<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<b[i]<<endl;
    }

    for (int i = 0; i < size; ++i)
    {
        for (int j = i+1; j <  size; j++)
        {
            h=a[j][i];
            for (int k = 0; k < size; k++)
            {
                a[j][k]=a[j][k] - ((h/a[i][i])*a[i][k]);
            }
        }
    }
    cout<<"Upper triangle matrix"<<endl;
    cout<<"Enter the Co-efficients of equations"<<endl;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout<<a[i][j]<<"  ";
        }
        cout<<endl;
    }

    x[size-1]=b[size-1]/a[size-1][size-1];
    float sum=0;
    cout<<x[size-1]<<endl<<endl;
    for(int i=size-2;i>=0;i++){
        for(int j=i+1;j<=size-1;j++){
           sum = sum + a[i][j]*x[j];
           x[i]=(b[j]-sum)/a[i][i];
           cout<<"x("<<i<<") : " <<x[i]<<endl;
        }

    }

    cout<<"Variable"<<endl;

    for (int i = 0; i < size; ++i)
    {
        cout<<"x("<<i<<") :"<<x[i]<<endl;
    }


    return 0;
}