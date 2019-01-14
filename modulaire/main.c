#include <stdio.h>
#include <stdlib.h>
#include "typesetconst.h"
#include "valeur.h"
#include "logique.h"
#include "vue.h"

//CARRE MAGIQUE
/*
BUT : Simuler le carr� magique de Pascal
ENTREE : Variable jeton, Sph�re, compteur
SORTIE : Tableau "sph�re" rempli
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
SORTIE : Matrice initialis�e
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
BUT : Monter le jeton d'une ligne et d�terminer si on va d�placer le jeton � gauche ou � droite
ENTREE : Variable jeton
SORTIE : Variable jeton modifi�e
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
BUT : Placer la valeur du compteur dans la case cibl�e
ENTREE : Variable jeton, Sph�re, compteur
SORTIE : Sph�re modifi�e
*/
void placer(tJeton *Jeton, int Sphere[BOUNDARY][BOUNDARY], int cpt)
{
    Sphere[Jeton->nX][Jeton->nY]=cpt;
}


//AVANCER DROITE
/*
BUT : D�placer le jeton � droite
ENTREE : Jeton
SORTIE : Jeton modifi�
*/
void avancerdroite(tJeton *Jeton)
{
    Jeton->nY+=1;
}
//AVANCER GAUCHE
/*
BUT : D�placer le jeton � gauche
ENTREE : Jeton
SORTIE : Jeton modifi�
*/
void avancergauche(tJeton *Jeton)
{
    Jeton->nY-=1;
}
