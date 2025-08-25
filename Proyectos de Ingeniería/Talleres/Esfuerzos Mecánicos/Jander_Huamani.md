# Informe de Simulación en SimScale

## 1. Introducción
La plataforma **SimScale** permite realizar análisis de elementos finitos (FEA) directamente desde la nube, facilitando la evaluación estructural de piezas en diferentes condiciones de carga y material.  
El presente informe documenta las simulaciones realizadas sobre un modelo 3D de un vaso cilíndrico con tapa inferior, fabricado virtualmente en material PLA, para estudiar su comportamiento bajo diferentes condiciones de fuerza.

## 2. Metodología
- **Modelo empleado**: Archivo STL de un vaso en forma de cilindro de revolución con tapa en la base.  
- **Material**: PLA (polímero de ácido poliláctico).  
- **Magnitud de fuerzas**: Se aplicaron fuerzas de 5000 N y 500000 N en diferentes configuraciones.  
- **Condiciones de contorno**:
  - Soporte fijo en base o contornos circulares según el caso.
  - Fuerzas aplicadas en dirección del eje Z, apuntando hacia arriba.

---

## 3. Resultados de las Simulaciones

### 3.1. Run 1
- **Configuración**:  
  - Soporte fijo en la base del vaso.  
  - Fuerza de 5000 N aplicada en el contorno superior.  
- **Resultado**: No se observó deformación apreciable en el modelo.  

**Imagen de soporte y fuerza:**  
![Soporte y Fuerza - Run 1](Proyectos de Ingeniería/Imágenes/SUPPORT.png)

**Imagen de mapa de calor (resultado):**  
![Mapa de Calor - Run 1](Proyectos de Ingeniería/Imágenes/RUN 1.png)

---

### 3.2. Run 2
- **Configuración**:  
  - Soporte fijo en la base.  
  - Fuerza de 5000 N aplicada en la arista superior.  
- **Resultado**: Similar al Run 1, no se observó deformación apreciable.

**Imagen de soporte y fuerza:**  
![Soporte y Fuerza - Run 2](Proyectos de Ingeniería/Imágenes/FORCE AND SUPPORT 2.png)

**Imagen de mapa de calor (resultado):**  
![Mapa de Calor - Run 2](Proyectos de Ingeniería/Imágenes/RUN 2.png)

---

### 3.3. Run 3
- **Configuración**:  
  - Soporte fijo en contorno circular de la base (sin tapa).  
  - Fuerza vertical de 500000 N aplicada en el contorno superior.  
- **Resultado**: Se observó deformación significativa; el vaso se estiró en dirección del eje Z.

**Imagen de soporte y fuerza:**  
![Soporte y Fuerza - Run 3](Proyectos de Ingeniería/Imágenes/RUN 3 FORCE AND SUPPORT.png)

**Imagen de mapa de calor (resultado):**  
![Mapa de Calor - Run 3](Proyectos de Ingeniería/Imágenes/RUN 3.png)

---

## 4. Discusión
- Las simulaciones muestran que la magnitud de la fuerza aplicada influye directamente en la deformación estructural.  
- A bajas cargas (5000 N), el material PLA soporta sin deformarse significativamente.  
- A cargas extremadamente altas (500000 N), el modelo exhibe deformación notable.  
- La distribución de la carga y la geometría de la pieza afectan el comportamiento estructural.

---

## 5. Conclusiones
- La plataforma SimScale es eficaz para estudiar la respuesta mecánica de piezas bajo diferentes condiciones de carga.  
- Se confirmó que el material PLA soporta fuerzas moderadas sin deformarse.  
- Se recomienda realizar simulaciones adicionales con diferentes materiales y configuraciones de carga para ampliar el estudio.
