
#include "Candidato.h"

Candidato::Candidato(int id, std::string nome)
: id(id), nome(nome), jaPerguntou(false)
{
    // TODO: verificar id > 0 e nome.size() > 0, se não raise Exception
    this->microfone = new Microfone(id);
}

void Candidato::ligarMicrofone(void)
{
    this->microfone->ligar();
}

void Candidato::desligarMicrofone(void)
{
    this->microfone->desligar();
}

void Candidato::marcarComoInquiridor(void)
{
    this->jaPerguntou = true;
}

int Candidato::getId(void) const
{
    return this->id;
}

std::string Candidato::getNome(void) const
{
    return this->nome;
}

bool Candidato::getJaPerguntou(void) const
{
    return this->jaPerguntou;
}

