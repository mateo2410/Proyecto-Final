# EcoMisión — Evolución del Diagrama UML y Matriz de Decisiones

---

## Versión Inicial del UML

> Diagrama base con las clases principales y sus relaciones generales, antes de comenzar a programar.

```mermaid
classDiagram
    class EcoMision {
        +iniciarSistema() void
    }

    class Reserva {
        -unordered_map~string, Zona~ zonas
        +agregarZona(string codigo, Zona zona) void
        +buscarZona(string zona) Zona
        +mostrarZona() void
    }

    class Zona {
        -string nombre
        -ElementoInteractivo elementos
        +agregarElemento(ElementoInteractivo elemento) void
        +mostrarElementos() void
        +interactuar(ElementoInteractivo elemento) void
    }

    class ElementoInteractivo {
        <<abstract>>
        -string nombre
        +interactuar(Explorador explorador) void
    }

    class Explorador {
        -string nombre
        -int energia
        -int puntajeAmbiental
        -Zona zonaActual
        -int elementos
        +getEnergia() int
        +getPuntaje() int
        +perderEnergia() void
        +ganarEnergia(int cantidad) void
        +ganarPuntaje(int cantidad) void
        +recolectarElemento(string elemento) void
        +cambiarZona(Zona zona) void
    }

    class PlantaMedicinal {
        +interactuar(Explorador explorador) void
    }

    class AnimalHerido {
        +interactuar(Explorador explorador) void
    }

    class ResiduoContaminante {
        +interactuar(Explorador explorador) void
    }

    EcoMision --> Reserva : asociación
    EcoMision --> Explorador : asociación
    Reserva o-- Zona : agregación
    Zona o-- ElementoInteractivo : agregación
    Zona --> Explorador : asociación
    PlantaMedicinal --|> ElementoInteractivo : hereda
    AnimalHerido --|> ElementoInteractivo : hereda
    ResiduoContaminante --|> ElementoInteractivo : hereda
```

### Descripción

En esta primera versión se planteó la idea general del proyecto.
Se definieron las clases principales: `EcoMision`, `Reserva`, `Zona`, `Explorador` y `ElementoInteractivo`.

También se agregó la herencia desde `ElementoInteractivo` hacia `PlantaMedicinal`, `AnimalHerido` y `ResiduoContaminante`, porque cada elemento debía tener una forma diferente de interactuar con el explorador.

---

## Versión Ajustada del UML

> Diagrama actualizado después de comenzar a programar, con los primeros ajustes que aparecieron al implementar las clases en C++.

```mermaid
classDiagram
    class EcoMision {
        -Reserva reserva
        -Explorador* explorador
        +EcoMision()
        +~EcoMision()
        +iniciarSistema() void
    }

    class Reserva {
        -unordered_map~string, Zona*~ zonas
        +agregarZona(string codigo, Zona* z) void
        +buscarZona(string codigo) Zona
        +mostrarZonas() void
    }

    class Zona {
        -string nombre
        -vector~ElementoInteractivo*~ elementos
        +Zona(string n)
        +getNombre() string
        +agregarElemento(ElementoInteractivo* e) void
        +mostrarElementos() void
        +interactuar(int indice, Explorador* explorador) void
        +interactuar(string nombre, Explorador* explorador) void
    }

    class ElementoInteractivo {
        -string nombre
        +ElementoInteractivo(string n)
        +getNombre() string
        +interactuar(Explorador* explorador) void
    }

    class Explorador {
        -string nombre
        -int energia
        -int puntajeAmbiental
        -int elementos
        -Zona* zonaActual
        +Explorador(string n, int e)
        +getNombre() string
        +getEnergia() int
        +getPuntaje() int
        +getZonaActual() Zona
        +perderEnergia(int cantidad) void
        +ganarEnergia(int cantidad) void
        +ganarPuntaje(int cantidad) void
        +recolectarElementos() void
        +cambiarZona(Zona* zona) void
        +mostrarInfo() void
    }

    class AnimalHerido {
        +AnimalHerido(string n)
        +interactuar(Explorador* explorador) void
    }

    class PlantaMedicinal {
        +PlantaMedicinal(string n)
        +interactuar(Explorador* explorador) void
    }

    class ResiduoContaminante {
        +ResiduoContaminante(string n)
        +interactuar(Explorador* explorador) void
    }

    EcoMision --> Reserva
    EcoMision --> Explorador
    Reserva o-- Zona
    Explorador --> Zona
    Zona o-- ElementoInteractivo
    AnimalHerido --|> ElementoInteractivo
    PlantaMedicinal --|> ElementoInteractivo
    ResiduoContaminante --|> ElementoInteractivo
```

