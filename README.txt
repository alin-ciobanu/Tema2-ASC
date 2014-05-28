TEMA 2 - Arhitectura Sistemelor de Calcul
Implementarea operatiei dtrmv

Student: Ciobanu Alin Emanuel
Grupa: 332 CC

Cuprins
------------------------------------------
1. Enunt
2. Utilizare
3. Implementare si compilare
4. Explicatii plot-uri


1. Enunt
------------------------------------------
Se cere implementarea operatie dtrmv, care inmulteste o matrice triunghiulara cu un vector.


2. Utilizare
------------------------------------------
sh run.sh --> se pun job-urile pe coada
asteptare terminare job-uri --> fisierele din folderul out
sh draw.sh --> deseneaza graficul (se afiseaza eroare daca job-urile nu au terminat)

Alternativ:
make submit-jobs
asteptare terminare job-uri
make draw-plot (se afiseaza eroare daca job-urile nu au terminat)
make view-plot

Explicatii:

Arhiva contine cate un makefile pentru fiecare arhitectura folosita.
Exista cate un script pentru fiecare din implementarile temei (de mana, atlas si optimizat) pentru fiecare arhitectura -> in total 9 scripturi.
Arhiva contine script-ul run.sh care poate fi rulat pentru a porni job-urile pe toate masinile.
Cand job-urile s-au terminat, se poate folosi script-ul draw.sh pentru a genera graficul graph.png.

Alternativ, se poate folosi makefile-ul Makefile pentru a trimite job-urile pe cozile celor 3 arhitecturi si a desena graficul.
make submit-jobs trimite job-urile pe cozi si le executa
make draw-plot deseneaza graficul (daca job-urile nu au fost terminate, se genereaza un mesaj de eroare, iar graph.png nu va fi construit)
make view-plot deschide imaginea png care contine graficul folosit eog (eye of gnome)


3. Implementare si compilare
------------------------------------------
Pentru a implementa de mana functia dtrmv, am transpus din Fortran in C codul care rezolva problema.
Pentru a compila functia optimizata am folosit flag-ul -O5.


4. Explicatii plot-uri
------------------------------------------
Am rulat tema pentru dimensiunea matricei de 30000. 
Se observa ca timpii de rulare sunt foarte ridicati pentru implementarea de mana fata de timpii functiei atlas (aproximativ de 14 ori mai ridicati).
Se observa ca folosirea flag-ului -O5 pentru compilare optimizata imbunatateste timpii de rulare cu aproximativ 50-60%.

De asemenea, se observa diferente de timpi intre arhitecturi.
Nehalem este cea mai rapida arhitectura (aproximativ de 1.5 ori mai rapida decat celelalte doua).

Observatie: Timpii de rulare difera in functie de cat de incarcata este masina pe care se ruleaza si de valoarea elementelor matricei si a vectorului.
