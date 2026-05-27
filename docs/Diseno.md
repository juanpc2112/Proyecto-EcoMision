# Diseño del sistema — EcoMisión

---

## Versión inicial (antes de programar)

Diagrama pensado antes de escribir código. Se identificaron las clases principales,
la jerarquía de herencia de `ElementoInteractivo` y las relaciones básicas entre
`EcoMision`, `Reserva`, `Zona` y `Explorador`. En este punto `EcoMision` manejaba
un único explorador y una única reserva.

```mermaid
classDiagram
class EcoMision{
    - Reserva* reserva
    - Explorador* explorador
    + crearExplorador(string nombre)
    + iniciarDatos()
    + mostrarEstado()
}
class Reserva{
    - unordered_map~string, Zona*~ zonas
    + agregarZona(string codigo, Zona* zona)
    + buscarZona(string codigo) Zona*
    + mostrarZonas()
}
class Zona{
    - string nombre
    - string codigo
    - string tipoZona
    - bool contaminada
    - vector~ElementoInteractivo*~ elementos
    + agregarElemento(ElementoInteractivo* elemento)
    + mostrarElementos()
    + interactuarElemento(int indice, Explorador* explorador)
    + interactuarElemento(string nombreElemento, Explorador* explorador)
    + getTipoZona() string
    + estaContaminada() bool
    + setContaminada(bool estado)
}
class Explorador{
    - string nombre
    - int energia
    - int puntajeAmbiental
    - Zona* zonaActual
    - vector~string~ semillasRecolectadas
    + perderEnergia(int cantidad)
    + recuperarEnergia(int cantidad)
    + aumentarPuntaje(int puntos)
    + cambiarZona(Zona* nuevaZona)
    + recolectarSemilla(string tipoSemilla)
    + plantarSemilla(string tipoSemilla)
    + mostrarSemillas()
}
class ElementoInteractivo{
    <<abstract>>
    - string nombre
    - string categoria
    + interactuar(Explorador* explorador)* void
    + getNombre() string
    + getCategoria() string
}
class AnimalHerido{
    + interactuar(Explorador* explorador)
}
class AguaContaminada{
    + interactuar(Explorador* explorador)
}
class EstacionEnergia{
    + interactuar(Explorador* explorador)
}
class ResiduoContaminante{
    + interactuar(Explorador* explorador)
}
class SemillaNativa{
    - string tipoSemilla
    + interactuar(Explorador* explorador)
}

EcoMision --> Reserva
EcoMision --> Explorador
Reserva o-- Zona
Zona o-- ElementoInteractivo
Explorador --> Zona
ElementoInteractivo <|-- AnimalHerido
ElementoInteractivo <|-- AguaContaminada
ElementoInteractivo <|-- EstacionEnergia
ElementoInteractivo <|-- ResiduoContaminante
ElementoInteractivo <|-- SemillaNativa
```

---

## Versión ajustada (después de comenzar a programar)

Durante el desarrollo se tomaron las primeras decisiones importantes:
se pasó de un único explorador y reserva a colecciones (`vector`), se agregó
`nombre` a `Reserva` para identificarla, se introdujo `mostrarEstado()` en
`Explorador`, y se añadió un menú de explorador con navegación entre zonas.
La contaminación de `Zona` pasó a calcularse automáticamente al agregar
o eliminar elementos, y los elementos desaparecen tras interactuar con ellos.

```mermaid
classDiagram
class EcoMision{
    - vector~Reserva*~ reservas
    - vector~Explorador*~ exploradores
    + iniciar()
    + crearReserva()
    + crearExplorador()
    + registrarZona()
    + agregarElemento()
    + listarReservas()
    + listarExploradores()
    + controlarExplorador()
    - menuExplorador(Explorador* explorador)
    - moverExplorador(Explorador* explorador)
    - interactuarEnZona(Explorador* explorador)
    - plantarEnZona(Explorador* explorador)
    - seleccionarReserva() Reserva*
    - buscarExplorador(string nombre) Explorador*
}
class Reserva{
    - string nombre
    - unordered_map~string, Zona*~ zonas
    + Reserva(string nombre)
    + agregarZona(string codigo, Zona* zona)
    + buscarZona(string codigo) Zona*
    + mostrarZonas()
    + getNombre() string
}
class Zona{
    - string nombre
    - string codigo
    - string tipoZona
    - bool contaminada
    - vector~ElementoInteractivo*~ elementos
    + agregarElemento(ElementoInteractivo* elemento)
    + mostrarElementos()
    + interactuarElemento(int indice, Explorador* explorador)
    + interactuarElemento(string nombreElemento, Explorador* explorador)
    + getNombre() string
    + getCodigo() string
    + getTipoZona() string
    + estaContaminada() bool
    + setContaminada(bool estado)
    - recalcularContaminacion()
}
class Explorador{
    - string nombre
    - int energia
    - int puntajeAmbiental
    - Zona* zonaActual
    - vector~string~ semillasRecolectadas
    + perderEnergia(int cantidad)
    + recuperarEnergia(int cantidad)
    + aumentarPuntaje(int puntos)
    + cambiarZona(Zona* nuevaZona)
    + recolectarSemilla(string tipoSemilla)
    + plantarSemilla(string tipoSemilla)
    + mostrarSemillas()
    + mostrarEstado()
    + getNombre() string
    + getEnergia() int
    + getPuntajeAmbiental() int
    + getZonaActual() Zona*
}
class ElementoInteractivo{
    <<abstract>>
    - string nombre
    - string categoria
    + interactuar(Explorador* explorador)* void
    + getNombre() string
    + getCategoria() string
}
class AnimalHerido{
    + interactuar(Explorador* explorador)
}
class AguaContaminada{
    + interactuar(Explorador* explorador)
}
class EstacionEnergia{
    + interactuar(Explorador* explorador)
}
class ResiduoContaminante{
    + interactuar(Explorador* explorador)
}
class SemillaNativa{
    - string tipoSemilla
    + interactuar(Explorador* explorador)
}

EcoMision "1" --> "*" Reserva : gestiona
EcoMision "1" --> "*" Explorador : gestiona
Reserva "1" o-- "*" Zona : contiene
Zona "1" o-- "*" ElementoInteractivo : contiene
Explorador --> Zona : conoce
ElementoInteractivo <|-- AnimalHerido
ElementoInteractivo <|-- AguaContaminada
ElementoInteractivo <|-- EstacionEnergia
ElementoInteractivo <|-- ResiduoContaminante
ElementoInteractivo <|-- SemillaNativa
```

