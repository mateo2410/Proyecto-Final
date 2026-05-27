#ifndef RESERVA_H_INCLUDED
#define RESERVA_H_INCLUDED
#include "Zona.h"
#include <unordered_map>
#include <string>
class Reserva{
private:
    std::unordered_map<std::string, Zona* >zonas;

public:
    void agregarZona(std::string codigo, Zona* z);
    Zona* buscarZona(std::string codigo);
    void mostrarZonas();
};


#endif // RESERVA_H_INCLUDED
