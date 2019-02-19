// Se considera o lista liniara simplu inlantuita care memoreaza valori intregi. Sa se scrie o functie care primeste
// ca parametru adresa primului nod al listei si insereaza in fata fiecarui nod care memoreaza o valoare negativa un
// nod care sa memoreze opusul acesteia.
#include <iostream>
using namespace std;

struct nod
{
    int inf;
    nod *adr;
} * p, *sf;

void adauga(int x)
{
    nod *q = new nod;
    q->inf = x;
    q->adr = 0;

    if (p != 0)
    {
        sf->adr = q;
        sf = q;
    }
    else
    {
        p = q;
        sf = q;
    }
}

void rezolva(nod *prim)
{
    nod *q = prim;
    nod *x;

    for (q = p; q->adr != 0; q = q->adr)
    {
        if (q->inf < 0)
        {
            x = new nod;
            x->inf = q->inf * (-1);
            x->adr = q->adr;
            q->adr = x;
        }
    }
}

void scrie()
{
    nod *q = new nod;

    for (q = p; q != 0; q = q->adr)
    {
        cout << q->inf << " ";
    }
    cout << endl;
}

int main()
{

    adauga(1);
    adauga(-2);
    adauga(3);
    adauga(-4);
    adauga(15);
    adauga(6);
    adauga(-19);
    adauga(100);

    rezolva(p);
    scrie();

    return 0;
}