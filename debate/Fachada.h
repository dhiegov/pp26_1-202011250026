#ifndef FACHADA_H
#define FACHADA_H

#include "GerenciadorDebate.h"
#include "Candidato.h"

// pergunta, resposta, réplica e tréplica
#define N_FALAS 4

class Fachada
{
private:
    static Fachada* instance;
    GerenciadorDebate* gerenciador;
    Fachada(); // singleton
public:
    static Fachada* getInstance(); // singleton

    /* @brief Configura os participantes e tempos de fala de todas interações. */
    void configurarDebate(const Candidato cands[], std::size_t n_cands, int tempos[N_FALAS]);

    /* @brief Retorna o id do Candidato sorteado para a próxima interação. */
    int sortearInquiridor(void);

    /* @brief Define o inquirido da próxima interação. */
    void definirInquirido(int idCandidato);

    /* @brief Inicia a primeira fase da primeira interação do debate.
     *
     * Espera-se que o inquiridor da primeira interação já tenha sido
     * sorteado e que inquirido já tenha sido definido.
     * Chama iniciarInteracao() para a primeira interação. */
    void iniciarDebate(void);

    /* @brief Inicia a primeira fase de uma nova interação.
     *
     * Espera-se que o inquiridor da interação a iniciar já tenha
     * sido sorteado e que o inquirido já tenha sido definido. */
    void iniciarInteracao(void);

    /* @brief Prematuramente avança uma fase da interação corrente. */
    void avancarFase(void);

    /* @brief Finaliza o debate oficialmente, causa geração do relatório. */
    void finalizarDebate(void);
};

#endif
