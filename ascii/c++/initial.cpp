#include<ncurses.h>
#include<cstring>
using namespace std;
//http://hughm.cs.ukzn.ac.za/~murrellh/os/notes/ncurses.html
//http://www.linuxdoc.org/HOWTO/NCURSES-Programming-HOWTO/init.html#ABOUTINIT
// g++ -lncurses -Wall initial.cpp
int main () 
{
  initscr();
  cbreak();
  noecho();
//  nodelay(stdscr, TRUE);
  halfdelay(10); // SOLUTION to the framerate / crazy CPU problem

  int height, width;
  getmaxyx(stdscr, height, width); // for future reference

  WINDOW * win = newwin(height, width, 0, 0);

/*  char * str;

  str = new char[strlen("Press q to quit")+1];
  strcpy(str, "Press q to quit");
*/
  getch(); // needed or else waddstr doesn't do anything ... it refreshes the stdscr

  wmove(win, 0, 0);

//  waddstr(win, str);  
  waddstr(win, "Hello");  
  wmove(win, 1, 0);
  wrefresh(win); // whenever a change is made

  int ar[height][width];

  for (int i = 0; i < height; i++) 
  {
    for (int j = 0; j < width; j++) 
    {
      ar[i][j] = '-';
    }
  }

  int ch;
  while(1) {

    if ((ch = getch()) == ERR) {
//      waddch(win, '.');    
      for (int i = 0; i < height; i++) 
      {
        for (int j = 0; j < width; j++) 
        { 
          waddch(win, ar[i][j]);
        }
      }
      wmove(win,1,0); // moves cursor to 1,0 again
      wrefresh(win);
    }
    else {
      waddch(win, ch);
      wrefresh(win);
      if (ch == 'q') {
        break;
      }
    } 

  }

  endwin();
}
