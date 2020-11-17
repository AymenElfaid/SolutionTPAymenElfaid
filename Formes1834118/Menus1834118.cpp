#include "Menus1834118.h"
#include <iostream>
#include <string>
using namespace std;

int validerMenu(int numMenu, int nbOptions)
{
	//on utilise une switch afin d'évaluer quel menu va être appelé à partir du choix de l'utilisateur
	int choix;
	switch (numMenu)
	{
	case 1:
		afficherMenu1();
		choix = saisirEntier(); //On fait appel à la fonction saisir entier vue en classe qui ne plante pas le programme en cas de donnés éronnés
		//Si le choix fait est éronné, on affiche un message d'erreur et on demande à l'utilisateur de réessayer
		while (!(choix >= 1 && choix <= nbOptions))
		{
			cout << "Erreur! Veuillez entrer une option entre 1 et " << nbOptions<< ": ";
			choix = saisirEntier();
		}
		break;
	case 2:
		afficherMenu2();
		choix = saisirEntier();//On fait appel à la fonction saisir entier vue en classe qui ne plante pas le programme en cas de donnés éronnés
		//Si le choix fait est éronné, on affiche un message d'erreur et on demande à l'utilisateur de réessayer
		while (!(choix >= 1 && choix <= nbOptions))
		{
			cout << "Erreur! Veuillez entrer une option entre 1 et " << nbOptions << ": ";
			choix = saisirEntier();
		}
		break;
	}
	//On retourne la variable choix après sa validation
	return choix;
}

int afficherMenu1()
{
	//On vide l'écran avec un cls 
	system("cls");
	//On affiche le menu 1 avec des cout
	cout << "Choisissez la forme" << endl;
	cout << "1 - Rectangle" << endl;
	cout << "2 - Triangle" << endl;
	cout << "3 - Carré" << endl;
	cout << "4 - Losange" << endl;
	cout << "5 - Quitter" << endl;
	cout << "Votre choix: ";
	return 0;
}

int afficherMenu2()
{
	//On vide l'écran avec un cls 
	system("cls");
	//On affiche le menu 1 avec des cout
	cout << "Choisissez le remplissage" << endl;
	cout << "1 - Plein" << endl;
	cout << "2 - Vide" << endl;
	cout << "3 - Retour au menu principal" << endl;
	cout << "Votre choix: ";

	return 0;
}


//Code accrédité à Karine Moreau 
//(Fonction vue en cours)
int saisirEntier()
{
	string clavier;

	getline(cin, clavier, '\n');            // Permet de stocker les caractères dans la variable clavier 
											// et de nettoyer la mémoire du clavier
	// Autre problème : stoi plante le programme si la chaine de caractères ne contient pas des chiffres
	// comme premiers caractères ou si elle est vide

	// Tant que 1. clavier est vide (clavier.empty() ou clavier == "") OU
	//          2. clavier ne commence pas (at(0), front(), [0]) par un chiffre (valeur positive) OU  commence  par le signe - et n'est pas suivi d'un chiffre




	/*while (!(!clavier.empty() && ((clavier.front() >= '0' && clavier.front() <= '9')
			|| (clavier.length() > 1 && clavier.front() == '-' && clavier.at(1) >= '0' && clavier.at(1) <= '9'))))*/


	while ((clavier.empty() || ((clavier.front() < '0' || clavier.front() > '9')
		&& (clavier.length() <= 1 || clavier.front() != '-' || clavier.at(1) < '0' || clavier.at(1) > '9'))))


	{
		cout << "Erreur : vous devez entrer un entier." << endl;
		cout << "Veuillez entrer un nombre entier : ";
		getline(cin, clavier, '\n');            // Permet de stocker les caractères dans la variable clavier 
	}


	// Il faut maintenant convertir la chaine en entier
	return stoi(clavier);

	// Ici, si l'utilisateur tape une lettre, le cin >> la refuse et surtout laisse le caractère dans la mémoire du clavier
	// Il met 0 dans la variable int, même si ce n'est pas la bonne valeur
	// Et donc le programme part en boucle infinie car le deuxième cin >> récupère les caractères laissés 
	// dans la mémoire du clavier
	// Solution ==> lire tous les caractères tapés au clavier avec une chaine de caractères : string avec getline


}

//Code accrédité à Karine Moreau 
//(Fonction vue en cours)
int genererNombreAleatoire(int min, int max)
{
	return rand() % (max - min + 1) + (min);
}
