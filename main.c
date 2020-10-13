#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "lectura_csv.c"
#include "Game.c"
#include "menu.c"

int main()
{
    List* Juegos;
    Juegos =create_list();
    FILE* games =(fopen("50 Juegos.csv","r"));
    Juego* datos;
    char line[105];
    while(fgets(line, 104,games) != NULL) 
    {
        datos =((Juego*)calloc(1,sizeof(Juego)));
        *datos =(create_Game(*datos));    
        datos->name =((char*)get_csv_field(line,0));
        datos->brand =((char*)get_csv_field(line,1));
        strcpy((datos->kind_ofGame),((char*)get_csv_field(line,2)));
        datos->min_players =(atol(get_csv_field(line,3)));
        datos->max_players =(atol(get_csv_field(line,4)));
        strcpy((datos->expansions),((char*)get_csv_field(line,5)));
        push_back(Juegos,datos);
    }
    fclose(games);
    free(games);
    datos =NULL;
    free(datos);
    menu(Juegos);
    free(Juegos);
    return 0;
}
//gcc -g main.c list.c -o tarea1-20551842 linea compilar