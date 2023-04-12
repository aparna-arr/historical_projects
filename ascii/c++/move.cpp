#include<ncurses.h>
#include<cstring>
#include<stdlib.h> // for rand()
#include<unistd.h> // for usleep()
using namespace std;

class Thing 
{
  public:
  Thing(int h, int w) {
    y = rand() % h + 1;
    x = rand() % w + 1;
    pic = '@';   
    maxx = w;
    maxy = h;
  }
  void setx (int i) {
    x = i;
  }
  void sety (int i) {
    y = i;
  }

  int getx() {
    return x;
  }
  int gety() {
    return y;
  }

  int getpic() {
    return pic;
  }

  void update() {
    int i = randpos(x);
    int j = randpos(y);

    if (checkpos(i, maxx)) {
      x = i;
    }

    if (checkpos(j, maxy)) {
      y = j;
    }
  }

  int randpos(int n) {
    if (rand() % 10 + 1 < 5) {
      n++;
    }
    else {
      n--;
    } 
    return n;
  }

  bool checkpos(int check, int max) {
    if (check <= max && check > 0) {
      return true;
    }
    else {
      return false;
    }
  }

  private:
  int maxx;
  int maxy;
  int x;
  int y;
  int pic;
};

int main() 
{
  initscr();
  cbreak();
  noecho();
//  halfdelay(10);
//  timeout(1000);
  nodelay(stdscr, TRUE);

  int height, width;
  getmaxyx(stdscr, height, width);

  WINDOW * win = newwin(height, width, 0, 0);
  
  Thing thing1(height, width), thing2(height, width);

  getch();
  wmove(win, 0, 0);
  waddstr(win, "   Press q to quit");
  mvwaddch(win, thing1.gety(), thing1.getx(), thing1.getpic());
  wrefresh(win);

  int ch;

  while(1) 
  {
    if((ch = getch()) == ERR) 
    {
      mvwaddch(win, thing1.gety(), thing1.getx(), ' ');
      thing1.update();
      mvwaddch(win, thing1.gety(), thing1.getx(), thing1.getpic());

      mvwaddch(win, thing2.gety(), thing2.getx(), ' ');
      thing2.update();
      mvwaddch(win, thing2.gety(), thing2.getx(), thing2.getpic());

      wrefresh(win);
      usleep(10000);
    }
    else 
    {
      mvwaddch(win, 0, 0, ch);
      wrefresh(win);
      if (ch == 'q') 
      {
        break;
      } 
    }
  }

  endwin();
}

