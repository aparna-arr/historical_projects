#include<cstring>
#include<unistd.h> // for usleep()
#include<time.h> // for time()
#include<string>
#include "Screen.h"
#include "Animals.h"

using namespace std;

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
  init_pair(3, COLOR_GREEN, COLOR_BLACK);

  Screen mainscr;
  
  int boxymax = mainscr.getboxpos('y') + mainscr.getboxlen('y');
  int boxxmax = mainscr.getboxpos('x') + mainscr.getboxlen('x');

  vector<Thing*> things;
//  vector<Predator> predators;
//  vector<Prey> prey;

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

  while(things.size() < 10) {
    Predator pred(boxymax, boxxmax, rand() % 80 + 1);
    Prey prey1(boxymax, boxxmax, rand() % 80 + 1);
    Prey prey2(boxymax, boxxmax, rand() % 80 + 1);

//  predators.push_back(pred);
//  prey.push_back(prey1);
//  prey.push_back(prey2);
    things.push_back(&pred);
    things.push_back(&prey1);
    things.push_back(&prey2);

    pred.print();
    prey1.print();
    prey2.print();
//    mvaddch(pred.gety(), pred.getx(), pred.getpic()|COLOR_PAIR(2));
//    mvaddch(prey1.gety(), prey1.getx(), prey1.getpic()|COLOR_PAIR(2));
//    mvaddch(prey2.gety(), prey2.getx(), prey2.getpic()|COLOR_PAIR(2));
//    things.push_back(tmp);
//    mvaddch(tmp.gety(), tmp.getx(), tmp.getpic()|COLOR_PAIR(2));
  }

  refresh();

  int ch;
  int loop = 0;
  while(1) 
  {
    ch = getch();
    if(ch == ERR) 
    {
      for (vector<Thing*>::iterator it = things.begin(); it != things.end(); it++) {
        if (loop % (*it)->getDelay() == 0) {
          int prevy, prevx;
          bool check;
          do {
            prevy = (*it)->gety();
            prevx = (*it)->getx();
            (*it)->update();
            if (it != things.begin()) {
              vector<Thing*> tmp(things.begin(), it);  
              check = (*it)->checkvector(tmp);
            }
            else {
              check = true;
            }
          } while (!check);
          mvaddch(prevy, prevx, ' ');
//          mvaddch((*it).gety(), (*it).getx(), (*it).getpic()|COLOR_PAIR(2));
//          (*it)->print(); 
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

