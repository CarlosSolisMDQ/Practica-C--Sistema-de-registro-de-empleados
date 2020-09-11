


#include "libreria.h"





using namespace std;



int main() {

    //bien, para evitar usar una funcion para cambiar de color voy a usar las ventajas de la terminal de linux que tiene ya incorporado un modo de color ansi. Lo primero que hago es cargar unas constantes con los valores de color que voy a usar y un reset para volver al cout a su color natural. lugo se puede cambiar el color solo enviando la constante a el cout: cout<<colordepreferencia

    const std::string red("\033[0;31m");
    const std::string green("\033[1;32m");
    const std::string yellow("\033[1;33m");
    const std::string cyan("\033[0;36m");
    const std::string magenta("\033[0;35m");
    const std::string reset("\033[0m");

    /*bueno, borron y cuenta nueva, voy a tratar de abordar esto usando solo metodos de c++ desde el principio*/
   
   empleado escribir;
   empleado leer;

   //declaro dos struct auxiliares para diferenciar el de esritura y el de lectura

   //relleno el struct, lo envio al bloque de escritura, hay que usar ios::app para que el archivo se prepare para apilar nuevos registros al final.

   //cargarEmpleado(&escribir);
   
   //escritura del archivo binario con el empleado cargado

   //escribirArchivoBinario(escribir);

   //Al fin pude hacer andar la funcion de borrado, simplemente no andaba porque me olvide de usar strcmp y estaba comparando string como si fueran enteros erroneamente.

   //borrarEmpleado("cool");

   //lectura del archivo

   //int cuenta = contarRegistros();
   //cout<<cuenta<<endl;

   //leerArchivoBinario(&leer);

   //imprimirArchivo();
   
  
   //esto es la estructura mas basica que encontre para escribir y leer struct en binarios. Hay un problema si no usas elementos de un tamanio certero en el struct. Si le pones un "string" en lugar de un char[] no podes leer saltando registros de tamanio fijo. Voy a ver como se resuelve eso otro dia.
    
    //la instruccion para limpiar la pantalla.
    std::system("clear");
   
    cout<< red << "\n\nSistema de empleados 0.1\n\n ";
     
   
    //esto de aca es un separador de "loading..." con los puntitos animados que voy a usar de separador con cada cls que use.

    //cout << yellow << "prueba color\n" << endl;

    cout << reset;

    funcion_loading();

    cout << endl;

    std::system("clear");

// esta instruccion cin.get es la version portable c++ de que lo antes en windows hacia con system(pause) o getch, para dejar al programa en ejecucion y poder leer lo escrito mientras programo.
//Leí que es una mala practica de programacion en stackoverflow.
    //cin.get();

   
   
   return 0;
}




