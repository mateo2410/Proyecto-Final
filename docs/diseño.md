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

---

## Matriz de Decisiones

> Pendiente por completar.

---

