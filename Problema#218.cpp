// Sa se creeze o lista liniara simplu inlantuita care contine elemente numere reale citite dintr-ul fisier text.
// Sa se insereze intre oricare 2 noduri din lista un nod care sa contina media celor 2 valori din cele 2 noduri..

#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("text.txt");

struct nod
{
    int inf;
    nod *adr;
} * p, *sf;

void adauga(int x)
{
    nod *r = new nod; //Definesc un nod

    r->inf = x;
    r->adr = 0;

    if (p != 0) //Lista nevida
    {
        sf->adr = r;
        sf = r;
    }
    else
    {
        p = r;
        sf = r;
    }
}

void medie(int x, int y)
{
    nod *q = new nod;
    nod *i = new nod;

    for (q = p; q->inf != x || q->adr->inf != y; q = q->adr)
    {
    }

    i->inf = (q->inf + q->adr->inf) / 2;

    i->adr = q->adr;
    q->adr = i;
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
    int x;
    while (fin >> x)
        adauga(x);

    scrie();

    medie(5, 4);

    scrie();

    fin.close();
    return 0;
}