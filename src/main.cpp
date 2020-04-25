#include "UI.h"
#include <iostream>
#include <curses.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
/*          __,__
   .--.  .-"     "-.  .--.
  / .. \/  .-. .-.  \/ .. \
 | |  '|  /   Y   \  |'  | |
 | \   \  \ 0 | 0 /  /   / |
  \ '- ,\.-"`` ``"-./, -' /
   `'-' /_   ^ ^   _\ '-'`
       |  \._   _./  | moneky seal of quality
       \   \ `~` /   /
        '._ '-=-' _.'
           '~---~'
*/


using int32 = int;
int angle;
float x,y,speed;
string cheese;
int main()
{
    angle = 0;
    speed = 0;
    x=7;
    y=7;
    WINDOW *scr = initscr();
    WINDOW *flightwin = newwin(32,64,0,0);
    WINDOW *navwin = newwin(16,16,16,65);
    wbkgdset(navwin,ACS_PLUS );
    keypad(scr, TRUE);
    cbreak();
    noecho();
    while (true){
      int32 in = getch();
      wclear(flightwin);
      wclear(navwin);
      clear();
      switch(in){
        case KEY_LEFT:
          angle+=20;
          break;
        case KEY_RIGHT:
          angle-=20;
          break;
        case KEY_DOWN:
          speed-=0.25;
          break;
        case KEY_UP:
          speed+=0.25;
          break;
        default :
          break;

      }
      wbkgdset(navwin,ACS_PLUS );
      wbkgd(navwin,ACS_PLUS );
      mvwaddch(navwin,y/32+1,x/32+1,'O');
      box(flightwin,0,0);
      box(navwin,0,0);
      wmove(flightwin,16,32);
      waddch(flightwin,'X');
      wmove(flightwin,sin(angle/57.32)*5+16,cos(angle/57.32)*5+32);
      waddch(flightwin,'+');
      move(4,70);
      printw("angel: %d",round(speed));
      move(5,70);
      printw("sped:[");
      bar(scr,76,5,10,0,5,speed);
      mvaddch(5,81,']');
      move(6,70);
      printw("EX: %d",round(x));
      move(7,70);
      printw("WHY: %d",round(y));
      refresh();
      wrefresh(flightwin);
      wrefresh(navwin);
      x+= cos(angle/57.32)*speed;
      y+= sin(angle/57.32)*speed;
      if(x<1){x=1;}
      if(x>447){x=447;}
      if(y<1){y=1;}
      if(y>447){y=447;}
      }
    return 0;
}
