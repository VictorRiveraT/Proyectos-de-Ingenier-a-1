<p align="left">
  <img src="https://github.com/user-attachments/assets/2cae9b13-d1de-4a5a-a827-643818c98091" width="200">
  <h1 align="center">Lista de Requerimientos</h1>
</p>

Proyecto: **Sistema de Monitoreo de Calidad de Aceite de Cocina Reutilizado mediante capacitancia y turbidez**  
Institución: Universidad Peruana Cayetano Heredia  
Fecha Primera Revisión: 18/08/2025  


| Fecha    | Tipo | Exigencia              | Descripción                                                                                                                                                                                                                       | Responsable                 |
|----------|------|------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------|
| 09/09/25 | E    | Función principal      | El dispositivo debe medir la calidad del aceite vegetal usado a través de **capacitancia** (relacionado con cambios en la constante dieléctrica del aceite debido a la degradación de sus componentes) y **turbidez** (indicador indirecto de la presencia de impurezas y particulas en suspensión). Ambos parámetros son aceptados en la literatura como indicadores de deterioro. | J.M, J.H, Vanesa R, Victor R, G.O |
| 09/09/25 | E    | Medición de parámetros | **Capacitancia aparente:** rango 0–1000 pF(ajustable segun calibración), resolución ±0.1 pF; alerta si la variación excede valores de referencia establecidos en pruebas experimentales(indicando deterioro). <br> **Turbidez en NTU:** (0-3000) con umbral critico > 500 NTU empleando dispersión de luz para detectar particulas quemadas del aceite.                                                       | J.M, J.H, G.O              |
| 18/08/25 | E    | Geometría y portabilidad | Prototipo compacto y liviano (<1.5 kg, ≤10×10×20 cm) para transporte en mochila y uso en campo (ISO 7250).                                                                                                                         | Victor R                   |
| 18/08/25 | D    | Energía y autonomía    | Autonomía mínima de 8 horas con baterías recargables de bajo costo; salida en corriente continua de 3–5 V.                                                                                                                         | G.O                        |
| 09/09/25 | E    | Software y control     | El sistema debe procesar lecturas de capacitancia, registrar turbidez y estimar NTU, corregir por temperatura y entregar diagnóstico (Apto/No apto).                                                                                    | J.M                        |
| 05/10/25 | E    | Conectividad y registro| Lecturas exportables a un dashboard interactivo vía Bluetooth/Wi-Fi.                                                                                                                                                                 | Vanesa R                   |
| 05/10/25 | E    | Señales e interfaz     | Un indicador visual debe mostrar capacitancia, turbidez y diagnóstico final.                                                                                                                                                        | Vanesa R                   |
| 18/08/25 | E    | Ergonomía y operación  | Uso simple con un único botón para medición. Respetar ergonomía (ISO 7250).                                                                                                                                            | G.O                        |
| 18/08/25 | D    | Costo accesible        | Costo del prototipo ≤ S/ 350 (sensores, microcontrolador, indicador visual, batería, carcasa).                                                                                                                                             | J.H                        |
| 18/08/25 | D    | Fabricación y resistencia | Carcasa impresa en 3D (PLA/ABS) y acrílico en contacto con el aceite. Cumplir ISO 22000 e ISO 468.                                                                                                                        | Victor R                   |
| 18/08/25 | D    | Limpieza y mantenimiento | Compartimento de muestras de fácil limpieza manual y fácil mantenimiento de componentes ; incluir manual de usuario.                                                                                                                                                     | G.O                        |
| 18/08/25 | E    | Comunicaciones internas | Subsistemas conectados por cableado confiable, evitando interferencias.                                                                                                                                                            | Vanesa R                   |
| 18/08/25 | E    | Seguridad              | Cumplimiento de Ley N°29783 y norma ISO 45001; incluir botón de encendidoo/apagado manual.                                                                                                                                             | J.H                        |
| 18/08/25 | D    | Fabricación            | Materiales accesibles en el mercado local o con importación ≤15 días. Cumplimiento con DS 007-98-SA (DIGESA).                                                                                                                      | J.H                        |
| 18/08/25 | E    | Control de calidad     | Cumplir dimensiones, tolerancias, seguridad, higiene y normativa alimentaria (Codex Alimentarius).                                                                                                                                 | Victor R, Vanesa R         |
| 18/08/25 | E    | Transporte             | Portátil, resistente a vibraciones y protegido para traslado en mochila.                                                                                                                                                           | Victor R                   |
| 18/08/25 | D    | Uso ambiental          | Operar hasta 3500 m.s.n.m y tolerar variaciones de temperatura y humedad (condiciones del Perú).                                                                                                                                   | Victor R                   |
| 18/08/25 | E    | Plazos                 | El proyecto empezará el lunes 18 de agosto y finalizará el martes 2 de diciembre con un total aproximado de 128 horas de trabajo.                                                                                                  | J.M, J.H, Vanesa R, Victor R, G.O |


