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
    //reservado de memoria para el nodo
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


//es diferente a las otras listas
void insertarFinal(struct node **head, struct node *nuevoNodo){
    if(*head == NULL){
        *head = nuevoNodo;
        nuevoNodo->next = nuevoNodo;
        nuevoNodo->prev = nuevoNodo;
    }

    else{
        struct node *ultimo = (*head)->prev;//obtengo el ultimo
        
        ultimo->next = nuevoNodo;//el ultimo apunta al nuevo
        nuevoNodo->prev = ultimo;//el nuevo apunta hacia atras
        nuevoNodo->next = *head;//ahoara apunta al primero osea la cabeza
        (*head)->prev = nuevoNodo;// y la cabeza apunta hacia atras osea al nuevo
    }
}

void insertarInicio(struct node **head, struct node *nuevoNodo){
    if(*head == NULL){
        *head = nuevoNodo;
        nuevoNodo->next = nuevoNodo;
        nuevoNodo->prev = nuevoNodo;

    }
    else{
        struct node *ultimo = (*head)->prev;

        nuevoNodo->next = *head;
        nuevoNodo->prev = ultimo;
        ultimo->next = nuevoNodo;
        (*head)->prev = nuevoNodo;
        *head = nuevoNodo;
    }

}

void mostarLista(struct node *head) 
{   
    struct node* temp = head;
    do{
        printf("------------------------------\n");
        printf("nombre: %s\n", temp->cliente.nombre);
        printf("apellido: %s\n", temp->cliente.apellido);
        printf("email: %s\n", temp->cliente.email);
        printf("telefono: %s\n", temp->cliente.telefono);
        temp = temp->prev;
    }while(temp!=head);
}

//actualizar funcion para esta lista , queda en bucle debido que no hay un NULL
void mostarListaAlreves(struct node *head){
    if(head==NULL){
        printf("la lista esta vacia\n");
    return;
    }
    
    struct node* temp = head->prev;
    struct node* ultimo = temp;

    do{  
        printf("------------------------------\n");
        printf("nombre: %s\n", temp->cliente.nombre);
        printf("apellido: %s\n", temp->cliente.apellido);
        printf("email: %s\n", temp->cliente.email);
        printf("telefono: %s\n", temp->cliente.telefono);
        temp = temp->prev;
    }while (temp != ultimo);

    printf("\n");
}

void borrarPorNombre(struct node **head, const char *nombre){
    if(*head == NULL){
        printf("Lista vacia\n");
        return ;
    }

    struct node *temp = *head;

    do{
        if(strcmp(temp->cliente.nombre, nombre) == 0){

            if(temp->next == temp && temp->prev == temp){
            free(temp);
            *head = NULL;
            printf("nodo %s eliminado, la lista ahora esta vacia\n",nombre);
            return ;
            }
        
            //renlazado de nodos 
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            
            if(temp == *head){
                *head = temp->next;
            }
            printf("nodo %s eliminado correctamente\n",nombre);
            free(temp);
            return ;
        }
            
    
        temp = temp->next;
    }while(temp != *head);

    printf("no se encontro el nodo con el nombre %s \n",nombre);
}





void freeLista(struct node* head){
    if(head == NULL)return;

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
        printf("3. mas opciones\n");
        printf("4. salir\n");

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
                int opcionMostarLista;
                printf("mostar lista\n");
                printf("mostar normal: 1  mostar lista al reves: 2 \n");scanf("%d",&opcionMostarLista);
                if(head != NULL){
                if(opcionMostarLista==1){
                    mostarLista(head);
                }else if(opcionMostarLista==2){
                    mostarListaAlreves(head);
                }
                else{
                    printf("opcion no valida\n");
                }
                }
                break;
            
                case 3:
                    char borrarNombre[64];
                    printf("mas opciones\n");
                    printf("1.borrar por nombre\n"); scanf("%s",borrarNombre);
                    borrarPorNombre(&head, borrarNombre);
                    break;
                
                case 4:
                    printf("saliendo\n");
                    opcion = 4;
                break;
                
            default:
                printf("Opcion invalida\n");
        }
    }while(opcion != 4);
    
    //liberacion de toda la memoria reservada
    freeLista(head);
    return 0;
}