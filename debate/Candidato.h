#ifndef CANDIDATO_H
#define CANDIDATO_H

#include <iostream>

#include "Microfone.h"
#include "Colaborador.h"

class Candidato : public Colaborador
{
private:
    int id; // idealmente o número de voto do Candidato
    std::string nome;
    bool jaPerguntou;
    Microfone* microfone;
public:
    void marcarComoInquiridor(void);
};

#endif // CANDIDATO_H
