#include "list.h"
#include <stdlib.h>
#include <stdio.h>

/* DataType Juego: Contain (int) min_players y (int) max_players, (char*)name, (char*)brand, (char*)kind_ofGame, y (char*)expansions*/
typedef struct
{
   int min_players;
   int max_players;
   char* name;
   char* brand; //marca
   char* kind_ofGame;
   char* expansions;
} Juego;

/* initialize a DataType Juego Variable*/
Juego create_Game(Juego input)
{
   input.name =(char*)calloc(105,sizeof(char));
   input.brand =(char*)calloc(105,sizeof(char));
   input.kind_ofGame =(char*)calloc(105,sizeof(char));
   input.expansions =(char*)calloc(105,sizeof(char));
   return (input);
}

/*Adds a Game into a List*/
void addGames(char* Name, char* Brand, char* Kind, int MinPlayers, int MaxPlayers, char* Expansions,List* Juegos)
{
   Juego newGame;
   newGame.name =(Name);
   newGame.brand =(Brand);
   newGame.kind_ofGame =(Kind);
   newGame.min_players =(MinPlayers);
   newGame.max_players =(MaxPlayers);
   newGame.expansions =(Expansions);
   push_back(Juegos,&newGame);
}


/*Search Functions*/


/*Receives a Brand and a GameList, Prints All the Games of that Brand, in case that there are no games made by that brand, Prints a "sorry, there are no games of that brand" style message*/
void search_byBrand(char* Brand,List* Juegos)
{
   int flag;
   flag =(-1);
   Juego* aux;
   create_Game(*aux);
   aux =(first(Juegos));
   while(aux!=NULL) 
   {
      if((strcmp(Brand,(aux->brand)))==0)
      {
         flag=(1);
         printf ("%-45s|%-30s|%-45s\t|%-2d~ %-2d jugadores |%s\n",(aux->name),(aux->brand),(aux->kind_ofGame),(aux->min_players),(aux->max_players),(aux->expansions));
      }
      aux =next(Juegos);
   }
   if (flag==(-1))
   {
      printf ("Pucha, no hay juegos de la marca %s  ༼ ༎ຶ ෴ ༎ຶ༽｡\n",Brand);
   }
   free(aux);
}

/*Receives a Kind of Game, and a GameList, Prints All the Games of that Kind, in case that there are no games of that Kind, Prints a "sorry, there are no games of that Kind" style message*/
void search_byKind(char* Kind,List* Juegos)
{
   int flag;
   flag =(-1);
   Juego* aux;
   aux =(first(Juegos));
   while(aux!=NULL) 
   {
      if((strcmp(Kind,(aux->kind_ofGame)))==0)
      {
         flag=(1);
         printf ("%-45s|%-30s|%-45s\t|%-2d~ %-2d jugadores |%s\n",(aux->name),(aux->brand),(aux->kind_ofGame),(aux->min_players),(aux->max_players),(aux->expansions));
      }
      aux =next(Juegos);
   }
   if (flag==(-1))
   {
      printf ("Pucha, no hay juegos del genero %s  ༼ ༎ຶ ෴ ༎ຶ༽｡\n",Kind);
   }
   free(aux);
}

/*Receives a Game Name, and a GameList, Prints All the Games that are called like this, in case that there are no games named like the input, Prints a "sorry, there are no games with that name" style message*/
void search_byName(char* Name,List* Juegos)
{
   int flag;
   flag =(-1);
   Juego* aux;
   aux =(first(Juegos));
   while(aux!=NULL) 
   {
      if((strcmp(Name,(aux->name)))==0)
      {
         flag=(1);
         printf ("%-45s|%-30s|%-45s\t|%-2d~ %-2d jugadores |%s\n",(aux->name),(aux->brand),(aux->kind_ofGame),(aux->min_players),(aux->max_players),(aux->expansions));
      }
      aux =next(Juegos);
   }
   if (flag==(-1))
   {
      printf ("Pucha, no hay ningun juego llamado %s  ༼ ༎ຶ ෴ ༎ຶ༽｡\n",Name);
   }
   free(aux);
}

/*Receives a "Number of Players", and a GameList, Prints All the Games that can be played with that amount of people, in case that there are no games for that amount, Prints a "sorry, there are no games for that amount of people" style message*/
void search_byRange(int CantJugadores,List* Juegos)
{   
   int flag;
   flag =(-1);
   Juego* aux;
   create_Game(*aux);
   aux =(first(Juegos));
   while(aux!=NULL) 
   {
      if((CantJugadores >= (aux->min_players)) && (CantJugadores <=(aux->max_players)))
      {
         flag=(1);
         printf ("%-45s|%-30s|%-45s\t|%-2d~ %-2d jugadores |%s\n",(aux->name),(aux->brand),(aux->kind_ofGame),(aux->min_players),(aux->max_players),(aux->expansions));
      }
      aux =next(Juegos);
   }
   if (flag==(-1))
   {
      printf ("Pucha, no hay juegos para %i jugadores ༼ ༎ຶ ෴ ༎ຶ༽｡\n",CantJugadores);
   }
   free(aux);
}

