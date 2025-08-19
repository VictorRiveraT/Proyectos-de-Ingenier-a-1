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
| 18/08/25 | E | **Función principal:** Evaluar la calidad de muestras de aceite vegetal usado, utilizando como parámetros el pH y el análisis de color y turbidez mediante procesamiento de imágenes (Machine Learning) para entregar un resultado confiable en menos de un minuto por muestra. | J.M, J.H, Vanesa R, Victor R, G.O |
| 18/08/25 | E | **Medición de parámetros:**<br>**pH in situ:** Mide pH de muestras de aceite (0-14) con resolución ±0.1; alerta si pH < 4.5, umbral crítico de degradación que libera ácidos grasos libres tóxicos.<br>**Análisis por imágenes:** Capturará una foto de la muestra en un cajetín diseñado para una iluminación controlada y que un modelo de machine learning analice el color y la turbidez. | J.M, J.H y G.O |
| 18/08/25 | D | **Geometría y portabilidad:** El prototipo debe ser compacto y ligero, con un peso inferior a 1.5 kg y dimensiones que no excedan 15x10x20 cm, para facilitar su transporte y uso en campo (diseñado para caber en una mochila estándar). | Victor R. |
| 18/08/25 | D | **Energía y autonomía:** Debe garantizar una autonomía de al menos 8 horas de uso continuo para inspecciones. Utilizará una batería, de corriente continua, recargable a pilas de salida 9v. Suficientes para los 5v necesarios. | G.O |
| 18/08/25 | D | **Software y control:** El sistema (controlado por Raspberry Pi X) deberá:<br>- Procesar los datos del sensor de pH.<br>- Controlar la cámara y la iluminación para la captura de imágenes.<br>- Ejecutar el modelo de machine learning para interpretar la imagen.<br>- Integrar ambos resultados (pH e imagen) para el diagnóstico final. | J.M |
| 18/08/25 | D | **Conectividad y registro:** Las lecturas y resultados deberán poder exportarse vía Bluetooth a una plataforma o aplicación móvil vinculada para el registro y seguimiento de datos. | Vanesa R. |
| 18/08/25 | D | **Señales e interfaz:** Contará con una pantalla LCD (16×2 cm) que muestre de forma clara e instantánea:<br>- Valor de pH.<br>- Indicador de calidad por imagen.<br>- Diagnóstico final: Apto o No apto. | Vanesa R. |
| 18/08/25 | D | **Ergonomía y uso rápido en campo:** El diseño debe ser ergonómico y de fácil manejo. Contará con un único botón que inicie la rutina de calibración y medición para simplificar la operación en campo. | G.O |
| 18/08/25 | D | **Costo accesible:** Costo de materiales < S/ 350 en prototipo (sensor, cámara, iluminación, pantalla LCD, power bank, microprocesador, protoboard, carcasa, jumpers, cables de puente, claves tipo USB y C). | J.H |
| 18/08/25 | D | **Fabricación y resistencia:** El diseño debe ser funcional y proteger los componentes internos (batería, electrónica, cámara) de salpicaduras de aceite o movimientos bruscos. Además la carcasa debe ser oscura para no interferir en el muestreo de imágenes, a su vez estar construida con materiales accesibles y resistentes de impresión 3D, PLA o FLEX. | Victor R |
| 18/08/25 | D | **Limpieza:** La limpieza de los compartimentos de las muestras se realizará manualmente. Se proveerán indicaciones claras en un manual de usuario para asegurar la no contaminación entre mediciones. El mantenimiento se limitará a la recarga de pilas y la limpieza. | G.O |
| 18/08/25 | D | **Comunicaciones:** El controlador debe poder comunicarse con los sensores y cámara a través de un sistema directo de cableado. Además, debe ser capaz de procesar correctamente la información obteida de la muestra. Asimismo, los dispositivos de mando deben facilitar su uso. | Vanesa R. |
| 18/08/25 | D | **Transporte:** Deberá contar con un peso adecuado para ser transportado de forma terrestre, además que sea portátil para el público objetivo. | Victor R. |
| 18/08/25 | E | **Plazos:** El proyecto empezará el lunes 18 de agosto y  espera su finalización el martes 2 de diciembre con un total aproximado de 128 horas de trabajo. | J.M |

<p align="center">
  <img src="https://github.com/VictorRiveraT/Proyectos-de-Ingenier-a/blob/main/Proyectos%20de%20Ingenier%C3%ADa/Im%C3%A1genes/1.jpg"/>
<p align="center">
  <img src="https://github.com/VictorRiveraT/Proyectos-de-Ingenier-a/blob/main/Proyectos%20de%20Ingenier%C3%ADa/Im%C3%A1genes/2.jpg"/>
<p align="center">
  <img src="https://github.com/VictorRiveraT/Proyectos-de-Ingenier-a/blob/main/Proyectos%20de%20Ingenier%C3%ADa/Im%C3%A1genes/3.jpg"/>

## Bibliografía
- Esterbauer, H., Schaur, R. J., & Zollner, H. (2014). Chemistry and biochemistry of 4-hydroxynonenal, malonaldehyde and related aldehydes. Neurotoxicology, 45, 10–21. https://doi.org/10.1016/j.neuro.2014.09.007
- FAO/WHO. (1994). Grasas y aceites alimentarios en la nutrición humana. Roma: FAO. https://www.fao.org/3/y2774s/y2774s06.htm
- Lethuaut, L., Bouvier-Navé, P., & Rousseau, D. (2016). Evaluation of frying oil degradation. ResearchGate. https://www.researchgate.net/publication/310742828
- Loguercio, C., & Federico, A. (2005). Oxidative stress in viral and alcoholic hepatitis. Journal of Hepatology, 42(6), 845–851. https://doi.org/10.1016/j.jhep.2005.07.019
- Ministerio del Ambiente. (s.f.). Ley General de Residuos Sólidos - Ley N.º 27314. https://www.gob.pe/institucion/minsa/normas-legales/251249-188-2006-sa-dvm
