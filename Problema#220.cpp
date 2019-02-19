// Se citesc numere intregi dintr-un fisier text. Sa se creeze 2 liste care sa contina in ordine elementele din fisier, una elementele pare, iar cealalta pe cele impare.
// Sa se adauge la sfarsitul listei cu elemente pare lista cu elemente impare.

#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("text.txt");

struct nod
{
    int inf;
    nod *adr;
} * primPar, *sfPar, *primImp, *sfImp;

void adaugaPar(int x)
{
    nod *q = new nod;
    q->inf = x;
    q->adr = 0;

    if (primPar != 0)
    {
        sfPar->adr = q;
        sfPar = q;
    }
    else
    {
        primPar = q;
        sfPar = q;
    }
}

void adaugaImpar(int x)
{
    nod *q = new nod;
    q->inf = x;
    q->adr = 0;

    if (primImp != 0)
    {
        sfImp->adr = q;
        sfImp = q;
    }
    else
    {
        primImp = q;
        sfImp = q;
    }
}

void scrie()
{
    nod *q = new nod;

    for (q = primPar; q->adr != 0; q = q->adr)
    {
        cout << q->inf << " ";
    }
}

main()
{
    int x;

    while (fin >> x)
    {
        if (x % 2 == 0)
            adaugaPar(x);
        else
            adaugaImpar(x);
    }

    sfPar->adr = primImp;

    scrie();

    return 0;
}
