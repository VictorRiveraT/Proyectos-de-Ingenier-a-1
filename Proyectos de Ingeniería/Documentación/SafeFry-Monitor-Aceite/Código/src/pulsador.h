#ifndef PULSADOR_H
#define PULSADOR_H

#include <Arduino.h>

class Pulsador {
private:
    int pin;
    volatile bool* flagPresionado;
    unsigned long ultimoTiempoCambio;
    unsigned long tiempoDebounce;
    
    static void IRAM_ATTR manejarInterrupcion();
    static volatile bool flagGlobal;
    static volatile unsigned long ultimoTiempoGlobal;
    
public:
    Pulsador(int pinBoton, unsigned long debounce = 200);
    void begin();
    bool presionado();  // Verifica si fue presionado
};

#endif