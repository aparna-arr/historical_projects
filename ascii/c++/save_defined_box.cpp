#include<ncurses.h>
#include<cstring>
#include<stdlib.h> // for rand()
#include<unistd.h> // for usleep()
#include<vector>
#include<time.h> // for time()
using namespace std;
// building off save_move_1.cpp
class Thing 
{
  public:
  Thing() {
    x = y = maxx = maxy = delay = 1;
    pic = '@';
  }
  Thing(int h, int w, int d) {
    y = rand() % (h - 3) + 2 ;
    x = rand() % (w - 3) + 2 ;
    pic = '@';   
    maxx = w;
    maxy = h;
    delay = d;
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
    if ((rand() % 10 + 1) <= 5) {
      n--;
    }
    else {
      n++;
    } 
    return n;
  }

  bool checkpos(int check, int max) {
    if (check < max && check > 1) {
      return true;
    }
    else {
      return false;
    }
  }
  
  bool checkvector(vector<Thing> v) {
    vector<Thing>::iterator iter;
    for (iter = v.begin(); iter != v.end(); iter++) {
      if((*iter).getx() == x && (*iter).gety() == y) {
        return false;
      }
    }
    return true;
  }

  void updateMaxes(int h, int w) {
    maxy = h;
    maxx = w;
  }

  void setDelay(int d) {
    delay = d;
  }

  int getDelay() {
    return delay;
  }

  private:
  int maxx;
  int maxy;
  int x;
  int y;
  int pic;
  int delay;
};

class Screen {
  public:
  Screen () {
    int height, width;
    getmaxyx(stdscr, height, width);
    maxx = width;
    maxy = height;
    boxposx = 1;
    boxposy = 1;
    boxx = 34;
    boxy = 18;
  }
  Screen(int h, int w) {
    maxx = w;
    maxy = h;
    boxposx = 1;
    boxposy = 1;
    boxx = 34;
    boxy = 18;
  }
  Screen(int h, int w, int y, int x) {
    maxy = h;
    maxx = w;
    boxposy = y;
    boxposx = x;
    boxx = 34;
    boxy = 18;
  } 
  int getboxpos(char c) {
    if (c == 'y') {
      return boxposy;
    } 
    
    if (c == 'x') {
      return boxposx;
    }
    return 0;
  }

  int getmaxpos(char c) {
    if (c == 'y') {
      return maxy;
    } 
    
    if (c == 'x') {
      return maxx;
    }
  }
  
  int getboxlen(char c) {
    if (c == 'y') {
      return boxy;
    }

    if (c == 'x') {
      return boxx;
    }
    return 0;
  }

  private:
  int maxx;
  int maxy;
  int boxx;
  int boxy;
  int boxposx;
  int boxposy;
};

int main() 
{
  srand(time(NULL));

  initscr();
  noecho();
  nodelay(stdscr, TRUE);
  curs_set(FALSE);
 
  start_color();
  init_pair(1, COLOR_BLUE, COLOR_BLACK); 
  init_pair(2, COLOR_RED, COLOR_BLACK); 

  Screen mainscr;
  
  int boxymax = mainscr.getboxpos('y') + mainscr.getboxlen('y');
  int boxxmax = mainscr.getboxpos('x') + mainscr.getboxlen('x');

  vector<Thing> things;

  refresh();
  move(0, 0);
  addstr("   Press q to quit");

  for (int j = mainscr.getboxpos('x'); j < boxxmax; j++) {
    mvaddch(mainscr.getboxpos('y'), j, '#'|COLOR_PAIR(1));
    mvaddch(boxymax, j,'#'|COLOR_PAIR(1));
  }
  
  for (int i = mainscr.getboxpos('y'); i <= boxymax; i++) {
    mvaddch(i, mainscr.getboxpos('x'), '#'|COLOR_PAIR(1));
    mvaddch(i, boxxmax, '#'|COLOR_PAIR(1));
  }

  while(things.size() < 20) {
    Thing tmp(boxymax, boxxmax, rand() % 80 + 1);
    things.push_back(tmp);
    mvaddch(tmp.gety(), tmp.getx(), tmp.getpic()|COLOR_PAIR(2));
  }

  refresh();

  int ch;
  int loop = 0;
  while(1) 
  {
    ch = getch();
    if(ch == ERR) 
    {
      for (vector<Thing>::iterator it = things.begin(); it != things.end(); it++) {
        if (loop % (*it).getDelay() == 0) {
          int prevy, prevx;
          bool check;
          do {
            prevy = (*it).gety();
            prevx = (*it).getx();
            (*it).update();
            if (it != things.begin()) {
              vector<Thing> tmp(things.begin(), it);  
              check = (*it).checkvector(tmp);
            }
            else {
              check = true;
            }
          } while (!check);
          mvaddch(prevy, prevx, ' ');
          mvaddch((*it).gety(), (*it).getx(), (*it).getpic()|COLOR_PAIR(2));
        }  
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

