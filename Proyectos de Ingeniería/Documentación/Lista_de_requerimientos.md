# 1. Lista de Exigencias

## Tabla 1: Lista de Exigencias

| **LISTA DE EXIGENCIAS** | **Páginas:** 2 |
|--------------------------|----------------|
| **PROYECTO:** Instrumento de medición de aceite vegetal utilizando pH y tratamiento de imágenes | **Edición:** Rev. 1 |
| **CLIENTE:** UNIVERSIDAD PERUANA CAYETANO HEREDIA | **Fecha:** 18/08/2025 |
| **Elaborado:**<br>Jesús Morales, Jander Huamani, Vanesa Rioja, Víctor Rivera, Gisela Oscco| **Revisado:** |

---

| **Fecha (cambios)** | **Deseo o Exigencia** | **Descripción** | **Responsable** |
|----------------------|-----------------------|-----------------|-----------------|
| 18/08/25 | E | **Función principal:** Medir la calidad de muestras de aceite vegetal usado, utilizando como parámetros el pH y el análisis de color y turbidez mediante procesamiento de imágenes (machine learning) para entregar un diagnóstico final. | J.M, J.H, Vanesa R, Victor R, G.O |
| 18/08/25 | E | **Medición de parámetros:**<br>**pH in situ:** Mide pH de muestras de aceite (0-14) con resolución ±0.1; alerta si pH < 4.5, umbral crítico de degradación que libera ácidos grasos libres tóxicos.<br>**Análisis por imágenes:** Capturará una foto de la muestra en un cajetín diseñado para una iluminación controlada y que un modelo de machine learning analice el color y la turbidez. | J.M, J.H y G.O |
| 18/08/25 | D | **Geometría y portabilidad:** El prototipo debe ser compacto y ligero, con un peso inferior a 1.5 kg y dimensiones que no excedan 15x10x20 cm, para facilitar su transporte y uso en campo (diseñado para caber en una mochila estándar). | Victor R. |
| 18/08/25 | D | **Energía y autonomía:** Debe garantizar una autonomía de al menos 8 horas de uso continuo para aplicaciones. Utilizará batería, de energía …, recargable a pilas de salida 5V. Suficientes para los 5V necesarios. | G.O |
| 18/08/25 | D | **Software y control:** El sistema (controlado por Raspberry Pi X) deberá:<br>- Procesar los datos del sensor de pH.<br>- Controlar la cámara y la iluminación para la captura de imágenes.<br>- Ejecutar el modelo de machine learning para interpretar la imagen.<br>- Integrar ambos resultados (pH e imagen) para el diagnóstico final. | J.M |
| 18/08/25 | D | **Conectividad y registro:** Las lecturas y resultados deberán poder exportarse vía … a una plataforma o aplicación móvil vinculada para el registro y seguimiento de datos. | Vanesa R. |
| 18/08/25 | D | **Señales e interfaz:** Contará con una pantalla LCD (16×2 cm) que muestre de forma clara e instantánea:<br>- Valor de pH.<br>- Indicador de calidad por imagen.<br>- Diagnóstico final: Apto o No apto. | Vanesa R. |
| 18/08/25 | D | **Ergonomía y uso rápido en campo:** El diseño debe ser ergonómico y de fácil manejo. Contará con un único botón que inicie la rutina de calibración y medición para simplificar la operación en campo. | G.O |
| 18/08/25 | D | **Costo accesible:** Costo de materiales < S/ 350 en prototipo (sensor, cámara, iluminación, pantalla LCD, power bank, microprocesador, protoboard, carcasa, jumpers, cables de puente, claves tipo USB y C). | J.H |
| 18/08/25 | D | **Fabricación y resistencia:** El diseño debe ser funcional y proteger los componentes internos (batería, electrónica, cámara) de salpicaduras de aceite o movimientos bruscos. Además la carcasa debe ser oscura para no interferir en el muestreo de imágenes, a su vez estar construida con materiales accesibles y resistentes de impresión 3D, PLA o FLEX. | Victor R |
| 18/08/25 | D | **Limpieza:** La limpieza de los compartimentos de las muestras se realizará manualmente. Se proveerán indicaciones claras en un manual de usuario para asegurar la no contaminación entre mediciones. El mantenimiento se limitará a la recarga de pilas y la limpieza. | G.O |
| 18/08/25 | E | **Comunicaciones:** El controlador debe poder comunicarse con los sensores y actuadores a través de un sistema directo de cableado. Además, debe ser capaz de procesar correctamente la información o señales ingresadas por el usuario. Asimismo, los dispositivos de mando deben facilitar su uso. Entre subsistemas, la comunicación debe evitar interferir con el funcionamiento general de la máquina asegurando la interoperabilidad entre subsistemas. | Vanesa R. |
| 18/08/25 | D | **Transporte:** Deberá contar con un peso adecuado para ser transportado de forma terrestre, además que sea portátil para el público objetivo. | Victor R. |
| 18/08/25 | D | **Costos:** Para costos de materiales se estimara que no exceda los 300 soles para mantener el prototipo accesible en el mercado. | J.H |
| 18/08/25 | E | **Plazos:** El proyecto empezará el lunes 18 de agosto y  espera su finalización el martes 2 de diciembre con un total aproximado de 128 horas de trabajo. | J.M |
