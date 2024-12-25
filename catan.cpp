#include <ncurses.h>
#include <unistd.h>
#include "catan.h"

Catan::Catan(int np) : num_players(np) { }

void Catan::startHex(int start_x, int start_y) {
  move(start_x, start_y);
  printw("\\E______E/");
  move(start_x + 1, start_y);
  printw("/        \\");
  move(start_x + 2, start_y - 1);
  printw("/          \\");
  move(start_x + 3, start_y - 3);
  printw("E/            \\E");
  move(start_x + 4, start_y - 2);
  printw("\\            /");
  move(start_x + 5, start_y - 1);
  printw("\\          /");
  move(start_x + 6, start_y);
  printw("\\E______E/");
} // startHex()

void Catan::printMap(int start_x, int start_y) {
  startHex(start_x, start_y);
} // printMap()

int main() {
  // Initializing ncurses and the Catan class
  Catan catan(4);
  initscr();
  start_color();
  refresh();

  int x, y;
  getmaxyx(stdscr, y, x);

  // Center the logo dynamically
  int logo_start_x = y / 8;
  int logo_start_y = (x - 115) / 2;

  // Creating game logo
  init_pair(1, COLOR_YELLOW, COLOR_BLACK);
  init_pair(2, COLOR_RED, COLOR_BLACK);
  init_pair(3, COLOR_WHITE, COLOR_BLACK);
  attron(COLOR_PAIR(1));
  mvprintw(logo_start_x, logo_start_y, "                   _________         __");
  mvprintw(logo_start_x + 1, logo_start_y, "                   \\_   ___ \\_____ _/  |______");
  mvprintw(logo_start_x + 2, logo_start_y, "                   /    \\  \\/\\__  \\\\   __\\__  \\ ");
  mvprintw(logo_start_x + 3, logo_start_y, "                   \\     \\____/ __ \\|  |  / __ \\ ");
  mvprintw(logo_start_x + 4, logo_start_y, "                    \\______  (____  /__| (____  ");
  mvprintw(logo_start_x + 5, logo_start_y, "                           \\/     \\/          \\/");
  attron(COLOR_PAIR(2));
  mvprintw(logo_start_x + 1, logo_start_y + 47, "  ____   ____  __ _________  ______ ____   ______");
  mvprintw(logo_start_x + 2, logo_start_y + 47, " /    \\_/ ___\\|  |  \\_  __ \\/  ___// __ \\ /  ___/");
  mvprintw(logo_start_x + 3, logo_start_y + 47, "|   |  \\  \\___|  |  /|  | \\/\\___ \\\\  ___/ \\___ \\ ");
  mvprintw(logo_start_x + 4, logo_start_y + 47, "/___|  /\\___  >____/ |__|  /____  >\\___  >____  >");
  mvprintw(logo_start_x + 5, logo_start_y + 47, "     \\/     \\/                  \\/     \\/     \\/ ");
  attron(COLOR_PAIR(3));

  // Creating the map interface
  WINDOW *map = nullptr;
  map = newwin(40, 100, (y / 2) - 20, (x / 2) - 50);
  box(map, 0, 0);
  wrefresh(map);
  catan.printMap((y / 2) - 5, (x / 2) - 5);

  refresh();

  getch();
  endwin();
  return 0;
}; // main()