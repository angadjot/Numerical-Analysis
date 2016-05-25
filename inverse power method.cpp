#include <iostream>
#include <math.h>
using namespace std;

void display(float a[100][100],int size);

int main(){

    int size;
    float array[100][100],inverse[100][100],x[100],z[100],e[100],zmax,emax,determinant=0;

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

    for(int i=0;i<size;i++){
        determinant = determinant + (array[0][i]* (array[1][(i+1)%size]*array[2][(i+2)%size] - array[1][(i+2)%size]*array[2][(i+1)%size]) );
    }
    if(determinant == 0){
        cout<<"Inverse does not exist (Determinant=0)"<<endl;
    }
    else{
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                inverse[i][j]=((array[(i+1)%size][(j+1)%size] * array[(i+2)%size][(j+2)%size]) - (array[(i+1)%size][(j+2)%size]* array[(i+2)%size][(j+1)%size]))/ determinant;
            }
        }
    }

    cout<<"Matrix :"<<endl;
    display(array,size);
    cout<<endl;
    cout<<"Inverse Matrix: "<<endl;
    display(inverse,size);
    cout<<endl;

    do{
        for(int i=0;i<size;i++){
            z[i]=0;
            for(int j=0;j<size;j++){
                z[i]=z[i]+(inverse[i][j]*x[j]);
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

    zmax=(1/zmax);
    cout<<"The required Eigen Value is "<<zmax<<endl;
    cout<<"The Required Eigen Vector is :"<<endl;
    for(int i=0;i<size;i++){
        cout<<z[i]<<"\t";
    }
    cout<<endl;

    return 0;
}

void display(float a[100][100],int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
}