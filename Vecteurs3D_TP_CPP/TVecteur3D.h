#pragma once
#ifndef H_VECTEUR3D
#define H_VECTEUR3D

#include <iostream>

using namespace std;

template <class T> class TVecteur3D
{
protected:
	T m_x, m_y, m_z; //Les coordonnées caractérisants le vecteur 3D
public :
	//Les constructeurs
	TVecteur3D(T x=0.f, T y=0.f, T z=0.f); //Le constructeur
	TVecteur3D(const TVecteur3D&); //Le constructeur de copie

	//Fonction d'affichage
	void Affiche() const;
	
	//Opérations usuelles sur les Vecteurs.
	TVecteur3D Addition(TVecteur3D vec3dA);
	TVecteur3D Soustraction(TVecteur3D vec3dA);
	TVecteur3D MultiplicationParScalaire(T scalaire);
	T ProduitScalaire(TVecteur3D vec3dA);
	TVecteur3D ProduitVectoriel(TVecteur3D vec3dA);
	T CalculDeterminant(TVecteur3D vec3dA, TVecteur3D vec3dB);
	TVecteur3D ProduitMixte(TVecteur3D vec3dA, T determinant);

	//Fonctions amies
	friend bool Coincide(TVecteur3D const vec3dA, TVecteur3D const vec3dB)
	{
		bool bResult;

		bResult = ((vec3dA.m_x == vec3dB.m_x) && (vec3dA.m_y == vec3dB.m_y) && (vec3dA.m_z == vec3dB.m_z));

		return bResult;
	}

	//Surcharges d'opérateurs :
	TVecteur3D operator+(const TVecteur3D vec3dA); //Addition
	TVecteur3D operator-(const TVecteur3D vec3dA); //Soustraction
	TVecteur3D operator*(const T scalaire); //Multiplication par Scalaire
	T operator*(const TVecteur3D vec3dA); //Produit Scalaire
	TVecteur3D operator^(const TVecteur3D vec3dA); //Produit Vectoriel
	TVecteur3D operator=(const TVecteur3D vec3dA); //Affectation
	bool operator==(const TVecteur3D vec3dA); //Coincide
	friend ostream& operator<<(ostream& os, const TVecteur3D& vec3d) //Affichage
	{
		cout << "X = " << vec3d.m_x << " Y = " << vec3d.m_y << " Z = " << vec3d.m_z;
		return os;
	}
};

//Les constructeurs

template <class T>
inline TVecteur3D<T>::TVecteur3D(T x, T y, T z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}

template <class T>
inline TVecteur3D<T>::TVecteur3D(const TVecteur3D& vectCopie)
{
	m_x = vectCopie.m_x;
	m_y = vectCopie.m_y;
	m_z = vectCopie.m_z;
}

//Fonction d'affichage
template <class T>
inline void TVecteur3D<T>::Affiche() const
{
	cout << "X = " << m_x << " Y = " << m_y << " Z = " << m_z << endl;
}

//Opérations usuelles sur les Vecteurs.
#pragma region Opérations usuelles sur les vecteurs

template <class T>
inline TVecteur3D<T> TVecteur3D<T>::Addition(TVecteur3D vec3dA)
{
	TVecteur3D vecResult;
	vecResult.m_x = this->m_x + vec3dA.m_x;
	vecResult.m_y = this->m_y + vec3dA.m_y;
	vecResult.m_z = this->m_z + vec3dA.m_z;

	return vecResult;
}

template <class T>
inline TVecteur3D<T> TVecteur3D<T>::Soustraction(TVecteur3D vec3dA)
{
	TVecteur3D vecResult;

	vecResult.m_x = this->m_x - vec3dA.m_x;
	vecResult.m_y = this->m_y - vec3dA.m_y;
	vecResult.m_z = this->m_z - vec3dA.m_z;

	return vecResult;
}

template <class T>
inline TVecteur3D<T> TVecteur3D<T>::MultiplicationParScalaire(T scalaire)
{
	TVecteur3D vecResult;

	vecResult.m_x = this->m_x * scalaire;
	vecResult.m_y = this->m_y * scalaire;
	vecResult.m_z = this->m_z * scalaire;

	return vecResult;
}

