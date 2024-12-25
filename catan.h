#ifndef CATAN_H
#define CATAN_H

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "island.h"
using std::string, std::vector;

class Catan {
  public:
    Catan(int np);
    void startHex(int start_x, int start_y); 
    void printMap(int start_x, int start_y);

  private:
    int num_players;
    string map;
    Island island;
    int start_x = 25;
    int start_y = 100;
};

#endif // CATAN_H