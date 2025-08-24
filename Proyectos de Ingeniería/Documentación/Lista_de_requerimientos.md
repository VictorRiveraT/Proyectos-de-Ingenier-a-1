# 📋 Lista de Exigencias

Proyecto: **Instrumento de medición de aceite vegetal por pH y Capacitancia**  
Cliente: Universidad Peruana Cayetano Heredia  
Fecha: 18/08/2025  

| Fecha    | Tipo | Exigencia              | Descripción                                                                                                                                                                                                                       | Responsable                 |
|----------|------|------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------|
| 18/08/25 | E    | Función principal      | El dispositivo debe medir la calidad del aceite vegetal usado a través de **pH aparente** (relacionado a la acidez y liberación de ácidos grasos) y **capacitancia dieléctrica** (indicador indirecto de %TPC). Ambos parámetros son aceptados en la literatura como indicadores de deterioro. | J.M, J.H, Vanesa R, Victor R, G.O |
| 18/08/25 | E    | Medición de parámetros | - **pH aparente (emulsión aceite–agua/etanol):** rango 0–14, resolución ±0.1; alerta si pH < 4.5 (alta acidez). <br> - **Capacitancia/TPC:** correlación con %TPC; fresco <10%, en uso 10–24%, deteriorado ≥25%.                                                        | J.M, J.H, G.O              |
| 18/08/25 | D    | Geometría y portabilidad | Prototipo compacto y liviano (<1.5 kg, ≤15×10×20 cm) para transporte en mochila y uso en campo (ISO 7250).                                                                                                                         | Victor R                   |
| 18/08/25 | D    | Energía y autonomía    | Autonomía mínima de 8 horas con baterías recargables de bajo costo; salida en corriente continua de 5–9 V.                                                                                                                         | G.O                        |
| 18/08/25 | D    | Software y control     | El sistema debe procesar lecturas de pH, registrar capacitancia y estimar %TPC, corregir por temperatura y entregar diagnóstico (Apto/No apto).                                                                                    | J.M                        |
| 18/08/25 | D    | Conectividad y registro| Lecturas exportables a aplicación móvil o PC vía Bluetooth o USB.                                                                                                                                                                 | Vanesa R                   |
| 18/08/25 | D    | Señales e interfaz     | Una pantalla (LCD/OLED) debe mostrar pH, %TPC estimado y diagnóstico final.                                                                                                                                                        | Vanesa R                   |
| 18/08/25 | D    | Ergonomía y operación  | Uso simple con un único botón para calibración/medición. Respetar ergonomía (ISO 7250).                                                                                                                                            | G.O                        |
| 18/08/25 | D    | Costo accesible        | Costo del prototipo ≤ S/ 350 (sensores, microcontrolador, pantalla, batería, carcasa).                                                                                                                                             | J.H                        |
| 18/08/25 | D    | Fabricación y resistencia | Carcasa impresa en 3D (PLA/ABS) y acero inoxidable en contacto con el aceite. Cumplir ISO 22000 e ISO 468.                                                                                                                        | Victor R                   |
| 18/08/25 | D    | Limpieza y mantenimiento | Compartimento de muestras de fácil limpieza manual; incluir manual de usuario.                                                                                                                                                     | G.O                        |
| 18/08/25 | D    | Comunicaciones internas | Subsistemas conectados por cableado confiable, evitando interferencias.                                                                                                                                                            | Vanesa R                   |
| 18/08/25 | D    | Seguridad              | Cumplimiento de Ley N°29783 y norma ISO 45001; incluir botón de apagado de emergencia.                                                                                                                                             | J.H                        |
| 18/08/25 | D    | Fabricación            | Materiales accesibles en el mercado local o con importación ≤15 días. Cumplimiento con DS 007-98-SA (DIGESA).                                                                                                                      | J.H                        |
| 18/08/25 | D    | Control de calidad     | Cumplir dimensiones, tolerancias, seguridad, higiene y normativa alimentaria (Codex Alimentarius).                                                                                                                                 | Victor R, Vanesa R         |
| 18/08/25 | D    | Transporte             | Portátil, resistente a vibraciones y protegido para traslado en mochila.                                                                                                                                                           | Victor R                   |
| 18/08/25 | D    | Uso ambiental          | Operar hasta 3500 m.s.n.m y tolerar variaciones de temperatura y humedad (condiciones del Perú).                                                                                                                                   | Victor R                   |
| 18/08/25 | E    | Plazos                 | El proyecto empezará el lunes 18 de agosto y finalizará el martes 2 de diciembre con un total aproximado de 128 horas de trabajo.                                                                                                  | J.M, J.H, Vanesa R, Victor R, G.O |


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
