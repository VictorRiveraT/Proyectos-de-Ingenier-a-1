#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoJson.h>
#include "sensor_capacitancia.h"
#include "sensores_turbidez.h"
#include "lcd_display.h"
#include "pulsador.h"

// ========== CONFIGURACIÓN WiFi ==========
const char* WIFI_SSID = "Redmi";
const char* WIFI_PASSWORD = "jesus123";

// ========== CONFIGURACIÓN UDP ==========
WiFiUDP udp;
const char* UDP_SERVER_IP = "10.172.94.8";  // IP de tu PC
const int UDP_SERVER_PORT = 1880;           // Puerto de Node-RED (recepción)
const int UDP_LOCAL_PORT = 1881;            // Puerto local ESP32 (escucha comandos)

// ========== CONFIGURACIÓN LCD ==========
LCDDisplay lcd(0x27, 21, 22);

// ========== CONFIGURACIÓN SENSORES ==========
SensorCapacitancia sensorCapacitivo(33);

HardwareSerial SerialTurbidez1(1);
SensorTurbidez sensorTurbidez1(&SerialTurbidez1, 16, 17);

HardwareSerial SerialTurbidez2(2);
SensorTurbidez sensorTurbidez2(&SerialTurbidez2, 27, 14);

// ========== CONFIGURACIÓN PULSADOR ==========
Pulsador boton(26);

// ========== UMBRALES DE DECISIÓN ==========
const float UMBRAL_CAPACITIVO = 50.0;
const float UMBRAL_TURBIDEZ = 40.0;

// ========== VARIABLES GLOBALES ==========
volatile bool sistemaPausado = true;
unsigned long intervaloMedicion = 5000;  // 5 segundos por defecto
unsigned long ultimaMedicion = 0;

struct DatosSensores {
    int capacitivoRaw;
    float capacitivoPorcentaje;
    String capacitivoEstado;
    bool capacitivoApto;
    
    int turbidez1Raw;
    int turbidez2Raw;
    float turbidezPromedio;
    String turbidezEstado;
    bool turbidezApto;
    
    bool sistemaApto;
    String decisionFinal;
};

DatosSensores datos;

// ========== LED INDICADOR WiFi ==========
const int LED_WIFI = 2;  // LED integrado ESP32

// ========== FUNCIONES WiFi ==========

void mostrarBannerWiFi() {
    Serial.println("\n╔════════════════════════════════════════════╗");
    Serial.println("║          CONECTANDO A WiFi...             ║");
    Serial.println("╚════════════════════════════════════════════╝");
    Serial.print("📡 Red: ");
    Serial.println(WIFI_SSID);
    Serial.print("🔑 Contraseña: ");
    Serial.println(WIFI_PASSWORD);
}

void conectarWiFi() {
    mostrarBannerWiFi();
    
    lcd.limpiar();
    lcd.mostrarConectandoWiFi();
    
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    
    int intentos = 0;
    while (WiFi.status() != WL_CONNECTED && intentos < 30) {
        delay(500);
        Serial.print(".");
        digitalWrite(LED_WIFI, !digitalRead(LED_WIFI));
        intentos++;
    }
    
    Serial.println();
    
    if (WiFi.status() == WL_CONNECTED) {
        digitalWrite(LED_WIFI, HIGH);
        
        Serial.println("\n✅ WiFi CONECTADO");
        Serial.print("📍 IP ESP32: ");
        Serial.println(WiFi.localIP());
        Serial.print("📊 Señal: ");
        Serial.print(WiFi.RSSI());
        Serial.println(" dBm");
        
        lcd.mostrarWiFiConectado(WiFi.localIP().toString());
        delay(2000);
        
        // Iniciar UDP
        udp.begin(UDP_LOCAL_PORT);
        Serial.print("🔌 UDP escuchando en puerto: ");
        Serial.println(UDP_LOCAL_PORT);
        Serial.print("📤 Enviando a: ");
        Serial.print(UDP_SERVER_IP);
        Serial.print(":");
        Serial.println(UDP_SERVER_PORT);
        
    } else {
        digitalWrite(LED_WIFI, LOW);
        
        Serial.println("\n❌ Error: No se pudo conectar a WiFi");
        Serial.println("⚠️ Continuando en modo OFFLINE");
        
        lcd.mostrarError("WiFi Error");
        delay(2000);
    }
}

