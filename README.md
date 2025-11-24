<p align="left">
  <img src="https://github.com/user-attachments/assets/2cae9b13-d1de-4a5a-a827-643818c98091" width="200">
  <h1 align="center">SafeFry: Kit Portable para la Evaluación de Aceite Vegetal</h1>
</p>

## Descripción General
### Proyecto: Sistema de Monitoreo de Calidad de Aceite de Cocina Reutilizado mediante capacitancia y turbidez

SafeFry se centra en el desarrollo de un dispositivo portátil y de bajo costo que combina:

- La medición de la **capacitancia** del aceite de cocina reutilizado, como indicador de cambio en sus propiedades dieléctricas asociadas al deterioro.
- El sondeo de la **turbidez**, para estimar la presencia de impurezas y particulas asociadas al deterior del aceite.

La iniciativa busca facilitar la fiscalización técnica en entornos gastronómicos informales y brindar herramientas accesibles y confiables para la inspección sanitaria. De esta forma, se contribuye a la reducción de riesgos asociados al consumo de aceites degradados y a la prevención de enfermedades.

### ODS 3: Salud y Bienestar

El proyecto se enmarca dentro del ODS 3: Salud y Bienestar, particularmente en la meta 3.9: “Reducir sustancialmente el número de muertes y enfermedades por productos químicos peligrosos y contaminación del aire, agua y suelo” (ONU, 2023).

Este dispositivo busca:
- Contribuir a la seguridad alimentaria en contextos urbanos y rurales.
- Apoyar a instituciones y actores locales en la inspección sanitaria.
- Reducir el riesgo para la salud humana derivado del consumo de aceites en mal estado.

## Características Principales

- **Medición eléctrica:** Integración de un sensor capacitivo para análisis indirecto de la constante dieéectrica en el aceite, relacionado con su grado de deterioro.
- **Medición optica:** Uso de un sensor de turbidez como parametro indirecto del deterioro, con criterio de alerta en niveles altos de particulas e impurezas.
- **Interfaz intuitiva:** Visualización clara de resultados (capacitancia, turbidez, diagnóstico final).
- **Diseño portátil:** Prototipo compacto, accesible y replicable en diferentes contextos.

## Motivación y Contexto

El acceso a herramientas accesibles y confiables para evaluar la calidad de aceites de cocina reutilizados suele estar limitado por altos costos, falta de precisión o la necesidad de equipos especializados. Esto genera un riesgo para la salud pública, especialmente en entornos gastronómicos informales donde los controles sanitarios son reducidos. </p>
SafeFry nace con la intención de democratizar la evaluación de aceites, ofreciendo una alternativa portátil, de bajo costo y sencilla de implementar, que combina la medición de capacitancia con el análisis de turbidez. </p>
Este proyecto también responde a la necesidad académica de brindar a los estudiantes experiencias prácticas en el uso de tecnologías emergentes (sensado químico y sensado optico), facilitando la comprensión de conceptos de seguridad alimentaria, control de calidad y sostenibilidad en escenarios reales.

## Funcionamiento Esperado

1. La muestras de aceite se preparan y colocan en compartimentos de medición.
2. El sensor capacitivo mide la **capacitancia aparente** de la muestra, relacionada con cambios en su composición.
3. El sensor optico mide la **turbidez** del aceite para detectar su grado de deterioro.
4. El sistema procesa ambos valores y los compara con parámetros de referencia.
5. Se muestra el resultado en pantalla: Apto / No apto.

## Resultados Esperados

- Medición confiable de **capacitancia** y **turbidez** como parámetros de referencia para la evaluación de la calidad del aceite.
- Prototipo portátil y de bajo costo, diseñado para ser implementado en entornos gastronómicos informales y educativos.
- Contribución académica y social, fortaleciendo la seguridad alimentaria y promoviendo el uso de tecnologías accesibles para el control de calidad.

## Estructura del Proyecto

A continuación se detalla la organización de carpetas y archivos del repositorio:

