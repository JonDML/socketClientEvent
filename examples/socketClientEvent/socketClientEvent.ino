#include <SPI.h>
#include <Ethernet.h>
#include <socketClientEvent.h>

byte mac[]  = {  0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xED };
byte ip[]   = { 192, 168, 2, 2 };

String f()  {  Serial.println("se llamo a f");   return ""; }

String f1() {  Serial.println("se llamo a f1");  return ""; }

String f2() {  Serial.println("se llamo a f2");  return ""; }

String f3() {  Serial.println("se llamo a f3");  return ""; }

EthernetServer server(23);
socketClientEvent sc = socketClientEvent(server);


void setup() {
  
  Serial.begin(9600);  
  Ethernet.begin(mac, ip);

  sc.on('a', f);
  sc.on('1', f1);
  sc.on('2', f2);
  sc.on('3', f3);
  sc.on('c', f);
  
}


void loop() {
    
  sc.listener();
}
