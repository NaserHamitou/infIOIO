#pragma once

#include <algorithm>
#include "Foncteur.h"

using namespace std;

template<typename T, typename S>
class MondeMagique 
{
public :
	//Constructeur
	MondeMagique();

	//Destructeur
	~MondeMagique();

	//accesseurs
	list<T*> obtenirMaitre();
	list<S*> obtenirCompagnon();

	/*methodes ajouter
	Param T et S*/
	void ajouter(T* t);
	void ajouter(S* s);

	/*methodes supprimer
	Param T et S*/
	void supprimer(T* t);
	void supprimer(S* s);

	/*methodes supprimeMaitres et supprimeCompagnon
	Param ---> ??? */
	void supprimerMaitre(/* ??? */);
	void supprimerCompagnon(/* ??? */);

	/*methode vider*/
	void vider();

	//Operateurs surcharger += et -=    
	T& operator+=(const T& t);
	T& operator-=(const T& t);
										/* ?????? */
	S& operator+=(const S& s); 
	S& operator-=(const S& s);

protected :
	list<T*> listMaitre_;
	list<S*> listCompagnon_;

};

template<typename T, typename S>
MondeMagique<T, S>::MondeMagique() {}

template<typename T, typename S>
MondeMagique<T, S>::~MondeMagique() {}

template<typename T, typename S>
list<T*> MondeMagique<T, S>::obtenirMaitre() {
	return listMaitre_;
}

template<typename T, typename S>
list<S*> MondeMagique<T, S>::obtenirCompagnon() {
	return listCompagnon_;
}

template<typename T, typename S>
void MondeMagique<T, S>::ajouter(T* t) {
	listMaitre_.insert(t);
}

template<typename T, typename S>
void MondeMagique<T, S>::ajouter(S* s) {
	listCompagnon_.insert(s);
}

template<typename T, typename S>
void MondeMagique<T, S>::supprimer(T* t) {
	for (list<T*>::iterator it = listMaitre_.begin(); it != listMaitre_.end(); i++) {
		if (*it == *t)
			listMaitre_.erase(it);
	}
}

template<typename T, typename S>
void MondeMagique<T, S>::supprimer(S* s) {
	for (list<S*>::iterator it = listCompagnon_.begin(); i != listCompagnon_.end(); i++) {
		if (*it == *s)
			listCompagnon_.erase(it);
	}
}

template<typename T, typename S>
void MondeMagique<T, S>::vider() {
	listMaitre_.clear();
	listCompagnon_.clear();
}

template<typename T, typename S>
T& MondeMagique<T, S>::operator+=(const T& t) {
	listMaitre_.insert(t);
	return listMaitre_;
}

template<typename T, typename S>
T& MondeMagique<T, S>::operator-=(const T& t) {
	supprimer(t);
}


