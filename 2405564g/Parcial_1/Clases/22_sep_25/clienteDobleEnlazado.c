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

struct node{
    Cliente cliente;
    struct node *next;
    struct node *prev;

};

struct node *crearNodo(char *nombre, char *apellido, char *email, char *telefono){
    struct node *nuevoNodo = malloc(sizeof(struct node));
    if(nuevoNodo == NULL){
        printf("Error al asignar memoria\n");
        exit(1);
    }

    strcpy(nuevoNodo->cliente.nombre, nombre);
    strcpy(nuevoNodo->cliente.apellido, apellido);
    strcpy(nuevoNodo->cliente.email, email);
    strcpy(nuevoNodo->cliente.telefono, telefono);
    nuevoNodo->next = NULL;
    nuevoNodo->prev = NULL;
    return nuevoNodo;
    
}



void insertarFinal(struct node **head, struct node *nuevoNodo){
    if(*head == NULL){
        *head = nuevoNodo;
    }

    else{
        struct node *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = nuevoNodo;
        nuevoNodo->prev = temp; 
        nuevoNodo->next = NULL;
    }
}

void insertarInicio(struct node **head, struct node *nuevoNodo){
    if(*head == NULL){
        *head = nuevoNodo;
    }
    else{
        nuevoNodo->next = *head;
        (*head)->prev = nuevoNodo;
        *head = nuevoNodo;
    }

}

void mostarLista(struct node *head) 
{   
    struct node* temp = head;
    while(temp!=NULL)
    {
        printf("------------------------------\n");
        printf("nombre: %s\n", temp->cliente.nombre);
        printf("apellido: %s\n", temp->cliente.apellido);
        printf("email: %s\n", temp->cliente.email);
        printf("telefono: %s\n", temp->cliente.telefono);
        temp = temp->next;
    }
    
}

void mostarListaAlreves(struct node *head){
    if(head==NULL){
        printf("la lista esta vacia\n");
    return;
    }
    
    struct node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    while (temp != NULL)
    {  
        printf("------------------------------\n");
        printf("nombre: %s\n", temp->cliente.nombre);
        printf("apellido: %s\n", temp->cliente.apellido);
        printf("email: %s\n", temp->cliente.email);
        printf("telefono: %s\n", temp->cliente.telefono);
        temp = temp->prev;
    }
    printf("\n");
    
    
}

void freeLista(struct node* head){
    struct node* temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}



int main(){
    struct node *head = NULL;
    struct node *nuevoNodo;
    char nombre[64], apellido[64], email[128], telefono[15];
    int opcion;
    int opcionLista;
    do{
        printf("-----------------------\n");
        printf("1. Agregar cliente\n");
        printf("2. mostar lista\n");
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
                printf("desea ingresarlo al principio de la lista: 1   al final: 2\n");scanf("%d",&opcionLista);
                if(opcionLista==1){
                    insertarInicio(&head, nuevoNodo);
                }
                else if(opcionLista==2){
                    insertarFinal(&head, nuevoNodo);
                }
                else{
                    printf("opcion no valida\n");
                }
                break;
            case 2:
                printf("mostar lista\n");
                mostarLista(head);
                mostarListaAlreves(head);
                break;
            default:
                printf("Opcion invalida\n");
        }
    }while(opcion != 3);

    freeLista(head);

    return 0;
}