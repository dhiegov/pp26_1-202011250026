#ifndef COLABORADOR_H
#define COLABORADOR_H

#include "Mediador.h"

// Colleague do Design Pattern Mediator, ver Mediador.h
class Colaborador
{
protected:
    Mediador* mediador;
public:
    void setMediador(Mediador* m) {
        this->mediador = m;
    }
};

#endif
