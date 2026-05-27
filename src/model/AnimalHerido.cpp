#include "AnimalHerido.h"
#include "Explorador.h"
#include <iostream>

AnimalHerido::AnimalHerido(std::string n): ElementoInteractivo(n){
}
void AnimalHerido::interactuar(Explorador* explorador){
    explorador->ganarPuntaje(10);
    std::cout<<"Ayudaste al animal herido. +10 puntos."<<std::endl;
}
