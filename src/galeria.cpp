#include "../include/galeria.h"

struct rep_galeria{
    TColeccionPiezas coleccion;
    TFecha fecha;
    TListaExposiciones finalizadas;
    TListaExposiciones activas;
    TListaExposiciones futuras;
};

TGaleria crearTGaleria(TFecha fecha){
    TGaleria nueva = new rep_galeria;
    nueva->coleccion = crearColeccionPiezasVacia();
    nueva->finalizadas = NULL;
    nueva->activas = NULL;
    nueva->futuras = NULL;
    nueva->fecha = fecha;
    return nueva;
}

void agregarPiezaTGaleria(TGaleria galeria, TPieza pieza){
    insertarPiezaColeccionPiezas(galeria->coleccion,pieza);
}

void agregarExposicionTGaleria(TGaleria galeria, TExposicion expo){
    if (compararTFechas(galeria->fecha,fechaInicioTExposicion(expo)) < 0){
        agregarExposicionTListaExposiciones(galeria->futuras, expo);
    } else {
        if (compararTFechas(galeria->fecha, fechaInicioTExposicion(expo)) >= 0){
            agregarExposicionTListaExposiciones(galeria->activas,expo);
        } else {
            agregarExposicionTListaExposiciones(galeria->finalizadas, expo);
        }
    }
}

void agregarPiezaAExposicionTGaleria(TGaleria galeria, int idPieza, int idExpo){
    TPieza pieza = obtenerPiezaColeccionPiezas(galeria->coleccion,idPieza);
    TExposicion destino = NULL;
    if (perteneceExposicionTListaExposiciones(galeria->activas, idExpo)){
        destino = obtenerExposicionTListaExposiciones(galeria->activas,idExpo);
    } else if (perteneceExposicionTListaExposiciones(galeria->futuras, idExpo)){
        destino = obtenerExposicionTListaExposiciones(galeria->futuras,idExpo);
    } else {
        destino = obtenerExposicionTListaExposiciones(galeria->finalizadas,idExpo);
    }
    agregarATExposicion(destino, pieza);
}

void avanzarAFechaTGaleria(TGaleria galeria, TFecha fecha){
    
}

void imprimirExposicionesFinalizadasTGaleria(TGaleria galeria){
    imprimirTListaExposiciones(galeria->finalizadas);
}

void imprimirExposicionesActivasTGaleria(TGaleria galeria){
    imprimirTListaExposiciones(galeria->activas);
}

void imprimirExposicionesFuturasTGaleria(TGaleria galeria){
    imprimirTListaExposiciones(galeria->futuras);
}

bool esCompatibleExposicionTGaleria(TGaleria galeria, TExposicion expo){
    
    return false;
}

void liberarTGaleria(TGaleria &galeria){
    liberarColeccionPiezas(galeria->coleccion);
    liberarTListaExposiciones(galeria->activas,true);
    liberarTListaExposiciones(galeria->finalizadas,true);
    liberarTListaExposiciones(galeria->futuras,true);
    liberarTFecha(galeria->fecha);
    delete galeria;
    galeria = NULL;
}
