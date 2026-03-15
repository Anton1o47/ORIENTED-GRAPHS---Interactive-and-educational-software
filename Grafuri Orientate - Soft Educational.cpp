/*
                         GRAFURI ORIENTATE - SOFT EDUCATIONAL
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include <string>

using namespace std;
int a[101][101], b[101][101], a2[101][101], k, n, i, j, m, x, y;
/*
    "n" REPREZINTA NUMARUL DE NODURI
    "m" REPREZINTA NUMARUL DE ARCE
    "a" ESTE MATRICEA DE ADIACENTA
    "b" ESTE MATRICEA VARFURI-ARCE
*/
void citire_tastatura()
{
    system("cls");
    x = -1; y = -1;
    cout << endl << endl << endl << endl << endl << "Introduceti numarul de noduri pe care doriti ca graful orientat sa il aiba";
    cout << " (retineti ca acestea vor fi numerotate de la 1): ";
    cin >> n;
    cout << endl << endl << "Introduceti arcele grafului dumneavoastra (maxim " << n * (n - 1) << "), cu un spatiu intre noduri. " << endl;
    cout << "Nodurile NU trebuie sa fie mai mici decat 1, sau mai mari decat " << n << " (1<=x<=" << n << " & 1<=y<=" << n << "),";
    cout << " si NU trebuie sa fie egale." << endl;
    cout << "Vor fi inregistrate doar arcele care respecta cerintele de mai sus." << endl;
    cout << "Introduceti doar caractere NUMERICE, altfel programul se va bloca si va trebui restartat." << endl;
    cout << "Dupa ce ati scris muchiile dorite, introduceti '0 0' si apasati ENTER." << endl << endl;
    for (i = 1; i <= (n * (n - 1)) && (x != 0 && y != 0); i++) {
        cin >> x >> y;
        if (x >= 1 && x <= n && y >= 1 && y <= n && x != y && a[x][y] == 0) a[x][y] = 1;
        else {
            if (x != 0 || y != 0) {
                cout << "Acest arc nu este valid!" << endl;
                i--;
                x = -1; y = -1;
            }
        }
    }
    cout << endl << "Graful a fost inregistrat cu succes.";
}
void spatiu()
{
    cout << endl << endl;
}
void nr_arce()
{
    cout << "Fiind dat arcul U=(x,y), se numesc extremitati ale sale nodurile x si y: " << endl;
    cout << " ->x se numeste extremitate initiala;" << endl;
    cout << " ->y se numeste extremitate finala." << endl;
    cout << " Numarul maxim de arce ale unui graf orientat cu n noduri este egal cu n*(n-1)." << endl;
    cout << endl;
    cout << "************************************************************************" << endl;
    m = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (a[i][j] == 1)
                m++;
    if (m == 0) cout << endl << "Graful introdus contine " << n << " noduri si niciun arc.";
    else if (m == 1) {
        cout << endl << "Graful introdus contine " << n << " noduri si un singur arc, acesta fiind ";
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (a[i][j] == 1)
                    cout << "(" << i << "," << j << ")";
        cout << ".";
    }
    else {
        cout << endl << "Graful introdus contine " << n << " noduri si " << m << " arce." << endl;
        cout << "Arcele grafului introdus sunt: " << endl;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (a[i][j] == 1)
                    cout << "(" << i << "," << j << ")" << endl;
    }
}
void afisare_matrice_adiacenta()
{
    cout << "Fie G=(V,U) un graf orientat cu n varfuri (V={ 1,2, ..., n}) si m arce." << endl;
    cout << "Matricea de adiacenta, asociata grafului G, este o matrice patratica de ordin n, cu elementele {0,1}." << endl;
    cout << "(a[i][j]=1, daca exista arc intre i si j si a[i][j]=0 daca nu exista arc intre i si j) " << endl;
    cout << endl;
    cout << "************************************************************************" << endl;
    cout << "PROPRIETATI: " << endl;
    cout << "->elementele de pe diagonala principala sunt 0;" << endl;
    cout << "->gradul exterior al unui varf x este egal cu numarul de elemente 1 de pe linia x;" << endl;
    cout << "->gradul interior al unui varf x este egal cu numarul de elemente 1 de pe coloana x;" << endl;
    cout << "->suma tuturor elementelor din matrice este egala cu numarul de arce din graf." << endl << endl;
    cout << "************************************************************************" << endl;
    cout << endl;
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            if (a[i][j] == 1) cout << "(" << i << "," << j << ")" << endl;
    }
    if (n == 0) cout << "Graful introdus nu are noduri!";
    else {
        cout << endl << "Pentru graful cu " << n << " noduri de mai sus, matricea de adiacenta este urmatoarea: " << endl << endl;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++)
                if (j == 1) cout << "  " << a[i][j] << " ";
                else cout << " " << a[i][j] << " ";
            cout << endl;
        }
    }
}

