// OSCAR OMAR AGUILERA DE LA TORRE MAESTRA VERONICA CAMACHO SANTILLAN
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
//variables globales
int j, buscarVar;
char mensaje_predeterminado[] = "Campo vacio";
//Prototipos de las funciones utilizadas durante todo el programa
void animacion();
void marco();
int menu();
void estetico();
void aniSalida();
int capturar();
int mostrar();
int buscar();
int modificar();
int eliminar();
void salir();
void gotoxy();
void batarang();
//Definicion de la estructura alumno 
struct alumno{
    char nombre[80], domicilio[80], fraccionamiento[40], fechaNacimiento[25];
    char ciudad[40], email[40], notas[200];
    char edad[4], codigoPostal[20], telefono[20];
    int identificador;
    struct academico{
        char promedio[5], codigo[20], nss[25];
        char carrera[60], semestre[15] , instituto[60], nrc[10], seccion[10];
        char materia[40], maestro[80], turno[20];
    }academic;
}al[10];
//Funcion principal o funcion llamadora
int main(){
	setlocale(LC_ALL, "spanish");
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    system("cls");
    //Variables utilizadas para el acceso por contraseña
    int respuesta;
    int i=0, nip, cont =0;
    //do-while que controla el numero de intentos para ingresar la contraseña
    do{
        system("cls");
        marco();
        gotoxy(4, 2);
        printf("---------------------Powered By Wayne Enterprises---------------------------\n");
        gotoxy(4, 3);
        printf("____________________________________________________________________________\n");
        gotoxy(4, 5);
        printf("          ¡Bienvenido, por favor ingrese su clave de acceso!\n");
        gotoxy(4, 6);
        printf("____________________________________________________________________________\n");
        batarang();
        scanf("%i", &nip);
        cont++;
	//while en caso de que se exceda el numero de intentos para el ingreso de la contraseña o se ingrese una contraseña incorrecta
    }while(nip!=123 && cont<3);
    if(cont<=3&&nip!=123){
        system("cls");
        marco();
        batarang();
        gotoxy(10,7);
        printf("\t\t\a    ¡CLAVE DE ACCESO INCORRECTA!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t");
    }
    //si la contraseña es correcta entonces...
    if(nip ==123){
       while(1){
        marco();
        animacion();
        system("cls");
        marco();
        //llamado de la funcion menu, se iguala a la variable que retorna la funcion menu, esto para identificar la accion que desea el usuario
        int switchVar = menu();
        switch(switchVar){
        case 1:
            marco();
            animacion();
            //en caso de que la entrada sea 1, ejecutar la funcion capturar
            capturar(i);
            i++;
            break;
        case 2:
            animacion();
            marco();
            //en caso de que la entrada sea 1, ejecutar la funcion mostrar
            mostrar(j);
            break;
        case 3:
            animacion();
            marco();
            //en caso de que la entrada sea 1, ejecutar la funcion buscar
            buscar(j);
            break;
        }
        marco();
        gotoxy(21, 27);
        //preguntar al usuario si desea ejecutar el programa despues de cada instruccion o accion
        printf("\t¿Desea Volver a ejecutarlo?\t1.-Sí\t2.-No\n");
        scanf("%i", &respuesta);
        //si el usuario decide no ejecutarlo de nuevo se rompre el while(1) "while true" y se muestra un mensaje en pantalla de despedida
        if(respuesta!=1 || i >=10){
            aniSalida();
            break;
        }else if(respuesta ==1){
            estetico();
        }
    }
    }

    return 0;
}
//funcion menu
int menu(){
    int opc;
    printf("\t\t");
    gotoxy(13, 2);
    //diseño de pantalla con fines esteticos
    printf("\t\t¡Bienvenido a su agenda personal!\n");
    gotoxy(4, 3);
    printf("____________________________________________________________________________\n");
    printf("\t\t\t||_______________________||__________________________|\n");
    printf("\t\t\t| _____________________  ||      __   __  _  __    _ |\n");
    printf("\t\t\t|| |P| | | |R| | | |R| | __..\\/ |  |_|  ||#||==|  / /|\n");
    printf("\t\t\t|| | |R| |G| |A| |A| | |/\\     \\|++|=|  || ||==| / / |\n");
    printf("\t\t\t||_|_|_|O|_|_|_|M|_|_|_/\\/\\_.__ \\__|_|__||_||__|/_/__|\n");
    printf("\t\t\t|____________________ /\\~()/()~//\\ __________________|\n");
    printf("\t\t\t| __   __    _  _     \\_  (_    _/ _    ___     _____|\n");
    printf("\t\t\t||~~|_|..|__| || |_ _   \\ //\\\\ /  |=|__|~|~|___| | | |\n");
    printf("\t\t\t||--|+|^^|==|1||2| | |__/\\ __ /\\__| |==|x|x|+|+|=|=| |\n");
    printf("\t\t\t||__|_|__|__|_||_|_| /  \\ \\  / /  \\_|__|_|_|_|_|_|_|_|\n");
    printf("\t\t\t|_________________ _/    \\/\\/      \\_ _______________|\n");
    printf("\t\t\t| _____   _   __  |/      \\../      \\|  __   __   ___|\n");
    printf("\t\t\t||_____|_| |_|##|_||   |   \\/ __|   ||_|==|_|++|_|-|||\n");
    printf("\t\t\t||______||=|#|--| |\\   \\   o    /   /| |  |~|  | | |||\n");
    printf("\t\t\t||_JRO__||_|_|__|_|_\\   \\  o   /   /_|_|__|_|__|_|_|||\n");
    printf("\t\t\t|_________ __________\\___\\____/___/___________ ______|\n");
    printf("\t\t\t|__    _  /    ________     ______           /| _ _ _|\n");
    printf("\t\t\t|\\ \\  |=|/   //    /| //   /  /  / |        / ||%%| |%%|\n");
    printf("\t\t\t| \\/\\ |*/  .//____//.//   /__/__/ (_)      /  ||=|=|=|\n");
    printf("\t\t\t|__\\_\\ /   /(____|/ //                    /  /||~|~|~|\n");
    printf("\t\t\t|___\\_/   /________//   ________         /  / ||_|_|_|\n");
    printf("\t\t\t|___ /   (|________/   |\\_______\\       /  /| |______|\n");
    printf("\t\t\t    /   ALFRED         \\|________)     /  / | |\n");
    printf("\t\t\t______________________________________________________");
    gotoxy(4,4);
    printf("¿Qué desea hacer?\n");
    gotoxy(4,6);
    printf("1.-Capturar");
    gotoxy(4,8);
    printf("2.-Mostrar");
    gotoxy(4,10);
    printf("3.-Buscar:");
    gotoxy(4,12);
    printf("      Modificar");
    gotoxy(4,14);
    printf("      Eliminar");
    gotoxy(4,16);
    printf("6.-Salir");
    gotoxy(4,18);
    printf("Opción:");
    scanf("%i", &opc);
    system("cls");
    return opc;
}
//funcion necesaria para mostrar impresiones en pantalla por medio de coordenadas
void gotoxy(int x, int y)
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}
//funcion marco apoyada en impresiones en pantalla por medio de coordenadas "gotoxy()"
void marco(){

    int i;
    // Configurar colores
    system("color 81");

    // Dibujar el marco
    for (i = 1; i < 29; i++)
    {
        gotoxy(3, i);
        printf("%c", 124);
    }

    for (i = 4; i < 80; i++)
    {
        gotoxy(i, 1);
        printf("%c", 278);
    }

    for (i = 1; i < 29; i++)
    {
        gotoxy(80, i);
        printf("%c", 124);
    }

    for (i = 4; i < 80; i++)
    {
        gotoxy(i, 28);
        printf("%c", 278);
    }
}
//funcion capturar
int capturar(int i){
	/*funciones utilizadas:
	setlocale(LC_ALL, "spanish");
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    gets("*Aqui se ingresa el indice a donde ira almacenada la informacion en nuestro arreglo*") <--- funcion necesaria de lectura de datos de entrada de tipo caracter
    */
    printf("\t\t");
    marco();
    gotoxy(10, 2);
    printf("¡Bienvenido a capturar, por favor ingrese sus datos personales!\n");
    gotoxy(4, 3);
    fflush(stdin);
    printf("____________________________________________________________________________\n");
    printf("\t\tIngrese su nombre: ");
    gets(al[i].nombre);
    fflush(stdin);
    gotoxy(4, 5);
    printf("____________________________________________________________________________\n");
    printf("\t\tIngrese su edad: ");
    gets(al[i].edad);
    fflush(stdin);
    gotoxy(4, 7);
    printf("____________________________________________________________________________\n");
    printf("\t\tIngrese su fecha de nacimiento Día/Mes/año: ");
    gets(al[i].fechaNacimiento);
    fflush(stdin);
    gotoxy(4, 9);
    printf("____________________________________________________________________________\n");
    printf("\t\tIngrese su domicilio: ");
    gets(al[i].domicilio);
    fflush(stdin);
    gotoxy(4, 11);
    printf("____________________________________________________________________________\n");
    printf("\t\tIngrese su Ciudad: ");
    gets(al[i].ciudad);
    fflush(stdin);
    gotoxy(4, 13);
    printf("____________________________________________________________________________\n");
    printf("\t\tIngrese su código postal: ");
    gets(al[i].codigoPostal);
    fflush(stdin);
    gotoxy(4, 15);
    printf("____________________________________________________________________________\n");
    printf("\t\tIngrese su fraccionamiento: ");
    gets(al[i].fraccionamiento);
    fflush(stdin);
    gotoxy(4, 17);
    printf("____________________________________________________________________________\n");
    printf("\t\tIngrese su teléfono: ");
    gets(al[i].telefono);
    fflush(stdin);
    gotoxy(4, 19);
    printf("____________________________________________________________________________\n");
    printf("\t\tIngrese su e-mail: ");
    gets(al[i].email);
    fflush(stdin);
    gotoxy(4, 21);
    printf("____________________________________________________________________________\n");
    printf("\t\tNotas: ");
    gets(al[i].notas);
    fflush(stdin);
    system("cls");
    marco();
    gotoxy(10, 2);
    printf("¡Bienvenido a capturar, por favor ingrese sus datos académicos!\n");
    gotoxy(4, 3);
    printf("____________________________________________________________________________\n");
    printf("\t\tCódigo de alumno: ");
    gets(al[i].academic.codigo);
    fflush(stdin);
    gotoxy(4, 5);
    printf("____________________________________________________________________________\n");
    printf("\t\tNúmero de seguro social: ");
    gets(al[i].academic.nss);
    fflush(stdin);
    gotoxy(4, 7);
    printf("____________________________________________________________________________\n");
    printf("\t\tInstituto: ");
    gets(al[i].academic.instituto);
    fflush(stdin);
    gotoxy(4, 9);
    printf("____________________________________________________________________________\n");
    printf("\t\tCarrera: ");
    gets(al[i].academic.carrera);
    fflush(stdin);
    gotoxy(4, 11);
    printf("____________________________________________________________________________\n");
    printf("\t\tSemestre: ");
    gets(al[i].academic.semestre);
    fflush(stdin);
    gotoxy(4, 13);
    printf("____________________________________________________________________________\n");
    printf("\t\tTurno: ");
    gets(al[i].academic.turno);
    fflush(stdin);
    gotoxy(4, 15);
    printf("____________________________________________________________________________\n");
    printf("\t\tMateria: ");
    gets(al[i].academic.materia);
    fflush(stdin);
    gotoxy(4, 17);
    printf("____________________________________________________________________________\n");
    printf("\t\tNrc: ");
    gets(al[i].academic.nrc);
    fflush(stdin);
    gotoxy(4, 19);
    printf("____________________________________________________________________________\n");
    printf("\t\tSección: ");
    gets(al[i].academic.seccion);
    fflush(stdin);
    gotoxy(4, 21);
    printf("____________________________________________________________________________\n");
    printf("\t\tMaestro: ");
    gets(al[i].academic.maestro);
    fflush(stdin);
    gotoxy(4, 23);
    printf("____________________________________________________________________________\n");
    printf("\t\tPromedio: ");
    gets(al[i].academic.promedio);
    fflush(stdin);
    //encriptacion del iterador 'i' para usarse posteriormente como identificador unico de usuario, (nos ayuda a acceder a datos especificos de cada usuario)
    //variables de encriptacion
    int clave1 = 0b10101010;
    int clave2 = 3;
    int numCript = (i^clave1)<<clave2;
    gotoxy(4, 25);
    printf("____________________________________________________________________________\n");
    printf("\tSu número de registro es '%i' sera necesario para acceder a sus datos", numCript);
    j = numCript;
}
int mostrar(){
	setlocale(LC_ALL, "spanish");
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    batarang();
    gotoxy(10, 2);
    printf("¡Bienvenido a mostrar, por favor ingrese su número de registro!\n");
    gotoxy(4, 3);
    printf("____________________________________________________________________________\n");
    scanf("%i", &j);
    system("cls");
    //desencriptacion del iterador 'i' para usarse posteriormente como identificador unico de indice en el arreglo de datos, (nos ayuda a acceder a datos especificos de cada usuario)
    //variables de encriptacion
    int clave1 = 0b10101010;
    int clave2 = 3;
    int numDesencriptado = (j>>clave2)^clave1;
    	//si el numero desencriptado coincide con el indice de entrada de datos entonces...
        if(numDesencriptado>=0 && numDesencriptado<=10){
        	//gotoxy()<-- nos ayuda a acomodar la estetica en pantalla
        	//printf("*El argumento de esta funcion sera el indice que corresponde al identificador unico de usuario desencriptado, -variable llamada- --> "numDesencriptado"*")<-- nos imprime los datos en pantalla
            marco();
            gotoxy(4, 2);
            printf("   ¡Hola! %s tus datos son los siguientes", al[numDesencriptado].nombre);
            gotoxy(4, 3);
            printf("____________________________________________________________________________\n");
            gotoxy(4, 4);
            printf("\tDATOS PERSONALES:");
            gotoxy(4, 5);
            printf("\tNombre: %s", al[numDesencriptado].nombre);
            gotoxy(4, 6);
            printf("\tEdad: %s", al[numDesencriptado].edad);
            gotoxy(4, 7);
            printf("\tFecha de nacimiento: %s", al[numDesencriptado].fechaNacimiento);
            gotoxy(4, 8);
            printf("\tDomicilio: %s", al[numDesencriptado].domicilio);
            gotoxy(4, 9);
            printf("\tCiudad: %s", al[numDesencriptado].ciudad);
            gotoxy(4, 10);
            printf("\tCódigo postal: %s", al[numDesencriptado].codigoPostal);
            gotoxy(4, 11);
            printf("\tFraccionamiento: %s", al[numDesencriptado].fraccionamiento);
            gotoxy(4, 12);
            printf("\tTeléfono: %s", al[numDesencriptado].telefono);
            gotoxy(4, 13);
            printf("\tE-mail: %s", al[numDesencriptado].email);
            gotoxy(4, 14);
            printf("\tNotas: %s", al[numDesencriptado].notas);
            gotoxy(4,15);
            printf("____________________________________________________________________________\n");
            gotoxy(4, 16);
            printf("\tDATOS ACADÉMICOS:");
            gotoxy(4, 17);
            printf("\tCódigo de alumno: %s", al[numDesencriptado].academic.codigo);
            gotoxy(4, 18);
            printf("\tNúmero de seguro social: %s", al[numDesencriptado].academic.nss);
            gotoxy(4, 19);
            printf("\tInstituto: %s", al[numDesencriptado].academic.instituto);
            gotoxy(4, 20);
            printf("\tCarrera: %s", al[numDesencriptado].academic.carrera);
            gotoxy(4, 21);
            printf("\tSemestre: %s", al[numDesencriptado].academic.semestre);
            gotoxy(4, 22);
            printf("\tTurno: %s", al[numDesencriptado].academic.turno);
            gotoxy(4, 23);
            printf("\tMateria: %s", al[numDesencriptado].academic.materia);
            gotoxy(4, 24);
            printf("\tNrc: %s", al[numDesencriptado].academic.nrc);
            gotoxy(4, 25);
            printf("\tSección: %s", al[numDesencriptado].academic.seccion);
            gotoxy(4, 26);
            printf("\tMaestra: %s", al[numDesencriptado].academic.maestro);
            gotoxy(4, 27);
            printf("\tPromedio: %s", al[numDesencriptado].academic.promedio);
            gotoxy(21, 27);
        } else{
        	//mensaje de tolerancia a errores en el ingreso del numero de registro
            system("cls");
            marco();
            gotoxy(20, 2);
            printf("\a         _nnnn_                      \n");
            gotoxy(20, 3);
            printf("        dGGGGMMb     ,.................................\n");
            gotoxy(20, 4);
            printf("       @p~qp~~qMb    |¡Número de registro incorrecto! |\n");
            gotoxy(20, 5);
            printf("       M|@||@) M|   _,.................................'\n");
            gotoxy(20, 6);
            printf("       @,----.JM| -'\n");
            gotoxy(20, 7);
            printf("      JS^\\__/  qKL\n");
            gotoxy(20, 8);
            printf("     dZP        qKRb\n");
            gotoxy(20, 9);
            printf("    dZP          qKKb\n");
            gotoxy(20, 10);
            printf("   fZP            SMMb\n");
            gotoxy(20, 11);
            printf("   HZM            MMMM\n");
            gotoxy(20, 12);
            printf("   FqM            MMMM\n");
            gotoxy(20, 13);
            printf(" __| \ .        |\\dS\ qML\n");
            gotoxy(20, 14);
            printf(" |    `.`       | `\' \\Zq\n");
            gotoxy(20, 15);
            printf("_)      \\.___.,|     .\'\n");
            gotoxy(20, 16);
            printf("\\____   )MMMMMM|   .\'\n");
            gotoxy(20, 17);
            printf("     `-'       `--\' hjm\ \n");
            Sleep(1000);
        }
}

