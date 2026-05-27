
#include "Microfone.h"

Microfone::Microfone(int id)
: id(id), ligado(false)
{
}

void Microfone::ligar(void)
{
    this->ligado = true;
}

void Microfone::desligar(void)
{
    this->ligado = false;
}
