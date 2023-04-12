#ifndef SCREEN_H
#define SCREEN_H

#include<ncurses.h>

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

#endif
