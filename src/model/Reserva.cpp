#include "Reserva.h"
#include <iostream>
#include "Zona.h"

void Reserva::agregarZona(std::string codigo, Zona* z){
    zonas[codigo]=z;
}
Zona* Reserva::buscarZona(std::string codigo){
    if(zonas.count(codigo)>0){
        return zonas[codigo];
    }
    return nullptr;
}
void Reserva::mostrarZonas(){
    for(auto& par : zonas){
        std::cout <<"codigo: "<<par.first <<std::endl;
    }
}
