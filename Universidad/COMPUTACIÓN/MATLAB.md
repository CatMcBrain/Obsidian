- Variables always start with letters
- `log()` is the natural log

## Basic concepts
```
x=1; % must end with ";"
% sin() , cos() Are defined

xor(case1, case2) % If they are both true or false, it returns 0, else, returns 1

clf(fig); % clear figure
```

#### Printing
Like in C:
```
fprintf("text %f", foo);

% Show results rendered
disp();
```

#### Variable collection
```
var = cell(0:4);
var{1} = foo; % accesses first index, in this case, 0
```

#### Dot. Element operator
If used with matrices, it will do element by element unless the size doesnt match, in which case it will expand and repeat the same operation:
```
"." ~ for each element of this do...

% example
[1,1;1,1] .* [1,2;3,4] = [1,2;3,4]
[1,1;1,1] .* [1,2] = [1,2;1,2]
```
Must use in all **non matrix** operations. 
## Operations

##### Function
```
syms y(x); % declares a y function with variable x (or declares just a variable to solve in Equations)

int(lim_o,lim_f,x);
diff(f,x,n); % df/dx. Order n
gradient(f, [x,y]); % Gradient of the variables choosed for a f
taylor(f,x,0,'Order',3) % taylor centrado en x=0 de orden 3
limit(f,x, n) % limit of f when x tends to n
```
##### Vector operations 
You can use these on vectors to do them to their elements:
```
sum(v);
mean(v); % Average
transpose(M); % or M'
rand(m,n); % Generates matrix of rand numbers between 0 and 1

inv % Inverse matrix
det % Determinant
eig % Eigenvalues
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
v = ini:pasos:fin ; % va sumando de paso en paso

v = linspace(1,10,5); 
% 5 puntos entre 1 y 10 equiespaciados
v = logspace();
% espaciados logarítmicamente, para frecuencias/potencias de 10
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

## Funciones
```
syms x y z % Crea variables simbólicas
eqn = Ax+by + z == C ;

solve(y,x) % solve equation y for the variable x
dsolve(y, cond) % solve differential equation
linsolve(A,B) % solve linear system AX=B
```

Si se quisiese substituir alguna variable, se usa `subs()` , o también se puede crear una `matlabFunction`:
```
% ej) --- Subs --- 
syms x z;
y = x+1

subs(y, x, 2); % y=3
% si fuese más de un valor: subs(y,[x,z],[1,2])

% --- matlabFunction ---
syms x z;
y = matlabFunction(x+z+1);

y(1,2);

```

#### Example of equations System
```
syms x y z ;
eqn1 = 2*x + y + z == 2;
eqn2 = -x + y - z == 3;
eqn3 = x + 2*y + 3*z == -10;

% Convert system to a matrix
[A,B] = equationsToMatrix([eqn1,eqn2,eqn3],[x,y,z]);
$automatically creates the matrix to use linsolve

linsolve(A,B);
```
You can also solve it normally by creating `A=[...],  B=[...]` matrices and solving them with `solve(A,varMatrix)` .

## Plot

```
% crea línea roja con círculos
plot(x,y,'r-o'); 
xlabel('x'); title('foo');

// plot crea grafico a partir de valores. fplot lo crea y grafica funciones sin valores de x

polarplot(theta,rho); % Coordenadas polares 
```
- El comando `hold` nos permite juntar varias gráficas guardando una en memoria

##### 2D
```
histogram(dat,nbar); % Grafica de barras con un número de barras determinado
imagesc(dat); % Mapa de calor
stairs(x,y,...); % "Escaleras" de 90 grados
```

#### 3D

*Todos los que tengan `f` delante representan funciones, no datos discretos en forma de matriz*
```
fplot3(); % Representar puntos/líneas en 3D
fmesh(); % Representar malla en 3D
fsurf(); % Representar superficie en 3D
fcontour3(); $ Líneas de nivel en 3D
```
##### Mallas
```
% Defino una malla
[X,Y] = meshgrid(x,y) % Cuadrícula 3D
Z = foo;
surf(X,Y,Z); % mostrar 
colorbar; % gradiente de colores

% Otros ----
mesh(); % malla no cuadriculada
quiver(); % vectores
```

##### Color
```
colorbar; % See colormap used for the mesh
colormap(name); % Set a custom colormap
	c = gca.Clim; % shows current limits for colormap
	gca.Clim = [n,m]; % modifies them
```
- *`gca` is "get current axes"*  
- you can name a figure window `fig1 = figure `

##### Graph customization
```matlab
xlabel("nameX"); % Axis name
title("Title"); % Title of graph

xlim([-1 5]); % Axis limits
grid on; % Grid
axis equal; % Both axis will be of the same scale
```

##### Plot style
It can be written together like `plot(x,y,"k--")`
```
% Forma ~
"-" % Contínua
"--" % Discontínua
":" % Puntos

% Color ~
"k" % Black
"r" % Red
"b" % Blue

% Superficies ~
surf(...,"FaceAlpha",0.5) % Transparencia
shading interp; % Suavizado
 
```
## Loops

```
for i=1:5 %from 1 to 5
	<code>
end

% -------------
if a > b
	<code>
else
	<more code>
end

% -----------
while <condition>
	 <code>
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

#### Save graphics
```
print -djpeg -r200 ’file.jpeg’
```
*Saves current active window in jpg at 200x resolution*

#### Misc
```
double(num); % returns a double float
pi; % is already defined
assume(x, 'real'); % assume something for simplification

expand(expression); % expands and operates
simplify(expression); % simplifies algebraic expression
factor(expression); % factorizes irreducible

randn(n,m); % matriz n m de números aleatorios de dist normal
randn(size(vec)) %genera un vector de un tamaño

pause(sec); % pausa la ejecución n segundos. Útil para animaciones

peaks(n); % example heatmap with n peaks
```