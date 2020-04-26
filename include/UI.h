
#ifndef UI_H
#define UI_H
#include <curses.h>
#include <iostream>
#include <fstream>

#define COLORCHAR 'C'
void bar(WINDOW *win,int x,int y,int mx,int max,int min,float val);

struct asciimg{
  short colors[16][16];
  char img[16][16];
};

  asciimg loadImg(std::ifstream&);

void wprintmg(WINDOW *win,int x,int y,asciimg img);

#endif /*UI_H8*/
