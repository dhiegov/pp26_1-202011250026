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
    Candidato(void) = delete;
    Candidato(int id, std::string nome);

    void ligarMicrofone(void);
    void desligarMicrofone(void);
    void marcarComoInquiridor(void);

    int getId(void) const;
    std::string getNome(void) const;
    bool getJaPerguntou(void) const;
};

#endif // CANDIDATO_H
