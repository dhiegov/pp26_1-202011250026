#ifndef MEDIADOR_H
#define MEDIADOR_H

// interface
// Mediator do Design Pattern Mediator, ver Colaborador.h
class Mediador
{
public:
    // proximaAcao no diagrama base, renomeado para
    // melhor indicar o que é feito.
    void virtual proximaFase(void) = 0;
};

#endif
