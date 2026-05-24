
# C
## CMD Arguments
```
int main(int argc, char *argv[])
```
- `argc` (argument count)
- `argv` (argument vector}:
    - `argv[0]` → program name
    - `argv[1]`, `argv[2]`, etc. → passed arguments

#### String to Number
To pass a **number**, it's needed to convert the string to a number with `atoi()` from `<stdlib.h>`:
```
int num = atoi(argv[1]);
```

## Random numbers within Range
```
#include<stdlib.h>
#include<time.h>

int main(){
	srand(time(NULL));
	
	float a = rand()/max // int de 0 a max de 1 en 1
	// + LIM MINIMO: rand()%(max + 1 - min) +min;
}
```

## Struct

It's a form of "object oriented programming". It's a custom **container**. A "variable" with several variables inside.
```c
struct Name{
	char foobar[10];
	int numb;
	bool isTrue;
}; // Creating the struct and assigning its variables

// Calling
struct Name foo1 = {"mhm", 7, false};
printf("%d", foo1.isTrue);
```
They can be organized into **arrays**:
```
struct Name foos[] = {foo1, foo2, foo3};
```
##### **Reassigning values**
```c
struct Name foo1 = {0}; //set all variables to 0

foo1.numb = 1;
foo1.isTrue = false;
strcpy(foo1.foobar, "something");

// assign various

struct Name foo1 = {"hi", 2, false}; 
// cannot be done after first assignment, it must be done separately like above. If so, it must be done like this:
foo1 = (struct Name){"hi",2,false};
// or 
foo1 = (struct Name){
	.foobar = "hi",
	.numb = 2,
	.isTrue = false,
}
```
Notice that to reassign **strings** it's needed to use `strcpy` from `<string.h>`. You can also, full redefine the struct like  in `foo1 = (struct Name){...}`

##### Typedef renaming
You can rename a struct with typedef, and you wont need to say "struct" when defining one of its time, but instead treat it as a normal type (like int, float...):
```
struct foo{
	int A;
	float B;
};
typedef struct foo foobar;

// <main>

foobar Name = {1,2.3};
```

#### Ternary operator and booleans
It's a compact if/else checking if something is true, it's useful with bools for outputs:
```
bool isTrue = false;

char str[]  = isTrue ? "true" : "false";
printf("%s", str);
```

# MATLAB

## Operaciones

```
diff(f,x,n); % df/dx (order n)

taylor(f,x,0,'Order',3) % taylor centrado en x=0 de orden 3 (orden 3 es hasta x^2, ya que uno es x^0)
limit(f,x, n) % limit of f when x tends to n
```

#### Matrix indexing
```
M(1,2) % 1st row, 2nd column value
M(:,1) % all rows, 1st column values 
```

## Syms
Declarar que son positivas/reales en caso de que sean variables físicas;
```
syms a b c positive real;
```

### isAlways
Checks if a condition is met matematically and outputs logical 1 or 0:
```
isAlways(cond)
```

## Gráficas

```
view(3) % View in 3D
colormap("grey")
```

## Functions
```
function out = functionName(input)  
	out = (...)
	% code here
end
```

## Printing
Like in C:
```
fprintf("text %f", foo);
```

### Misc
```
% Minimum and index
[ymin yind] = min(y)

% Text on Graph
text(x, y, 'text')

histogram(data, n) % number of bins

% Bar chart 
bar(data);
set(gca, 'xticklabel', arrayOfLabels);
```