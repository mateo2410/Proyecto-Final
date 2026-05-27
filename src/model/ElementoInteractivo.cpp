#include "ElementoInteractivo.h"

ElementoInteractivo::ElementoInteractivo(std::string n){
    nombre=n;
}
std::string ElementoInteractivo::getNombre(){
    return nombre;
}
