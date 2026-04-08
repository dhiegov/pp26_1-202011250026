
#include <iostream>
#include <string>

class Implementador;

class Publicacao {
protected:
    Implementador *imp;
    std::string autor;
    std::string titulo;
public:
    virtual void obterDados(Implementador *i);
    virtual std::string getTitulo() = 0;
    virtual std::string getAutor() = 0;
};

class Livro : public Publicacao {
private:
    std::string isbn;
public:
    void obterDados(Implementador *i) override;
    std::string getISBN() { return this->isbn; }
    std::string getTitulo() { return this->titulo; }
    std::string getAutor() { return this->autor; }
};

class Revista : public Publicacao {
private:
    int n_artigos;
    std::string artigos[];
public:
    void obterDados(Implementador *i) override;
    std::string getArtigo(int id) {
        if (id > 0 && id < n_artigos)
            return artigos[id];
    }
    std::string getTitulo() { return this->titulo; }
    std::string getAutor() { return this->autor; }
};

class Implementador {
public:
    virtual void getDados(Publicacao *p) = 0;
    virtual void getDados(Livro *li) = 0;
    virtual void getDados(Revista *r) = 0;
};

// definir método de Publicacao após métodos de Implementador serem conhecidos
void Publicacao::obterDados(Implementador *i) {
    i->getDados(this);
}

// É necessário re-definir obterDados nas classes especializadas
// para que a chamada a getDados estaticamente e em tempo de compilação
// seja associada ao método sobrecarregado correspondente.
//
// Achei melhor do que utilizar dynamic_cast em Publicacao::obterDados
// para, em tempo de execução, tentar converter para um tipo especializado
// e se falhar, tentar para outros tipos especializados, e se falhar,
// indicando que seria uma instância duma publicação genérica mesmo,
// finalmente chamar getDados passando estaticamente um ponteiro
// para Publicacao. Esta alternativa requeriria a definição de Publicacao
// saber quais classes herdam dela para tentar converter dinamicamente
// para um ponteiro do tipo de cada uma, não escala bem.
void Livro::obterDados(Implementador *i) {
    i->getDados(this);
}

void Revista::obterDados(Implementador *i) {
    i->getDados(this);
}

class PublicacaoImplBD : public Implementador {
    void getDados(Publicacao *p) {
        std::cout << "Lendo dados de uma publicação genérica" << std::endl;
        std::cout << "    a partir de um Banco de Dados" << std::endl;
    }
    void getDados(Livro *li) {
        std::cout << "Lendo dados de um livro" << std::endl;
        std::cout << "    a partir de um Banco de Dados" << std::endl;
    }
    void getDados(Revista *r) {
        std::cout << "Lendo dados de uma revista" << std::endl;
        std::cout << "    a partir de um Banco de Dados" << std::endl;
    }
};

class PublicacaoImplXML : public Implementador {
    void getDados(Publicacao *p) {
        std::cout << "Lendo dados de uma publicação genérica" << std::endl;
        std::cout << "    a partir de um arquivo XML" << std::endl;
    }
    void getDados(Livro *li) {
        std::cout << "Lendo dados de um livro" << std::endl;
        std::cout << "    a partir de um arquivo XML" << std::endl;
    }
    void getDados(Revista *r) {
        std::cout << "Lendo dados de uma revista" << std::endl;
        std::cout << "    a partir de um arquivo XML" << std::endl;
    }
};

int main()
{
    Livro *li = new Livro();
    PublicacaoImplBD *imp = new PublicacaoImplBD();
    li->obterDados(imp);
    delete li;
    delete imp;
    return 0;
}
