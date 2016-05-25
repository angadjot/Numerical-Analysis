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
#include<iostream>
using namespace std;

void printline();
void display(float arr[100][100],int size);
void uppertriangle(float array[100][100],int size);

int main(){

    int size;
    float array[100][100],x[50],b[50];
    cout<<"Enter the Size of the Square Matrix"<<endl;
    cin>>size;

    cout<<"Enter the Elements of the matrix in row-wise fashion"<<endl;

    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            cin>>array[i][j];
        }
    }
    cout<<"Enter the Right hand Side matrix"<<endl;
    for (int i = 0; i < size; i++)
    {
        cin>>b[i];
    }

    display(array,size);
    uppertriangle(array,size);
    display(array,size);


    x[size-1]=b[size-2]/array[size-1][size-1];
    float sum=0;
    cout<<x[size-1]<<endl<<endl;
    for(int i=size-2;i>=0;i++){
        for(int j=i+1;j<=size-1;j++){
           sum = sum + array[i][j]*x[j];
           x[i]=(b[j]-sum)/array[i][i];
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

void display(float arr[100][100],int size){

    printline();
    cout<<"Elements of Matrix are : "<<endl;
    printline();

    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }

    printline();
}

void uppertriangle(float array[100][100],int size){

    float h;

    for (int i=0; i<size; i++) {
        for (int j=i+1; j<size; j++) {
            h=array[j][i];
            for (int k=0; k<size; k++) {
                array[j][k]=array[j][k]-(h * array[i][k]/array[i][i]);
            }

        }
    }

}

void printline(){
    for (int i=0; i<50; i++) {
        cout<<"-";
    }
    cout<<endl;
}