#include <stdio.h>
#include <stdlib.h>
#include "typesetconst.h"
#include "logique.h"

//EST ELLE VIDE
/*
BUT : D�terminer si la case vis�e est vide
ENTREE : Jeton et Sph�re
SORTIE : BOOLEEN vrai ou faux
*/
Bool estellevide(tJeton *Jeton, int Sphere[BOUNDARY][BOUNDARY])
{
    if(Sphere[Jeton->nX][Jeton->nY]==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//CORRIGER
/*
BUT : D�placer le jeton de l'autre c�t� du carr� s'il en d�passe, simuler la "courbure" de la sph�re.
ENTREE : Variable jeton, Sph�re
SORTIE : Jeton modifi�
*/
void corriger(tJeton *Jeton)
{
    if(Jeton->nX<1)
    {
        Jeton->nX+=5;
    }
    if(Jeton->nY<1)
    {
        Jeton->nY+=5;
    }
    if(Jeton->nX>5)
    {
        Jeton->nX-=5;
    }
    if(Jeton->nY>5)
    {
        Jeton->nY-=5;
    }
}
