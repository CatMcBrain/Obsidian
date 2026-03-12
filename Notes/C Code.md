
Start with:
```
#include <stdio.h>

int main(){

	return 0;
}
```

# Basic packages:
```
#include <stdio.h> //print
#include <math.h> //math functions
#include <stdbool.h> //booleans
#include <string.h> //string actions (e.g. strlen() )

```
# Commands:

```
printf("Print text and %d variables \n", var);
```

#### Input
```
printf("Input your info: ");
scanf(" %d", &data);
```

#### Input a string
```
printf("Input info for a string of 30: ");
fgets(data, 30, stdin); //stdin = standard info
```

#### Get **full** array length and just **string** length
```
int data_length = sizeof(data);

printf("Input info for a string of n length: ");
fgets(data, sizeof(data),stdin);

// #include <string.h>

if(strlen(data)==0){
	printf("Your string is empty");
}
```

# Variables and Format specifiers

```
int = whole number (%d)
float = decimal number (%f)
double = long float ($lf)
char = 'single character' (%c)
char[] = "string" (%s)
bool = true/false //you need <stdbool.h>

MODIFIERS:
	%.2f : number of decimals
	$2f : minimum number of total characters
	
// You can also declare fixed constants with:
	const float PI = 3.1416
	
// A shortcut to edit a variable in increments is:
	x+=1 ; // (x=x+1) 
```

Each variable exists within a scope *"{}"*, and you can't reuse a variable name within the same scope. **They are different for each function**, `int x` for main is not the same for any other function, they are not shared. 

- Unless you define a **global**, which are defined outside functions.
# Pointers and memory

`*` defines a pointer and `&` is the address it points to. You need a pointer to point to an address.

```
int x = 5;
int * px = &x; // integer pointer (*) named "px" is set to address (&) of "x"
```

That has set the pointer px to the address of x. If we define an integer variable like `vx= *px`, it will read the value of the address pointed by px, as it's equivalent to `* &x`

```
int vx = *px; // integer vx is set to the value pointed by px
```

*(extra)*
After setting a pointer px, if you modify using the *"value pointed by"*, it modifies the value of x:
```
int *px = &x;
*px = 6; // x=6
```

___

To **store a variable** value change permanently with functions, you need to write to its adress
```
int x = 0;

scanf(" %n", &x);
```
	(This is not needed with direct assignation like "x=1")

A string is already a pointer, so you don't need to use the address to persist
```
char str[8] = ''

fgets(str, sizeof(str), stdin);
```


# Math functoins

The package `<math.h>` gives us some functions:
```
sqrt(n); // square root
pow(n,pot); // elevate n to pot
round(n); ceil(n); floor(n); // round\round up\round down
abs(n); // absolute value
log(n); // natural logarithm (Ln)
sin(n); cos(n); tan(n); // trigonometry (n in radians)
```

- Watch out with divisions with integers, if you want to have decimals, you need to use `4.0 / 3.0`

# Conditionals

#### If / Else
```
if (condition){
	... ;
}
else if(condition2){
	... ;
}
else{
	... ;
}

// conditions: a == b , a >= b, a=='t' ...
```

#### Switch
It checks if a variable is equal to 1, 2, ... (**use *break***)
```
int var = 0;

switch(var){
	case 1:
		... ; // will trigger if var == 1
		break;
	case 2:
		... ;
		break;
	case 'T'; // can also be used for other kind of data
		... ;
	default:
		printf("There were no matches");
}
```

#### Logical Operators
```
// && = AND
// || = OR
// ! = NOT
```

# Functions

They are created outside `main`. `void` just "inputs" the code, does not return variables:
```
void function(int var1, char var2){ 
	... ;
}

int main(){
	
	function(x, y);
	
	return 0;
}

// for each variable we are using with the function, we must determine its type inside the parentheses
```

If you want a function to return a value/result as an "output" after ending:
```
int function(int x){
	... ;
	return result;
}

// the "int" at the beginning determines the kind of value it returns
```

*# You can use  `if/else` inside a function to then return different values in different cases*

___
___
# Extras

#### Empty variable defining
It's convenient to define our variables even if empty, to avoid errors
```
int num = 0;
float fl = 0.0;
char ch = '\0'; //null
char str[] = ""; //empty string
```

#### Function prototypes
To have neater code, sometime's it's desired to have your functions after `main(){}`, but they won't work there, as they are defined after being called inside `main`.
To be able to do this, you can **predefine** said function before `main`, stating only its name and input variables (and a `;`), and then place its whole definition after `main`:
```
void func(x,y);

int main(){
	... ;
	return 0;
}

void func(x,y){
	(functio)
}
```

#### String newline correction
When printing a string with `fgets`, a newline is included because it reads our `"Enter"` as input, to fix it we need a package:
```
#include <string.h>

fgets(data, sizeof(data), stdin);
data[strlen(data)-1] = '\0'; //Removes the "enter" press

printf("%s\n%, name);

// (We can also just remove the newline in the printf statement)
```

€, unlike $, is a string with 3 bytes, not a character. So we need a string to store it:
	`char currency[3]="€"`