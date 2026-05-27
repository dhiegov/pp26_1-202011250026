
#include "Logger.h"

#include <iostream>
#include <string>

void Logger::registrar(std::string acao)
{
    if (acao.empty()) {
        return;
    }
    this->logs.push_back(acao);
    // debug
    std::cout << acao << std::endl;
}

void Logger::gerarRelatorio(void) const
{
    // TODO: gerar relatório para arquivo, sobrecarregando este método
    // com outro que aceita um nome de arquivo
    if (this->logs.empty()) {
        std::cout << "Relatório vazio, nenhuma ação registrada." << std::endl;
        return;
    }
    std::cout << "# Relatório do debate" << std::endl;
    std::cout << std::endl;
    // TODO: em GerenciadorDebate, ao adicionar cada Candidato ao
    // container de Candidatos, registrar em log algo como
    // "Participante adicionado: <nome do candidato> (<id>)"
    for (const std::string& log : logs) {
        std::cout << log << std::endl;
    }
}
