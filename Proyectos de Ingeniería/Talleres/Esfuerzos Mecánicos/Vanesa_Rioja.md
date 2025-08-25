## 1. Introducción
El análisis por elementos finitos (FEA) en ingeniería es fundamental para predecir el comportamiento de componentes bajo diferentes tipos fuerzas y carga.  
En este taller se utilizó la aplicación **SimScale**, una plataforma de simulación, para analizar una pieza importada desde Onshape bajo condiciones de **tracción** (fuerza positiva en eje X) y **compresión** (fuerza negativa en eje X).  

El estudio incluyó la definición de condiciones de frontera, mallado, aplicación de cargas y visualización de resultados teniendo en cuenta el **desplazamientos** y **esfuerzos de Von Mises**, permitiéndonos evaluar la respuesta estructural de la pieza y anticipar posibles fallas mecánicas.  

---

## 2. Evidencia y Resultados

### 2.1 Selección del material
Se seleccionó el material PLA con un modulo de Young de 3.5e+9 Pa, un radio de Poisson de 0.36 y una densidad de 1250 gk/m^3.

---

### 2.2 Mallado de la pieza
Se generó un mallado automático con refinamiento en las zonas críticas. 

![Mesh](https://github.com/VictorRiveraT/Proyectos-de-Ingenier-a-1/blob/main/Proyectos%20de%20Ingenier%C3%ADa/Im%C3%A1genes/mallado.png)

---

### 2.2 Simulación de Tracción (Fuerza = +1000 N en eje X)
En esta condición, se aplicó una carga de **+1000 N** en la dirección positiva del eje X, contando con una superficie de soporte fijo ubicado a la izquierda de la pieza. La pieza mostró un desplazamiento hacia la derecha y una distribución de esfuerzos concentrada en la zona de fijación.  

![tracción](https://github.com/VictorRiveraT/Proyectos-de-Ingenier-a-1/blob/main/Proyectos%20de%20Ingenier%C3%ADa/Im%C3%A1genes/tracci%C3%B3n.png)

---

### 2.3 Simulación de Compresión (Fuerza = -1000 N en eje X)
Se aplicó una fuerza de **-1000 N** en la dirección negativa del eje X, generando una compresión de la pieza. En este caso también se cuenta con una superficie de soporte fijo ubicado a la izquierda de la pieza. La deformación ocurre en sentido contrario a la tracción, y la concentración de esfuerzos se observa también en los laterales.  

![compresión](https://github.com/VictorRiveraT/Proyectos-de-Ingenier-a-1/blob/main/Proyectos%20de%20Ingenier%C3%ADa/Im%C3%A1genes/compresi%C3%B3n.png)

---

### 2.4 Análisis comparativo
- En tracción, los esfuerzos tienden a alargarse, distribuyéndose en la dirección de la fuerza.  
- En compresión, los esfuerzos tienden a acumularse en los laterales, aumentando el riesgo de aplastamiento en ciertas zonas.  
- Los valores máximos de esfuerzo se concentran en las superficies donde la pieza se encuentra restringida.  

---

## 3. Conclusiones
- La plataforma **SimScale** permitió simular adecuadamente los efectos de tracción y compresión en la pieza.  
- La visualización con mapas de color facilita la identificación de zonas críticas de esfuerzo.  
- El método de elementos finitos confirma que los puntos de fijación concentran mayores tensiones, lo cual es consistente con la teoría de resistencia de materiales.  
- Esta práctica refuerza la importancia de realizar simulaciones previas en diseños mecánicos para prevenir fallas y optimizar geometrías.  
