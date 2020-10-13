#include <stdio.h>
int menu (List* Juegos)
{
    char option;
    printf("Bienvenid@ a tu ludoteca! OwO\nQue te gustaria hacer hoy?(\'w\')\na)Importar juegos\nb)Exportar juegos\nc)Agregar juego\nd)Buscar juegos para 'x' cantidad de jugadores\ne)Buscar juegos de 'x' marca\nf)Buscar un juego\ng)Buscar juego por tipo\nh)Busqueda Avanzada\ni)Mostrar todos los juegos\nj)Mostrar expansiones\nSi no quieres nada, solo presiona la tecla enter uwu\n");
    scanf("%c",&option);
    switch (option)
    {
        case 'a':
        {
            char* file;
            file =((char*)calloc(105,sizeof(char)));
            printf("Ingresa el nombre del archivo a importar! OwO (nombre sin el formato) uwu \n");
            scanf("%s",file);
            importGames(file,Juegos);
            break;
        }
        case 'b':
        {
            char* name;
            name =((char*)calloc(105,sizeof(char)));
            printf("Ingrese el nombre que desea que tenga el archivo a exportar! (nombre sin el formato) uwu \n");
            scanf("%s",name);
            exportGames(name,Juegos);
            printf("Se exportaron los Juegos al archivo %s.csv\n",name);
            break;
        }
        case 'c':
        {
            char* name;
            name =((char*)calloc(105,sizeof(char)));
            char* brand;
            brand =((char*)calloc(105,sizeof(char)));
            char* kind;
            kind =((char*)calloc(105,sizeof(char)));
            int min;
            int max;
            char* expansion;
            expansion =((char*)calloc(105,sizeof(char)));
            printf("Ingresa el nombre (si contiene comas,añade comillas al principio y al final de la manera \"nombre,juego,con,comas\" porfavor)");
            scanf("%s",name);
            printf("Ingresa La Marca");
            scanf("%s",brand);
            printf("Ingresa El tipo de Juego");
            scanf("%s",kind);
            printf("Ingresa el numero minimo de Jugadores");
            scanf("%d",&min);
            printf("Ingresa el numero maximo de Jugadores");
            scanf("%d",&max);
            printf("Ingresa el juego base en caso de ser una expansion, si no lo es, escribe \"No aplica\" (sin las comillas)");
            scanf("%s",expansion);
            addGames(name,brand,kind,min,max,expansion,Juegos);
            break;
        }
        case 'd':
        {
            int range;
            printf("ingrese la cantidad de jugadores!\n");
            scanf("%d",&range);
            search_byRange(range,Juegos);
            break;
        }
        case 'e':
        {
            char* brand =((char*)calloc(100,sizeof(char)));
            printf("ingrese la marca a filtrar!\n");
            scanf("%s",brand);
            search_byBrand(brand,Juegos);
            break;
        }
        case 'f':
        {
            char* name =((char*)calloc(100,sizeof(char)));
            printf("ingrese el nombre a filtrar!\n");
            scanf("%s",name);
            search_byName(name,Juegos);
            break;
        }
        case 'g':
        {
            char* kind =((char*)calloc(100,sizeof(char)));
            printf("Escriba el tipo de juego a buscar! =o=\n");
            scanf("%s",kind);
            search_byKind(kind,Juegos);
            break;
        }
        case 'h':
        {
            char* kind =((char*)calloc(100,sizeof(char)));
            int range;
            printf("Escriba el tipo de juego a buscar! =o=\n");
            scanf("%s",kind);
            printf("Escriba el numero de jugadores! (=w=)7\n");
            scanf("%d",&range);
            advanced_Search(kind,range,Juegos);
            break;
        }
        case 'i':
        {
            print_All(Juegos);
            break;
        }
        case 'j':
        {
            print_Expansions(Juegos);
            break;
        }
        default:
            printf("Chau! (=w=)/\n");
            break;
        }
    return(0);
}