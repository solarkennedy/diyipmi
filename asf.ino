
void respondToASF(const char *data, word len, byte *srcip, word port) {
  Serial.println("Got an ASF packet");

  //Hard coded ASF Pong. All I care about really
  char reply[] = { 0x06, 0x00, 0xff, 0x06, 0x00, 0x00, 0x11, 0xbe, 0x40, 0x00, 0x00, 0x10, 0x00, 0x00, 0x11, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

  ether.sendUdp(reply, sizeof(reply), RMCP_UDP_PORT, srcip, port );
  Serial.print("Sent a ASF pong to ");
  // WHY IS THIS WRONG?
  IPAddress replydst(srcip[0], srcip[1], srcip[2], srcip[3]);
  Serial.print(replydst);
  Serial.print(":");
  Serial.println(port);
  Serial.println();

}
