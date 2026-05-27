#ifndef EXPLORADOR_H_INCLUDED
#define EXPLORADOR_H_INCLUDED
#include <string>
class Zona;
class Explorador{
private:
    std::string nombre;
    int energia;
    int puntajeAmbiental;
    int elementos;
    Zona* zonaActual;

public:
    Explorador(std::string n, int e);
    int getEnergia ();
    int getPuntaje ();
    void perderEnergia(int cantidad);
    void ganarEnergia(int cantidad);
    void ganarPuntaje(int cantidad);
    void recolectarElementos();
    void cambiarZona(Zona* zona);
    void mostrarInfo();
    Zona* getZonaActual();
};

#endif // EXPLORADOR_H_INCLUDED
