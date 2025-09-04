#include<stdio.h>
#include<math.h>    

typedef struct {
    char nombre[30];
    int edad;
    float calificacion;
} alumno;

int main()
{
    alumno alumno1, alumno2, alumno3;

    printf("Ingrese el nombre del alumno 1: ");
    scanf("%s", alumno1.nombre);
    printf("Ingrese la edad del alumno 1: ");
    scanf("%d", &alumno1.edad);
    printf("Ingrese la calificacion del alumno 1: ");
    scanf("%f", &alumno1.calificacion);

    printf("Ingrese el nombre del alumno 2: ");
    scanf("%s", alumno2.nombre);
    printf("Ingrese la edad del alumno 2: ");
    scanf("%d", &alumno2.edad);
    printf("Ingrese la calificacion del alumno 2: ");
    scanf("%f", &alumno2.calificacion);

    printf("Ingrese el nombre del alumno 3: ");
    scanf("%s", alumno3.nombre);
    printf("Ingrese la edad del alumno 3: ");
    scanf("%d", &alumno3.edad);
    printf("Ingrese la calificacion del alumno 3: ");
    scanf("%f", &alumno3.calificacion);

    if(alumno1.calificacion >= alumno2.calificacion && alumno1.calificacion >= alumno3.calificacion) {
        printf("El alumno con la calificacion mas alta es: %s con una calificacion de %.2f\n", alumno1.nombre, alumno1.calificacion);
    } else if(alumno2.calificacion >= alumno1.calificacion && alumno2.calificacion >= alumno3.calificacion) {
        printf("El alumno con la calificacion mas alta es: %s con una calificacion de %.2f\n", alumno2.nombre, alumno2.calificacion);
    } else {
        printf("El alumno con la calificacion mas alta es: %s con una calificacion de %.2f\n", alumno3.nombre, alumno3.calificacion);
    }
    return 0;
}