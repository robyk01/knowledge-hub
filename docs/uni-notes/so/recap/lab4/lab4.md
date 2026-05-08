# Lab 4 - Programare C cu Fișiere (POSIX API)

## Partea I: Exerciții de Programare C cu Prelucrări de Fișiere

### Exerciții Propuse - Rezolva în Laborator

#### #1: The filter MyTr
Să se scrie un program C care primește de la linia de comandă numele a două fișiere și două caractere, cu care va face următoarea procesare: va copia conținutul fișierului de intrare în cel de ieșire, înlocuind fiecare apariție a primului caracter specificat ca argument cu cel de-al doilea caracter specificat ca argument. În caz că fișierul de ieșire deja există, se va cere confirmare de suprascriere. Respectiv, va fi creat în cazul în care nu există, cu drepturi de citire și scriere doar pentru proprietar.
Cerință obligatorie: se vor utiliza apelurile de sistem din API-ul POSIX pentru accesarea fișierelor.
(Indicație: printr-o singură parcurgere a fișierului de intrare, copiați fiecare caracter citit, aplicând transformarea cerută, în fișierul de ieșire.)
Cerință suplimentară: dacă de la linia de comandă se primește un singur nume de fișier, sau dacă numele fișierului de ieșire coincide cu numele celui de intrare, atunci se va trata, într-un mod adecvat, această situație (i.e., nu se mai face copiere, ci supra-scriere).
Observație: ceea ce trebuie tratat separat aici, este cazul excepțional când fișierul de ieșire coincide cu fișierul de intrare. Aici am simplificat testul, cerându-vă doar să testați egalitatea celor două nume de fișiere. În realitate însă, un fișier poate avea mai multe nume (mai multe aliasuri, i.e. linkuri hard sau simbolice), astfel că detectarea acestui caz excepțional revine la a compara perechile formate din ID-ul device-ului și al i-nodului, corespunzătoare celor două nume de fișiere -- pentru mai multe detalii în acest sens, (re)citiți observația ce urmează imediat după programele demonstrate în exemplul rezolvat [Filter programs], prezentat în suportul de laborator.

---

#### #2: The command MyHead
Să se scrie un program C ce implementează comanda head, inclusiv cu opțiunile -n și -c (și inclusiv cu valori numerice negative pentru aceste opțiuni). Se va permite precizarea de argumente multiple de tip nume de fișiere, în linia de comandă a programului, pentru procesare.
Cerință obligatorie: se vor utiliza apelurile de sistem din API-ul POSIX pentru accesarea fișierelor.
(Indicație: încercați să simulați cât mai exact comportamentul comenzii head.)

### Exerciții Suplimentare - Acasă

#### MyFind #2
Să se implementeze o clonă simplificată pentru comanda find, care funcționează astfel: programul primește un singur parametru în linia de comandă, reprezentând numele exact al fișierului care este căutat. Pornind din directorul acasă al utilizatorului curent, programul va parcurge recursiv întregul subarbore din sistemul de fișiere cu rădăcina în acesta, și va afișa calea, relativă față de directorul de start, spre fiecare fișier întâlnit în timpul parcurgerii, ce are numele căutat. În plus, în caz de eroare, programul va afișa un mesaj explicit și se va închide "elegant", returnând și un cod de terminare specific erorii apărute.
(Indicație: parcurgeți directorul cu șablonul indicat în lecția practică și, pentru fiecare intrare din director ce are numele căutat, afișați calea ei, iar pentru fiecare intrare ce este de tip director, apelați recursiv funcția de parcurgere.)

---

#### MyFind #3
Să se scrie un program C care șterge toate legăturile simbolice "rupte" (i.e. legături ale căror destinații nu mai există) aflate într-un director, dat ca parametru, sau în subdirectoarele lui (parcurse recursiv).
(Indicație: parcurgeți directorul cu șablonul indicat în lecția practică și, pentru fiecare intrare din director ce este o legătură simbolică, testați existența destinației cu funcția access(legătură, F_OK) și, în caz negativ, ștergeți legătura respectivă cu funcția unlink(legătură), iar pentru fiecare intrare ce este de tip director, apelați recursiv funcția de parcurgere.)

Show / Hide some suggestions for solving the problem

---

