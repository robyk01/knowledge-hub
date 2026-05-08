# I. Exerciții de programare cu mai multe procese secvențiale - Partea I
Creare diverse ierarhii de procese și execuția programatică a unor comenzi uzuale

## a) Exerciții propuse spre rezolvare

Iată un exercițiu de programare C cu creare de diverse ierarhii de procese, precum și un exercițiu de programare C cu apeluri exec*, pe care să încercați să le rezolvați în timpul acestui laborator:

### A particular tree of processes

Să se scrie un program C care să creeze un arbore particular de procese, având 3 nivele, structurate astfel:
1) unicul proces P1,1 de pe nivelul 1 al arborelui (i.e., rădăcina arborelui) va avea 4 procese fii, și anume procesele P2,1 , P2,2 , P2,3 și P2,4 de pe nivelul 2 al arborelui;
2) fiecare dintre cele 4 procese de pe nivelul 2 al arborelui, va avea la rândul său 3 procese fii pe nivelul 3 al arborelui, numerotate cu P3,1 , P3,2 , ... , P3,12 , care vor fi astfel "nepoți" ai procesului din rădăcina arborelui și, în plus, nu vor avea nici un fiu la rândul lor (i.e., vor fi "frunze" în arbore).

Fiecare proces va afișa pe ecran, pe o singură linie (!), mesajul compus din următoarele informații: "numărul lui de ordine" în arbore, urmat de PID-ul lui, cel al părintelui său, precum și perechile de PID-uri și coduri de terminare corespunzătoare tuturor fiilor acestuia. (Prin "numărul lui de ordine" în arbore înțelegem perechea (i,j) , ce poate avea următoarele valori: (1,1), (2,1), (2,2), (2,3), (3,1), ... , (3,12) .)

Show / Hide some suggestion for this problem

### Exec command #5: cut

i) Să se scrie un program C care să execute comanda cut --fields 1,3,4,6 -d: --output-delimiter=" -- " /etc/passwd , iar la sfârșitul execuției comenzii să afișeze textul: "Comanda cut a fost executata ...", dar numai în situația când într-adevăr s-a executat comanda cut, altfel să fie afișat textul: "Comanda cut nu a putut fi executata...".
Cerință obligatorie: se va folosi execvp și nu funcția system, și nici execlp !

ii) Să se rescrie programul de la punctul i), utilizând primitiva execv în locul primitivei execvp.

//TODO (Sarcină pentru dvs.): testați corectitudinea programului scris, în sensul că outputul afișat de acesta pe ecran să fie IDENTIC cu outputul afișat de comanda specificată în enunț!

Show / Hide some suggestions for solving the problem

Iar acum, încercați să completați codul lipsă din cele două exerciții parțial rezolvate prezentate în suportul de laborator asociat acestei lecții.

## b) Exerciții suplimentare pentru acasă

### A perfect k-ary tree of processes #1 (v1 = the recursive version)

Să se scrie un program C care să creeze un arbore K-ar perfect cu N nivele, de procese (valorile K și N vor fi citite de la tastatură, sau primite din linia de comandă).
Și anume: unicul proces P1,1 de pe nivelul 1 al arborelui (i.e., rădăcina arborelui) va avea K procese fii, și anume procesele P2,1,...,P2,K de pe nivelul 2 al arborelui, fiecare dintre acestea va avea la rândul său K procese fii pe nivelul 3 al arborelui, ș.a.m.d. până la cele KN-1 procese de pe nivelul N al arborelui, care nu vor avea nici un fiu.
Fiecare proces își va tipări, printr-un singur mesaj, numărul lui de ordine în arbore (i.e. perechea i,j cu 1≤i≤N și 1≤j≤Ki-1), PID-ul lui, pe cel al părintelui său, precum și PID-urile celor K fii ai acestuia și codurile acestora de terminare.

Cerință: proiectați o rezolvare recursivă a acestei probleme (i.e., folosiți o funcție recursivă pentru crearea proceselor), astfel:

i) prin recursie doar după adâncimea în arbore, N (recursia este mai simplă);
sau
ii) prin recursie după K și N (recursia este mai complexă).

Show / Hide some suggestion for this problem

### A perfect k-ary tree of processes #2 (v2 = the iterative version)

