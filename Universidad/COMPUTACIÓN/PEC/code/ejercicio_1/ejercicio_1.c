#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

const int L = 100;
const float Du = 1;
const float Dv = 10;
const float a = 0.1;
const float b = 0.9;
const float dt = 0.01; // segundos
const int T = 200 ; // segundos

const int archNum = 10; // número de archivos deseados
const int archStep = 200; // paso temporal de cada archivo nuevo

void mlaplace(float (*m)[L][L]){ // 3) Laplaciano
	for(int i=0; i<L; i++){
		for(int j=0; j<L; j++){
			(*m)[i][j] = (*m)[i+1][j]+(*m)[i-1][j]+(*m)[i][j+1]+(*m)[i][j-1]-4*(*m)[i][j];
		}
	}
}

float laplace(float m[L][L], int a, int b){
	return  m[a+1][b]+m[a-1][b]+m[a][b+1]+m[a][b-1]-4*m[a][b] ;
}

void timestep(float u[L][L], float v[L][L]){ // 4) Actualización temporal
	// En t = 0, será el estado inicial de u y v
	float buffer_u[L][L] = {0}; // guardar el valor de u para usarlo en v
	
	int currNum = 0; // número de archivo
	int currStep = 1; // cuento t=0 como primer paso

	for(int t=1; t<=T/dt; t++){ // paso del tiempo desde t = 1
		for(int i=0; i<L; i++){
			for(int j=0; j<L; j++){
				fill(&buffer_u,u);
				// ecuación de actualización temporal desplazada n-1
				u[i][j] = u[i][j]+dt*(Du*laplace(u, i, j)+a-(u[i][j] * u[i][j]) * v[i][j]);
				v[i][j] = v[i][j]+dt*(Dv*laplace(v, i, j)+b-(buffer_u[i][j] * buffer_u[i][j]) * v[i][j]);
			}
		}
		currStep++;
		if(currStep == archStep){
			// escribir el estado actual de u en un archivo
			//<>
			currNum++;
		}
		if(currNum == archNum){
			break;
		}
		
	}
}

void fill(float (*ini)[L][L], float fin[L][L]){
	for(int i=0; i< L; i++){
		for(int j=0; j<L; j++){
			(*ini)[i][j] = fin[i][j];
		}
	}
} 

void filesave(float m[L][L], int count) {
    char nombre[50] = {'\0'};
    sprintf(nombre, "u_%d.dat", count); // nombre dinámico

    FILE *f = fopen(nombre, "w");

    for (int i=0; i<L; i++) {
        for (int j=0; j<L; j++) {
            fprintf(f, "%f ", m[i][j]);
        }
        fprintf(f, "\n");
    }

    fclose(f);
}

// -----------------------------------------------------

int main(){

	srand(time(NULL)); // para números aleatorios

	float redu[L][L] = {};
	float redv[L][L] = {};
	

// inicializo las redes con perturbaciones
for(int i=0; i<L; i++){
	for(int j=0; j<L; j++){
		// defino perturbaciones normalizando rand max y convertir el rango a [-1,1]
		float pert = 0.01*(2.0*rand() / RAND_MAX - 1.0);
		redu[i][j] = a+b + pert;
		redv[i][j] = b/((a+b)*(a+b)) + pert;
	}
}

// laplaciano

mlaplace(&redu);
mlaplace(&redv);

// actualización temporal



	return 0;
}