---

## Versión final (después de terminar)

Versión completa del sistema. Se incorporaron: historial de interacciones en `Zona`,
tercera sobrecarga de `interactuarElemento` por categoría y posición,
`mostrarHistorial()` y `mostrarInfoNatural()` para el requerimiento de
*mostrar cambios en el estado del explorador o de la reserva*, validación
bidireccional de compatibilidad entre tipo de zona y categoría de elemento,
y corrección del conteo de semillas por nombre exacto del elemento.

```mermaid
classDiagram
class EcoMision{
    - vector~Reserva*~ reservas
    - vector~Explorador*~ exploradores
    + iniciar()
    + crearReserva()
    + crearExplorador()
    + registrarZona()
    + agregarElemento()
    + listarReservas()
    + listarExploradores()
    + controlarExplorador()
    + verHistorialZona()
    + buscarZonaMenu()
    + ~EcoMision()
    - menuExplorador(Explorador* explorador)
    - moverExplorador(Explorador* explorador)
    - interactuarEnZona(Explorador* explorador)
    - plantarEnZona(Explorador* explorador)
    - seleccionarReserva() Reserva*
    - buscarExplorador(string nombre) Explorador*
}
class Reserva{
    - string nombre
    - unordered_map~string, Zona*~ zonas
    - vector~Zona*~ listaZonas
    + Reserva(string nombre)
    + agregarZona(string codigo, Zona* zona)
    + buscarZona(string codigo) Zona*
    + mostrarZonas()
    + getNombre() string
    + ~Reserva()
}
class Zona{
    - string nombre
    - string codigo
    - string tipoZona
    - bool contaminada
    - vector~ElementoInteractivo*~ elementos
    - vector~string~ historial
    + agregarElemento(ElementoInteractivo* elemento)
    + mostrarElementos()
    + mostrarHistorial()
    + mostrarInfoNatural()
    + interactuarElemento(int indice, Explorador* explorador)
    + interactuarElemento(string nombreElemento, Explorador* explorador)
    + interactuarElemento(string categoria, int cual, Explorador* explorador)
    + getNombre() string
    + getCodigo() string
    + getTipoZona() string
    + estaContaminada() bool
    + setContaminada(bool estado)
    + ~Zona()
    - recalcularContaminacion()
    - contarSemillas() int
    - registrarInteraccion(string nombre, string categoria)
}
class Explorador{
    - string nombre
    - int energia
    - int puntajeAmbiental
    - Zona* zonaActual
    - vector~string~ semillasRecolectadas
    + perderEnergia(int cantidad)
    + recuperarEnergia(int cantidad)
    + aumentarPuntaje(int puntos)
    + cambiarZona(Zona* nuevaZona)
    + recolectarSemilla(string tipoSemilla)
    + plantarSemilla(string tipoSemilla)
    + mostrarSemillas()
    + mostrarEstado()
    + getNombre() string
    + getEnergia() int
    + getPuntajeAmbiental() int
    + getZonaActual() Zona*
}
class ElementoInteractivo{
    <<abstract>>
    - string nombre
    - string categoria
    + interactuar(Explorador* explorador)* void
    + getNombre() string
    + getCategoria() string
    + ~ElementoInteractivo()
}
class AnimalHerido{
    + interactuar(Explorador* explorador)
}
class AguaContaminada{
    + interactuar(Explorador* explorador)
}
class EstacionEnergia{
    + interactuar(Explorador* explorador)
}
class ResiduoContaminante{
    + interactuar(Explorador* explorador)
}
class SemillaNativa{
    - string tipoSemilla
    + interactuar(Explorador* explorador)
}

EcoMision "1" --> "*" Reserva : gestiona
EcoMision "1" --> "*" Explorador : gestiona
Reserva "1" o-- "*" Zona : agrega
Zona "1" o-- "*" ElementoInteractivo : agrega
Explorador --> Zona : conoce
ElementoInteractivo <|-- AnimalHerido
ElementoInteractivo <|-- AguaContaminada
ElementoInteractivo <|-- EstacionEnergia
ElementoInteractivo <|-- ResiduoContaminante
ElementoInteractivo <|-- SemillaNativa
```
