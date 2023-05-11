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


int main()
{
	q1();
	return 0;
}


