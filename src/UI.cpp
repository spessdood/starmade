
#include "UI.h"
#include <curses.h>
#include <math.h>
#define COLORCHAR 'C'
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
