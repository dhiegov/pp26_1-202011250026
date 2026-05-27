
#include "GerenciadorDebate.h"

#include <random>

GerenciadorDebate::GerenciadorDebate()
: tempos {0, 0, 0, 0}
{
    this->inquiridor = nullptr;
    this->inquirido = nullptr;
    this->cronometro = new Cronometro();
    this->cronometro->setMediador(this);
    this->logger = new Logger();
    this->faseAtual = PERGUNTA;
}

GerenciadorDebate::~GerenciadorDebate()
{
    delete this->cronometro;
    delete this->logger;
}

void GerenciadorDebate::addCandidato(Candidato* c)
{
    this->candidatos.push_back(c);
    this->registrarAcao("Candidato/a " + c->getNome() + " adicionado/a ao debate");
}

void GerenciadorDebate::setTempos(int perg, int resp, int repl, int trep)
{
    int temp[] = {perg, resp, repl, trep};
    for (int i=0; i < N_FALAS; i++) {
        this->tempos[i] = temp[i];
    }
    this->registrarAcao("Tempo para pergunta: " + std::to_string(perg) + " s");
    this->registrarAcao("Tempo para resposta: " + std::to_string(resp) + " s");
    this->registrarAcao("Tempo para réplica: " + std::to_string(repl) + " s");
    this->registrarAcao("Tempo para tréplica: " + std::to_string(trep) + " s");
}

int GerenciadorDebate::sortearInquiridor(void)
{
    if (this->faseAtual != PERGUNTA) {
        this->registrarAcao("ERRO: Tentativa de sortear inquiridor durante interação.");
        return -1;
    }
    std::vector<Candidato*> disponiveis;
    for (Candidato* c : this->candidatos) {
        if (! c->getJaPerguntou()) {
            disponiveis.push_back(c);
        }
    }
    if (disponiveis.empty()) {
        this->registrarAcao("Tentativa de sortear inquiridor depois que todos já foram inquiridores.");
        return -1;
    }
    int ultimo = disponiveis.size() - 1;
    int sorteado = this->random(0, ultimo);
    this->inquiridor = disponiveis[sorteado];
    this->inquiridor->marcarComoInquiridor();
    this->registrarAcao("Inquiridor sorteado: " + this->inquiridor->getNome());
    return this->inquiridor->getId();
}

void GerenciadorDebate::definirInquirido(int id)
{
    for (Candidato* c : this->candidatos) {
        if (c->getId() == id && c != this->inquiridor) {
            this->inquirido = c;
            this->registrarAcao("Inquirido definido: " + c->getNome());
            return;
        }
    }
    this->registrarAcao("Inquirido escolhido é o próprio inquiridor ou candidato não existe"
        " (id: " + std::to_string(id) + ")");
}

void GerenciadorDebate::iniciarFase()
{
    iniciarFase(this->tempos[this->faseAtual]);
}

void GerenciadorDebate::iniciarFase(int tempo)
{
    switch (this->faseAtual)
    {
        case PERGUNTA:
            this->registrarAcao("=== Interação: "
                + this->inquiridor->getNome()
                + " pergunta "
                + this->inquirido->getNome()
                + " ===");
        case REPLICA:
            this->inquiridor->ligarMicrofone();
            this->inquirido->desligarMicrofone();
            this->registrarAcao(" " + this->inquiridor->getNome() + " fala.");
        break;

        case RESPOSTA:
        case TREPLICA:
            this->inquiridor->desligarMicrofone();
            this->inquirido->ligarMicrofone();
            this->registrarAcao("                "
                + this->inquirido->getNome() + " fala.");
        break;

        default:
            this->inquiridor->desligarMicrofone();
            this->inquirido->desligarMicrofone();
            this->registrarAcao("ERRO: gerenciador->faseAtual inválida: "
                + std::to_string(this->faseAtual));
            return;
        break;
    }
    switch (this->faseAtual)
    {
        case PERGUNTA:
            this->registrarAcao("Fase iniciada: Pergunta"
                " ("+ std::to_string(tempo) + " s)");
        break;
        case RESPOSTA:
            this->registrarAcao("Fase iniciada: Resposta"
                " ("+ std::to_string(tempo) + " s)");
        break;
        case REPLICA:
            this->registrarAcao("Fase iniciada: Réplica"
                " ("+ std::to_string(tempo) + " s)");
        break;
        case TREPLICA:
            this->registrarAcao("Fase iniciada: Tréplica"
                " ("+ std::to_string(tempo) + " s)");
        break;
    }
    this->cronometro->iniciar(tempo);
}

void GerenciadorDebate::registrarAcao(std::string acao)
{
    this->logger->registrar(acao);
}

void GerenciadorDebate::proximaFase()
{
    switch (this->faseAtual)
    {
        case PERGUNTA:
            this->faseAtual = RESPOSTA;
            this->iniciarFase(this->tempos[RESPOSTA]);
        break;

        case RESPOSTA:
            this->faseAtual = REPLICA;
            this->iniciarFase((this->tempos[REPLICA]));
        break;

        case REPLICA:
            this->faseAtual = TREPLICA;
            this->iniciarFase((this->tempos[TREPLICA]));
        break;

        case TREPLICA:
            this->faseAtual = PERGUNTA;
            this->registrarAcao("___ Fim da tréplica: Interação terminada. ___");
        break;

        default:
            this->faseAtual = PERGUNTA;
        break;
    }
}

void GerenciadorDebate::proximaFase(med_msg_sender_t sender)
{
    switch (sender) {
        case CRONOMETRO:
            this->registrarAcao("Tempo expirado!");
        default:
            this->proximaFase();
        break;
    }
}

int GerenciadorDebate::random(int a, int b) const
{
    if (a == b) {
        return a;
    }
    std::random_device rd;   // seed
    std::mt19937 gen(rd());  // mersenne twister
    std::uniform_int_distribution<> dist(a, b); // de a até b inclusivo
    return dist(gen);
}

