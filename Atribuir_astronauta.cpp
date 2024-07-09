#include "atribuir_astronauta.h"

void atribuicao(gerenciador &a) {
	if(a.numastronautas == 0){
		cout << "Não há astronautas disponíveis" << endl;
		return;
	}
	if(a.numvoos == 0){
    	cout << "Não há voos disponíveis" << endl;
		return;
    }
    int nome_escolhido;
    int voo_escolhido;
    cout << "Estes sao os voos disponíveis. Escolha: " << endl;
    a.exibir_voos_aguardando();
    cout << "\n:";
    cin >> voo_escolhido;
    voo* b = a.voos[voo_escolhido];
    cout << "Estes são os astronautas disponíveis. Escolha (digite o índice): " << endl;
    a.exibir_astronautas_vivos();
    cout << ":";
    cin >> nome_escolhido;
    b->addtripulante(a.astronautas[nome_escolhido]);
}