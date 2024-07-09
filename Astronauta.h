#ifndef ASTRONAUTAH
#define ASTRONAUTAH

#include <string>
#include <iostream>
#include <list>

using namespace std;

class astronauta{
private:
    string cpf;
    string nome;
    int idade;
    bool vivo;
    bool disponivel;
    int numvoos;
    std::list<int> voos;

public:
    astronauta(string cpf, std::string nome, int idade);
    ~astronauta();
    void morte();
    void voou(int cod);
    void exibir_nome();
    bool checar_status();
    bool checar_vida();
    
};

#endif