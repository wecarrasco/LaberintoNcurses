#include <ncurses.h>

int main()
{	
	initscr();							/* Start curses mode 		  */
	raw();								/* Line buffering disabled	*/
	keypad(stdscr, TRUE);				/* We get F1, F2 etc..		*/
	noecho();		
	printw("***MENU***");				/* Print Hello World		  */
	printw("1) Iniciar juego");
	printw("2) Salir");
	refresh();							/* Print it on to the real screen */
	int menu = getch();					/* Wait for user input */
	printw("%d",menu-48);
	getch();
	endwin();							/* End curses mode		  */


	return 0;
}