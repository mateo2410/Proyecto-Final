#include "PlantaMedicinal.h"
#include "Explorador.h"
#include <iostream>

PlantaMedicinal::PlantaMedicinal(std::string n):ElementoInteractivo(n){
}
void PlantaMedicinal::interactuar(Explorador* explorador){
    explorador->ganarEnergia(10);
    std::cout<<"Has ganado energia. +10"<<std::endl;
    explorador->recolectarElementos();
}