/*Receives a "Kind of Game", an amount of players, and the GameList, Prints all the games that fill the requirements. In case that there are no games that fill the requirements, Prints a "Sorry there are no games that fill your requirements" Style Message*/
void advanced_Search(char* Kind,int CantJugadores,List* Juegos)
{
   int flag;
   flag =(-1);
   Juego* aux;
   aux =(first(Juegos));
   while(aux!=NULL) 
   {
      if(((strcmp(Kind,(aux->kind_ofGame)))==0)&&((CantJugadores >= (aux->min_players)) && (CantJugadores <=(aux->max_players))))
      {
         flag=(1);
         printf ("%-45s|%-30s|%-45s\t|%-2d~ %-2d jugadores |%s\n",(aux->name),(aux->brand),(aux->kind_ofGame),(aux->min_players),(aux->max_players),(aux->expansions));
      }
      aux =next(Juegos);
   }
   if (flag==(-1))
   {
      printf ("Pucha, no hay juegos que cumplan con tus requisitos ༼ ༎ຶ ෴ ༎ຶ༽｡\n");
   }
   free(aux);
}


/*File Functions*/


/*Export Function, Creates A File (.csv) With the Specified Name, and Writes The GameList onto this File*/
void exportGames(char* name,List* Juegos)
{
   FILE* output;
   char fileName[105];
   snprintf(fileName,sizeof(fileName),"%s%s",name,".csv");
   output =fopen(fileName,"w");
   Juego* aux;
   aux =(first(Juegos));
   char cadena[105];
   while(aux!=NULL) 
   {
      snprintf(cadena,sizeof(cadena),"\"%s\",%s,\"%s\",%d,%d,%s\n",aux->name,aux->brand,aux->kind_ofGame,aux->min_players,aux->max_players,aux->expansions);
      fputs(cadena,output);
      aux =next(Juegos);
   }
   fclose(output);
   free(output);
   free(aux);
}

/*Import Function, Reads a GameList From a (.csv) File, and writes it into a List*/
void importGames(char* name,List* Juegos)
{
   FILE* input;
   char fileName[105];
   snprintf(fileName,sizeof(fileName),"%s%s",name,".csv");
   input =fopen(fileName,"r");
   char line[105];
   Juego* datos;
   while(fgets(line, 104,input) != NULL) 
   {
      datos =((Juego*)calloc(1,sizeof(Juego)));
      datos[0] =(create_Game(datos[0]));    
      datos->name =((char*)get_csv_field(line,0));
      datos->brand =((char*)get_csv_field(line,1));
      strcpy((datos->kind_ofGame),((char*)get_csv_field(line,2)));
      datos->min_players =(atol(get_csv_field(line,3)));
      datos->max_players =(atol(get_csv_field(line,4)));
      strcpy((datos->expansions),((char*)get_csv_field(line,5)));
      push_back(Juegos,datos);
   }
   fclose(input);
   free(input);
   free(datos);
}


/*Print Functions*/


/*Prints All The Games In The List*/
void print_All(List* Juegos)
{
   Juego* aux;
   aux =(first(Juegos));
   char cadena[105];
   while(aux!=NULL) 
   {
      printf("%-45s|%-30s|%-45s\t|%-2d~ %-2d jugadores |%s\n",aux->name,aux->brand,aux->kind_ofGame,aux->min_players,aux->max_players,aux->expansions);
      aux =next(Juegos);
   }
   free(aux);
}

/*Prints All The Expansions In the GameList*/
void print_Expansions(List* Juegos)
{
   int flag;
   flag =(-1);
   Juego* aux;
   create_Game(*aux);
   aux =(first(Juegos));
   while(aux!=NULL) 
   {
      if((strcmp("extension",(aux->kind_ofGame)))==0)
      {
         flag=(1);
         printf ("%-45s|%-30s|%-45s\t|%-2d~ %-2d jugadores |%s\n",(aux->name),(aux->brand),(aux->kind_ofGame),(aux->min_players),(aux->max_players),(aux->expansions));
      }
      aux =next(Juegos);
   }
   //printf("%s",Expansion);
   if (flag==(-1))
   {
      printf ("Pucha, no tienes expansiones para tus juegos ༼ ༎ຶ ෴ ༎ຶ༽｡\n");
   }
   free(aux);
}