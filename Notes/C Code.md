
Start with:
```
#include <stdio.h>

int main(){

	return 0;
}
```

### Commands:

```
printf("Print text and %d variables \n", var);
```

Input
```
printf("Input your info: ");
scanf(" %d", &data);
```

Input a string
```
printf("Input info for a string of 30: ");
fgets(data, 30, stdin); //stdin = standard info
```

Get array (string) length
```
int data_length = sizeof(data);

printf("Input info for a string of n length: ");
fgets(data, sizeof(data),stdin);
```

## Variables and Format specifiers

```
int = whole number (%d)
float = decimal number (%f)
double = long float ($lf)
char = 'single character' (%c)
char[] = "string" (%s)
bool = true/false

MODIFIERS:
	%.2f : number of decimals
	$2f : minimum number of total characters
	
// You can also declare fixed constants with:
	const float PI = 3.1416
```

## Pointers and memory

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


## Math functoins

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

## Conditionals and Loops

If / Else
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

// conditions: a == b , a >= b ...
```
___
___
## Extras

It's convenient to define our variables even if empty, to avoid errors
```
int num = 0;
float fl = 0.0;
char ch = '\0'; //null
char str[] = ""; //empty string
```

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