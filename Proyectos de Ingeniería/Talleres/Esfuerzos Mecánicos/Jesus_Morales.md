# Simulación Estructural

## 📌 Descripción 
Consiste en la simulación estructural de un cajetín diseñado en **Onshape** e importado a **SimScale**.  
El objetivo fue analizar el comportamiento mecánico del modelo al aplicarle una fuerza en una dirección específica, verificando el desplazamiento y la distribución de esfuerzos.

## ⚙️ Configuración de la Simulación

- **Software utilizado:** SimScale (análisis estático lineal).
- **Geometría:** Cajetín importado desde Onshape.
- **Material:** PLA (Polylactic Acid).
- **Condiciones de frontera:**
  - Base del cajetín fijada (restricción total de desplazamientos).
  - Fuerza aplicada en el eje **X** con magnitud de **500 N**.
- **Mallado:** Generado automáticamente con refinamiento estándar.

## 📊 Resultados

La simulación permitió visualizar:
- El **mapa de desplazamientos**, que muestra la deformación bajo la carga aplicada.
- La **distribución de esfuerzos de Von Mises**, que permite identificar zonas críticas en el cajetín.
- Se realizó 3 pruebas de estiramiento y compresión, aplicando 500N, las imagenes se encuentran en evidencias.

Se observa que las zonas de mayor concentración de esfuerzos se encuentran alrededor del área cercana a la fijación, mientras que el resto del cuerpo presenta esfuerzos menores.

## 🖼️ Evidencias

A continuación se presentan las capturas de cada etapa y del resultado final de la simulación:

### 🔹 Paso 1 – Importación del modelo desde Onshape
<img width="1119" height="853" alt="image" src="https://github.com/user-attachments/assets/ce79b466-f9eb-4d69-822c-a0a0b3047b45" />

### 🔹 Paso 2 – Definición de material
<img width="1209" height="838" alt="image" src="https://github.com/user-attachments/assets/ca7009ea-2fbf-409a-a1fa-a8352fb4e007" />

<img width="766" height="785" alt="image" src="https://github.com/user-attachments/assets/bc79df8a-2dab-4fd7-9869-e49b7f3fb10d" />

### 🔹 Paso 3 – Condiciones de frontera
<img width="1176" height="673" alt="image" src="https://github.com/user-attachments/assets/7c8bda9a-1964-40e1-b369-c47624db5705" />

<img width="1381" height="793" alt="image" src="https://github.com/user-attachments/assets/7d15c25c-ef62-4b96-bf73-6b03b1dcecfb" />

### 🔹 Paso 4 – Generación de malla
<img width="1272" height="693" alt="image" src="https://github.com/user-attachments/assets/8dd17953-2a13-4738-88fe-3fc7d7519ea1" />

### 🔹 Resultado final – Mapa de calor
<img width="1915" height="913" alt="image" src="https://github.com/user-attachments/assets/8e8c391c-b40e-4763-a88e-c4c6986e1424" />

<img width="1919" height="913" alt="image" src="https://github.com/user-attachments/assets/86f8079b-45d5-4547-8ae4-36aa998257a0" />

<img width="1919" height="909" alt="image" src="https://github.com/user-attachments/assets/45afe530-2925-4013-910e-76f522668b58" />

## ✅ Conclusiones

- El cajetín fabricado en PLA resiste adecuadamente la carga de **500 N** en dirección X, presentando deformaciones dentro de un rango esperado para el material.  
- La fijación en la base es la zona crítica, por lo que en un diseño real se recomienda reforzar esta área para evitar concentraciones excesivas de tensión.  
- El análisis confirma la utilidad de **SimScale** para la validación inicial de diseños provenientes de **Onshape**.

