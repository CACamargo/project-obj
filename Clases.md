**Clases**
========	
Tras revisar la lista de requerimientos para el proyecto buscando sustantivos y nombres que puedan transformarse en clases de importancia, obtuve la siguiente lista preliminar:

* Personaje del jugador. 
* Profesión.
* Atributos.
* Habilidades.
* Mapa.
* Estado de salud.
* Inventario.
* Objeto.
* Persona.
* Tesoro.
* Arma.
* Poción.
* Dinero.
* Comandos.
* Enemigo.
* Hechizo.
* Turno.
* Ganador.
* Botín.
* Experiencia.

Como puede apreciarse, se trata de una lista extensa en la que no todos los términos resultan únicos o útiles. Por ejemplo, puede incluirse la profesión, experiencia y salud dentro de los atributos de un personaje del juego. El dinero, por ser un dato sencillo, también puede incluirse en dichos atributos. Tampoco se requiere de clases para designar específicamente el ganador de un conflicto, el turno actual en combate y el botín. Por último, comandos y habilidades básicamente hacen referencia a lo mismo, así que solo se requerirá uno de los dos. 

Eliminando estas propuestas obsoletas, la lista se reduce a lo siguiente:

* Personaje del jugador. 
* Atributos.
* Habilidades.
* Mapa.
* Inventario.
* Objeto.
* Persona.
* Tesoro.
* Arma. 
* Poción.
* Comandos.
* Enemigo.
* Hechizo.

Ahora bien, podemos identificar en esta lista ciertas clases que actúan como superclases para otras. Adémas, se modificará por conveniencia el nombre de ciertas clases, y se agregarán algunas no incluidas inicialmente. Una posible jerarquía inicial sería la siguiente:

* Personaje del jugador
 * Atributos
 * Habilidades
 * Inventario  
 * Salud

* Persona neutral
 * Atributos
 * Habilidades
 * Inventario  
 * Salud

* Enemigo
 * Atributos
 * Habilidades
 * Inventario  
 * Salud

* Objetos
 * Arma
 * Poción
 * Tesoro
 * Hechizo
 
* Mapa
 * Cuarto (múltiples)

Aún hay clases con elementos similares, asi que puede agruparse mejor la lista con una superclase más. Se tiene, entonces, la organización final de más alto nivel para el juego:

* Entes
 * Personaje del jugador 
 * Persona neutral
 * Enemigo

* Objetos
 * Arma
 * Poción
 * Tesoro
 * Hechizo

* Mapa
 * Cuarto (múltiples)