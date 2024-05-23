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
    if (listaExposiciones == NULL || compararTFechas(fechaInicioTExposicion(expo), fechaInicioTExposicion(listaExposiciones->exposicion)) <= 0){
        nuevo->sig = listaExposiciones;
        listaExposiciones = nuevo;
    } else {
        TListaExposiciones aux = listaExposiciones;
        while (aux->sig != NULL && compararTFechas(fechaInicioTExposicion(expo), fechaInicioTExposicion(aux->sig->exposicion)) > 0){
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

TListaExposiciones obtenerExposicionesFinalizadas(TListaExposiciones &listaExposiciones, TFecha fecha){
    TListaExposiciones res = NULL;

    //Si el primero finalizo
    while (listaExposiciones != NULL && compararTFechas(fecha,fechaFinTExposicion(listaExposiciones->exposicion)) == 1){
        TListaExposiciones movido = listaExposiciones;
        listaExposiciones = listaExposiciones->sig;
        movido->sig = res;
        res = movido;
    }

    //Luego del primero
    TListaExposiciones aux = listaExposiciones;
    while (aux != NULL && aux->sig != NULL){
        TListaExposiciones aux2 = aux->sig;
        //  aux2 != NULL &&
        if ( compararTFechas(fecha,fechaFinTExposicion(aux2->exposicion)) == 1){
            aux->sig = aux2->sig;
            aux2->sig = res;
            res = aux2;
        } else {
            aux = aux->sig;
        }
    }

    return res;
}              

TListaExposiciones obtenerExposicionesActivas(TListaExposiciones &listaExposiciones, TFecha fecha){
    TListaExposiciones res = NULL;

    //Si el primero esta activo
    while (listaExposiciones != NULL && compararTFechas(fecha, fechaInicioTExposicion(listaExposiciones->exposicion)) >= 0 && compararTFechas(fechaFinTExposicion(listaExposiciones->exposicion),fecha) >= 0){
        TListaExposiciones movido = listaExposiciones;
        listaExposiciones = listaExposiciones->sig;
        movido->sig = NULL;
        agregarExposicionTListaExposiciones(res, movido->exposicion);
    }

    //Luego del primero
    TListaExposiciones aux = listaExposiciones;
    while (aux != NULL && aux->sig != NULL){
        TListaExposiciones aux2 = aux->sig;
        if (compararTFechas(fecha, fechaInicioTExposicion(aux2->exposicion)) >= 0 && compararTFechas(fechaFinTExposicion(aux2->exposicion),fecha) >= 0){
            aux->sig = aux2->sig;
            aux2->sig = NULL;
            agregarExposicionTListaExposiciones(res, aux2->exposicion);
        } else {
            aux = aux->sig;
        }
    }
    return res;
}

bool esCompatibleTListaExposiciones(TListaExposiciones listaExposiciones, TExposicion expo){ return false; }

TListaExposiciones unirListaExposiciones(TListaExposiciones listaExpo1, TListaExposiciones listaExpo2){ return NULL; }



