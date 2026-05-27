
#include "Fachada.h"

Fachada* Fachada::instance = nullptr;

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

void Fachada::configurarDebate(std::vector<Candidato*> cands, int tempos[N_FALAS])
{
    for (Candidato* c : cands) {
        gerenciador->addCandidato(c);
    }
    gerenciador->setTempos(tempos[0], tempos[1], tempos[2], tempos[3]);
}

int Fachada::sortearInquiridor(void)
{
    return gerenciador->sortearInquiridor();
}

void Fachada::definirInquirido(int idCandidato)
{
    gerenciador->definirInquirido(idCandidato);
}

/* @brief Inicia a primeira fase da primeira interação do debate.
 *
 * Espera-se que o inquiridor da primeira interação já tenha sido
 * sorteado e que inquirido já tenha sido definido.
 * Chama iniciarInteracao() para a primeira interação. */
void Fachada::iniciarDebate(void)
{
    // TODO: checar se inquirido, inquiridor e tempos foram definidos
    Fachada::instance->iniciarInteracao();
}

/* @brief Inicia a primeira fase de uma nova interação.
 *
 * Espera-se que o inquiridor da interação a iniciar já tenha
 * sido sorteado e que o inquirido já tenha sido definido. */
void Fachada::iniciarInteracao(void)
{
    gerenciador->iniciarFase();
}

/* @brief Prematuramente avança uma fase da interação corrente. */
//void avancarFase(void);

/* @brief Finaliza o debate oficialmente, causa geração do relatório. */
//void finalizarDebate(void);
