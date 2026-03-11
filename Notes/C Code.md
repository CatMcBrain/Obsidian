
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

MODIFIERS: %
```

## Pointers and memory

`*` defines a pointer and `&` addresses it 


## Extras

When printing a string with `fgets`, a newline is included because it reads our `"Enter"` as input, to fix it we need a package:
```
#include <string.h>

fgets(data, sizeof(data), stdin);
data[strlen(data)-1] = '\0' \\Removes the "enter" press

printf("%s%, name)
```