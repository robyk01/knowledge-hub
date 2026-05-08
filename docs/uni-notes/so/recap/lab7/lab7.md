I) Exerciții de programare ce implementează comunicații între procese (prima parte, folosind canale de comunicație anonime) :

Exerciții propuse spre rezolvare:

Iată un exercițiu de programare ce utilizează comunicații prin canale anonime, pe care să încercați să-l rezolvați în timpul acestui laborator:

[Pipe commands #3]
Generalizarea exercițiilor rezolvate [Pipe commands #1 & #2] prezentate în suportul online de laborator :
Să se scrie un program C care "simulează" comanda înlănțuită:
UNIX> ps -eo user,comm,pid --no-headers | tr -s " " | cut -d" " -f1,2,3 --output-delimiter=: | sort -k2 -t:
Cerință: pentru executarea comenzilor simple din lanț se vor utiliza apeluri de sistem din familia exec și nu funcția system.
(Indicație: rezolvare similară ca la exercițiile amintite mai sus, doar că va fi nevoie de 4 procese, câte unul pentru fiecare comandă simplă din comanda înlănțuită din enunț, și respectiv de 3 canale anonime pentru realizarea înlănțuirilor.)

Iată și o sugestie generală de rezolvare a problemelor de genul celei propuse mai sus:  Show / Hide some suggestions for solving these problems
Ideea generală de rezolvare se poate desprinde ușor recitind, cu atenție, fie observația referitoare la a treia soluție prezentată în exercițiul rezolvat [Pipe commands #2] din suportul online de laborator, fie observația referitoare la a doua soluție prezentată în același exercițiu.
Exerciții suplimentare, propuse spre rezolvare pentru acasă:

Iată alte câteva exerciții de programare ce utilizează comunicații prin canale anonime, pe care să încercați să le rezolvați singuri în timpul liber, pentru a vă auto-evalua cunoștințele dobândite în urma acestui laborator.

[MyShell v2, with pipelines]   Show / hide this problem
Incorporați în programul realizat la exercițiul [MyShell v1] din laboratorul #5, ideea generalizată de la exercițiile [Pipe commands #1, #2 și #3] din laboratorul curent:

Să se scrie un program C care, într-o buclă, preia de la tastatură numele a m comenzi simple înlănțuite prin simbolul pipe, i.e. o linie de forma următoare:
UNIX> comanda1 arg1,1 ... arg1,N1 | comanda2 arg2,1 ... arg2,N2 | ... ... | comandam argm,1 ... argm,Nm
și le execută în manieră înlănțuită, similar interpretoarelor clasice de comenzi din UNIX/Linux.
La așteptarea introducerii unei noi comenzi înlănțuite, programul va afișa prompterul "UNIX>". Pentru executarea comenzilor se vor utiliza apeluri de sistem din familia exec și nu funcția system.

Show / Hide some suggestions for solving this problem

['Supervisor-workers' pattern #6: A coordinated distributed sum #1N (v2, using anonymous pipes for IPC)]   Hide / show this problem
Să se modifice programul din exercițiul rezolvat ['Supervisor-workers' pattern #1N: A coordinated distributed sum #1N (v1, using regular files for IPC)] prezentat în suportul de laborator #5, astfel încât comunicațiile între procese să se realizeze prin canale anonime, în loc de fișiere obișnuite.
În plus, citirea numerelor de la tastatură se va muta în cod după apelurile fork(), lucru posibil deoarece sincronizările ce erau necesare în varianta cu fișiere obișnuite, se vor realiza acum în mod automat (prin faptul că citirea din canale este, în mod implicit, blocantă).
(Indicație: este suficient să utilizați doar N+1 canale anonime, în locul celor N+N fișiere de intrare și de ieșire.)

II) Exerciții de programare ce implementează comunicații între procese (partea a doua, folosind canale de comunicație fifo) :

Exerciții propuse spre rezolvare:

Iată un exercițiu de programare mai complex, ce folosește comunicații între procese de ambele tipuri (i.e., canale anonime și canale fifo) ; încercați să-l rezolvați în timpul acestui laborator:

['Supervisor & cooperating workers' pattern #1 (using pipes and fifos for IPC)]
Să se scrie un program C ce creează două procese fii și care va avea comportamentul descris în continuare:
- procesul părinte citește dintr-un fișier cu numele input-data.txt un șir de caractere, până la sfârșitul fișierului, și le trimite printr-un canal anonim primului fiu;
- primul proces fiu primește caracterele de la procesul părinte, le selectează doar pe acelea care sunt cifre hexazecimale (i.e., cifre în baza 16 ; în plus, literele mari 'A',...,'F' vor fi convertite la minuscule 'a',...,'f') și le trimite printr-un canal fifo către cel de-al doilea fiu;
- al doilea proces fiu creează un fișier numit statistics.txt în care va scrie, pe câte o linie, fiecare cifră distinctă și numărul de apariții ale acesteia în fluxul de date primit. În plus, la final va trimite părintelui, printr-un alt canal anonim, numărul de cifre distincte întâlnite în fluxul primit;
- procesul părinte afișează pe ecran rezultatul primit de la al doilea proces fiu.
Cerință: pentru comunicarea între procese se vor folosi două canale anonime și un canal fifo, conform celor specificate mai sus.

Show / Hide some suggestions for solving the problem
Exerciții suplimentare, propuse spre rezolvare pentru acasă:

Iată alte câteva exerciții de programare ce utilizează comunicații prin canale fifo, pe care să încercați să le rezolvați singuri în timpul liber, pentru a vă auto-evalua cunoștințele dobândite în urma acestui laborator.

['Supervisor-workers' pattern #7: A coordinated distributed sum #1N (v3, using fifos for IPC)]
Să se modifice programul din exercițiul rezolvat ['Supervisor-workers' pattern #1N: A coordinated distributed sum #1N (v1, using regular files for IPC)] prezentat în suportul de laborator #5, astfel încât comunicațiile între procese să se realizeze prin canale fifo, în loc de fișiere obișnuite.
În plus, citirea numerelor de la tastatură se va muta în cod după apelurile fork(), lucru posibil deoarece sincronizările ce erau necesare în varianta cu fișiere obișnuite, se vor realiza acum în mod automat (prin faptul că citirea din canale este, în mod implicit, blocantă).
(Indicație: sunt suficiente doar N+1 canale fifo, în locul celor N+N fișiere de intrare și de ieșire.)

I) Exerciții de programare cu semnale, pentru programare asincronă și tratarea excepțiilor:

Exerciții propuse spre rezolvare:

Iată un exercițiu de programare C cu procesări de semnale, pe care să încercați să îl rezolvați în timpul acestui laborator:

[Signal processing #2 (using signals for syncronization between father and child)]
Să se scrie un program C care la execuție mai întâi va crea un proces fiu și apoi va avea comportamentul descris în continuare.
Programul inițial (i.e., procesul tată) va copia intrarea standard într-un fișier text, al cărui nume este specificat în linia de comandă a programului.
Dacă se scurge un timp egal cu 5*N secunde (i.e., 5 intervale de câte N secunde), de la începerea execuției programului, fără a se introdude nici un caracter de la tastatură, atunci programul va fi terminat, cu codul de exit 1 (i.e., nu este lăsat să aștepte input de la tastatură pe o perioadă nelimitată). Altfel, programul va fi terminat atunci când utilizatorul tastează CTRL+D (i.e., EOF în fluxul stdin), cu codul de exit 0.
Valoarea constantei N este specificată, de asemenea, ca și argument al programului în linia de comandă.
În plus, pentru fiecare interval de N secunde dintre cele 5 amintite mai sus, dacă acel interval este neutilizat (i.e., fără input de la tastatură din partea utilizatorului), atunci utilizatorul va fi atenționat printr-un mesaj corespunzător.
Iar înainte de a se termina (în ambele situații posibile de terminare descrise mai sus), după ce a închis fișierul de output, procesul părinte va trimite procesului fiu semnalul SIGUSR2, iar apoi va aștepta semnalul SIGCHLD (generat automat de fiu când acesta se va termina) și abia apoi va afișa pe ecran un mesaj de terminare (e.g., "Parinte: sfarsit executie!") și își va încheia execuția, cu codul de exit specificat mai sus, pentru cele două situații posibile de terminare descrise mai sus.
Iar procesul fiu va începe prin a aștepta primirea semnalului SIGUSR2, iar la primirea acestuia va afișa pe ecran un mesaj de genul "Fiul: am primit USR2!", urmat de afișarea pe ecran a conținutului fișierului de output creat de părinte, și apoi își va încheia execuția, afișând pe ecran un mesaj corespunzător (e.g., "Fiul: sfarsit executie!").
(Indicație: pentru măsurarea scurgerii intervalelor de N secunde, tratați semnalul SIGALRM, generat cu apelul alarm.)

Show / Hide some suggestions for solving this problem
Exerciții suplimentare, propuse spre rezolvare pentru acasă:

Iată alte câteva exerciții de programare cu procesări de semnale, pe care să încercați să le rezolvați singuri în timpul liber, pentru a vă auto-evalua cunoștințele dobândite în urma acestui laborator.

['Ping-pong' pattern #5 (using signals for syncronization)]   Hide / show this problem

Două procese, ce nu sunt înrudite (i.e. nu sunt în relația părinte-fiu), trebuie să citească alternativ câte un caracter dintr-un fișier text fis.txt. Sincronizarea execuției celor două procese, pentru citirea alternativă din fișier, va fi realizată exclusiv prin semnale. Comunicarea reciprocă a PID-urilor (PID-urile sunt necesare pentru a putea trimite semnale unul altuia) se va face la începutul execuției lor, prin canale de comunicație fifo (sau printr-un fișier de date). Caracterele citite de fiecare proces vor fi scrise în fișierele fis_poz-impare.txt și, respectiv, fis_poz-pare.txt.
