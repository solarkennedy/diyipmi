void printIPMIPacket(const char *data, word len) {
  Serial.print("RCMP HEADER: ");
  for (int i = 0; i <= 3;i++) {
    p("0x%02x ",data[i]);
  }
  Serial.println();

  Serial.print("IPMI SESSION: ");
  for (int i = 4; i <= 13;i++) {
    p("0x%02x ",data[i]);
  }
  Serial.println();

  Serial.print("IPMI CMD: ");
  for (int i = 14; i <= len;i++) {
    p("0x%02x ",data[i]);
  }
  Serial.println();
    Serial.print("Length: ");
  Serial.println(len);
  Serial.println();

}
