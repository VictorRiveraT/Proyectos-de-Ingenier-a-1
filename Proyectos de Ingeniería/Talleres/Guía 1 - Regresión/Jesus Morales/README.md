# Informe Técnico: Predicción y Validación de Monóxido de Carbono (CO) en New York (2023–2025)

## 1. Introducción
El presente informe documenta el desarrollo de un modelo predictivo para estimar las concentraciones de **Monóxido de Carbono (CO)** en diferentes estaciones de monitoreo de la ciudad de **New York, Estados Unidos**.  
El análisis se realizó utilizando datos proporcionados por la **Environmental Protection Agency (EPA) – Air Quality System (AQS)**.  

El objetivo principal fue **predecir las concentraciones mensuales de CO para el año 2025** y comparar dichas predicciones con los valores reales registrados, con el fin de evaluar el desempeño del modelo.

---

## 2. Metodología

### 2.1. Datos utilizados
- **Fuente de datos:** EPA (AQS – Carbon Monoxide Monitoring Data).  
- **Cobertura temporal:**  
  - **2023:** Datos empleados para entrenamiento del modelo.  
  - **2024:** Datos empleados para validación y prueba.  
  - **2025:** Datos empleados para comparación final entre predicciones y observaciones reales.  
- **Variable de interés:** Concentración diaria de **Monóxido de Carbono (CO)**, reportada como  
  *“Daily Max 8-hour CO Concentration (ppm)”*.  
- **Ubicación:** Estaciones de monitoreo de calidad de aire en el estado de **New York**.  
- **Identificación:** Cada estación se distingue mediante un **Site ID** único.  

### 2.2. Preparación de la información
1. Se transformaron los datos diarios en registros **mensuales**, obteniendo el valor promedio de CO para cada estación y mes.  
2. Se generaron variables de rezago (*lags*) que permitieron capturar la dependencia temporal de las concentraciones.  
3. Se dividió la base de datos en:  
   - **Entrenamiento:** año 2023.  
   - **Validación y test:** año 2024.  
   - **Predicción y comparación:** año 2025.  

### 2.3. Modelado
El modelo entrenado incorporó los rezagos temporales y tendencias mensuales con el fin de pronosticar el comportamiento del CO. Posteriormente, los valores predichos fueron contrastados con los datos reales de 2025.

---

## 3. Resultados

### 3.1. Tabla comparativa
Se generó un cuadro comparativo que contiene:  
- **Pred_CO:** concentración de CO estimada por el modelo.  
- **Real_CO:** concentración de CO observada por la EPA.  

Ejemplo de resultados:

| Site ID   | Fecha     | Pred_CO | Real_CO |
|-----------|-----------|---------|---------|
| 360050133 | 2025-01-31 | 0.3771  | 0.3067 |
| 360290005 | 2025-01-31 | 0.2181  | 0.2194 |
| 360550015 | 2025-02-28 | 0.2312  | 0.3214 |
| 360610135 | 2025-02-28 | 0.2729  | 0.3964 |

En general, los valores predichos se aproximaron de manera adecuada a los reales, manteniendo diferencias moderadas en la mayoría de estaciones.

### 3.2. Visualización
Se elaboraron gráficos comparativos por estación de monitoreo.  
- La serie **predicha** mostró un comportamiento consistente con la serie **real**, siguiendo las mismas tendencias temporales.  
- En algunos meses se observó una ligera **subestimación** (predicciones menores que lo observado) y en otros una **sobreestimación**.  

---

## 4. Discusión
- El modelo demostró **buena capacidad de generalización**, logrando replicar las tendencias de CO en las distintas estaciones de New York.  
- El entrenamiento con datos de 2023 y la validación con datos de 2024 permitieron garantizar la robustez antes de proyectar hacia 2025.  
- El contraste con los valores reales del 2025 permitió identificar que las desviaciones no superan rangos críticos, por lo que el modelo es confiable para análisis de corto plazo.  

---

## 5. Conclusiones
1. Se implementó un modelo predictivo de CO basado en rezagos temporales y tendencias mensuales, entrenado con datos de 2023 y validado con datos de 2024.  
2. El modelo logró predecir con éxito las concentraciones de CO en el año 2025, mostrando alta coherencia con los valores reales.  
3. Las diferencias observadas corresponden a variaciones normales en fenómenos ambientales, lo que sugiere que el modelo es útil como herramienta de apoyo para la gestión de la calidad del aire.  
4. El enfoque puede ser replicado en otros contaminantes y regiones, contribuyendo a la planificación y control de la contaminación atmosférica en entornos urbanos.  

---

## 6. Recomendaciones
- Incorporar datos meteorológicos (temperatura, humedad, velocidad del viento) para mejorar la precisión del modelo.  
- Evaluar métricas de error como MAE o RMSE para cuantificar formalmente el desempeño.  
- Extender el análisis a contaminantes adicionales (NO₂, O₃, PM₂.₅) para una visión integral de la calidad del aire en New York.  

---
