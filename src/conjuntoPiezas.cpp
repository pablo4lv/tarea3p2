#include "../include/conjuntoPiezas.h"

struct rep_conjuntopiezas{
    int* ids;
    int cantidad;
    int max;
};

TConjuntoPiezas crearTConjuntoPiezas(int cantMax){
    TConjuntoPiezas nuevo = new rep_conjuntopiezas;
    nuevo->ids = new int[cantMax];
    for (int i = 0; i < cantMax; i++){
        nuevo->ids[i] = 0;
    }
    nuevo->cantidad = 0;
    nuevo->max = cantMax;
    return nuevo;
}

bool esVacioTConjuntoPiezas(TConjuntoPiezas c){
    
    return false;
}

void insertarTConjuntoPiezas(TConjuntoPiezas &c, int id){
    if (id < c->max){
        if (c->ids[id] != 1){
            c->ids[id] = 1;
            c->cantidad++;
        }
    }
}

void borrarDeTConjuntoPiezas(TConjuntoPiezas &c, int id){}

bool perteneceTConjuntoPiezas(TConjuntoPiezas c, int id){ return false; }

int cardinalTConjuntoPiezas(TConjuntoPiezas c){ return 0; }

int cantMaxTConjuntoPiezas(TConjuntoPiezas c){ return 0; }

void imprimirTConjuntoPiezas(TConjuntoPiezas c){
    for (int i = 0; i < c->max; i++){
        if(c->ids[i] == 1){
            printf("%i ",i);
        }
    }
    printf("\n");   
}

void liberarTConjuntoPiezas(TConjuntoPiezas &c){
    delete[] c->ids;
    delete c;
    c = NULL;
}

TConjuntoPiezas unionTConjuntoPiezas(TConjuntoPiezas c1, TConjuntoPiezas c2){ return NULL; }

TConjuntoPiezas interseccionTConjuntoPiezas(TConjuntoPiezas c1, TConjuntoPiezas c2){ return NULL; }

TConjuntoPiezas diferenciaTConjuntoPiezas(TConjuntoPiezas c1, TConjuntoPiezas c2){ return NULL; }
