- Variables always start with letters
- `log()` is the natural log

## Basic concepts
```
x=1; % must end with ;
xor <>
```

#### Printing
Like in C:
```
fprintf("text %f", foo);
```

## Operations

##### Function
```
int(lim_o,lim_f,x);
diff(x,n); %n is the order of the diff

				(to use with diff, int, subs...)
```
##### Vector operations 
You can use these on vectors to do them to their elements:
```
sum(v);
mean(v); % Average
transpose(M); % or M'
rand(m,n); % Generates matrix of rand numbers between 0 and 1
```

#### Conditions 
```
isprime(n)  %condición si es primo o no
```

## Matrices and Vectors

```
v = [1,2,3,4]
M = [1, 2, 3 ; 4, 5, 6 ] ;

length(v);
size(M); % [rows,cols]
```

Otras funciones para crear vectores son:
```
v = ini:pasos:fin ;

v = linspace(1,10,5); 
% 5 puntos entre 1 y 10 equiespaciados
```

#### Indexing
```
M(1,2) % 1st row, 2nd column value
M(:,1) % all rows, 1st column values 
```

#### Matrices definidas
Si ponemos un valor será dimensión, si ponemos dos, será filas, cols: 
```
zeros(d) % matriz de ceros de dimensión d
ones(m,n) % matriz de unos con [m,n]
eye(d) % identidad de dimensión d
M(m,n) % cuadrado mágico, suma filas = suma cols
```

## Ecuaciones
```
Ax+b == c <>

dsolve <>
```

## Plot

```
plot(x,y,'r-o'); %Crea una roja con círculos
xlabel('x'); title('foo');

polarplot(x,y); %números polares <>
```
- El comando `hold` nos permite juntar varias gráficas guardando una en memoria

#### 3D
```
meshgrid <>
```

## Loops

```
for i=1:5 %from 1 to 5
	<code>
end

if a > b
	<code>
else
	<more code>
end
```

- `pause(<sec>)` is useful to slow down the process to view results before continuing

## Input

```
x= input("text to prompt");
```

## Extra

#### Save/Load
```
save file.mat a b % save variables
load file.mat
```