Să se elaboreze o soluție iterativă a problemei [A perfect k-ary tree of processes #1] (i.e., folosiți bucle iterative pentru crearea proceselor).

Show / Hide some suggestion for this problem

### MyCall_System

Să se scrie un program C care să simuleze apelul funcției system, folosind doar apeluri fork, wait și exec.

Show / Hide some suggestions for solving the problem

### Run SPMD programs (versiunea în C)

Să se scrie un program C care să implementeze în C funcționalitatea scriptului RunMySPMD.sh, ce a fost descris în exercițiul rezolvat [Run SPMD programs] prezentat în suportul de laborator #3.

Cerință: trebuie să scrieți cod C echivalent cu acel script bash, adică NU vă este permis să apelați direct acel script, prin intermediul vreunei primitive exec sau a funcției system !

Show / Hide some suggestions for solving the problem

# II. Exerciții de programare cu mai multe procese secvențiale - Partea II
Diverse probleme de sincronizare a unor procese cooperante

## a) Exerciții propuse spre rezolvare

### 'Supervisor-workers' pattern #2 (v1, using regular files for IPC)

Completați codul ce lipsește din programul prezentat în exercițiul parțial rezolvat ['Supervisor-workers' pattern #2 (v1, using regular files for IPC)] din suportul de laborator #5, pe baza indicațiilor de rezolvare date acolo.

Show / Hide some suggestion for this problem

### 'Ping-pong' pattern #1 (v1, using regular file for syncronization)

Completați codul ce lipsește din programul prezentat în exercițiul parțial rezolvat ['Ping-pong' pattern #1 (v1, using regular file for syncronization)] din suportul de laborator #5, pe baza indicațiilor de rezolvare date acolo.

Show / Hide some suggestion for this problem

## b) Exerciții suplimentare pentru acasă

### MyShell v1

Să se scrie un program C care să ofere funcționalitatea minimă, de bază, a unui shell pentru sistemele de operare UNIX/Linux: într-o buclă va afișa un prompter și va prelua de la tastatură numele unei comenzi simple, cu sau fără parametri, pe care o va executa, fie în foreground (caz în care va aștepta terminarea execuției ei înainte de a reafișa prompterul), fie în background (caz în care nu mai așteaptă terminarea ei), apoi va relua bucla de citire și execuție de comenzi simple, până la citirea comenzilor exit sau logout.

Cerințe: se va folosi primitiva execlp și nu funcția system ! La așteptarea introducerii unei comenzi, programul va afișa ca prompter textul: MyShell> .

### 'Supervisor-workers' pattern #5: Coordinated parallel sorting

Să se scrie un program C care să realizeze coordonarea execuției simultane și concurente a N instanțe ale programului de sortare cu lacăte din exercițiul rezolvat [MyCritSec #2 : Parallel sorting] prezentat în suportul de laborator #4.

(Indicație: Mai precis, programul pe care trebuie să-l scrieți va crea N procese fii, iar în fiecare fiu va executa programul de sortare cu lacăte.)

Show / Hide some suggestions for solving the problem

### 'Ping-pong' pattern #2: "Heigh-Ho, Heigh-Ho, ..." (v1, using a regular file for syncronization)

Să se scrie un program C care să creeze un fiu, după care se vor realiza următoarele operații: tatăl va scrie pe ecran mesajul "hi-" în mod repetat, iar fiul va scrie pe ecran mesajul "ho, " în mod repetat.

În plus, cele două procese trebuie să se sincronizeze conform șablonului 'Ping-pong', astfel încât pe ecran să apară exact succesiunea de mesaje:   hi-ho, hi-ho, hi-ho, hi-ho, hi-ho, ...   și nu alte combinații posibile de "interclasare" a mesajelor afișate de cele două procese aflate în execuție simultană.

(Indicație: scopul acestui exercițiu este acela de a implementa corect un mecanism de sincronizare de forma "Acum e rândul meu --> acum e rândul tău --> acum e rândul meu --> acum e rândul tău --> ... ș.a.m.d.", folosind comunicații prin intermediul unui fișier obișnuit. )

Show / Hide some suggestion for this problem

### Another parallel sorting, based on merge-sort (v1, using regular file for IPC)

Să se implementeze algoritmul de sortare merge sort lucrând pe un fișier ce conține o secvență de numere stocate în format binar, folosind lacăte pe porțiuni din fișier pentru secțiunile critice din program, într-o manieră similară ca la exercițiul rezolvat [MyCritSec #2 : Parallel sorting] prezentat în suportul de laborator #4.

Cerință: în loc de lansări simultane în execuție ale programului, printr-o comandă asemănătoare ca la exercițiul amintit mai sus:
UNIX> ./mergesort 1 & ./mergesort 2 & ./mergesort 3 & ... ,
acum veți crea prin program procesele necesare, cu apeluri fork (și astfel va fi suficientă o singură lansare în execuție a programului).

Practic, programul va crea un arbore binar de procese, "frunzele" făcând comparațiile și inversiunile propriu-zise, iar apoi procesele părinte realizează interclasarea secvențelor parțiale, ordonate de procesele copii.

Show / Hide some suggestion for this problem

### 'Client/Server' pattern #1: A supervisor which spawns a new worker for every task received

Show / Hide this problem

### 'Client/Server' pattern #1bis: A supervisor which spawns a new worker for every task received

Show / Hide this problem

### 'Client/Server' pattern #2: A supervisor which spawns a new worker for every task received

Show / Hide this problem

### 'Client/Server' pattern #2bis: A supervisor which spawns a new worker for every task received

Show / Hide this problem

# III. Exerciții cu greșeli "strecurate" intenționat în programe C

## a) Exerciții propuse pentru acasă

### Exemplul #2 cu erori sintactice și semantice
Se dă programul C de mai jos, ce conține (măcar) trei erori sintactice și o greșeală logică:

Show / Hide the program

/*
  Filename: p2.c

  Programul de mai jos ar trebui să ofere următoarea funcționalitate:

    Procesul principal creează un fiu.
    Procesul fiu se reacoperă cu comanda stat, executată cu opțiunea de a afisa tipul fișierului pentru fișierul "p2.c"
    și cu redirectarea output-ului către fișierul "fisier.txt".
    În acest timp, procesul părinte așteaptă să se termine fiul, apoi citește din "fisier.txt" primele 10 caractere și le afișează.

*/  

#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	int pid1;

	pid1 = fork();

	if(pid1 == -1)
	{
		perror(failed to create child process);
		return -1;
	}

	if(pid1==0)
	{
		int fd = open("fisier.txt", O_WRONLY|O_CREAT, 0600);
		dup2(fd, 1);
		close(fd);
		execlp("stat","stat","p2.c","--printf","%F" ,NULL);
		return 0;
	}
	else
	{
		wait(NULL);
		int fd = open("fisier.txt", O_RDONLY);
		char a;
		read(fd, &a, siezof(char));
		close(fd);
		print("Primele 10 caractere din fisier.txt sunt: %c\n", a);
	}

	return 0;
}

i) Explicați ce se dorește a se afișa pe ecran în urma execuției programului.
ii) Corectați eventualele erori existente astfel încât programul să poată fi executat și să ofere la execuție EXACT funcționalitatea descrisă în comentariul de la începutul programului.
Show / Hide some suggestions for solving the problem

### Exemplul #3 cu erori sintactice și semantice
Se dă programul C de mai jos, ce conține (măcar) trei erori sintactice și o greșeală logică:

Show / Hide the program

/*
  Filename: p3.c

  Programul de mai jos ar trebui să ofere următoarea funcționalitate:

    Procesul principal creează un fiu.
    Procesul fiu se reacoperă cu comanda ps, executată cu opțiunea -o pid,user,args.
    În acest timp, procesul părinte așteaptă să se termine fiul, apoi afișează un mesaj.

*/

#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[])
{

	int pid3;

	pid3 = fork();

	if(pid3 == -1)
	{
		perror("failed to create  child process");
		return -1;
	}

	if(pid != 0)
	{
		wait(NULL);
		print("Procesul fiu a executat comanda ps.\n");;
	}
	else
	{
		char* parametru[] = {"ps","-o","pid","user","args",NULL};
		execvp("ps", parametru);
		abort();
	}

	return perror;
}

i) Explicați ce se dorește a se afișa pe ecran în urma execuției programului.
ii) Corectați eventualele erori existente astfel încât programul să poată fi executat și să ofere la execuție EXACT funcționalitatea descrisă în comentariul de la începutul programului.
Show / Hide some suggestions for solving the problem

### Exemplul #4 cu erori sintactice și semantice
Se dă programul C de mai jos, ce conține (măcar) trei erori sintactice și o greșeală logică:

Show / Hide the program

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
	char w=0, *text;
	int p, q[2];
	pipe(q[2]);
	p=fork(2);
	if(p==-1) exit(2);
	if(!p)
	{
		dup2(q[0],0);
		close(q[1]);
		while( read(0,&w,1) != 0)
			printf("%c",w);
		wait(NULL);
	}
	elif
	{
		text="Salutari!\n";
		write(q[0],text,strlen(text));
	}
	return 0;
}

i) Explicați ce se dorește a se afișa pe ecran în urma execuției programului.
ii) Corectați eventualele erori existente astfel încât programul să poată fi executat și să producă la execuție afișarea pe ecran de către procesul fiu a textului primit de la părinte.
(Recomandare: abordați acest exercițiu după ce învățați lecția despre canale de comunicație anonime, în laboratorul următor.)