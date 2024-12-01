# **Sistema de Monitoramento CNC**

## **Descrição**
Este projeto é um sistema de monitoramento para máquinas CNC, desenvolvido com o ESP8266 e sensores precisos. Ele permite capturar, processar e transmitir dados das máquinas em tempo real, utilizando uma interface web para visualização e controle. O sistema emprega protocolos como MQTT e Modbus para comunicação eficiente e escalável.

---

## **Objetivo**
Monitorar o desempenho e o estado das máquinas CNC em tempo real, fornecendo dados críticos como temperatura, vibração, corrente e tensão. O sistema é capaz de gerar alertas, exibir gráficos e oferecer controles básicos diretamente pela interface web.

---

## **Tecnologias Utilizadas**
- **Hardware:**
  - ESP8266 (Microcontrolador com Wi-Fi integrado)
  - Sensores para monitoramento de:
    - Temperatura
    - Vibração
    - Tensão
    - Corrente
- **Protocolos de Comunicação:**
  - **MQTT:** Para troca de mensagens entre o ESP8266 e o servidor.
  - **Modbus:** Para integração direta com os controladores das máquinas CNC.
- **Software:**
  - **Arduino IDE:** Desenvolvimento e upload do código para o ESP8266.
  - **Broker MQTT (Mosquitto):** Servidor de mensagens para gerenciar os dados.
  - **HTML/CSS/JavaScript:** Interface web para visualização e controle.
  - **Node-RED/AWS IoT (opcional):** Para análise avançada e armazenamento de dados.

---

## **Principais Funcionalidades**
1. **Leitura de Dados Sensoriais:**
   - Monitoramento de temperatura, vibração, tensão e corrente em tempo real.
2. **Publicação MQTT:**
   - Dados enviados a um broker MQTT, organizados em tópicos específicos.
3. **Interface Web:**
   - Acesso via navegador na rede local.
   - Exibição de gráficos em tempo real e alertas de condições críticas.
   - Controle remoto básico, como reiniciar máquinas CNC ou redefinir alarmes.
4. **Notificações:**
   - Alertas configuráveis para condições críticas (ex.: superaquecimento ou vibração excessiva).

---

## **Configuração do Sistema**

### **1. Hardware**
- Instale o ESP8266 no sistema CNC.
- Conecte os sensores necessários (temperatura, vibração, etc.).
- Certifique-se de que o ESP8266 tenha alimentação elétrica adequada.

### **2. Configuração da Rede**
- Configure o ESP8266 para conectar-se à rede Wi-Fi:
  - SSID e senha da rede devem ser definidos no código.
- O endereço IP do ESP8266 será utilizado para acessar a interface web.

### **3. Broker MQTT**
- Configure um broker MQTT local ou na nuvem.
  - Recomenda-se o uso do Mosquitto.
  - Porta padrão: **1883**.
  - Exemplo de tópico MQTT: `CNC1/temperatura`.

### **4. Modbus**
- Configure a comunicação com as máquinas CNC para envio e recebimento de dados.

---

## **Instalação**

1. Clone este repositório:
   ```bash
   git clone https://github.com/seu-usuario/Sistema-de-Monitoramento-CNC.git
   cd Sistema-de-Monitoramento-CNC

## **Aplicações Futuras**

- **Manutenção Preditiva:** Uso de análise avançada para prever falhas antes que ocorram.
- **Integração com Nuvem:** Armazenamento centralizado e análise em larga escala.
- **Expansão:** Suporte a outros tipos de máquinas industriais.

## **Diferenciais**

- **Monitoramento em Tempo Real:** Atualizações instantâneas dos dados das máquinas.
- **Interface Web Intuitiva:** Visualização simples e acessível em qualquer navegador.
- **Escalabilidade:** Suporte para múltiplas máquinas CNC conectadas ao mesmo sistema.

## **Contribuindo**
Sinta-se à vontade para contribuir com este projeto. Envie pull requests ou abra issues para discutir melhorias e novas funcionalidades.

## **Licença**
Este projeto está licenciado sob a MIT License.

## **Contato*
*Autor:* Bruno HSS
*GitHub:* https://github.com/brunohss
*E-mail:* brunohss01@gmail.com
