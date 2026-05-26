
#include "Fachada.h"

Fachada::Fachada()
{
    this->gerenciador = new GerenciadorDebate();
}

Fachada * Fachada::getInstance()
{
    if (Fachada::instance == nullptr) {
        Fachada::instance = new Fachada();
    }
    return Fachada::instance;
}

