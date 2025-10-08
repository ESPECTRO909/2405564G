#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int folio;
    int idCliente;
    double pesoKg;
    char origen[64];
    char destino[64];
    char fechaEnvio[11];
    char estado[16];
}paquetes;

struct nodo{
    paquetes paquete;
    struct nodo *next;
};

typedef struct{
    struct nodo *top;
}nodoStack; 

//prototipos

//crear 
nodoStack* crearPila(void){
    nodoStack *stack = (nodoStack*)malloc(sizeof(nodoStack));
    if(stack == NULL){
        printf("Error al crear la pila\n");
        return(NULL);
    }

    stack->top = NULL;
    return stack;
}

//apilar
int paqueteStackPush(nodoStack *stack, paquetes valor){
    struct nodo *nuevoNodo = (struct nodo*)malloc(sizeof(struct nodo));
    if(nuevoNodo == NULL){
        printf("Error al crear el nodo\n");
        return 0;
    }

    nuevoNodo->paquete = valor;
    nuevoNodo->next = stack->top;
    stack->top = nuevoNodo;
    return 1;
}

//desapilar
int paqueteStackPop(nodoStack *stack, paquetes *out){
    if(stack->top == NULL){
        printf("La pila esta vacia\n");
        return 0;
    }
    
    struct nodo *temp = stack->top;
    *out = temp->paquete;
    stack->top = stack->top->next;
    free(temp);
    return 1;
}

//verificar si la pila esta vacia
int pilaVacia(const nodoStack *stack){
    return stack->top == NULL;
}

//libear toda la pila
void liberarPila(nodoStack *stack){
    struct nodo *temp = stack->top;
    while(temp != NULL){
        struct nodo *next = temp->next;
        free(temp);
        temp = next;
    }
    free(stack);
}

//mostar pila
void mostrarPila(const nodoStack *stack){
    if(stack->top == NULL){
        printf("\n");
        printf("La pila esta vacia\n");
        return;
    }

    struct nodo *temp = stack->top;
    printf("\n");
    printf("Contenido de la pila:\n");
    while(temp != NULL){
        printf("Folio: %d, ID Cliente: %d, Peso (kg): %.2f, Origen: %s, Destino: %s, Fecha de Envio: %s, Estado: %s\n",
            temp->paquete.folio, temp->paquete.idCliente, temp->paquete.pesoKg,
            temp->paquete.origen, temp->paquete.destino,
            temp->paquete.fechaEnvio, temp->paquete.estado);
        temp = temp->next;
    }
    printf("\n");
}


void limpiarPantalla(){
        system("clear");
}


int main(void){
    nodoStack *miPila = crearPila();

    int folio;
    int idCliente;
    double pesoKg;
    char origen[64];
    char destino[64];
    char fechaEnvio[11];
    char estado[16];
    int opcionMenu;
    do{
        limpiarPantalla();
        printf("Menu de gestion de paquetes\n");
        printf("--------------------------\n");
        printf("1.apilar paquete\n");
        printf("2.desapilar paquete\n");
        printf("3.mostrar pila\n");
        printf("4.salir\n");
        printf("ingrese una opcion: ");
        scanf("%d",&opcionMenu);
        switch (opcionMenu)
        {
        case 1:
            printf("apilar paquete\n");
            printf("ingrese el folio: "); scanf("%d",&folio);
            printf("ingrese el id del cliente: "); scanf("%d",&idCliente);
            printf("ingrese el peso en kg: "); scanf("%lf",&pesoKg);
            printf("ingrese el origen: "); scanf("%s",origen);
            printf("ingrese el destino: "); scanf("%s",destino);
            printf("ingrese la fecha de envio (YYYY-MM-DD): "); scanf("%s",fechaEnvio);
            printf("ingrese el estado: "); scanf("%s",estado);
            paquetes nuevoPaquete;
            nuevoPaquete.folio = folio;
            nuevoPaquete.idCliente = idCliente;
            nuevoPaquete.pesoKg = pesoKg;
            strcpy(nuevoPaquete.origen, origen);
            strcpy(nuevoPaquete.destino, destino);
            strcpy(nuevoPaquete.fechaEnvio, fechaEnvio);
            strcpy(nuevoPaquete.estado, estado);
            paqueteStackPush(miPila,nuevoPaquete);

            break;
        
            case 2:
                printf("desapilar paquete\n");
                paquetes paqueteDesapilado;
                if(paqueteStackPop(miPila, &paqueteDesapilado)){
                    printf("Paquete desapilado: Folio %d\n", paqueteDesapilado.folio);
                }
                break;
            
            case 3:
                int opcion3=0;
                do{
                limpiarPantalla();
                printf("mostrar pila\n");
                mostrarPila(miPila);
                printf("desea desapilar el paquete de la cima? 1.si  2.no\n");
                int opcionDesapilar;
                scanf("%d",&opcionDesapilar);
                if(opcionDesapilar == 1){
                    paquetes paqueteDesapilado;
                    if(paqueteStackPop(miPila, &paqueteDesapilado)){
                        printf("Paquete desapilado: Folio %d\n", paqueteDesapilado.folio);
                    }
                }else{opcion3=2;}
                }   
                while(opcion3 !=2);
                break;
            case 4:
                printf("saliendo...\n");
                opcionMenu=4;
                break;

        default:
            break;
        }
        char enter;
        printf("presione enter para continuar\n");
        getchar();
        scanf("%c",&enter);
    }while(opcionMenu != 4);

    liberarPila(miPila);
    return 0;

}