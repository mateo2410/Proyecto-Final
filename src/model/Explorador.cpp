#include "Explorador.h"
#include "Zona.h"
#include <iostream>

Explorador::Explorador(std::string n, int e){
    nombre=n;
    energia=e;
    puntajeAmbiental=0;
    elementos=0;
    zonaActual= nullptr;
}

int Explorador::getEnergia(){
    return energia;
}
int Explorador::getPuntaje(){
    return puntajeAmbiental;
}
void Explorador::perderEnergia(int cantidad) {
    energia=energia-cantidad;
}
void Explorador::ganarEnergia(int cantidad){
    energia=energia+cantidad;
}
void Explorador::ganarPuntaje(int cantidad){
    puntajeAmbiental=puntajeAmbiental+cantidad;
}
void Explorador::recolectarElementos(){
    elementos++;
    std::cout<<"elemento recolectado"<<std::endl;
}
void Explorador::cambiarZona(Zona* zona){
    zonaActual=zona;
}
void Explorador::mostrarInfo(){
    std::cout<<"Explorador: "<<nombre<<std::endl;
    std::cout<<"Energia: "<<energia<<std::endl;
    std::cout<<"Puntaje ambiental: "<<puntajeAmbiental<<std::endl;
    std::cout<<"Elementos recolectados: "<<elementos<<std::endl;
    if(zonaActual != nullptr){
        std::cout<<"Zona actual: "<<zonaActual->getNombre()<<std::endl;
    }
}
Zona* Explorador::getZonaActual(){
    return zonaActual;
}
