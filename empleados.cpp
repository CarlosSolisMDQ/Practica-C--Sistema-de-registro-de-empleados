#include<iostream>
#include<fstream>
#include <cstring>
using namespace std;
struct tipo {
   char apellido[30];
   char nombre[30];
  
};
int main() {

    /*bueno, borron y cuenta nueva, voy a tratar de abordar esto usando solo metodos de c++ desde el principio*/
   
   tipo escribir;
   tipo leer;

   //declaro dos struct para diferenciar el de esritura y el de lectura

   std::cout<<"nombre: ";
   //strcpy(escribir.apellido, "pepe");
   std::cin>>escribir.nombre;
   std::cout<<"apellido: ";
   std::cin>>escribir.apellido;

   //relleno el struct de escritura y lo envio al bloque de escritura, hay que usar ios::app para que el archivo se prepare para apilar nuevos registros al final.
   

   ofstream escribirArchivo("archivo.dat", ios::binary | ios::app);
   escribirArchivo.write((char*)&escribir, sizeof(tipo));
   escribirArchivo.close();

  
   //lectura del archivo

   ifstream leerArchivo("archivo.dat", ios::binary );
   
   
   //di muchas vueltas para lograr la lectura secuencial. Al final el algoritmo es este, una lectura previa y que entre a un while que constate que no este en el EOF, la gracia es que la comprobacion va en la segunda lectura.
        
   leerArchivo.read((char*)&leer, sizeof(tipo));
   
   while (!leerArchivo.eof())
   {
        std::cout<<leer.apellido<< endl;
        std::cout<<leer.nombre<< endl;
        leerArchivo.read((char*)&leer, sizeof(tipo));
   }
   leerArchivo.close();
   
   //esto es la estructura mas basica que encontre para escribir y leer struct en binarios. Hay un problema si no usas elementos de un tamanio certero en el struct. Si le pones un "string" en lugar de un char[] no podes leer saltando registros de tamanio fijo. Voy a ver como se resuelve eso otro dia.


   system("pause");
   return 0;
}