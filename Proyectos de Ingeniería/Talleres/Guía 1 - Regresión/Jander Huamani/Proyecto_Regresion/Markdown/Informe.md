# Informe: Predicción de CO en el Condado de Douglas (2022–2025)

## Introducción
La contaminación por monóxido de carbono (CO) es un problema relevante para la salud pública y el medio ambiente. Con el fin de evaluar tendencias y apoyar la toma de decisiones, se desarrolló un modelo de predicción para estimar los valores diarios de CO en el condado de Douglas, utilizando series históricas de datos provenientes de la **EPA Air Quality System (AQS)** para los años 2022, 2023 y 2025.  

El objetivo principal fue **predecir los niveles diarios de CO en 2025** a partir de los datos de entrenamiento (2022–2023, y 2024 si estuviera disponible), y posteriormente comparar las predicciones con los valores reales del año 2025.

---

## Metodología
El trabajo se estructuró en cuatro etapas principales:

1. **Preparación de datos**  
   - Se cargaron los datasets en formato `.csv` correspondientes a los años 2022, 2023 y 2025.  
   - Se seleccionó como variable objetivo (*target*) la columna asociada a los valores diarios de CO.  
   - Los datos fueron limpiados y transformados para garantizar fechas consistentes y sin valores faltantes.

2. **Construcción de características (features)**  
   - **Calendario**: mes, día de la semana y día del año.  
   - **Variables de rezago (lags)**: valor de CO del día anterior (`lag1`) y de la semana anterior (`lag7`).  
   - **Medias móviles (rolling)**: promedio móvil de 7 y 30 días (`rm7`, `rm30`).

3. **División temporal del dataset**  
   - Conjunto de entrenamiento: años 2022 y 2023 (más 2024 si disponible).  
   - Conjunto de prueba: año 2025 completo (comparación final).  
   - La división fue estrictamente temporal para evitar fuga de información (no se utilizó split aleatorio).

4. **Modelo de predicción**  
   - Se utilizó el algoritmo **Random Forest Regressor** (`scikit-learn`).  
   - Parámetros principales: `n_estimators=400`, `max_depth=None`, `random_state=42`.  
   - Métricas de evaluación: **MAE** (Mean Absolute Error), **RMSE** (Root Mean Squared Error) y **R²** (coeficiente de determinación).

---

## Resultados
- Métricas obtenidas en el conjunto de prueba (2025):  
  - **MAE = 0.1088**  
  - **RMSE = 0.1419**  
  - **R² = –0.0724**

- El modelo logra **aproximar la tendencia general** de los niveles de CO con un error absoluto bajo.  
- Sin embargo, el valor negativo de R² indica que el modelo **no consigue explicar la variabilidad total** de los datos mejor que una predicción promedio.  
- En la gráfica comparativa, las predicciones presentan un comportamiento **suavizado**, capturando la media general pero sin reproducir los picos y caídas bruscas de los valores reales.

---

## Discusión
El desempeño del modelo muestra la utilidad del enfoque de Random Forest para estimar niveles promedio de CO, pero también evidencia sus limitaciones:  

- **Ventajas**: robustez frente al ruido, capacidad de capturar relaciones no lineales, bajo MAE y RMSE.  
- **Limitaciones**: dificultad para anticipar eventos extremos (altos picos de contaminación), reflejada en el bajo R².  
- **Posibles mejoras**:  
  - Incluir variables exógenas como temperatura, humedad, velocidad del viento o tráfico vehicular.  
  - Probar modelos de series temporales especializados (XGBoost,Prophet).  
  - Ampliar el rango histórico de entrenamiento (años previos a 2022, o añadir 2024).

---

## Referencias
- [1] Breiman, L. (2001). Random forests. Machine Learning, 45(1), 5–32. https://doi.org/10.1023/A:1010933404324
- [2] Pedregosa, F., Varoquaux, G., Gramfort, A., Michel, V., Thirion, B., Grisel, O., Blondel, M., Prettenhofer, P., Weiss, R., Dubourg, V., Vanderplas, J., Passos, A., Cournapeau, D., Brucher, M., Perrot, M., & Duchesnay, É. (2011). Scikit-learn: Machine learning in Python. Journal of Machine Learning Research, 12, 2825–2830. http://jmlr.org/papers/v12/pedregosa11a.html
- [3] United States Environmental Protection Agency. (n.d.). Air Quality System (AQS). U.S. Environmental Protection Agency. https://www.epa.gov/outdoor-air-quality-data/download-daily-data
