#include "../include/listaExposiciones.h"

struct rep_listaexposiciones{
    TExposicion exposicion;
    TListaExposiciones sig;
};

TListaExposiciones crearTListaExposicionesVacia(){
    return NULL;
}

void agregarExposicionTListaExposiciones(TListaExposiciones &listaExposiciones, TExposicion expo){
    TListaExposiciones nuevo = new rep_listaexposiciones;
    nuevo->exposicion = expo;
    nuevo->sig = NULL;

    //Si se inserta al principio, sea vacía o no la lista
    if (listaExposiciones == NULL || fechaInicioTExposicion(expo) < fechaInicioTExposicion(listaExposiciones->exposicion)){
        nuevo->sig = listaExposiciones;
        listaExposiciones = nuevo;
    } else {
        TListaExposiciones aux = listaExposiciones;
        while (aux->sig != NULL && fechaInicioTExposicion(expo) >= fechaInicioTExposicion(aux->sig->exposicion)){
            aux = aux->sig;
        }
        nuevo->sig = aux->sig;
        aux->sig = nuevo;
    }
}

bool perteneceExposicionTListaExposiciones(TListaExposiciones listaExposiciones, int idExpo){
    while (listaExposiciones != NULL){
        if(idTExposicion(listaExposiciones->exposicion) == idExpo){
            return true;
        }
        listaExposiciones = listaExposiciones->sig;
    }
    return false;
}

TExposicion obtenerExposicionTListaExposiciones(TListaExposiciones listaExposiciones, int idExpo){
    while (idTExposicion(listaExposiciones->exposicion) != idExpo){
        listaExposiciones = listaExposiciones->sig;
    }
    return listaExposiciones->exposicion;
}

bool esVaciaTListaExposiciones(TListaExposiciones listaExposiciones){
    return listaExposiciones == NULL;
}

void imprimirTListaExposiciones(TListaExposiciones listaExposiciones){
    while (listaExposiciones != NULL){
        imprimirTExposicion(listaExposiciones->exposicion);
        listaExposiciones = listaExposiciones->sig;
    }
}

void liberarTListaExposiciones(TListaExposiciones &listaExposiciones, bool liberarExposiciones){
    if (liberarExposiciones){
        while (listaExposiciones != NULL){
            TListaExposiciones aux = listaExposiciones;
            listaExposiciones = listaExposiciones->sig;
            liberarTExposicion(aux->exposicion);
            delete aux;
        }
    }
    listaExposiciones = NULL;
}

TListaExposiciones obtenerExposicionesFinalizadas(TListaExposiciones &listaExposiciones, TFecha fecha){ return NULL; }              

TListaExposiciones obtenerExposicionesActivas(TListaExposiciones &listaExposiciones, TFecha fecha){ return NULL; }

bool esCompatibleTListaExposiciones(TListaExposiciones listaExposiciones, TExposicion expo){ return false; }

TListaExposiciones unirListaExposiciones(TListaExposiciones listaExpo1, TListaExposiciones listaExpo2){ return NULL; }



