#### 1. First Smallest Index

Input: Un vector A = (a0, a1, .. an-1) unde n apartine N, n >= 2 si ai apartine N pentru orice i apartine {0, 1, .. n - 1}
Output: O pereche de indici (p, q) cu p,q apartin {0, 1, .. n - 1}, p != q, astfel incat ap <= aq si ap <= aq <= aj, oricare ar fi j apartine {0, 1, .. n - 1}

Algoritmul nu este corect deoarece nu satisface toate conditiile de output. 
Contraexemplu: 
- a = [3, 10, 5]
- sml = 0, nxtsml = 1 (a[0] = 3, a[1] = 10)
- a[2] < a[sml] => 5 < 3 Fals
- algoritmul termina si afiseaza indicii (0, 1) corespunzatori valorilor (3, 10)
- outputul corect ar fi fost indicii (0, 2) corespunzatori valorilor (3, 5)

---

#### 2. Punct fix in vector

Input: Un vector A = (a0, a1, .. an - 1) de numere intregi distincte, ai < ai + 1 pentru orice 0 <= i < n - 1
Output: Un indice i astfel incat ai = i sau -1 daca nu exista un indice.

Metoda eficienta: cautare binara pe functia f(i) = a[i] - i.

Algoritm:
- left = 0, right = n - 1
- cat timp left <= right:
	- mid = (left + right) / 2
	- daca a[mid] == mid, am gasit punct fix si returnam mid
	- daca a[mid] < mid, atunci pentru orice k <= mid avem a[k] - k <= a[mid] - mid < 0,
		deci nu exista punct fix in stanga; cautam in dreapta: left = mid + 1
	- altfel (a[mid] > mid), pentru orice k >= mid avem a[k] - k >= a[mid] - mid > 0,
		deci nu exista punct fix in dreapta; cautam in stanga: right = mid - 1
- daca bucla se termina, nu exista punct fix: returnam -1

Corectitudine:
- Invariant: daca exista un punct fix, atunci el se afla in intervalul [left, right].
- La fiecare pas eliminam corect jumatatea care nu poate contine indice i cu a[i] = i, folosind monotonia lui f(i) = a[i] - i.
- Cand gasim a[mid] = mid, raspunsul este valid. daca intervalul devine vid, nu mai poate exista solutie.

Exemplu:
a = [-2, 0, 2, 4, 7, 9]
1. left = 0, right = 5, mid = 2, a[2] = 2

a = [1, 2, 4, 6]
1. left = 0, right = 3, mid = 1, a[1] = 2 > 1 -> right = 0
2. left = 0, right = 0, mid = 0, a[0] = 1 > 0 -> right = -1

Complexitate timp: O(log n)
Complexitate spatiu: O(1)

---

#### 6. Numar lipsa

Input: Un numar n apartine N, un vector A = (a0, a1, .. an-1) de numere naturale unde pentru orice j apartine {0, 1, .. n - 1}, ai != aj. Pentru orice i apartine {0, 1, .. n - 1}, 1 <= ai <= n
Output: Un numar x apartine N, unde 1 <= x <= n si x nu apartine (a0, a1, .. an-1)

O solutie eficienta ar fi o mapa de frecventa, unde la citire crestem frecventa, apoi facem o parcurgere de la 1 la n si verificam unde e frecventa 0.
O alta solutie ar fi sa facem suma cu formula lui Gauss.
Complexitate timp O(n)
Complexitate spatiu O(n)

#### 7. Numar lipsa cu duplicate

Acelasi input, output. 
input += nu exista (i, j) apartine [1, n]^2 cu i < j
Putem folosi o mapa de frecventa pentru a verifica ce lipseste, analog 6.
S = 1 + 2 + .. + n - suma(ai) = m - d
m = numar lipsa
d = numar duplicat

S - s = m - d = A
Complexitate O(n)

---

