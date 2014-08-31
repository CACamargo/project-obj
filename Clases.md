**Clases**
========	
Tras revisar la lista de requerimientos para el proyecto buscando sustantivos y nombres que puedan transformarse en clases de importancia, obtuve la siguiente lista preliminar:

* Personaje del jugador. 
* Pantalla inicial.
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
* Exploración.
* Combate.

Como puede apreciarse, se trata de una lista extensa en la que no todos los términos resultan únicos o útiles. Por ejemplo, puede incluirse la profesión, experiencia y salud dentro de los atributos de un personaje del juego. El dinero, por ser un dato sencillo, también puede incluirse en dichos atributos. Tampoco se requiere de clases para designar de modo individual al ganador de un conflicto, el turno actual en combate y el botín. Por último, comandos y habilidades básicamente hacen referencia a lo mismo, así que solo se requerirá uno de los dos, y por último, un hechizo puede considerarse como una habilidad. 

Eliminando estas propuestas obsoletas, la lista se reduce a lo siguiente:

* Personaje del jugador. 
* Pantalla inicial.
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
* Exploración.
* Combate.

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
 * Armadura
 * Poción
 * Tesoro
 
* Mapa
 * Cuarto (múltiples)

* Pantalla inicial.
* Pantalla de Exploración.
* Pantalla de Combate.
* Estado del personaje.
* Estado del inventario.

Aún hay clases con elementos similares, asi que puede agruparse mejor la lista con una superclase para los entes del juego. De igual manera, sería útil disponer de una superclase adicional para controlar lo que será la interfaz gráfica del juego. Se tiene, entonces, la organización final de más alto nivel para el juego:

* Entes
 * Personaje del jugador 
 * Persona neutral
 * Enemigo

* Objetos
 * Arma
 * Armadura
 * Poción
 * Tesoro

* Mapa
 * Cuarto (múltiples)

* Interfaz
 * Pantalla inicial.
 * Pantalla de exploración.
 * Pantalla de combate.
 * Estado del personaje.
 * Estado del inventario.