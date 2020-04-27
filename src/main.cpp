#include <iostream>
#include <curses.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <fstream>
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
void saveFile(WINDOW *win);

using int32 = int;
int color = 0;
int x=0;
int y=0;
bool bruh = false;
int main()
{

  WINDOW *stdscr = initscr();
  noecho();
  cbreak();
  WINDOW *win = newwin(18,18,0,0);
  start_color();
  init_pair(0,COLOR_WHITE,COLOR_BLACK);
  init_pair(1, COLOR_YELLOW, COLOR_BLACK);
  init_pair(2, COLOR_BLUE, COLOR_BLACK);
  init_pair(3, COLOR_GREEN, COLOR_BLACK);
  init_pair(4, COLOR_RED, COLOR_BLACK);
  keypad(stdscr,true);
  if(has_colors()==FALSE){
    endwin();
    exit(1);
  }
    while(true){
      bruh = false;
      wattroff(win,COLOR_PAIR(color));
      int32 in = getch();
      switch (in) {
        case KEY_UP:
          y--;
          break;
        case KEY_DOWN:
          y++;
          break;
        case KEY_LEFT:
          x--;
          break;
        case KEY_RIGHT:
          x++;
          break;
        case '>':
        color++;
        if(color>4)color = 0;
        break;
        case '<':
          color--;
          if(color<0)color = 4;
          break;
        case '`':
          saveFile(win);
          break;
        default:
         bruh = true;
      }
      wattron(win,COLOR_PAIR(color));
      if(bruh)mvwaddch(win,y,x,in);
      box(win,0,0);
      wmove(win,0,0);
      waddch(win,(char)(color+48));
      wmove(win,y,x);
      refresh();
      wrefresh(win);
    }
    return 0;
}


void saveFile(WINDOW *win){
  string name;
  int coloro = 0;
  ofstream out;
  cout << "name file dood:";
  cin>>name;
  out.open(name);
  for(int i =0;i< 16;i++){
    for(int w =0;w<16;w++){
      char ch = mvwinch(win,i+1,w+1) & A_CHARTEXT;
      short coloring = winch(win) & A_COLOR;
      cout<<coloring<<'B';
    if(coloring!=COLOR_PAIR(coloro)){
        out<<'C';
        for(int z = 0;z<4;z++){
          if(COLOR_PAIR(z)==coloring){
            coloro = z;
            out<<(char)(coloro+48);
            break;
          }
        }
      }
      out<< ch;
    }
    out << "\n";
  }

}
