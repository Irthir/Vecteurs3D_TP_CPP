#include <iostream>
#include "TVecteur3D.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, ""); //Pour mettre les accents dans la console.

	TVecteur3D<float> vecA(1.f, 2.f, 3.f);
	TVecteur3D<float> vecB(3.f, 2.f, 1.f);
	TVecteur3D<float> vecC(5.f, 5.f, 4.f);

	cout << "Affichage des vecteurs A, B et C : " << endl;
	vecA.Affiche();
	vecB.Affiche();
	vecC.Affiche();

	cout << "Addition des vecteurs A et B : " << endl;
	vecA.Addition(vecB).Affiche();

	cout << "Soustration du vecteur A par B : " << endl;
	vecA.Soustraction(vecB).Affiche();

	cout << "Produit Scalaire de A et B : " << vecA.ProduitScalaire(vecB) << endl;

	cout << "Produit vectoriel de A et B : " << endl;
	vecA.ProduitVectoriel(vecB).Affiche();

	float fDeterminant;
	fDeterminant = vecA.CalculDeterminant(vecB, vecC);
	cout << "Calcul du déterminant de A, B et C : " << fDeterminant << endl;

	cout << "Calcul du Produit mixte de A, B et du déterminant précédent : " << endl;
	vecA.ProduitMixte(vecB, fDeterminant).Affiche();

	return 0;
}