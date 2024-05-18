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

bool perteneceATExposicion(TExposicion exp, TPieza p){
    return perteneceTConjuntoPiezas(exp->conjunto,idTPieza(p));
}

int idTExposicion(TExposicion exp){
    return exp->id;
}

void imprimirTExposicion(TExposicion exp){
    printf("Exposicion #%i del ", exp->id);
    imprimirTFecha(exp->inicio);
    printf(" al ");
    imprimirTFecha(exp->fin);
    printf("\n");
    printf("Piezas: ");
    imprimirTConjuntoPiezas(exp->conjunto);
}

TFecha fechaInicioTExposicion(TExposicion exp){
    return exp->inicio;
}

TFecha fechaFinTExposicion(TExposicion exp){
    return exp->fin;
}

bool sonExposicionesCompatibles(TExposicion exp1, TExposicion exp2){
    //Si se superponen
    if ((compararTFechas(exp1->fin,exp2->inicio) && (compararTFechas(exp1->inicio,exp2->fin))!=1) || compararTFechas(exp2->fin,exp1->inicio)){
        //y tienen piezas en comun
        TConjuntoPiezas interseccion = interseccionTConjuntoPiezas(exp1->conjunto,exp2->conjunto);
        if(!esVacioTConjuntoPiezas(interseccion)){
            liberarTConjuntoPiezas(interseccion);
            return false;
        }
        liberarTConjuntoPiezas(interseccion);
    }
    return true;
}

void liberarTExposicion(TExposicion &exp){
    liberarTFecha(exp->inicio);
    liberarTFecha(exp->fin);
    liberarTConjuntoPiezas(exp->conjunto);
    delete exp;
    exp = NULL;
}

