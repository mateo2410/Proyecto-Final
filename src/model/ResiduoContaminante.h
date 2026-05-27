#ifndef RESIDUOCONTAMINANTE_H_INCLUDED
#define RESIDUOCONTAMINANTE_H_INCLUDED
#include "ElementoInteractivo.h"

class ResiduoContaminante : public ElementoInteractivo{
public:
    ResiduoContaminante(std::string n);
    void interactuar(Explorador* explorador);
};


#endif // RESIDUOCONTAMINANTE_H_INCLUDED
