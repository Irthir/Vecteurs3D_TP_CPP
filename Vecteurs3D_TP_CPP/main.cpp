#include <iostream>
#include "TVecteur3D.h"
#include "TVecteur2D.h"
#include "TConteneur.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, ""); //Pour mettre les accents dans la console.

	//Travail 1 :

	TVecteur3D<float> vecA(1.f, 2.f, 3.f);
	TVecteur3D<float> vecB(3.f, 2.f, 1.f);
	TVecteur3D<float> vecC(5.f, 5.f, 4.f);

	//Version 1 :
	cout << "Affichage des vecteurs A, B et C : " << endl;
	vecA.Affiche();
	vecB.Affiche();
	vecC.Affiche();

	cout << "Addition des vecteurs A et B : " << endl;
	vecA.Addition(vecB).Affiche();

	cout << "Soustraction du vecteur A par B : " << endl;
	vecA.Soustraction(vecB).Affiche();

	cout << "Produit Scalaire de A et B : " << vecA.ProduitScalaire(vecB) << endl;

	cout << "Produit vectoriel de A et B : " << endl;
	vecA.ProduitVectoriel(vecB).Affiche();

	float fDeterminant;
	fDeterminant = vecA.CalculDeterminant(vecB, vecC);
	cout << "Calcul du déterminant de A, B et C : " << fDeterminant << endl;

	cout << "Calcul du Produit mixte de A, B et du déterminant précédent : " << endl;
	vecA.ProduitMixte(vecB, fDeterminant).Affiche();

	//Version 2 :
	cout << "Passons aux surcharge d'opérateurs !" << endl;

	cout << "Addition des vecteurs A et B : " << endl << (vecA + vecB) << endl;

	cout << "Soustraction du vecteur A par B : " << endl << (vecA - vecB) << endl;

	cout << "Produit Scalaire de A et B : " << (vecA*vecB) << endl;

	cout << "Produit vectoriel de A et B : " << endl << (vecA ^ vecB) << endl;

	//Travail 2 :

	TVecteur2D<int> vectA(1, 2);
	TVecteur2D<int> vectB(3, 4);

	cout << "Affichage des vecteurs A et B : " << endl;
	vectA.Affiche();
	vectB.Affiche();

	cout << "Addition des vecteurs A et B : " << endl << (vectA + vectB) << endl;

	cout << "Soustraction du vecteur A par B : " << endl << (vectA - vectB) << endl;

	cout << "Produit Scalaire de A et B : " << (vectA * vectB) << endl;

	cout << "Produit vectoriel de A et B : " << endl << (vectA ^ vectB) << endl;

	//Travail 3 :

	cout << "Le conteneur de vecteurs !" << endl;

	TConteneur<TVecteur2D<int>, 2> tab2D;
	tab2D[0] = vectA;
	tab2D[1] = vectB;
	for (int i = 0; i < 2; i++)
	{
		cout<< tab2D[i] <<endl;
	}

	TConteneur<TVecteur3D<float>, 3> tab3D;
	tab3D[0] = vecA;
	tab3D[1] = vecB;
	tab3D[2] = vecC;
	for (int i = 0; i < 3; i++)
	{
		cout << tab3D[i] << endl;
	}

	return 0;
}