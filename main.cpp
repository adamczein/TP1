/*
* Programme TD1 du cours INF1015
* \file main.cpp
* \auteurs Salma Zaghloul et Adam El Zein
* \date 14 mai 2023
* \Cr�� le 10 mai 2023
*/

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits.h>

using namespace std;

// Fonction qui v�rifie si un nombre entier est premier ou non
bool estPremier(int nombreEntier)
{
	// On parcourt tous les entiers de 2 � la racine carr�e du nombre
	for (int i = 2; i <= sqrt(nombreEntier); i++)
	{
		// Si le nombre est divisible par un entier, il n'est pas premier
		if (nombreEntier % i == 0)
		{
			return false;
		}
	}
	// Si aucun entier ne divise le nombre, il est premier
	return true;
}

// Fonction qui demande � l'utilisateur d'entrer des nombres entiers jusqu'� ce qu'il entre -1
void q1()
{
	while (true)
	{
		int nombreEntier;
		cout << "Entrez un nombre entier : ";
		cin >> nombreEntier;
		if (nombreEntier == -1)
		{
			break;
		}

		// On incr�mente le nombre tant qu'il n'est pas premier
		while (!estPremier(nombreEntier))
		{
			nombreEntier++;
		}

		cout << "Le prochain nombre premier est " << nombreEntier <<"."<< endl;;

	}
}

// Cette fonction permet de lire un entier dans un intervalle donn�
// et renvoie l'entier lu.
int lireEntierDansIntervalle(string texte, int valeurMinimale, int valeurMaximale)
{
	double entree;

	// On demande � l'utilisateur d'entrer un entier
	// tant que l'entier n'est pas dans l'intervalle souhait�.
	do
	{
		cout << texte;
		cin >> entree;

	} while (entree > valeurMaximale || entree < valeurMinimale);

	return round(entree);

	/*Le warning C4244 signifie que le compilateur a d�tect� une possible perte de donn�es lors de la conversion
	d'un type de donn�es en une autre. Cependant dans notre cas, le return round(entree) permet de prendre en compte la partie
	fractionnaire et d'arrondir � l'entier le plus proche, tel qu'il est demand� dans la partie de l'�nonc� qui stipule :
	L�entr�e de l�entier de l�utilisateur sera par cette fonction, o� le r�el r�sultant sera converti en entier.
	Ainsi, le warning C4244 n'est pas un probl�me dans ce cas et peut �tre ignor�. */
	
}

