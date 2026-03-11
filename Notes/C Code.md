
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
scanf("%d", &data);
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
```

## Pointers and memory

`*` defines a pointer and `&` addresses it 