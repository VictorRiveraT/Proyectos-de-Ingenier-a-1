# SafeFry Pro - Sistema de Monitoreo de Calidad de Aceite

Sistema IoT profesional para monitoreo en tiempo real de la calidad del aceite de fritura mediante sensores capacitivos y de turbidez, con dashboard web interactivo y control remoto vía WiFi/UDP.

---

## Tabla de Contenidos

- [Características](#-características)
- [Requisitos](#-requisitos-del-sistema)
- [Instalación](#-instalación)
- [Documentación de Código](#-documentación-de-código)
- [Configuración](#-configuración)
- [Uso del Sistema](#-uso-del-sistema)
- [Dashboard Node-RED](#-dashboard-node-red)
- [API y Protocolos](#-api-y-protocolos)
- [Calibración de Sensores](#-calibración-de-sensores)
- [Solución de Problemas](#-solución-de-problemas)

---

## Características

### Funcionalidades Principales

-  **Monitoreo Multi-Sensor**: Medición simultánea de capacitancia y turbidez
-  **Conectividad WiFi**: Transmisión de datos en tiempo real
-  **Dashboard Web**: Interfaz gráfica profesional con Node-RED
-  **Control Remoto**: Pausa/reanuda mediciones desde cualquier dispositivo
-  **Display LCD**: Visualización local de datos y estado del sistema
-  **Toma de Decisiones**: Clasificación automática del aceite (Apto/No Apto)
-  **Histórico de Datos**: Gráficas temporales de evolución
-  **Sistema Modular**: Código organizado en clases reutilizables
-  **Calibración Flexible**: Ajuste de umbrales según tipo de aceite

### Sensores Implementados

| Sensor | Tipo | GPIO | Protocolo | Función |
|--------|------|------|-----------|---------|
| **Capacitivo** | Analógico | 25 | ADC 12-bit | Mide degradación molecular |
| **Turbidez 1** | Digital | 16/17 | UART (9600) | Detecta partículas suspendidas |
| **Turbidez 2** | Digital | 27/14 | UART (9600) | Redundancia y promediado |

### Interfaces de Usuario

1. **LCD 16x2 I2C**: Display físico local (tiempo real)
2. **Dashboard Web**: Interfaz gráfica accesible desde navegador
3. **Monitor Serial**: Logs detallados para debugging (115200 baudios)

---

## Requisitos del Sistema

### Hardware Necesario

#### Componentes Principales
- **Microcontrolador**: ESP32 DevKit (240MHz, 320KB RAM, WiFi integrado)
- **Display**: LCD 16x2 con módulo I2C (dirección 0x27)
- **Sensores**:
  - 1x Sensor capacitivo analógico (0-4095 ADC)
  - 2x Sensores de turbidez UART (protocolo propietario)
- **Entrada**: Pulsador momentáneo (pull-down)
- **Alimentación**: 5V/2A mínimo

### Software Necesario

#### En el ESP32
- **PlatformIO IDE**: v6.0 o superior (extensión VSCode)
- **Framework**: Arduino para ESP32 v3.x
- **Librerías**:
  - `ArduinoJson` v7.4.2+ (manejo de JSON)
  - `LiquidCrystal_I2C` v1.1.4+ (control LCD)
  - `WiFi` (integrado ESP32)
  - `WiFiUdp` (integrado ESP32)

#### En el Servidor (PC)
- **Node.js**: v14 LTS o superior
- **Node-RED**: v3.x
- **node-red-dashboard**: v3.6.6+

---

## Instalación

### 1. Configurar PlatformIO

```bash
# Instalar PlatformIO Core (si no está instalado)
pip install platformio

# O instalar la extensión en VSCode
# Buscar: "PlatformIO IDE" en el marketplace
```

### 2. Instalar Dependencias del ESP32

```bash
# Las dependencias se instalan automáticamente desde platformio.ini
pio pkg install

# Verificar instalación
pio pkg list
```

**Salida esperada:**
```
Library Manager
===============
ArduinoJson @ 7.4.2
LiquidCrystal_I2C @ 1.1.4
```

### 3. Configurar Node-RED

```bash
# Instalar Node-RED globalmente
npm install -g --unsafe-perm node-red

# Instalar Dashboard
npm install -g node-red-dashboard

# Iniciar Node-RED
node-red
```

### 4. Importar el Flow de Node-RED

1. Abrir navegador: `http://localhost:1880`
2. Menú ☰ → **Import** → **Clipboard**
3. Pegar el contenido de `nodered-flow.json`
4. Click **Import**
5. Click **Deploy** (botón rojo)

### 5. Configurar WiFi en el Código

Editar `src/main.cpp` (líneas 12-13):

```cpp
const char* WIFI_SSID = "TU_RED_WIFI";        // ← Cambiar
const char* WIFI_PASSWORD = "TU_CONTRASEÑA";  // ← Cambiar
```

Editar dirección IP del servidor (línea 17):

```cpp
const char* UDP_SERVER_IP = "192.168.1.XXX";  // ← IP de tu PC
```

### 6. Compilar y Subir al ESP32

```bash
# Compilar
pio run

# Subir al ESP32 (automáticamente detecta puerto)
pio run -t upload

# Abrir monitor serial
pio device monitor
```
---

## Documentación de Código

### `main.cpp` - Programa Principal

**Ubicación:** `src/main.cpp`

**Responsabilidades:**
- Orquestación de todo el sistema
- Conexión WiFi y gestión de red
- Comunicación UDP bidireccional
- Loop principal de medición
- Manejo de interrupciones del botón

**Estructura:**

```cpp
// ========== INCLUDES Y CONFIGURACIÓN ==========
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoJson.h>
#include "sensor_capacitancia.h"
#include "sensores_turbidez.h"
#include "lcd_display.h"
#include "pulsador.h"

// ========== CONFIGURACIÓN WiFi/UDP ==========
const char* WIFI_SSID = "...";
const char* WIFI_PASSWORD = "...";
const char* UDP_SERVER_IP = "...";
const int UDP_SERVER_PORT = 1880;
const int UDP_LOCAL_PORT = 1881;

// ========== INSTANCIAS DE OBJETOS ==========
LCDDisplay lcd(0x27, 21, 22);
SensorCapacitancia sensorCapacitivo(25);
// ... (otros sensores)

// ========== UMBRALES DE DECISIÓN ==========
const float UMBRAL_CAPACITIVO = 50.0;   // 50% degradación
const float UMBRAL_TURBIDEZ = 40.0;     // 40% turbidez

// ========== ESTRUCTURA DE DATOS ==========
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
```

**Funciones Principales:**

#### `void conectarWiFi()`
```cpp
// Conecta el ESP32 a la red WiFi configurada
// Muestra progreso en LCD y Serial
// Timeout: 30 intentos (15 segundos)
// Retorna: void (actualiza estado global)
```

#### `void enviarDatosUDP()`
```cpp
// Envía datos de sensores al servidor Node-RED
// Formato: JSON con 13 campos
// Protocolo: UDP unicast al puerto 1880
// Frecuencia: Según intervaloMedicion (default 5s)
```

#### `void procesarComandosUDP()`
```cpp
// Escucha comandos desde Node-RED en puerto 1881
// Comandos soportados:
//   - {"comando":"pausar"}
//   - {"comando":"reanudar"}
//   - {"comando":"intervalo", "valor":5000}
```

#### `void leerSensores()`
```cpp
// Lee todos los sensores y procesa datos
// 1. Lee sensor capacitivo (50 muestras promediadas)
// 2. Lee ambos sensores de turbidez (10 muestras c/u)
// 3. Calcula promedios y porcentajes
// 4. Determina estados (EXCELENTE/BUENO/REGULAR/MALO)
// 5. Toma decisión final (APTO/NO APTO)
```

**Loop Principal:**

```cpp
void loop() {
    // 1. Verificar WiFi cada 30 segundos
    verificarWiFi();
    
    // 2. Procesar comandos UDP entrantes
    procesarComandosUDP();
    
    // 3. Verificar botón físico (interrupción)
    if (boton.presionado()) {
        sistemaPausado = !sistemaPausado;
    }
    
    // 4. Ejecutar mediciones si está activo
    if (!sistemaPausado) {
        if (millis() - ultimaMedicion >= intervaloMedicion) {
            leerSensores();
            enviarDatosUDP();
            lcd.mostrarResultados(...);
            ultimaMedicion = millis();
        }
    }
}
```

---

###  `lcd_display.h/.cpp` - Control del Display LCD

**Ubicación:** `src/lcd_display.h` + `src/lcd_display.cpp`

**Descripción:**
Clase para manejar un LCD 16x2 con módulo I2C. Proporciona métodos para mostrar diferentes pantallas del sistema.

**Interfaz Pública:**

```cpp
class LCDDisplay {
public:
    LCDDisplay(uint8_t addr, int sda, int scl);
    
    // Configuración
    void begin();
    bool detectar();
    
    // Pantallas del sistema
    void mostrarInicio();
    void mostrarEsperandoBoton();
    void mostrarIniciandoSistema();
    void mostrarLeyendoSensores();
    void mostrarResultados(int capRaw, float capPorc, 
                          int turbRaw, float turbPorc, 
                          bool apto);
    void mostrarPausado();
    void mostrarError(String mensaje);
    
    // Pantallas WiFi
    void mostrarConectandoWiFi();
    void mostrarWiFiConectado(String ip);
    
    // Control básico
    void limpiar();
    void backlight(bool encender);
};
```

**Ejemplo de Uso:**

```cpp
LCDDisplay lcd(0x27, 21, 22);  // Dirección I2C, SDA, SCL

void setup() {
    lcd.begin();
    
    if (lcd.detectar()) {
        lcd.mostrarInicio();
    } else {
        lcd.mostrarError("LCD no detect");
    }
}
```

**Pantallas Implementadas:**

| Pantalla | Duración | Uso |
|----------|----------|-----|
| `mostrarInicio()` | 2s | Splash screen inicial |
| `mostrarConectandoWiFi()` | Variable | Durante conexión WiFi |
| `mostrarWiFiConectado(ip)` | 2s | Confirmación de conexión |
| `mostrarEsperandoBoton()` | Permanente | Espera inicio del usuario |
| `mostrarLeyendoSensores()` | 1s | Durante lectura |
| `mostrarResultados(...)` | 5s | Datos + decisión (alternante) |
| `mostrarPausado()` | Permanente | Sistema en pausa |

---

### `sensor_capacitancia.h/.cpp` - Sensor Capacitivo

**Ubicación:** `src/sensor_capacitancia.h` + `src/sensor_capacitancia.cpp`

**Descripción:**
Clase para leer y procesar un sensor capacitivo analógico que mide la degradación del aceite basándose en cambios en su constante dieléctrica.

**Principio de Funcionamiento:**
```
Aceite Fresco    →  Alta capacitancia (≈3130)  →  0% degradación
Aceite Degradado →  Baja capacitancia (≈3140)  →  100% degradación
```

**Interfaz Pública:**

```cpp
class SensorCapacitancia {
public:
    SensorCapacitancia(int pinSensor);
    
    // Configuración
    void begin();
    void calibrar(int aire, int agua, int limpio, int sucio);
    void setNumLecturas(int num);
    
    // Lectura
    int leerRaw();              // Valor ADC (0-4095)
    float leerPorcentaje();     // Degradación (0-100%)
    
    // Utilidades
    String obtenerEstado();
    String obtenerEstadoDetallado(float porcentaje);
};
```

**Calibración:**

```cpp
sensorCapacitivo.calibrar(
    3430,  // Valor en aire (máximo)
    290,   // Valor en agua (mínimo)
    3130,  // Aceite limpio
    3140   // Aceite degradado
);
```

**Algoritmo de Lectura:**

```cpp
int SensorCapacitancia::leerRaw() {
    long suma = 0;
    for (int i = 0; i < numLecturas; i++) {  // Default: 50
        suma += analogRead(pin);
        delay(10);  // 10ms entre muestras
    }
    return suma / numLecturas;  // Promedio
}

float SensorCapacitancia::leerPorcentaje() {
    int raw = leerRaw();
    // Mapeo inverso: limpio(3130)→0%, sucio(3140)→100%
    return map(raw, valorSucio, valorLimpio, 0, 100);
}
```

**Estados de Clasificación:**

| Porcentaje | Estado | Descripción |
|------------|--------|-------------|
| 0-24% | EXCELENTE | Aceite en condiciones óptimas |
| 25-49% | BUENO | Aceite apto, sin degradación significativa |
| 50-74% | REGULAR | Aceite con degradación moderada |
| 75-100% | MALO | Aceite altamente degradado, cambiar |

---

### `sensores_turbidez.h/.cpp` - Sensores de Turbidez

**Ubicación:** `src/sensores_turbidez.h` + `src/sensores_turbidez.cpp`

**Descripción:**
Clase para comunicarse con sensores de turbidez que usan protocolo UART propietario. Mide la cantidad de partículas suspendidas en el aceite.

**Protocolo de Comunicación:**

```
Comando de lectura (5 bytes):
[0x18] [0x05] [0x00] [0x01] [0x0D]
  ↓      ↓      ↓      ↓      ↓
 Start  Cmd   Addr  Length  End

Respuesta del sensor (5 bytes):
[0x??] [0x??] [0x??] [VALUE] [0x??]
                       ↑
                 Dato de turbidez (0-255)
```

**Interfaz Pública:**

```cpp
class SensorTurbidez {
public:
    SensorTurbidez(HardwareSerial* port, int rx, int tx);
    
    // Configuración
    void begin();
    void calibrar(int limpio, int sucio);
    void setNumLecturas(int num);
    
    // Lectura
    int leerRaw();                      // Valor (0-255)
    float leerPorcentajeSuciedad();    // Suciedad (0-100%)
    
    // Utilidades
    String obtenerEstado();
    String obtenerEstadoDetallado(float porcentaje);
    bool disponible();
};
```

**Calibración:**

```cpp
sensorTurbidez1.calibrar(
    243,  // Aceite limpio (valor alto)
    205   // Aceite sucio (valor bajo)
);
```

**Algoritmo de Lectura:**

```cpp
int SensorTurbidez::leerRaw() {
    long suma = 0;
    int lecturasValidas = 0;
    
    for (int i = 0; i < 10; i++) {  // 10 intentos
        // 1. Limpiar buffer
        while (serial->available()) serial->read();
        
        // 2. Enviar comando
        serial->write(comandoLectura, 5);
        
        // 3. Esperar respuesta (timeout 500ms)
        unsigned long inicio = millis();
        while (serial->available() < 5 && 
               (millis() - inicio) < 500) {
            delay(10);
        }
        
        // 4. Leer respuesta
        if (serial->available() >= 5) {
            for (int j = 0; j < 5; j++) {
                buffer[j] = serial->read();
            }
            suma += buffer[3];  // Byte de datos
            lecturasValidas++;
        }
        
        delay(100);  // Pausa entre lecturas
    }
    
    return (lecturasValidas > 0) ? 
           suma / lecturasValidas : -1;  // -1 = error
}
```

**Promediado de Sensores:**

```cpp
// En main.cpp
float turbidez1 = sensorTurbidez1.leerPorcentajeSuciedad();
float turbidez2 = sensorTurbidez2.leerPorcentajeSuciedad();

if (turbidez1 >= 0 && turbidez2 >= 0) {
    turbidezPromedio = (turbidez1 + turbidez2) / 2.0;  // Promedio
} else if (turbidez1 >= 0) {
    turbidezPromedio = turbidez1;  // Solo sensor 1
} else if (turbidez2 >= 0) {
    turbidezPromedio = turbidez2;  // Solo sensor 2
} else {
    turbidezPromedio = -1;  // Error total
}
```

---

### `pulsador.h/.cpp` - Control del Botón

**Ubicación:** `src/pulsador.h` + `src/pulsador.cpp`

**Descripción:**
Clase para manejar un pulsador con interrupciones y antirrebote por software.

**Interfaz Pública:**

```cpp
class Pulsador {
public:
    Pulsador(int pinBoton, unsigned long debounce = 200);
    void begin();
    bool presionado();  // Retorna true si fue presionado
    
private:
    static void IRAM_ATTR manejarInterrupcion();
    static volatile bool flagGlobal;
    static volatile unsigned long ultimoTiempoGlobal;
};
```

**Implementación del Antirrebote:**

```cpp
void IRAM_ATTR Pulsador::manejarInterrupcion() {
    unsigned long tiempoActual = millis();
    
    // Ignorar rebotes en 200ms
    if (tiempoActual - ultimoTiempoGlobal > 200) {
        flagGlobal = true;
        ultimoTiempoGlobal = tiempoActual;
    }
}

bool Pulsador::presionado() {
    if (flagGlobal) {
        flagGlobal = false;  // Reset flag
        return true;
    }
    return false;
}
```

**Configuración de Hardware:**

```
GPIO 26 ────┬──── Pulsador ──── VCC
            │
           ═╧═  10kΩ Pull-down
            │
           GND
```

---

## Configuración

### Configuración WiFi

Editar en `src/main.cpp`:

```cpp
// ========== CONFIGURACIÓN WiFi ==========
const char* WIFI_SSID = "TU_RED_WIFI";
const char* WIFI_PASSWORD = "TU_CONTRASEÑA";
```

**Requisitos:**
-  Red WiFi 2.4 GHz (ESP32 no soporta 5 GHz)
-  DHCP habilitado (asignación automática de IP)
-  Sin firewall que bloquee UDP

### Configuración UDP

```cpp
// ========== CONFIGURACIÓN UDP ==========
const char* UDP_SERVER_IP = "192.168.1.100";  // IP de tu PC
const int UDP_SERVER_PORT = 1880;             // Puerto entrada
const int UDP_LOCAL_PORT = 1881;              // Puerto escucha
```

**Verificar IP de tu PC:**

Windows:
```cmd
ipconfig
```

Linux/Mac:
```bash
ifconfig
```

### Configuración de Umbrales

```cpp
// ========== UMBRALES DE DECISIÓN ==========
const float UMBRAL_CAPACITIVO = 50.0;  // % degradación
const float UMBRAL_TURBIDEZ = 40.0;    // % turbidez
```

**Lógica de Decisión:**
```cpp
bool aptoCap = (capacitancia < UMBRAL_CAPACITIVO);
bool aptoTurb = (turbidez < UMBRAL_TURBIDEZ);
bool sistemaApto = aptoCap && aptoTurb;  // Ambos deben ser aptos
```

### Configuración de Sensores

#### Sensor Capacitivo
```cpp
sensorCapacitivo.begin();
sensorCapacitivo.calibrar(3430, 290, 3130, 3140);
sensorCapacitivo.setNumLecturas(50);  // 50 muestras
```

#### Sensores de Turbidez
```cpp
sensorTurbidez1.begin();
sensorTurbidez1.calibrar(243, 205);  // Limpio, Sucio

sensorTurbidez2.begin();
sensorTurbidez2.calibrar(243, 205);
```

---

## Uso del Sistema

### Inicio del Sistema

1. **Conexión de Hardware**
   - Conectar todos los sensores según diagrama
   - Conectar LCD I2C
   - Conectar pulsador
   - Alimentar ESP32 (5V/2A)

2. **Arranque Automático**
   ```
   [LCD] SAFEFRY v1.1
         Monitor Aceite
   
   [LCD] Conectando
         WiFi...
   
   [LCD] WiFi OK!
         192.168.1.123
   
   [LCD] Presiona boton
         para iniciar
   ```

3. **Iniciar Mediciones**
   - Presionar botón físico (GPIO 26)
   - O desde dashboard web: click **▶️ REANUDAR**

### Operación Normal

**Ciclo de Medición (cada 5 segundos):**

```
1. [LCD] Leyendo sensores...         (1 segundo)
2. [Serial] Log detallado de datos   (contínuo)
3. [LCD] C:3135  T:223               (3 segundos)
        45%    35%    OK
4. [LCD] DECISION FINAL:             (2 segundos)
        *** APTO ***
5. [UDP] Envío de JSON al servidor
6. [Dashboard] Actualización gráfica
```

### Control Remoto

Desde el dashboard web (`http://IP_PC:1880/ui`):

| Acción | Efecto | Feedback |
|--------|--------|----------|
| **⏸️ PAUSAR** | Detiene mediciones | LCD: "SISTEMA PAUSADO" |
| **▶️ REANUDAR** | Inicia mediciones | LCD: "Iniciando... Sistema" |
| ** Slider** | Cambia intervalo (1-30s) | Serial: "Intervalo cambiado a: Xs" |

### Lectura del LCD

**Pantalla 1 - Valores RAW (3s):**
```
┌────────────────┐
│C:3135    T:223 │  ← Valores RAW de sensores
│45%       35% OK│  ← Porcentajes + Estado
└────────────────┘
```

**Pantalla 2 - Decisión (2s):**
```
┌────────────────┐
│DECISION FINAL: │
│  *** APTO ***  │
└────────────────┘
```

### Monitor Serial

**Ejemplo de salida:**

```
╔════════════════════════════════════════════╗
║         LEYENDO SENSORES SAFEFRY          ║
╚════════════════════════════════════════════╝

 SENSOR CAPACITIVO:
  RAW: 3135 | Degradación: 45.5% | Estado: BUENO | ✅ APTO

 SENSORES DE TURBIDEZ:
  Sensor 1: 225 (35.2%)
  Sensor 2: 220 (34.8%)
  Promedio: 35.0% NTU | Estado: BUENO | ✅ APTO

╔════════════════════════════════════════════╗
║        DECISIÓN FINAL: ✅ APTO            ║
╚════════════════════════════════════════════╝

 Datos enviados por UDP:
{"timestamp":12345,"capacitancia_raw":3135,...}
```

---

## Dashboard Node-RED

### Acceso al Dashboard

```
Local:     http://localhost:1880/ui
Red local: http://192.168.1.100:1880/ui
Móvil:     http://IP_PC:1880/ui
```

### Componentes del Dashboard

#### 1. Indicadores Principales

**Gauges Tipo Donut:**
- **Turbidez**: 0-100% (Verde: 0-40, Amarillo: 40-70, Rojo: 70-100)
- **Capacitancia**: 0-100% (Verde: 0-50, Amarillo: 50-75, Rojo: 75-100)

**Características:**
- Actualización en tiempo real
- Animación suave
- Colores dinámicos según valor

#### 2. Estado del Sistema

**Banner Principal:**
```css
┌────────────────────────────────────┐
│                                    │
│         ✅ APTO                    │  ← Gradiente morado
│                                    │     Fuente grande, sombras
└────────────────────────────────────┘
```

**Indicador de Decisión:**
- ✅ SISTEMA APTO (verde)
- ❌ NO APTO (rojo)

#### 3. Histórico de Mediciones

**Gráfica de Líneas:**
- Eje X: Tiempo (HH:mm:ss)
- Eje Y: Porcentaje (0-100%)
- Línea azul: Turbidez
- Línea naranja: Capacitancia
- Histórico: Últimos 5 minutos
- Interpolación: Lineal
- Zoom: Interactivo

#### 4. Valores RAW

**Displays grandes:**
```
┌─────────────────────┐  ┌─────────────────────┐
│    Turbidez RAW     │  │    Capacitancia RAW │
│                     │  │                     │
│       223           │  │       3135          │
│   (fuente 36px)     │  │   (fuente 36px)     │
└─────────────────────┘  └─────────────────────┘
```

#### 5. Estados Detallados

**Texto descriptivo:**
-  Capacitancia: BUENO (45.5%)
-  Turbidez: EXCELENTE (35.0%)

**Indicadores de estado:**
- Cap: ✅ APTO / ❌ NO APTO
- Turb: ✅ APTO / ❌ NO APTO
- Sistema: ▶️ ACTIVO / ⏸️ PAUSADO

#### 6. Resumen Completo

**Tabla HTML estilizada:**

|   Parámetro | Valor | Estado |
|-------------|-------|--------|
|   Capacitancia RAW | 3135 | ✅ APTO |
|   Capacitancia % | 45.5% | BUENO |
|   Turbidez Sensor 1 RAW | 225 | - |
|   Turbidez Sensor 2 RAW | 220 | - |
|   Turbidez Promedio RAW | 223 | ✅ APTO |
|   Turbidez % | 35.0% | EXCELENTE |
|   **DECISIÓN FINAL** | **✅ APTO** | **✅ SISTEMA APTO** |
|   Última actualización | 09/11/2025 15:30:45 | - |

**Características:**
- Hover effects
- Badges coloridos
- Responsive design
- Exportable

#### 7. Control Remoto

**Botones:**
- ⏸️ **PAUSAR**: Botón rojo, detiene mediciones
- ▶️ **REANUDAR**: Botón verde, inicia mediciones

**Slider de Intervalo:**
- Rango: 1-30 segundos
- Paso: 1 segundo
- Feedback inmediato
- Indicador de valor actual

### Ejemplo Visual del Dashboard

```
╔═══════════════════════════════════════════════════════════╗
║                SafeFry Dashboard Pro                    ║
╠═══════════════════════════════════════════════════════════╣
║    INDICADORES PRINCIPALES                              ║
║  ┌──────────┐  ┌──────────┐                             ║
║  │    35%  │  │    45%  │  (Gauges donut)             ║
║  └──────────┘  └──────────┘                             ║
║                                                          ║
║  🚦 ESTADO DEL SISTEMA                                   ║
║  ┌────────────────────────────────────────┐             ║
║  │          ✅ APTO                       │ (Banner)    ║
║  └────────────────────────────────────────┘             ║
║  ✅ SISTEMA APTO                           (Decisión)    ║
║                                                          ║
║  📈 HISTÓRICO                                            ║
║  ┌────────────────────────────────────────┐             ║
║  │      ╱╲    ╱╲                          │             ║
║  │    ╱    ╲╱    ╲                        │ (Gráfica)   ║
║  │  ╱                                     │             ║
║  └────────────────────────────────────────┘             ║
║                                                          ║
║  🔢 VALORES RAW                                          ║
║  ┌──────────┐  ┌──────────┐                             ║
║  │   223    │  │   3135   │                             ║
║  └──────────┘  └──────────┘                             ║
║                                                          ║
║    ESTADOS: ✅ Cap OK  ✅ Turb OK  ▶️ Activo            ║
║                                                          ║
║    TABLA COMPLETA                                       ║
║  [Tabla con todos los datos detallados]                 ║
║                                                          ║
║    CONTROL REMOTO                                      ║
║  [⏸️ PAUSAR] [▶️ REANUDAR] [━━━━◉━━━ 5s]               ║
╚═══════════════════════════════════════════════════════════╝
```

---

## 📡 API y Protocolos

### Protocolo UDP

#### Formato de Datos (ESP32 → Node-RED)

**Puerto:** 1880  
**Protocolo:** UDP  
**Formato:** JSON  

**Estructura del JSON:**

```json
{
  "timestamp": 12345,
  "capacitancia_raw": 3135,
  "capacitancia": 45.5,
  "capacitancia_estado": "BUENO",
  "capacitancia_apto": true,
  "turbidez1_raw": 225,
  "turbidez2_raw": 220,
  "turbidez_promedio_raw": 223,
  "turbidez": 35.0,
  "turbidez_estado": "EXCELENTE",
  "turbidez_apto": true,
  "sistema_apto": true,
  "estado": "✅ APTO",
  "pausado": false
}
```

**Campos:**

| Campo | Tipo | Rango | Descripción |
|-------|------|-------|-------------|
| `timestamp` | int | 0-∞ | Milisegundos desde inicio |
| `capacitancia_raw` | int | 0-4095 | Valor ADC 12-bit |
| `capacitancia` | float | 0-100 | % de degradación |
| `capacitancia_estado` | string | - | EXCELENTE/BUENO/REGULAR/MALO |
| `capacitancia_apto` | bool | - | true/false |
| `turbidez1_raw` | int | 0-255 | Sensor 1 RAW |
| `turbidez2_raw` | int | 0-255 | Sensor 2 RAW |
| `turbidez_promedio_raw` | int | 0-255 | Promedio RAW |
| `turbidez` | float | 0-100 | % de suciedad |
| `turbidez_estado` | string | - | EXCELENTE/BUENO/REGULAR/MALO/MUY_MALO |
| `turbidez_apto` | bool | - | true/false |
| `sistema_apto` | bool | - | true/false (AND de ambos) |
| `estado` | string | - | "✅ APTO" / "❌ NO APTO" |
| `pausado` | bool | - | Estado del sistema |

#### Comandos (Node-RED → ESP32)

**Puerto:** 1881  
**Protocolo:** UDP Broadcast  
**Formato:** JSON  

**1. Pausar Sistema:**
```json
{
  "comando": "pausar"
}
```

**2. Reanudar Sistema:**
```json
{
  "comando": "reanudar"
}
```

**3. Cambiar Intervalo:**
```json
{
  "comando": "intervalo",
  "valor": 5000
}
```
**Rango válido:** 1000-60000 ms

### Diagrama de Secuencia

```
ESP32                    Node-RED
  │                         │
  ├─────── WiFi Connect ────│
  │◄──────── DHCP IP ───────┤
  │                         │
  ├── UDP(1880): JSON ──────►│ [Procesar datos]
  │                         │ [Actualizar dashboard]
  │                         │ [Usuario: Click PAUSAR]
  │◄─ UDP(1881): {"pausar"} ┤
  │                         │
  [Sistema pausado]         │
  │                         │
  │◄─ UDP(1881): {"reanudar"} ┤
  │                         │
  ├── UDP(1880): JSON ──────►│
  │    (ciclo continúa)      │
```

---

## Calibración de Sensores

### Sensor Capacitivo

#### Procedimiento de Calibración

**1. Calibración en Aire (máximo):**
```cpp
// Sensor al aire libre, sin contacto
int valorAire = sensorCapacitivo.leerRaw();
// Valor esperado: ~3430
```

**2. Calibración en Agua (mínimo):**
```cpp
// Sensor sumergido en agua destilada
int valorAgua = sensorCapacitivo.leerRaw();
// Valor esperado: ~290
```

**3. Calibración con Aceite Limpio:**
```cpp
// Sensor en aceite fresco sin usar
int valorLimpio = sensorCapacitivo.leerRaw();
// Valor esperado: ~3130
```

**4. Calibración con Aceite Degradado:**
```cpp
// Sensor en aceite muy usado/oscuro
int valorSucio = sensorCapacitivo.leerRaw();
// Valor esperado: ~3140
```

**5. Aplicar Calibración:**
```cpp
sensorCapacitivo.calibrar(
    valorAire,    // 3430
    valorAgua,    // 290
    valorLimpio,  // 3130
    valorSucio    // 3140
);
```

#### Troubleshooting

| Problema | Causa | Solución |
|----------|-------|----------|
| Lecturas erráticas | Ruido eléctrico | Agregar capacitor 100nF |
| Valores fuera de rango | Mala conexión | Verificar soldaduras |
| No detecta cambios | Sensor dañado | Reemplazar sensor |

### Sensores de Turbidez

#### Procedimiento de Calibración

**1. Calibración con Aceite Limpio:**
```cpp
// Sumergir sensor en aceite fresco
// Realizar múltiples lecturas
int sum = 0;
for (int i = 0; i < 10; i++) {
    sum += sensorTurbidez1.leerRaw();
    delay(1000);
}
int valorLimpio = sum / 10;
// Valor esperado: ~243
```

**2. Calibración con Aceite Sucio:**
```cpp
// Aceite muy usado o con partículas añadidas
int valorSucio = /* promedio de 10 lecturas */;
// Valor esperado: ~205
```

**3. Aplicar Calibración:**
```cpp
sensorTurbidez1.calibrar(valorLimpio, valorSucio);
sensorTurbidez2.calibrar(valorLimpio, valorSucio);
```

#### Mantenimiento

- **Limpieza:** Limpiar lentes cada semana con alcohol isopropílico
- **Verificación:** Calibrar cada mes o ante lecturas anómalas
- **Almacenamiento:** Guardar en lugar seco cuando no se use

---

## Solución de Problemas

### WiFi

#### ❌ ESP32 no se conecta a WiFi

**Síntomas:**
- LCD muestra "Conectando WiFi..." indefinidamente
- Serial: "❌ Error: No se pudo conectar a WiFi"

**Soluciones:**

1. **Verificar credenciales:**
   ```cpp
   const char* WIFI_SSID = "NOMBRE_EXACTO";
   const char* WIFI_PASSWORD = "contraseña_exacta";
   ```

2. **Verificar frecuencia de red:**
   - ESP32 solo soporta 2.4 GHz
   - Desactivar temporalmente banda 5 GHz del router

3. **Verificar rango de señal:**
   ```cpp
   Serial.print("Señal: ");
   Serial.print(WiFi.RSSI());
   Serial.println(" dBm");
   // Ideal: > -50 dBm
   // Bueno: -50 a -70 dBm
   // Malo: < -70 dBm
   ```

4. **Reset WiFi manual:**
   ```cpp
   WiFi.disconnect(true);
   delay(1000);
   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
   ```

#### Conecta pero pierde conexión

**Solución:** La función `verificarWiFi()` ya maneja reconexión automática cada 30s.

### UDP

#### Dashboard no recibe datos

**Checklist:**

1. ✅ **Firewall de Windows:**
   ```cmd
   # Verificar reglas
   netsh advfirewall firewall show rule name=all | findstr "1880"
   
   # Si no existe, crear regla
   netsh advfirewall firewall add rule name="Node-RED UDP 1880" dir=in action=allow protocol=UDP localport=1880
   ```

2. ✅ **IP correcta:**
   ```cpp
   // En main.cpp, verificar que coincide con tu PC
   const char* UDP_SERVER_IP = "192.168.1.100";
   ```
   
   ```cmd
   # Windows: obtener tu IP
   ipconfig | findstr IPv4
   ```

3. ✅ **Node-RED escuchando:**
   ```cmd
   netstat -an | findstr "1880"
   # Debe mostrar: UDP 0.0.0.0:1880
   ```

4. ✅ **Debug en Serial:**
   ```
   📤 Datos enviados por UDP:
   {"timestamp":12345,...}
   ```

5. ✅ **Debug en Node-RED:**
   - Abrir pestaña "Debug"
   - Verificar nodo "🔍 Debug Datos"
   - Debe aparecer el JSON recibido

#### Comandos no llegan al ESP32

**Solución:**

1. Verificar que ESP32 escucha en 1881:
   ```cpp
   Serial.print("🔌 UDP escuchando en puerto: ");
   Serial.println(UDP_LOCAL_PORT);  // Debe ser 1881
   ```

2. En Node-RED, nodo "📤 UDP Salida":
   - Campo "Address": **dejar en BLANCO**
   - Multicast: **broadcast**

3. Test manual:
   ```python
   # Python script para test
   import socket
   import json
   
   sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
   sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
   
   mensaje = json.dumps({"comando": "pausar"})
   sock.sendto(mensaje.encode(), ('<broadcast>', 1881))
   ```

### Sensores

#### Sensor capacitivo da valores constantes

**Diagnóstico:**
```cpp
// En setup(), agregar:
Serial.print("Test ADC GPIO 25: ");
Serial.println(analogRead(25));
// Debe variar entre 0-4095
```

**Causas:**
- Pin no configurado como INPUT
- Sensor desconectado
- Sensor en corto

**Solución:**
```cpp
pinMode(25, INPUT);
analogReadResolution(12);  // 12 bits
```

#### Sensores de turbidez no responden

**Diagnóstico:**
```cpp
int raw1 = sensorTurbidez1.leerRaw();
Serial.println(raw1);  // -1 = error, 0-255 = OK
```

**Causas comunes:**

1. **Baudrate incorrecto:**
   ```cpp
   serial->begin(9600, SERIAL_8N1, pinRx, pinTx);
   ```

2. **Pines RX/TX invertidos:**
   ```
   ESP32 RX → Sensor TX
   ESP32 TX → Sensor RX
   ```

3. **Alimentación insuficiente:**
   - Sensores requieren 5V estable
   - Verificar con multímetro

4. **Comando incorrecto:**
   ```cpp
   unsigned char comandoLectura[5] = {0x18, 0x05, 0x00, 0x01, 0x0D};
   ```

### LCD

#### LCD no detectado

**Diagnóstico:**
```cpp
if (!lcd.detectar()) {
    Serial.println("❌ LCD no detectado");
    // Probar direcciones alternativas
    for (uint8_t addr = 0x20; addr <= 0x27; addr++) {
        Wire.beginTransmission(addr);
        if (Wire.endTransmission() == 0) {
            Serial.print("✅ Dispositivo I2C en: 0x");
            Serial.println(addr, HEX);
        }
    }
}
```

**Direcciones comunes:**
- 0x27 (default)
- 0x3F
- 0x20

**Solución:**
```cpp
LCDDisplay lcd(0x3F, 21, 22);  // Cambiar dirección
```

#### LCD muestra caracteres raros

**Causas:**
- Contraste mal ajustado (potenciómetro en módulo I2C)
- Inicialización fallida

**Solución:**
```cpp
lcd.begin();
delay(100);
lcd.begin();  // Doble inicialización
```

---


</div>
