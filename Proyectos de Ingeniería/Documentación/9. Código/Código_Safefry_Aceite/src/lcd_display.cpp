#include "lcd_display.h"

LCDDisplay::LCDDisplay(uint8_t addr, int sda, int scl) {
    direccion = addr;
    sdaPin = sda;
    sclPin = scl;
    lcd = new LiquidCrystal_I2C(direccion, 16, 2);
}

void LCDDisplay::begin() {
    Wire.begin(sdaPin, sclPin);
    lcd->init();
    lcd->backlight();
    lcd->clear();
}

bool LCDDisplay::detectar() {
    Wire.beginTransmission(direccion);
    byte error = Wire.endTransmission();
    return (error == 0);
}

void LCDDisplay::mostrarInicio() {
    lcd->clear();
    lcd->setCursor(2, 0);
    lcd->print("SAFEFRY v1.1");
    lcd->setCursor(0, 1);
    lcd->print("Monitor Aceite");
    delay(2000);
    
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print("Inicializando");
    lcd->setCursor(0, 1);
    lcd->print("sensores...");
}

void LCDDisplay::mostrarEsperandoBoton() {
    lcd->clear();
    lcd->setCursor(1, 0);
    lcd->print("Presiona boton");
    lcd->setCursor(2, 1);
    lcd->print("para iniciar");
}

void LCDDisplay::mostrarIniciandoSistema() {
    lcd->clear();
    lcd->setCursor(2, 0);
    lcd->print("Iniciando...");
    lcd->setCursor(4, 1);
    lcd->print("Sistema");
    delay(1000);
}

void LCDDisplay::mostrarLeyendoSensores() {
    lcd->clear();
    lcd->setCursor(3, 0);
    lcd->print("Leyendo");
    lcd->setCursor(3, 1);
    lcd->print("sensores...");
}

void LCDDisplay::mostrarResultados(int capacitanciaRaw, float capacitanciaPorcentaje, 
                                    int turbidezRaw, float turbidezPorcentaje, 
                                    bool sistemaApto) {
    // ===== PANTALLA 1: Valores RAW + Porcentajes (3 segundos) =====
    lcd->clear();
    
    // Línea 1: Valores RAW
    lcd->setCursor(0, 0);
    lcd->print("C:");
    lcd->print(capacitanciaRaw);  // Valor RAW capacitancia
    
    lcd->setCursor(8, 0);
    lcd->print("T:");
    lcd->print(turbidezRaw);  // Valor RAW promedio turbidez
    
    // Línea 2: Porcentajes de degradación
    lcd->setCursor(0, 1);
    lcd->print((int)capacitanciaPorcentaje);
    lcd->print("%");
    
    lcd->setCursor(8, 1);
    lcd->print((int)turbidezPorcentaje);
    lcd->print("%");
    
    // Indicador de estado
    lcd->setCursor(14, 1);
    if (sistemaApto) {
        lcd->print("OK");
    } else {
        lcd->print("!!");
    }
    
    delay(3000);
    
    // ===== PANTALLA 2: Decisión final (2 segundos) =====
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print("DECISION FINAL:");
    
    lcd->setCursor(2, 1);
    if (sistemaApto) {
        lcd->print("*** APTO ***");
    } else {
        lcd->print("** NO APTO **");
    }
    
    delay(2000);
}

void LCDDisplay::mostrarPausado() {
    lcd->clear();
    lcd->setCursor(3, 0);
    lcd->print("SISTEMA");
    lcd->setCursor(3, 1);
    lcd->print("PAUSADO");
}

void LCDDisplay::mostrarError(String mensaje) {
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print("ERROR:");
    lcd->setCursor(0, 1);
    lcd->print(mensaje.substring(0, 16));
}

// ========== NUEVAS FUNCIONES PARA WiFi ==========

void LCDDisplay::mostrarConectandoWiFi() {
    lcd->clear();
    lcd->setCursor(1, 0);
    lcd->print("Conectando");
    lcd->setCursor(4, 1);
    lcd->print("WiFi...");
}

void LCDDisplay::mostrarWiFiConectado(String ip) {
    lcd->clear();
    lcd->setCursor(2, 0);
    lcd->print("WiFi OK!");
    lcd->setCursor(0, 1);
    
    // Mostrar IP completa si cabe, sino solo los últimos 16 caracteres
    if (ip.length() <= 16) {
        lcd->print(ip);
    } else {
        // Mostrar solo la parte final de la IP
        lcd->print(ip.substring(ip.length() - 16));
    }
}

// ================================================

void LCDDisplay::limpiar() {
    lcd->clear();
}

void LCDDisplay::backlight(bool encender) {
    if (encender) {
        lcd->backlight();
    } else {
        lcd->noBacklight();
    }
}