#ifndef LOGGER_H
#define LOGGER_H

#include <vector>

class Logger
{
private:
    std::vector<std::string> logs;
public:
    void registrar(std::string acao);
    void gerarRelatorio(void);
};

#endif
