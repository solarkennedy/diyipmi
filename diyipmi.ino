#include <EEPROM.h>
#include <IPAddress.h>
#include <EtherCard.h>
#include <avr/wdt.h>
#include "libipmi.h"

#define CS_PIN 10

byte Ethernet::buffer[400];
byte mymac[] = { 
  0x74,0x69,0x69,0x2D,0x30,0x31 };

void setup () {
  init_network();
  ether.udpServerListenOnPort(&IPMIServer, 623);
}


void loop () {
  ether.packetLoop(ether.packetReceive());
}


#include <stdarg.h>
void p(char *fmt, ... ){
  char buf[128]; // resulting string limited to 128 chars
  va_list args;
  va_start (args, fmt );
  vsnprintf(buf, 128, fmt, args);
  va_end (args);
  Serial.print(buf);
}

