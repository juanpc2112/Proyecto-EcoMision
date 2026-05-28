# Bitácora de uso de IA — EcoMisión

## ¿Para qué usamos IA generativa?

Usamos IA principalmente como apoyo para revisar decisiones de diseño,
detectar errores en el código y mejorar la estructura del sistema a medida
que avanzábamos. No se usó para generar el proyecto desde cero, sino para
discutir opciones y entender las consecuencias de cada decisión.

## ¿Qué decisiones de diseño revisamos con IA?

- Cómo pasar de un único explorador y reserva a manejar múltiples de cada uno.
- Si la sobrecarga de `interactuarElemento` en `Zona` era válida o solo cosmética,
  y cómo agregar una tercera sobrecarga con criterio real.
- Quién debía ser responsable de actualizar el estado de contaminación de una zona:
  cada elemento o la zona misma.
- Si tenía sentido usar tanto un `unordered_map` como un `vector` en `Reserva`,
  y cuál era el rol de cada uno.
- Si los destructores eran necesarios y cuál era el orden correcto de liberación
  de memoria en cada clase.

---

## ¿Qué sugerencia de IA aceptamos y por qué?

**Responsabilidad de la contaminación en `Zona`:** la IA sugirió que en lugar
de que cada `ElementoInteractivo` llamara `setContaminada()` directamente,
`Zona` recalculara su propio estado con `recalcularContaminacion()` cada vez
que se agregara o eliminara un elemento. Lo aceptamos porque hace el diseño
más robusto — si alguien agrega una subclase nueva, no tiene que recordar
llamar ese método manualmente.

**Destructor en cadena:** la IA propuso que el `vector<Zona*>` en `Reserva`
fuera el "dueño" de los objetos y el `unordered_map` solo limpiara sus
propias estructuras. Lo aceptamos porque evita hacer `delete` dos veces
sobre el mismo puntero, lo cual causaría un error en tiempo de ejecución.

**Corrección del contador de semillas:** la IA detectó que `contarSemillas()`
contaba por categoría `"Natural"`, lo que hacía que `AnimalHerido` también
se contara como semilla. Aceptamos cambiar la comparación por nombre exacto
`"SemillaNativa"` porque era la causa directa de un bug visible en consola.

---

## ¿Qué sugerencia de IA corregimos o rechazamos y por qué?

**Validación de compatibilidad entre zona y elemento:** inicialmente la ia nos propuso
que para que no dejaran elementos `"Natural"` en las zonas de tipo `"Tecnologica"`,
pero al ver esta sugerencia nos percatamos de que faltaba una validacion en reversa y la
agregamos para que tambien los elementos `"Tecnologicos"` no pudieran estar en zonas 
de tipo `"Natural"`.

**Descripción del método `contarSemillas` en el UML inicial:** Le pedimos a la IA que revisara
el UML propuesto por nosotros y propuso el `contarSemillas` como un metodo publico, pero esto
no tiene sentido ya que es algo que solo necesita saber la zona y no se necesita en ninguna otra
clase, por eso lo cambiamos a privado.

---

## ¿Qué parte del proyecto debe poder defender cada integrante?

Juan Pantoja:Conoce bien el diseño del sistema, las relaciones entre clases y las decisiones de diseño.
Puede explicar el funcionamiento del código y modificarlo con un poco de dificultad.

Mariana Guzmán:Comprende el diseño del sistema, las relaciones entre clases y las decisiones de diseño. 
En cuanto al código, maneja los conceptos generales de cada clase y puede explicar su funcionamiento.

