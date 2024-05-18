#include "../include/exposicion.h"

struct rep_exposicion{
    int id;
    TFecha inicio;
    TFecha fin;
    TConjuntoPiezas conjunto;
};

TExposicion crearTExposicion(int idExp, TFecha ini, TFecha fin, int cantMax){
    TExposicion nuevo = new rep_exposicion;
    nuevo->id = idExp;
    nuevo->inicio = ini;
    nuevo->fin = fin;
    nuevo->conjunto = crearTConjuntoPiezas(cantMax);
    return nuevo;
}

void agregarATExposicion(TExposicion &exp, TPieza p){
    insertarTConjuntoPiezas(exp->conjunto, idTPieza(p));
}

bool perteneceATExposicion(TExposicion exp, TPieza p){ return false; }

int idTExposicion(TExposicion exp){ return 0; }

void imprimirTExposicion(TExposicion exp){
    printf("Exposicion #%i del %s al %s\n", exp->id, copiarTFecha(exp->inicio),copiarTFecha(exp->fin));
    printf("Piezas: ");
    imprimirTConjuntoPiezas(exp->conjunto);
    printf("\n");
}

TFecha fechaInicioTExposicion(TExposicion exp){ return NULL; }

TFecha fechaFinTExposicion(TExposicion exp){ return NULL; }

bool sonExposicionesCompatibles(TExposicion exp1, TExposicion exp2){ return false; }

void liberarTExposicion(TExposicion &exp){
    liberarTFecha(exp->inicio);
    liberarTFecha(exp->fin);
    liberarTConjuntoPiezas(exp->conjunto);
    delete exp;
    exp = NULL;
}

