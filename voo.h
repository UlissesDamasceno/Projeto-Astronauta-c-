#ifndef VOO_H
#define VOO_H

#include "astronauta.h"
#include <list>

class voo {
private:
    bool voando;
    bool explodiu;
    int codigo;
    int numtripulantes;
    std::list<astronauta*> tripulantes;

public:
    voo(int codigo);
    ~voo();
    void explodir();
    void addtripulante(astronauta *tripulante);
    void get_codigo();
    int get_trip_num();
    void listar_tripulantes();
    void remover_tripulante(int num);
    void voar();
    int retornar_codigo();
    bool esta_voando();
    void pousar();
};

#endif