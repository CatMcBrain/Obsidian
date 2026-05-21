
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

```
diff(f,x,n); % df/dx
```