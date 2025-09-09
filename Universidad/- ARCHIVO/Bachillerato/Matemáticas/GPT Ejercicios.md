# ✏️ Ejercicios Tipo EVAU – Geometría Analítica

---

## 📘 Ejercicio 1: Plano que pasa por tres puntos

**Enunciado:**  
Halla la ecuación general del plano que pasa por los puntos  
$A(1, 0, 2)$, $B(0, 1, 1)$ y $C(2, 1, 3)$.

**Solución:**

1. Calcula dos vectores:  
   $\vec{AB} = B - A = (-1, 1, -1)$  
   $\vec{AC} = C - A = (1, 1, 1)$

2. Vector normal $\vec{n} = \vec{AB} \times \vec{AC}$:

$$
\vec{n} = \begin{vmatrix}
\vec{i} & \vec{j} & \vec{k} \\
-1 & 1 & -1 \\
1 & 1 & 1
\end{vmatrix}
= (2, 0, -2)
$$

3. Usa el punto $A(1, 0, 2)$:

$$
2(x - 1) + 0(y - 0) - 2(z - 2) = 0 \Rightarrow 2x - 2z + 2 = 0
$$

✅ **Solución final:**  
$$
\boxed{2x - 2z + 2 = 0}
$$

---

## 📘 Ejercicio 2: Recta que pasa por dos puntos

**Enunciado:**  
Halla la ecuación paramétrica de la recta que pasa por  
$A(1, 2, 3)$ y $B(4, -1, 2)$.

**Solución:**

1. Vector dirección:  
   $\vec{v} = \overrightarrow{AB} = (3, -3, -1)$

2. Ecuación paramétrica:

$$
\begin{cases}
x = 1 + 3t \\
y = 2 - 3t \\
z = 3 - t
\end{cases}
$$

✅ **Solución final:**

$$
\boxed{r(t): \begin{cases}
x = 1 + 3t \\
y = 2 - 3t \\
z = 3 - t
\end{cases}}
$$

---

## 📘 Ejercicio 3: Punto pertenece a un plano

**Enunciado:**  
¿El punto $P(2, -1, 3)$ pertenece al plano $\pi: x - 2y + z - 1 = 0$?

**Solución:**

Sustituimos en la ecuación:

$$
2 - 2(-1) + 3 - 1 = 2 + 2 + 3 - 1 = 6 \neq 0
$$

❌ **No pertenece** al plano.

---

## 📘 Ejercicio 4: Recta perpendicular a un plano

**Enunciado:**  
Halla la ecuación de la recta perpendicular al plano $ \pi: 2x - y + 3z + 4 = 0 $  
y que pasa por el punto $P(1, 2, -1)$.

**Solución:**

- Vector normal del plano → dirección de la recta: $\vec{v} = (2, -1, 3)$  
- Punto: $P(1, 2, -1)$

$$
\boxed{r(t): \begin{cases}
x = 1 + 2t \\
y = 2 - t \\
z = -1 + 3t
\end{cases}}
$$

---

## 📘 Ejercicio 5: Intersección de dos planos

**Enunciado:**  
Halla la recta intersección de los planos:

$$
\pi_1: x + y + z = 1 \\
\pi_2: 2x - y + z = 3
$$

**Solución:**

1. Vector dirección:  
   Normales: $\vec{n}_1 = (1, 1, 1)$, $\vec{n}_2 = (2, -1, 1)$

$$
\vec{v} = \vec{n}_1 \times \vec{n}_2 = \begin{vmatrix}
\vec{i} & \vec{j} & \vec{k} \\
1 & 1 & 1 \\
2 & -1 & 1
\end{vmatrix}
= (2, 1, -3)
$$

2. Buscar un punto común: fija $z = 0$

$$
\begin{cases}
x + y = 1 \\
2x - y = 3
\end{cases}
\Rightarrow x = \frac{4}{3},\ y = -\frac{1}{3}
$$

→ Punto: $P\left(\frac{4}{3}, -\frac{1}{3}, 0\right)$

3. Ecuación de la recta:

$$
\boxed{r(t): \begin{cases}
x = \frac{4}{3} + 2t \\
y = -\frac{1}{3} + t \\
z = -3t
\end{cases}}
$$
