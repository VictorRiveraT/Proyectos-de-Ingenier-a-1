#ifndef SENSOR_CAPACITANCIA_H
#define SENSOR_CAPACITANCIA_H

#include <Arduino.h>

class SensorCapacitancia {
private:
    int pin;
    
    // Valores de calibración
    int valorAire;
    int valorAgua;
    int valorAceiteLimpio;
    int valorAceiteSucio;
    
    // Configuración de lectura
    int numLecturas;
    int delayLectura;
    
public:
    // Constructor
    SensorCapacitancia(int pinSensor);
    
    // Configuración
    void begin();
    void calibrar(int aire, int agua, int aceiteLimpio, int aceiteSucio);
    void setNumLecturas(int num);
    
    // Lectura (con promedio de 50 lecturas)
    int leerRaw();
    float leerPorcentaje();
    
    // Utilidades
    String obtenerEstado();
    String obtenerEstadoDetallado(float porcentaje);
};

#endif