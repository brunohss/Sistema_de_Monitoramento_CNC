float getTemperature() {
  uint8_t result = node.readInputRegisters(0x0001, 1);
  if (result == node.ku8MBSuccess) {
    return node.getResponseBuffer(0) / 10.0;
  }
  return -1; // Erro
}

float getVibration() {
  uint8_t result = node.readInputRegisters(0x0002, 1);
  if (result == node.ku8MBSuccess) {
    return node.getResponseBuffer(0) / 100.0;
  }
  return -1; // Erro
}

float getEnergy() {
  uint8_t result = node.readInputRegisters(0x0003, 1);
  if (result == node.ku8MBSuccess) {
    return node.getResponseBuffer(0);
  }
  return -1; // Erro
}

void callbackMQTT(char* topic, byte* payload, unsigned int length) {
  // Tratar comandos via MQTT
}
