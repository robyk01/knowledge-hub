# Lab 2 - Exerciții cu Comenzi Înlănțuite (Pipelines)

## Exerciții Propuse - Rezolva în Laborator

### File/Database Processing #1
**Descriere:** Scrie o comandă înlănțuită care scrie în fișierul `max15.txt` username-urile acelor conturi stocate în primele 15 linii ale fișierului `/etc/passwd`, cu următoarele condiții:
- Username-ul se termină cu o literă din intervalul `m..z`
- Contul folosește ca interpretor de login `/sbin/nologin`

**Hint:** Folosiți înlănțuiri de comenzi simple și procesați informațiile din `/etc/passwd`

**Solution:** grep "/usr/bin/false" /etc/passwd | head -n 15 | cut -d: -f1 | grep "[m-z]$" > max15.txt

---

### Running Tasks #2
**Descriere:** Scrie o comandă înlănțuită care scrie în fișierul `output.txt` toate procesele utilizatorilor care:
- Folosesc bash drept interpretor de comenzi
- Lucrează la terminale (pts/XY) ce încep cu cifrele `0`, `1`, `2` sau `5`
- Sortate după PID-uri în ordine **descrescătoare** (numeric!)

**Hint:** Prelucrați rezultatele comenzii `ps` cu opțiunile adecvate

**Solution**: ps -eo user,comm,pid,tty | grep bash | grep "00[0125] *$" | sort -r -k3 -n > o
utput.txt

---

### Connected Users #3
**Descriere:** Scrie o comandă înlănțuită care scrie în fișierul `filtruIPs.txt` doar IP-urile calculatoarelor de la care s-au conectat cei mai recent conectați **8 utilizatori** din acest moment

**Hint:** Folosiți înlănțuiri de comenzi simple, prelucrând informațiile despre utilizatorii conectați la sistem

**Solution**:
cat test_w.txt | tail -n 8 | awk '{print $3}' > filtrulIPs.txt (MACOS)
w | tail -n 8 | cut -d" " -f3

---

### Puzzle Pipeline #2
**Descriere:** Specifică ordinea corectă de înlănțuire a celor 4 comenzi de mai jos, astfel încât lanțul să afișeze toate procesele din sistem în formatul `user:comanda:pid`, ordonate după numele comenzii.

**Comenzile (în ordine greșită):**
```bash
cut -d" " -f1,2,3 --output-delimiter=:
sort -k2 -t:
ps -eo user,comm,pid --no-headers
tr -s " "
```

**Hint:** Aplicați raționamentul logic pentru a micșora numărul de ordini posibile pe care să le investigați

**Solution**: ps -eo user,comm,pid --no-headers | tr -s " " | cut -d" " -f1,2,3 --output-delimiter=: | sort -k2 -t:
ps - show raw process data
tr - replaces multiple spaces into a single spaces
cut - split on single space, extract fields 1-3 and output with : delimitator
sort - sorts by comm using : as field separator

---

## Exerciții Suplimentare - Rezolva Acasă (Auto-evaluare)

### User Accounts #2
**Descriere:** Scrie o comandă înlănțuită care afișează:
- Forma: `username -> UID -> GID`
- Pentru toți utilizatorii sistemului
- Sortați crescător după UID

**Hint:** Folosiți înlănțuiri de comenzi simple și procesați `/etc/passwd`

**Status:** ⬜ Not started

---

### Regex #3 / User Accounts #3
**Descriere:** Scrie o comandă înlănțuită care afișează toți utilizatorii sistemului cu UID-ul mai mare **strict** decât 4681 (adică `>= 4682`)

**Hint:** Folosiți `grep` cu expresii regulate pentru a descrie numere mai mari sau egale cu 4682. Procesați `/etc/passwd`

**Status:** ⬜ Not started

---

### File/Database Processing #2
**Descriere:** Scrie o comandă înlănțuită care scrie în fișierul `volume-montate.txt`:
- Numele partițiilor ce folosesc sistemul de fișiere **ext4**
- Montate cu opțiunea **rw** (read-write)
- Separator: `" -> "`

**Hint:** Procesați `/etc/mtab` (sau outputul comenzii `mount` fără parametri)

**Status:** ⬜ Not started

---

### Running Tasks #3
**Descriere:** Scrie o comandă înlănțuită care scrie în fișierul `CMDs.txt`:
- Toate comenzile rulate cu drepturi de **root**
- Instanțe de execuție ale programului **init**
- Afișate inclusiv cu argumente (întreaga linie de comandă)

**Hint:** Prelucrați rezultatele comenzii `ps` cu opțiunile adecvate

**Status:** ⬜ Not started

---

### Last Connected Users
**Descriere:** Scrie o comandă înlănțuită care afișează ultimii **15 utilizatori conectați** la sistem, cu:
- Sortare după ora conectării
- Afișând: data, ora și stația de la care s-au conectat

**Hint:** Procesați outputul comenzii `last`

**Status:** ⬜ Not started

---

### Connected Users #4
**Descriere:** Scrie o comandă înlănțuită care afișează, pentru fiecare utilizator conectat la sistem:
- Numele de cont
- Stația de la care s-a conectat
- Procesul rulat în foreground
- Ordonate alfabetic după numen de cont

**Hint:** Folosiți înlănțuiri de comenzi simple, prelucrând informațiile despre utilizatorii conectați

**Status:** ⬜ Not started

---

### Connected Users #5
**Descriere:** Scrie o comandă înlănțuită care **adaugă** la finalul fișierului `FirstLogins.txt`:
- Cele mai mici 12 "ore" (format HH:MM)
- Ale utilizatorilor conectați la momentul curent pe server

**Hint:** Folosiți înlănțuiri de comenzi simple, prelucrând informațiile despre utilizatorii conectați

**Status:** ⬜ Not started

---

## Note & Progres

- **Totalul exercițiilor**: 11
- **Propuse în laborator**: 4
- **Propuse acasă**: 7
- **Comenzi cheie pentru lab2**: `ps`, `cut`, `sort`, `grep`, `tr`, `mount`/`mtab`, `last`, `w`