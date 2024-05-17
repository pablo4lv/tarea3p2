#include "../include/visitaDia.h"

struct nodo{
	TGrupoABB grupo;
	nodo* anterior;
	nodo* siguiente;
};

struct coleccionGrupos {
    int contador;
	nodo* primero;
	nodo* ultimo;
};
struct rep_visitadia{
    TFecha fecha;
    coleccionGrupos* coleccion;
};

TVisitaDia crearTVisitaDia(TFecha fecha){
    TVisitaDia nuevo = new rep_visitadia;
    nuevo->fecha = fecha;
    nuevo->coleccion = new coleccionGrupos;
    nuevo->coleccion->primero = nuevo->coleccion->ultimo = NULL;
    nuevo->coleccion->contador = 0; 
    return nuevo;
}

void encolarGrupoTVisitaDia(TVisitaDia &visitaDia, TGrupoABB grupo){
    nodo* nuevo = new nodo;
    nuevo->grupo = grupo;
    if (visitaDia->coleccion->primero == NULL){
        visitaDia->coleccion->primero = visitaDia->coleccion->ultimo = nuevo;
        nuevo->anterior = nuevo->siguiente = NULL;
    } else {
        nuevo->siguiente = visitaDia->coleccion->primero;
        nuevo->anterior = NULL;
        visitaDia->coleccion->primero->anterior = nuevo;
        visitaDia->coleccion->primero = nuevo;
    }
    visitaDia->coleccion->contador++;
}

int cantidadGruposTVisitaDia(TVisitaDia visitaDia){
    return visitaDia->coleccion->contador; 
}

void imprimirVisitaDia(TVisitaDia visitaDia){
    printf("Visita para dia: ");
    imprimirTFecha(visitaDia->fecha);
    printf("\n");
    nodo* aux = visitaDia->coleccion->primero;
    while (aux != NULL){
        imprimirTGrupoABB(aux->grupo);
        aux = aux->siguiente;
    }
}

TGrupoABB desencolarGrupoTVisitaDia(TVisitaDia &visitaDia){
    nodo* aux = visitaDia->coleccion->ultimo;
    TGrupoABB ultimo = aux->grupo;
    visitaDia->coleccion->ultimo = aux->anterior;
    if (visitaDia->coleccion->ultimo != NULL){
        visitaDia->coleccion->ultimo->siguiente = NULL;
    }
    visitaDia->coleccion->contador--;
    // liberarTGrupoABB(aux->grupo);
    // delete aux;
    return ultimo;
}

void liberarTVisitaDia(TVisitaDia &visitaDia){
    nodo* aux = visitaDia->coleccion->primero;
    while (visitaDia->coleccion->primero != NULL){
        visitaDia->coleccion->primero = visitaDia->coleccion->primero->siguiente;
        liberarTGrupoABB(aux->grupo);
        delete aux;
        aux = visitaDia->coleccion->primero;
    }
    delete visitaDia->coleccion;
    liberarTFecha(visitaDia->fecha);
    delete visitaDia;
    visitaDia = NULL;
}

