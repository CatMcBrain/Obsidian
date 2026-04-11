#include<stdio.h>

const int L = 100;
const float Du = 1;
const float Dv = 10;
const float a = 0.1;
const float b = 0.9;
const float dt = 0.01; // segundos
const int T = 200 ; // segundos

void laplace(float (*m)[L][L]){ // 3) Laplaciano
	for(int i=0; i<L; i++){
		for(int j=0; j<L; j++){
			(*m)[i][j] = (*m)[i+1][j]+(*m)[i-1][j]+(*m)[i][j+1]+(*m)[i][j-1]-4*(*m)[i][j];
		}
	}
}

float timestep(float (*m)[L][L], char mode){ // 4) Actualización temporal
	float res[L][L] = {};
	int n = 0;
	float var = 0; // para englobar el caso de u y el de v en una sóla función

	for(int t=0; t<=T; t++){ // paso del tiempo
		for(int i=0; i<L; i++){
			for(int j=0; j<L; j++){
				if (t != 0){ // condición periódica
					n = t-1;
				}else{
					n = T;
				}
				(*m)[i][j] = 0; // ecuación de actualización temporal
			}
		}
	}
}

int main(){

	float redu[L][L] = {};
	float redv[L][L] = {};

	// me falta saber inicializar la red
	// luego meter perturbaciones
	


	return 0;
}