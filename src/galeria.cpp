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
    nueva->coleccion = NULL;
    nueva->finalizadas = NULL;
    nueva->activas = NULL;
    nueva->futuras = NULL;
    nueva->fecha = fecha;
    return nueva;
}

void agregarPiezaTGaleria(TGaleria galeria, TPieza pieza){}

void agregarExposicionTGaleria(TGaleria galeria, TExposicion expo){}

void agregarPiezaAExposicionTGaleria(TGaleria galeria, int idPieza, int idExpo){}

void avanzarAFechaTGaleria(TGaleria galeria, TFecha fecha){}

void imprimirExposicionesFinalizadasTGaleria(TGaleria galeria){}

void imprimirExposicionesActivasTGaleria(TGaleria galeria){}

void imprimirExposicionesFuturasTGaleria(TGaleria galeria){}

bool esCompatibleExposicionTGaleria(TGaleria galeria, TExposicion expo){ return false; }

void liberarTGaleria(TGaleria &galeria){}
