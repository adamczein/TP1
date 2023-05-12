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

void q2()
{
	int nombreEntier;
	int nombreAleatoire = rand() % 1001;
	int nombreTentatives = 0;

	
	while(true)
	{ 
		do 
		{
			cout << "Entrez un nombre entier entre 0 et 1000 : ";
			cin >> nombreEntier;
		} while (nombreEntier > 1000 || nombreEntier < 0);

		if (nombreEntier < nombreAleatoire)
		{
		cout << "Trop bas." << endl;
		nombreTentatives++;

		}

		if (nombreEntier > nombreAleatoire)
		{
		cout << "Trop haut." << endl;
		nombreTentatives++;
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
	
	if (vitesseTrain2 < 0)
	{
		if (positionInitialeTrain1 + (vitesseTrain1 * tempsTotal) > positionInitialeTrain2 + (vitesseTrain2 * tempsTotal)) {
			return true;
		}
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

	do 
	{
	cout << "Entrez le temps total :";
	cin >> tempsTotal;
	} while (tempsTotal < 0);

	cout << "Entrez la position intiale du premier train :";
	cin >> positionInitialeTrain1;

	do
	{ 
	cout << "Entrez la vitesse du premier train :";
	cin >> vitesseTrain1;
	} while (vitesseTrain1 < -100 || vitesseTrain1 > 100);

	cout << "Entrez la position intiale du second train :";
	cin >> positionInitialeTrain2;

	do
	{
		cout << "Entrez la vitesse du second train :";
		cin >> vitesseTrain2;
	} while (vitesseTrain2 < -100 || vitesseTrain2 > 100);

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



int main()
{
	q1();
	q2();
	q3();
	return 0;
}


