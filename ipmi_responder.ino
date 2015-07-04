
void respondToIPMI(const char *data, word len, byte *srcip, word port) {
  Serial.println("Got an IPMI packet");

  Serial.print("Function code: ");
  Serial.println(data[0], HEX);
  switch (data[0]) {
    case IPMI_NETFN_APP:
      Serial.println("  Handling APP stuff");
      Serial.print("  Command: ");
      Serial.println(data[19], HEX);
      switch (data[19]) {
        case IPMI_CMD_GET_CHAN_AUTH_CAPA: {
            return ipmi_app_auth_capa(srcip, port);
          }
        case IPMI_CMD_GET_SESS_CHALLENGE: {
            return ipmi_app_get_sess_challenge(srcip, port);
          }
        default: {
            Serial.println("Unknown command");
          }
      }
      return;
    default: {
        Serial.println("Unknown function code");
      }
  }
}

