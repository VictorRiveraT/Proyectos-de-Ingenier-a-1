**1. PROCEDIMIENTO**

**1.1** Clasificación Multiclase (Dataset: Salud)

-Carga y feature engineering: Se genera la variable **Stay_Days** a partir de la diferencia entre la fecha de alta y la fecha de admisión.

-Selección de variables: La variable objetivo será Test Results. Como predictores se toman todas las columnas excepto las de identificación (Nombre, Doctor, Número de Habitación) y las fechas originales.

-Preprocesamiento: Se implementa un **ColumnTransformer** que aplica OneHotEncoder en las variables categóricas y normalización en las variables numéricas.

-Partición del dataset: Se divide en entrenamiento y prueba con **train_test_split**, manteniendo estratificación en y, un 20% para test y **random_state=42**.

-Modelo: Se entrena una Regresión Logística con el solver **"saga"**, adecuado para problemas multiclase y datasets con variables codificadas.

Evaluación: Se obtiene el **classification_report**, exactitud global y matriz de confusión para analizar el desempeño.


**1.2** Clasificación con KNN (Dataset: Datos Clasificados)

**Normalización**: Se aplican transformaciones con StandardScaler para que todas las variables estén en la misma escala.

**División de datos**: Se separa en entrenamiento y prueba en proporción 50/50, con random_state=101 para asegurar reproducibilidad.

**Modelo inicial**: Se utiliza un clasificador KNN con **n_neighbors=11** como punto de partida.

Optimización de hiperparámetros: Se emplea **GridSearchCV** probando combinaciones de:

-número de vecinos (𝑘),

-tipo de ponderación (uniform o distance),

-distancia de Minkowski con 𝑝 ∈{1,2}, con validación cruzada de 5 a 10 particiones.

**Curva del codo**: Se analiza la evolución del error en entrenamiento y validación con **cross_val_score** para identificar un valor adecuado de 𝑘.

**Métricas finales**: Se reporta la exactitud y la matriz de confusión sobre el conjunto de prueba.

**2. ANALISIS y DISCUSIÓN**

-Preprocesamiento: El OneHotEncoder permite usar modelos lineales con variables categóricas. Para KNN, la estandarización es fundamental porque el algoritmo depende de distancias.

-Ajuste de hiperparámetros: La elección de **weights="distance"** y la métrica (Manhattan o Euclidiana, 
𝑝=1 o 𝑝=2) afecta la frontera de decisión. Valores bajos de 𝑘 generan sobreajuste, mientras que valores muy grandes llevan a subajuste.

-Validez del modelo: Al aplicar correctamente la división entre entrenamiento y prueba se evita data leakage. Esto puede reducir un poco las métricas, pero da una mejor estimación de la capacidad de generalización del modelo.







