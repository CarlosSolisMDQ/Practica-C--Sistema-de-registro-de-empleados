#include <iostream>
#include <string.h>


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

int main()
{
    empleado emp[2];
    
    carga(2, emp);
    lecturaTotal(2, emp);
    

    system("pause");
    return 0;
}

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
        
    }
}

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