project-obj
===========
Mi idea para el proyecto de la asignatura es desarrollar un videojuego haciendo uso de las ventajas ofrecidas por el lenguaje C++ y el framework de Qt. De lo que he podido observar, la combinación de estos dos me permitirá crear una aplicación con una complejidad mucho mayor a las que hemos hecho en C hasta este punto, por lo cual he decidido  que es hora de hacer algo de mayor superioridad que un simple juego de tanques o de tetris.

Así pues, el videojuego que quiero desarrollar será del género dungeon crawler en primera persona, inspirado en otros juegos de la misma clase como lo son las sagas de Wizardry, Shin Megami Tensei, Ultima Underworld, Might and Magic, entre otros. Los dungeon crawlers son, inherentemente, juegos de rol en escenarios de fantasía. Por lo tanto, es de esperar que mi proyecto posea los elementos clásicos del género como atributos (fuerza, agilidad, inteligencia, etc.), varios tipos de armas (de filo, impacto y otros) magia, y de manera general, una libertad para explorar y actuar como desee el jugador.  

Ahora bien, la presentación del juego será en primera persona, como he mencionado anteriormente, así como en dos dimensiones, pues me parece un estilo más sencillo y no necesariamente menos agradable que 3D. La idea es, por supuesto, aprovechar las herramientas de Qt para que la aplicación tenga su propia GUI, a diferencia de las que hemos desarrollado en C y que han utilizado la consola como medio de impresión en pantalla. 

Respecto al gameplay como tal, este se desarrollará en un gran nivel de tipo laberinto separado por pisos que, a su vez, estarán compuestos por una cantidad determinada de cuartos. De este modo, el jugador se desplazará de cuarto en cuarto con el fin de adentrarse más en el laberinto y desenmarañar lo que ocurre en este. A medida que visita cada cuarto podrá encontrarse con seres hostiles, personas de utilidad para alcanzar su objetivo, tesoros de alto valor, situaciones problema o incluso con nada. Naturalmente, a medida que progresa la aventura el jugador mejorará sus habilidades y arsenal, pero los retos también serán de dificultad creciente.

Mi propósito es que el juego presente un buen reto al jugador pero sin llegar a un nivel muy injusto, con el fin de que, con planeación y dedicación suficientes,  pueda tener una sensación de logro y éxito al final.

project-obj
===========

Inmediatamente tras la ejecución del programa, el jugador será recibido por una pantalla inicial en la que podrá elegir entre empezar una nueva aventura o salir del juego.

Si elige empezar una nueva aventura, entonces se pondrá a su disposición una serie de opciones para diseñar al personaje que lo representará en el juego. Entre estas opciones estará elegir una profesión, determinar como serán sus atributos y decidir que habilidades tendrá.

Una vez que haya decidido todo la anterior podrá realmente comenzar el juego. Durante la ejecución del programa, el jugador se encontrará en uno de dos modos posibles: exploración y conflicto:

En el modo de exploración el jugador podrá desplazarse a través del mapa. Para ello, podrá elegir tres opciones básicas de movimiento: avanzar en la dirección que esta mirando (si no hay obstáculos), girar a la izquierda y girar a la derecha. Asimismo, mientras este en modo de exploración tendrá la posibilidad de elegir alguno de los siguientes comandos:

  •	Obtener información acerca de su personaje (e.g., atributos, habilidades, estado de salud).
  •	Revisar su inventario (así podrá saber que objetos lleva consigo).
  •	Usar un objeto de su inventario.
  •	Salir del juego.
  
A medida que explora el mapa, el jugador podrá encontrarse con personas y tesoros con los que podrá interactuar debidamente. Si se trata de otro personaje, podrá negociar con este para obtener armas, pociones u otros objetos, a cambio de dinero. Por otro lado, si encuentra un tesoro podrá decidir entre apropiarse de su contenido o seguir adelante.

De igual manera, el jugador también podrá encontrarse con una variedad de criaturas hostiles en medio de su exploración. En ese momento se hará la transición al modo de conflicto, en el cual tanto el jugador como los enemigos actuarán por turnos para decidir quién será el vencedor. En su turno, el jugador deberá escoger uno de los siguientes comandos, distintos a los del modo de exploración:

  •	Atacar a los enemigos directamente.
  •	Lanzar un hechizo.
  •	Adoptar una posición defensiva para reducir el daño recibido.
  •	Usar un objeto de su inventario.
  •	Escapar.

Decidido esto, se reportará debidamente el efecto de la acción del jugador y, si no han sido eliminados, será el turno de los oponentes. Estos, de igual manera, ejecutarán acciones determinadas para intentar acabar con el jugador. Los anteriores pasos continuarán hasta que resulte un ganador.
 
Si el jugador es el vencedor recibirá un botín, que podrá ir desde dinero hasta armamento, y puntos de experiencia, que le servirán para incrementar sus atributos y habilidades, mejorando su capacidad de combate. La magnitud de ambas recompensas será proporcional a la dificultad del encuentro. 
