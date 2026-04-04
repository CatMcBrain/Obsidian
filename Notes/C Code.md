
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
char[] = "string" (%s) //a string is an ARRAY of characters
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

#### Enum
Set of named constants of an user-defined "datatype":
```
enum Datatype{
	A, B, C, D
};

enum Datatype foo = A;
printf("%d", A); //will return 0 if undefined, and B will be 1, C=2, D=3...
```
	It makes it more readable as it replaces numbers with readable names.

## Arrays

They store values of the same type:
```
int array[] = {1,2,3} //An array of integers
char foo[] = {'A','B','C'} //An array of characters

printf("%d",array[0]) // Print first number
printf("%c",foo[1])

//to get the length of an array, we can use sizeof to get size of array full array in bytes and divide it by the size of a single element

int length = sizeof(array[]) / sizeof(array[0])
```
	To reassign values in a position: 
```
int[1]=4
```

#### 2D Arrays
Arrays which contain arrays as their values. You have to **declare the number of columns** to define.
```
int array[n][m!!]= {{11,12,13},
				  {21,22,23},
				  {31,32,33}};
char foo[][wrdLength]= {"Word","foo","thing"}  

// n = rows , m = columns 

printf("%d ",array[0][2]); //desired coordinates
```

# Struct

It's a form of object oriented programming. It's a custom **container**. A "variable" with several variables inside.
```
struct Name{
	char foobar[10];
	int numb;
	bool isTrue;
}; // Creating the struct and assigning its variables

// Calling
struct Name foo1 = {"mhm", 7, false};
printf("%s", foo1.isTrue);
```
They can be organized into **arrays**:
```
struct Name foos[] = {foo1, foo2, foo3};
```
##### **Reassigning values**
```
struct Name foo1 = {0}; //set all variables to 0

foo1.numb = 1;
foo1.isTrue = false;
strcpy(foobar, "something");
```
Notice that to reassign **strings** it's needed to use `strcpy` from `<string.h>`.

# Pointers and memory

`*` defines a pointer and `&` is the address it points to. *Only a pointer can store an address*.

```
int x = 5;
int * px = &x; // integer pointer (*) named "px" is set to address (&) of "x"
```

That has set the pointer px to the address of x. If we define an integer variable like `vx= *px`, it will read the value of the address pointed by px, as it's equivalent to `* &x`

```
int vx = *px; // integer vx is set to the value pointed by px
```
They are used to modify variables between scopes or functions. To **pass refereces to variables**. You first pass the address to the function and then dereference:
```
void plus(int* x){
	(*x)++;
}

int main(){
	int num = 1;
	plus(&num);
	return 0;
}
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

#### Ternary operator
Condensed way to return one value of another based if a condition is **true or false**:
```
int tern = (condition) ? <value if true>:<value if false> ;

// Example
int x = 1;
int y = 2;

char comp[] = (x>y) ? "x is bigger":"y is bigger" ;
printf("%s",comp);
```


# Loops

#### While
The loop will start and continue until some condition is met. *This is useful to verify correct user input before proceeding*.
```
while(condition){
	... ;
}
```

A variation of this is a `do{} while{}` loop, which checks if the conditions are met **at the end of each iteration**:
```
do{
	// what to do
} while(condition);
```

#### For
Repeats some code a limited amount of times
```
// for(initial condition; continue until; increment)

for(i =0; i < 10; i+=1){
	... ;
}
```

*You can add a "sleep" timer between iterations with the packages*:
```
#include <windows.h> //for Windows
#include <unistd.h> //for Linux or Mac

Sleep(1000)  //time in ms

```

#### Sequence breaking
There are commands that alter the sequences of a loop *(can be used in a nested `if`, as it would only affect the outside loops)*
```
break \\ fully break out of a loop
continue \\ skip current cycle and continue loop
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
// the text after "return" determines what returns (x, y, false, ...)
```

*# You can use  `if/else` inside a function to then return different values in different cases*

___
___
# Extras

#### Typedef
Define command names:
```
typedef <command> <newname> ;

// Example
typedef int Number;
Number x = 1;

typedef char String[10]; //string with 10 bytes
String word = "hello";
```

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
void func(int x,char y);

int main(){
	... ;
	return 0;
}

void func(int x,char y){
	... ; // function code
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