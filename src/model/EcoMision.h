#ifndef ECOMISION_H_INCLUDED
#define ECOMISION_H_INCLUDED
#include "Reserva.h"
#include "Explorador.h"

class EcoMision{
private:
    Reserva reserva;
    Explorador* explorador;

public:
    EcoMision();
    ~EcoMision();
    void iniciarSistema();
};


#endif // ECOMISION_H_INCLUDED
