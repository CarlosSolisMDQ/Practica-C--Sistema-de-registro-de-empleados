# Practica-C++-Sistema-de-registro-de-empleados
 
Voy a ir progresando esto de a poco mientras estudio c++ y sus funciones de manejo de archivos. La idea es un pequeño sistema que desde un menú permita mantener una diminuta base de datos de empleados y que incluya su nombre, apellido, sueldo, y su locacion... Ciudad, pais, provincia, calle y numeracion. El menu tiene que permitir buscar dar de alta un empleado, borrarlo, buscarlo, enumerarlos todos, editar los datos de un empleado y por ultimo tiene que poder imprimir los datos de un empleado en un txt.

Basicamente un CRUD en c++ con persistencia en archivos binarios.


15/8/20

Bueno, despues de varias semanas sin tener tiempo para joder con esto (tambien tengo que trabajar y evadir exitosamente la cuarentena medieval) empiezo a ordenar un poco el codigo y planear la interfase con el usuario.

Por lo pronto creo la libreria "libreria.h" y apilo las funciones y definiciones ahi. Cuando hice la movida me saltaron errores por todos lados, ya que el nuevo archivo no leia las definiciones de los struct. La solucion que encontre para que por lo menos no aparecieran tantas luces rojas en vscode fue: hacer un #include en libreria.h y endosarle todos los archivos de cabecera ahi. Tambien las definiciones de los struct. Espero que ande porque aun no probe el codigo. Por otro lado, tengo que averiguar como usar colores para el menu asi no queda todo tan choto.

Tengo que mejorar la funcion de busqueda y usarla para las funciones de borrado y listado individual.

16/8/20

Logre encontrar una funcion que me permite cambiar el color de la letra en la consola y hice un separador con puntitos animados. Es todo por hoy, me voy a ver Umbrella Academy.


28/8/20, Una actualizacion de windows me corrompió el disco. No me quedó otra que instalar linux y ahora tengo que ver como adapto este codigo al nuevo entorno.

Te maldigo bill gates!


6/9/2020

Al fin logro algo de tiempo para el hobby despues de bastante trabajo de taller, jaja. Me introduje en el mundo del crosscompiling intentando compilar para windows en linux y... no salió
O por le menos me pareció insolitamente complicado para solamente hacer andar dos llamadas a sistema que tenía en mi codigo y la funcion que cambiaba el color de las letras. Voy a sacrificar esa funcion, las dos llamadas y santo remedio, ya salió compilando en linux.

Fue una buena tarde de investigacion.