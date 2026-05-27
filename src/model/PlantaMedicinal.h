#ifndef PLANTAMEDICINAL_H_INCLUDED
#define PLANTAMEDICINAL_H_INCLUDED
#include "ElementoInteractivo.h"
#include <iostream>

class PlantaMedicinal : public ElementoInteractivo{
public:
    PlantaMedicinal(std::string n);
    void interactuar(Explorador* explorador);
};


#endif // PLANTAMEDICINAL_H_INCLUDED
