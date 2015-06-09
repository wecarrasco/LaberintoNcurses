#include <ncurses.h>
#include <cstdlib>
#include <ctime>

//Funciones
void printTable();

int main()
{	
	initscr();							/* Start curses mode 		  */
	srand(time(0));
	raw();								/* Line buffering disabled	*/
	keypad(stdscr, TRUE);				/* We get F1, F2 etc..		*/
	noecho();		
	printw("***MENU***\n");				/* Print Hello World		  */
	printw("1) Iniciar juego\n");
	printw("2) Salir\n");
	refresh();							/* Print it on to the real screen */
	char menu = getch();
	if (menu - 48 == 1)
	{
		printTable();
	}
/*	char ch = getch();					//Wait for user input 
	addch(ch | A_BOLD | A_UNDERLINE);
	refresh();*/
	//printw("%d",ch);
	getch();
	endwin();							/* End curses mode		  */
	return 0;
}

/*bool start(){

}*/

void printTable(){
	initscr();
	srand(time(0));
	printw("\n\n");
	char tabla [15][15];

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			tabla[i][j] = ' ';
		}
	}

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
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

	tabla[entrada][0] = ' ';
	tabla[salida][14] = ' ';

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			printw("[%c]",tabla[i][j]);
		}
		printw("\n");
	}

	refresh();
}