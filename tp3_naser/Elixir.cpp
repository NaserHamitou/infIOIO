#include "Elixir.h"

Elixir::Elixir() : PotionMagique() {}

Elixir::Elixir(const std::string &nom, int bonus) : PotionMagique(nom, bonus){}

<<<<<<< HEAD
void Elixir::utiliserSur(Creature& creature) const{         /*!!!!!!!!!NOT SURE!!!!!!!!!*/
=======
void Elixir::utiliserSur(Creature& creature) const{         /*!!!!!!!!!! NOT SURE !!!!!!!!!*/
>>>>>>> f7ee4e751e9ec3ce6c07cf6320f00a855590d6df

	ObjetMagique::utiliserSur(creature);
	PotionMagique::utiliserSur(creature);

}

 std::ostream& operator<<(std::ostream& os, const Elixir& elixir){
<<<<<<< HEAD

	 os << "l'objet " << elixir.obtenirNom() << "fournit un bonus de " << elixir.obtenirBonus() << std::endl;
	 return os;

=======
	 os << "l'objet " << elixir.obtenirNom() << "fournit un bonus de " << elixir.obtenirBonus() << std::endl;
	 return os;
>>>>>>> f7ee4e751e9ec3ce6c07cf6320f00a855590d6df
 }