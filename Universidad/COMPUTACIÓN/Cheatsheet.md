
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


# MATLAB

## Operaciones

```
diff(f,x,n); % df/dx (order n)

taylor(f,x,0,'Order',3) % taylor centrado en x=0 de orden 3 (orden 3 es hasta x^2, ya que uno es x^0)
limit(f,x, n) % limit of f when x tends to n
```

## Syms
Declarar que son positivas en caso de que sean variables físicas;
```
syms a b c positive;
```