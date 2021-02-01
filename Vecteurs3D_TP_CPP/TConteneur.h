#pragma once
#ifndef H_CONTENEUR
#define H_CONTENEUR

#include <iostream>

using namespace std;

template <class T,int n> class TConteneur
{
private :
	T m_Tableau[n];
public :
	//Les constructeurs
	TConteneur(); //Le constructeur
	TConteneur(const TConteneur&); //Le constructeur de copie
	~TConteneur();//Le destructeur

	//Les surcharges de l'opérateur d'indexation
	//T operator[](int const n_i)const;
	T& operator[](int const n_i);
};

//Le constructeur
template <class T, int n>
inline TConteneur<T,n>::TConteneur()
{}

//Le constructeur de copie
template <class T, int n>
inline TConteneur<T, n>::TConteneur(const TConteneur& tOrigine)
{
	m_Tableau = new T[n];
	m_Tableau = tOrigine.m_Tableau;
}

//Le destructeur
template <class T, int n>
inline TConteneur<T, n>::~TConteneur()
{}

//Les surcharges de l'opérateur d'indexation
/*template <class T, int n>
inline T TConteneur<T, n>::operator[](int const n_i)const
{
	if (n_i >= 0 && n_i < n)
	{
		return m_Tableau[n_i];
	}
	else
	{
		cout << "Erreur dépassement de Tableau." << endl;
		return m_Tableau[0];
	}
}*/

//Seul celui-ci est appelé
template <class T, int n>
inline T& TConteneur<T, n>::operator[](int const n_i)
{
	if (n_i >= 0 && n_i < n)
	{
		return m_Tableau[n_i];
	}
	else
	{
		cout << "Erreur dépassement de Tableau." << endl;
		return m_Tableau[0];
	}
}
#endif