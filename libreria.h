
#ifndef libreria
#define libreria

//#include <windows.h>
#include <time.h>
//#include<dos.h>

#include<iostream>
#include<fstream>
#include <cstring>
#include "struct.h"
//este es un archivo de cabecera de linux que agrega la llamada sleep.
#include <unistd.h>




 
using namespace std;

namespace libreria {


 



void cargarEmpleado(empleado *emp);
void imprimirEmpleado(empleado emp);
void leerArchivoBinario(empleado *leer);
void escribirArchivoBinario(empleado emp);
void borrarEmpleado(char apellido[]);
int contarRegistros();
int numeracionDeEmpleados();
void imprimirArchivo();
void SetColor(int ForgC);
void funcion_loading();


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
   (*emp).numeroEmp = numeracionDeEmpleados();
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
   std::cout<<emp.numeroEmp<<endl;
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

//funcion de busqueda de empleado, le ingresamos un string y nos retorna el numero de empleado, si no existe nos retorna 

int buscarEmpleado(char apellido[]){
   empleado emp;
   ifstream lecturaArch ("archivo.dat", ios::binary);

   while(lecturaArch.read((char*)&emp,sizeof(empleado))){
     if(strcmp(emp.apellido, apellido)) {
        //uso la propiedad apellido porque no tengo lista la funcion que numere a los empleados. 
        //retorno la posicion del registro o su numero de empleado (cuando termine la funcion de numerar cliente)
         return emp.numeroEmp;
     } else {
        cout<<"el empleado no existe";
     }

   }
   lecturaArch.close();

}

//funcion para numerar los empleados.

int numeracionDeEmpleados(){
   //cuanto los registros y le sumo el actual, liego ingreso ese numero en el registro a escribir;
   int total = contarRegistros();
   return total++;
    
}

//funcion para contar todos los registros que tenga en el archivo.

int contarRegistros(){
   int acumulador = 0;
   empleado leer;
   ifstream lecturaArch ("archivo.dat", ios::binary);
   
   while(lecturaArch.read((char*)&leer, sizeof(empleado))){
      acumulador++;
   }
   lecturaArch.close();
   return acumulador;
}

//funcion para imprimir todo el archivo en un txt.

void imprimirArchivo(){
   ifstream binario;
   binario.open("archivo.dat", ios::binary);
   ofstream texto;
   texto.open("empleados.txt");
    if (!binario || !texto){
        cout << "No se pudo crear el archivo" << endl;
        
    }

    empleado emp;             
    
    while (binario.read((char*)&emp, sizeof(empleado))){
        texto<<"-----------------------"<<endl;
        texto<<"Nombre: "<<emp.nombre<<endl;
        texto<<"Apellido: "<<emp.apellido<<endl;
        texto<<"Calle: "<<emp.dir.calle<<endl;
        texto<<"Numero: "<<emp.dir.numero<<endl;
        texto<<"Ciudad: "<<emp.dir.ciudad<<endl;
        texto<<"Provincia: "<<emp.dir.provincia<<endl;
        texto<<"Pais: "<<emp.dir.pais<<endl;
        texto<<"-----------------------"<<endl;
    }

    
    binario.close();
    texto.close();
}

//esta funcion va a escribir en pantalla loading y unos puntitos animados

void funcion_loading(){

//explicaciones, el loading se carga 3 veces imprimiendo los 5 puntitos

   for (int j = 0; j < 3; j++) {
      cout << "\rLoading     \rLoading";
//este cout es importante, imprime un loading con 5 espacios vacios para borrar los puntos anteriores y despues el loading para los puntitos

      for (int i = 0; i < 5; i++) {
         cout << ".";
         sleep(1);
         fflush(stdout);
      }
      fflush(stdout);
      //hay que tirar un fflush despues de cada ciclo de impresion, la llamada a sistema sleep es un tanto diferente que en windows, aca te toma el numero como segundos, no milisegundos.
   }
   cout<<endl;
    //el salto de linea para que el promt no te quede en el loading
}
}



#endif;