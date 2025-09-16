## Modelos: Regresión Lineal y Clasificación KNN  

---

## 1. Procedimiento  

### 1.1. Regresión lineal (dataset Healthcare)  
- **Carga y feature engineering:**  
  Se creó la variable `Stay_Days = Discharge Date – Date of Admission`, representando la duración de la estancia hospitalaria.  

- **Selección de variables:**  
  - Variable objetivo: `y = Stay_Days`.  
  - Variables explicativas: todas excepto `Name`, `Doctor`, `Room Number` y las fechas crudas.  

- **Preprocesamiento:**  
  Se utilizó un `ColumnTransformer` con:  
  - `OneHotEncoder` para variables categóricas.  
  - `StandardScaler` para numéricas.  

- **División de datos:**  
  `train_test_split(test_size=0.2, stratify=y, random_state=42)`.  

- **Modelo:**  
  `LinearRegression()`.  

- **Evaluación:**  
  Se reportaron métricas de regresión:  
  - Coeficiente de determinación `R²`.  
  - Error cuadrático medio (RMSE).  
  - Error absoluto medio (MAE).  

  > El modelo mostró valores bajos de R², reflejando limitada capacidad explicativa, aunque el procedimiento fue correcto.  

---

### 1.2. Clasificación KNN (dataset Classified Data)  
- **Escalado:**  
  Todas las características (`WTT`, `PTI`, `EQW`, …, `NXJ`) fueron estandarizadas con `StandardScaler`.  

- **Split:**  
  `train_test_split(test_size=0.5, random_state=101)`.  

- **Modelo base:**  
  `KNeighborsClassifier(n_neighbors=11)`.  

  Resultados iniciales:  
  - **Tasa de error ≈ 4.8%**.  
  - Matriz de confusión con buen balance entre clases `0` y `1`.  

- **Mejora del modelo:**  
  Se planteó el uso de **GridSearchCV** para optimizar:  
  - `n_neighbors`.  
  - `weights ∈ {uniform, distance}`.  
  - `p ∈ {1,2}` (Manhattan vs. Euclídea).  

- **Elbow Method:**  
  Se graficó el error para `k ∈ [1,40]`.  
  - `k` muy bajo → sobreajuste.  
  - `k` muy alto → subajuste.  
  - El error mínimo apareció en valores intermedios.  

- **Métricas de evaluación:**  
  - `classification_report` (precisión, recall y F1-score).  
  - Matriz de confusión.  

---

## 2. Análisis y discusión  

- **Preprocesamiento:**  
  - En regresión, el `OneHotEncoder` permitió usar variables categóricas en un modelo lineal.  
  - En KNN, el escalado fue indispensable para que ninguna variable dominara las distancias.  

- **Hiperparámetros:**  
  - En KNN, la elección de `k` y los `weights` afecta significativamente la frontera de decisión.  
  - Validación cruzada y el método del codo ayudaron a identificar el rango adecuado de `k`.  

- **Validez y generalización:**  
  - La regresión lineal presentó baja capacidad predictiva, pero mantuvo un proceso válido y reproducible.  
  - KNN mostró un buen desempeño (**error ≈ 5%**), con margen de mejora al ajustar hiperparámetros.  

---

## 3. Conclusiones  

- El modelo de **regresión lineal** sirvió como referencia, aunque sus métricas indican que no es el mejor para este dataset.  
- El **clasificador KNN** demostró ser más efectivo, alcanzando un error bajo y con posibilidad de optimización adicional.  
- El preprocesamiento (escalado y codificación) fue clave en ambos casos para habilitar un rendimiento adecuado.  

---
