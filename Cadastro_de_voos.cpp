#include "Cadastro_de_Voos.h"

void Cadastro_de_Voos(gerenciador &a){
	int codigo;
	cout << "Digite o codigo do voo: " << endl;
	cout << ":";
	cin >> codigo;
	voo *b = new voo(codigo);
	a.voo_criado(b);
}