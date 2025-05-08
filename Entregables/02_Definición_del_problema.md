# Definición del Problema

**Problema:** La medición en campo de la calidad del aceite reutilizado en establecimientos gastronómicos carece de métodos accesibles y eficaces, lo que dificulta la fiscalización sanitaria y expone a consumidores a subproductos tóxicos, lo que afecta la salud pública.

-----

![image](https://github.com/user-attachments/assets/a8698fb6-a0be-44e7-9e8e-d34798f6d9ae)
<sup>FUENTE: Getty Images / Sinc</sup>

El uso reiterado de aceite de cocina en establecimientos gastronómicos representa un riesgo crítico para la salud pública, especialmente en contextos donde el costo del insumo ha aumentado y las regulaciones son escasas o carecen de mecanismos de verificación técnica. Al someterse a temperaturas superiores a 180 °C de forma continua, el aceite inicia reacciones de oxidación de ácidos grasos insaturados, polimerización de triglicéridos e hidrólisis de enlaces éster, generando una mezcla compleja de compuestos peligrosos. Entre ellos destacan aldehídos reactivos (4-HNE, MDA), productos de glicación avanzada (AGEs), ácidos grasos trans y radicales libres, todos asociados a la inflamación crónica, disfunción endotelial y daño mitocondrial en tejidos cardiovasculares, hepáticos y neurológicos. La inhalación de aerosoles de estos subproductos, reportada en cocinas industriales, también incrementa la incidencia de asma ocupacional y enfermedades respiratorias crónicas en el personal de cocina <sup>1</sup> <sup>2</sup>.

Investigaciones de la Universidad de Reading y la Universidad de Illinois han demostrado que la ingestión o inhalación de estos compuestos produce estrés oxidativo a nivel celular, comprometiendo la integridad del ADN y promoviendo procesos carcinogénicos en el tracto digestivo y pulmonar <sup>3</sup> <sup>4</sup>.

### Definir el usuario (¿Para quién es un problema?)

Este problema afecta principalmente a entidades encargadas de la fiscalización sanitaria como municipalidades, ministerios de salud, ONGs especializadas en nutrición e inocuidad alimentaria, y asociaciones de consumidores. También repercute en los consumidores finales y en el personal de cocina que se expone a vapores tóxicos.

### Definir el contexto (¿Por qué es un problema?)

La reutilización excesiva del aceite es una práctica común en restaurantes informales, carretillas, ferias gastronómicas y comedores populares, debido al aumento de su precio y la falta de conocimiento técnico. Esta situación se ha agudizado tras la pandemia del COVID-19, que impulsó la aparición de nuevos negocios gastronómicos sin fiscalización. En estos espacios, no se realiza ningún tipo de control técnico sobre la calidad del aceite utilizado.

<p align="center">
  <img src="https://github.com/user-attachments/assets/e730a762-6ed2-4e6a-ad94-3306f2478f12" width="300"/>
</p>
<sup>FUENTE: Dreamstime</sup> 

### Definir los puntos de dolor (¿Cuándo y cómo es un problema?)

Cuando los establecimientos gastronómicos reutilizan aceite más allá de los límites seguros sin filtrado ni monitoreo, el riesgo se transfiere directamente al consumidor. Es un problema también cuando las entidades fiscalizadoras no cuentan con herramientas accesibles para medir parámetros de degradación. Además, los trabajadores de cocina pueden inhalar vapores tóxicos producidos por compuestos como los aldehídos volátiles.

### ¿Qué consecuencias tiene si no se resuelve el problema?

Si no se controla esta práctica, se perpetúan efectos nocivos sobre la salud pública: incremento de enfermedades crónicas, como cáncer, Alzheimer, trastornos hepáticos y cardiovasculares<sup>1</sup> <sup>2</sup>. A esto se suman costos médicos indirectos, informalidad en la gestión de residuos y un ambiente propicio para prácticas alimentarias insalubres. También se pierde la oportunidad de generar cultura de prevención sanitaria en el rubro gastronómico <sup>3</sup>.

El aceite reutilizado sufre una transformación química tras múltiples usos a alta temperatura, generando compuestos como aldehídos (4-HNE, MDA), acroleína, acrilamida, hidroperóxidos lipídicos y ácidos grasos trans. Estos compuestos se adhieren y penetran los alimentos fritos, convirtiéndolos en vectores directos de sustancias tóxicas. Su ingesta reiterada se ha relacionado con:
- Aterosclerosis y enfermedad coronaria (por grasas trans) <sup>2</sup>.
- Cáncer de colon y estómago (por acrilamida y 4-HNE) <sup>3</sup>.
- Hígado graso no alcohólico y hepatitis tóxica (por productos oxidativos) <sup>4</sup>.
- Alzheimer y Parkinson (por malondialdehído – MDA) <sup>5</sup>.
- Síndrome metabólico e inflamación crónica <sup>6</sup>.
- Bronquitis y asma ocupacional por inhalación de vapores <sup>7</sup>.

### ¿Cómo se ha intentado resolver este problema hasta ahora?

Las soluciones existentes en Perú y otros países de la región se han centrado en la recolección de aceite usado para su reciclaje como biodiésel. Sin embargo, no existen métodos simples, rápidos ni económicos para determinar la calidad del aceite mientras está en uso activo <sup>4</sup>. La fiscalización sigue dependiendo de observaciones visuales o encuestas, lo cual es subjetivo y fácilmente manipulable <sup>5</sup>.

### Solución Propuesta

Se propone desarrollar un dispositivo portátil, autónomo y de bajo costo que permita medir en campo los parámetros de pH y turbidez del aceite reutilizado. El sistema contará con sensores, pantalla para lectura instantánea, alarmas LED/zumbador para advertencias, y opcionalmente, conectividad para almacenar datos (microSD o Bluetooth).

El sistema permitirá detectar si un aceite ha excedido los límites aceptables (por ejemplo, pH < 4.5 o turbidez > 500 NTU en emulsiones <sup>10</sup>). Esto facilitará la labor de fiscalización, permitirá a negocios informales autocontrolarse, y reducirá riesgos sanitarios en la población.

### Requisitos del Dispositivo
- Sensor de pH (ej: PH-4502C)
- Sensor de turbidez (ej: DFRobot SEN0189)
- Microcontrolador (Arduino UNO o ESP32)
- Pantalla LCD u OLED
- Alarma (buzzer y LED)
- Botón de calibración
- Alimentación por batería recargable o powerbank
- (Opcional) microSD o módulo Bluetooth HC-05

### Público Objetivo

Este sistema está dirigido a:
- Municipalidades y entidades como DIGESA
- ONGs enfocadas en salud pública y nutrición
- Administradores de restaurantes, mercados y comedores
- Escuelas de gastronomía
- Organismos ambientales interesados en residuos oleosos

### Referencias bibliográficas

1) World Health Organization. (s.f.). Healthy diet. WHO. https://www.who.int/news-room/fact-sheets/detail/healthy-diet

