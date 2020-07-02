#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
using namespace std;


typedef struct {
    char calle[30];
    int numero;
    char provincia[30];
    char pais[30];
} direccion;

typedef struct {
    char nombre[30];
    float sueldo;
    direccion dir; 
} empleado;

void carga(int num, empleado emp[]);
void lecturaTotal(int num, empleado emp[]);
void escribirArchivo(empleado emp[]);
int leerArchivo(char *nombre, int num);

int main()
{
    empleado emp[2];
    
    carga(1, emp);
    //lecturaTotal(2, emp);
    leerArchivo("empleados.dat", 5);
    

    system("pause");
    return 0;
}

//funcion de carga de empleados
//tengo que hacer que tenga un loop y que la carga de empleados sea manejada por el usuario.

void carga(int num, empleado emp[]){
    for (int i = 0; i < num; i++)
    {
        std::cout<<"\ningrese el nombre del empleado numero "<<i+1<<": ";
        std::cin>>emp[i].nombre;
        std::cout<<"\ningrese el sueldo del empleado numero "<<i+1<<": ";
        std::cin>>emp[i].sueldo;
            std::cout<<"\ningrese el domicilio del empleado";
            std::cout<<"\ningrese la calle: ";
            std::cin>>emp[i].dir.calle;
            std::cout<<"\ningrese la numeracion: ";
            std::cin>>emp[i].dir.numero;
            std::cout<<"\ningrese la provincia: ";
            std::cin>>emp[i].dir.provincia;
            std::cout<<"\ningrese el pais: ";
            std::cin>>emp[i].dir.pais;
    escribirArchivo(emp);    
    }
}

//funcion de listado total de empleados en memoria

void lecturaTotal(int num, empleado emp[]){
    for (int i = 0; i < num; i++)
    {
        std::cout<<"\nel nombre del empleado numero "<<i+1<<": ";
        std::cout<<emp[i].nombre;
        std::cout<<"\nel sueldo del empleado numero "<<i+1<<": ";
        std::cout<<emp[i].sueldo;
        std::cout<<"\nel domicilio del empleado es: ";
            std::cout<<"\ncalle: ";
            std::cout<<emp[i].dir.calle;
            std::cout<<"\nnumeracion: ";
            std::cout<<emp[i].dir.numero;
            std::cout<<"\nprovincia: ";
            std::cout<<emp[i].dir.provincia;
            std::cout<<"\npais: ";
            std::cout<<emp[i].dir.pais<<"\n";
        
    
    }
}

//esto es como apilar registros en un archivo en c, tengo aun que averiguar la manera de hacerlo con un stream en c++ (igual hace solo un dia que estoy estudiando c++)

void escribirArchivo(empleado emp[]){
    FILE *fichero;
    fichero = fopen("empleados.dat", "ab");
    if(!fichero) {
      cout << "Error al escribir el archivo!" << endl;
      
    }
    fwrite(emp, sizeof(empleado), 1, fichero);
    fclose(fichero);
}

//tengo que hacer que esto funcione buscando el EOF. otro dia buscare como.

int leerArchivo(char *nombre, int num){
   ifstream fichero(nombre, ios::out | ios::binary);
   if(!fichero) {
      cout << "\nNo existe el archivo" << endl;
      return 1;
   }
   empleado emp[20];
   for(int i = 0; i < num; i++)
   {
      fichero.read((char *) &emp[i], sizeof(empleado));
   }
   fichero.close();
   
    
    //despues la modularizare mas...

    std::cout<<"\naca empieza la lectura de archivo\n";

    for (int i = 0; i < num; i++)
    {
        std::cout<<"\nel nombre del empleado ";
        std::cout<<emp[i].nombre;
        std::cout<<"\nel sueldo del empleado ";
        std::cout<<emp[i].sueldo;
        std::cout<<"\nel domicilio del empleado es: ";
            std::cout<<"\ncalle: ";
            std::cout<<emp[i].dir.calle;
            std::cout<<"\nnumeracion: ";
            std::cout<<emp[i].dir.numero;
            std::cout<<"\nprovincia: ";
            std::cout<<emp[i].dir.provincia;
            std::cout<<"\npais: ";
            std::cout<<emp[i].dir.pais<<"\n";
        
    
    }

    return 1;
}