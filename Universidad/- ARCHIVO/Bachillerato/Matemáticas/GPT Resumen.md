# 🧮 Geometría Analítica – Resumen Exprés EVAU

## 📌 ELEMENTOS BÁSICOS

- **Punto**: $P(x, y, z)$  
- **Vector**: $\vec{v} = (v_1, v_2, v_3)$

---

## ✅ CONSTRUIR UNA RECTA

### 1. **Recta que pasa por un punto y tiene un vector dirección**

**Datos**: Punto $P$, vector dirección $\vec{v}$  
**Ecuación paramétrica**:

$$
r: \begin{cases}
x = x_0 + v_1 t \\
y = y_0 + v_2 t \\
z = z_0 + v_3 t
\end{cases}
\quad \text{(con $P = (x_0, y_0, z_0)$, $\vec{v} = (v_1, v_2, v_3)$)}
$$

---

### 2. **Recta que pasa por dos puntos $A$ y $B$**

- Vector dirección: $\vec{v} = \overrightarrow{AB} = B - A$  
- Usas $A$ como punto base  
- Ecuación paramétrica como en el caso anterior

---

### 3. **Recta intersección de dos planos**

- Dados dos planos $\pi_1$ y $\pi_2$  
- Vector dirección: $\vec{v}_r = \vec{n}_1 \times \vec{n}_2$  
- Encuentra un punto común resolviendo el sistema de las ecuaciones de los planos (puedes fijar una variable)

---

## ✅ CONSTRUIR UN PLANO

### 1. **Plano que pasa por un punto y tiene un vector normal**

**Datos**: Punto $P = (x_0, y_0, z_0)$, normal $\vec{n} = (a, b, c)$  
**Ecuación**:

$$
a(x - x_0) + b(y - y_0) + c(z - z_0) = 0
$$

O bien:

$$
ax + by + cz + d = 0 \quad \text{(encuentras $d$ usando el punto)}
$$

---

### 2. **Plano que pasa por tres puntos $A, B, C$**

- Vectores: $\vec{u} = \overrightarrow{AB}$, $\vec{v} = \overrightarrow{AC}$  
- Vector normal: $\vec{n} = \vec{u} \times \vec{v}$  
- Usa $A$ y aplica la fórmula del plano anterior

---

### 3. **Plano que contiene una recta y es perpendicular a otra**

- Usa un punto de la recta y su vector dirección  
- El vector dirección de la otra recta será el **vector normal** del plano

---

## 🧠 TRUCOS RÁPIDOS

- Plano **paralelo** a otro → misma normal  
- Recta **perpendicular** a plano → vector dirección = vector normal del plano  
- Recta **contenida en plano** → su vector dirección es ortogonal al vector normal del plano  
- Punto pertenece a plano/recta → sustituye y comprueba que se cumple  
- Rectas **que se cortan** → sistema compatible determinado  
- Rectas **que no se cortan ni son paralelas** → **alabeadas**

---

## 🛠️ HERRAMIENTAS ÚTILES

- **Producto escalar**:  
  $$
  \vec{a} \cdot \vec{b} = 0 \Rightarrow \text{vectores ortogonales}
  $$

- **Producto vectorial** (para sacar normales):  
  $$
  \vec{a} \times \vec{b}
  $$

- **Determinantes**:  
  Para saber si dos vectores son proporcionales (paralelos)

---
