void IPMIServer(word port, byte *ip, word srcPort, const char *data, word len) {
 // IPAddress src(ip[0], ip[1], ip[2], ip[3]);
  Serial.print("Source: ");
  //Serial.print(src);
  Serial.print(":");
  Serial.println(port);
  printIPMIPacket(data, len);
  decodeAndReply(data, len);
}


void decodeAndReply(const char *data, word len){

  if (data[RMCP_HEADER_OFFSET_VERSION] == RMCP_HEADER_VERSION) {
    if (data[RMCP_HEADER_OFFSET_RESERVED] == RMCP_HEADER_RESERVED)  {

      respondToASF(data, len);
    }      


    else {
      Serial.println("here3");
    }
  }
  else {
    Serial.println("here4");
  }


}


void respondToASF(const char *data, word len) {
  Serial.println("Got an ASF packet");
  //ether.sendUdp("textToSend", sizeof("textToSend"), RMCP_UDP_PORT, ether.hisip, dstPort ); 
}




