
#include "Cronometro.h"

#include <chrono>
#include <thread>

Cronometro::Cronometro()
{
    this->tempoAtual = 0;
}

void Cronometro::iniciar(int tempo)
{
    for (this->tempoAtual = tempo; this->tempoAtual > 0; this->tempoAtual--) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    this->finalizarTempo();
}

void Cronometro::finalizarTempo(void)
{
    this->mediador->proximaFase(CRONOMETRO);
}

