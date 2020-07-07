#include<iostream>
#include<fstream>
#include <cstring>
using namespace std;

typedef struct {
   char calle[30];
   int numero;
   char ciudad[30];
   char provincia[30];
   char pais[30];
} domicilio;

struct empleado {
   char apellido[30];
   char nombre[30];
   int numeroEmp;
   domicilio dir;
};

void cargarEmpleado(empleado *emp);
void imprimirEmpleado(empleado emp);
void leerArchivoBinario(empleado *leer);
void escribirArchivoBinario(empleado emp);
void borrarEmpleado(char apellido[]);

int main() {

    /*bueno, borron y cuenta nueva, voy a tratar de abordar esto usando solo metodos de c++ desde el principio*/
   
   empleado escribir;
   empleado leer;

   //declaro dos struct auxiliares para diferenciar el de esritura y el de lectura

   //relleno el struct, lo envio al bloque de escritura, hay que usar ios::app para que el archivo se prepare para apilar nuevos registros al final.

   cargarEmpleado(&escribir);
   
   //escritura del archivo binario con el empleado cargado

   escribirArchivoBinario(escribir);

   //Al fin pude hacer andar la funcion de borrado, simplemente no andaba porque me olvide de usar strcmp y estaba comparando string como si fueran enteros erroneamente.

   borrarEmpleado("cool");

   //lectura del archivo

   leerArchivoBinario(&leer);
   
  
   //esto es la estructura mas basica que encontre para escribir y leer struct en binarios. Hay un problema si no usas elementos de un tamanio certero en el struct. Si le pones un "string" en lugar de un char[] no podes leer saltando registros de tamanio fijo. Voy a ver como se resuelve eso otro dia.


   system("pause");
   return 0;
}

//empiezo modularizando la carga, esta tiene que recibir un puntero porque retorna los valores a al struct

void cargarEmpleado(empleado *emp){
   std::cout<<"\nIngrese los datos del empleado: "<<endl;  
   std::cout<<"nombre: ";
   //strcpy(escribir.apellido, "pepe");
   std::cin>>(*emp).nombre;
   std::cout<<"apellido: ";
   std::cin>>(*emp).apellido;
   std::cout<<"calle: ";
   std::cin>>(*emp).dir.calle;
   std::cout<<"numero: ";
   std::cin>>(*emp).dir.numero;
   std::cout<<"ciudad: ";
   std::cin>>(*emp).dir.ciudad;
   std::cout<<"provincia: ";
   std::cin>>(*emp).dir.provincia;
   std::cout<<"pais: ";
   std::cin>>(*emp).dir.pais;
}

//la impresion de el registro la mando a esta funcion. paso el parametro por copia porque solo hace una salida a pantalla.

void imprimirEmpleado(empleado emp){
   std::cout<<"------------------"<< endl;
   std::cout<<emp.apellido<< endl;
   std::cout<<emp.nombre<< endl;
   std::cout<<emp.dir.calle<< endl;
   std::cout<<emp.dir.ciudad<< endl;
   std::cout<<emp.dir.provincia<< endl;
   std::cout<<emp.dir.pais<< endl;
   std::cout<<"------------------"<< endl;
}

//funcion de lectura secuencial del archivo binario, esta funcion lista TODOS los registros.

void leerArchivoBinario(empleado *leer){
   //di muchas vueltas para lograr la lectura secuencial. Al final el algoritmo es este, una lectura previa y que entre a un while que constate que no este en el EOF, la gracia es que la comprobacion va en la segunda lectura.
   ifstream leerArchivo("archivo.dat", ios::binary );     
   leerArchivo.read((char*)leer, sizeof(empleado));
   
   while (!leerArchivo.eof())
   {
        imprimirEmpleado(*leer);
        leerArchivo.read((char*)leer, sizeof(empleado));
   }
   leerArchivo.close();
}

//funcion de escritura del archivo binario, esta funcion escribe solo UN registro.

void escribirArchivoBinario(empleado emp){
   ofstream escribirArchivo("archivo.dat", ios::binary | ios::app);
   escribirArchivo.write((char*)&emp, sizeof(empleado));
   escribirArchivo.close();
}

//funcion de borrado de un registro. 

void borrarEmpleado(char apellido[]){
   empleado emp;
   ofstream escrituraTemp ("temp.dat", ios::binary);
   ifstream lecturaArch ("archivo.dat", ios::binary);

   //preparo la lectura del binario y inicio un archivo temporal para hacer la recopilacion de los registros que no quiero descartar. Tendria que buscar si esto mismo se puede hacer sin salir de memoria, usando un buffer y no un archivo. Tambien tengo que ampliar el struct empleado para que registre su numero de empleado. y que una busqueda por nombre o lo que quiera retorne el numero de empleado.

   //meter como condicion la instruccion de lectura no se me habia ocurrido, gracias internet.

   while(lecturaArch.read((char*)&emp,sizeof(empleado))){
     if(strcmp(emp.apellido, apellido)) {
        //uso la propiedad aplellido porque no tengo lista la funcion que numere a los empleados. 
        escrituraTemp.write((char*)&emp,sizeof(empleado));
     }

   }
   lecturaArch.close();
   escrituraTemp.close();

   remove("archivo.dat");
   rename("temp.dat","archivo.dat");
}

