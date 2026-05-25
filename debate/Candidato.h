#ifndef CANDIDATO_H
#define CANDIDATO_H

#include <iostream>

#include "Microfone.h"

class Candidato
{
private:
    int id;
    std::string nome;
    bool jaPerguntou;
    Microfone* microfone;


};

#endif // CANDIDATO_H
