# Lab 3 - Exerciții cu Fișiere de Comenzi (Shell Scripts)

## Partea I: Scripturi cu Calcule Matematice (Iterative și Recursive)

### Exerciții Propuse - Rezolva în Laborator

#### Recursive Math #3
**Descriere:** Scrie un script care primește un număr `n` și calculează recursiv puterile succesive ale lui 2:
- De la 2⁰ până la 2ⁿ
- Afișează pe stderr
- Folosește relația: 2ᵏ = 2 × 2ᵏ⁻¹, pentru k>0

**Input:** `n` (din linia de comandă sau via `read`)

**Hint:** Implementează o funcție recursivă care afișează fiecare putere

**Status:** ⬜ Not started

---

#### Cooperating Iterative Math #2
**Descriere:** Două scripturi care colaborează pentru a calcula suma cuburilor:
- **producer.sh**: Filtrează o secvență de numere pe baza unui prag `p`
  - Citește numere ca argumente
  - Citește prag `p` cu `read`
  - Afișează pe stdout doar numerele ≤ p (separate prin spații)
- **consumer.sh**: Procesează numerele din stdin
  - Adună cuburile numerelor
  - Afișează suma (sau NULL dacă vid)
  - Exit code: 0 dacă sum>0, 1 dacă vid

**Execuție:** Pipe cu `|` între scripturi + afișare exit code

**Exemple:**

**Status:** ⬜ Not started

---

### Exerciții Suplimentare - Acasă

#### Iterative Math #6
**Descriere:** Calculează valoarea de rang n din șirul Fibonacci

**Input:** n (din linia de comandă sau via `read`)

**Hint:** Relație: F(n) = F(n-1) + F(n-2), cu F(0)=0, F(1)=1

**Status:** ⬜ Not started

---

#### Iterative Math #7
**Descriere:** Calculează A(n,k) - aranjamente de n luate câte k

**Input:** n și k (din linia de comandă sau via `read`)

**Hint:** A(n,k) = n!/(n-k)!

**Status:** ⬜ Not started

---

#### Iterative Math #8
**Descriere:** Script cu 1+N*k+p argumente
- Preia primul argument ca N
- Calculează suma următoarelor argumente luate câte N
- Afișează și salvează sumele în output.txt
- Fără parametri: cere N și N numere, afișează doar prima sumă

**Input:** 1+N*k+p argumente sau interactiv

**Hint:** Folosește `shift` și `expr`

**Status:** ⬜ Not started

---

#### Iterative Math #9
**Descriere:** Calculează factorial iterativ: n! = 1 × 2 × ... × n (n > 0)

**Input:** n (din linia de comandă sau via `read`)

**Hint:** Multiplicare iterativă în loop

**Status:** ⬜ Not started

---

#### Cooperating Iterative Math #3
**Descriere:** Două scripturi colaborative - sumă a numerelor > 1000
- **producer.sh**: 
  - Citește numere ca argumente
  - Filtrează doar numerele > 1000
  - Transmite via variabilă mediu `secventa1001`
  - Apelează consumer și afișează exit code
- **consumer.sh**:
  - Citește din variabila `secventa1001`
  - Adună numerele (sau NULL dacă vidă)
  - Exit code: 0 dacă sum>0, 1 dacă vidă

**Input:** Secvență de numere ca argumente

**Hint:** Variabile de mediu pentru comunicare între procese

**Status:** ⬜ Not started

---

#### Recursive Math #4
**Descriere:** Suma cifrelor prime ale lui n (recursiv)
- Exemplu 1: n=1235 → 2+3+5=10
- Exemplu 2: n=6274 → 2+7=9

**Input:** n > 0 (din linia de comandă sau via `read`)

**Hint:** Extrageți ultima cifră, verificați dacă e primă, recursie

**Status:** ⬜ Not started

---

#### Recursive Math #5
**Descriere:** Inversul numărului complementieren (fiecare cifră: 9-cifră)
- Exemplu 1: n=13950 → 9-0=9, 9-5=4, 9-9=0, 9-3=6, 9-1=8 → 94068
- Exemplu 2: n=349 → 650

**Input:** n > 0 (din linia de comandă sau via `read`)

**Hint:** Recursie pe cifre, construiți rezultatul invers

**Status:** ⬜ Not started

---

#### Recursive Math #6
**Descriere:** Calculează xₙ al șirului definit:
- x₀ = 1, x₁ = 2
- xₘ = xₘ₋₁ + 4×xₘ₋₂ + m (pentru m≥2)

**Input:** n > 0 (din linia de comandă sau via `read`)

**Hint:** Funcție recursivă cu cazurile de bază; tratați excepții

**Status:** ⬜ Not started

---

#### Recursive Math #7
**Descriere:** Calculează yₙ al șirului definit:
- y₀ = 1, y₁ = 1
- yₘ = (m+1)×yₘ₋₁ + (m+2)×yₘ₋₂ (pentru m≥2)

**Input:** n > 0 (din linia de comandă sau via `read`)

**Hint:** Funcție recursivă cu cazurile de bază; tratați excepții

**Status:** ⬜ Not started

---

#### Recursive Math #8
**Descriere:** Calculează GCD recursiv pentru a și b
- Folosește algoritmul Euclid cu scăderi ca funcție recursivă

**Input:** a și b (din linia de comandă sau via `read`)

**Hint:** Relație: GCD(a,b) = GCD(a-b, b) dacă a>b

**Status:** ⬜ Not started

---

## Partea II: Scripturi cu Procesări de Fișiere

### Exerciții Propuse - Rezolva în Laborator

