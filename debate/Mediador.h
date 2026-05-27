#ifndef MEDIADOR_H
#define MEDIADOR_H

// enum utilizado para identificar o objeto remetente da
// mensagem enviada ao Mediador. A alternativa de acordo
// com o Design Pattern não adaptado é que o objeto
// remetente envie a mensagem para Mediador passando
// um ponteiro ou referência a si mesmo (this). No entanto,
// visto que o tipo de ponteiro passado mudaria,
// seria necessário criar sobrecargas de métodos
// no Mediador concreto (aqui, GerenciadorDebate)
// para cada tipo de Colaborador, mesmo quando
// o mediador concreto não utiliza essa informação.
// Utilizando um enum, basta uma sobrecarga que aceite
// med_msg_sender_t e o Mediador concreto pode
// ignorar os valores que não lhe interessam.
//
// No momento apenas CRONOMETRO está definido por
// ele ser o único a chamar o Mediador concreto;
// nesse caso, para avançar a fase quando o tempo
// de fala de um candidato expirar.
typedef enum {
    CRONOMETRO
} med_msg_sender_t;

// interface
// Mediator do Design Pattern Mediator, ver Colaborador.h
class Mediador
{
public:
    // proximaAcao no diagrama base, renomeado para
    // melhor indicar o que é feito.
    void virtual proximaFase(void) = 0;
    void virtual proximaFase(med_msg_sender_t sender) = 0;
};

#endif
