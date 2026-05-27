#include "Zona.h"
#include "ElementoInteractivo.h"
#include "Explorador.h"
#include <vector>
#include <iostream>
#include <algorithm>
Zona::Zona(std::string n){
    nombre=n;
}
void Zona::agregarElemento(ElementoInteractivo* e){
    elementos.push_back(e);
    std::cout<<"Elemento agregado correctamente"<<std::endl;
}
void Zona::mostrarElementos(){
    for (int i= 0; i<elementos.size();i++){
        std::cout<<i<<"."<<elementos[i]->getNombre()<<std::endl;
    }
}
void Zona::interactuar (int indice, Explorador* explorador){
    if (indice>=0 && indice < elementos.size()){
        elementos[indice]->interactuar(explorador);
    }else {
        std::cout<<"no existe un elemento en esas posicion."<<std::endl;
    }
}
void Zona::interactuar(std::string nombre, Explorador* explorador){
    std::string nombreBuscado = nombre;
    std::transform(nombreBuscado.begin(), nombreBuscado.end(), nombreBuscado.begin(), ::tolower);

    for(int i = 0; i < elementos.size(); i++){
        std::string nombreElemento = elementos[i]->getNombre();
        std::transform(nombreElemento.begin(), nombreElemento.end(), nombreElemento.begin(), ::tolower);

        if(nombreElemento == nombreBuscado){
            elementos[i]->interactuar(explorador);
            return;
        }
    }
    std::cout << "No se encontro un elemento con ese nombre." << std::endl;
}
std::string Zona::getNombre(){
    return nombre;
}
