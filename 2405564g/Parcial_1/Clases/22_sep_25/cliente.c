#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

typedef struct {
    char nombre[64];
    char apellido[64];
    char email[128];
    char telefono[15];
} Cliente;

typedef struct node{
    Cliente cliente;
    struct node *next;
};

void crearNodo(char *nombre, char *apellido, char *email, char *telefono){
    struct node *nuevoNodo = (struct node*) malloc(sizeof(struct(node)));
    if(nuevoNodo == NULL){
        printf("Error al asignar memoria\n");
        exit(1);
    }

    strcpy(nuevoNodo->cliente.nombre, nombre);
    strcpy(nuevoNodo->cliente.apellido, apellido);
    strcpy(nuevoNodo->cliente.email, email);
    strcpy(nuevoNodo->cliente.telefono, telefono);
    nuevoNodo->next = NULL;
    return nuevoNodo;
    
};



void insertar(struct node **head, struct node *nuevoNodo){
    if(*head == NULL){
        *head = nuevoNodo;
    }

    else{
        struct node *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = nuevoNodo;
    }
};



int main(){
    struct node *head = NULL;
    struct node *nuevoNodo;
    char nombre[64], apellido[64], email[128], telefono[15];
    int opcion;
    do{
        printf("1. Agregar cliente\n");
        printf("2. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                printf("Ingrese el nombre: ");
                scanf("%s", nombre);
                printf("Ingrese el apellido: ");
                scanf("%s", apellido);
                printf("Ingrese el email: ");
                scanf("%s", email);
                printf("Ingrese el telefono: ");
                scanf("%s", telefono);
                nuevoNodo = crearNodo(nombre, apellido, email, telefono);
                insertar(&head, nuevoNodo);
                break;
            case 2:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida\n");
        }
    }while(opcion != 2);

    return 0;
}