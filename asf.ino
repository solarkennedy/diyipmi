
void respondToASF(const char *data, word len, byte *ip, word port) {
  Serial.println("Got an ASF packet");

  //Hard coded ASF Pong. All I care about really
  char reply[] = { 0x06, 0x00, 0xff, 0x06, 0x00, 0x00, 0x11, 0xbe, 0x40, 0x00, 0x00, 0x10, 0x00, 0x00, 0x11, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
  ether.sendUdp(reply, sizeof(reply), RMCP_UDP_PORT, ip, port );
  Serial.print("Sent a reply to ");
  IPAddress dst(ip[0], ip[1], ip[2], ip[3]);
  Serial.print(dst);
  Serial.print(":");
  Serial.println(port);
}
