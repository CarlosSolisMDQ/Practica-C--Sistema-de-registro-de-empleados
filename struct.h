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
