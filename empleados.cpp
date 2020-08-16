


#include "libreria.h"





using namespace std;



int main() {

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
   
   SetColor(14);
   printf("\n \n Sistema de empleados 0.1 \n \n ");
   SetColor(15);
   //bueno, encontre una funcion escrita por un chico en stackoverrun para cambiar el color de la letra, lo que me facilito bastante el trabajo. 
   
    cout << "\rLoading";
        for (int i = 0; i < 10; i++) {
            cout << ".";
            Sleep(300);
        }
    cout<<endl;

    //esto de aca es un separador de "loading..." con los puntitos animados que voy a usar de separador con cada cls que use.

   system("pause");
   
   return 0;
}




