#include "Desatribuir_Astronauta.h"

void desatribuir(gerenciador &a){
    if(a.checar_voos_com_astronautas() == false){
      cout << "não há voos com astronautas" <<endl;
        return;
    }
	int nome_escolhido;
    int voo_escolhido;
   cout << "Estes sao os voos que já tem astronautas. Escolha: " << endl;
    a.exibir_voos_com_astronautas();
   cout << "\n:";
   cin >> voo_escolhido;
    voo* b = a.voos[voo_escolhido];
    cout << "Estes sao os astronautas disponíveis. Escolha: " << endl;
    b->listar_tripulantes();
  cout << ":";
    cin >> nome_escolhido;
    b->remover_tripulante(nome_escolhido);
}