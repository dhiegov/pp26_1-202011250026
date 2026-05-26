#ifndef GERENCIADOR_DEBATE_H
#define GERENCIADOR_DEBATE_H

#include <vector>

#include "Candidato.h"
#include "Cronometro.h"
#include "Logger.h"
#include "Mediador.h"

// pergunta, resposta, réplica e tréplica
#define N_FALAS 4
#define MAX_CANDIDATOS 10

typedef enum {
    PERGUNTA = 0,
    RESPOSTA,
    REPLICA,
    TREPLICA
} fase_t;

class GerenciadorDebate : public Mediador
{
private:
    std::vector<Candidato> candidatos;
    Candidato* inquiridor;
    Candidato* inquirido;
    Cronometro* cronometro;
    Logger* logger;
    fase_t faseAtual;
    int tempos[N_FALAS];
public:
    GerenciadorDebate();
    ~GerenciadorDebate();
    int sortearInquiridor(void);
    void definirInquirido(int id);
    void iniciarFase(int tempo);
    void registrarAcao(std::string acao);
    void proximaFase(void) override;
};

#endif
