// Codul de mai jos poate genera erori. Care sunt acestea s, i din ce motiv pot apărea?
// Propunet, i o solut, ie care păstrează funct, ionalitatea s, i evită erorile.

int dim = 3;

int * p =( int *)malloc( dim * sizeof ( int ));
int * pi = &p[1];

p = (int *)realloc(p , 2* dim * sizeof ( int ));

//Problema este ca atunci cand se face realloc, adresa la care pointeaza pi nu mai este valida.
//deoarece memoria a fost realocata si adresa la care pointeaza pi nu mai este in zona de memorie alocata.

asa ca ar trebui initalizat din nou pi dupa realloc.

pi = &p[1]; //dupa realloc