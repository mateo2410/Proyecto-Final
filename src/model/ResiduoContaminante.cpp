#include "ResiduoContaminante.h"
#include "Explorador.h"
#include <iostream>

ResiduoContaminante::ResiduoContaminante(std::string n):ElementoInteractivo(n){
}
void ResiduoContaminante::interactuar(Explorador* explorador){
    explorador->perderEnergia(10);
    std::cout<<"Has limpiado el residuo con exito"<<std::endl;
    std::cout<<"has perdido energia. -10"<<std::endl;
}
