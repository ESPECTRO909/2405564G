#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

typedef struct {
    char id[64];
    char nombre[64];
    char apellido[64];
    char email[128];
    char telefono[15];
} Cliente;

struct node{
    Cliente cliente;
    struct node *next;
};

struct node *crearNodo(char *id ,char *nombre, char *apellido, char *email, char *telefono){
    struct node *nuevoNodo = malloc(sizeof(struct node));
    if(nuevoNodo == NULL){
        printf("Error al asignar memoria\n");
        exit(1);
    }

    strcpy(nuevoNodo->cliente.id, id);
    strcpy(nuevoNodo->cliente.nombre, nombre);
    strcpy(nuevoNodo->cliente.apellido, apellido);
    strcpy(nuevoNodo->cliente.email, email);
    strcpy(nuevoNodo->cliente.telefono, telefono);
    nuevoNodo->next = NULL;
    return nuevoNodo;
    
}



void insertar(struct node **head, struct node *nuevoNodo){
    if(*head == NULL){
        *head = nuevoNodo;
        nuevoNodo->next = *head;
    }

    else{
        struct node *temp = *head;
        while(temp->next != *head){
            temp = temp->next;
        }
        temp->next = nuevoNodo;
        nuevoNodo->next = *head;
    }
}

void mostarLista(struct node *head) 
{   
    if(head == NULL){
        printf("lista vacia\n");
        return;
    }
    
    struct node* temp = head;

    do
    {
	printf("id: %s\n", temp->cliente.id);
        printf("nombre: %s\n", temp->cliente.nombre);
        printf("apellido: %s\n", temp->cliente.apellido);
        printf("email: %s\n", temp->cliente.email);
        printf("telefono: %s\n", temp->cliente.telefono);
        printf("------------------------\n");
        temp = temp->next;
    }while(temp != head);
    
}

void agregarNodoEspecifico(struct node **head, struct node *nuevoNodo, char *id){

if(*head == NULL){
	*head = nuevoNodo;
	nuevoNodo->next = *head;
	printf("la lista estaba vacia, ya tiene un registro\n");
	return ;
}

struct node* temp = nuevoNodo;


do{
	if(temp->cliente.id == id)
	{
		temp = temp->next;

        }	
	else{
		printf("el id no existe\n");
		return;
	}
}while(temp != *head);


}




int main(){
    struct node *head = NULL;
    struct node *nuevoNodo;
    char id[64], nombre[64], apellido[64], email[128], telefono[15];
    int opcion;
    int opcionLista;
    char idInsertar[64];
    do{
        printf("1. Agregar cliente\n");
        printf("2. mostar lista\n");
	printf("3.salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
		printf("ingrese el id:  ");
		scanf("%s", id);
                printf("Ingrese el nombre: ");
                scanf("%s", nombre);
                printf("Ingrese el apellido: ");
                scanf("%s", apellido);
                printf("Ingrese el email: ");
                scanf("%s", email);
                printf("Ingrese el telefono: ");
                scanf("%s", telefono);
                nuevoNodo = crearNodo(id, nombre, apellido, email, telefono);
		printf("desea insertar al final :1     o despues de un cliente especifico: 2 \n"); scanf("%d",&opcionLista);
		if(opcionLista == 1){insertar(&head, nuevoNodo);}

		else if(opcionLista == 2){ 
			printf("ingresa el id: \n");
			scanf("%s",idInsertar);
			agregarNodoEspecifico(&head,nuevoNodo,idInsertar);}	
		else{
			printf("opcion no valida/n");
		}
                break;



            case 2:
                printf("mostar lista\n");
                mostarLista(head);
                break;
            case 3:
                opcion = 3;
                break;
            default:
                printf("Opcion invalida\n");
        }
    }while(opcion != 3);

    return 0;
}
