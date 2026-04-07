- Variables always start with letters
- `log()` is the natural log
## Matrices and Vectors

```
v = [1,2,3,4]
M = [1, 2, 3 ; 4, 5, 6 ] ;

length(v);
size(M); % [rows,cols]
```

#### Indexing
```
M(1,2) % 1st row, 2nd column value
M(:,1) % all rows, 1st column values 
```
#### Crear vectores

```
(ini:pasos:fin);
```

## Operations

You can use these on vectors to do them to their elements:
```
sum(v);
mean(v); % Average
transpose(M); % or M'
```
### Plot

```
plot(x,y,'r-o'); %Crea una roja con círculos
xlabel('x'); title('foo');
```

## Loops

```
for i=1:5 %from 1 to 5
	<code>
end

if a > b
	<code>
else
	<more code>
end
```

## Extra

#### Save/Load
```
save file.mat a b % save variables
load file.mat
```