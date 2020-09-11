# **Practica-C++-Sistema-de-registro-de-empleados**

Voy a ir progresando esto de a poco mientras estudio c++ y sus funciones de manejo de archivos. La idea es un pequeño sistema que desde un menú permita mantener una diminuta base de datos de empleados y que incluya su nombre, apellido, sueldo, y su locacion... Ciudad, pais, provincia, calle y numeracion. El menu tiene que permitir buscar dar de alta un empleado, borrarlo, buscarlo, enumerarlos todos, editar los datos de un empleado y por ultimo tiene que poder imprimir los datos de un empleado en un txt.

**Basicamente un CRUD en c++ con persistencia en archivos binarios.**

## 15/8/20

Bueno, despues de varias semanas sin tener tiempo para joder con esto **(tambien tengo que trabajar y evadir exitosamente la cuarentena medieval)** empiezo a ordenar un poco el codigo y planear la interfase con el usuario.

Por lo pronto creo la libreria "libreria.h" y apilo las funciones y definiciones ahi. Cuando hice la movida me saltaron errores por todos lados, ya que el nuevo archivo no leia las definiciones de los struct. La solucion que encontre para que por lo menos no aparecieran tantas luces rojas en vscode fue: hacer un #include en libreria.h y endosarle todos los archivos de cabecera ahi. Tambien las definiciones de los struct. Espero que ande porque aun no probe el codigo. Por otro lado, tengo que averiguar como usar colores para el menu asi no queda todo tan choto.

Tengo que mejorar la funcion de busqueda y usarla para las funciones de borrado y listado individual.

## 16/8/20

Logre encontrar una funcion que me permite cambiar el color de la letra en la consola y hice un separador con puntitos animados. Es todo por hoy, me voy a ver Umbrella Academy.
28/8/20, Una actualizacion de **windows me corrompió el disco**. No me quedó otra que **instalar linux** y ahora tengo que ver como adapto este codigo al nuevo entorno.

Te maldigo bill gates!

## 6/9/20

Al fin logro algo de tiempo para el hobby despues de bastante trabajo de taller, jaja. Me introduje en el mundo del crosscompiling intentando compilar para windows en linux y... no salió
O por le menos me pareció insolitamente complicado para solamente hacer andar dos llamadas a sistema que tenía en mi codigo y la funcion que cambiaba el color de las letras. Voy a sacrificar esa funcion, las dos llamadas y santo remedio, ya salió compilando en linux.

Fue una buena tarde de investigacion.

## 10/9/20

Hoy en un rato libre solucioné el tema de la funcion de colores, que resultó que linux ya tiene incorporado en su consola los colores ansi. Solo era cosa de "cargar" en el cout el color adecuado. Tambien resolví como hacer la animacion de "loading" con puntitos sin las llamadas a sistema que hacia en windows. lo que me llevó a agregar un archivo de cabecera linux para poder usar la funcion sleep. Es todo por hoy, tengo que volver a planificar mi trabajo de la vida real para mañana. Cuando tenga mas tiempo libre voy a empezar el menú principal.

*Tambien empecé a aprender Markdown. Para darle un poco de onda a estos readme y parecer menos provinciano.*

## 11/9/20

Finalmente empecé a hacer el menú. Despues de una tarde cortando madera en mi sierra de banco logré ponerme un rato en este vicio. El menú va a ser espartano, por lo menos hasta que aprenda como ponerle mas onda con el diseño.
Lo mas probable es que tenga que retocar las funciones de manejo de empleados, pero voy a pensar en ese puente cuendo llegue a ese rio.
