
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

# 24J1

## Ej 2 - C

```
#include<stdio.h>
#include<math.h>
 
float res[3] ={0};
  
void op(float a[3], float b[3], float (*c)[3]){
    for(int i=0;i<3; i++){
        (*c)[i] = a[i]*b[i];
    }
}
  
int main (){
  
    float n[3] = {1,2,3};
    float m[3] = {4,5,6};
  
    op(n,m,&res);
    for(int i=0;i<3;i++){
        printf("%f ", res[i]);
    }
  
    return 0;
}
```

## Ej 2
Con ayuda
```
x=0:0.01:25;
v = sin(x);


hold on;
plot(x,v,'k');  

% Líneas verticales
xline(10, 'k--');
xline(13, 'k--');  

% Etiquetas
title('Experimento 1');
xlabel('t (ms)');
ylabel('V (mV)');  

axis([0 23 -1 1]); % [xo xf yo yf]
```

## Ej 3
Con ayuda
```
syms g k h positive;
w = sqrt(g*k*tanh(k*h));
vg = diff(w,k);
vg = simplify(vg)
  
vg0 = limit(vg,k,0)
vg1 = 1/2 *limit(diff(vg,k,2),k,0)

tay = taylor(vg,k,0)
```

## Ej 4

Skip

# EX Ejemplo

## Ej 3

replicar gráfica

```
clf;

  

% Dummy Data

t = linspace(0,12,100);

w = 2*pi; phi = pi/2;

  

experimento  = NaN(1,length(t));

for i=1:length(t)

    if mod(i,11) == 0

    experimento(i) = rand*4-2;

    end

end

  

% Actual code

  

hold on;

plot(t, sin(w*t+phi), 'k-', 'DisplayName','sin(w*t+phi)');

ylabel('x(cm)');

xlabel('t(s)');

title('Resultado del ejercicio 5');

scatter(t,experimento, 'DisplayName','Experimento');

legend show;

hold off;
```

## Ej 4

replicar operaciones simbólicas

```
syms vo a t xo v x;

vt = vo + a*t;

xt = xo + int(vt, t, 0, t);

  

disp(xt)

  

td = (v-vo)/a;

xv= subs(xt,t,td);

  

xv = simplify(xv);

  

disp(xv)

  

res = solve(x==xv, v);

  

disp(res)
```

## Ej 5

```
#include<stdio.h>

#include<math.h>

const float k = 9e9 ;

  

// xc = posicion x del punto estudiado. x_i = posicion x cada carga. N = numero de cargas (para el loop)

  

void campo_plano(int N, float q[], float x[], float y[], float xc, float yc, float (*E)[]){

    for(int i=0; i<N; i++){

        float r[2] = {xc-x[i],yc-y[i]};

        float modr = sqrt(r[0]*r[0]+r[1]*r[1]);

        (*E)[0] += k*q[i]*r[0]/(modr*modr*modr);

        (*E)[1] += k*q[i]*r[1]/(modr*modr*modr);

    }

}

  

int main(){

  

    int N = 3;

  

    float q[] = { 2e-6, -1e-6, 3e-6 };

  

    float x[] = { 0.0, 2.0, -1.0 };

  

    float y[] = { 0.0, 1.0, 2.0 };

  

    float xc = 1.0;

    float yc = 1.5;

  

    float E[2] = {0};

  

    campo_plano(N, q, x, y, xc, yc, &E);

  

    printf("Ex = %e\n", E[0]);

    printf("Ey = %e\n", E[1]);

  
  

    return 0;

}
```

### ej disco

```
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
  
// N puntos aleatorios en un disco de radio 1 con masa homogenea y calcular momento de inercia alrededor de su centro a partir de sus posicones
  
const float M = 10;
  
float m_i_MC(int N){
    float I = 0;
    float x[N];
    float y[N];
    int count = 0;
    // se generan números aleatorios del 0 al 1:
    while(count<N){
        x[count] = (rand()%300-100)*0.01;
        y[count] = (rand()%300-100)*0.01;
        if (x[count]*x[count]+y[count]*y[count] <= 1){
            printf("[%f,%f], ",x[count],y[count]);
            count += 1;
        }
    }
    for(int i=0;i<N;i++){
        I+= (M/N)*(x[i]*x[i]+y[i]*y[i]);
    }
    return I;
}
  
int main(int argc, char *argv[]){
  
    srand(time(NULL));
  
    float I = m_i_MC(30);
    printf("\n%f",I);
  
    return 0;
}
```

### Ej grafica
```
x = -2:0.1:2;
y = -2:0.1:2;

[X,Y] = meshgrid(x,y);
  
Z = X.^2/4 - Y.^2/9;
Z0 = zeros(41);
  
hold on
  
surf(X,Y,Z)
surf(X,Y,Z0)
  
legend('geometria','z=0')
  
xlabel('x')
ylabel('y')
zlabel('z')
colormap("gray")
view(3)
```

## Ej MATLAB función ma