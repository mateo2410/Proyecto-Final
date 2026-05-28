# Bitácora de uso de IA generativa
## Proyecto: EcoMisión
## Integrantes: Diego Calvo y Mateo Rivera

---

## ¿Para qué usamos IA generativa?

Usamos IA generativa como herramienta de apoyo durante el desarrollo del proyecto. 
La usamos principalmente para resolver errores de compilación, entender conceptos 
nuevos y tomar decisiones de diseño. En ningún momento fue usada para generar el 
código completo del proyecto, sino para guiar el aprendizaje y resolver dudas 
puntuales.

---

## Decisiones de diseño revisadas con IA

### 1. Vector vs arreglo en Zona
Consultamos con IA si era mejor usar un arreglo fijo o un vector para guardar los 
elementos en la clase Zona. La IA nos explicó que el vector era mejor porque crece 
automáticamente sin necesidad de definir un tamaño máximo desde el principio, 
lo cual es más flexible para una zona que puede tener diferente cantidad de elementos.
*Decisión aceptada* porque tiene justificación técnica clara.

### 2. Orden de construcción de las clases
Consultamos con IA cuál era el orden correcto para construir las clases del proyecto.
La IA nos recomendó construir de adentro hacia afuera:
Explorador → ElementoInteractivo → clases hijas → Zona → Reserva → EcoMision.
*Decisión aceptada* porque cada clase depende de las anteriores y este orden 
evita errores de compilación por referencias a clases no definidas.

---

## Sugerencias de IA aceptadas y por qué

### 1. Uso de std::transform para búsqueda sin distinción de mayúsculas
Tuvimos el problema de que si el usuario escribía "animal herido" en minúsculas 
el programa no encontraba el elemento porque estaba guardado como "Animal Herido". 
La IA nos sugirió usar std::transform con tolower para convertir ambos textos a 
minúsculas antes de compararlos.
*Aceptamos* porque resolvió el problema y hace la experiencia más amigable para 
el usuario.

### 2. Forward declaration de Zona en Explorador.h
Tuvimos un error de compilación porque Explorador usaba Zona* pero Zona no estaba 
definida todavía. La IA nos sugirió agregar class Zona; antes de la clase Explorador 
como forward declaration.
*Aceptamos* porque resolvió el error sin necesidad de incluir el archivo completo 
y es una práctica estándar en C++.

### 3. Uso de try-catch con stoi para leer opciones del menú
Tuvimos el problema de que al presionar Enter sin escribir nada o al escribir texto 
en lugar de un número el programa se caía. La IA nos sugirió usar try-catch con 
stoi para manejar ese error.
*Aceptamos* porque hace el programa más robusto y evita que se caiga por entradas 
inválidas del usuario.

---

## Sugerencias de IA corregidas o rechazadas y por qué

### 1. Corrección de errores de sintaxis
En varios momentos enviamos código con errores de escritura como palabras incompletas,
falta de punto y coma o llaves mal ubicadas. La IA identificó los errores pero 
nosotros los corregimos manualmente en CodeBlocks para entender qué estaba mal y 
por qué, en lugar de simplemente copiar la corrección.

### 2. cin.ignore vs getline para leer el menú
La IA inicialmente sugirió usar cin.ignore para resolver el problema del buffer. 
Después de probarlo y ver que no funcionaba completamente, consultamos de nuevo y 
la IA sugirió cambiar a getline para toda la lectura del menú. Aceptamos el cambio 
después de entender por qué getline era mejor en este caso.

---

## ¿Qué parte del proyecto debe defender cada integrante?

### Diego Calvo y Mateo Rivera
Ambos integrantes tienen conocimiento completo del código ya que trabajamos juntos 
en cada parte del proyecto desde el diseño inicial hasta la implementación final. 
Estudiamos y construimos cada clase juntos, por lo tanto ambos podemos defender 
cualquier parte del código, explicar las decisiones de diseño y responder preguntas 
sobre cualquier concepto aplicado.
