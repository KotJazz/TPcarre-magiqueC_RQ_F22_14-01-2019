#include <stdio.h>
#include <stdlib.h>
#include "typesetconst.h"
#include "logique.h"

//EST ELLE VIDE
/*
BUT : Déterminer si la case visée est vide
ENTREE : Jeton et Sphère
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
BUT : Déplacer le jeton de l'autre côté du carré s'il en dépasse, simuler la "courbure" de la sphère.
ENTREE : Variable jeton, Sphère
SORTIE : Jeton modifié
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
