#include <ncurses.h>
#include <cstdlib>
#include <ctime>

using namespace std;

//funciones
char** crearMatriz(int);
void iniciarMatriz(char**, int);
void crearLaberinto();
void bordeLaberinto(char**, int, int, int);
void paredes(char**);
void imprimir(char**);
void borrar(char***);
void objeto(char**);

int main(int argc, char const *argv[])
{
	initscr();															/*Iniciar Ncurses*/
	srand(time(0));														/*Iniciar Random*/

	char** tabla = NULL;												/*Matriz de Laberinto*/
	tabla = crearMatriz(15);
	iniciarMatriz(tabla, 15);
	int entrada = 1 + rand()%14;
	int salida = 1 + rand()%14;
	bordeLaberinto(tabla, 15, entrada, salida);
	paredes(tabla);
	objeto(tabla);

	start_color();														//Iniciar
	init_pair(1, COLOR_RED, COLOR_BLACK);										 //Modo
	attron(COLOR_PAIR(1));															   //Color


	mvprintw(10,30,"******MENU******\n");										//Menu		
	mvprintw(11,30,"1) Iniciar juego\n");
	mvprintw(12,30,"2) Salir\n");
	

	attroff(COLOR_PAIR(1));												//Apagar atributo de color
	
	int objetos = 0;

	refresh();
	char menu = getch();

	clear();
	imprimir(tabla);
	
	if (menu - 48 == 1)
	{
		int x, y;
		while(true){
			char cursor = getch();

			if (cursor == 'A')
			{
				//printw("arriba");

				for (int i = 0; i < 15; i++)
				{
					for (int j = 0; j < 15; j++)
					{
						if (tabla[i][j] == '*')
						{
							x = i;
							y = j;
						}
					}
				}
				if (tabla[x-1][y] == '%')
				{
					tabla[x][y] = '*';
					tabla[x-1][y] = '%';
				}else if(tabla[x-1][y] == '?'){
					objetos++;
					tabla[x][y] = ' ';
					tabla[x-1][y] = '*';
				}else if( (tabla[x][15] == '*')  &&  (objetos == 4) ){
					clear();
					attron(COLOR_PAIR(1));
					printw("GANADOR");
					attroff(COLOR_PAIR(1));
					getch();
					break;
				}else{
					tabla[x][y] = ' ';
					tabla[x-1][y] = '*';
				}

			}
			if (cursor == 'B'){
				//printw("abajo");

				for (int i = 0; i < 15; i++)
				{
					for (int j = 0; j < 15; j++)
					{
						if (tabla[i][j] == '*')
						{
							addch('h');
							x = i;
							y = j;
						}
					}
				}
				if (tabla[x+1][y] == '%')
				{
					tabla[x][y] = '*';
					tabla[x+1][y] = '%';
				}else if(tabla[x+1][y] == '?'){
					objetos++;
					tabla[x][y] = ' ';
					tabla[x+1][y] = '*';
				}else if( (tabla[x][15] == '*') &&  (objetos == 4) ){
					clear();
					attron(COLOR_PAIR(1));
					printw("GANADOR");
					attroff(COLOR_PAIR(1));
					getch();
					break;
				}else{
					tabla[x][y] = ' ';
					tabla[x+1][y] = '*';
				}

			}

			if (cursor == 'C')
			{
				//printw("derecha");

				for (int i = 0; i < 15; i++)
				{
					for (int j = 0; j < 15; j++)
					{
						if (tabla[i][j] == '*')
						{
							x = i;
							y = j;
						}
					}
				}
				if (tabla[x][y+1] == '%')
				{
					tabla[x][y] = '*';
					tabla[x][y+1] = '%';
				}else if(tabla[x][y+1] == '?'){
					objetos++;
					tabla[x][y] = ' ';
					tabla[x][y+1] = '*';
				}else if( (tabla[x][15] == '*') &&  (objetos == 4) ){
					clear();
					attron(COLOR_PAIR(1));
					printw("GANADOR");
					attroff(COLOR_PAIR(1));
					getch();
					break;
				}else{
					tabla[x][y] = ' ';
					tabla[x][y+1] = '*';
				}

			}
			if (cursor == 'D')
			{
				for (int i = 0; i < 15; i++)
				{
					for (int j = 0; j < 15; j++)
					{
						if (tabla[i][j] == '*')
						{
							x = i;
							y = j;
						}
					}
				}
				if (tabla[x][y-1] == '%')
				{
					tabla[x][y] = '*';
					tabla[x][y-1] = '%';
				}else if(tabla[x][y-1] == '?'){
					objetos++;
					tabla[x][y] = ' ';
					tabla[x][y-1] = '*';
				}else if( (tabla[x][15] == '*') &&  (objetos == 4) ){
					clear();
					attron(COLOR_PAIR(1));
					printw("GANADOR");
					attroff(COLOR_PAIR(1));
					getch();
					break;
				}else{
					tabla[x][y] = ' ';
					tabla[x][y-1] = '*';
				}

				//printw("izquierda");
			}
			if (cursor == 'x')
			{
				break;
			}
			clear();
			imprimir(tabla);
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

void bordeLaberinto(char** tabla, int size, int entrada, int salida){
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


	tabla[entrada][0] = '*';
	tabla[salida][14] = ' ';
}//Fin de bordeLaberinto

void imprimir(char** tabla){
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (tabla[i][j] == '%')
			{
				printw("[%c]",tabla[i][j]);
			}else{
				printw(" %c ",tabla[i][j]);
			}
			
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

void objeto(char** tabla){	
	int a = 0;
	while (a < 4){
		int x = 2 + rand()%12;
		int y = 2 + rand()%12;
		if (tabla[x][y] == ' ')
		{
			tabla[x][y] = '?';
			a++;
		}
	}
}