void verificarWiFi() {
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("\n⚠️ WiFi desconectado. Reconectando...");
        conectarWiFi();
    }
}

// ========== FUNCIONES UDP ==========

void enviarDatosUDP() {
    if (WiFi.status() != WL_CONNECTED) return;
    
    // Crear JSON (ArduinoJson v7)
    JsonDocument doc;
    
    doc["timestamp"] = millis();
    doc["capacitancia_raw"] = datos.capacitivoRaw;
    doc["capacitancia"] = datos.capacitivoPorcentaje;
    doc["capacitancia_estado"] = datos.capacitivoEstado;
    doc["capacitancia_apto"] = datos.capacitivoApto;
    
    doc["turbidez1_raw"] = datos.turbidez1Raw;
    doc["turbidez2_raw"] = datos.turbidez2Raw;
    doc["turbidez_promedio_raw"] = (datos.turbidez1Raw + datos.turbidez2Raw) / 2;
    doc["turbidez"] = datos.turbidezPromedio;
    doc["turbidez_estado"] = datos.turbidezEstado;
    doc["turbidez_apto"] = datos.turbidezApto;
    
    doc["sistema_apto"] = datos.sistemaApto;
    doc["estado"] = datos.decisionFinal;
    doc["pausado"] = sistemaPausado;
    
    // Serializar
    String jsonString;
    serializeJson(doc, jsonString);
    
    // Enviar por UDP
    udp.beginPacket(UDP_SERVER_IP, UDP_SERVER_PORT);
    udp.print(jsonString);
    udp.endPacket();
    
    Serial.println("\n📤 Datos enviados por UDP:");
    Serial.println(jsonString);
}

void procesarComandosUDP() {
    int packetSize = udp.parsePacket();
    
    if (packetSize > 0) {
        char incomingPacket[255];
        int len = udp.read(incomingPacket, 255);
        
        if (len > 0) {
            incomingPacket[len] = '\0';
        }
        
        Serial.print("\n📥 Comando UDP recibido: ");
        Serial.println(incomingPacket);
        
        // Parsear JSON (ArduinoJson v7)
        JsonDocument doc;
        DeserializationError error = deserializeJson(doc, incomingPacket);
        
        if (error) {
            Serial.print("❌ Error parseando JSON: ");
            Serial.println(error.c_str());
            return;
        }
        
        String comando = doc["comando"].as<String>();
        
        if (comando == "pausar") {
            sistemaPausado = true;
            Serial.println("⏸️  Sistema PAUSADO por comando remoto");
            lcd.mostrarPausado();
            
        } else if (comando == "reanudar") {
            sistemaPausado = false;
            Serial.println("▶️  Sistema REANUDADO por comando remoto");
            lcd.mostrarIniciandoSistema();
            
        } else if (comando == "intervalo") {
            int nuevoIntervalo = doc["valor"];
            if (nuevoIntervalo >= 1000 && nuevoIntervalo <= 60000) {
                intervaloMedicion = nuevoIntervalo;
                Serial.print("⏱️  Intervalo cambiado a: ");
                Serial.print(intervaloMedicion);
                Serial.println(" ms");
            }
        }
    }
}

// ========== FUNCIONES PRINCIPALES ==========

void inicializarLCD() {
    Serial.println("\n=== Inicializando LCD ===");
    lcd.begin();
    
    if (lcd.detectar()) {
        Serial.println("✅ LCD detectado en 0x27");
    } else {
        Serial.println("⚠️ LCD no detectado - Verificar conexiones");
    }
    
    lcd.mostrarInicio();
    delay(2000);
}