2) Harvard T.H. Chan School of Public Health. (s.f.). Trans fats. https://www.hsph.harvard.edu/nutritionsource/transfats/

3) International Agency for Research on Cancer. (s.f.). IARC evaluation of the carcinogenicity of acrylamide. https://www.iarc.who.int/news-events/iarc-evaluation-of-thecarcinogenicity-of-acrylamide/

4) Loguercio, C., & Federico, A. (2005). Oxidative stress in viral and alcoholic hepatitis. Journal of Hepatology, 42(6), 845–851. https://doi.org/10.1016/j.jhep.2005.07.019

5) Esterbauer, H., Schaur, R. J., & Zollner, H. (2014). Chemistry and biochemistry of 4-hydroxynonenal, malonaldehyde and related aldehydes. Neurotoxicology, 45, 10–21. https://doi.org/10.1016/j.neuro.2014.09.007

6) Ministerio del Ambiente. (s.f.). Ley General de Residuos Sólidos - Ley N.º 27314. https://www.gob.pe/institucion/minsa/normas-legales/251249-188-2006-sa-dvm

7) Instituto Nacional de Estadística e Informática (INEI). (2022). Variación de precios al consumidor 2022. https://www.inei.gob.pe/estadisticas/indice-tematico/precios/

9) FAO/WHO. (1994). Grasas y aceites alimentarios en la nutrición humana. Roma: FAO. https://www.fao.org/3/y2774s/y2774s06.htm

10) Lethuaut, L., Bouvier-Navé, P., & Rousseau, D. (2016). Evaluation of frying oil degradation. ResearchGate. https://www.researchgate.net/publication/310742828

# Mapa de Empatía
![WhatsApp Image 2025-05-02 at 1 14 55 PM (2)](https://github.com/user-attachments/assets/daa28ac6-3453-4b49-af6f-ed795f028ffd)


# Mapa del Viajero
![WhatsApp Image 2025-05-02 at 1 14 55 PM (1)](https://github.com/user-attachments/assets/5f3700de-ac01-406a-bfdb-ddc47588fa55)


# Mapa de Ishikawa
![WhatsApp Image 2025-05-02 at 1 14 55 PM](https://github.com/user-attachments/assets/9639c042-5674-4867-a43f-c63ad670bc57)
