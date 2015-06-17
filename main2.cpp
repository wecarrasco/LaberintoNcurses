#include <ncurses.h>
#include <cstdlib>
#include <ctime>

using namespace std;

//funciones
char** crearMatriz(int);
void iniciarMatriz(char**, int);
void crearLaberinto();
void bordeLaberinto(char**, int);
void paredes(char**);
void imprimir(char**);
void borrar(char***);
void bomba();

int main(int argc, char const *argv[])
{
	initscr();															/*Iniciar Ncurses*/
	srand(time(0));														/*Iniciar Random*/

	char** tabla = NULL;												/*Matriz de Laberinto*/
	tabla = crearMatriz(15);
	iniciarMatriz(tabla, 15);
	bordeLaberinto(tabla, 15);
	paredes(tabla);

	start_color();														//Iniciar
	init_pair(1, COLOR_RED, COLOR_BLACK);										 //Modo
	attron(COLOR_PAIR(1));															   //Color


	mvprintw(10,30,"***MENU***\n");										//Menu		
	mvprintw(11,30,"1) Iniciar juego\n");
	mvprintw(12,30,"2) Salir\n");
	

	attroff(COLOR_PAIR(1));												//Apagar atributo de color
	
	clear();
	imprimir(tabla);

	refresh();
	char menu = getch();
	
	if (menu - 48 == 1)
	{
		while(true){
			char cursor = getch();
			if (cursor == 'A')
			{
				printw("arriba");
			}
			if (cursor == 'B')
			{
				printw("abajo");
			}
			if (cursor == 'C')
			{
				printw("derecha");
			}
			if (cursor == 'D')
			{
				printw("izquierda");
			}
			if(cursor == '['){
				printw("escape");
			}
		}
	}
	endwin();
	borrar(&tabla);
	return 0;
}



//Funciones
char** crearMatriz(int size){
	char** retVal=NULL;
	retVal=new char*[size];
	for(int i=0;i<size;i++){
		retVal[i]=new char[size];
	}
	return retVal;
}//fin crearMatriz

void iniciarMatriz(char** tabla, int size){
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			tabla[i][j] = ' ';
		}
	}
}//Fin iniciarMatriz

void bordeLaberinto(char** tabla, int size){
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == 0)
			{
				tabla[i][j] = '%';
			}
			if (i == 14)
			{
				tabla[i][j] = '%';
			}
			if (j == 14)
			{
				tabla [i][j] = '%';
			}
			if (j == 0)
			{
				tabla[i][j] = '%';
			}
		}
	}
	int entrada = 1 + rand()%14;
	int salida = 1 + rand()%14;

	tabla[entrada][0] = '*';
	tabla[salida][14] = ' ';
}//Fin de bordeLaberinto

void imprimir(char** tabla){
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			printw("[%c]",tabla[i][j]);
		}
		printw("\n");
	}
}//Fin de Imprimir

void borrar(char*** tabla){
	for (int i = 0; i < 15; i++){
		delete[] (*tabla)[i];
	}
	delete[] *tabla;
	*tabla=NULL;
}//fin delete_maze

void paredes(char** tabla){
	int contador = 1;
	while(contador < 50){
		int x = 2 + rand()%12;
		int y = 2 + rand()%12;
		//printw("x: %d, y: %d \n",x,y);
		tabla[x][y] = '%';
		contador++;
	}
}//Fin de paredes