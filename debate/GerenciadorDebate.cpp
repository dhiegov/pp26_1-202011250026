
#include "GerenciadorDebate.h"

GerenciadorDebate::GerenciadorDebate()
: tempos {0, 0, 0, 0}
{
    this->inquiridor = nullptr;
    this->inquirido = nullptr;
    this->cronometro = new Cronometro();
    this->cronometro->setMediador(this);
    this->logger = new Logger();
    this->faseAtual = PERGUNTA;
}

GerenciadorDebate::~GerenciadorDebate()
{
    delete this->cronometro;
    delete this->logger;
}

void GerenciadorDebate::iniciarFase(int tempo)
{

}


void GerenciadorDebate::proximaFase()
{
    switch (this->faseAtual)
    {
        case PERGUNTA:
            this->faseAtual = RESPOSTA;
            this->iniciarFase(this->tempos[RESPOSTA]);
        break;

        case RESPOSTA:
            this->faseAtual = REPLICA;
            this->iniciarFase((this->tempos[REPLICA]));
        break;

        case REPLICA:
            this->faseAtual = TREPLICA;
            this->iniciarFase((this->tempos[TREPLICA]));
        break;

        case TREPLICA:
            this->faseAtual = PERGUNTA;
            this->registrarAcao("Interação terminada.");
        break;

        default:
            this->faseAtual = PERGUNTA;
        break;
    }
}
