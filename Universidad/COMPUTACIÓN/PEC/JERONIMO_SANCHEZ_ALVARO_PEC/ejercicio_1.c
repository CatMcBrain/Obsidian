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

double random(){
	double n = 0.000000;
	while(n==0.000000){ // evitar logaritmo de 0
	n = (double)rand() / RAND_MAX ;
	}
	return n;
}

double gauss(double sig){
	double u1 = random();
	double u2 = random();
	// transformada de Box-Muller
	return sig * sqrt(-2.0 * log(u1)) * cos(2.0 * Pi * u2);
}

// Laplaciano para usar en la función del paso temporal
double laplace(double m[L][L], int i, int j){
	// condiciones de contorno
	int am = i-1; 
	int ap= i+1;
	if(i==0){am = L-1;}
	if(i==L-1){ap = 0;}
	int bm = j-1; 
	int bp= j+1;
	if(j==0){bm = L-1;}
	if(j==L-1){bp = 0;}

	return  m[ap][j]+m[am][j]+m[i][bp]+m[i][bm]-4*m[i][j] ;
}

void fill(double ini[L][L], double fin[L][L]){
	for(int i=0; i< L; i++){
		for(int j=0; j<L; j++){
			ini[i][j] = fin[i][j];
		}
	}
} 

void filesave(double m[L][L], int count) {
	char name[50] = {'\0'};
	sprintf(name, "u_%d.dat", count); // nombre dinámico

	FILE *f = fopen(name, "w");

	for (int i=0; i<L; i++) {
		for (int j=0; j<L; j++) {
			fprintf(f, "%f ", m[i][j]);
		}
		fprintf(f, "\n");
	}

	fclose(f);
}

double amplitud(double m[L][L]){
	double sum = 0.;
	for(int i=0;i<L; i++){
		for(int j=0; j<L; j++){
			sum = sum + (m[i][j]-(a+b))*(m[i][j]-(a+b));
		}
	}
	return sqrt(sum);
}

void ampsave(double m[L][L], int i){
	FILE *f;
	if(i==0){
		f = fopen("amplitud.dat", "w");
	} else{
		f = fopen("amplitud.dat", "a");
	}
	fprintf(f, "%lf\n", amplitud(m));
	fclose(f);
}

void timestep(double u[L][L], double v[L][L]){ // 4) Actualización temporal
	// En t = 0, será el estado inicial de u y v
	double Newu[L][L];
	double Newv[L][L];
	
	fill(Newu, u);
	fill(Newv, v);
	ampsave(u, 0);
	
	int currNum = 0; // número de archivo
	int currStep = 0; 

	for(int t=1; t<=T/dt; t++){ // paso del tiempo desde t = 1

		// Cálculo de la amplitud cada paso de tiempo
		ampsave(u, t);

		for(int i=0; i<L; i++){
			for(int j=0; j<L; j++){
				// ecuación de actualización temporal desplazada n-1
				Newu[i][j] = u[i][j]+dt*(Du*laplace(u, i, j)+a-u[i][j]+(u[i][j] * u[i][j]) * v[i][j]);
				Newv[i][j] = v[i][j]+dt*(Dv*laplace(v, i, j)+b-(u[i][j] * u[i][j]) * v[i][j]);
			}
		}
		fill(u,Newu);
		fill(v,Newv);

		currStep++;
		if(currStep == archStep){
			// escribir el estado actual de u en un archivo
			filesave(u, currNum);
			currNum++;
			currStep=0;
		}
		if(currNum == archNum){
			break;
		}
		
	}
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

FILE *f = fopen("time.dat", "w");	
	for(int i=0; i<=T/dt; i++){
		fprintf(f,"%d ",i);
	}

fclose(f);

	return 0;
}