#### MyMv
Să se scrie un program C ce implementează comanda mv , inclusiv cu opțiunile sale -i , -u și -t . Se va permite precizarea mai multor fișiere sursă și a unui singur fișier/director destinație.

---

#### MyLs
Să se scrie un program C ce implementează comanda ls , inclusiv cu opțiunile sale -l și -A . Se va permite precizarea de argumente multiple de tip nume de fișiere sau directoare.

---

#### MyRm
Să se scrie un program C ce implementează comanda rm , inclusiv cu opțiunile sale -i și -r . Se va permite precizarea de argumente multiple de tip nume de fișiere sau directoare.

---

#### MyChmod
Să se scrie un program C ce implementează o variantă interactivă a comenzii chmod , i.e. programul va afișa meniuri text pentru interacțiunea cu utilizatorul, în vederea interogării acestuia pentru schimbarea permisiunilor fișierelor.

---

#### The filter Octal2Binary
Să se scrie un program C care primește de la linia de comandă numele a două fișiere, cu care va face următoarea procesare: va copia conținutul fișierului de intrare în cel de ieșire, înlocuind fiecare cifră în octal întâlnită (i.e., caracterele '0', '1', ..., '7') cu tripleta de caractere reprezentând numărul echivalent în baza 2, scris în format big-endian. Exemplu: cifra '6' în octal este echivalentă cu numărul '110' în baza 2, prin urmare caracterul '6' va fi înlocuit cu tripleta de caractere '1','1','0' (în această ordine).
În caz că fișierul de ieșire deja există, se va cere confirmare de suprascriere. Respectiv, va fi creat în cazul în care nu există, cu drepturi de citire și scriere doar pentru proprietar.
Cerință obligatorie: pentru accesarea fișierelor se vor utiliza apelurile de sistem din API-ul POSIX.
Cerință suplimentară: dacă de la linia de comandă se primește un singur nume de fișier, sau dacă numele fișierului de ieșire coincide cu numele celui de intrare, atunci se va trata, într-un mod adecvat, această situație (i.e., nu se mai face copiere, ci supra-scriere).
(Indicație: printr-o singură parcurgere a fișierului de intrare, copiați fiecare caracter citit, aplicând transformarea cerută, în fișierul de ieșire.)

---

#### The filter Base64
Să se scrie un program C care primește de la linia de comandă numele a două fișiere, cu care va face următoarea procesare: va copia conținutul fișierului de intrare în cel de ieșire, aplicând o transformare de tip Base64 ce codifică fiecare tripletă de caractere ASCII (orice caracter din setul ASCII, nu doar litere și cifre) prin patru valori din setul Base64.
În caz că fișierul de ieșire deja există, se va cere confirmare de suprascriere. Respectiv, va fi creat în cazul în care nu există, cu drepturi de citire și scriere doar pentru proprietar.
Despre ce este o transformare de tip Base64 puteți citi aici.
Cerință obligatorie: pentru accesarea fișierelor se vor utiliza apelurile de sistem din API-ul POSIX.
Cerință suplimentară: dacă de la linia de comandă se primește un singur nume de fișier, sau dacă numele fișierului de ieșire coincide cu numele celui de intrare, atunci se va trata, într-un mod adecvat, această situație (i.e., nu se mai face copiere, ci supra-scriere).
(Indicație: printr-o singură parcurgere a fișierului de intrare, copiați fiecare caracter citit, aplicând transformarea cerută, în fișierul de ieșire.)

---

#### MyUniq
Să se scrie un program C ce implementează comanda uniq, inclusiv cu opțiunile -c și -w N, unde N este un string reprezentând o valoare întreagă pozitivă.
Se va permite precizarea de argumente multiple de tip nume de fișiere, în linia de comandă a programului, pentru procesare.
Cerință obligatorie: pentru accesarea fișierelor se vor utiliza apelurile de sistem din API-ul POSIX.
(Indicație: încercați să simulați cât mai exact comportamentul comenzii uniq, inclusiv cu cele două opțiuni specificate.)

---

#### MyTac
Să se scrie un program C ce implementează comanda tac, inclusiv cu opțiunile -b și -s STRING.
Se va permite precizarea de argumente multiple de tip nume de fișiere, în linia de comandă a programului, pentru procesare.
Cerință obligatorie: pentru accesarea fișierelor se vor utiliza apelurile de sistem din API-ul POSIX.