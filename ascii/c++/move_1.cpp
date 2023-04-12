#include<ncurses.h>
#include<cstring>
#include<stdlib.h> // for rand()
#include<unistd.h> // for usleep()
using namespace std;
// this all works
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
  noecho();
  nodelay(stdscr, TRUE);
  curs_set(FALSE);
  int height, width;
  getmaxyx(stdscr, height, width);

  
  Thing thing1(height, width), thing2(height, width);

  refresh();
  move(0, 0);
  addstr("   Press q to quit");
  mvaddch(thing1.gety(), thing1.getx(), thing1.getpic());
  refresh();

  int ch;
  int loop = 0;
  while(1) 
  {
    ch = getch();
    if(ch == ERR) 
    {
      if (loop % 20 == 0) {
        mvaddch(thing1.gety(), thing1.getx(), ' ');
        thing1.update();
        mvaddch(thing1.gety(), thing1.getx(), thing1.getpic());
      }
      if (loop % 50 == 0) {
        mvaddch(thing2.gety(), thing2.getx(), ' ');
        thing2.update();
        mvaddch(thing2.gety(), thing2.getx(), thing2.getpic());
      }
    }
    else 
    {
      mvaddch(0, 0, ch);
      if (ch == 'q') 
      {
        break;
      } 
    }
    refresh();
    loop++;
    usleep(30000);
  }

  endwin();
}

