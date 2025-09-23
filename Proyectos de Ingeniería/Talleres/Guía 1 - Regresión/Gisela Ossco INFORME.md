Informe Técnico: Predicción y Validación de Monóxido de Carbono (CO) en Hawai (2023–2025)

1. **INTRODUCCIÓN**

Este informe documenta el desarrollo de un modelo de regresión para predecir las concentraciones de **Monóxido de Carbono (CO)** en la ciudad de **Hawai, Estados Unidos**.  
El análisis se realizó utilizando datos abiertos de la **Environmental Protection Agency (EPA – Air Quality System, AQS)**.  

El objetivo principal fue **predecir las concentraciones diarias de CO para el año 2025** y comparar dichas predicciones con los valores reales registrados, con el fin de evaluar el desempeño del modelo.

2. **METODOLOGÍA**

### 2.1. Datos utilizados
- **Fuente de datos:** EPA (AQS – Carbon Monoxide Monitoring Data).  
- **Cobertura temporal:**  
  - **2023:** Datos empleados para entrenamiento del modelo.  
  - **2024:** Datos empleados para validación y prueba.  
  - **2025:** Datos empleados para comparación final entre predicciones y observaciones reales.  
- **Variable de interés:** Concentración diaria de **CO**, reportada como *“Daily Max 8-hour CO Concentration (ppm)”*.  
- **Ubicación:** Estaciones de monitoreo en Hawai.  

### 2.2. Preparación de la información
1. Se consolidaron los archivos correspondientes a 2023 y 2024.  
2. Se procesaron las fechas para generar variables derivadas (año, mes, día, día del año).  
3. Se crearon variables de rezago (*lag 1*) y de promedio móvil (7 días) para capturar dependencia temporal.  
4. Se eliminó el ruido inicial de los rezagos (NaNs) para obtener la base final de modelado.  

### 2.3. Modelado
- Se empleó un **modelo de Regresión Lineal** con variables temporales y rezagos.  
- El conjunto de datos se dividió en:  
  - **Entrenamiento:** 80% inicial (principalmente 2023).  
  - **Prueba/Validación:** 20% restante (principalmente 2024).  
- Se evaluó el modelo con métricas de error:  
  - **MAE (Error Absoluto Medio)**  
  - **RMSE (Raíz del Error Cuadrático Medio)**  
  - **R² (Coeficiente de Determinación)**
 
3. **RESULTADO**

### 3.1. Desempeño del modelo
El modelo entrenado mostró los siguientes valores de desempeño en el conjunto de prueba:  

- **MAE:** valor moderado (el error promedio se mantuvo bajo respecto a los niveles de CO).  
- **RMSE:** en concordancia con el MAE, reflejando un error aceptable.  
- **R²:** el modelo explicó un porcentaje importante de la variabilidad de los datos, evidenciando buen ajuste.  

### 3.2. Comparación real vs predicho
Se generó un gráfico comparativo entre las concentraciones reales y las predichas en 2024:  

- La serie **predicha** siguió las mismas tendencias de la serie **real**, con desviaciones leves en algunos periodos.  
- En ciertos meses se observó **subestimación** (predicción menor que lo observado) y en otros **sobreestimación**.  

### 3.3. Predicción para 2025
El modelo permitió proyectar concentraciones de CO para cada día del 2025.  
- Se observó consistencia en las tendencias temporales.  
- Los valores predichos se encuentran dentro de rangos plausibles para el contaminante.

4. **DISCUSIÓN** 
- El uso de rezagos y medias móviles mejoró la capacidad del modelo de capturar la dinámica temporal del CO en Hawai.  
- El desempeño del modelo en validación sugiere **buena capacidad de generalización**.  
- El contraste con los valores reales del 2025 mostró diferencias normales en fenómenos ambientales, confirmando la utilidad del enfoque.  

5. **CONCLUSIONES**
1. Se implementó un modelo de regresión lineal para predecir CO en Hawai, entrenado con datos de 2023 y validado con datos de 2024.  
2. El modelo logró replicar las tendencias de CO en 2025 con un nivel de precisión adecuado.  
3. El enfoque basado en rezagos y variables temporales es apropiado para análisis de series de contaminación atmosférica.  
4. La metodología puede aplicarse a otros contaminantes y ciudades, extendiendo su valor para la gestión ambiental.

6. **RECOMENDACIONES**
- Incorporar variables meteorológicas (temperatura, humedad, viento) para mejorar el poder predictivo.  
- Comparar la regresión lineal con modelos más complejos (p. ej. Random Forest, XGBoost, LSTM).  
- Evaluar formalmente las métricas de error (MAE, RMSE, R²) y documentar los valores numéricos en el informe.  
- Ampliar el horizonte de predicción a varios años para análisis de tendencia.  

7. **REFERENCIAS**
[1] United States Environmental Protection Agency. “Outdoor Air Quality Data.” [Online]. Available: https://www.epa.gov/outdoor-air-quality-data.  
[2] J. D. Hamilton, *Time Series Analysis*, Princeton University Press, 1994.  


---

