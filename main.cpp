#include <iostream>
using namespace std;

struct nod
{
  int inf;
  nod *adr;
} * p, *sf;

void adaug(int x)
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

void sterge(int x)
{
  nod *r = new nod;
  nod *temp = new nod;

  if (x == p->inf) //Daca x este primul nod
  {
    temp = p;
    p = p->adr;
    delete temp;
  }

  else if (x == sf->inf) //Daca x este ultimul nod
  {
    for (r = p; r->adr != sf; r = r->adr) //r se pune pe penultimul element
    {
    }

    r->adr = 0;
    delete sf;
    sf = r;
  }
  else
  {
    for (r = p; r->adr->inf != x; r = r->adr) //Caut elementul cu informatia egala cu x
    {
    }

    temp = r->adr;
    r->adr = temp->adr;
    delete temp;
  }
}

void adaugaDupa(int x, int y)
{
  nod *r = new nod;
  nod *q = new nod;

  for (q = p; q->inf != x; q = q->adr)
  {
  }

  r->inf = y;
  r->adr = q->adr;
  q->adr = r;
}

void adaugaInainte(int x, int y)
{
  nod *r = new nod;
  nod *q = new nod;

  for (q = p; q->adr->inf != x; q = q->adr)
  {
  }

  r->inf = y;
  r->adr = q->adr;
  q->adr = r;
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
  adaug(3);
  adaug(7);
  adaug(9);
  adaug(10);
  adaug(1099);

  adaugaDupa(7, 8);
  scrie();

  adaugaDupa(8, 11);
  scrie();

  return 0;
}