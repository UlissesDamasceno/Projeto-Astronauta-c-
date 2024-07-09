#include "Astronauta.h"
#include "voo.h"
#include "Cadastro_de_Astronautas.h"
#include "Cadastro_de_Voos.h"
#include "gerenciador.h"
#include "atribuir_astronauta.h"
#include "desatribuir_astronauta.h"
#include "Lancar_voo.h"
#include "Explodir.h"

int main(){
	gerenciador a;
	while(true){
		int escolha = 999;
		std::cout << std::endl;
		std::cout << "Digite o que deseja fazer: " << std::endl;
		std::cout << "0 - fechar o programa" << std::endl;
		std::cout << "1 - cadastro astronauta" << std::endl;
		std::cout << "2 - criar voo" << std::endl;
		std::cout << "3 - atribuir astronauta a voo" << std::endl;
		std::cout << "4 - desatribuir astronauta a voo" << std::endl;
		std::cout << "5 - lancar voo" << std::endl;
		std::cout << "6 - explodir voo" << std::endl;
		std::cin >> escolha;
		std::cout << std::endl;
		switch(escolha){
		case 0: return 0;
		case 1: Cadastro_de_Astronautas(a);std::cin.ignore();break;
		case 2: cadastro_de_Voos(a);std::cin.ignore();break;
		case 3: atribuicao(a);break;
		case 4: desatribuir(a);break;
		case 5: Lancar_voo(a);break;
		case 6: Explodir(a); break;
		}
	}

	return 0;
}