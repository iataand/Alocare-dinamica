// Din fisierul date.in se citeste un numar natural k si apoi de pe a doua linie numere intregi. Contruiti o lista liniara simplu inlantuita care sa contina numerele intregi citite in ordinea din fisier.
// Permutati lista cu k pozitii spre stanga si afisati valorile din lista.
// Indicatie: se vor scrie si folosi functii pentru adaugarea unei valori la sfarsitul listei si pentru stergerea primului nod al listei si vor fi folosite pentru permuarea ceruta.
// Exemplu:
// date.in
// 3
// 1 2 3 4
// date.out
// 4 1 2 3

#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("text.txt");

struct nod
{
  int inf;
  nod *adr;
} * p, *sf;

void adaugaNod(int x)
{
  nod *q = new nod;

  if (p != 0)
  {
    q->inf = x;
    q->adr = 0;
    sf->adr = q;
    sf = q;
  }
  else
  {
    q->inf = x;
    p = q;
    sf = q;
  }
}

void adaugaSf()
{
  nod *q = new nod;

  sf->adr = q;
  q->inf = p->inf;
  q->adr = 0;
  sf = q;
}

void stergeP()
{
  nod *temp = new nod;

  temp = p;
  p = p->adr;
  delete temp;
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
  int k, x;
  fin >> k;

  while (fin >> x)
  {
    adaugaNod(x);
  }

  while (k)
  {
    adaugaSf();
    stergeP();

    k--;
  }

  scrie();

  return 0;
}
