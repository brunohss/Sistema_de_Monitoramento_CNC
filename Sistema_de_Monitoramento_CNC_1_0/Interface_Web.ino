String generateHTML() {
  String html = "<html><head><title>CNC Monitor</title>";
  html += "<style>body { font-family: Arial; text-align: center; }</style></head>";
  html += "<body><h1>Sistema de Monitoramento CNC</h1>";
  html += "<div><p>Temperatura: <span id='temp'>--</span> °C</p>";
  html += "<p>Vibração: <span id='vibration'>--</span> g</p>";
  html += "<p>Energia: <span id='energy'>--</span> W</p></div>";
  html += "<script>";
  html += "setInterval(() => { fetch('/data').then(res => res.json()).then(data => {";
  html += "document.getElementById('temp').innerText = data.temp;";
  html += "document.getElementById('vibration').innerText = data.vibration;";
  html += "document.getElementById('energy').innerText = data.energy;";
  html += "}); }, 1000);</script></body></html>";
  return html;
}
