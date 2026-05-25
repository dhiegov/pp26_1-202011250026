#ifndef GERENCIADOR_DEBATE_H
#define GERENCIADOR_DEBATE_H

#include "Candidato.h"
#include "Cronometro.h"
#include "Logger.h"

#define MAX_CANDIDATOS 10

class GerenciadorDebate
{
private:
    Candidato candidatos[10];
    int n_candidatos;

};

#endif
