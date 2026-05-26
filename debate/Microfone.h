#ifndef MICROFONE_H
#define MICROFONE_H

#include "Colaborador.h"

class Microfone : public Colaborador
{
private:
    int id;
    bool ligado;
public:
    void ligar(void);
    void desligar(void);
};

#endif // MICROFONE_H
