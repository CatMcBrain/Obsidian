#include<stdio.h>

const int L = 100;
const float Du = 1;
const float Dv = 10;
const float a = 0.1;
const float b = 0.9;
const float dt = 0.01; // segundos
const float T = 200 ; // segundos

void laplace(float *m[][], int n){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			*m[i][j] = m[i+1][j]+m[i-1][j]+m[i][j+1]+m[i][j-1]-4*m[i][j];
		}
	}
}
int main(){

	float red[L][L] = {};


	return 0;
}