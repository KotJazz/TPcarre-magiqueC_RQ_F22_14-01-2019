#include <stdio.h>
#include <stdlib.h>
#define BOUNDARY 7 //Taille du tableau
typedef struct tJeton //"Curseur" qui se déplacera en fonction des règles du carré magique
{
    int nX;
    int nY;
}tJeton;
typedef enum {true=1,false=0}Bool; //Booléen
//PROTOTYPES
void init(int Sphere[BOUNDARY][BOUNDARY]);
void avancer(tJeton *, int Sphere[BOUNDARY][BOUNDARY],int);
void avancerdroite(tJeton *);
void avancergauche(tJeton *);
void affichage(int Sphere[BOUNDARY][BOUNDARY]);
Bool estellevide(tJeton *Jeton,int Sphere[BOUNDARY][BOUNDARY]);
void corriger(tJeton *);
void placer(tJeton *, int Sphere[BOUNDARY][BOUNDARY], int);
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
