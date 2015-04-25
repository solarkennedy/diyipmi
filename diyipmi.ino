#include <EEPROM.h>
#include <EtherCard.h>
#include <avr/wdt.h>

#define CS_PIN 10

byte Ethernet::buffer[700];
byte mymac[] = { 0x74,0x69,0x69,0x2D,0x30,0x31 };

void setup () {

  Serial.begin(115200);
  Serial.println(F("diyipmi Module Booting Up!"));
  if (ether.begin(sizeof Ethernet::buffer, mymac) == 0) 
    Serial.println(F("Failed to access Ethernet controller"));
  if (!ether.dhcpSetup())
    Serial.println(F("DHCP failed"));

  ether.printIp("IP:  ", ether.myip);
  ether.printIp("GW:  ", ether.gwip);  
  ether.printIp("DNS: ", ether.dnsip); 

}


void loop () {
}