// Cette fonction permet de jouer au jeu de deviner un nombre
// choisi al�atoirement entre 0 et 1000.
void q2()
{
	int nombreEntier;
	int nombreAleatoire = rand() % 1001;  // On choisit un nombre al�atoire
	int nombreTentatives = 0;  // On initialise le nombre de tentatives � 0
	static const int valeurMinimale = 0;
	static const int valeurMaximale = 1000;


	// On continue � demander � l'utilisateur d'entrer un nombre
	// jusqu'� ce qu'il trouve le bon nombre.
	while (true)
	{
		nombreEntier = lireEntierDansIntervalle("Entrez un nombre entier : ", valeurMinimale, valeurMaximale);

		// Si le nombre entr� est plus petit que le nombre � trouver
		if (nombreEntier < nombreAleatoire)
		{
			cout << "Trop bas." << endl;
			nombreTentatives++;

		}

		// Si le nombre entr� est plus grand que le nombre � trouver
		if (nombreEntier > nombreAleatoire)
		{
			cout << "Trop haut." << endl;
			nombreTentatives++;

		}

		// Si le nombre entr� est �gal au nombre � trouver, on a gagn�.
		if (nombreEntier == nombreAleatoire)
		{
			cout << "Bravo! Vous avez reussi en " << nombreTentatives + 1 << " tentative(s)!" << endl;
			return;

		}
	}
}
// Cette fonction d�termine si deux trains en mouvement entrent en collision � un moment donn�
// tempsTotal: le temps �coul� depuis le d�but du mouvement des trains
// positionInitialeTrain1, positionInitialeTrain2: positions initiales des trains
// vitesseTrain1, vitesseTrain2: vitesses des trains (positives ou n�gatives)
bool estEnCollision(int tempsTotal, int positionInitialeTrain1,
	int positionInitialeTrain2, int vitesseTrain1,
	int vitesseTrain2)
{
	if (vitesseTrain1 < 0 && vitesseTrain2 >= 0) {
		if (positionInitialeTrain1 + (vitesseTrain1 * tempsTotal) < positionInitialeTrain2 + (vitesseTrain2 * tempsTotal)) {
			return true;
		}
		return false;
	}

	else if (vitesseTrain2 < 0 && vitesseTrain1 >=0)
	{
		if (positionInitialeTrain1 + (vitesseTrain1 * tempsTotal) > positionInitialeTrain2 + (vitesseTrain2 * tempsTotal)) {
			return true;
		}
		return false;
	}

	else if (vitesseTrain2 < 0 && vitesseTrain1 < 0)
	{
		if (vitesseTrain1 < vitesseTrain2)
			if (positionInitialeTrain1 > positionInitialeTrain2)
				if (positionInitialeTrain1 + (vitesseTrain1 * tempsTotal) < positionInitialeTrain2 + (vitesseTrain2 * tempsTotal)) {
					return true;
				}
		if (vitesseTrain2 < vitesseTrain1)
			if (positionInitialeTrain2 > positionInitialeTrain1)
				if (positionInitialeTrain2 + (vitesseTrain2 * tempsTotal) < positionInitialeTrain1 + (vitesseTrain1 * tempsTotal)) {
					return true;
				}
		if (positionInitialeTrain2 + (vitesseTrain2 * tempsTotal) < positionInitialeTrain1 + (vitesseTrain1 * tempsTotal)) {
			return true;
		}
		return false;
	}
	
	else if (abs(vitesseTrain1) > abs(vitesseTrain2))
	{
		if (abs(positionInitialeTrain1) < abs(positionInitialeTrain2))
			if (abs(positionInitialeTrain1 + abs(vitesseTrain1 * tempsTotal)) > abs(positionInitialeTrain2 + abs(vitesseTrain2 * tempsTotal)))
			{
				return true;
			}
		return false;
	}

	else if (abs(vitesseTrain2) > abs(vitesseTrain1))
	{
		if (abs(positionInitialeTrain2) < abs(positionInitialeTrain1))
			if (abs(positionInitialeTrain2 + abs(vitesseTrain2 * tempsTotal)) > abs(positionInitialeTrain1 + abs(vitesseTrain1 * tempsTotal)))
			{
				return true;
			}
		return false;
	}

	else if (positionInitialeTrain1 == positionInitialeTrain2)
		return true;

	else if (positionInitialeTrain2 + (vitesseTrain2 * tempsTotal) == positionInitialeTrain1 + (vitesseTrain1 * tempsTotal))
		return true;

	else {
		return false;
	}
}

// Cette fonction calcule la position d'un train � un temps donn�
int positionTrain(int positionInitiale, int vitesse, int temps)
{
	int position;

	position = positionInitiale + (vitesse * temps);

	return position;
}

// Cette fonction permet � l'utilisateur d'entrer les informations sur les deux trains
// et de d�terminer s'ils entrent en collision pendant le temps total donn�.
void q3()
{
	// D�claration des variables pour le temps total, les positions initiales et les vitesses des deux trains
	int tempsTotal;
	int positionInitialeTrain1;
	int positionInitialeTrain2;
	int vitesseTrain1;
	int vitesseTrain2;

	// Lecture des entr�es utilisateur
	tempsTotal = lireEntierDansIntervalle("Entrez le temps total :", 0, INT_MAX);

	positionInitialeTrain1 = lireEntierDansIntervalle("Entrez la position intiale du premier train :", INT_MIN, INT_MAX);

	vitesseTrain1 = lireEntierDansIntervalle("Entrez la vitesse du premier train :", -100, 100);

	positionInitialeTrain2 = lireEntierDansIntervalle("Entrez la position intiale du second train :", INT_MIN, INT_MAX);

	vitesseTrain2 = lireEntierDansIntervalle("Entrez la vitesse du second train :", -100, 100);

	// It�ration pour chaque seconde jusqu'� la fin du temps total
	for (int i = 1; i <= tempsTotal; i++)
	{
		// Affichage des positions des trains � chaque seconde
		cout << "Apres " << i << " seconde(s)" << endl;

		cout << "Train 1 : " << positionTrain(positionInitialeTrain1, vitesseTrain1, i) << endl;
		cout << "Train 2 : " << positionTrain(positionInitialeTrain2, vitesseTrain2, i) << endl;

		// V�rification de collision � chaque seconde
		if (estEnCollision(i, positionInitialeTrain1,
			positionInitialeTrain2, vitesseTrain1,
			vitesseTrain2))
		{
			cout << "Il y a eu une collision pendant la " << i << "e seconde !" << endl;
			return;
		}

	}

	// Si aucune collision n'a eu lieu
	cout << "Il n'y a pas eu de collision" << endl;
}

