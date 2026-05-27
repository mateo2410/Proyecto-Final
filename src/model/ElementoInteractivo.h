#ifndef ELEMENTOINTERACTIVO_H_INCLUDED
#define ELEMENTOINTERACTIVO_H_INCLUDED
#include <string>

class Explorador;
class ElementoInteractivo{
private:
    std::string nombre;

public:
    ElementoInteractivo(std::string n);
    std::string getNombre();
    virtual void interactuar(Explorador* explorador)=0;
};

#endif // ELEMENTOINTERACTIVO_H_INCLUDED
