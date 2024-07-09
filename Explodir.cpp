#include "Explodir.h"

void Explodir(gerenciador &a){
	int voo_escolhido;
	cout << "os voos em curso sao os seguintes. Escolha (digite o indice): " << endl;
	a.exibir_voos_voando();
	cout << "\n:";
    cin >> voo_escolhido;
    voo* b = a.voos[voo_escolhido];
    a.explodir_voo(b, voo_escolhido);
}