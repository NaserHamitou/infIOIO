#include "Elixir.h"

Elixir::Elixir() : PotionMagique() {}

Elixir::Elixir(const std::string &nom, int bonus) : PotionMagique(nom, bonus){}

void Elixir::utiliserSur(Creature& creature) const{         /*!!!!!!!!!! NOT SURE !!!!!!!!!*/

	ObjetMagique::utiliserSur(creature);
	PotionMagique::utiliserSur(creature);

}

 std::ostream& operator<<(std::ostream& os, const Elixir& elixir){
	 os << "l'objet " << elixir.obtenirNom() << "fournit un bonus de " << elixir.obtenirBonus() << std::endl;
	 return os;
 }