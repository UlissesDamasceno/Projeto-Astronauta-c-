#include "Astronauta.h"

astronauta::astronauta(string cpf, string nome, int idade){
	this->cpf = cpf;
	this->nome = nome;
	this->idade = idade;
	this->vivo = true;
	this->disponivel = true;
	this->numvoos = 0;
}

astronauta::~astronauta() {
	voos.clear();
}

void astronauta::morte(){
	this->vivo = false;
	this->disponivel = false;
}

void astronauta::voou(int cod) {
    this->voos.push_back(cod);
    this->disponivel = false;
    this->numvoos += 1;
}

void astronauta::exibir_nome(){
	std::cout << this->nome << std::endl;
}

bool astronauta::checar_status(){
	if(this->vivo == true && this->disponivel == true){
		return true;
	}
	else{
		return false;
	}
}

bool astronauta::checar_vida(){
	if(this->vivo == true){
		return true;
	}
	else{
		return false;
	}
}