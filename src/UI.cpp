
#include "UI.h"
#include <curses.h>
#include <math.h>
#include <string>
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
  while(getline(input,line)){
    for(int i =0;i<line.length();i++){
      if(ct%16)break;
      if(line.at(i)==COLORCHAR){
        color = (int)line.at(i)-48;
        i++;
      }
      else{
        out.img[ct/16][ct%16] = line.at(i);
      }
      out.colors[ct/16][ct%16] = color;
      ct++;
    }
  }
  return out;
}