### ¿Qué cambió?

* Se agregaron punteros como `Explorador*`, `Zona*` y `ElementoInteractivo*`, porque en C++ era más práctico trabajar con direcciones de memoria y no con copias completas de los objetos.

* En `Zona`, el atributo `elementos` pasó a ser un `vector<ElementoInteractivo*>`. Esto mejoró el diseño porque una zona no debía guardar un solo elemento, sino varios.

* Se agregaron constructores en varias clases para inicializar mejor los objetos desde el comienzo.

* Se agregó el destructor `~EcoMision()`, ya que al usar punteros es importante pensar en la liberación de memoria.

* Se mejoró la interacción en `Zona`, permitiendo interactuar por índice o por nombre. Esto hizo el sistema más flexible para el usuario.

---

## Versión Final del UML

> Diagrama final después de terminar el proyecto, con una estructura más limpia y más cercana al código entregado.

```mermaid
classDiagram
    class EcoMision {
        -Reserva reserva
        -Explorador* explorador
        +EcoMision()
        +iniciarSistema() void
    }

    class Reserva {
        -unordered_map~string, Zona*~ zonas
        +agregarZona(string codigo, Zona* z) void
        +buscarZona(string codigo) void
        +mostrarZonas() void
    }

    class Explorador {
        -string nombre
        -int energia
        -int puntajeAmbiental
        -Zona* zonaActual
        -int elementos
        +Explorador(string n, int e)
        +getNombre() string
        +getEnergia() int
        +getPuntaje() int
        +perderEnergia(int cantidad) void
        +ganarEnergia(int cantidad) void
        +ganarPuntaje(int cantidad) void
        +recolectarElementos() void
        +cambiarZona(Zona* zona) void
        +mostrarInfo() void
    }

    class Zona {
        -string nombre
        -vector~ElementoInteractivo*~ elementos
        +Zona(string n)
        +agregarElemento(ElementoInteractivo* e) void
        +mostrarElementos() void
        +interactuar(int indice, Explorador* explorador) void
        +interactuar(string nombre, Explorador* explorador) void
    }

    class ElementoInteractivo {
        -string nombre
        +ElementoInteractivo(string n)
        +getNombre() string
        +interactuar(Explorador* explorador) void
    }

    class AnimalHerido {
        +AnimalHerido(string n)
        +interactuar(Explorador* explorador) void
    }

    class PlantaMedicinal {
        +PlantaMedicinal(string n)
        +interactuar(Explorador* explorador) void
    }

    class ResiduoContaminante {
        +ResiduoContaminante(string n)
        +interactuar(Explorador* explorador) void
    }

    EcoMision --> Reserva
    EcoMision --> Explorador
    Reserva o-- Zona
    Explorador --> Zona
    Zona o-- ElementoInteractivo
    AnimalHerido --|> ElementoInteractivo
    PlantaMedicinal --|> ElementoInteractivo
    ResiduoContaminante --|> ElementoInteractivo
```

### ¿Qué cambió?

* Se dejó el diagrama más limpio y ordenado, quitando detalles que no eran tan necesarios para entender la estructura principal.

* Se mantuvo el uso de punteros, porque esa fue la forma usada en el código para conectar objetos como el explorador, las zonas y los elementos interactivos.

* Se mantuvo el `vector<ElementoInteractivo*>` en `Zona`, ya que fue clave para guardar varios elementos dentro de una misma zona.

* Se conservó la herencia desde `ElementoInteractivo` hacia las clases hijas, porque ahí se aplica el polimorfismo: cada elemento interactúa de una manera diferente.

* La versión final muestra mejor la idea del sistema: `EcoMision` controla el juego, `Reserva` administra las zonas, `Zona` contiene elementos, `Explorador` representa al jugador y los elementos interactivos modifican su energía o puntaje.



## Matriz de Decisiones

> Esta matriz resume las decisiones principales que se tomaron durante la evolución del UML y por qué esos cambios mejoraron el diseño del proyecto.

