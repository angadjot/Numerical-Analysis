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
*/
#include <iostream>
using namespace std;

void printline();
float function(float t);

int main(){

	int n,k=0;
	float x[100],fun[100][100];

	cout<<"Enter the Number of Values of x"<<endl;
	cin>>n;
	printline();
	cout<<"Enter "<<n<<" Values of x"<<endl;
	for(int i=0;i<n;i++){
		cin>>x[i];
	}

	cout<<"Enter the corresponding Values of function f(x):"<<endl;
    for(int i=0;i<n;i++){
        cout<<"f(x"<<i<<") :";
        cin>>fun[k][i];
    }
    cout<<endl;

	for(int i=1;i<n;i++){
		k=i;
		for(int j=0;j<n-i;j++){
			fun[i][j]=(fun[i-1][j+1]-fun[i-1][j])/x[k]-x[j];
			k++;
		}
	}

	printline();
	cout<<"\n  x(i)\t   y(i)\t";
	for(int i=1;i<=n-1;i++){
		cout<<"y"<<i<<"(i)\t";
	}
	cout<<endl;
	printline();

	for(int i=0;i<n;i++){
		printf("\n %.3f",x[i]);
		for(int j=0;j<n-i;j++){
			cout<<"  ";
			printf(" %.3f",fun[j][i]);
		}
	}
	cout<<endl;
	printline();
	return(0);
}


void printline(){

	for(int i=0;i<50;i++){
		cout<<"-";
	}
	cout<<endl;
}
