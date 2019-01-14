#include <stdio.h>
#include <stdlib.h>
#include "typesetconst.h"
#include "vue.h"

//AFFICHAGE
/*
BUT : Afficher la "sphère" (= carré)
ENTREE : Sphère
SORTIE : Sphère affichée
*/
void affichage(int Sphere[BOUNDARY][BOUNDARY])
{
    //VAR
    int nI=0, nJ=0; //CPT
    //
    for(nI=1;nI<BOUNDARY-1;nI++){ //lignes
        for(nJ=1;nJ<BOUNDARY-1;nJ++){ //colonnes
            printf("[%d]",Sphere[nI][nJ]);
        }
        printf("\n");
    }
    printf("\n");
}
