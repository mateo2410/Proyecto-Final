#ifndef ANIMALHERIDO_H_INCLUDED
#define ANIMALHERIDO_H_INCLUDED
#include "ElementoInteractivo.h"
#include <iostream>

class AnimalHerido : public ElementoInteractivo {
public:
    AnimalHerido(std::string n);
    void interactuar(Explorador* explorador);
};
#endif // ANIMALHERIDO_H_INCLUDED
