#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
typedef struct Bitacora{
char usuario[10];
char accion[20];
char resultado[10];
}Bitacora;
char usuarioActual[10];
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
    system("cls");
    Articulo ar;
    FILE *arch;
    arch=fopen("Inventario.data","rb");
    printf("\nCodigo de Barra\tNombre del producto\tCantidad\tPrecio de compra\tPrecio de venta\n");
    while(!feof(arch))
    {
    	fread(&ar,sizeof(Articulo),1,arch);
    	printf("%d\t%s\t%d\t%d\t%d\n",ar.CB,ar.nombreMarca,ar.cantidad,ar.precioCompra,ar.precioVenta);
    }
    system("pause");
	fclose(arch);
}
void ConsultaB(){
    system("cls");
    Bitacora B;
    FILE *arch;
    arch=fopen("Eventos.data","rb");
    printf("Usuario\tAcciontResultado\n");
    while(!feof(arch))
    {
    	fread(&B,sizeof(Bitacora),1,arch);
    	printf("%s\t%s\t%s\n",B.usuario,B.accion,B.resultado);
    }
    system("pause");
	fclose(arch);
}
void Actualizar(){
     system("cls");
            FILE *file, *fileAux;
            Articulo ar;
            fileAux=fopen("InventarioAux.data","wb");
            file=fopen("Inventario.data","rb");
            if(!file){
                printf("No hay nada en el archivo\n");
            }
            else{
                int cb;
                printf("Escribe el codigo de barra del producto a modificar:\n");
                fflush(stdin);
                scanf("%d",&cb);
                //Recibe los mismo parametros que fwrite
                while(fread(&ar, sizeof(Articulo),1, file)){

                    if (ar.CB!=cb){
                        fwrite(&ar, sizeof(Articulo),1, fileAux);
                    }else{
                        printf("Digite el nuevo nombre del producto\n");
                        LeeCadena(ar.nombreMarca);
                        printf("Digite el nuevo Precio de venta\n");
                        scanf("%d",&ar.precioVenta);
                        printf("Digite el nuevo Precio de compra\n");
                        scanf("%d",&ar.precioCompra);
                        printf("Digite las nuevas unidades del producto\n");
                        scanf("%d",&ar.cantidad);
                        fwrite(&ar, sizeof(Articulo),1, fileAux);
                    }
                }
                fclose(file);
                fclose(fileAux);

                fileAux=fopen("InventarioAux.data","rb");
                file=fopen("Inventario.data","wb");
                while(fread(&ar, sizeof(Articulo),1, fileAux)){
                    fwrite(&ar, sizeof(Articulo),1, file);
                }

            }
            fclose(file);
            fclose(fileAux);
}
void Eliminar(){
            system("cls");
            FILE *file, *fileAux;
            Articulo ar;
            fileAux=fopen("InventarioAux.data","wb");
            file=fopen("Inventario.data","rb");
            if(!file){
                printf("No hay nada en el archivo\n");
            }
            else{
                int cb;
                printf("Escribe el codigo de barra del producto a borrar:\n");
                fflush(stdin);
                scanf("%d",&cb);
                //Recibe los mismo parametros que fwrite
                while(fread(&ar, sizeof(Articulo),1, file)){

                    if (ar.CB!=cb){
                    fwrite(&ar, sizeof(Articulo),1, fileAux);
                    }
                }
                fclose(file);
                fclose(fileAux);

                fileAux=fopen("InventarioAux.data","rb");
                file=fopen("Inventario.data","wb");
                while(fread(&ar, sizeof(Articulo),1, fileAux)){
                    fwrite(&ar, sizeof(Articulo),1, file);
                }

            }
            fclose(file);
            fclose(fileAux);



}
int Agregar(){
    system("CLS");
    Articulo ar;
    Articulo arBuff;
    FILE *arch;
    arch=fopen("Inventario.data","ab");
    printf("Agregar un articulo al inventario.\n");
    printf("Digite el Codigo de barras\n");
    scanf("%d",&ar.CB);
    arch=fopen("Inventario.data","rb");
    while(!feof(arch)){
            fread(&arBuff,sizeof(Articulo),1,arch);
            if(ar.CB==arBuff.CB){
                return -1; //Articulo ya registrado
            }
        }
    printf("Digite el nombre del producto\n");
    LeeCadena(ar.nombreMarca);
    printf("Digite el Precio de venta\n");
    scanf("%d",&ar.precioVenta);
    printf("Digite el Precio de compra\n");
    scanf("%d",&ar.precioCompra);
    printf("Digite las unidades del producto\n");
    scanf("%d",&ar.cantidad);
        fclose(arch);
        arch = fopen("Inventario.data","ab");
        fwrite(&ar,sizeof(Articulo),1,arch);
        fclose(arch);
        return 0; //Registro exitoso


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
                strcpy(usuarioActual,userN.name);
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
void Evento(int evento){
    Bitacora Bit;
    FILE *arch;
    arch=fopen("Eventos.data","ab");
    switch(evento){
    case 0: //Login Exitoso
        strcpy(Bit.usuario,usuarioActual);
        strcpy(Bit.accion,"Login");
        strcpy(Bit.resultado,"Exitoso");
        fwrite(&Bit,sizeof(Bit),1,arch);
    case 1: //Consulta
        strcpy(Bit.usuario,usuarioActual);
        strcpy(Bit.accion,"Consulta Inventario");
        strcpy(Bit.resultado,"Exitoso");
        fwrite(&Bit,sizeof(Bit),1,arch);
      case 2: //Modificacion fallida
        strcpy(Bit.usuario,usuarioActual);
        strcpy(Bit.accion,"Login");
        strcpy(Bit.resultado,"Exitoso");
        fwrite(&Bit,sizeof(Bit),1,arch);
      case 3: //Modificaci exutisa
        strcpy(Bit.usuario,usuarioActual);
        strcpy(Bit.accion,"Login");
        strcpy(Bit.resultado,"Exitoso");
        fwrite(&Bit,sizeof(Bit),1,arch);
      case 4: //Consulta
        strcpy(Bit.usuario,usuarioActual);
        strcpy(Bit.accion,"Login");
        strcpy(Bit.resultado,"Exitoso");
        fwrite(&Bit,sizeof(Bit),1,arch);
      case 5: //Consulta
        strcpy(Bit.usuario,usuarioActual);
        strcpy(Bit.accion,"Login");
        strcpy(Bit.resultado,"Exitoso");
        fwrite(&Bit,sizeof(Bit),1,arch);
      case 6: //Consulta
        strcpy(Bit.usuario,usuarioActual);
        strcpy(Bit.accion,"Login");
        strcpy(Bit.resultado,"Exitoso");
        fwrite(&Bit,sizeof(Bit),1,arch);
      case 7: //Consulta
        strcpy(Bit.usuario,usuarioActual);
        strcpy(Bit.accion,"Login");
        strcpy(Bit.resultado,"Exitoso");
        fwrite(&Bit,sizeof(Bit),1,arch);
    }
        fclose(arch);


}
int main()
{

    int loginR;
    while(loginR!=0){
    loginR =login();
    }
    Evento(0);
    char opcion = '0';
    printf("-*-Bienvenido al sistema de inventario-*-\n");
    while(opcion!='5'){
    fflush(stdin);
    char opcion = '0';
       system("CLS");
       printf("Seleccione la opcion\n");
       printf("1. Consultar inventario\n");
       printf("2. Actualizar artículos del inventario\n");
       printf("3. Eliminar artículos del inventario\n");
       printf("4. Agregar al artículos al inventario\n");
       printf("5. Registrar usuario\n");
       printf("6. Consultar Bitacora\n");
       printf("7. Salir\n");
       scanf("%c", &opcion);
       if(isdigit(opcion)){
       switch(opcion){
        case '1':
            Consulta();
            Evento(1);
            break;
        case '2':
            Actualizar();
            break;
        case '3':
            Eliminar();
            break;
        case '4':
            {
            int a = Agregar();
            switch(a){
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
            break;
            system("PAUSE");
            }
        case '5':
            {
            int r = registrarUsuario();
            switch(r){
                case -1:
                    printf("Error: El articulo ya existe\n");
                    break;
                case 0:
                    printf("Articulo registrado correctamente\n");
                    break;
            }

            system("PAUSE");
            break;
            }
        case '7':
            printf("Hasta luego");
            return(0);
        case '6':
            ConsultaB();
            return(0);



        default:
            printf("Verifique su entrada\n");
       }
       }
       else{
            printf("Funcion incorrecta\n");
           system("PAUSE");
       }
    }

}
