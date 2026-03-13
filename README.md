# ORIENTED-GRAPHS---Interactive-and-educational-software
DESCRIEREA TEMEI: Prezentarea completă și interactivă a principalelor caracteristici și operații asociate grafurilor orientate, oferind utilizatorului o înțelegere mai profundă a acestui domeniu al informaticii.

DESCRIEREA PROGRAMULUI C++: Programul implementează o aplicație de prezentare generală a grafurilor orientate în limbajul C++. Utilizatorul poate selecta diferite opțiuni de afișare și analiză a grafului orientat citit dintr-un fișier, sau din consolă.
Programul utilizează 16 subprograme pentru a realiza aceste operații și oferă utilizatorului un meniu interactiv pentru a alege opțiunile dorite. Acesta conține și un test cu 9 întrebări, cu scopul revizuirii cunoștițelor legate de grafuri orientate. 



SUBPROGRAMELE UTILIZATE ȘI ROLURILE LOR:

1)	citire_fisier() - Citirea grafului orientat din fișierul “graf.in” și compunerea matricei de adicență a acestuia;
2)	citire_tastatura() – Citirea grafului orientat din consolă și compunerea matricei de adiacență a acestuia;
3)	gr_int() – Calculul gradului interior pentru un nod din graf;
4)	gr_ext() – Calculul gradului exterior pentru un nod din graf;
5)	nr_arce() - Calculul și afișarea numărului de arce din graful citit;
6)  afisare_matrice_adiacenta() - Afișarea matricei de adiacență asociate grafului citit;
7)	afisare_matrice_varfuri_arce() – Compunerea și afișarea matricei vârfuri-arce asociate grafului citit;
8)	succesori() - Afișarea listei de succesori (sau de adiacență) pentru fiecare nod din graful citit;
9)	predecesori() - Afișarea listei de predecesori pentru fiecare nod din graful citit;
10)	afisare_grade() - Calculul și afișarea gradelor fiecărui nod din graful citit;
11)	afisare_noduri_izolate() - Afișarea nodurilor izolate din graful citit;
12)	afisare_noduri_terminale() - Afișarea nodurilor terminale din graful citit;
13)	afisare_noduri_maximale() - Afișarea nodurilor maximale din graful citit;
14)	numar_grafuri() - Calculul și afișarea numărului total de grafuri cu numărul de noduri pe care îl are graful citit;
15)	adiacenta() - Determinarea adiacenței dintre două noduri ale grafului citit, introduse de utilizator la tastatură;
16)	graf_turneu() - Verificarea dacă graful citit este turneu;
17)	nrgraf_complet() – Calculul și afișarea numărului de grafuri complete cu numărul de noduri pe care îl are graful citit;
18)	muchiimin_lipsa_complet() – Calculul și afișarea numărului minim de muchii care pot fi adăugate pentru a face graful citit complet;
19)	muchiimax_lipsa_complet() - Calculul și afișarea numărului maxim de muchii care pot fi adăugate pentru a face graful citit complet;
20)	test() - Un test de evaluare a cunoștințelor despre grafuri orientate;
21)	meniu() – Afișarea pe ecran a meniului cu opțiunile pe care utilizatorul le poate alege.
