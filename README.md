# Proyecto-EcoMision
Proyecto realizado para el trabajo final de la materia de POO en Universidad Javeriana Cali

## Integrantes

| Nombre | Código |
|---|---|
|Juan Pantoja| 9040928 |
| Mariana Guzman | [9039850 |


---

## Descripción

EcoMisión es un prototipo de experiencia interactiva sobre cuidado ambiental desarrollado
en consola. Una persona exploradora recorre una reserva natural compuesta por varias zonas,
cada una con elementos del entorno con los que puede interactuar. Algunos elementos ayudan
al explorador, otros consumen su energía y otros representan problemas ambientales que deben
resolverse. El sistema permite crear múltiples reservas y exploradores, navegar entre zonas,
interactuar con elementos y llevar un registro de los cambios en el estado ambiental.

---

## Cómo compilar y ejecutar

El proyecto fue desarrollado en **CodeBlocks**. Para ejecutarlo:

1. Abrir CodeBlocks.
2. Cargar el archivo `EcoMision.cbp`.
3. Asegurarse de que todos los archivos `.cpp` y `.h` estén incluidos en el proyecto.
4. Presionar **Build and Run** (F9) o ir a `Build > Build and Run`.

Los archivos fuente deben estar en la carpeta `/src` y los headers en `/include`.

---

## Archivos principales del proyecto

| Archivo | Descripción |
|---|---|
| `main.cpp` | Punto de entrada del programa |
| `EcoMision.h / .cpp` | Controlador principal, maneja los menús y coordina el sistema |
| `Reserva.h / .cpp` | Representa el conjunto de zonas, usa `unordered_map` y `vector` |
| `Zona.h / .cpp` | Representa un lugar de la reserva con elementos interactivos |
| `Explorador.h / .cpp` | Representa al jugador con energía, puntaje y semillas |
| `ElementoInteractivo.h / .cpp` | Clase abstracta base para todos los elementos |
| `AnimalHerido.h / .cpp` | Elemento que aumenta puntaje al ser ayudado |
| `AguaContaminada.h / .cpp` | Elemento que reduce energía al tocarse |
| `ResiduoContaminante.h / .cpp` | Elemento que se limpia a costa de energía |
| `EstacionEnergia.h / .cpp` | Elemento que recupera energía del explorador |
| `SemillaNativa.h / .cpp` | Elemento que se recolecta y se puede plantar |

---

## Imágenes del proyecto funcionando

### Menú principal

<!-- Insertar imagen del menú principal -->

### Creación de reserva y zonas

<!-- Insertar imagen creando una reserva con varias zonas -->

### Menú del explorador

<!-- Insertar imagen del menú del explorador dentro de una zona -->

### Interacción con elementos

<!-- Insertar imagen de una interacción y sus efectos en energía y puntaje -->

### Historial de una zona

<!-- Insertar imagen del historial de interacciones de una zona -->

### Búsqueda de zona por código

<!-- Insertar imagen de la búsqueda de una zona por código -->