void inicializarSensores() {
    Serial.println("\n=== Inicializando Sensores ===");
    
    sensorCapacitivo.begin();
    sensorCapacitivo.calibrar(3430, 290, 3130, 3140);
    sensorCapacitivo.setNumLecturas(50);
    Serial.println("✅ Sensor capacitivo OK");
    
    sensorTurbidez1.begin();
    sensorTurbidez1.calibrar(243, 205);
    Serial.println("✅ Sensor turbidez 1 OK");
    
    sensorTurbidez2.begin();
    sensorTurbidez2.calibrar(243, 205);
    Serial.println("✅ Sensor turbidez 2 OK");
}

void leerSensores() {
    lcd.mostrarLeyendoSensores();
    
    Serial.println("\n╔════════════════════════════════════════════╗");
    Serial.println("║         LEYENDO SENSORES SAFEFRY          ║");
    Serial.println("╚════════════════════════════════════════════╝");
    
    // ===== SENSOR CAPACITIVO =====
    Serial.println("\n📊 SENSOR CAPACITIVO:");
    datos.capacitivoRaw = sensorCapacitivo.leerRaw();
    datos.capacitivoPorcentaje = sensorCapacitivo.leerPorcentaje();
    datos.capacitivoEstado = sensorCapacitivo.obtenerEstadoDetallado(datos.capacitivoPorcentaje);
    datos.capacitivoApto = (datos.capacitivoPorcentaje < UMBRAL_CAPACITIVO);
    
    Serial.print("  RAW: ");
    Serial.print(datos.capacitivoRaw);
    Serial.print(" | Degradación: ");
    Serial.print(datos.capacitivoPorcentaje, 1);
    Serial.print("% | Estado: ");
    Serial.print(datos.capacitivoEstado);
    Serial.print(" | ");
    Serial.println(datos.capacitivoApto ? "✅ APTO" : "❌ NO APTO");
    
    // ===== SENSORES DE TURBIDEZ =====
    Serial.println("\n🌊 SENSORES DE TURBIDEZ:");
    datos.turbidez1Raw = sensorTurbidez1.leerRaw();
    float turbidez1Porcentaje = (datos.turbidez1Raw >= 0) ? sensorTurbidez1.leerPorcentajeSuciedad() : -1;
    
    datos.turbidez2Raw = sensorTurbidez2.leerRaw();
    float turbidez2Porcentaje = (datos.turbidez2Raw >= 0) ? sensorTurbidez2.leerPorcentajeSuciedad() : -1;
    
    if (turbidez1Porcentaje >= 0 && turbidez2Porcentaje >= 0) {
        datos.turbidezPromedio = (turbidez1Porcentaje + turbidez2Porcentaje) / 2.0;
        Serial.print("  Sensor 1: ");
        Serial.print(datos.turbidez1Raw);
        Serial.print(" (");
        Serial.print(turbidez1Porcentaje, 1);
        Serial.println("%)");
        Serial.print("  Sensor 2: ");
        Serial.print(datos.turbidez2Raw);
        Serial.print(" (");
        Serial.print(turbidez2Porcentaje, 1);
        Serial.println("%)");
    } else if (turbidez1Porcentaje >= 0) {
        datos.turbidezPromedio = turbidez1Porcentaje;
        Serial.println("  ⚠️ Solo Sensor 1 funcionando");
    } else if (turbidez2Porcentaje >= 0) {
        datos.turbidezPromedio = turbidez2Porcentaje;
        Serial.println("  ⚠️ Solo Sensor 2 funcionando");
    } else {
        Serial.println("  ❌ Error: Ningún sensor responde");
        datos.turbidezPromedio = -1;
        datos.turbidezApto = false;
    }
    
    if (datos.turbidezPromedio >= 0) {
        datos.turbidezEstado = sensorTurbidez1.obtenerEstadoDetallado(datos.turbidezPromedio);
        datos.turbidezApto = (datos.turbidezPromedio < UMBRAL_TURBIDEZ);
        
        Serial.print("  Promedio: ");
        Serial.print(datos.turbidezPromedio, 1);
        Serial.print("% NTU | Estado: ");
        Serial.print(datos.turbidezEstado);
        Serial.print(" | ");
        Serial.println(datos.turbidezApto ? "✅ APTO" : "❌ NO APTO");
    }
    
    // ===== DECISIÓN FINAL =====
    datos.sistemaApto = datos.capacitivoApto && datos.turbidezApto;
    datos.decisionFinal = datos.sistemaApto ? "✅ APTO" : "❌ NO APTO";
    
    Serial.println("\n╔════════════════════════════════════════════╗");
    Serial.print("║        DECISIÓN FINAL: ");
    Serial.print(datos.decisionFinal);
    Serial.print(datos.sistemaApto ? "          " : "       ");
    Serial.println("║");
    Serial.println("╚════════════════════════════════════════════╝");
    
    if (!datos.sistemaApto) {
        Serial.println("\n⚠️ RAZONES:");
        if (!datos.capacitivoApto) {
            Serial.print("  • Alta degradación: ");
            Serial.print(datos.capacitivoPorcentaje, 1);
            Serial.println("%");
        }
        if (!datos.turbidezApto) {
            Serial.print("  • Alta turbidez: ");
            Serial.print(datos.turbidezPromedio, 1);
            Serial.println(" NTU");
        }
    }
    
    Serial.println();
}

