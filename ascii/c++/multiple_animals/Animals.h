#ifndef ANIMALS_H
#define ANIMALS_H

#include<stdlib.h>
#include<vector>
#include<ncurses.h>

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
  void setpic (char c) {
    pic = c;
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
  
  bool checkvector(std::vector<Thing*> v) {
    std::vector<Thing*>::iterator iter;
    for (iter = v.begin(); iter != v.end(); iter++) {
      if((*iter)->getx() == x && (*iter)->gety() == y) {
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

  virtual void print() {
    mvaddch(gety(), getx(), getpic());
  }

  protected:
  int maxx;
  int maxy;
  int x;
  int y;
  int pic;
  int delay;
};

class Predator : public Thing {
  public:
  Predator() : Thing() {
    setpic('%');
  }
  Predator(int h, int w, int d) : Thing(h,w,d) {
    setpic('%');
  }
  
  virtual void print () {
    mvaddch(gety(), getx(), getpic()|COLOR_PAIR(2));
  }
  private:
};

class Prey : public Thing {
  public:
  Prey() : Thing() {
    setpic('&');
  }
  Prey(int h, int w, int d) : Thing(h,w,d) {
    setpic('&');
  }
  virtual void print () {
    mvaddch(gety(), getx(), getpic()|COLOR_PAIR(3));
  }
  

  private:
};

#endif
