#include "MondeMagique.h"


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