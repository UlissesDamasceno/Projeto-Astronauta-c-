#include "Cadastro_de_Astronautas.h"

void Cadastro_de_Astronautas(gerenciador &a) {
    string cpf;
    string nome;
    int idade;
   
    cout << "Digite o CPF: ";
    cin >> cpf;
    cout << "Digite o nome: ";
    cin >> nome;
    cout << "Digite a idade: ";
    cin >> idade;
    astronauta *b = new astronauta(cpf, nome, idade);
    a.astronauta_criado(b);
}