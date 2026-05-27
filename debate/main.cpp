
#include <iostream>

#include "Fachada.h"

int main() {
	Fachada *f = Fachada::getInstance();
	Candidato *a = new Candidato(1, "Anaíza");
	Candidato *b = new Candidato(2, "Bruno");
	Candidato *c = new Candidato(3, "Camila");
	Candidato *d = new Candidato(4, "Douglas");

	std::vector<Candidato*> candidatos;
	candidatos.push_back(a);
	candidatos.push_back(b);
	candidatos.push_back(c);
	candidatos.push_back(d);

	int tempos[] = {2, 4, 3, 2};
	int inqridoPorInqridor[] = {0, 3, 3, 1, 2};

	f->configurarDebate(candidatos, tempos);
	int ridor;
	while (1) {
		ridor = f->sortearInquiridor();
		// sorteio resulta em -1 quando não há mais inquiridores
		if (ridor < 0) {
			std::cout << "Sem mais inquiridores! Debate terminado." << std::endl;
			break;
		}
		f->definirInquirido(inqridoPorInqridor[ridor]);
		f->iniciarInteracao();
	}
	return 0;
}

