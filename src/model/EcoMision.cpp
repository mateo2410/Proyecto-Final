#include "EcoMision.h"
#include "AnimalHerido.h"
#include "PlantaMedicinal.h"
#include "ResiduoContaminante.h"
#include <iostream>

EcoMision::EcoMision() {
    explorador = nullptr;
}

void EcoMision::iniciarSistema() {
    // crear zonas
    Zona* bosque = new Zona("Bosque Humedo");
    Zona* rio = new Zona("Rio Contaminado");
    Zona* vivero = new Zona("Vivero de Restauracion");

    // agregar elementos a las zonas
    bosque->agregarElemento(new AnimalHerido("Animal Herido"));
    bosque->agregarElemento(new PlantaMedicinal("Planta Medicinal"));
    rio->agregarElemento(new ResiduoContaminante("Residuo Contaminante"));
    vivero->agregarElemento(new PlantaMedicinal("Semilla Nativa"));
    vivero->agregarElemento(new AnimalHerido("Ave Herida"));

    // agregar zonas a la reserva
    reserva.agregarZona("bosque", bosque);
    reserva.agregarZona("rio", rio);
    reserva.agregarZona("vivero", vivero);

    // crear explorador y ubicarlo en zona inicial
    explorador = new Explorador("Westcol", 100);
    explorador->cambiarZona(bosque);

    // menu principal
    int opcion = -1;
    while(opcion != 0) {
        std::cout << "\n=== ECOMISION ===" << std::endl;
        std::cout << "1. Estado del explorador" << std::endl;
        std::cout << "2. Explorar zona actual" << std::endl;
        std::cout << "3. Interactuar con elemento por posicion" << std::endl;
        std::cout << "4. Interactuar con elemento por nombre" << std::endl;
        std::cout << "5. Cambiar de zona" << std::endl;
        std::cout << "6. Ver reserva completa" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "Elige una opcion: ";
        std::string inputOpcion;
        std::getline(std::cin, inputOpcion);
        try {
            opcion = std::stoi(inputOpcion);
        } catch(...) {
            opcion = -1;
        }

        switch(opcion) {
            case 1:
                explorador->mostrarInfo();
                break;

            case 2:
                std::cout << "\nElementos en zona actual:" << std::endl;
                explorador->getZonaActual()->mostrarElementos();
                break;

            case 3: {
                std::string inputIndice;
                std::cout << "Ingresa el numero del elemento: ";
                std::getline(std::cin, inputIndice);
                int indice = std::stoi(inputIndice);
                explorador->getZonaActual()->interactuar(indice, explorador);
                break;
            }

            case 4: {
                std::string nombre;
                std::cout << "Ingresa el nombre del elemento: ";
                std::getline(std::cin, nombre);
                explorador->getZonaActual()->interactuar(nombre, explorador);
                break;
            }

            case 5: {
                std::string codigo;
                std::cout << "Zonas disponibles:" << std::endl;
                reserva.mostrarZonas();
                std::cout << "Ingresa el codigo de la zona: ";
                std::cin >> codigo;
                std::cin.ignore(1000,'\n');
                Zona* nuevaZona = reserva.buscarZona(codigo);
                if(nuevaZona != nullptr) {
                    explorador->cambiarZona(nuevaZona);
                    std::cout << "Zona cambiada exitosamente." << std::endl;
                } else {
                    std::cout << "Zona no encontrada." << std::endl;
                }
                break;
            }

            case 6:
                reserva.mostrarZonas();
                break;

            case 0:
                std::cout << "Hasta luego!" << std::endl;
                break;

            default:
                std::cout << "Opcion invalida." << std::endl;
        }
    }
}
EcoMision::~EcoMision(){
    delete explorador;
    std::cout<<"EcoMision finalizada."<<std::endl;
}
