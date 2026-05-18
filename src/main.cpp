// ESP32 ThingsBoard - EasyThingsBoard baseada no código que funciona!
// Agora é MUITO mais simples mas mantém todos os callbacks!

#include <Arduino.h>
#include <EasyThingsBoard.h>

// ===== CONFIGURAÇÕES =====
const char *WIFI_SSID = "CURTOCIRCUITO";
const char *WIFI_PASSWORD = "Curto@1020";
const char *TB_TOKEN = "odiDQPrSXYfpZ9Lc6lXz";
const char *TB_SERVER = "lab.curtocircuito.com.br";
const int TB_PORT = 1883;
const int LED_PIN = 2;

// ===== BIBLIOTECA =====
EasyThingsBoard tb;

void setup()
{
    Serial.begin(115200);
    Serial.println("EasyThingsBoard - Super Simples!");

    // ===== CONECTAR =====
    tb.connect(WIFI_SSID, WIFI_PASSWORD, TB_TOKEN, TB_SERVER, TB_PORT);
    tb.setupLED(LED_PIN); // Já adiciona setState/getState automaticamente!

    Serial.println("✅ Sistema pronto!");
}

void loop()
{
    tb.loop();
    tb.sendTelemetry("temperatura", 25.5f);          // 'f' especifica float
    delay(3000);
}
