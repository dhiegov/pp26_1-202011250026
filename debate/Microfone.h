#ifndef MICROFONE_H
#define MICROFONE_H

#include "Colaborador.h"

class Microfone : public Colaborador
{
private:
    int id;
    bool ligado;
public:
    Microfone(void) = delete;
    Microfone(int id);
    void ligar(void);
    void desligar(void);
};

#endif // MICROFONE_H
