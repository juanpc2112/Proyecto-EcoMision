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

![Menu principal](https://github.com/juanpc2112/Proyecto-EcoMision/blob/master/docs/images/Menuprincipal.png)

### Creación de reserva y zonas

![creacionReserval](https://github.com/juanpc2112/Proyecto-EcoMision/blob/master/docs/images/CreacionReserva.png)

![creacionzona](https://github.com/juanpc2112/Proyecto-EcoMision/blob/master/docs/images/Creacionzona.png)

### Menú del explorador

![Menu Explorador](https://github.com/juanpc2112/Proyecto-EcoMision/blob/master/docs/images/MenuExplorador.png)

### Interacción con elementos

![InteraccionElemento](https://github.com/juanpc2112/Proyecto-EcoMision/blob/master/docs/images/InteraccionElemento.png)

### Historial de una zona

![HistorialZona](https://github.com/juanpc2112/Proyecto-EcoMision/blob/master/docs/images/HistorialZona.png)

### Búsqueda de zona por código

![Busquedazonacodigo](https://github.com/juanpc2112/Proyecto-EcoMision/blob/master/docs/images/BuscarZonaCodigo.png)
