/**
* Programme TD1 du cours INF1015
* \file Source.cpp
* \auteurs Salma Zaghloul et Adam El Zein
* \date 14 mai 2023
* \Créé le 10 mai 2023
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

bool estPremier(int nombreEntier) 
{
	for (int i = 2; i <= sqrt(nombreEntier); i++)
	{ 
		if(nombreEntier % i == 0) 
		{
			return false;
		}
	}
		return true;

}

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

		while (!estPremier(nombreEntier)) 
		{
			nombreEntier++;
	    }

		cout << "Le prochain nombre entier est " << nombreEntier << endl;;
		
	}
}

int lireEntierDansIntervalle(string texte, int valeurMinimale, int valeurMaximale)
{
	int entree;

	do
	{
		cout << texte;
		cin >> entree;

	} while (entree > valeurMaximale || entree < valeurMinimale);

	return entree;
}

void q2()
{
	int nombreEntier;
	int nombreAleatoire = rand() % 1001;
	int nombreTentatives = 0;


	while(true)
	{ 
		nombreEntier = lireEntierDansIntervalle("Entrez un nombre entier : " , 0, 1000);
		nombreTentatives++;

		if (nombreEntier < nombreAleatoire)
		{
		cout << "Trop bas." << endl;

		}

		if (nombreEntier > nombreAleatoire)
		{
		cout << "Trop haut." << endl;
	
		}
	
		if (nombreEntier == nombreAleatoire)
		{
		cout << "Bravo! Vous avez reussi en " << nombreTentatives + 1 << " tentative(s)!" << endl;
		return;

		}
	}
}

bool estEnCollision(int tempsTotal, int positionInitialeTrain1, 
					int positionInitialeTrain2, int vitesseTrain1, 
					int vitesseTrain2)
{	
	if (vitesseTrain1 < 0) {
		if (positionInitialeTrain1 + (vitesseTrain1 * tempsTotal) < positionInitialeTrain2 + (vitesseTrain2 * tempsTotal)) {
			return true;
		}
	return false;

	}
	
	else if (vitesseTrain2 < 0)
	{
		if (positionInitialeTrain1 + (vitesseTrain1 * tempsTotal) > positionInitialeTrain2 + (vitesseTrain2 * tempsTotal)) {
			return true;
		}
	return false;
	}

	else 
	{
		return false;
	}	

}

int positionTrain(int positionInitiale, int vitesse, int temps)
{
	int position;

	position = positionInitiale + (vitesse * temps);

	return position;
}

void q3()
{

	int tempsTotal;
	int positionInitialeTrain1;
	int positionInitialeTrain2;
	int vitesseTrain1;
	int vitesseTrain2;

	tempsTotal = lireEntierDansIntervalle("Entrez le temps total :", 0, INT_MAX);

	positionInitialeTrain1 = lireEntierDansIntervalle("Entrez la position intiale du premier train :", INT_MIN, INT_MAX);

	vitesseTrain1 = lireEntierDansIntervalle("Entrez la vitesse du premier train :", -100, 100);

	positionInitialeTrain2 = lireEntierDansIntervalle("Entrez la position intiale du second train :", INT_MIN, INT_MAX);

	vitesseTrain2 = lireEntierDansIntervalle("Entrez la vitesse du second train :", -100, 100);

	for (int i = 1; i <= tempsTotal; i++)
	{
		cout << "Apres " << i << " seconde(s)" << endl;

		cout << "Train 1 : " << positionTrain(positionInitialeTrain1, vitesseTrain1, i) << endl;
		cout << "Train 2 : " << positionTrain(positionInitialeTrain2, vitesseTrain2, i) << endl;

		if (estEnCollision(i ,positionInitialeTrain1,
			positionInitialeTrain2, vitesseTrain1,
			vitesseTrain2))
		{
			cout << "Il y a eu une collision pendant la " << i << "e seconde !" << endl;
			return;
		}
		
	}

	cout << "Il n'y a pas eu de collision" << endl;

}

void q4() {
	const int taille = 10; //not sure si il fait ou pas mettre const
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

	// Affichage du tableau trié
	cout << "Voici le tableau trié : ";
	for (int i = 0; i < taille; i++) {
		cout << tab[i] << " ";
	}
	cout << endl;

}

//les constantes necessiares pour question 5
const int MAX_ALIMENTS = 10;

struct Aliment {
	string nom;
	string type;
	int quantite;
	double prix;
};

//la question 5 peut supporter jusqu'a 10 aliments  (limite imposer dans la question)
void q5() {
	// Création du tableau d'aliments
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

	// Recherche de l'aliment le plus cher
	int indexMaxPrix = 0;
	double maxPrix = inventaire[0].prix;

	for (int i = 1; i < nbAliments; i++) {
		if (inventaire[i].prix > maxPrix) {
			indexMaxPrix = i;
			maxPrix = inventaire[i].prix;
		}
	}

	// Affichage de tous les aliments de l'inventaire
	for (int i = 0; i < nbAliments; i++) {
		cout << inventaire[i].quantite << " " << inventaire[i].nom << " ("
			<< inventaire[i].type << ") a " << inventaire[i].prix
			<< "$ chacun" << endl;
	}

	// Affichage de l'aliment le plus cher
	cout << endl << "L'aliment le plus cher est : " << inventaire[indexMaxPrix].quantite
		<< " " << inventaire[indexMaxPrix].nom << " (" << inventaire[indexMaxPrix].type
		<< ") a " << inventaire[indexMaxPrix].prix << "$ chacun" << endl;
}




int main()
{
	//q1();
	//q2();
	//q3();
	//q4();
	//q5();
	return 0;
}


