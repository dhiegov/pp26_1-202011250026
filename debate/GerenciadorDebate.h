#ifndef GERENCIADOR_DEBATE_H
#define GERENCIADOR_DEBATE_H

#include <vector>

#include "Candidato.h"
#include "Cronometro.h"
#include "Logger.h"
#include "Mediador.h"

// pergunta, resposta, réplica e tréplica
#define N_FALAS 4

typedef enum {
    PERGUNTA = 0,
    RESPOSTA,
    REPLICA,
    TREPLICA
} fase_t;

class GerenciadorDebate : public Mediador
{
private:
    std::vector<Candidato*> candidatos;
    Candidato* inquiridor;
    Candidato* inquirido;
    Cronometro* cronometro;
    Logger* logger;
    fase_t faseAtual;
    int tempos[N_FALAS];
public:
    GerenciadorDebate();
    ~GerenciadorDebate();
    void addCandidato(Candidato* c);
    void setTempos(int perg, int resp, int repl, int trep);
    int sortearInquiridor(void);
    void definirInquirido(int id);
    void iniciarFase(void);
    void iniciarFase(int tempo);
    void registrarAcao(std::string acao);
    void proximaFase(void) override;
    void proximaFase(med_msg_sender_t sender) override;
private:
    int random(int a, int b) const;
};

#endif
