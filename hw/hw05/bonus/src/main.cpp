#include <iostream>
#include <vector>
#include "boardGame2D.h"
#include "pegSolitaire.h"
#include "eightPuzzle.h"
#include "klotski.h"

using std::vector;
using std::cout;
using std::endl;
using GameEBY::BoardGame2D;
using GameEBY::PegSolitaire;
using GameEBY::EightPuzzle;
using GameEBY::Klotski;

template<class T>
void test (BoardGame2D<T> * g, int gmode);
// plays the given game in two different game mode 
// gmode = 0 for auto mode 
// gmode = 1 for player mode 
template<class T>
void test ();
// tests all the games in auto mode

int main (void) {
    // change the gamemode
    // gmode 0 auto mode 
    // gmode 1 user mode 
    int gmode = 0;
    
    /*
    test(new Klotski, 0);
    test(new EightPuzzle, 0);
    test(new PegSolitaire, 0);
    */
    
    return 0;
}


template<class T>
void test (BoardGame2D<T> * g, int gmode) {
    g->initialize();
    if (gmode == 0) 
        g->playAutoAll();
    else if (gmode == 1) 
        g->playUser();
}

template<class T>
void test () {
    BoardGame2D<T> * g[6];
    g[0] = new PegSolitaire;
    g[1] = new PegSolitaire;
    g[2] = new EightPuzzle;
    g[3] = new EightPuzzle;
    g[4] = new Klotski;
    g[5] = new Klotski;
    
    for (auto p : g)
        p->playAutoAll();
}