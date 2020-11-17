#include "Formes1834118.h"
#include "Menus1834118.h"
#include <iostream>

using namespace std;


//Traitemenr des formes
void traiterRectangle(int remplissage)
{
	char rempl;
	int longueur;
	int largeur;


	//On décide à l'aide d'un switch quel char on passera en paramètre a partir du choix de l'utilisateur
	switch (remplissage)
	{
	case 1:
		rempl = '#';
		break;
	case 2:
		rempl = ' ';
		break;
	}

	//On demande à l'utilisateur les dimension de la forme
	cout << "Indiquez la hauteur : ";
	longueur = saisirEntier();
	cout << "Indiquez la largeur : ";
	largeur = saisirEntier();
	dessinerRectangle(longueur, largeur, rempl);
}
void traiterCarre(int remplissage)
{
	char rempl;
	int longueur;

	//On décide à l'aide d'un switch quel char on passera en paramètre a partir du choix de l'utilisateur
	switch (remplissage)
	{
	case 1:
		rempl = '#';
		break;
	case 2:
		rempl = ' ';
		break;
	}

	//On demande à l'utilisateur la dimension de la forme
	cout << "Indiquez la hauteur : ";
	longueur = saisirEntier();
	//on fait appel à la fonction dessinerRectangle avec la même variable pour la hauteur et la largeur car un carré est fondamentalement un rectangle avec deux côtés égaux
	dessinerRectangle(longueur, longueur, rempl);
}

void traiterTriangle(int remplissage)
{
	int longueur;
	//On génère un nombre aléatoire entre 0 et 3 afin de décider quel triangle va être dessiné
	int forme = genererNombreAleatoire(0, 3);
	int rempl;

	//On décide à l'aide d'un switch quel char on passera en paramètre a partir du choix de l'utilisateur
	switch (remplissage)
	{
	case 1:
		rempl = '#';
		break;
	case 2:
		rempl = ' ';
		break;
	}
	//On demande à l'utilisateur la dimension de la forme
	cout << "Indiquez la hauteur : ";
	longueur = saisirEntier();

	//On utilise la variable forme (qui porte un valeur aléatoire entre 0 et 3) dans une switch afin d'appeler la fonction approprié pour chaque triangle
	switch (forme)
	{
	case 0:
		dessinerTriangle1(longueur, rempl);
		break;
	case 1:
		dessinerTriangle2(longueur, rempl);
		break;
	case 2:
		dessinerTriangle3(longueur, rempl);
		break;
	case 3:
		dessinerTriangle4(longueur, rempl);
		break;

	}

}

void traiterLosange(int remplissage)
{
	char rempl;
	int longueur;

	//On décide à l'aide d'un switch quel char on passera en paramètre a partir du choix de l'utilisateur
	switch (remplissage)
	{
	case 1:
		rempl = '#';
		break;
	case 2:
		rempl = ' ';
		break;
	}

	//On demande à l'utilisateur la dimension de la forme
	cout << "Indiquez la hauteur : ";
	longueur = saisirEntier();
	while (longueur%2==0)
	{
		cout << "Erreur! La longueur du losange doit être impaire!" <<endl;
		cout << "Réessayez: ";
		longueur = saisirEntier();
	}
	dessinerLosange(longueur, rempl);
}




//Dessin des formes
void dessinerRectangle(int longueur, int largeur, char remplissage)
{
	if (longueur == largeur)
		cout << "Voici votre carré de: " << longueur << " x " << largeur<< endl;
	else
	cout << "Voici votre rectangle de: " << longueur << " x " << largeur << endl;
	for (int i = 0; i < largeur; i++)
		cout << "*";
	cout << endl;
	for (int i = 0; i < longueur-2; i++)
	{
		cout << '*';
		for (int i = 0; i < largeur-2; i++)
		{
			cout << remplissage;
		}
		cout << '*';
		cout << endl;
	}
	for (int i = 0; i < largeur; i++)
		cout << "*";
	cout << endl;
	system("pause");
}


