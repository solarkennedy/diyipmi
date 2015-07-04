void IPMIServer(word port, byte *ip, word srcPort, const char *data, word len) {
  IPAddress src(ip[0], ip[1], ip[2], ip[3]);
  Serial.print("Source: ");
  Serial.print(src);
  Serial.print(":");
  Serial.println(srcPort);
  printIPMIPacket(data, len);
  decodeAndReply(data, len, ip, srcPort);
}


void decodeAndReply(const char *data, word len, byte *ip, word port){

  IPAddress src(ip[0], ip[1], ip[2], ip[3]);
  Serial.print("Analyzing packet from ");
  Serial.println(src);

  if (data[RMCP_HEADER_OFFSET_VERSION] == RMCP_HEADER_VERSION) {
    if (data[RMCP_HEADER_OFFSET_RESERVED] == RMCP_HEADER_RESERVED)  {
      respondToASF(data, len, ip, port);
    }      


    else {
      Serial.println("here3");
    }
  }
  else {
    Serial.println("here4");
  }


}






