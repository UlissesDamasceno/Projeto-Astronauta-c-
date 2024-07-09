#include "gerenciador.h"

map<int, astronauta*> gerenciador::astronautas;
map<int, voo*> gerenciador::voos;
int gerenciador::numastronautas = 0;
int gerenciador::numvoos = 0;
map<int, astronauta*> gerenciador::astronautas_mortos;
map<int, voo*> gerenciador::voos_destruidos;
int gerenciador::numastronautas_mortos = 0;
int gerenciador::numvoos_destruidos = 0;
map<int, voo*> gerenciador::voos_finalizados; 
int gerenciador::numvoos_finalizados = 0;


gerenciador::~gerenciador() {
    for (map<int, astronauta*>::iterator it = astronautas.begin(); it != astronautas.end(); it++){
        delete it->second;
    }
    astronautas.clear();
    for (map<int, voo*>::iterator it = voos.begin(); it != voos.end(); it++){
        delete it->second;
    }
    voos.clear();
}

void gerenciador::astronauta_criado(astronauta* tripulante){
    this->numastronautas += 1;
    astronautas.insert(make_pair(numastronautas, tripulante));
}

void gerenciador::voo_criado(voo* espaconave){
	this->numvoos += 1;
    voos.insert(make_pair(numvoos, espaconave));
}

void gerenciador::exibir_astronautas_vivos(){
    for (map<int, astronauta*>::iterator it = astronautas.begin(); it != astronautas.end(); it++){
    	if(it->second->checar_status() == false){
    		continue;
    	}
        cout << it->first << " => ";
        it->second->exibir_nome();
    }
}

void gerenciador::exibir_voos_aguardando(){
	for (map<int, voo*>::iterator it = voos.begin(); it != voos.end(); it++){
		if(it->second->esta_voando() == true){
			continue;
		}
        cout << it->first << " => ";
        it->second->get_codigo();
        cout << endl;
    }
}

void gerenciador::exibir_voos_com_astronautas(){
    for (map<int, voo*>::iterator it = voos.begin(); it != voos.end(); ++it) {
        if(it->second->get_trip_num() > 0) {
            cout << it->first << " => ";
            it->second->get_codigo();
            cout << endl;
        }
    }
}

bool gerenciador::checar_voos_com_astronautas(){
    for (map<int, voo*>::iterator it = voos.begin(); it != voos.end(); ++it) {
        if(it->second->get_trip_num() > 0) {
            return true;
        }
    }
    return false;
}

bool gerenciador::exibir_voos_voando(){
    int a = 0;
	for (map<int, voo*>::iterator it = voos.begin(); it != voos.end(); it++){
		if(it->second->esta_voando() == true && it->second->get_trip_num() > 0){
			cout << it->first << " => ";
        	it->second->get_codigo();
        	cout << endl;
            a += 1;
		}
		else{
			continue;
		}
    }
    if(a == 0){
        cout << "Não há voos voando." << endl;
        return false;
    }
    else{
        return true;
    }
}

    void gerenciador::explodir_voo(voo* espaconave, int voo_escolhido) {
    espaconave->explodir();
    
    this->numvoos_destruidos += 1;
    this->numvoos -= 1;

    map<int, voo*>::iterator voo_explodido = this->voos.find(voo_escolhido);
    if (voo_explodido != this->voos.end()) {
        this->voos_destruidos.insert(make_pair(voo_escolhido, voo_explodido->second));
        this->voos.erase(voo_explodido);
    }

    for (map<int, astronauta*>::iterator it = this->astronautas.begin(); it != this->astronautas.end();) {
        if (!it->second->checar_vida()) {
            this->numastronautas_mortos += 1;
            this->astronautas_mortos.insert(make_pair(numastronautas_mortos, it->second));
            map<int, astronauta*>::iterator temp = it;
            ++it;
            this->astronautas.erase(temp);
        } else {
            ++it;
        }
    }
}

    