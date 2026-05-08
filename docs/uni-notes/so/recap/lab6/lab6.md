# I. Exerciții de programare cu fișiere mapate în memorie
Diverse procesări de fișiere, operate direct în memorie

## a) Exerciții propuse spre rezolvare

Iată câteva exerciții de programare C cu procesări de fișiere, operate direct în memorie, pe care să încercați să le rezolvați în timpul acestui laborator:

### #1: MyTr_mmap

Să se rescrie programul cerut în exercițiul [#1: The filter MyTr], propus în laboratorul #4, astfel încât să utilizeze interfața de prelucrare a fișierelor prin mapare în memorie, în locul interfeței clasice de acces I/O la disc (i.e., nu folosiți apelurile de sistem read() și write(), sau cele din biblioteci de genul stdio).

### #2: MyHead_mmap

Să se rescrie programul cerut în exercițiul [#2: The command MyHead], propus în laboratorul #4, astfel încât să utilizeze interfața de prelucrare a fișierelor prin mapare în memorie, în locul interfeței clasice de acces I/O la disc (i.e., nu folosiți apelurile de sistem read() și write(), sau cele din biblioteci de genul stdio).

Atenție: cu alte cuvinte, trebuie să rescrieți cele două programe propuse spre rezolvare în laboratorul #6 astfel încât să utilizeze interfața de prelucrare a fișierelor prin mapare în memorie, în locul interfeței clasice de acces I/O la disc (i.e., nu folosiți apelurile de sistem read() și write(), sau cele din biblioteci de genul stdio).

Iată și câteva sugestii de rezolvare a acestor probleme propuse mai sus:

Show / Hide some suggestions for solving these problems

## b) Exerciții suplimentare pentru acasă

Iată alte câteva exerciții de programare C cu fișiere mapate în memorie, pe care să încercați să le rezolvați singuri în timpul liber, pentru a vă auto-evalua cunoștințele dobândite în urma acestui laborator.

### MyWc_mmap

Să se rescrie programul ilustrat în exercițiul rezolvat [MyWc] prezentat în suportul de laborator #4, astfel încât să utilizeze interfața de prelucrare a fișierelor prin mapare în memorie, în locul interfeței clasice de acces I/O la disc (i.e., nu folosiți apelurile de sistem read() și write(), sau cele din biblioteci de genul stdio).

### MyCp_mmap

Să se rescrie programul ilustrat în exercițiul rezolvat [MyCp] prezentat în suportul de laborator #4, astfel încât să utilizeze interfața de prelucrare a fișierelor prin mapare în memorie, în locul interfeței clasice de acces I/O la disc (i.e., nu folosiți apelurile de sistem read() și write(), sau cele din biblioteci de genul stdio).

### ArithmeticMean_mmap

Să se rescrie programul ilustrat în exercițiul rezolvat [ArithmeticMean] prezentat în suportul de laborator #4, astfel încât să utilizeze interfața de prelucrare a fișierelor prin mapare în memorie, în locul interfeței clasice de acces I/O la disc (i.e., nu folosiți apelurile fscanf() și fprintf() din biblioteca stdio). În schimb, pentru conversia datelor din memorie, între reprezentarea 'textuală' și cea 'binară', puteți apela funcțiile sscanf() și sprintf() din biblioteca stdio).

### MyExpr_mmap

Să se rescrie programul ilustrat în exercițiul rezolvat [MyExpr] prezentat în suportul de laborator #4, astfel încât să utilizeze interfața de prelucrare a fișierelor prin mapare în memorie, în locul interfeței clasice de acces I/O la disc (i.e., nu folosiți apelurile fscanf() și fprintf() din biblioteca stdio). În schimb, pentru conversia datelor din memorie, între reprezentarea 'textuală' și cea 'binară', puteți apela funcțiile sscanf() și sprintf() din biblioteca stdio).

# II. Exerciții de programare a unor probleme de sincronizare și cooperare
Procese multiple prin memorie partajată

## a) Exerciții propuse spre rezolvare

Încercați să rezolvați singuri, la alegere, una dintre cele două probleme de sincronizare din lista următoare :

### MyCS_shmem #1

Să se rescrie programul din exercițiul rezolvat [MyCritSec #1] prezentat în suportul de laborator #4, astfel încât să utilizeze interfața de prelucrare a fișierelor prin mapare în memorie, plus mecanisme de sincronizare bazate pe memorie partajată (e.g., semafoare POSIX), în locul interfeței clasice de acces I/O la disc (i.e., apelurile read() și write(), etc.) și a sincronizării bazate pe blocaje pe fișiere.

### MyCS_shmem #2 : Parallel sorting

Să se rescrie programul de sortare paralelă din exercițiul rezolvat [MyCritSec #2 : Parallel sorting] prezentat în suportul de laborator #4, astfel încât să utilizeze interfața de prelucrare a fișierelor prin mapare în memorie, plus mecanisme de sincronizare bazate pe memorie partajată (e.g., semafoare POSIX), în locul interfeței clasice de acces I/O la disc (i.e., apelurile read() și write(), etc.) și a sincronizării bazate pe blocaje pe fișiere.

## b) Exerciții suplimentare pentru acasă

Iată alte câteva exerciții de programare C cu memorie partajată și sincronizări folosind semafoare, pe care să încercați să le rezolvați singuri în timpul liber, pentru a vă auto-evalua cunoștințele dobândite în urma acestui laborator.

Aceste exerciții se referă la câteva instanțe ale unor probleme de sincronizare clasice, instanțe ce reprezintă practic niște cazuri particulare ale acelor probleme generale, și care au mai fost propuse spre rezolvare și în laboratorul #4 (dar acolo sincronizările necesare trebuiau implementate folosind blocaje pe fișiere):

### MyCREW_shmem #1

Să se rescrie programul din exercițiul [MyCREW #1], propus spre rezolvare în laboratorul #4, astfel încât să utilizeze interfața de prelucrare a fișierelor prin mapare în memorie, plus mecanisme de sincronizare bazate pe memorie partajată (e.g., semafoare POSIX), în locul interfeței clasice de acces I/O la disc (i.e., apelurile read() și write(), etc.) și a sincronizării bazate pe blocaje pe fișiere.

### MyCREW_shmem #2

Să se rescrie programul din exercițiul [MyCREW #2], propus spre rezolvare în laboratorul #4, astfel încât să utilizeze interfața de prelucrare a fișierelor prin mapare în memorie, plus mecanisme de sincronizare bazate pe memorie partajată (e.g., semafoare POSIX), în locul interfeței clasice de acces I/O la disc (i.e., apelurile read() și write(), etc.) și a sincronizării bazate pe blocaje pe fișiere.

### MyCS_shmem #2bis : Parallel sorting II

Să se rescrie programul de sortare paralelă din exercițiul suplimentar [MyCritSec #2bis : Parallel sorting II], propus spre rezolvare în laboratorul #4, astfel încât să utilizeze interfața de prelucrare a fișierelor prin mapare în memorie, plus mecanisme de sincronizare bazate pe memorie partajată (e.g., semafoare POSIX), în locul interfeței clasice de acces I/O la disc (i.e., apelurile read() și write(), etc.) și a sincronizării bazate pe blocaje pe fișiere.

### MyCS_shmem #2game : Parallel sorting III

Să se rescrie programul de sortare paralelă din exercițiul suplimentar [MyCritSec #2game : Parallel sorting III], propus spre rezolvare în laboratorul #4, astfel încât să utilizeze interfața de prelucrare a fișierelor prin mapare în memorie, plus mecanisme de sincronizare bazate pe memorie partajată (e.g., semafoare POSIX), în locul interfeței clasice de acces I/O la disc (i.e., apelurile read() și write(), etc.) și a sincronizării bazate pe blocaje pe fișiere.


### 'Ping-pong' pattern #3 (v1, using anon mmap for syncronization)

Se consideră două fișiere, nume.txt și telefon.txt, în care sunt scrise, pe câte o linie, numele și respectiv numerele de telefon ale unor persoane (se va trata și cazul de excepție când nu există o corespondență bijectivă la nivel de linie între cele două fișiere).
Să se scrie un program C care să creeze un fiu, după care se vor realiza următoarele operații: tatăl va citi, în mod repetat, câte o linie cu date din fișierul nume.txt și o va scrie în fișierul agenda_tel.txt, iar fiul va citi, în mod repetat, câte o linie cu date din fișierul telefon.txt și o va scrie în fișierul agenda_tel.txt.
În plus, cele două procese trebuie să se sincronizeze conform șablonului 'Ping-pong', folosind o mapare anonimă, astfel încât informațiile să apară exact pe câte o linie, sub forma "NUME - TELEFON", în fișierul de ieșire agenda_tel.txt, și nu alte combinații posibile de "interclasare" a informațiilor parțiale scrise de cele două procese aflate în execuție simultană.
(Indicație: scopul acestui exercițiu este acela de a implementa corect un mecanism de sincronizare de forma "Acum e rândul meu --> acum e rândul tău --> acum e rândul meu --> acum e rândul tău --> ... ș.a.m.d.", folosind comunicații prin intermediul unei zone de memorie partajată (i.e., o mapare anonimă), în locul unui fișier obișnuit.
Notă: după cum am mai spus, șablonul 'ping-pong' este de fapt o instanță cu p=2 procese, pentru un șablon mai general de sincronizare între p procese, cunoscut în literatura de specialitate sub denumirea de șablonul de sincronizare token ring.)
Show / Hide some suggestion for this problem

### 'Token ring' pattern #1 (v1, using anon mmap for syncronization)

Se consideră trei fișiere, nume.txt, prenume.txt și nota.txt, în care sunt înregistrate, câte unul pe linie, numele, prenumele și respectiv nota obținută de mai mulți studenți la o anumită disciplină (se va trata și cazul de excepție când nu există o corespondență bijectivă la nivel de linie între cele trei fișiere).
Să se scrie un program C care să creeze doi fii, după care se vor realiza următoarele operații: tatăl va citi, în mod repetat, câte o linie cu date din fișierul nume.txt și o va scrie într-un fișier de ieșire, numit tabel.txt, primul fiu va citi, în mod repetat, câte o linie cu date din fișierul prenume.txt și o va scrie în fișierul de ieșire tabel.txt, iar al doilea fiu va citi, în mod repetat, câte o linie cu date din fișierul nota.txt și o va scrie în fișierul de ieșire tabel.txt.
În plus, cele trei procese trebuie să se sincronizeze conform șablonului general 'Token-ring' particularizat pentru p=3 procese, folosind o mapare anonimă, astfel încât informațiile să apară exact pe câte o linie, sub forma "NUME - PRENUME - NOTA", în fișierul de ieșire tabel.txt, și nu alte combinații posibile de "interclasare" a informațiilor parțiale scrise de cele trei procese aflate în execuție simultană.
(Indicație: scopul acestui exercițiu este acela de a implementa corect un mecanism de sincronizare de forma "Acum e rândul jucătorului #1 --> acum e rândul jucătorului #2 --> acum e rândul jucătorului #3 --> acum e rândul jucătorului #1 --> acum e rândul jucătorului #2 --> acum e rândul jucătorului #3 -->... ș.a.m.d.", folosind comunicații prin intermediul unei zone de memorie partajată (i.e., o mapare anonimă), în locul unui fișier obișnuit.)
Show / Hide some suggestion for this problem

### 'Token ring' pattern #2 : "Eeny, meeny, miny, moe, ..." (v1, using anon mmap for syncronization)

Să se scrie un program C care să creeze trei fii, după care se vor realiza următoarele operații: tatăl va scrie pe ecran textul "ini-" în mod repetat, primul fiu va scrie pe ecran textul "mini-" în mod repetat, al doilea fiu va scrie pe ecran textul "maini-" în mod repetat, iar al treilea fiu va scrie pe ecran textul "mo, " în mod repetat.
În plus, cele patru procese trebuie să se sincronizeze conform șablonului 'Token-ring' particularizat pentru p=4 procese, astfel încât pe ecran să apară exact succesiunea de mesaje:
  ini-mini-maini-mo, ini-mini-maini-mo, ini-mini-maini-mo, ini-mini-maini-mo, ...  
și nu alte combinații posibile de "interclasare" a mesajelor afișate de cele patru procese aflate în execuție simultană.
(Indicație: scopul acestui exercițiu este acela de a implementa corect un mecanism de sincronizare de forma "Acum e rândul jucătorului #1 --> acum e rândul jucătorului #2 --> acum e rândul jucătorului #3 --> acum e rândul jucătorului #4 --> acum e rândul jucătorului #1 --> acum e rândul jucătorului #2 --> acum e rândul jucătorului #3 --> acum e rândul jucătorului #4 ->... ș.a.m.d.", folosind comunicații prin intermediul unei zone de memorie partajată (i.e., o mapare anonimă), în locul unui fișier obișnuit.)

Show / Hide some suggestion for this problem

### 'Supervisor-workers' pattern #1 (v2, using mmap-files for IPC)

Re-implementați programul prezentat în exercițiul rezolvat ['Supervisor-workers' pattern #1 : A coordinated distributed sum #1 (v1, using regular files for IPC)] din suportul de laborator #5, astfel încât cele 4 fișiere folosite pentru comunicații să fie accesate prin maparea lor în memorie.

Show / Hide some suggestion for this problem

### 'Supervisor-workers' pattern #1 (v3, using anon mmap for IPC)

Show / Hide this problem

### #1: Yet another instance of the 'Supervisor-workers' pattern (using anon mmap for IPC)

Să se scrie un program C care va crea două procese fii. Apoi, părintele va genera (pseudo-)aleator 1000 de numere naturale, mai mici decât 101, pe care le va transmite fiilor, astfel: numerele impare vor fi trimise primului fiu, iar numerele pare celui de-al doilea fiu (păstrându-le ordinea în care au fost generate). Primul fiu va determina care dintre numerele primite sunt numere prime, transmițându-le înapoi părintelui doar pe cele prime (cu păstrarea ordinii lor). Al doilea fiu va determina care dintre numerele primite sunt divizibile cu 4, transmițându-le înapoi părintelui doar pe acelea (cu păstrarea ordinii lor). Părintele va salva numerele primite de la ambii fii într-un singur vector, pe care-l va sorta crescător și va afișa la final rezultatul sortării.
Cerință: pentru comunicațiile dintre tată și fiecare fiu, se va folosi (câte) o mapare anonimă.