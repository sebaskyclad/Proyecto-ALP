#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef struct Articulo{
int id;
int cantidad;
char nombreMarca[20];
int precioCompra;
int precioVenta;
}Articulo;

typedef struct Usuario{
int id;
char name[10];
char pass[10];
}Usuario;

int LeeCadena(char *cl) {
    int i = 0;
    char car;
    do{
        car = getchar();
    }while ((car == '\n')||(car == '\t')||(car == ' '));//quita blancos
    if (car != '\n') {
        cl[i] = car;
        i++;
    }
    while ((car = getchar()) != '\n') {
        cl[i] = car;
        i++;
    }
    cl[i] = '\0';
    return i;
}
void Consulta(){

}
void Actualizar(){
}
void Eliminar(){
}
void Agregar(){
}
int login(){

    return 1;
}

void registrarUsuario(){
    system("CLS");
    FILE *arch;
    arch=fopen("Usuarios.txt")
    char user[10];
    char pass1[20];
    char pass2[20];
    printf("\nDigite el username: ");
    LeeCadena(user);
    printf("\nDigite la password: ");
    LeeCadena(pass1);
    printf("\nConfirme la password: ");
    LeeCadena(pass2);
    int i = strcmp(pass1,pass2);
    if (i==0){
        fopen()
    }


}
int main()
{
    int loginR;
    loginR =login();
    if (loginR==1){
    int opcion = 0;
    printf("-*-Bienvenido al sistema de inventario-*-\n");
    while(opcion!=-1){
        system("CLS");
       printf("Seleccione la opcion\n");
       printf("1. Consultar inventario\n");
       printf("2. Actualizar art�culos del inventario\n");
       printf("3. Eliminar art�culos del inventario\n");
       printf("4. Agregar al art�culos al inventario\n");
       printf("0. Registrar usuario\n");
       printf("5. Salir\n");
       scanf ("%d",&opcion);
       switch(opcion){
        case 1:
            Consulta();
            break;
        case 2:
            Actualizar();
            break;
        case 3:
            Eliminar();
            break;
        case 4:
            Agregar();
            break;
        case 0:
            registrarUsuario();
            break;
        case 5:
            printf("Hasta luego");
            return(0);
        default:
            printf("Funcion incorrecta");
       }
    }
    }
    else{
        printf("Error en el login");
    }
}
