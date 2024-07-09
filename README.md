
Projeto Gerenciador de Voos Espaciais
Este projeto em C++ simula um sistema de gerenciamento de voos espaciais, permitindo o cadastro de astronautas, criação de voos, gerenciamento de tripulações, e simulação de eventos como decolagens, pousos e explosões.

Funcionalidades
Cadastro de Astronautas: Adicione astronautas ao sistema com seus nomes e informações relevantes.
Criação de Voos: Crie voos espaciais, atribuindo códigos de identificação.
Gerenciamento de Tripulação: Associe astronautas a voos específicos.
Simulação de Eventos: Simule decolagens, pousos e explosões de voos, alterando o status dos voos e dos astronautas envolvidos.
Relatórios: Exiba informações sobre astronautas vivos, voos aguardando decolagem, voos em andamento e voos finalizados.
Estrutura do Projeto
gerenciador.h: Contém a classe Gerenciador, responsável por controlar as operações do sistema.
gerenciador.cpp: Implementação da classe Gerenciador.
astronauta.h: Contém a classe Astronauta, representando os astronautas.
astronauta.cpp: Implementação da classe Astronauta.
voo.h: Contém a classe Voo, representando os voos espaciais.
voo.cpp: Implementação da classe Voo.

Compilação: g++ -o executavel main.cpp Astronauta.cpp voo.cpp Atribuir_astronauta.cpp Cadastro_de_Astronautas.cpp Desatribuir_Astronauta.cpp Explodir.cpp gerenciador.cpp Lancar_voo.cpp 


