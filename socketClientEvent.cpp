/*
  socketClientEvent.cpp - Librería para 
  la gestión de eventos de red
  Creada por Bego Septiembre'2014
  Lanzado bajo licencia MIT
*/

#include "arduino.h"
#include <Ethernet.h>
#include "socketClientEvent.h"

socketClientEvent::socketClientEvent(EthernetServer& server) { 

  if(lista == NULL) {
      lista = (Lista *) malloc (sizeof (Lista));
      inicializar(lista);
  }

  this->_server = &server;
}


int socketClientEvent::on (char dato, String (*callb)()) {

  Elemento *nuevo_elemento;
  
  if ((nuevo_elemento = (Elemento *) malloc (sizeof (Elemento))) == NULL)
    return -1;
  
  nuevo_elemento->dato = dato;
  nuevo_elemento->callb = callb;

  nuevo_elemento->siguiente = lista->inicio;
  lista->inicio = nuevo_elemento;

  return 0;
}


void socketClientEvent::inicializar (Lista *lista) {
      
  lista->inicio = NULL;
  lista->fin = NULL;
}


String socketClientEvent::disparar (char c) {

  Elemento *actual;
  actual = lista->inicio;

  while (actual != NULL) {
    if(actual->dato == c )
      return actual->callb();

    actual = actual->siguiente;
  }
}


void socketClientEvent::listener() {
  
  _cliente = _server->available();
  
  if (_cliente)
    while (_cliente.connected()) 
      _cliente.print(disparar(_cliente.read()));          


  _cliente.stop();  
}