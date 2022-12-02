#include <curses.h>
#include <string>
#include <vector>

using namespace std;

string opcion1(){
	//string s = "";
	//for(int i = 0; i < 100; i++){s += "s\n";}
	//return s;
	return "Danfo";
}
string opcion2(){
	return "Tec";
}

int main(){
  //Inicializar la pantalla
  initscr();
  //Habiltar input de todo el teclado
  keypad(stdscr, TRUE);
  //Desabilitamos el echo automatico
  noecho();
  //Habilitamos la obtencion inmediata de chars
  cbreak();
  //Hacemos la pantalla scrollable
  scrollok(stdscr, TRUE);
  //Obtenemos el tamaño de la pantalla
  int rows,cols;
  getmaxyx(stdscr,rows,cols);

  //vector<string> msgs = {"Este es el primer ejemplo de ncurses compilado con CMake", "Hola."};
  vector<string> msgs = {"Menu de opciones: ", "", "1. Printear nombre", "2. Printear host", "c. Salir", "", ""};
  for(int i = 0; i < msgs.size(); i++){
  	mvprintw((rows/2) + i, (cols-10)/2, msgs[i].c_str());
  }
  bool listening = TRUE; 
  while(listening){
	int c = getch();
	move((rows/2) + msgs.size() - 1, 0);
	clrtoeol(); 
	msgs[msgs.size()-1] = "> ";

	switch(c){
 		case 49:
			msgs[msgs.size()-1] += opcion1();
 			break;
		case 50:
			msgs[msgs.size()-1] += opcion2();
 			break;
		case 99:
			listening = FALSE;
 			break;	
 	}
	for(int i = 0; i < msgs.size(); i++){
  		mvprintw((rows/2) + i, (cols-10)/2, msgs[i].c_str());
  	}
  }
  //\n\nY como se puede ver, se puede plotear en toda la pantalla de manera efectiva."
  refresh();

  endwin();
  return 0;
}
