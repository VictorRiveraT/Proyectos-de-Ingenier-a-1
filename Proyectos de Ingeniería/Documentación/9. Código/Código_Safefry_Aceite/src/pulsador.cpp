#include "pulsador.h"

// Variables estáticas para la interrupción
volatile bool Pulsador::flagGlobal = false;
volatile unsigned long Pulsador::ultimoTiempoGlobal = 0;

Pulsador::Pulsador(int pinBoton, unsigned long debounce) {
    pin = pinBoton;
    tiempoDebounce = debounce;
    ultimoTiempoCambio = 0;
}

void IRAM_ATTR Pulsador::manejarInterrupcion() {
    unsigned long tiempoActual = millis();
    
    // Antirrebote por software
    if (tiempoActual - ultimoTiempoGlobal > 200) {
        flagGlobal = true;
        ultimoTiempoGlobal = tiempoActual;
    }
}

void Pulsador::begin() {
    pinMode(pin, INPUT_PULLDOWN);
    attachInterrupt(digitalPinToInterrupt(pin), manejarInterrupcion, RISING);
}

bool Pulsador::presionado() {
    if (flagGlobal) {
        flagGlobal = false;
        return true;
    }
    return false;
}