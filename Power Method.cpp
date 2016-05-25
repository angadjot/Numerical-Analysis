#include <iostream>
#include <math.h>
using namespace std;

int main(){

    int size;
    float array[100][100],x[100],z[100],e[100],zmax,emax;

    cout<<"Enter the Size of Co-efficient Matrix"<<endl;
    cin>>size;

    cout<<"Enter the Co-efficients"<<endl;
    for (int i=0;i<size;i++){
        for(int j=0; j<size;j++){
            cin>>array[i][j];
        }
    }

    cout<<"Enter the starting Eigen Vector"<<endl;
    for(int i=0;i<size;i++){
        cin>>x[i];
    }

    do{
        for(int i=0;i<size;i++){
            z[i]=0;
            for(int j=0;j<size;j++){
                z[i]=z[i]+(array[i][j]*x[j]);
            }
        }

        zmax=fabs(z[0]);
        for (int i=1;i<size;i++){
            if(zmax<fabs(z[i])){
                zmax=fabs(z[i]);
            }
        }

        for(int i=0;i<size;i++){
            z[i]=z[i]/zmax;
        }

        for(int i=0;i<size;i++){
            e[i]=0;
            e[i]=fabs( (fabs(z[i])) - (fabs(x[i])) );
        }

        emax=fabs(e[0]);

        for(int i=1;i<size;i++){
            if(e[i]>emax){
                emax=e[i];
            }
        }

        for(int i=0;i<size;i++){
            x[i]=z[i];
        }
    }while(emax>=0.001);

    cout<<"The required Eigen Value is "<<zmax<<endl;
    cout<<"The Required Eigen Vector is :"<<endl;
    for(int i=0;i<size;i++){
        cout<<z[i]<<"\t";
    }
    cout<<endl;

    return 0;
}