```text
Proyectos-de-Ingenier-a-1/                        # Repositorio raíz
│
├── README.md                                     # Presentación general y documentación global
├── Fundamentos de Diseño/                        # Carpeta del curso predecesor
│
└── Proyectos de Ingeniería/                      # Carpeta principal del curso actual
    ├── Certificados/                             # Documentos de gestión y madurez TRL
    ├── Imágenes/                                 # Recursos visuales subidos
    ├── Sobre Nosotros/                           # Información de los integrantes
    ├── Talleres/                                 # Talleres y laboratorios del curso
    │
    └── Documentación/                            # Documentación técnica de ingeniería
        ├── 1.Justificación_Científica.md         # Base científica del proyecto
        ├── 2.Lista_de_Requerimientos.md          # Requisitos de portabilidad y técnicos
        ├── 3.Caja_Negra_y_Esquema_Funciones.md   # Diagramas funcionales del sistema
        ├── 4.Matriz_Morfológica.md               # Evaluación de alternativas de diseño
        ├── 5.Tabla_de_Valoración.md              # Selección de la solución final
        ├── 6.Bocetos.md                          # Dibujos preliminares del prototipo
        ├── 7.Modelo_3D.md                        # Modelado del prototipo en Onshape
        ├── 8.Esquemático.md                      # Diagramas de conexiones electrónicas
        │
        └── 9. Código/                            # Sección de Software y Firmware
            ├── README.md                         # Presentación de "SafeFry Pro" (IoT)
            │
            ├── Código_Node_Red/                  # Lógica del Dashboard IoT
            │   ├── Node-Red_Flow-Safefry.json    # Flujo completo: Dashboard y Gráficas
            │   └── README.md                     # Presentación del Flujo Node-RED
            │
            └── Código_Safefry_Aceite/            # Proyecto de Firmware (PlatformIO)
                ├── .gitignore                    # Archivos ignorados por Git
                ├── platformio.ini                # Configuración del entorno y librerías
                │
                ├── .vscode/                      # Configuración del editor VSCode
                │   └── extensions.json           # Extensiones recomendadas
                │
                ├── include/                      # Archivos de cabecera (.h) globales
                │   └── README                    # Info sobre headers
                │
                ├── lib/                          # Librerías privadas específicas
                │   └── README                    # Info sobre librerías estáticas
                │
                ├── test/                         # Pruebas unitarias del código
                │   └── README                    # Info sobre PlatformIO Test Runner
                │
                └── src/                          # Código fuente principal (C++)
                    ├── main.cpp                  # Archivo principal (Lógica de control)
                    ├── lcd_display.cpp           # Código control pantalla LCD
                    ├── lcd_display.h             # Definiciones pantalla LCD
                    ├── pulsador.cpp              # Lógica de los botones físicos
                    ├── pulsador.h                # Definiciones de botones
                    ├── sensor_capacitancia.cpp   # Lectura del sensor capacitivo (Aceite)
                    ├── sensor_capacitancia.h     # Definiciones sensor capacitivo
                    ├── sensores_turbidez.cpp     # Lectura de turbidez
                    └── sensores_turbidez.h       # Definiciones turbidez
```

## Integrantes:

| Miembro | Rol | Función Principal | Correo |
| :------------: | :------------: | :------------: | :------------: |
| **Rivera Torres Victor Daniel** | Diseño mecánico y prototipo | Diseñar y generar planos; iterar el prototipo físico | victor.rivera@upch.pe |
| **Morales Alvarado Jesús Anselmo** | Firmware y Telemetría | Programar filtrado y lógica; telemetría con envío al sitio web | jesus.morales@upch.pe |
| **Rioja Cruz Vanesa Doris** | Investigación y Requisitos | Liderar la revisión bibliográfica, definir métricas/umbrales y protocolos de calibración | vanesa.rioja@upch.pe |
| **Oscco Pizarro Gisela** | Gestión de Repositorio y Flujo de Desarrollo | Estructurar y mantener el GitHub, control de versiones de datos | gisela.oscco@upch.pe |
| **Huamani Salazar Jander** | Electrónica y Ensamble | Diseñar el esquema, cableado y ensamble electrónico | jander.huamani@upch.pe |
