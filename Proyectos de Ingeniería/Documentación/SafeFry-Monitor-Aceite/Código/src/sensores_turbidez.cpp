#include "sensores_turbidez.h"

// Constructor
SensorTurbidez::SensorTurbidez(HardwareSerial* serialPort, int rx, int tx) {
    serial = serialPort;
    pinRx = rx;
    pinTx = tx;
    
    // Valores por defecto (TUS mediciones reales)
    valorLimpio = 243;  // Aceite limpio
    valorSucio = 205;   // Aceite sucio
    
    // Configuración de lecturas
    numLecturas = 10;   // Por defecto 10 lecturas promediadas
}

// Inicializar sensor
void SensorTurbidez::begin() {
    serial->begin(9600, SERIAL_8N1, pinRx, pinTx);
    delay(100);
}

// Calibrar con valores medidos
void SensorTurbidez::calibrar(int limpio, int sucio) {
    valorLimpio = limpio;
    valorSucio = sucio;
}

// Verificar si hay datos disponibles
bool SensorTurbidez::disponible() {
    return serial->available() > 0;
}

// Leer valor RAW del sensor con promedio (0-255)
int SensorTurbidez::leerRaw() {
    const int numLecturas = 10;
    long suma = 0;
    int lecturasValidas = 0;
    
    for (int i = 0; i < numLecturas; i++) {
        // Limpiar buffer
        while (serial->available()) {
            serial->read();
        }
        
        // Enviar comando de lectura
        serial->write(comandoLectura, 5);
        
        // Esperar respuesta (timeout 500ms)
        unsigned long inicio = millis();
        while (serial->available() < 5 && (millis() - inicio) < 500) {
            delay(10);
        }
        
        // Verificar si hay datos suficientes
        if (serial->available() >= 5) {
            // Leer 5 bytes
            for (int j = 0; j < 5; j++) {
                buffer[j] = serial->read();
                delay(5);
            }
            
            // Acumular valor
            suma += buffer[3];
            lecturasValidas++;
        }
        
        delay(100); // Esperar entre lecturas
    }
    
    if (lecturasValidas > 0) {
        return suma / lecturasValidas;
    }
    
    return -1; // Error: sin respuesta
}

// Leer porcentaje de suciedad (0% = limpio, 100% = sucio)
float SensorTurbidez::leerPorcentajeSuciedad() {
    int valorRaw = leerRaw();
    
    if (valorRaw < 0) {
        return -1; // Error
    }
    
    // IMPORTANTE: El sensor da valores ALTOS para líquido LIMPIO
    // Por eso invertimos: 255 = 0% suciedad, 0 = 100% suciedad
    
    // Mapear usando los valores calibrados
    float porcentaje = map(valorRaw, valorLimpio, valorSucio, 0, 100);
    
    // Limitar entre 0-100
    if (porcentaje < 0) porcentaje = 0;
    if (porcentaje > 100) porcentaje = 100;
    
    return porcentaje;
}

// Obtener estado actual del aceite
String SensorTurbidez::obtenerEstado() {
    float porcentaje = leerPorcentajeSuciedad();
    
    if (porcentaje < 0) {
        return "ERROR";
    }
    
    return obtenerEstadoDetallado(porcentaje);
}

// Obtener estado detallado según porcentaje de suciedad
String SensorTurbidez::obtenerEstadoDetallado(float porcentaje) {
    if (porcentaje < 20) {
        return "EXCELENTE";
    } else if (porcentaje < 40) {
        return "BUENO";
    } else if (porcentaje < 60) {
        return "REGULAR";
    } else if (porcentaje < 80) {
        return "MALO";
    } else {
        return "MUY_MALO";
    }
}