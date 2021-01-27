#pragma once
#ifndef H_VECTEUR2D
#define H_VECTEUR2D

#include "TVecteur3D.h"


template <class T> class TVecteur2D :public TVecteur3D<T>
{
public:
	//Les constructeurs
	TVecteur2D(T x = 0.f, T y = 0.f); //Le constructeur
	TVecteur2D(const TVecteur2D&); //Le constructeur de copie

	//Fonction d'affichage
	void Affiche() const;

	//Opérations usuelles sur les Vecteurs avec des Surcharges d'opérateurs :
	TVecteur2D operator+(const TVecteur2D vec2dA); //Addition
	TVecteur2D operator-(const TVecteur2D vec2dA); //Soustraction
	TVecteur2D operator*(const T scalaire); //Multiplication par Scalaire
	T operator*(const TVecteur2D vec2dA); //Produit Scalaire
	TVecteur2D operator^(const TVecteur2D vec2dA); //Produit Vectoriel

	TVecteur2D operator=(const TVecteur2D vec2dA); //Affectation
	bool operator==(const TVecteur2D vec2dA); //Coincide
	friend ostream& operator<<(ostream& os, const TVecteur2D& vec2d) //Affichage
	{
		cout << "X = " << vec2d.m_x << " Y = " << vec2d.m_y;
		return os;
	}
	
	//Fonctions amies
	friend bool Coincide(TVecteur2D const vec2dA, TVecteur2D const vec2dB)
	{
		bool bResult;

		bResult = ((vec2dA.m_x == vec2dB.m_x) && (vec2dA.m_y == vec2dB.m_y));

		return bResult;
	}
};

//Les constructeurs

template <class T>
inline TVecteur2D<T>::TVecteur2D(T x, T y):TVecteur3D<T>(x,y,static_cast<T>(1))
{}

template <class T>
inline TVecteur2D<T>::TVecteur2D(const TVecteur2D& vectCopie)
{
	this->m_x = vectCopie.m_x;
	this->m_y = vectCopie.m_y;
}

//Fonction d'affichage
template <class T>
inline void TVecteur2D<T>::Affiche() const
{
	cout << "X = " << this->m_x << " Y = " << this->m_y << endl;
}

//Opérations usuelles sur les Vecteurs avec des Surcharges d'opérateurs :
#pragma region Opérations usuelles sur les Vecteurs.
template <class T>
inline TVecteur2D<T> TVecteur2D<T>:: operator+(const TVecteur2D vec2dA)
{
	TVecteur2D vecResult;
	vecResult.m_x = this->m_x + vec2dA.m_x;
	vecResult.m_y = this->m_y + vec2dA.m_y;

	return vecResult;
}

template <class T>
inline TVecteur2D<T> TVecteur2D<T>::operator-(const TVecteur2D vec2dA)
{
	TVecteur2D vecResult;

	vecResult.m_x = this->m_x - vec2dA.m_x;
	vecResult.m_y = this->m_y - vec2dA.m_y;

	return vecResult;
}

template <class T>
inline TVecteur2D<T> TVecteur2D<T>::operator*(const T scalaire)
{
	TVecteur2D vecResult;

	vecResult.m_x = this->m_x * scalaire;
	vecResult.m_y = this->m_y * scalaire;
	
	return vecResult;
}

template <class T>
inline T TVecteur2D<T>::operator*(const TVecteur2D vec2dA)
{
	T scalaireResult;

	scalaireResult = (this->m_x * vec2dA.m_x) + (this->m_y * vec2dA.m_y);

	return scalaireResult;
}

template <class T>
inline TVecteur2D<T> TVecteur2D<T>::operator^(const TVecteur2D vec2dA)
{
	TVecteur2D vecResult;

	vecResult.m_x = this->m_y - vec2dA.m_y;
	vecResult.m_y = vec2dA.m_x - this->m_x;

	return vecResult;
}

template <class T>
inline TVecteur2D<T> TVecteur2D<T>:: operator=(const TVecteur2D vec2dA)
{
	this->m_x = vec2dA.m_x;
	this->m_y = vec2dA.m_y;

	return *this;
}

template <class T>
inline bool TVecteur2D<T>::operator==(const TVecteur2D vec2dA)
{
	bool bResult;

	bResult = ((vec2dA.m_x == this->m_x) && (vec2dA.m_y == this->m_y));

	return bResult;
}
#pragma endregion

#endif // !H_VECTEUR2D