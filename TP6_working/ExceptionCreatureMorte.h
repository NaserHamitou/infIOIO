#ifndef EXCEPTIONCREATUREMORTE_H
#define EXCEPTIONCREATUREMORTE_H

#include <stdexcept>

class ExceptionCreatureMorte : public std::runtime_error
{
public:
    ExceptionCreatureMorte(const std::string & what_arg = "") : std::runtime_error(what_arg) {
        compteur_++;
    }

     int obtenirValeurCompteur() { return compteur_;}

private:
     int compteur_;
};

#endif // EXCEPTIONCREATUREMORTE_H
