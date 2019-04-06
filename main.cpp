#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef struct Articulo{
int CB;
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
    system("CLS");
    Articulo ar;
    Articulo arBuff;
    FILE *arch;
    arch=fopen("Inventario.data","ab");
    printf("Agregar un articulo al inventario.\n");
    printf("Digite el Codigo de barras\n");
    scanf("%d",&ar.CB);
    printf("Digite el nombre del producto\n");
    LeeCadena(ar.nombreMarca);

}
int login(){
    system("CLS");
    Usuario userN;
    Usuario userBuff;
    FILE *arch;
    arch=fopen("Usuarios.data","rb");
        printf("Digite sus credenciales.");
    printf("\nDigite el username: ");
    LeeCadena(userN.name);
    printf("\nDigite la password: ");
    LeeCadena(userN.pass);
    while(!feof(arch)){
            fread(&userBuff,sizeof(Usuario),1,arch);
            if(strcmp(userN.name,userBuff.name)==0&&strcmp(userN.pass,userBuff.pass)==0){
                fclose(arch);
                return 0; //Contraseñas correctas
            }
    }
    fclose(arch);
    printf("Credenciales equivocadas, vuelva a intentarlo\n");
    system("PAUSE");
    return -1;
}

int registrarUsuario(){
    system("CLS");
    Usuario userN;
    Usuario userBuff;
    FILE *arch;
    arch=fopen("Usuarios.data","ab");
    fclose(arch);
    char pass1[10];
    char pass2[10];
    printf("\nDigite el username: ");
    LeeCadena(userN.name);
    printf("\nDigite la password: ");
    LeeCadena(pass1);
    printf("\nConfirme la password: ");
    LeeCadena(pass2);
    int i = strcmp(pass1,pass2);
    if (i==0){
        strcpy(userN.pass,pass1);
        arch=fopen("Usuarios.data","rb");
        int cont = 0;
        while(!feof(arch)){
            cont++;
            fread(&userBuff,sizeof(Usuario),1,arch);
            if(strcmp(userN.name,userBuff.name)==0){
                return -1; //El usuario ya existe
            }
        }
        fclose(arch);
        cont++;
        arch = fopen("Usuarios.data","ab");
        userN.id=cont;
        fwrite(&userN,sizeof(Usuario),1,arch);
        fclose(arch);
        return 0; //Registro exitoso
    }else{
        return -2; //Contraseñas no coinciden
    }


}
int main()
{

    int loginR;
    while(loginR!=0){
    loginR =login();
    }
    int opcion = 0;
    printf("-*-Bienvenido al sistema de inventario-*-\n");
    while(opcion!=-1){
        system("CLS");
       printf("Seleccione la opcion\n");
       printf("1. Consultar inventario\n");
       printf("2. Actualizar artículos del inventario\n");
       printf("3. Eliminar artículos del inventario\n");
       printf("4. Agregar al artículos al inventario\n");
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
            {
            int r = registrarUsuario();
            switch(r){
                case -1:
                    printf("Error: El usuario ya existe\n");
                    break;
                case -2:
                    printf("Error: Las constraseñas no coinciden\n");
                    break;
                case 0:
                    printf("Usuario registrado correctamente\n");
                    break;
            }
            system("PAUSE");

            break;
            }
        case 5:
            printf("Hasta luego");
            return(0);
        default:
            printf("Funcion incorrecta");
       }
    }

}
