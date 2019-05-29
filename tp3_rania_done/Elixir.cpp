//
//  Elixir.cpp
//  tp3
//
//  Created by Rania Abid on 2019-05-26.
//  Copyright © 2019 Rania Abid. All rights reserved.
//

#include "Elixir.h"
Elixir::Elixir():PotionMagique()
{}

Elixir:: Elixir(const std::string &nom, int bonus):PotionMagique(nom,bonus)
{}

std::ostream& operator<<(std::ostream& o, const Elixir& elixir);

void Elixir::utiliserSur(Creature& creature) const
{
    
}

