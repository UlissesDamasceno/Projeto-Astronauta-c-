#include "voo.h"

voo::voo(int codigo){
	this->voando = false;
	this->explodiu = false;
	this->codigo = codigo;
	this->numtripulantes = 0;
}

voo::~voo(){
	tripulantes.clear();
}

void voo::explodir() {
    this->explodiu = true;
    this->voando = false;
    for (list<astronauta*>::iterator it = this->tripulantes.begin(); it != this->tripulantes.end(); it++) {
        if (*it) {  
            (*it)->morte(); 
        }
    }
}

void voo::addtripulante(astronauta *tripulante) {
	this->tripulantes.push_back(tripulante);
	this->numtripulantes += 1;
}

void voo::get_codigo(){
	cout << this->codigo;
}

int voo::retornar_codigo(){
	return this->codigo;
}

int voo::get_trip_num(){
	return this->numtripulantes;
}

void voo::listar_tripulantes() {
    int contador = 0;
    for (list<astronauta*>::iterator it = tripulantes.begin(); it != tripulantes.end(); ++it) {
        contador += 1;
        cout << contador << " => ";
        (*it)->exibir_nome();
        cout << endl;
    }
}


void voo::remover_tripulante(int num) {
    int contador = 0;
    for (list<astronauta*>::iterator it = tripulantes.begin(); it != tripulantes.end(); ++it) {
        contador += 1;
        if (num == contador) {
            it = tripulantes.erase(it);
            break; 
        }
    }
    this->numtripulantes -= 1;
}

bool voo::esta_voando(){
	return this->voando;
}

void voo::voar(){
	this->voando = true;
	for (list<astronauta*>::iterator it = tripulantes.begin(); it != tripulantes.end(); ++it) {
		(*it)->voou(this->retornar_codigo());
	}

}


