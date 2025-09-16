**Procedimiento**

1.1 Clasificación Multiclase (Dataset: Salud)

-Carga y feature engineering: Se genera la variable ´´Stay_Days´´ a partir de la diferencia entre la fecha de alta y la fecha de admisión.

-Selección de variables: La variable objetivo será Test Results. Como predictores se toman todas las columnas excepto las de identificación (Nombre, Doctor, Número de Habitación) y las fechas originales.

-Preprocesamiento: Se implementa un ColumnTransformer que aplica OneHotEncoder en las variables categóricas y normalización en las variables numéricas.

-Partición del dataset: Se divide en entrenamiento y prueba con train_test_split, manteniendo estratificación en y, un 20% para test y random_state=42.

-Modelo: Se entrena una Regresión Logística con el solver "saga", adecuado para problemas multiclase y datasets con variables codificadas.

Evaluación: Se obtiene el classification_report, exactitud global y matriz de confusión para analizar el desempeño.



