/*
socketClientEvent.h - Librería para 
la gestión de eventos de red
Creada por Bego Septiembre'2014
Lanzado bajo licencia MIT
*/

#ifndef socketClientEvent_h
#define socketClientEvent_h
#include "arduino.h"
#include <Ethernet.h>


typedef struct ElementoLista {

      char  dato;
      void  (*callb)();
      struct ElementoLista *siguiente;

}Elemento;


typedef struct ListaIdentificar {
      
      Elemento *inicio;
      Elemento *fin;
      
}Lista;


class socketClientEvent {

   private:
      Lista *lista;
      EthernetServer* _server;
      EthernetClient _cliente;
      void inicializar (Lista *lista);
      void disparar(char c);

   public:
      int on (char dato, void(*)());
      socketClientEvent(EthernetServer& server);
      void listener(); 
};

#endif