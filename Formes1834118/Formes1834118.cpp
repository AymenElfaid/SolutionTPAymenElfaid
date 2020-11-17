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


	//On d�cide � l'aide d'un switch quel char on passera en param�tre a partir du choix de l'utilisateur
	switch (remplissage)
	{
	case 1:
		rempl = '#';
		break;
	case 2:
		rempl = ' ';
		break;
	}

	//On demande � l'utilisateur les dimension de la forme
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

	//On d�cide � l'aide d'un switch quel char on passera en param�tre a partir du choix de l'utilisateur
	switch (remplissage)
	{
	case 1:
		rempl = '#';
		break;
	case 2:
		rempl = ' ';
		break;
	}

	//On demande � l'utilisateur la dimension de la forme
	cout << "Indiquez la hauteur : ";
	longueur = saisirEntier();
	//on fait appel � la fonction dessinerRectangle avec la m�me variable pour la hauteur et la largeur car un carr� est fondamentalement un rectangle avec deux c�t�s �gaux
	dessinerRectangle(longueur, longueur, rempl);
}

void traiterTriangle(int remplissage)
{
	int longueur;
	//On g�n�re un nombre al�atoire entre 0 et 3 afin de d�cider quel triangle va �tre dessin�
	int forme = genererNombreAleatoire(0, 3);
	int rempl;

	//On d�cide � l'aide d'un switch quel char on passera en param�tre a partir du choix de l'utilisateur
	switch (remplissage)
	{
	case 1:
		rempl = '#';
		break;
	case 2:
		rempl = ' ';
		break;
	}
	//On demande � l'utilisateur la dimension de la forme
	cout << "Indiquez la hauteur : ";
	longueur = saisirEntier();

	//On utilise la variable forme (qui porte un valeur al�atoire entre 0 et 3) dans une switch afin d'appeler la fonction appropri� pour chaque triangle
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

	//On d�cide � l'aide d'un switch quel char on passera en param�tre a partir du choix de l'utilisateur
	switch (remplissage)
	{
	case 1:
		rempl = '#';
		break;
	case 2:
		rempl = ' ';
		break;
	}

	//On demande � l'utilisateur la dimension de la forme
	cout << "Indiquez la hauteur : ";
	longueur = saisirEntier();
	while (longueur%2==0)
	{
		cout << "Erreur! La longueur du losange doit �tre impaire!" <<endl;
		cout << "R�essayez: ";
		longueur = saisirEntier();
	}
	dessinerLosange(longueur, rempl);
}




//Dessin des formes
void dessinerRectangle(int longueur, int largeur, char remplissage)
{
	if (longueur == largeur)
		cout << "Voici votre carr� de: " << longueur << " x " << largeur<< endl;
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


//La fonction pour dessiner le losange n'est pas parfaite Car j'ai eu beaucoup de mis�re � la mettre en code
//J'ai eu recours � un exemple sur internet pour la faire
void dessinerLosange(int longueur, char remplissage)
{
	cout << "Voici votre losange de " << longueur << " de hauteur" << endl;
	//premi�re moiti�
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
	//deuxi�me moiti�
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
//La fonction pour dessiner deux des quatres triangles n'est pas parfaite (les formes qui sont vides du c�t� gauche) 
//j'ai eu beaucoup de mis�re � la coder m�me en regardant des exemples sur internet :(
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

//La fonction pour dessiner deux des quatres triangles n'est pas parfaite (les formes qui sont vides du c�t� gauche) 
//j'ai eu beaucoup de mis�re � la coder m�me en regardant des exemples sur internet :(
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