int buscar(){
	setlocale(LC_ALL, "spanish");
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    int accion;
    gotoxy(10, 2);
    printf("¡Bienvenido a buscar, por favor ingrese su número de registro!\n");
    gotoxy(4, 3);
    printf("____________________________________________________________________________\n");
    batarang();
    scanf("%i", &j);
    system("cls");
    //desencriptacion del iterador 'i' para usarse posteriormente como identificador unico de indice en el arreglo de datos, (nos ayuda a acceder a datos especificos de cada usuario)
    //variables de encriptacion
    int clave1 = 0b10101010;
    int clave2 = 3;
    int numDesencriptado = (j>>clave2)^clave1;
    	//si el numero desencriptado coincide con el identificador unico de usuario entonces muestra en pantalla que dato desea buscar
        if(numDesencriptado>=0 && numDesencriptado<=10){
            marco();
            gotoxy(10, 2);
            printf("\tHola! %s ¿qué dato deseas buscar?\n\t1.-Nombre\n\t2.-Edad\n\t3.-Fecha de nacimiento\n\t4.-Domicilio\n", al[numDesencriptado].nombre);
            printf("\t5.-Ciudad\n\t6.-Código postal\n\t7.-Fraccionamiento\n\t8.-Teléfono\n\t9.-E-mail\n\t10.-Notas\n");
            printf("\t11.-Código de alumno\n\t12.-Número de seguro social\n\t13.-Instituto\n\t14.-Carrera\n");
            printf("\t15.-Semestre\n\t16.-Turno\n\t17.-Materia\n\t18.-Nrc\n\t19.-Sección\n\t20.-Maestro\n\t21.-Promedio\n");
            scanf("%i", &buscarVar);
            system("cls");
            marco();
            gotoxy(10, 2);
            printf("¡Bienvenido a buscar, aquí esta el dato seleccionado!\n");
            gotoxy(4, 3);
            printf("____________________________________________________________________________\n\n");
            switch(buscarVar){
            //se muestra el dato y se le pregunta al usuario si desea eliminarlo o modificarlo
            case 1:
                printf("\tNombre: %s\n", al[numDesencriptado].nombre);
                printf("    ____________________________________________________________________________\n\n");
                printf("\t¿Qué desea hacer con el?\n\t1.-Modificar\n\t2.-Eliminar\n\t3.-Salir\n");
                scanf("%i", &accion);
                if(accion==1){
                    modificar();
                }
                else if(accion ==2){
                    eliminar();
                }
                break;
            case 2:
                printf("\tEdad: %s\n", al[numDesencriptado].edad);
                printf("    ____________________________________________________________________________\n\n");
                printf("\t¿Qué desea hacer con el?\n\t1.-Modificar\n\t2.-Eliminar\n\t3.-Salir\n");
                scanf("%i", &accion);
                if(accion==1){
                    modificar();
                }
                else if(accion ==2){
                    eliminar();
                }
                break;
            case 3:
                printf("\tFecha de nacimiento: %s\n", al[numDesencriptado].fechaNacimiento);
                printf("    ____________________________________________________________________________\n\n");
                printf("\t¿Qué desea hacer con el?\n\t1.-Modificar\n\t2.-Eliminar\n\t3.-Salir\n");
                scanf("%i", &accion);
                if(accion==1){
                    modificar();
                }
                else if(accion ==2){
                    eliminar();
                }
                break;
            case 4:
                printf("\tDomicilio: %s\n", al[numDesencriptado].domicilio);
                printf("    ____________________________________________________________________________\n\n");
                printf("\t¿Qué desea hacer con el?\n\t1.-Modificar\n\t2.-Eliminar\n\t3.-Salir\n");
                scanf("%i", &accion);
                if(accion==1){
                    modificar();
                }
                else if(accion ==2){
                    eliminar();
                }
                break;
            case 5:
                printf("\tCiudad: %s\n", al[numDesencriptado].ciudad);
                printf("    ____________________________________________________________________________\n\n");
                printf("\t¿Qué desea hacer con el?\n\t1.-Modificar\n\t2.-Eliminar\n\t3.-Salir\n");
                scanf("%i", &accion);
                if(accion==1){
                    modificar();
                }
                else if(accion ==2){
                    eliminar();
                }
                break;
            case 6:
                printf("\tCódigo postal: %s\n", al[numDesencriptado].codigoPostal);
                printf("    ____________________________________________________________________________\n\n");
                printf("\t¿Qué desea hacer con el?\n\t1.-Modificar\n\t2.-Eliminar\n\t3.-Salir\n");
                scanf("%i", &accion);
                if(accion==1){
                    modificar();
                }
                else if(accion ==2){
                    eliminar();
                }
                break;
            case 7:
                printf("\tFraccionamiento: %s\n", al[numDesencriptado].fraccionamiento);
                printf("    ____________________________________________________________________________\n\n");
                printf("\t¿Qué desea hacer con el?\n\t1.-Modificar\n\t2.-Eliminar\n\t3.-Salir\n");
                scanf("%i", &accion);
                if(accion==1){
                    modificar();
                }
                else if(accion ==2){
                    eliminar();
                }
                break;
            case 8:
                printf("\tTeléfono: %s\n", al[numDesencriptado].telefono);
                printf("    ____________________________________________________________________________\n\n");
                printf("\t¿Qué desea hacer con el?\n\t1.-Modificar\n\t2.-Eliminar\n\t3.-Salir\n");
                scanf("%i", &accion);
                if(accion==1){
                    modificar();
                }
                else if(accion ==2){
                    eliminar();
                }
                break;
            case 9:
                printf("\tE-mail: %s\n", al[numDesencriptado].email);
                printf("    ____________________________________________________________________________\n\n");
                printf("\t¿Qué desea hacer con el?\n\t1.-Modificar\n\t2.-Eliminar\n\t3.-Salir\n");
                scanf("%i", &accion);
                if(accion==1){
                    modificar();
                }
                else if(accion ==2){
                    eliminar();
                }
                break;
            case 10:
                printf("\tNotas: %s\n", al[numDesencriptado].notas);
                printf("    ____________________________________________________________________________\n\n");
                printf("\t¿Qué desea hacer con el?\n\t1.-Modificar\n\t2.-Eliminar\n\t3.-Salir\n");
                scanf("%i", &accion);
                if(accion==1){
                    modificar();
                }
                else if(accion ==2){
                    eliminar();
                }
                break;
            case 11:
                printf("\tCódigo de alumno: %s\n", al[numDesencriptado].academic.codigo);
                printf("    ____________________________________________________________________________\n\n");
                printf("\t¿Qué desea hacer con el?\n\t1.-Modificar\n\t2.-Eliminar\n\t3.-Salir\n");
                scanf("%i", &accion);
                if(accion==1){
                    modificar();
                }
                else if(accion ==2){
                    eliminar();
                }
                break;
            case 12:
                printf("\tNúmero de seguro social: %s\n", al[numDesencriptado].academic.nss);
                printf("    ____________________________________________________________________________\n\n");
                printf("\t¿Qué desea hacer con el?\n\t1.-Modificar\n\t2.-Eliminar\n\t3.-Salir\n");
                scanf("%i", &accion);
                if(accion==1){
                    modificar();
                }
                else if(accion ==2){
                    eliminar();
                }
                break;
            case 13:
                printf("\tInstituto: %s\n", al[numDesencriptado].academic.instituto);
                printf("    ____________________________________________________________________________\n\n");
                printf("\t¿Qué desea hacer con el?\n\t1.-Modificar\n\t2.-Eliminar\n\t3.-Salir\n");
                scanf("%i", &accion);
                if(accion==1){
                    modificar();
                }
                else if(accion ==2){
                    eliminar();
                }
                break;
            case 14:
                printf("\tCarrera: %s\n", al[numDesencriptado].academic.carrera);
                printf("    ____________________________________________________________________________\n\n");
                printf("\t¿Qué desea hacer con el?\n\t1.-Modificar\n\t2.-Eliminar\n\t3.-Salir\n");
                scanf("%i", &accion);
                if(accion==1){
                    modificar();
                }
                else if(accion ==2){
                    eliminar();
                }
                break;
            case 15:
                printf("\tSemestre: %s\n", al[numDesencriptado].academic.semestre);
                printf("    ____________________________________________________________________________\n\n");
                printf("\t¿Qué desea hacer con el?\n\t1.-Modificar\n\t2.-Eliminar\n\t3.-Salir\n");
                scanf("%i", &accion);
                if(accion==1){
                    modificar();
                }
                else if(accion ==2){
                    eliminar();
                }
                break;
            case 16:
                printf("\tTurno: %s\n", al[numDesencriptado].academic.turno);
                printf("    ____________________________________________________________________________\n\n");
                printf("\t¿Qué desea hacer con el?\n\t1.-Modificar\n\t2.-Eliminar\n\t3.-Salir\n");
                scanf("%i", &accion);
                if(accion==1){
                    modificar();
                }
                else if(accion ==2){
                    eliminar();
                }
                break;
            case 17:
                printf("\tMateria: %s\n", al[numDesencriptado].academic.materia);
                printf("    ____________________________________________________________________________\n\n");
                printf("\t¿Qué desea hacer con el?\n\t1.-Modificar\n\t2.-Eliminar\n\t3.-Salir\n");
                scanf("%i", &accion);
                if(accion==1){
                    modificar();
                }
                else if(accion ==2){
                    eliminar();
                }
                break;
            case 18:
                printf("\tNrc: %s\n", al[numDesencriptado].academic.nrc);
                printf("    ____________________________________________________________________________\n\n");
                printf("\t¿Qué desea hacer con el?\n\t1.-Modificar\n\t2.-Eliminar\n\t3.-Salir\n");
                scanf("%i", &accion);
                if(accion==1){
                    modificar();
                }
                else if(accion ==2){
                    eliminar();
                }
                break;
            case 19:
                printf("\tSección: %s\n", al[numDesencriptado].academic.seccion);
                printf("    ____________________________________________________________________________\n\n");
                printf("\t¿Qué desea hacer con el?\n\t1.-Modificar\n\t2.-Eliminar\n\t3.-Salir\n");
                scanf("%i", &accion);
                if(accion==1){
                    modificar();
                }
                else if(accion ==2){
                    eliminar();
                }
                break;
            case 20:
                printf("\tMaestra: %s\n", al[numDesencriptado].academic.maestro);
                printf("    ____________________________________________________________________________\n\n");
                printf("\t¿Qué desea hacer con el?\n\t1.-Modificar\n\t2.-Eliminar\n\t3.-Salir\n");
                scanf("%i", &accion);
                if(accion==1){
                    modificar();
                }
                else if(accion ==2){
                    eliminar();
                }
                break;
            case 21:
                printf("\tPromedio: %s\n", al[numDesencriptado].academic.promedio);
                printf("    ____________________________________________________________________________\n\n");
                printf("\t¿Qué desea hacer con el?\n\t1.-Modificar\n\t2.-Eliminar\n\t3.-Salir\n");
                scanf("%i", &accion);
                if(accion==1){
                    modificar();
                }
                else if(accion ==2){
                    eliminar();
                }
                break;
            }
            marco();
            gotoxy(10,3);
            printf("\n\n\n\n\n\n\n\tPRESIONE ENTER PARA CONTINUAR\n");
            getch();
            system("cls");
        } else{
        	//mensaje de tolerancia a errores del ingreso del identificador unico de usuario
            system("cls");
            marco();
            gotoxy(20, 2);
            printf("\a         _nnnn_                      \n");
            gotoxy(20, 3);
            printf("        dGGGGMMb     ,.................................\n");
            gotoxy(20, 4);
            printf("       @p~qp~~qMb    | ¡Número de registro incorrecto! |\n");
            gotoxy(20, 5);
            printf("       M|@||@) M|   _,.................................'\n");
            gotoxy(20, 6);
            printf("       @,----.JM| -'\n");
            gotoxy(20, 7);
            printf("      JS^\\__/  qKL\n");
            gotoxy(20, 8);
            printf("     dZP        qKRb\n");
            gotoxy(20, 9);
            printf("    dZP          qKKb\n");
            gotoxy(20, 10);
            printf("   fZP            SMMb\n");
            gotoxy(20, 11);
            printf("   HZM            MMMM\n");
            gotoxy(20, 12);
            printf("   FqM            MMMM\n");
            gotoxy(20, 13);
            printf(" __| \ .        |\\dS\ qML\n");
            gotoxy(20, 14);
            printf(" |    `.`       | `\' \\Zq\n");
            gotoxy(20, 15);
            printf("_)      \\.___.,|     .\'\n");
            gotoxy(20, 16);
            printf("\\____   )MMMMMM|   .\'\n");
            gotoxy(20, 17);
            printf("     `-'       `--\' hjm\ \n");
            Sleep(1000);
        }
}
int modificar(){
	setlocale(LC_ALL, "spanish");
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    animacion();
    //desencriptacion del iterador 'i' para usarse posteriormente como identificador unico de indice en el arreglo de datos, (nos ayuda a acceder a datos especificos de cada usuario)
    //variables de encriptacion
    int clave1 = 0b10101010;
    int clave2 = 3;
    int numDesencriptado = (j>>clave2)^clave1;
    system("cls");
    marco();
    gotoxy(10, 2);
    printf("¡Bienvenido a modificar!\n");
    gotoxy(4, 3);
    printf("____________________________________________________________________________\n\n");
    //en caso de modificar, sobreescribir los datos bajo el mismo indice 
    switch(buscarVar){
        case 1:
            fflush(stdin);
            printf("\tIngrese un nuevo nombre:\n");
            gets(al[numDesencriptado].nombre);
            fflush(stdin);
            break;
        case 2:
            fflush(stdin);
            printf("\tIngrese una nueva edad:\n");
            gets(al[numDesencriptado].edad);
            fflush(stdin);
            break;
        case 3:
            fflush(stdin);
            printf("\tIngrese una nueva fecha de nacimiento:\n");
            gets(al[numDesencriptado].fechaNacimiento);
            fflush(stdin);
            break;
        case 4:
            fflush(stdin);
            printf("\tIngrese un nuevo domicilio:\n");
            gets(al[numDesencriptado].domicilio);
            fflush(stdin);
            break;
        case 5:
            fflush(stdin);
            printf("\tIngrese una nueva ciudad:\n");
            gets(al[numDesencriptado].ciudad);
            fflush(stdin);
            break;
        case 6:
            fflush(stdin);
            printf("\tIngrese un nuevo código postal:\n");
            gets(al[numDesencriptado].codigoPostal);
            fflush(stdin);
            break;
        case 7:
            fflush(stdin);
            printf("\tIngrese un nuevo fraccionamiento\n");
            gets(al[numDesencriptado].fraccionamiento);
            fflush(stdin);
            break;
        case 8:
            fflush(stdin);
            printf("\tIngrese un nuevo teléfono\n");
            gets(al[numDesencriptado].telefono);
            fflush(stdin);
            break;
        case 9:
            fflush(stdin);
            printf("\tIngrese un nuevo e-mail\n");
            gets(al[numDesencriptado].email);
            fflush(stdin);
            break;
        case 10:
            fflush(stdin);
            printf("\tIngrese nuevas notas\n");
            gets(al[numDesencriptado].notas);
            fflush(stdin);
            break;
        case 11:
            fflush(stdin);
            printf("\tIngrese un nuevo código de alumno\n");
            gets(al[numDesencriptado].academic.codigo);
            fflush(stdin);
            break;
        case 12:
            fflush(stdin);
            printf("\tIngrese un nuevo número de seguro social\n");
            gets(al[numDesencriptado].academic.nss);
            fflush(stdin);
            break;
        case 13:
            fflush(stdin);
            printf("\tIngrese un nuevo instituto\n");
            gets(al[numDesencriptado].academic.instituto);
            fflush(stdin);
            break;
        case 14:
            fflush(stdin);
            printf("\tIngrese una nueva carrera\n");
            gets(al[numDesencriptado].academic.carrera);
            fflush(stdin);
            break;
        case 15:
            fflush(stdin);
            printf("\tIngrese un nuevo semestre\n");
            gets(al[numDesencriptado].academic.semestre);
            fflush(stdin);
            break;
        case 16:
            fflush(stdin);
            printf("\tIngrese un nuevo turno\n");
            gets(al[numDesencriptado].academic.turno);
            fflush(stdin);
            break;
        case 17:
            fflush(stdin);
            printf("\tIngrese una nueva materia\n");
            gets(al[numDesencriptado].academic.materia);
            fflush(stdin);
            break;
        case 18:
            fflush(stdin);
            printf("\tIngrese un nuevo Nrc\n");
            gets(al[numDesencriptado].academic.nrc);
            fflush(stdin);
            break;
        case 19:
            fflush(stdin);
            printf("\tIngrese una nueva sección\n");
            gets(al[numDesencriptado].academic.seccion);
            fflush(stdin);
            break;
        case 20:
            fflush(stdin);
            printf("\tIngrese un nuevo maestro\n");
            gets(al[numDesencriptado].academic.maestro);
            fflush(stdin);
            break;
        case 21:
            fflush(stdin);
            printf("\tIngrese un nuevo promedio\n");
            gets(al[numDesencriptado].academic.promedio);
            fflush(stdin);
            break;
    }

    animacion();
}
int eliminar(){
    animacion();
    int n;
    //desencriptacion del iterador 'i' para usarse posteriormente como identificador unico de indice en el arreglo de datos, (nos ayuda a acceder a datos especificos de cada usuario)
    //variables de encriptacion
    int clave1 = 0b10101010;
    int clave2 = 3;
    int numDesencriptado = (j>>clave2)^clave1;
	//si se desea eliminar el dato se copea un arreglo "previamente declarado con un mensaje predeterminado" al arreglo deseado a eliminar mediante la funcion strcpy(arreglo a reemplazar, arreglo origen)
    switch(buscarVar){
        case 1:
            strcpy(al[numDesencriptado].nombre, mensaje_predeterminado);
            break;
        case 2:
            strcpy(al[numDesencriptado].edad, mensaje_predeterminado);
            break;
        case 3:
            strcpy(al[numDesencriptado].fechaNacimiento, mensaje_predeterminado);
            break;
        case 4:
            strcpy(al[numDesencriptado].domicilio, mensaje_predeterminado);
            break;
        case 5:
            strcpy(al[numDesencriptado].ciudad, mensaje_predeterminado);
            break;
        case 6:
            strcpy(al[numDesencriptado].codigoPostal, mensaje_predeterminado);
            break;
        case 7:
            strcpy(al[numDesencriptado].fraccionamiento, mensaje_predeterminado);
            break;
        case 8:
            strcpy(al[numDesencriptado].telefono, mensaje_predeterminado);
            break;
        case 9:
            strcpy(al[numDesencriptado].email, mensaje_predeterminado);
            break;
        case 10:
            strcpy(al[numDesencriptado].notas, mensaje_predeterminado);
            break;
        case 11:
            strcpy(al[numDesencriptado].academic.codigo, mensaje_predeterminado);
            break;
        case 12:
            strcpy(al[numDesencriptado].academic.nss, mensaje_predeterminado);
            break;
        case 13:
            strcpy(al[numDesencriptado].academic.instituto, mensaje_predeterminado);
            break;
        case 14:
            strcpy(al[numDesencriptado].academic.carrera, mensaje_predeterminado);
            break;
        case 15:
            strcpy(al[numDesencriptado].academic.semestre, mensaje_predeterminado);
            break;
        case 16:
           strcpy(al[numDesencriptado].academic.turno, mensaje_predeterminado);
            break;
        case 17:
            strcpy(al[numDesencriptado].academic.materia, mensaje_predeterminado);
            break;
        case 18:
            strcpy(al[numDesencriptado].academic.nrc, mensaje_predeterminado);
            break;
        case 19:
            strcpy(al[numDesencriptado].academic.seccion, mensaje_predeterminado);
            break;
        case 20:
            strcpy(al[numDesencriptado].academic.maestro, mensaje_predeterminado);
            break;
        case 21:
            strcpy(al[numDesencriptado].academic.promedio, mensaje_predeterminado);
            break;
    }
    animacion();
}
void animacion(){
	//funcion con fines esteticos, cargando sistema
    marco();
    batarang();
    gotoxy(10,3);
    printf("\t\t\t \aCargando sistema\n\n");
    gotoxy(10,5);
    printf("\t\t\t |...............\n\n");
    Sleep(100);
    system("cls");
    marco();
    batarang();
    gotoxy(10,3);
    printf("\t\t\t \aCargando sistema\n\n");
    gotoxy(10,5);
    printf("\t\t\t ||..............\n\n");
    Sleep(100);
    system("cls");
    marco();
    batarang();
    gotoxy(10,3);
    printf("\t\t\t \aCargando sistema\n\n");
    gotoxy(10,5);
    printf("\t\t\t |||.............\n\n");
    Sleep(100);
    system("cls");
    marco();
    batarang();
    gotoxy(10,3);
    printf("\t\t\t \aCargando sistema\n\n");
    gotoxy(10,5);
    printf("\t\t\t ||||............\n\n");
    Sleep(100);
    system("cls");
    marco();
    batarang();
    gotoxy(10,3);
    printf("\t\t\t \aCargando sistema\n\n");
    gotoxy(10,5);
    printf("\t\t\t |||||...........\n\n");
    Sleep(100);
    system("cls");
    marco();
    batarang();
    gotoxy(10,3);
    printf("\t\t\t \aCargando sistema\n\n");
    gotoxy(10,5);
    printf("\t\t\t ||||||..........\n\n");
    Sleep(100);
    system("cls");
    marco();
    batarang();
    gotoxy(10,3);
    printf("\t\t\t \aCargando sistema\n\n");
    gotoxy(10,5);
    printf("\t\t\t |||||||.........\n\n");
    Sleep(100);
    system("cls");
    marco();
    batarang();
    gotoxy(10,3);
    printf("\t\t\t \aCargando sistema\n\n");
    gotoxy(10,5);
    printf("\t\t\t ||||||||........\n\n");
    Sleep(100);
    system("cls");
    marco();
    batarang();
    gotoxy(10,3);
    printf("\t\t\t \aCargando sistema\n\n");
    gotoxy(10,5);
    printf("\t\t\t |||||||||.......\n\n");
    Sleep(100);
    system("cls");
    marco();
    batarang();
    gotoxy(10,3);
    printf("\t\t\t \aCargando sistema\n\n");
    gotoxy(10,5);
    printf("\t\t\t ||||||||||......\n\n");
    Sleep(100);
    system("cls");
    marco();
    batarang();
    gotoxy(10,3);
    printf("\t\t\t \aCargando sistema\n\n");
    gotoxy(10,5);
    printf("\t\t\t |||||||||||.....\n\n");
    Sleep(100);
    system("cls");
    marco();
    batarang();
    gotoxy(10,3);
    printf("\t\t\t \aCargando sistema\n\n");
    gotoxy(10,5);
    printf("\t\t\t ||||||||||||....\n\n");
    Sleep(100);
    system("cls");
    marco();
    batarang();
    gotoxy(10,3);
    printf("\t\t\t \aCargando sistema\n\n");
    gotoxy(10,5);
    printf("\t\t\t |||||||||||||...\n\n");
    Sleep(100);
    system("cls");
    marco();
    batarang();
    gotoxy(10,3);
    printf("\t\t\t \aCargando sistema\n\n");
    gotoxy(10,5);
    printf("\t\t\t ||||||||||||||..\n\n");
    Sleep(100);
    system("cls");
    marco();
    batarang();
    gotoxy(10,3);
    printf("\t\t\t \aCargando sistema\n\n");
    gotoxy(10,5);
    printf("\t\t\t |||||||||||||||.\n\n");
    Sleep(100);
    system("cls");
    marco();
    batarang();
    gotoxy(10,3);
    printf("\t\t\t \aCargando sistema\n\n");
    gotoxy(10,5);
    printf("\t\t\t ||||||||||||||||\n\n");
    Sleep(100);
    system("cls");
}
void estetico(){
	//funcion con fines esteticos "figura geometrica"
    system("cls");
    marco();
    gotoxy(10,3);
    printf("\n\n\n\n\n\n\t\t\t\t");
	printf("   ______");
	printf("\n\t\t\t\t");
	printf("  /\\_____\\");
	printf("\n\t\t\t\t");
	printf(" _\\ \\__/_/_ ");
	printf("\n\t\t\t\t");
	printf("/\\_\\ \\_____\\");
	printf("\n\t\t\t\t");
	printf("\\ \\ \\/ / / /");
	printf("\n\t\t\t\t");
	printf(" \\ \\/ /\\/ /");
	printf("\n\t\t\t\t");
	printf("  \\/_/\\/_/ ");
	gotoxy(30,15);
	printf("\n\n\t\t\t");
	printf("\aRegresando al menú principal");
	printf("\n\t\t\t\t");
	Sleep(600);
    system("cls");
    marco();
    gotoxy(10,3);
    printf("\n\n\n\n\n\n\t\t\t\t");
	printf(" ______");
	printf("\n\t\t\t\t");
	printf("/\\_____\\");
	printf("\n\t\t\t\t");
	printf("\\ \\__/_/_");
	printf("\n\t\t\t\t");
	printf("/\\ \\_____\\ ");
	printf("\n\t\t\t\t");
	printf("\\ \\/ / / /");
	printf("\n\t\t\t\t");
	printf(" \\/_/\\/ /");
	printf("\n\t\t\t\t");
	printf("    \\/_/");
	gotoxy(30,15);
	printf("\n\n\t\t\t");
	printf("\aRegresando al menú principal");
	printf("\n\t\t\t\t");
	Sleep(600);
    system("cls");
    marco();
    gotoxy(10,3);
    printf("\n\n\n\n\n\n\t\t\t\t");
	printf(" ______");
	printf("\n\t\t\t\t");
	printf("/\\_____\\");
	printf("\n\t\t\t\t");
	printf("\\ \\__/_/");
	printf("\n\t\t\t\t");
	printf("/\\ \\___\\ ");
	printf("\n\t\t\t\t");
	printf("\\ \\/ / /");
	printf("\n\t\t\t\t");
	printf(" \\/_/_/");
	gotoxy(30,15);
	printf("\n\n\t\t\t");
	printf("\aRegresando al menú principal");
	printf("\n\t\t\t\t");
	Sleep(600);
    system("cls");
    marco();
    gotoxy(10,3);
    printf("\n\n\n\n\n\n\t\t\t\t");
	printf("  ____");
	printf("\n\t\t\t\t");
	printf(" /\\___\\");
	printf("\n\t\t\t\t");
	printf("/\\ \\___\\");
	printf("\n\t\t\t\t");
	printf("\\ \\/ / /");
	printf("\n\t\t\t\t");
	printf(" \\/_/_/");
	gotoxy(30,15);
	printf("\n\n\t\t\t");
	printf("\aRegresando al menú principal");
	printf("\n\t\t\t\t");

	//reversa

    Sleep(600);
    system("cls");
    marco();
    gotoxy(10,3);
    printf("\n\n\n\n\n\n\t\t\t\t");
	printf(" ______");
	printf("\n\t\t\t\t");
	printf("/\\_____\\");
	printf("\n\t\t\t\t");
	printf("\\ \\__/_/");
	printf("\n\t\t\t\t");
	printf("/\\ \\___\\ ");
	printf("\n\t\t\t\t");
	printf("\\ \\/ / /");
	printf("\n\t\t\t\t");
	printf(" \\/_/_/");
	gotoxy(30,15);
	printf("\n\n\t\t\t");
	printf("\aRegresando al menú principal");
	printf("\n\t\t\t\t");

	Sleep(600);
    system("cls");
    marco();
    gotoxy(10,3);
    printf("\n\n\n\n\n\n\t\t\t\t");
	printf(" ______");
	printf("\n\t\t\t\t");
	printf("/\\_____\\");
	printf("\n\t\t\t\t");
	printf("\\ \\__/_/_");
	printf("\n\t\t\t\t");
	printf("/\\ \\_____\\ ");
	printf("\n\t\t\t\t");
	printf("\\ \\/ / / /");
	printf("\n\t\t\t\t");
	printf(" \\/_/\\/ /");
	printf("\n\t\t\t\t");
	printf("    \\/_/");
	gotoxy(30,15);
	printf("\n\n\t\t\t");
	printf("\aRegresando al menú principal");
	printf("\n\t\t\t\t");

    Sleep(600);
    system("cls");
    marco();
    gotoxy(10,3);
    printf("\n\n\n\n\n\n\t\t\t\t");
	printf("   ______");
	printf("\n\t\t\t\t");
	printf("  /\\_____\\");
	printf("\n\t\t\t\t");
	printf(" _\\ \\__/_/_ ");
	printf("\n\t\t\t\t");
	printf("/\\_\\ \\_____\\");
	printf("\n\t\t\t\t");
	printf("\\ \\ \\/ / / /");
	printf("\n\t\t\t\t");
	printf(" \\ \\/ /\\/ /");
	printf("\n\t\t\t\t");
	printf("  \\/_/\\/_/ ");
	gotoxy(30,15);
	printf("\n\n\t\t\t");
	printf("\aRegresando al menú principal");
	printf("\n\t\t\t\t");
	system("cls");
}
void aniSalida(){
	//funcion con fines esteticos "figura geometrica" para mensaje de salida o despedida
    system("cls");
    marco();
    gotoxy(10,3);
    printf("\n\n\n\n\n\n\t\t\t\t");
	printf("   ______");
	printf("\n\t\t\t\t");
	printf("  /\\_____\\");
	printf("\n\t\t\t\t");
	printf(" _\\ \\__/_/_ ");
	printf("\n\t\t\t\t");
	printf("/\\_\\ \\_____\\");
	printf("\n\t\t\t\t");
	printf("\\ \\ \\/ / / /");
	printf("\n\t\t\t\t");
	printf(" \\ \\/ /\\/ /");
	printf("\n\t\t\t\t");
	printf("  \\/_/\\/_/ ");
	gotoxy(30,15);
	printf("\n\n\t\t\t");
	printf("\aSaliendo del sistema");
	printf("\n\t\t\t\t");
	Sleep(600);
    system("cls");
    marco();
    gotoxy(10,3);
    printf("\n\n\n\n\n\n\t\t\t\t");
	printf(" ______");
	printf("\n\t\t\t\t");
	printf("/\\_____\\");
	printf("\n\t\t\t\t");
	printf("\\ \\__/_/_");
	printf("\n\t\t\t\t");
	printf("/\\ \\_____\\ ");
	printf("\n\t\t\t\t");
	printf("\\ \\/ / / /");
	printf("\n\t\t\t\t");
	printf(" \\/_/\\/ /");
	printf("\n\t\t\t\t");
	printf("    \\/_/");
	gotoxy(30,15);
	printf("\n\n\t\t\t");
	printf("\aSaliendo del sistema.");
	printf("\n\t\t\t\t");
	Sleep(600);
    system("cls");
    marco();
    gotoxy(10,3);
    printf("\n\n\n\n\n\n\t\t\t\t");
	printf(" ______");
	printf("\n\t\t\t\t");
	printf("/\\_____\\");
	printf("\n\t\t\t\t");
	printf("\\ \\__/_/");
	printf("\n\t\t\t\t");
	printf("/\\ \\___\\ ");
	printf("\n\t\t\t\t");
	printf("\\ \\/ / /");
	printf("\n\t\t\t\t");
	printf(" \\/_/_/");
	gotoxy(30,15);
	printf("\n\n\t\t\t");
	printf("\aSaliendo del sistema..");
	printf("\n\t\t\t\t");
	Sleep(600);
    system("cls");
    marco();
    gotoxy(10,3);
    printf("\n\n\n\n\n\n\t\t\t\t");
	printf("  ____");
	printf("\n\t\t\t\t");
	printf(" /\\___\\");
	printf("\n\t\t\t\t");
	printf("/\\ \\___\\");
	printf("\n\t\t\t\t");
	printf("\\ \\/ / /");
	printf("\n\t\t\t\t");
	printf(" \\/_/_/");
	gotoxy(30,15);
	printf("\n\n\t\t\t");
	printf("\aSaliendo del sistema...");
	printf("\n\t\t\t\t");

	//reversa

    Sleep(600);
    system("cls");
    marco();
    gotoxy(10,3);
    printf("\n\n\n\n\n\n\t\t\t\t");
	printf(" ______");
	printf("\n\t\t\t\t");
	printf("/\\_____\\");
	printf("\n\t\t\t\t");
	printf("\\ \\__/_/");
	printf("\n\t\t\t\t");
	printf("/\\ \\___\\ ");
	printf("\n\t\t\t\t");
	printf("\\ \\/ / /");
	printf("\n\t\t\t\t");
	printf(" \\/_/_/");
	gotoxy(30,15);
	printf("\n\n\t\t\t");
	printf("\aSaliendo del sistema..");
	printf("\n\t\t\t\t");

	Sleep(600);
    system("cls");
    marco();
    gotoxy(10,3);
    printf("\n\n\n\n\n\n\t\t\t\t");
	printf(" ______");
	printf("\n\t\t\t\t");
	printf("/\\_____\\");
	printf("\n\t\t\t\t");
	printf("\\ \\__/_/_");
	printf("\n\t\t\t\t");
	printf("/\\ \\_____\\ ");
	printf("\n\t\t\t\t");
	printf("\\ \\/ / / /");
	printf("\n\t\t\t\t");
	printf(" \\/_/\\/ /");
	printf("\n\t\t\t\t");
	printf("    \\/_/");
	gotoxy(30,15);
	printf("\n\n\t\t\t");
	printf("\aSaliendo del sistema.");
	printf("\n\t\t\t\t");

    Sleep(600);
    system("cls");
    marco();
    gotoxy(10,3);
    printf("\n\n\n\n\n\n\t\t\t\t");
	printf("   ______");
	printf("\n\t\t\t\t");
	printf("  /\\_____\\");
	printf("\n\t\t\t\t");
	printf(" _\\ \\__/_/_ ");
	printf("\n\t\t\t\t");
	printf("/\\_\\ \\_____\\");
	printf("\n\t\t\t\t");
	printf("\\ \\ \\/ / / /");
	printf("\n\t\t\t\t");
	printf(" \\ \\/ /\\/ /");
	printf("\n\t\t\t\t");
	printf("  \\/_/\\/_/ ");
	gotoxy(30,15);
	printf("\n\n\t\t\t");
	printf("\aSaliendo del sistema");
	printf("\n\t\t\t\t");
	system("cls");
}
void batarang(){
		//impresion en pantalla para fines esteticos
        gotoxy(4, 9);
        printf("  _____________________                              _____________________\n");
        gotoxy(4, 10);
        printf("  `-._:  .:'   `:::  .:\\           |\\__/|           /::  .:'   `:::  .:.-'");
        gotoxy(4, 11);
        printf("      \\      :          \\          |:   |          /         :       /    ");
        gotoxy(4, 12);
        printf("       \\     ::    .     `-_______/ ::   \\_______-'   .      ::   . /      ");
        gotoxy(4, 13);
        printf("        |  :   :: ::'  :   :: ::'  :   :: ::'      :: ::'  :   :: :|       ");
        gotoxy(4, 14);
        printf("        |     ;::         ;::         ;::         ;::         ;::  |       ");
        gotoxy(4, 15);
        printf("        |  .:'   `:::  .:'   `:::  .:'   `:::  .:'   `:::  .:'   `:|       ");
        gotoxy(4, 16);
        printf("        |  .:'   `:::  .:'   `:::  .:'   `:::  .:'   `:::  .:'   `:|       ");
        gotoxy(4, 17);
        printf("        /     :           :           :           :           :    \\       ");
        gotoxy(4, 18);
        printf("       /______::_____     ::    .     ::    .     ::   _____._::____\\      ");
        gotoxy(4, 19);
        printf("                      `----._:: ::'  :   :: ::'  _.----'                    ");
        gotoxy(4, 20);
        printf("                             `--.       ;::  .--'                           ");
        gotoxy(4, 21);
        printf("                                 `-. .:'  .-'                               ");
        gotoxy(4, 22);
        printf("                                    \\    /                             ");
        gotoxy(4, 23);
        printf("                                     \\  /");
        gotoxy(4, 24);
        printf("                                      \\/\n\n\t\t");
}