#### Call2Find #3
**Descriere:** Căută și procesează fișiere pe baza modului de modificare
- Primește număr pentru profunzimea maximă
- Găsește fișiere normale modificate în ultimele 4 săptămâni
- Pentru fișiere C: compilează (afișează status sau eroare)
- Pentru alte fișiere: afișează data modificării

**Input:** Număr (profunzime) din linia de comandă sau `read`

**Hint:** `find` cu `-depth`, `-mtime`, `file` pentru tip conținut, `gcc` pentru compilare

**Status:** ⬜ Not started

---

#### Cooperating MyFind #1
**Descriere:** Două scripturi colaborative - parcurgere recursivă cu SHA256
- **script1**: Verifică permisiuni director (r+x), apelează script2 din subfolder
- **script2**: Parcurge recursiv explicit (fără find/ls -R)
  - Scripturi bash: calculează SHA256, afișează hash + cale
  - Alte fișiere: afișează pe stderr cale + nr. linii newline
  - Final: afișează nr. total scripturi; exit 0 dacă >0, exit -1 dacă 0

**Input:** Cale director (din linia de comandă)

**Hint:** Funcție recursivă cu `for`, `test -d`, `file`, `sha256sum`

**Status:** ⬜ Not started

---

### Exerciții Suplimentare - Acasă

#### MyFind #4
**Descriere:** Statistici text din toate fișierele ASCII
- Cere: nr. total cuvinte, lungimea maximă linie
- Parcurgere recursivă explicită
- Afișează statistici pentru fiecare subdirector

**Input:** Director (linia de comandă sau `read`)

**Hint:** Parcurgeți `for`, `file` pentru "ASCII text", `wc`, funcție recursivă

**Status:** ⬜ Not started

---

#### Cooperating MyFind #2
**Descriere:** Două scripturi - parcurgere pentru programe C
- **script1**: Verifică permisiune citire director, apelează script2 din subdir_sh
- **script2**: Parcurge recursiv explicit
  - Programe C: nr. linii + cale
  - Alte fișiere: stderr cale + primele 5 linii
  - Final: afișează nr. total linii; exit 0 dacă >0, exit 1 dacă 0

**Input:** Cale director (din linia de comandă)

**Hint:** Similar ca MyFind #1, adaptate pentru conținut C

**Status:** ⬜ Not started

---

#### Call2Find #4
**Descriere:** Căută și modifică permisiuni fișiere
- Primește număr pentru profunzime minimă
- Găsește fișiere cu permisiuni read+write pentru proprietar
- Scripturi bash: adaugă permisiune execuție toți, afișează notație simbolică
- Alte fișiere: afișează permisiuni octal + cale

**Input:** Număr (profunzime min) din linia de comandă sau `read`

**Hint:** `find` cu `-depth`, `-newer`, `file`, `chmod +x`, `stat` pentru octal

**Status:** ⬜ Not started

---

#### Call2Find #5
**Descriere:** Playlist HTML pentru fișiere MP3
- Scanează director pentru MP3 (default: ~)
- Creează hard links în ~/html/muzica/
- Generează playlist.html în ~/html cu link-uri
- Setează permisiuni (rx pentru directoare, r pentru fișiere)

**Input:** Director (linia de comandă, default ~)

**Hint:** `find`, `ln`, `basename`, `chmod`, construiți HTML simplu

**Status:** ⬜ Not started

---

#### Call2Find #6
**Descriere:** Pagină web cu imagini, sortate după modificare
- Găsește .jpg, .gif, .png din home
- Generează pagină HTML cu link-uri
- Sortează după data modificării
- Setează permisiuni pentru acces web

**Input:** Implicit din home

**Hint:** `find -name`, `stat` pentru dată, `sort`, HTML, `chmod`

**Status:** ⬜ Not started

---

#### MyLast
**Descriere:** Citește utilizatori și afișează ultimele 3 conectări
- Preia ce vom pe stdin cu `read`
- Afișează ultimele 3 logări lunii curente
- Dacă nicio logare: "Utilizatorul X nu s-a conectat niciodată!"

**Input:** Nume utilizatori din stdin

**Hint:** Folosiți comanda `last`

**Status:** ⬜ Not started

---

#### MyZip
**Descriere:** Arhivează fișiere text și scripturi dintr-un director
- Preia director (linia de comandă sau `read`)
- Fișiere .txt: gzip
- Fișiere .sh: zip cu extensie schimbată .sh → .zip

**Input:** Director (linia de comandă sau `read`)

**Hint:** Cautati doar în directorul curent (nu subdirectoare), `gzip`, `zip`

**Status:** ⬜ Not started

---

## Partea III: Corectarea Scripturilor Eronate

#### Exemplul #2 - Erori de Sintaxă
**Descriere:** Identificați și corectați erorile din script:

```bash
#!/bin/noshell
A=1; #B=0;
for a in $(ls /usr/share)
do
  [ -d $a ] && let B++
done
echo #B, $A
```

**Scop:** Script corect afișează nr. subdirectoare în /usr/share + nr. parametri ai scriptului

**Status:** ⬜ Not started

---

#### Exemplul #3 - Erori de Sintaxă și Logică
**Descriere:** Identificați și corectați erorile din script:

```bash
#!/bin/nologin
if[ $# -lt 1] then
    read -p "Dati n: " n
else
    n=$1

prod=0
for k in ${seq 1 n}
do
    prod*=k
done

echo "Fact($n)=prod"
```

**Scop:** Script corect calculează factorial pentru parametrul primit (sau citit interactiv)

**Status:** ⬜ Not started

