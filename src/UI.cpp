
#include "UI.h"
#include <curses.h>
#include <math.h>
#include <string>
#include <iostream>
#include <array>
/*
ACS_CKBOARD:1:(char)219
ACS_BOARD:.75:(char)178
'|':.50:(char)177
':':.25:(char)176
*/
void bar(WINDOW *win,int x,int y,int mx,int min,int max,float val){
  float unit = mx/(max-min);
  wmove(win,y,x);
  for(float i =unit;i<=val;i+=unit){
    if(i<=val){waddch(win, ACS_CKBOARD);}
  }
  double Bruh = fmod(val,unit)/unit;
  if(Bruh<=0.25 && Bruh != 0){waddch(win,':');}
  else if(Bruh<=0.5&& Bruh != 0){waddch(win,'|');}
  else if(Bruh<1&& Bruh != 0){waddch(win,ACS_BOARD);}

  for(float i = val+unit;i<max-min;i+=unit){
    if(i<val)waddch(win,' ');
  }
}


asciimg loadImg(std::ifstream& input){
  asciimg out;
  int color = 0;
  std::string line;
  int ct = 0;
  for(int ctlin =0;ctlin<16;ctlin++){
    ct =0;
    for(int i =0;i<line.length();i++){
      if(line.at(i)==COLORCHAR){
        i++;
        color = (int)line.at(i)-48;
      }
      else{
        out.img[ctlin][ct] = line.at(i);
        ct++;
      }
      out.colors[ctlin][ct] = color;
      if(ct>16)break;
    }
    ctlin++;
    if(ctlin>16)break;
  }
  return out;
}

void wprintmg(WINDOW *win,int x,int y,asciimg image){
  for(int i =0;i<sizeof(image.img);i++){
    for(int w= 0;w<sizeof(image.img[i]);w++){
      wattron(win,COLOR_PAIR(image.colors[i][w]));
      mvwaddch(win,i+y,w+x,image.img[i][w]);
      wattroff(win,COLOR_PAIR(image.colors[i][w]));
    }

  }

}
