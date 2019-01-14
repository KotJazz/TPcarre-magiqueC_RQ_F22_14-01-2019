#include <stdio.h>
#include <stdlib.h>
#define BOUNDARY 7 //Taille du tableau
typedef struct tJeton //"Curseur" qui se d�placera en fonction des r�gles du carr� magique
{
    int nX;
    int nY;
}tJeton;
typedef enum {true=1,false=0}Bool; //Bool�en
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
//AFFICHAGE
/*
BUT : Afficher la "sph�re" (= carr�)
ENTREE : Sph�re
SORTIE : Sph�re affich�e
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
