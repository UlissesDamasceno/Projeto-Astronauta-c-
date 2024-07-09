#ifndef GERENCIADOR_H
#define GERENCIADOR_H

#include "astronauta.h"
#include "voo.h"
#include <map>

class gerenciador {
public:
	static map<int, astronauta*> astronautas;
	static map<int, voo*> voos;
	static map<int, astronauta*> astronautas_mortos;
	static map<int, voo*> voos_destruidos;
	static int numastronautas;
	static int numvoos;
	static int numastronautas_mortos;
	static int numvoos_destruidos;
	static map<int, voo*> voos_finalizados;
	static int numvoos_finalizados;
	
	~gerenciador();
	void astronauta_criado(astronauta* tripulante);
	void voo_criado(voo* espaconave);
	void exibir_astronautas_vivos();
	void exibir_voos_aguardando();
	void exibir_voos_com_astronautas();
	bool checar_voos_com_astronautas();
	void exibir_voos_voando();
	void voo_destruido(voo* espaconave);
	void astronauta_morto(astronauta* tripulante);
	void explodir_voo(voo* espaconave, int voo_escolhido);
	void finalizar_voo(voo* espaconave, int voo_escolhido);
};

#endif