## Bibliografía

- Anderson-Negele. (2025, 19 de febrero). Turbidity control in food and beverage production: Overview, applications and selection criteria [White paper]. Anderson-Negele.
  Recuperado de [https://www.anderson-negele.com/wp-content/themes/andersonnegele/assets/whitepaper/Whitepaper_40010_Turbidity-Control-Technology_en.pdf](https://www.anderson-negele.com/wp-content/themes/andersonnegele/assets/whitepaper/Whitepaper_40010_Turbidity-Control-Technology_en.pdf)

- AOCS. (2017). *Official Method Cd 20-91: Total Polar Materials in Used Frying Oils.* American Oil Chemists’ Society.  
  Recuperado de [https://www.aocs.org/resource/determination-of-polar-compounds-in-used-frying-oils-and-fats-by-adsorption-chromatography](https://www.aocs.org/resource/determination-of-polar-compounds-in-used-frying-oils-and-fats-by-adsorption-chromatography)

- Codex Alimentarius. (2019). *Standard for Named Vegetable Oils (CODEX-STAN 210-1999).* FAO/WHO.  
  Recuperado de [http://www.fao.org/fao-who-codexalimentarius/sh-proxy/en/?lnk=1&url=https://workspace.fao.org/sites/codex/Standards/CODEX%20STAN%20210-1999/CXS_210e.pdf](http://www.fao.org/fao-who-codexalimentarius/sh-proxy/en/?lnk=1&url=https://workspace.fao.org/sites/codex/Standards/CODEX%20STAN%20210-1999/CXS_210e.pdf)
  
- Congreso de la República del Perú. (2011). *Ley N° 29783, Ley de Seguridad y Salud en el Trabajo.*  
  Recuperado de [https://www.gob.pe/institucion/mtpe/normas-legales/203435-ley-n-29783](https://www.gob.pe/institucion/mtpe/normas-legales/203435-ley-n-29783)

- FAO/OMS. (2010). *Safety evaluation of certain food additives and contaminants* (WHO Food Additives Series 61). Geneva: World Health Organization.  
  Recuperado de [https://www.who.int/publications/i/item/9789241660614](https://www.who.int/publications/i/item/9789241660614)

- Haryanto, B., Alexander, V., Nasution, I. T., Polem, A. F., Sitohang, O. M., Tambun, R., & Masyithah, Z. (2023). Environmental sustainability through the utilization of corn cobs as an adsorbent material in waste cooking oil. IOP Conference Series: Earth and Environmental Science, 1241, 012115.
  Recuperado de [https://doi.org/10.1088/1755-1315/1241/1/012115](https://doi.org/10.1088/1755-1315/1241/1/012115)

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
  Recuperado de [https://doi.org/10.1016/j.inpa.2015.07.002](https://doi.org/10.1016/j.inpa.2015.07.002)

- Ministerio de Salud del Perú. (1998). *Decreto Supremo N° 007-98-SA, Reglamento sobre Vigilancia y Control Sanitario de Alimentos y Bebidas.*  
  Recuperado de [https://www.gob.pe/institucion/minsa/normas-legales/287047-007-98-sa](https://www.gob.pe/institucion/minsa/normas-legales/287047-007-98-sa)

- Srkar, D., Vasudeva Reddy, T., Anirudh Reddy, R., Siri, B., Lahari, B., & Sangeetha Rani, E. (2025). Cooking oil purity and reusability detection system using embedded system. E3S Web of Conferences, 648, Article 03028.
  Recuperado de [https://doi.org/10.1051/e3sconf/202564803028](https://doi.org/10.1051/e3sconf/202564803028)

- Zhang, Z., Li, Z., Zhang, X., Zhou, J., Wang, S., & Chen, Y. (2020). Portable dielectric sensor for frying oil monitoring. *Sensors, 20*(3), 837.
  Recuperado de [https://doi.org/10.3390/s20030837](https://doi.org/10.3390/s20030837)

- Zubair, M., Kim, H. S., & Kim, H. S. (2018). Capacitive sensor for engine oil deterioration measurement. *Sensors and Transducers, 219*(7), 1–8.  
  Recuperado de [https://www.sensorsportal.com/HTML/DIGEST/july_2018/P_3098.pdf](https://www.sensorsportal.com/HTML/DIGEST/july_2018/P_3098.pdf)