template <class T>
inline T TVecteur3D<T>::ProduitScalaire(TVecteur3D vec3dA)
{
	T scalaireResult;

	scalaireResult = (this->m_x * vec3dA.m_x) + (this->m_y * vec3dA.m_y) + (this->m_z * vec3dA.m_z);

	return scalaireResult;
}

template <class T>
inline TVecteur3D<T> TVecteur3D<T>::ProduitVectoriel(TVecteur3D vec3dA)
{
	TVecteur3D vecResult;

	vecResult.m_x = (this->m_y * vec3dA.m_z) - (this->m_z * vec3dA.m_y);
	vecResult.m_y = (this->m_z * vec3dA.m_x) - (this->m_x * vec3dA.m_z);
	vecResult.m_z = (this->m_x * vec3dA.m_y) - (this->m_y * vec3dA.m_x);

	return vecResult;
}

template <class T>
inline T TVecteur3D<T>::CalculDeterminant(TVecteur3D vec3dA, TVecteur3D vec3dB)
{
	T determinantResult;

	//Si j'ai compris la formule du produit mixte, c'est le produit vectoriel des deux vecteurs U et V, qu'on utilise pour faire le produit scalaire avec le vecteur W.
	determinantResult = vec3dB.ProduitScalaire(this->ProduitVectoriel(vec3dA)); // determinant = (U * V) . W

	return determinantResult;
}

template <class T>
inline TVecteur3D<T> TVecteur3D<T>::ProduitMixte(TVecteur3D vec3dA, T determinant)
{
	TVecteur3D vecResult;

	vecResult = (this->ProduitVectoriel(vec3dA)).MultiplicationParScalaire(determinant);

	return vecResult;
}
#pragma endregion

//Surcharge des opérateurs.
#pragma region surcharge des opérateurs.
template <class T>
inline TVecteur3D<T> TVecteur3D<T>:: operator+(const TVecteur3D vec3dA)
{
	TVecteur3D vecResult;
	vecResult.m_x = this->m_x + vec3dA.m_x;
	vecResult.m_y = this->m_y + vec3dA.m_y;
	vecResult.m_z = this->m_z + vec3dA.m_z;

	return vecResult;
}

template <class T>
inline TVecteur3D<T> TVecteur3D<T>::operator-(const TVecteur3D vec3dA)
{
	TVecteur3D vecResult;

	vecResult.m_x = this->m_x - vec3dA.m_x;
	vecResult.m_y = this->m_y - vec3dA.m_y;
	vecResult.m_z = this->m_z - vec3dA.m_z;

	return vecResult;
}

template <class T>
inline TVecteur3D<T> TVecteur3D<T>::operator*(const T scalaire)
{
	TVecteur3D vecResult;

	vecResult.m_x = this->m_x * scalaire;
	vecResult.m_y = this->m_y * scalaire;
	vecResult.m_z = this->m_z * scalaire;

	return vecResult;
}

template <class T>
inline T TVecteur3D<T>::operator*(const TVecteur3D vec3dA)
{
	T scalaireResult;

	scalaireResult = (this->m_x * vec3dA.m_x) + (this->m_y * vec3dA.m_y) + (this->m_z * vec3dA.m_z);

	return scalaireResult;
}

template <class T>
inline TVecteur3D<T> TVecteur3D<T>::operator^(const TVecteur3D vec3dA)
{
	TVecteur3D vecResult;

	vecResult.m_x = (this->m_y * vec3dA.m_z) - (this->m_z * vec3dA.m_y);
	vecResult.m_y = (this->m_z * vec3dA.m_x) - (this->m_x * vec3dA.m_z);
	vecResult.m_z = (this->m_x * vec3dA.m_y) - (this->m_y * vec3dA.m_x);

	return vecResult;
}

template <class T>
inline TVecteur3D<T> TVecteur3D<T>:: operator=(const TVecteur3D vec3dA)
{
	this->m_x = vec3dA.m_x;
	this->m_y = vec3dA.m_y;
	this->m_z = vec3dA.m_z;

	return *this;
}

template <class T>
inline bool TVecteur3D<T>::operator==(const TVecteur3D vec3dA)
{
	bool bResult;

	bResult = ((vec3dA.m_x == this->m_x) && (vec3dA.m_y == this->m_y) && (vec3dA.m_z == this->m_z));
	
	return bResult;
}
#pragma endregion

#endif // !H_VECTEUR3D