#include<iostream>

using namespace std;


void creation(int dArray[2][2][5]){
	int i,j,k,num;
	for(i=0;i<2;i++){
		for(j=0 ; j<2 ; j++){
			for(k=0;k<5;k++){
				cout<<"Enter the element of the Array[";
				cout<<i<<"]["<<j<<"]["<<k<<"] : ";
				cin>>num;
				dArray[i][j][k]=num;
			}
		}
	}
}
				
void sorting(int dArray[2][2][5]){
	int i,j,k,l;
	for(i=0;i<20;i++){
		for(j=0 ; j<2 ; j++){
			for(k=0;k<2;k++){
				for(l=0;l<4;l++){
					if (dArray[j][k][l]>dArray[j][k][l+1]){
						int a = 0;
						a = dArray[j][k][l+1];
						dArray[j][k][l+1] = dArray[j][k][l];
						dArray[j][k][l] = a;
						
							
					}
					if(l==3 && dArray[j][k][l+1]>dArray[j][k+1][0]){
						int b = 0;
						b = dArray[j][k+1][0];
						dArray[j][k+1][0]=dArray[j][k][l+1];
						dArray[j][k][l+1] = b;
					}
					if(l==3 && k==1 && dArray[j][k][l+1]>dArray[j+1][0][0]){
						int c = 0;
						c = dArray[j+1][0][0];
						dArray[j+1][0][0]=dArray[j][k+1][l+1];
						dArray[j][k+1][l+1]=c;
						
					}
						
					else{
						continue;
					}
				}
			}
		}
	}
}

void printing(int dArray[2][2][5]){
	int i,j,k,num;
	cout<<endl<<"--output of 3d Array in sorted form-- "<<endl<<endl;
	for(i=0;i<2;i++){
		for(j=0 ; j<2 ; j++){
			for(k=0;k<5;k++){
				cout<<"Array["<<i<<"]["<<j<<"]["<<k<<"] : ";
				cout<<dArray[i][j][k]<<"	";
				cout<<endl;
			}

		}
	}
}


int main(){
	int dArray[2][2][5];
	creation(dArray);
	sorting(dArray);
	printing(dArray);
	return 0;
}