int gr_ext(int i)
{
    int j, s;
    s = 0;
    for (j = 1; j <= n; j++) s = s + a[i][j];
    return s;
}
int gr_int(int i)
{
    int j, s;
    s = 0;
    for (j = 1; j <= n; j++) s = s + a[j][i];
    return s;
}
void afisare_grade()
{
    cout << "Fie G=(V, U) un graf orientat si x un nod al sau. " << endl;
    cout << "Se numeste grad exterior al nodului x, numarul arcelor de forma (x,y) (numarul arcelor care ies din x), notat d+(x)." << endl;
    cout << "Se numeste grad interior al nodului x, numarul arcelor de forma (y,x) (numarul arcelor care intra in x), notat d-(x)." << endl;
    cout << "Se numeste gradul unui nod suma dintre gradul exterior si gradul interior al nodului." << endl;
    cout << endl;
    cout << "************************************************************************" << endl;
    cout << endl;
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            if (a[i][j] == 1) cout << "(" << i << "," << j << ")" << endl;
    }
    if (n == 0) cout << "Graful introdus nu are noduri!";
    else {
        cout << endl << "Pentru graful cu " << n << " noduri de mai sus, gradele nodurilor sunt urmatoarele: " << endl << endl;
        for (i = 1; i <= n; i++) {
            cout << "d(" << i << ") = d+(" << i << ") + d-(" << i << ") = ";
            cout << gr_ext(i) << " + " << gr_int(i) << " = " << gr_ext(i) + gr_int(i) << endl;
        }
    }
}
void afisare_matrice_varfuri_arce()
{
    cout << "Fie G=(V, U) un graf orientat cu n varfuri (V={1,2, ..., n}) si m arce. " << endl;
    cout << "Matricea varfuri-arce, asociata grafului G, este o matrice cu n linii si m coloane, cu elementele {-1,0,1}. " << endl;
    cout << "->b[i][j]= 1, daca i este extremitate initiala pentru arcul ij;" << endl;
    cout << "->b[i][j]= 0, daca intre nodurile i si j nu exista niciun arc;" << endl;
    cout << "->b[i][j]= -1, daca i este extremitate finala pentru arcul ij;" << endl;
    cout << endl;
    cout << "************************************************************************" << endl;
    cout << endl;
    int m = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (a[i][j] == 1) {
                m++;
                cout << "(" << i << "," << j << ")" << endl;
            }
    if (n == 0) cout << "Graful introdus nu are noduri, prin urmare nu are nici matrice varfuri-arce!";
    else if (m == 0) cout << "Graful introdus nu are niciun arc, prin urmare nu are nici matrice varfuri-arce!" << endl;
    else {
        for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) b[i][j] = 0;
        k = 0;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (a[i][j] == 1) {
                    k++;
                    b[i][k] = 1;
                    b[j][k] = -1;
                }
        cout << endl << "Pentru graful cu " << n << " noduri de mai sus, matricea varfuri-arce este urmatoarea: " << endl;
        cout << endl;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= k; j++)
                cout << setw(3) << b[i][j];
            cout << endl;
        }
    }
}
void afisare_noduri_izolate()
{
    cout << "Un nod se numeste izolat daca nu este legat de niciun alt nod din graf: d+(x) = d-(x) = 0." << endl;
    cout << endl;
    cout << "************************************************************************" << endl;
    cout << endl;
    int i, j, nr = 0;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            if (a[i][j] == 1) cout << "(" << i << "," << j << ")" << endl;
    }
    if (n == 0) cout << "Graful introdus nu are noduri!";
    else {
        cout << endl << "Pentru graful cu " << n << " noduri de mai sus, nodurile izolate sunt: ";
        for (i = 1; i <= n; i++)
            if ((gr_ext(i) + gr_int(i)) == 0) {
                cout << i << " ";
                nr++;
            }
        if (nr == 0) cout << "NU EXISTA NODURI IZOLATE!";
    }
}
void afisare_noduri_terminale()
{
    cout << "Un nod se numeste terminal daca este legat de un singur nod din graf: d+(x) + d-(x) = 1." << endl;
    cout << endl;
    cout << "************************************************************************" << endl;
    cout << endl;
    int i, j, nr = 0;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            if (a[i][j] == 1) cout << "(" << i << "," << j << ")" << endl;
    }
    if (n == 0) cout << "Graful introdus nu are noduri!";
    else {
        cout << endl << "Pentru graful cu " << n << " noduri de mai sus, nodurile terminale sunt: ";
        for (i = 1; i <= n; i++)
            if ((gr_ext(i) + gr_int(i)) == 1) {
                cout << i << " ";
                nr++;
            }
        if (nr == 0) cout << "NU EXISTA NODURI TERMINALE!";
    }
}
void afisare_noduri_maximale()
{
    cout << "Un nod se numeste maximal daca este legat cu cate doua muchii, de toate celelalte noduri din graf: d+(x) + d-(x)= 2*(n-1), cu n fiind numarul de noduri." << endl;
    cout << endl;
    cout << "************************************************************************" << endl;
    cout << endl;
    int i, j, nr = 0;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            if (a[i][j] == 1) cout << "(" << i << "," << j << ")" << endl;
    }
    if (n == 0) cout << "Graful introdus nu are noduri!";
    else {
        cout << endl << "Pentru graful cu " << n << " noduri de mai sus, nodurile maximale sunt: ";
        for (i = 1; i <= n; i++)
            if ((gr_ext(i) + gr_int(i)) == 2 * (n - 1)) {
                cout << i << " ";
                nr++;
            }
        if (nr == 0) cout << "NU EXISTA NODURI MAXIMALE!";
    }
}
void numar_grafuri()
{
    cout << "Numarul total de grafuri orientate cu n noduri este 4^[n*(n-1)/2]." << endl;
    cout << endl;
    cout << "************************************************************************" << endl << endl;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            if (a[i][j] == 1) cout << "(" << i << "," << j << ")" << endl;
    }
    long long p = 1;
    for (int i = 1; i <= (n * (n - 1) / 2); i++)
        p = p * 4;
    cout << endl << "Numarul total de grafuri cu " << n << " noduri este: " << p;
    if (n > 8) cout << endl << endl << endl << "Nota: Pentru grafurile care au mai mult de 8 noduri, programul nu poate calcula valoarea adevarata, aceasta fiind prea mare.";
}
void adiacenta()
{
    cout << "Daca intr-un graf exista arcul u=(x,y) (sau u=(y,x), sau amandoua), se spune despre nodurile x si y ca sunt adiacente ." << endl;
    cout << "Intr-un graf orientat, doua noduri pot avea maxim doua arce intre ele." << endl;
    cout << endl;
    cout << "************************************************************************" << endl;
    cout << endl;
    int x, y, i, j, nad = 0, m = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (a[i][j] == 1) {
                cout << "(" << i << "," << j << ")" << endl;
                m++;
            }
            else if (a[i][j] == 0 && a[j][i] == 0 && i != j) nad++;
    if (n == 0) cout << "Graful introdus nu are noduri!";
    else if (nad == 0) cout << endl << "Toate nodurile din graful citit sunt adiacente intre ele.";
    else if (m == 0) cout << "Graful introdus nu are arce, prin urmare nu exista noduri adiacente intre ele.";
    else {
        cout << endl << "Introduceti doua noduri, de la 1 la " << n << " : ";
        cin >> x >> y;
        cout << endl << endl;
        if (x == y || (x<1 || x>n) || (y<1 || y>n))
            do {
                if (x == y)
                    if ((x<1 || x>n)) cout << "Nodul " << x << " nu se afla in graful citit." << endl;
                    else cout << "Nodurile introduse sunt egale." << endl;
                else if ((x<1 || x>n) && (y<1 || y>n)) cout << "Nodurile " << x << " si " << y << " nu se afla in graful citit." << endl;
                else if (x<1 || x>n) cout << "Nodul " << x << " nu se afla in graful citit." << endl;
                else if (y<1 || y>n) cout << "Nodul " << y << " nu se afla in graful citit." << endl;
                cout << endl << "Introduceti doua noduri de la 1 la " << n << ": ";
                cin >> x >> y;
                cout << endl << endl;
            } while (x<1 || x>n || y<1 || y>n || x == y);
        if (a[x][y] == 1 || a[y][x] == 1) cout << "Nodurile " << x << " si " << y << " sunt adiacente.";
        else cout << "Nodurile " << x << " si " << y << " nu sunt adiacente.";
    }
}
void graf_turneu()
{
    cout << "Un graf este turneu, daca intre oricare 2 varfuri i si j, exista un singur arc:(i,j) sau (j,i)." << endl;
    cout << "Numarul de grafuri turneu cu n noduri este 2^[n*(n-1)/2]. " << endl;
    cout << "In orice graf turneu exista un drum elementar care trece prin toate varfurile grafului." << endl;
    cout << endl;
    cout << "************************************************************************" << endl;
    cout << endl;
    int i, j, m = 0, ok = 1, k1 = 0, k2 = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            a2[i][j] = a[i][j];
    if (n == 0) cout << "Graful introdus nu are noduri!";
    else {
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (a[i][j] == 1) {
                    cout << "(" << i << "," << j << ")" << endl;
                    m++;
                }
        if (m == n * (n - 1)) {
            cout << endl << "Graful introdus nu este turneu!" << endl << "Pentru ca acesta sa devina turneu, trebuie eliminate urmatoarele muchii: " << endl;
            for (i = 1; i <= n; i++)
                for (j = 1; j <= n; j++)
                    if (a2[i][j] == a2[j][i] && i != j) {
                        cout << "(" << i << "," << j << ") " << endl;
                        a2[j][i] = 0;
                    }
        }
        else if (m == 0) {
            cout << endl << "Graful introdus nu este turneu!" << endl << "Pentru ca acesta sa devina turneu, trebuie adaugate urmatoarele muchii: " << endl;
            for (i = 1; i <= n; i++)
                for (j = 1; j <= n; j++)
                    if (a2[i][j] == a2[j][i] && i != j) {
                        cout << "(" << i << "," << j << ") " << endl;
                        a2[j][i] = 1;
                    }
        }
        else {
            for (i = 1; i <= n; i++)
                for (j = 1; j <= n; j++)
                    if (a[i][j] == 1 && a[j][i] == 1 && i != j) { ok = 0; k1++; }
                    else if (a[i][j] == 0 && a[j][i] == 0 && i != j) { ok = 0; k2++; }


            if (ok == 1) cout << endl << endl << "Graful introdus este turneu!";


            else {
                if (k1 == 0 && k2 > 0) {
                    cout << endl << "Graful introdus nu este turneu!" << endl << "Pentru ca acesta sa devina turneu, trebuie adaugate urmatoarele muchii: " << endl;
                    for (i = 1; i <= n; i++)
                        for (j = 1; j <= n; j++) if (a2[i][j] == a2[j][i] && i != j) {
                            cout << "(" << i << "," << j << ") " << endl;
                            a2[i][j] = 1;
                        }
                }
                else if (k1 > 1 && k2 == 0) {
                    cout << endl << "Graful introdus nu este turneu!" << endl << "Pentru ca acesta sa devina turneu, trebuie eliminate urmatoarele muchii: " << endl;
                    for (i = 1; i <= n; i++)
                        for (j = 1; j <= n; j++) if (a2[i][j] == a2[j][i] && i != j) {
                            cout << "(" << j << "," << i << ") " << endl;
                            a2[j][i] = 0;
                        }
                }
                else if (k1 > 1 && k2 > 0) {
                    cout << endl << "Graful introdus nu este turneu!" << endl << "Pentru ca acesta sa devina turneu, trebuie adaugate urmatoarele muchii: " << endl;
                    for (i = 1; i <= n; i++)
                        for (j = 1; j <= n; j++) if (a2[i][j] == 0 && a2[j][i] == 0 && i != j) {
                            cout << "(" << i << "," << j << ") " << endl;
                            a2[i][j] = 1;
                        }

                    cout << endl << "De asemenea, trebuie eliminate urmatoarele muchii: " << endl;
                    for (i = 1; i <= n; i++)
                        for (j = 1; j <= n; j++) if (a2[i][j] == 1 && a2[j][i] == 1 && i != j) {
                            cout << "(" << j << "," << i << ") " << endl;
                            a2[j][i] = 0;
                        }
                }
            }
        }
    }
}
void nrgraf_complet()
{
    cout << "Fie G=(V, U) un graf orientat. Graful G se numeste graf complet daca oricare doua varfuri distincte ale sale sunt adiacente." << endl;
    cout << "Doua varfuri x si y sunt adiacente daca intre acestea exista cel putin un arc. " << endl;
    cout << "Numarul total de grafuri orientate complete cu n noduri este 3^[n*(n-1)/2]. " << endl;
    cout << endl;
    cout << "************************************************************************" << endl;
    cout << endl;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            if (a[i][j] == 1) cout << "(" << i << "," << j << ")" << endl;
    }
    long long p = 1;
    for (int i = 1; i <= (n * (n - 1) / 2); i++)
        p = p * 3;
    cout << endl << "Numarul total de grafuri orientate complete cu " << n << " noduri este: " << p;
    if (n > 10) cout << endl << endl << endl << "Nota: Pentru grafurile care au mai mult de 10 noduri, programul nu poate calcula valoarea adevarata, aceasta fiind prea mare.";
}
void muchiimin_lipsa_complet()
{
    cout << "Numarul minim de muchii dintr-un graf complet este n*(n-1)/2." << endl;
    cout << endl;
    cout << "************************************************************************" << endl;
    cout << endl;
    int i, j, nad = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (a[i][j] == 1)
                cout << "(" << i << "," << j << ")" << endl;
            else if (a[i][j] == 0 && a[j][i] == 0 && i != j) nad++;
    int nr_min = nad / 2;
    if (n == 0) cout << "Graful introdus nu are noduri!";
    else if (nad == 0) cout << endl << "Graful introdus este deja complet!" << endl;
    else cout << endl << "Numarul minim de muchii care trebuie adaugate pentru ca graful introdus sa devina complet este " << nr_min << "." << endl;
}
void muchiimax_lipsa_complet()
{
    cout << "Numarul maxim de muchii dintr-un graf complet este n*(n-1)." << endl;
    cout << endl;
    cout << "************************************************************************" << endl;
    cout << endl;
    int i, j, ml = 0, nad = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (a[i][j] == 1)
                cout << "(" << i << "," << j << ")" << endl;
            else {
                if (a[j][i] == 0 && i != j) nad++;
                else if (a[j][i] == 1 && i != j) ml++;
            }
    int nr_max = nad + ml;
    if (n == 0) cout << "Graful introdus nu are noduri!";
    else {
        if (nad == 0) {
            if (ml == 0)
                cout << endl << "Graful introdus este deja complet, si are numarul maxim de muchii.";
            else if (ml == 1) {
                cout << endl << "Graful introdus este deja complet, insa ii mai poate fi adaugata o singura muchie, aceasta fiind ";
                for (i = 1; i <= n; i++)
                    for (j = 1; j <= n; j++)
                        if (a[i][j] == 0 && i != j) cout << "(" << i << "," << j << ")." << endl;
            }
            else {
                cout << endl << "Graful introdus este deja complet, insa ii mai pot fi adaugate inca " << ml << " muchii, acestea fiind:" << endl;
                for (i = 1; i <= n; i++)
                    for (j = 1; j <= n; j++)
                        if (a[i][j] == 0 && i != j) cout << "(" << i << "," << j << ")" << endl;
            }
        }
        else {
            cout << endl << "Numarul maxim de muchii care trebuie adaugate pentru ca graful introdus sa devina complet este " << nr_max << ", acestea fiind:" << endl;
            for (i = 1; i <= n; i++)
                for (j = 1; j <= n; j++)
                    if (a[i][j] == 0 && i != j) cout << "(" << i << "," << j << ")" << endl;
        }
    }
}
void succesori()
{
    cout << "Fie G=(V, U) un graf orientat, cu n varfuri (V={ 1,2, ..., n}) si m arce. " << endl;
    cout << "Reprezentarea grafului G, prin liste de adiacenta, consta in: " << endl;
    cout << "- precizarea numarului de varfuri, notat cu n; " << endl;
    cout << "- pentru fiecare varf i, se precizeaza lista succesorilor sai." << endl;
    cout << "                                           _                               _" << endl;
    cout << "Multimea succesorilor lui x se noteaza cu | +(x) si se reprezinta astfel: | +(x) = {y e V(x, y) e U } ." << endl;
    cout << endl;
    cout << "************************************************************************" << endl;
    cout << endl;
    int i, j, k;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            if (a[i][j] == 1) cout << "(" << i << "," << j << ")" << endl;
    }
    if (n == 0) cout << "Graful introdus nu are noduri!";
    else {
        cout << endl << "Pentru graful cu " << n << " noduri de mai sus, lista succesorilor (sau lista de adiacenta) este urmatoarea:" << endl << endl;
        cout << endl << " Varf | Vecini / succesori " << endl;
        for (i = 1; i <= 26; i++)
            cout << "-";
        cout << endl;
        for (i = 1; i <= n; i++)
        {
            cout << "  " << i << "   |   ";
            k = 0;
            for (j = 1; j <= n; j++)
                if (a[i][j] == 1) {
                    cout << j << ", ";
                    k++;
                }
            if (k == 0)
                cout << "-";
            else
                cout << '\b' << '\b' << " ";
            cout << endl;
        }
    }
}
void predecesori()
{
    cout << "                                             _                               _" << endl;
    cout << "Multimea predecesorilor lui x se noteaza cu | -(x) si se reprezinta astfel: | -(x) = {y e V(y, x) e U } ." << endl;
    cout << endl;
    cout << "************************************************************************" << endl;
    cout << endl;
    int i, j, k;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            if (a[i][j] == 1) cout << "(" << i << "," << j << ")" << endl;
    }
    if (n == 0) cout << "Graful introdus nu are noduri!";
    else {
        cout << endl << "Pentru graful cu " << n << " noduri de mai sus, lista predecesorilor este urmatoarea:" << endl << endl;
        cout << endl << " Varf | Predecesori " << endl;
        for (i = 1; i <= 19; i++)
            cout << "-";
        cout << endl;
        for (j = 1; j <= n; j++)
        {
            cout << "  " << j << "   |   ";
            k = 0;
            for (i = 1; i <= n; i++)
                if (a[i][j] == 1) {
                    cout << i << ", ";
                    k++;
                }
            if (k == 0)
                cout << "-";
            else
                cout << '\b' << '\b' << " ";
            cout << endl;
        }
    }
}
void test()
{
    int k = 0; char s[1000];
    cout << "************************************************************************" << endl << endl;
    cout << "Introduceti raspunsul pentru fiecare intrebare folosind doar caractere NUMERICE, altfel programul il va considera incorect!" << endl << endl;
    cout << "1. Cate grafuri orientate cu 3 noduri se pot forma?" << endl << "R: ";
    cin >> s;
    if (strcmp(s, "64") == 0) { k++; cout << "Corect!" << endl; }
    else cout << "Incorect! Raspunsul este 64." << endl << "Numarul total de grafuri orientate cu n noduri se calculeaza cu formula 4^[n*(n-1)/2]." << endl;

    cout << endl << "2. Care este gradul unui nod terminal?" << endl << "R: ";
    cin >> s;
    if (strcmp(s, "1") == 0) { k++; cout << "Corect!" << endl; }
    else cout << "Incorect! Raspunsul este 1." << endl << "Nodul terminal este nodul in care intra un singur arc." << endl;

    cout << endl << "3. Suma tuturor elementelor din matricea de adiacenta a unui graf orientat cu 7 arce este egala cu?" << endl << "R: ";
    cin >> s;
    if (strcmp(s, "7") == 0) { k++; cout << "Corect!" << endl; }
    else cout << "Incorect! Raspunsul este 7." << endl << "In matricea de adiacenta a unui graf orientat, suma elementelor matricei = numarul arcelor." << endl;

    cout << endl << "4. Numarul maxim de muchii dintr-un graf orientat cu 5 noduri este?" << endl << "R: ";
    cin >> s;
    if (strcmp(s, "20") == 0) { k++; cout << "Corect!" << endl; }
    else cout << "Incorect! Raspunsul este 20." << endl << "Numarul maxim de arce ale unui graf orientat cu n noduri este egal cu n*(n-1)." << endl;

    cout << endl << "5. Care este gradul unui nod maximal, intr-un graf orientat cu 129 noduri?" << endl << "R: ";
    cin >> s;
    if (strcmp(s, "256") == 0) { k++; cout << "Corect!" << endl; }
    else cout << "Incorect! Raspunsul este 256." << endl << "Intr-un graf orientat cu n noduri, gradul unui nod maximal este egal cu 2*(n-1)." << endl;

    cout << endl << "6. Cate elemente are matricea de adiacenta a unui graf orientat cu 6 noduri?" << endl << "R: ";
    cin >> s;
    if (strcmp(s, "36") == 0) { k++; cout << "Corect!" << endl; }
    else cout << "Incorect! Raspunsul este 36." << endl << "Matricea de adiacenta a unui graf orientat este patratica, iar numarul liniilor/coloanelor = numarul de arce al grafului." << endl << "Prin urmare, numarul de elemente din matrice = (numarul liniilor/coloanelor)^2 = (numarul de arce al grafului)^2." << endl;

    cout << endl << "7. Care este numarul maxim de succesori/predecesori pe care il poate avea un nod intr-un graf orientat cu 10 noduri?" << endl << "R: ";
    cin >> s;
    if (strcmp(s, "9") == 0) { k++; cout << "Corect!" << endl; }
    else cout << "Incorect! Raspunsul este 9." << endl << "Intr-un graf orientat cu n noduri, un nod poate avea maxim n-1 succesori/predecesori." << endl;

    cout << endl << "8. Cate grafuri orientate complete cu 3 noduri se pot forma?" << endl << "R: ";
    cin >> s;
    if (strcmp(s, "27") == 0) { k++; cout << "Corect!" << endl; }
    else cout << "Incorect! Raspunsul este 27." << endl << "Numarul total de grafuri orientate complete cu n noduri este 3^[n*(n-1)/2]." << endl;

    cout << endl << "9. Cate grafuri turneu cu 3 noduri se pot forma?" << endl << "R: ";
    cin >> s;
    if (strcmp(s, "8") == 0) { k++; cout << "Corect!" << endl; }
    else cout << "Incorect! Raspunsul este 8." << endl << "Numarul total de grafuri turneu cu n noduri este 2^[n*(n-1)/2]." << endl;

    if (k == 9) cout << endl << "  Felicitari, ai raspuns corect la toate intrebarile!";
    else if (k >= 5) cout << endl << "   Te-ai descurcat bine!";
    else cout << endl << "   Mai studiaza!";

}
void final()
{
    cout << endl << endl;
    cout << "************************************************************************" << endl;
    cout << endl << "Apasati tasta ENTER intoarcerea in meniul principal!" << endl;
}
void meniu()
{
    cout << "                                            _______________________________________________________________________________________________________________________" << endl;
    cout << "                                           |                                                                                                                       |" << endl;
    cout << "                                           |                                                                                                                       |" << endl;
    cout << "                                           |                                                                                                                       |" << endl;
    cout << "                                           |                                                                                                                       |";
    cout << endl << "                                           |                                    GRAFURI ORIENTATE - PREZENTARE GENERALA                                            |" << endl;
    cout << "                                           |                                                                                                                       |" << endl;
    cout << "                                           |                                                                                                                       |" << endl;
    cout << "                                           |                                                                                                                       |" << endl;
    cout << "                                           |                  Se numeste graf orientat o pereche ordonata de multimi notata G=(V, U), unde:                        |" << endl;
    cout << "                                           |                     -> V: este o multime, finita si nevida, ale carei elemente se numesc noduri sau varfuri;          |" << endl;
    cout << "                                           |                     -> U: este o multime, de perechi ordonate de elemente distincte din V, care se numesc arce.       |" << endl;
    cout << "                                           |                                                                                                                       |" << endl;
    cout << "                                           |                                                                                                                       |" << endl;
    cout << "                                           |                  Aplicatiile disponibile:                                                                             |" << endl;
    cout << "                                           |                                                                                                                       |" << endl;
    cout << "                                           |                                                                                                                       |" << endl;
    cout << "                                           |                     1. Citirea grafului.                                                                              |" << endl;
    cout << "                                           |                                                                                                                       |" << endl;
    cout << "                                           |                     2. Numarul de arce si arcele grafului.                                                            |" << endl;
    cout << "                                           |                                                                                                                       |" << endl;
    cout << "                                           |                     3. Matricea de adiacenta.                                                                         |" << endl;
    cout << "                                           |                                                                                                                       |" << endl;
    cout << "                                           |                     4. Matricea varfuri-arce.                                                                         |" << endl;
    cout << "                                           |                                                                                                                       |" << endl;
    cout << "                                           |                     5. Lista succesorilor / Lista de adiacenta.                                                       |" << endl;
    cout << "                                           |                                                                                                                       |" << endl;
    cout << "                                           |                     6. Lista predecesorilor.                                                                          |" << endl;
    cout << "                                           |                                                                                                                       |" << endl;
    cout << "                                           |                     7. Gradul fiecarui nod.                                                                           |" << endl;
    cout << "                                           |                                                                                                                       |" << endl;
    cout << "                                           |                     8. Afisarea nodurilor izolate.                                                                    |" << endl;
    cout << "                                           |                                                                                                                       |" << endl;
    cout << "                                           |                     9. Afisarea nodurilor terminale.                                                                  |" << endl;
    cout << "                                           |                                                                                                                       |" << endl;
    cout << "                                           |                     10. Afisarea nodurilor maximale.                                                                  |" << endl;
    cout << "                                           |                                                                                                                       |" << endl;
    cout << "                                           |                     11. Numarul de grafuri cu " << n << " noduri.                                                               |" << endl;
    cout << "                                           |                                                                                                                       |" << endl;
    cout << "                                           |                     12. Adiacenta dintre doua noduri.                                                                 |" << endl;
    cout << "                                           |                                                                                                                       |" << endl;
    cout << "                                           |                     13. Graful introdus este turneu?                                                                  |" << endl;
    cout << "                                           |                                                                                                                       |" << endl;
    cout << "                                           |                     14. Numarul grafurilor complete cu " << n << " noduri.                                                      |" << endl;
    cout << "                                           |                                                                                                                       |" << endl;
    cout << "                                           |                     15. Numarul minim de muchii care pot fi adaugate pentru ca graful introdus sa fie complet.        |" << endl;
    cout << "                                           |                                                                                                                       |" << endl;
    cout << "                                           |                     16. Numarul maxim de muchii care pot fi adaugate pentru ca graful introdus sa fie complet.        |" << endl;
    cout << "                                           |                                                                                                                       |" << endl;
    cout << "                                           |                     17. Test.                                                                                         |" << endl;
    cout << "                                           |                                                                                                                       |" << endl;
    cout << "                                           |                     18. Iesire din proiect.                                                                           |" << endl;
    cout << "                                           |                                                                                                                       |" << endl;
    cout << "                                           |                                                                                                                       |";
    cout << endl << "                                           |_______________________________________________________________________________________________________________________|" << endl;
    cout << endl;
}
int main()
{
    system("color F0");
    int op, citire, reint, k = 0, aplicatii[15] = { 0 }, ap_par = 0;
    do {
        meniu();
        cout << endl << "                                                                                          Alegeti o optiune (1-18): ";
        cin >> op;
        switch (op)
        {
        case 1:
            system("cls");
            if (k == 0) {
                citire_tastatura(); k = 1; final(); ap_par++; break;
            }
            else {
                cout << endl << endl << endl << endl << endl << "Ati citit deja un graf. ";
                cout << "Doriti sa introduceti altul?" << endl << endl;
                cout << "1 - Graf nou" << endl << "2 - Intoarcere in meniul principal" << endl << endl;
                cin >> reint;
                while (reint != 1 && reint != 2) cin >> reint;
                if (reint == 1) {
                    for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) a[i][j] = 0;
                    for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) b[i][j] = 0;
                    citire_tastatura(); final(); break;
                }
                else break;

            }

        case 2:
            system("cls");
            if (k == 0) {
                cout << endl << endl << endl << endl << endl << "************************************************************************" << endl;
                cout << endl << "Pentru a realiza aceasta operatiune, mai intai trebuie sa cititi graful.";
                final(); break;
            }
            else { spatiu(); nr_arce(); final(); ap_par++; break; }

        case 3:
            system("cls");
            if (k == 0) {
                cout << endl << endl << endl << endl << endl << "************************************************************************" << endl;
                cout << endl << "Pentru a realiza aceasta operatiune, mai intai trebuie sa cititi graful.";                final(); break;
            }
            else { spatiu(); afisare_matrice_adiacenta(); final(); ap_par++; break; }

        case 4:
            system("cls");
            if (k == 0) {
                cout << endl << endl << endl << endl << endl << "************************************************************************" << endl;
                cout << endl << "Pentru a realiza aceasta operatiune, mai intai trebuie sa cititi graful.";
                final(); break;
            }
            else { spatiu(); afisare_matrice_varfuri_arce(); final(); ap_par++; break; }

        case 5:
            system("cls");
            if (k == 0) {
                cout << endl << endl << endl << endl << endl << "************************************************************************" << endl;
                cout << endl << "Pentru a realiza aceasta operatiune, mai intai trebuie sa cititi graful.";
                final(); break;
            }
            else { spatiu(); succesori(); final(); ap_par++; break; }

        case 6:
            system("cls");
            if (k == 0) {
                cout << endl << endl << endl << endl << endl << "************************************************************************" << endl;
                cout << endl << "Pentru a realiza aceasta operatiune, mai intai trebuie sa cititi graful.";
                final(); break;
            }
            else { spatiu(); predecesori(); final(); ap_par++; break; }

        case 7:
            system("cls");
            if (k == 0) {
                cout << endl << endl << endl << endl << endl << "************************************************************************" << endl;
                cout << endl << "Pentru a realiza aceasta operatiune, mai intai trebuie sa cititi graful.";
                final(); break;
            }
            else { spatiu(); afisare_grade(); final(); ap_par++; break; }

        case 8:
            system("cls");
            if (k == 0) {
                cout << endl << endl << endl << endl << endl << "************************************************************************" << endl;
                cout << endl << "Pentru a realiza aceasta operatiune, mai intai trebuie sa cititi graful.";
                final(); break;
            }
            else { spatiu(); afisare_noduri_izolate(); final(); ap_par++; break; }

        case 9:
            system("cls");
            if (k == 0) {
                cout << endl << endl << endl << endl << endl << "************************************************************************" << endl;
                cout << endl << "Pentru a realiza aceasta operatiune, mai intai trebuie sa cititi graful.";
                final(); break;
            }
            else { spatiu(); afisare_noduri_terminale(); final(); ap_par++; break; }

        case 10:
            system("cls");
            if (k == 0) {
                cout << endl << endl << endl << endl << endl << "************************************************************************" << endl;
                cout << endl << "Pentru a realiza aceasta operatiune, mai intai trebuie sa cititi graful.";
                final(); break;
            }
            else { spatiu(); afisare_noduri_maximale(); final(); ap_par++; break; }

        case 11:
            system("cls");
            if (k == 0) {
                cout << endl << endl << endl << endl << endl << "************************************************************************" << endl;
                cout << endl << "Pentru a realiza aceasta operatiune, mai intai trebuie sa cititi graful.";
                final(); break;
            }
            else { spatiu(); numar_grafuri(); final(); ap_par++; break; }

        case 12:
            system("cls");
            if (k == 0) {
                cout << endl << endl << endl << endl << endl << "************************************************************************" << endl;
                cout << endl << "Pentru a realiza aceasta operatiune, mai intai trebuie sa cititi graful.";
                final(); break;
            }
            else { spatiu(); adiacenta(); final(); ap_par++; break; }

        case 13:
            system("cls");
            if (k == 0) {
                cout << endl << endl << endl << endl << endl << "************************************************************************" << endl;
                cout << endl << "Pentru a realiza aceasta operatiune, mai intai trebuie sa cititi graful.";
                final(); break;
            }
            else { spatiu(); graf_turneu(); final(); ap_par++; break; }

        case 14:
            system("cls");
            if (k == 0) {
                cout << endl << endl << endl << endl << endl << "************************************************************************" << endl;
                cout << endl << "Pentru a realiza aceasta operatiune, mai intai trebuie sa cititi graful.";
                final(); break;
            }
            else { spatiu(); nrgraf_complet(); final(); ap_par++; break; }

        case 15:
            system("cls");
            if (k == 0) {
                cout << endl << endl << endl << endl << endl << "************************************************************************" << endl;
                cout << endl << "Pentru a realiza aceasta operatiune, mai intai trebuie sa cititi graful.";
                final(); break;
            }
            else { spatiu(); muchiimin_lipsa_complet(); final(); ap_par++; break; }

        case 16:
            system("cls");
            if (k == 0) {
                cout << endl << endl << endl << endl << endl << "************************************************************************" << endl;
                cout << endl << "Pentru a realiza aceasta operatiune, mai intai trebuie sa cititi graful.";
                final(); break;
            }
            else { spatiu(); muchiimax_lipsa_complet(); final(); ap_par++; break; }

        case 17:
            system("cls");

            if (ap_par < 16) {
                cout << endl << endl << endl << endl << "************************************************************************" << endl;
                cout << endl << "Pentru a accesa testul, trebuie sa parcurgeti toate cele 16 aplicatii ale programului." << endl << endl << "Aplicatii parcurse: " << ap_par << "." << endl;
                final(); break;
            }
            else { spatiu(); test(); final(); break; }
        case 18: break;
        }

        if (op != 18) _getch();// asteapta apasarea unei taste
        system("cls");// curata ecranul
    } while (op >= 1 && op <= 17);

    return 0;
}
