# Lab 1: Exerciții cu comenzi simple

## Exerciții propuse spre rezolvare

### Creare și manipulare directoare
Să se scrie comenzile care realizează următoarele operații cu directoare:

- i) Creează un subdirector cu numele `programe`, în directorul dvs. acasă (referit prin caracterul `~` în cele de mai jos)
- ii) Creează două subdirectoare cu numele `tema1` și, respectiv, `tema2`, în directorul creat la pct. i)
- iii) Creează un subdirector cu numele `sub-temaA`, în directorul `tema2` creat la pct. ii)
- iv) Redenumește directorul creat la pct. iii) cu numele `tema2_sub-temaA`

**Indicație:** Folosiți comenzile `mkdir` și `mv`
### Creare și manipulare fișiere normale
Să se scrie comenzile care realizează următoarele operații cu fișiere:

- i) Creează trei fișiere cu numele `program1.c`, `program2.c` și `program2.h`, în directorul `~/programe` pe care l-ați creat la exercițiul precedent
- ii) Creează două fișiere cu numele `tema1-1.c` și, respectiv, `tema1-2.c`, în directorul `~/programe/tema1` pe care l-ați creat la exercițiul precedent
- iii) Creează două fișiere cu numele `sub-temaA1.c` și `sub-temaA2.cpp`, în directorul `~/programe/tema2/tema2_sub-temaA` creat la exercițiul precedent
- iv) Creează două alias-uri, în directorul `~/programe/tema2/tema2_sub-temaA`, după cum urmează: unul hard, cu numele `tema2_sub-temaA1.c`, pentru fișierul `sub-temaA1.c`, și al doilea simbolic, cu numele `tema2_sub-temaA2.cpp`, pentru fișierul `sub-temaA2.cpp`
- v) Copie fișierul `~/programe/tema1/tema1-1.c` în directorul `~/programe/tema2/`, schimbând numele copiei în `tema2-1.c`
- vi) Mută fișierul `~/programe/tema1/tema1-2.c` în directorul `~/programe/tema2/`, schimbându-i totodată și numele în `tema2-2.c`
- vii) Șterge unul dintre cele două nume ale fișierului identificat prin numele alternative `sub-temaA1.c` sau `tema2_sub-temaA1.c`

**Indicație**: folosiți comenzile touch, ln, rm, cp și mv.

### Basic file operations #6
- i) Să se scrie comanda ce afișează toate metadatele asociate fișierelor `program1.c`, `program2.c` și `program2.h` din directorul `~/programe`

- ii) Să se modifice drepturile de acces asociate celor trei fișiere:
  - Pentru `program1.c`: eliminați dreptul de citire de către proprietar, păstrând neschimbate celelalte permisiuni
  - Pentru `program2.c`: adăugați dreptul de execuție de către proprietar și grupul proprietar
  - Pentru `program2.h`: setați permisiunile de acces astfel încât să permită doar operații de citire pentru proprietar și grupul proprietar

**Indicație:** Folosiți comanda `stat` pentru rezolvarea cerinței i) și comanda `chmod` pentru rezolvarea cerinței ii și pentru grupul proprietar.
### cut #2
Să se scrie comanda care afișează numele și GID-urile tuturor grupurilor de utilizatori ai sistemului.

**Cerință suplimentară:** Înlocuiți `:` cu ` - ` în rezultatele afișate de comandă.

**Indicație:** Folosiți comanda `cut` și informațiile din fișierul `/etc/group`; pentru cerința suplimentară, căutați în `man cut` opțiunea pentru înlocuirea delimitatorului.

---

### grep #2
Să se scrie comanda care afișează informațiile asociate tuturor utilizatorilor care sunt membri ai grupului `root`.

**Indicație:** Mai întâi aflați GID-ul grupului `root` din `/etc/group`, apoi folosiți `grep` și informațiile din `/etc/passwd`.

---

### stat #1
Să se scrie comanda care să afle (și să afișeze) câte nume sinonime (link-uri hard) are un fișier, specificat prin oricare dintre aceste nume sinonime.

**Explicație:** Orice fișier stocat pe disc are cel puțin un nume. Aceste nume sunt sinonime între ele și pot fi folosite pentru a identifica fișierul. Din perspectiva sistemului, nu există nicio diferență între numele cu care a fost creat fișierul și numele suplimentare create ca link-uri hard.

**Indicație:** Folosiți comanda `stat` cu un format de afișare adecvat.

---

### wc #2
Să se scrie comanda ce afișează câte linii de text conține fișierul `/etc/mtab`, precum și lungimea celei mai lungi linii.

**Indicație:** Folosiți comanda `wc`.

## Exerciții suplimentare (pentru acasă)

### ps #2
Să se scrie comanda care să afișeze toate procesele din sistem ce rulează ca `root` (proprietarul real și cel efectiv), în formatul: `processID parentID real_userID effective_userID command`.

**Indicație:** Folosiți comanda `ps`.

---

### sort #3
Să se scrie comanda care să sorteze descrescător după GID liniile din fișierul `/etc/group`.

**Indicație:** Folosiți comanda `sort`.

---

### find #5
Să se scrie comanda ce afișează toate fișierele și directoarele din directorul dat ca argument (recursiv), pentru care grupul proprietarului are drepturi de citire și execuție, împreună cu drepturile de acces.

**Indicație:** Folosiți comanda `find`.

---

### find #6
Să se scrie comanda care să afișeze toate programele sursă C/C++ (extensii `.c`, `.cpp`, `.h`) pe care le dețineți, împreună cu dimensiunile în octeți și data ultimei modificări.

**Indicație:** Folosiți `find` cu trei opțiuni `-name` și opțiunea `-printf` pentru acțiuni.

---

### find #7
Să se scrie comanda care identifică toate programele sursă C++ (extensia `.cpp`) din directorul home, și dacă dimensiunea < 5 KB, încearcă să le compileze cu `g++`. Redirecționați erorile în `errors.txt`.

**Indicație:** Folosiți `find` cu opțiunile `-name`, `-size` și `-exec g++ ... 2>> errors.txt`.

---

### find #8
Să se scrie comanda ce afișează toate fișierele web (extensii `.htm`, `.html`, `.php`, `.css`) pe care le dețineți, cu dimensiunile în KB și data ultimei modificări.

**Indicație:** Folosiți comanda `find`.

---

### find #9
Să se scrie comanda care șterge toate fișierele temporare din home și subdirectoarele sale.

**Explicație:** Fișierele temporare sunt cele care se termină cu `~` sau `.bak` (create de editori de text pentru salvarea versiunilor anterioare).

**Indicație:** Folosiți `find` cu `rm` sau opțiunea de ștergere.

---

### find #10
Să se scrie comanda care găsește și afișează toate link-urile hard ale unui fișier, specificat prin oricare dintre aceste nume.

**Explicație:** Orice fișier pe disc poate avea mai multe nume (link-uri hard). Aceste sunt sinonime și din perspectiva sistemului nu există diferență între ele.

**Indicație:** Folosiți `find` cu un test specific.ctoarele, precum și drepturile de acces asociate acestora, aflate în directorul dat ca argument în linia de comandă, parcurs recursiv, pentru care grupul proprietarului are drepturi de citire și de execuție.
(Indicație: folosiți comanda find.)