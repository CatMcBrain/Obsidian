#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

const double Pi = 3.14159265358979323846;
const int L = 100;
const double Du = 1;
const double Dv = 10;
const double a = 0.1;
const double b = 0.9;
const double dt = 0.01; // segundos
const int T = 200 ; // segundos

const int archNum = 10; // número de archivos deseados
const int archStep = 2000; // paso temporal de cada archivo nuevo
const double sigma = 1e-3; // para obtener valores de ruido del orden pedido

double gauss(double sig){
	double u1 = (double)rand() / RAND_MAX;
	double u2 = (double)rand() / RAND_MAX;
	// transformada de Box-Muller
	return sig * sqrt(-2.0 * log(u1)) * cos(2.0 * Pi * u2);
}

// Laplaciano para usar en la función del paso temporal
double laplace(double m[L][L], int a, int b){
	return  m[a+1][b]+m[a-1][b]+m[a][b+1]+m[a][b-1]-4*m[a][b] ;
}

void timestep(double u[L][L], double v[L][L]){ // 4) Actualización temporal
	// En t = 0, será el estado inicial de u y v
	double buffer_u[L][L] = {0}; // guardar el valor de u para usarlo en v
	
	int currNum = 0; // número de archivo
	int currStep = 0; 

	for(int t=1; t<=T/dt; t++){ // paso del tiempo desde t = 1
		fill(&buffer_u,u);
		for(int i=0; i<L; i++){
			for(int j=0; j<L; j++){
				// ecuación de actualización temporal desplazada n-1
				u[i][j] = u[i][j]+dt*(Du*laplace(u, i, j)+a-u[i][j]+(u[i][j] * u[i][j]) * v[i][j]);
				v[i][j] = v[i][j]+dt*(Dv*laplace(v, i, j)+b-(buffer_u[i][j] * buffer_u[i][j]) * v[i][j]);
			}
		}
		currStep++;
		if(currStep == archStep){
			// escribir el estado actual de u en un archivo
			filesave(u, currNum);
			currNum++;
		}
		if(currNum == archNum){
			break;
		}
		
	}
}

void fill(double (*ini)[L][L], double fin[L][L]){
	for(int i=0; i< L; i++){
		for(int j=0; j<L; j++){
			(*ini)[i][j] = fin[i][j];
		}
	}
} 

void filesave(double m[L][L], int count) {
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

	double redu[L][L] = {};
	double redv[L][L] = {};
	

// inicializo las redes con perturbaciones (ruido Gaussiano)
for(int i=0; i<L; i++){
	for(int j=0; j<L; j++){
		double pert = gauss(sigma);
		redu[i][j] = a+b + pert;
		redv[i][j] = b/((a+b)*(a+b)) + pert;
	}
}

// actualización temporal

timestep(redu, redv);

// <REVISAR contorno>

	return 0;
}