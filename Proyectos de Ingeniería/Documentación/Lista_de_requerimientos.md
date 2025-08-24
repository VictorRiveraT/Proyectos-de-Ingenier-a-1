# Lista de Exigencias

Proyecto: **Sistema de Monitoreo de Calidad de Aceite de Cocina Reutilizado mediante pH y Capacitancia**  
Institución: Universidad Peruana Cayetano Heredia  
Fecha: 18/08/2025  

| Fecha    | Tipo | Exigencia              | Descripción                                                                                                                                                                                                                       | Responsable                 |
|----------|------|------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------|
| 18/08/25 | E    | Función principal      | El dispositivo debe medir la calidad del aceite vegetal usado a través de **pH aparente** (relacionado a la acidez y liberación de ácidos grasos) y **capacitancia dieléctrica** (indicador indirecto de %TPC). Ambos parámetros son aceptados en la literatura como indicadores de deterioro. | J.M, J.H, Vanesa R, Victor R, G.O |
| 18/08/25 | E    | Medición de parámetros | **pH aparente (emulsión aceite–agua/etanol):** rango 0–14, resolución ±0.1; alerta si pH < 4.5 (alta acidez). <br> **Capacitancia/TPC:** correlación con %TPC; fresco <10%, en uso 10–24%, deteriorado ≥25%.                                                        | J.M, J.H, G.O              |
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


## Bibliografía

- AOCS. (2017). *Official Method Cd 20-91: Total Polar Materials in Used Frying Oils.* American Oil Chemists’ Society.  
  Recuperado de [https://www.aocs.org/resource/determination-of-polar-compounds-in-used-frying-oils-and-fats-by-adsorption-chromatography](https://www.aocs.org/resource/determination-of-polar-compounds-in-used-frying-oils-and-fats-by-adsorption-chromatography)

- Codex Alimentarius. (2019). *Standard for Named Vegetable Oils (CODEX-STAN 210-1999).* FAO/WHO.  
  Recuperado de [http://www.fao.org/fao-who-codexalimentarius/sh-proxy/en/?lnk=1&url=https://workspace.fao.org/sites/codex/Standards/CODEX%20STAN%20210-1999/CXS_210e.pdf](http://www.fao.org/fao-who-codexalimentarius/sh-proxy/en/?lnk=1&url=https://workspace.fao.org/sites/codex/Standards/CODEX%20STAN%20210-1999/CXS_210e.pdf)

- FAO/OMS. (2010). *Safety evaluation of certain food additives and contaminants* (WHO Food Additives Series 61). Geneva: World Health Organization.  
  Recuperado de [https://www.who.int/publications/i/item/9789241660614](https://www.who.int/publications/i/item/9789241660614)

- ISO. (2020). *ISO 660:2020 – Animal and vegetable fats and oils — Determination of acid value and acidity.*  
  Recuperado de [https://www.iso.org/standard/76623.html](https://www.iso.org/standard/76623.html)

- ISO. (2018). *ISO 22000:2018 – Food safety management systems — Requirements for any organization in the food chain.*  
  Recuperado de [https://www.iso.org/standard/65464.html](https://www.iso.org/standard/65464.html)

- ISO. (2019). *ISO 468:2019 – Surface roughness — Parameters, their values and general rules for specifying requirements.*  
  Recuperado de [https://www.iso.org/standard/69126.html](https://www.iso.org/standard/69126.html)

- ISO. (2017). *ISO 7250-1:2017 – Basic human body measurements for technological design — Part 1.*  
  Recuperado de [https://www.iso.org/standard/65244.html](https://www.iso.org/standard/65244.html)

- ISO. (2018). *ISO 45001:2018 – Occupational health and safety management systems.*  
  Recuperado de [https://www.iso.org/standard/63787.html](https://www.iso.org/standard/63787.html)

- Khaled, A. Y., Aziz, S. A., & Rokhani, F. Z. (2015). Capacitive sensor probe to assess frying oil degradation. *Information Processing in Agriculture, 2*(2), 142–148.  
  https://doi.org/10.1016/j.inpa.2015.07.002

- Zhang, Z., Li, Z., Zhang, X., Zhou, J., Wang, S., & Chen, Y. (2020). Portable dielectric sensor for frying oil monitoring. *Sensors, 20*(3), 837.  
  https://doi.org/10.3390/s20030837

- Zubair, M., Kim, H. S., & Kim, H. S. (2018). Capacitive sensor for engine oil deterioration measurement. *Sensors and Transducers, 219*(7), 1–8.  
  Recuperado de [https://www.sensorsportal.com/HTML/DIGEST/july_2018/P_3098.pdf](https://www.sensorsportal.com/HTML/DIGEST/july_2018/P_3098.pdf)

- Congreso de la República del Perú. (2011). *Ley N° 29783, Ley de Seguridad y Salud en el Trabajo.*  
  Recuperado de [https://www.gob.pe/institucion/mtpe/normas-legales/203435-ley-n-29783](https://www.gob.pe/institucion/mtpe/normas-legales/203435-ley-n-29783)

- Ministerio de Salud del Perú. (1998). *Decreto Supremo N° 007-98-SA, Reglamento sobre Vigilancia y Control Sanitario de Alimentos y Bebidas.*  
  Recuperado de [https://www.gob.pe/institucion/minsa/normas-legales/287047-007-98-sa](https://www.gob.pe/institucion/minsa/normas-legales/287047-007-98-sa)
