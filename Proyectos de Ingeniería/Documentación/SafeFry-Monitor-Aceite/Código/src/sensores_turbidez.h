#ifndef SENSORES_TURBIDEZ_H
#define SENSORES_TURBIDEZ_H

#include <Arduino.h>

class SensorTurbidez {
private:
    HardwareSerial* serial;
    int pinRx;
    int pinTx;
    
    // Comando para solicitar lectura
    unsigned char comandoLectura[5] = {0x18, 0x05, 0x00, 0x01, 0x0D};
    unsigned char buffer[5];
    
    // Valores de calibración (RAW del sensor)
    int valorLimpio;    // Aceite limpio (valor ALTO, ej: 243)
    int valorSucio;     // Aceite sucio (valor BAJO, ej: 205)
    
    // Configuración de lecturas
    int numLecturas;    // Número de lecturas para promedio
    
public:
    // Constructor
    SensorTurbidez(HardwareSerial* serialPort, int rx, int tx);
    
    // Configuración
    void begin();
    void calibrar(int limpio, int sucio);
    void setNumLecturas(int num);
    
    // Lectura (ahora con promedio de 10 lecturas)
    int leerRaw();
    float leerPorcentajeSuciedad();
    
    // Utilidades
    String obtenerEstado();
    String obtenerEstadoDetallado(float porcentaje);
    bool disponible();
};

#endif