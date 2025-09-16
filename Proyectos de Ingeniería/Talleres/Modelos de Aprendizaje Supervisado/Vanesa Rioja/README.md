## 1. Procedimiento

### 1.1. Clasificación multiclase (dataset Healthcare)
1. **Carga y FE:** creación de `Stay_Days = Discharge Date – Date of Admission`.  
2. **Selección de variables:** `y = Test Results`; `X` excluye `Name`, `Doctor`, `Room Number`, fechas crudas.  
3. **Preprocesamiento:** `ColumnTransformer` con `OneHotEncoder` y escalado en numéricas.  
4. **Split:** `train_test_split(test_size=0.2, stratify=y, random_state=42)`.  
5. **Modelo:** `LogisticRegression(solver="saga")`.  
6. **Evaluación:** `classification_report`, accuracy y matriz de confusión.

### 1.2. Clasificación KNN (dataset Classified Data)
1. **Escalado:** `StandardScaler` sobre todas las features.  
2. **Split:** 50/50 con `random_state=101`.  
3. **Modelo base:** `KNeighborsClassifier(n_neighbors=11)`.  
4. **Mejora del error:** `GridSearchCV` con parrilla en `n_neighbors`, `weights ∈ {uniform, distance}`, `p ∈ {1,2}` y `cv=5–10`.  
5. **Elbow:** curva de error en train mediante `cross_val_score`.  
6. **Métricas finales:** accuracy y matriz de confusión.

---

## 2. Análisis y discusión
- **Preprocesamiento**: el One Hot Encoder habilita modelos lineales en datos categóricos; el escalado es crítico para KNN.  
- **Hiperparámetros**: `weights='distance'` y `p={1,2}` cambian la frontera de decisión; un `k` muy bajo sobreajusta y uno muy alto sub-ajusta.  
- **Validez**: al evitar fugas de datos el rendimiento baja ligeramente pero refleja mejor la generalización.

