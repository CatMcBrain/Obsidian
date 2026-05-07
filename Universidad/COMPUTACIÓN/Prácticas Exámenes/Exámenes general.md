
# 25J1

## Ej 1b - C

```
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float c[3][3] = {0};

void operate(float a[3][3],float b[3], float (*c)[3][3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            (*c)[i][j] += b[i]*a[i][j];
        }
    }
}
 
int main(){
  
    float a[3][3] = {{1,1,1},{1,1,1},{1,1,1}};
    float b[3] = {1,2,3};
  
    operate(a,b,&c);
  
 
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%f ", c[i][j]);
        }
        printf("\n");
    }
  
    return 0;
}
```

## Ej 2 - MAT

3D Plot. Skipped.

## Ej 3 - MAT

```
syms r Vo R;
v = Vo*(1-(r/R)^2);
Q = int(v+2*pi*r,r)
```