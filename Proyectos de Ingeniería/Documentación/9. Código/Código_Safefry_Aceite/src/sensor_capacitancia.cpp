#include "sensor_capacitancia.h"

// Constructor
SensorCapacitancia::SensorCapacitancia(int pinSensor) {
    pin = pinSensor;
    
    // Valores por defecto (deben ser calibrados)
    valorAire = 3430;
    valorAgua = 290;
    valorAceiteLimpio = 3130;
    valorAceiteSucio = 3140;
    
    // Configuración de lectura
    numLecturas = 50;
    delayLectura = 10;
}

// Inicializar sensor
void SensorCapacitancia::begin() {
    pinMode(pin, INPUT);
    analogReadResolution(12);
}

// Calibrar con valores medidos
void SensorCapacitancia::calibrar(int aire, int agua, int aceiteLimpio, int aceiteSucio) {
    valorAire = aire;
    valorAgua = agua;
    valorAceiteLimpio = aceiteLimpio;
    valorAceiteSucio = aceiteSucio;
}

// Configurar número de lecturas para promedio
void SensorCapacitancia::setNumLecturas(int num) {
    if (num > 0 && num <= 100) {
        numLecturas = num;
    }
}

// Leer valor RAW con promedio (50 lecturas por defecto)
int SensorCapacitancia::leerRaw() {
    long suma = 0;
    
    for (int i = 0; i < numLecturas; i++) {
        suma += analogRead(pin);
        delay(delayLectura);
    }
    
    return suma / numLecturas;
}

// Leer porcentaje de degradación (0% = limpio, 100% = sucio)
float SensorCapacitancia::leerPorcentaje() {
    int valorRaw = leerRaw();
    
    // IMPORTANTE: Como aceite limpio (3130) es MENOR que sucio (3140)
    // invertimos el mapeo para que limpio = 0% y sucio = 100%
    float porcentaje = map(valorRaw, valorAceiteSucio, valorAceiteLimpio, 0, 100);
    
    // Limitar entre 0-100
    if (porcentaje < 0) porcentaje = 0;
    if (porcentaje > 100) porcentaje = 100;
    
    return porcentaje;
}

// Obtener estado actual del aceite
String SensorCapacitancia::obtenerEstado() {
    float porcentaje = leerPorcentaje();
    return obtenerEstadoDetallado(porcentaje);
}

// Obtener estado detallado según porcentaje
String SensorCapacitancia::obtenerEstadoDetallado(float porcentaje) {
    if (porcentaje < 25) {
        return "EXCELENTE";
    } else if (porcentaje < 50) {
        return "BUENO";
    } else if (porcentaje < 75) {
        return "REGULAR";
    } else {
        return "MALO";
    }
}