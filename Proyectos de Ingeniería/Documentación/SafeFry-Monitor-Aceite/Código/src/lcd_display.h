#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

class LCDDisplay {
private:
    LiquidCrystal_I2C* lcd;
    int sdaPin;
    int sclPin;
    uint8_t direccion;
    
public:
    LCDDisplay(uint8_t addr, int sda, int scl);
    
    // Configuración
    void begin();
    bool detectar();
    
    // Pantallas del sistema ORIGINAL
    void mostrarInicio();
    void mostrarEsperandoBoton();
    void mostrarIniciandoSistema();
    void mostrarLeyendoSensores();
    void mostrarResultados(int capacitanciaRaw, float capacitanciaPorcentaje, 
                          int turbidezRaw, float turbidezPorcentaje, 
                          bool sistemaApto);
    void mostrarPausado();
    void mostrarError(String mensaje);
    
    // ========== NUEVAS FUNCIONES PARA WiFi ==========
    void mostrarConectandoWiFi();
    void mostrarWiFiConectado(String ip);
    // ================================================
    
    // Control básico
    void limpiar();
    void backlight(bool encender);
};

#endif