void q4() {
	const int taille = 10; 
	int tab[taille];

	// Saisie du tableau d'entiers
	cout << "Entrez 10 nombres entiers : ";
	for (int i = 0; i < taille; i++) {
		cin >> tab[i]; //pour ajouter les nombres entrees dans le tableau
	}

	// Tri du tableau d'entiers
	for (int i = 0; i < taille - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < taille; j++) {
			if (tab[j] < tab[minIndex]) {
				minIndex = j;
			}
		}
		int temp = tab[i];
		tab[i] = tab[minIndex];
		tab[minIndex] = temp;
	}

	// Affichage du tableau tri�
	cout << "Voici le tableau trie : ";
	for (int i = 0; i < taille; i++) {
		cout << tab[i] << " ";
	}
	cout << endl;

}

// D�finition de la structure Aliment
struct Aliment {
	string nom;
	string type;
	int quantite;
	double prix;
};
/*Le warning C26495 signifie "Variable 'nom/type/quantite/prix' est d�clar�e mais n'est jamais initialis�e."
  Cela signifie qu'on devrait initialiser ces variables � une valeur avant de les utiliser pour �viter les
  comportements ind�finis.

  Dans le cas de la structure Aliment, les variables sont initialis�es par les donn�es lues � partir du fichier
  dans la fonction q5(). Ainsi, vous pouvez ignorer ces avertissements car les variables seront initialis�es avant
  d'�tre utilis�es dans le reste du code.*/

// Fonction pour trouver l'aliment le plus cher dans l'inventaire
Aliment alimentPlusCher(Aliment inventaire[], int nbAliments) {
	// Recherche de l'aliment le plus cher
	int indexMaxPrix = 0;
	double maxPrix = inventaire[0].prix;

	for (int i = 1; i < nbAliments; i++) {
		if (inventaire[i].prix > maxPrix) {
			indexMaxPrix = i;
			maxPrix = inventaire[i].prix;
		}
	}

	// Retourne l'aliment le plus cher
	return inventaire[indexMaxPrix];
}

// Fonction pour la question 5
void q5() {
	const int MAX_ALIMENTS = 10;

	// Cr�ation du tableau d'aliments
	Aliment inventaire[MAX_ALIMENTS];
	int nbAliments = 0;

	// Lecture du fichier d'inventaire
	ifstream fichier("inventaire.txt");
	if (!fichier) {
		cout << "Erreur: impossible d'ouvrir le fichier d'inventaire." << endl;
		return;
	}

	while (nbAliments < MAX_ALIMENTS && !fichier.eof()) {
		string ligne;
		getline(fichier, ligne);
		if (!ligne.empty()) {
			size_t pos1 = ligne.find('\t');
			size_t pos2 = ligne.find('\t', pos1 + 1);
			size_t pos3 = ligne.find('\t', pos2 + 1);
			string nom = ligne.substr(0, pos1);
			string type = ligne.substr(pos1 + 1, pos2 - pos1 - 1);
			int quantite = stoi(ligne.substr(pos2 + 1, pos3 - pos2 - 1));
			double prix = stod(ligne.substr(pos3 + 1));
			Aliment aliment = { nom, type, quantite, prix };
			inventaire[nbAliments++] = aliment;
		}
	}

	fichier.close();

	// Affichage de tous les aliments de l'inventaire avec le prix total
	for (int i = 0; i < nbAliments; i++) {
		double prixTotal = inventaire[i].quantite * inventaire[i].prix;
		cout << inventaire[i].quantite << " " << inventaire[i].nom << " ("
			<< inventaire[i].type << ") a " << inventaire[i].prix
			<< "$ chacun, pour un total de " << prixTotal << "$" << endl;
	}

	// Trouver l'aliment le plus cher
	Aliment alimentCher = alimentPlusCher(inventaire, nbAliments);

	// Affichage de l'aliment le plus cher
	cout << endl << "L'aliment le plus cher est : " << alimentCher.quantite
		<< " " << alimentCher.nom << " (" << alimentCher.type
		<< ") a " << alimentCher.prix << "$ chacun pour un total de "
		<< (alimentCher.prix * alimentCher.quantite) << "$" << endl;
}


int main()
{
	q1();
	q2();
	q3();
	q4();
	q5();
	return 0;
}


