#ifndef CRONOMETRO_H
#define CRONOMETRO_H

#include "Colaborador.h"

class Cronometro : public Colaborador
{
private:
    int tempoAtual;
public:
    Cronometro();
    void iniciar(int tempo);
    void finalizarTempo(void);
};

#endif