<table>
  <thead>
    <tr>
      <th>Decisión</th>
      <th>Alternativas consideradas</th>
      <th>Decisión final</th>
      <th>Justificación</th>
      <th>Riesgo si se modela mal</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Cómo representar las zonas</td>
      <td><code>vector</code>, <code>map</code>, <code>unordered_map</code></td>
      <td><code>unordered_map&lt;string, Zona*&gt;</code></td>
      <td>La reserva busca zonas por código, por ejemplo <code>bosque</code> o <code>rio</code>. Por eso era más práctico usar una estructura que permitiera buscar directamente por clave.</td>
      <td>Se puede complicar la búsqueda de zonas o mezclar la lógica del mapa con la lógica del juego.</td>
    </tr>
    <tr>
      <td>Cómo guardar los elementos de una zona</td>
      <td>Un solo <code>ElementoInteractivo</code>, arreglo fijo, <code>vector</code></td>
      <td><code>vector&lt;ElementoInteractivo*&gt;</code></td>
      <td>Una zona puede tener varios elementos. Con un vector se pueden agregar plantas, animales o residuos de forma dinámica.</td>
      <td>La zona quedaría limitada a un solo elemento o sería difícil agregar nuevos objetos.</td>
    </tr>
    <tr>
      <td>Cómo permitir distintos tipos de elementos</td>
      <td>Muchos <code>if/else</code>, clases separadas sin relación, herencia</td>
      <td>Clase base <code>ElementoInteractivo</code></td>
      <td>Todos los elementos comparten una idea común: pueden interactuar con el explorador. Por eso se creó una clase base.</td>
      <td>El código se volvería repetitivo y cada nuevo elemento obligaría a modificar muchas partes.</td>
    </tr>
    <tr>
      <td>Cómo hacer que cada elemento actúe diferente</td>
      <td>Método general en <code>Zona</code>, condicionales por tipo, polimorfismo</td>
      <td>Método <code>interactuar()</code> en cada clase hija</td>
      <td>Cada elemento sabe qué debe hacer: la planta da energía, el animal da puntaje y el residuo quita energía.</td>
      <td>La clase <code>Zona</code> terminaría haciendo demasiadas cosas y sería más difícil mantener el código.</td>
    </tr>
    <tr>
      <td>Cómo conectar objetos en C++</td>
      <td>Guardar objetos completos, referencias, punteros</td>
      <td>Usar <code>Explorador*</code>, <code>Zona*</code> y <code>ElementoInteractivo*</code></td>
      <td>Los punteros permiten relacionar objetos sin copiarlos completos. También ayudan a trabajar con herencia y polimorfismo.</td>
      <td>Se podrían crear copias innecesarias o perder el comportamiento real de las clases hijas.</td>
    </tr>
    <tr>
      <td>Cómo representar la zona actual del explorador</td>
      <td>Guardar el nombre, guardar una copia de <code>Zona</code>, usar puntero</td>
      <td><code>Zona* zonaActual</code></td>
      <td>El explorador solo necesita apuntar a la zona donde está, sin duplicarla.</td>
      <td>El explorador podría quedar con una zona desactualizada o una copia que no refleja los cambios reales.</td>
    </tr>
    <tr>
      <td>Cómo interactuar con elementos</td>
      <td>Solo por posición, solo por nombre, ambas opciones</td>
      <td><code>interactuar(int indice, Explorador*)</code> e <code>interactuar(string nombre, Explorador*)</code></td>
      <td>Se dejaron ambas formas porque dan más flexibilidad al usuario para elegir un elemento.</td>
      <td>La interacción sería menos clara o dependería de una sola forma de búsqueda.</td>
    </tr>
    <tr>
      <td>Cómo inicializar los objetos</td>
      <td>Crear objetos vacíos, llenar datos después, usar constructores</td>
      <td>Constructores en las clases principales</td>
      <td>Los constructores permiten crear los objetos con sus datos importantes desde el inicio.</td>
      <td>Los objetos podrían quedar incompletos o con valores incorrectos.</td>
    </tr>
    <tr>
      <td>Cómo organizar la clase principal</td>
      <td>Poner todo en <code>main</code>, repartir lógica sin control, usar <code>EcoMision</code></td>
      <td><code>EcoMision</code> controla el flujo del sistema</td>
      <td>La clase <code>EcoMision</code> centraliza el inicio del juego, la creación de zonas, elementos y explorador.</td>
      <td>El programa quedaría desordenado y sería más difícil explicar qué parte controla el sistema.</td>
    </tr>
    <tr>
      <td>Cómo mostrar información del jugador</td>
      <td>Mostrar datos desde varias clases, acceder directo a atributos, usar método</td>
      <td><code>mostrarInfo()</code> en <code>Explorador</code></td>
      <td>El explorador es quien tiene su energía, puntaje y zona actual, por eso tiene sentido que él mismo muestre su información.</td>
      <td>Se rompería el encapsulamiento o habría código repetido.</td>
    </tr>
  </tbody>
</table>


## Matriz de Decisiones

