
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
fgets(data, 30, stdin); \\stdin = standard info
```

Get array (string) length
```
int data_length = sizeof(data);

printf("Input info for a string of n length: ");
fgets(data, sizeof(data),stdin)
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
```

## Pointers and memory

`*` defines a pointer and `&` addresses it 

```
int x = 5;
int *px = &x; // integer pointer (*) named "px" is set to address (&) of "x"
```

To **store a variable** value change permanently with functions, you need to write to its adress
```
int x = 0;

scanf(" %n", &x)
```
	(This is not needed with direct assignation like "x=1")

A string is already a pointer, so you don't need to use the address to persist
```
char str[8] = ''

fgets(str, sizeof(str), stdin)
```
## Extras

It's convenient to define our variables even if empty, to avoid errors
```
int num = 0;
float fl = 0.0;
char ch = '\0'; \\null
char str[] = ""; \\empty string
```

When printing a string with `fgets`, a newline is included because it reads our `"Enter"` as input, to fix it we need a package:
```
#include <string.h>

fgets(data, sizeof(data), stdin);
data[strlen(data)-1] = '\0' \\Removes the "enter" press

printf("%s\n%, name)

\\ (We can also just remove the newline in the printf statement)
```