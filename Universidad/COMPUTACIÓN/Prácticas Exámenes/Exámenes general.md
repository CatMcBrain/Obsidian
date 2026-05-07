
# 25J1

## Ej 1b - C

Bien
```
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float c[3][3] = {0};

void operate(float a[3][3],float b[3], float (*c)[3][3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            (*c)[i][j] += b[i]*a[i][j];
        }
    }
}
 
int main(){
  
    float a[3][3] = {{1,1,1},{1,1,1},{1,1,1}};
    float b[3] = {1,2,3};
  
    operate(a,b,&c);
  
 
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%f ", c[i][j]);
        }
        printf("\n");
    }
  
    return 0;
}
```

## Ej 2 - MAT

3D Plot. Skipped.

## Ej 3 - MAT

a) Incompleto
```
syms r Vo R;
v = Vo*(1-(r/R)^2);
Q = int(v*2*pi*r,r)
```
falta evaluar límites: `int(v*2*pi*r,r,0,R)`

b) Incompleto
```
syms u L;
f=2*pi*u*diff(v,r);
S=2*pi*R*L;
F=S*f;
disp(F)
```
falta sustituir r=R: `f = subs(f,r,R); % (línea2|3)`

c) Bien
```
A=pi*R^2;
P=F/A;
disp(P)
```

## Ej 4 - C

Con ayuda.
```
#include<stdio.h>
#include<math.h>

struct SComplex{
	double A,B;
};
typedef struct SComplex Complex;

Complex x1 = {0,0} ;
Complex x2 = {0,0} ;

void solve(double a, double b, double c, Complex *s1, Complex *s2){
	double delta = b*b - 4*a*c;
	if(delta>=0){
		s1->A = -b/(2*a) + sqrt(delta)/(2*a);
		s2->A = -b/(2*a) - sqrt(delta)/(2*a);
	} else{
		s1->A = -b/(2*a) ;
		s1->B = sqrt(-delta)/(2*a);
		s2->A = -b/(2*a) ;
		s2->B = - sqrt(-delta)/(2*a);
	}
	
}

int main(){

	double a = 2;
	double b = 4;
	double c = 10;

	solve(a,b,c,&x1,&x2);

	printf("x1: %lf + i%lf \n x2: %lf + i%lf", x1.A,x1.B,x2.A,x2.B);

	return 0;
}
```