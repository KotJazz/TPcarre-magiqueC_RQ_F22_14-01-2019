#include <stdio.h>
#include <stdlib.h>
#include "typesetconst.h"
#include "valeur.h"
#include "logique.h"
#include "vue.h"

//CARRE MAGIQUE
/*
BUT : Simuler le carré magique de Pascal
ENTREE : Variable jeton, Sphère, compteur
SORTIE : Tableau "sphère" rempli
*/
int main()
{
    //VAR
    tJeton Jeton={2,3};
    int cpt=2;
    int Sphere[BOUNDARY][BOUNDARY];
    //
    init(Sphere);
    do
    {
        avancer(&Jeton,Sphere,cpt);
        cpt++;
        affichage(Sphere);
    }while(cpt<=((BOUNDARY-2)*(BOUNDARY-2)));
    return 0;
}
//INIT
/*
BUT : Initialiser la matrice
ENTREE : Matrice
SORTIE : Matrice initialisée
*/
void init(int Sphere[BOUNDARY][BOUNDARY])
{
    //VAR
    int nI=0, nJ=0; //CPT
    //
    for(nI=0;nI<BOUNDARY;nI++){ //lignes
        for(nJ=0;nJ<BOUNDARY;nJ++){ //colonnes
            Sphere[nI][nJ]=0;
        }
    }
    Sphere[2][3]=1;
}
//NORD
/*
BUT : Monter le jeton d'une ligne et déterminer si on va déplacer le jeton à gauche ou à droite
ENTREE : Variable jeton
SORTIE : Variable jeton modifiée
*/
void avancer(tJeton *Jeton, int Sphere[BOUNDARY][BOUNDARY],int cpt)
{
    Jeton->nX-=1;
    avancerdroite(Jeton);
    /*if(estellevide(Jeton,Sphere)==false)
    {
        avancergauche(Jeton);
    }*/
    corriger(Jeton);
    while(estellevide(Jeton,Sphere)==false)
    {
        Jeton->nX-=1;
        avancergauche(Jeton);
        corriger(Jeton);
    }
    placer(Jeton,Sphere,cpt);
}
//PLACER
/*
BUT : Placer la valeur du compteur dans la case ciblée
ENTREE : Variable jeton, Sphère, compteur
SORTIE : Sphère modifiée
*/
void placer(tJeton *Jeton, int Sphere[BOUNDARY][BOUNDARY], int cpt)
{
    Sphere[Jeton->nX][Jeton->nY]=cpt;
}


//AVANCER DROITE
/*
BUT : Déplacer le jeton à droite
ENTREE : Jeton
SORTIE : Jeton modifié
*/
void avancerdroite(tJeton *Jeton)
{
    Jeton->nY+=1;
}
//AVANCER GAUCHE
/*
BUT : Déplacer le jeton à gauche
ENTREE : Jeton
SORTIE : Jeton modifié
*/
void avancergauche(tJeton *Jeton)
{
    Jeton->nY-=1;
}