//La fonction pour dessiner le losange n'est pas parfaite Car j'ai eu beaucoup de misère à la mettre en code
//J'ai eu recours à un exemple sur internet pour la faire
void dessinerLosange(int longueur, char remplissage)
{
	cout << "Voici votre losange de " << longueur << " de hauteur" << endl;
	//première moitié
	for (int i = 1; i <= longueur/2; i++) {
		for (int j = longueur/2; j > i; j--) {
			cout << " ";
		}
		cout << "*";
		for (int j = 1; j < (i - 1) * 2; j++) {
			cout << remplissage;
		}
		if (i == 1) {
			cout << endl;
		}
		else {
			cout << "*"<< endl;
		}
	}
	//deuxième moitié
	for (int i = longueur/2; i >= 1; i--) {
		for (int j = longueur/2; j > i; j--) {
			cout << " ";
		}
		cout << "*";
		for (int j = 1; j < (i - 1) * 2; j++) {
			cout << remplissage;
		}
		if (i == 1) {
			cout << endl;
		}
		else {
			cout << "*"<<endl;
		}
	}
system("pause");
}

void dessinerTriangle1(int longueur, char remplissage)
{
	cout << "voici votre triangle, hauteur de " << longueur <<endl;
	cout << "*" << endl;
	for (int i = 0; i < longueur-2; i++)
	{
		cout << "*";
		for (int j = 0; j < i; j++)
		{
			cout << remplissage;
		}
		cout << "*" << endl;
	}
	for (int i = 0; i < longueur; i++)
	{
		cout << "*" ;
	}
	cout << endl;
	system("pause");
}

void dessinerTriangle2(int longueur, char remplissage)
{
	cout << "voici votre triangle, hauteur de " << longueur << endl;
	for (int i = 0; i < longueur; i++)
	{
		cout << "*";
	}
	cout << endl;
	for (int i = 0; i < longueur-2; i++)
	{
		cout << "*";
		for (int j = longueur-2; j >i; j--)
		{
			cout << remplissage;
		}
	cout << "*"<<endl;
	}
	cout << "*"<<endl;
		system("pause");
	
		
}
//La fonction pour dessiner deux des quatres triangles n'est pas parfaite (les formes qui sont vides du côté gauche) 
//j'ai eu beaucoup de misère à la coder même en regardant des exemples sur internet :(
void dessinerTriangle3(int longueur, char remplissage)
{
	cout << "voici votre triangle, hauteur de " << longueur << endl;
	for (int i = 0; i < longueur; i++)
	{
		cout << "* ";
	}
	cout << endl;
	for (int i = longueur-2; i > 0; i--)
	{
		for (int j = 0; j < (longueur-2)-i; j++)
		{
			cout << "  ";
		}
		cout << "* ";
		for (int k = 0; k < i; k++)
		{
			cout << remplissage << " ";
		}
		cout << "*" << endl;
		
	}
	system("pause");
}

//La fonction pour dessiner deux des quatres triangles n'est pas parfaite (les formes qui sont vides du côté gauche) 
//j'ai eu beaucoup de misère à la coder même en regardant des exemples sur internet :(
void dessinerTriangle4(int longueur, char remplissage)
{
	cout << "voici votre triangle, hauteur de " << longueur << endl;
	for (int i = (longueur - 2); i > 0; i--)
	{
		cout << "  ";
	}
	cout << "*"<<endl;


	for (int i = 1; i <= longueur-2; i++)
	{
		for (int j = (longueur-2) - i; j > 0; j--)
		{
			cout << "  "; 
		}
		cout << "*";
		for (int k = 1; k <= i; k++)
		{
			cout << (remplissage) << " ";
		}
		cout << "*";

		cout << endl;
	}
	for (int i = 0; i < longueur; i++)
	{
		cout << "* ";
	}
	system("pause");
}
