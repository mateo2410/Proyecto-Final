#ifndef ZONA_H_INCLUDED
#define ZONA_H_INCLUDED
#include <string>
#include <vector>
#include "ElementoInteractivo.h"
class Explorador;
class Zona{
private:
     std::string nombre;
     std::vector<ElementoInteractivo*>elementos;
public:
    Zona(std::string n);
    void agregarElemento(ElementoInteractivo* e);
    void mostrarElementos();
    void interactuar (int indice, Explorador* explorador);
    void interactuar (std::string nombre, Explorador* explorador);
    std::string getNombre();
 };
#endif // ZONA_H_INCLUDED