// ========== SETUP ==========
void setup() {
    Serial.begin(115200);
    delay(2000);
    
    Serial.println("\n\n");
    Serial.println("╔════════════════════════════════════════════╗");
    Serial.println("║       SAFEFRY - SISTEMA DE MONITOREO      ║");
    Serial.println("║     Calidad de Aceite v2.0 WiFi + UDP     ║");
    Serial.println("╚════════════════════════════════════════════╝");
    
    // Inicializar LED WiFi
    pinMode(LED_WIFI, OUTPUT);
    digitalWrite(LED_WIFI, LOW);
    
    // Inicializar pulsador
    boton.begin();
    Serial.println("\n✅ Pulsador inicializado (GPIO 26)");
    
    // Inicializar LCD
    inicializarLCD();
    
    // Conectar WiFi
    conectarWiFi();
    
    // Inicializar sensores
    inicializarSensores();
    
    // Mostrar pantalla de espera
    lcd.mostrarEsperandoBoton();
    
    Serial.println("\n✅ Sistema listo");
    Serial.println("💡 Presiona el botón para INICIAR/PAUSAR mediciones");
    Serial.println("🌐 Dashboard disponible en: http://10.172.94.8:1880/ui\n");
}

// ========== LOOP ==========
void loop() {
    // Verificar WiFi periódicamente
    static unsigned long ultimaVerificacionWiFi = 0;
    if (millis() - ultimaVerificacionWiFi > 30000) {  // Cada 30 segundos
        verificarWiFi();
        ultimaVerificacionWiFi = millis();
    }
    
    // Procesar comandos UDP
    procesarComandosUDP();
    
    // Verificar botón físico
    if (boton.presionado()) {
        sistemaPausado = !sistemaPausado;
        
        if (sistemaPausado) {
            Serial.println("\n⏸️  ═══════════════════════════");
            Serial.println("        SISTEMA PAUSADO");
            Serial.println("   ═══════════════════════════\n");
            lcd.mostrarPausado();
        } else {
            Serial.println("\n▶️  ═══════════════════════════");
            Serial.println("        SISTEMA INICIADO");
            Serial.println("   ═══════════════════════════\n");
            lcd.mostrarIniciandoSistema();
        }
        
        delay(500);
    }
    
    // Ejecutar mediciones si está activo
    if (!sistemaPausado) {
        unsigned long tiempoActual = millis();
        
        if (tiempoActual - ultimaMedicion >= intervaloMedicion) {
            leerSensores();
            
            // Enviar datos por UDP
            enviarDatosUDP();
            
            // Calcular promedio RAW de turbidez
            int turbidezRawPromedio = (datos.turbidez1Raw + datos.turbidez2Raw) / 2;
            
            // Mostrar en LCD
            lcd.mostrarResultados(datos.capacitivoRaw, datos.capacitivoPorcentaje, 
                                 turbidezRawPromedio, datos.turbidezPromedio, 
                                 datos.sistemaApto);
            
            ultimaMedicion = tiempoActual;
        }
    } else {
        delay(50);
    }
}