ModbusMaster node;

// Configuração do Modbus
#define MAX485_DE 2
#define MAX485_RE 2

void preTransmission() {
  digitalWrite(MAX485_RE, HIGH);
  digitalWrite(MAX485_DE, HIGH);
}

void postTransmission() {
  digitalWrite(MAX485_RE, LOW);
  digitalWrite(MAX485_DE, LOW);
}

void setupModbus() {
  pinMode(MAX485_RE, OUTPUT);
  pinMode(MAX485_DE, OUTPUT);
  digitalWrite(MAX485_RE, LOW);
  digitalWrite(MAX485_DE, LOW);

  node.begin(1, Serial);  // Endereço do dispositivo Modbus
  node.preTransmission(preTransmission);
  node.postTransmission(postTransmission);
}
