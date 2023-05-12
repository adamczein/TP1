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
		do {
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



int main()
{
	q1();
	q2();
	return 0;
}


