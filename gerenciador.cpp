#include "gerenciador.h"

std::map<int, astronauta*> gerenciador::astronautas;
std::map<int, voo*> gerenciador::voos;
int gerenciador::numastronautas = 0;
int gerenciador::numvoos = 0;
std::map<int, astronauta*> gerenciador::astronautas_mortos;
std::map<int, voo*> gerenciador::voos_destruidos;
int gerenciador::numastronautas_mortos = 0;
int gerenciador::numvoos_destruidos = 0;


gerenciador::~gerenciador() {
    for (std::map<int, astronauta*>::iterator it = astronautas.begin(); it != astronautas.end(); it++){
        delete it->second;
    }
    astronautas.clear();
    for (std::map<int, voo*>::iterator it = voos.begin(); it != voos.end(); it++){
        delete it->second;
    }
    voos.clear();
}

void gerenciador::astronauta_criado(astronauta* tripulante){
    this->numastronautas += 1;
    astronautas.insert(std::make_pair(numastronautas, tripulante));
}

void gerenciador::voo_criado(voo* espaconave){
	this->numvoos += 1;
    voos.insert(std::make_pair(numvoos, espaconave));
}

void gerenciador::exibir_astronautas_vivos(){
    for (std::map<int, astronauta*>::iterator it = astronautas.begin(); it != astronautas.end(); it++){
    	if(it->second->checar_status() == false){
    		continue;
    	}
        std::cout << it->first << " => ";
        it->second->exibir_nome();
    }
}

void gerenciador::exibir_voos_aguardando(){
	for (std::map<int, voo*>::iterator it = voos.begin(); it != voos.end(); it++){
		if(it->second->esta_voando() == true){
			continue;
		}
        std::cout << it->first << " => ";
        it->second->get_codigo();
        std::cout << std::endl;
    }
}

void gerenciador::exibir_voos_com_astronautas(){
    for (std::map<int, voo*>::iterator it = voos.begin(); it != voos.end(); ++it) {
        if(it->second->get_trip_num() > 0) {
            std::cout << it->first << " => ";
            it->second->get_codigo();
            std::cout << std::endl;
        }
    }
}

bool gerenciador::checar_voos_com_astronautas(){
    for (std::map<int, voo*>::iterator it = voos.begin(); it != voos.end(); ++it) {
        if(it->second->get_trip_num () > 0) {
            return true;
        }
    }
    return false;
}

void gerenciador::exibir_voos_voando(){
	for (std::map<int, voo*>::iterator it = voos.begin(); it != voos.end(); it++){
		if(it->second->esta_voando() == true && it->second->get_trip_num() > 0){
			std::cout << it->first << " => ";
        	it->second->get_codigo();
        	std::cout << std::endl;
		}
		else{
			continue;
		}
    }
}

    void gerenciador::explodir_voo(voo* espaconave, int voo_escolhido) {
    espaconave->explodir();
    
    this->numvoos_destruidos += 1;
    this->numvoos -= 1;

    std::map<int, voo*>::iterator voo_explodido = this->voos.find(voo_escolhido);
    if (voo_explodido != this->voos.end()) {
        this->voos_destruidos.insert(std::make_pair(voo_escolhido, voo_explodido->second));
    }

    for (std::map<int, astronauta*>::iterator it = this->astronautas.begin(); it != this->astronautas.end();) {
        if (!it->second->checar_vida()) {
            this->numastronautas_mortos += 1;
            this->astronautas_mortos.insert(std::make_pair(numastronautas_mortos, it->second));
            std::map<int, astronauta*>::iterator temp = it;
            ++it;
            this->astronautas.erase(temp);
        } else {
            ++it;
        }
    }
}