// -------------------------
// projects/life/RunLife.c++
// Copyright (C) 2014
// Glenn P. Downing
// -------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <vector>
#include <string>

#include "Life.h"

//helper that reads a board into a 1d vector
//parse description of life instance, return life instance?
Life<ConwayCell> read_life_cc(std::istream& in) {
    using namespace std;
    string type;
    getline(in,type);
    int x, y;
    in >> y;
    in >> x;
    if(type != "ConwayCell") assert(false);

    vector<ConwayCell> r;
    for(int i = 0; i <= y; ++i) {
        string tmp;
        getline(in,tmp);
        string::iterator b = tmp.begin();
        while(b != tmp.end()) {
            switch(*b) {
            case '.': r.push_back( ConwayCell(0)); break;
            case '*': r.push_back( ConwayCell(1)); break;
            default : ;
            }
            ++b;
        }
    }
    string t; getline(in,t);
    return Life<ConwayCell>(x,y,r);
}
Life<FredkinCell> read_life_fc(std::istream& in) {
    using namespace std;
    string type;
    getline(in,type);
    int x, y;
    in >> y;
    in >> x;
    if(type != "FredkinCell") assert(false);

    vector<FredkinCell> r;
    for(int i = 0; i <=y; ++i) {
        string tmp;
        getline(in,tmp);
        string::iterator b = tmp.begin();
        while(b != tmp.end()) {
            switch(*b) {
            case '-': r.push_back(FredkinCell(0)); break;
            case '0': r.push_back(FredkinCell(1)); break;
            default : ;
            }
            ++b;
        }
    }
    string t; getline(in,t);
    return Life<FredkinCell>(x,y,r);
}
Life<Cell> read_life_c(std::istream& in) {
    using namespace std;
    string type;
    getline(in,type);
    int x, y;
    in >> y;
    in >> x;
    if(type != "Cell") assert(false);

    vector<Cell> r;
    for(int i = 0; i <=y; ++i) {
        string tmp;
        getline(in,tmp);
        string::iterator b = tmp.begin();
        while(b != tmp.end()) {
            switch(*b) {
            case '.': r.push_back(new  ConwayCell(0)); break;
            case '*': r.push_back(new  ConwayCell(1)); break;
            case '-': r.push_back(new FredkinCell(0)); break;
            case '0': r.push_back(new FredkinCell(1)); break;
            default : ;
            }
            ++b;
        }
    }
    string t; getline(in,t);
    return Life<Cell>(x,y,r);
}




// ----
// main
// ----

int main () {
    using namespace std;

    // -----------------
    // Conway Cell 21x13
    // -----------------

    cout << "*** Life<ConwayCell> 21x13 ***" << endl;
    {
    Life<ConwayCell> l = read_life_cc(cin);
    for(int i = 0;i < 13; ++i) {
        cout << "Generation = " << i 
             << ", Population = " << l.population() << '.' << endl
             << l << endl;
        l.round();
    }
    }
    /*
    Simulate 12 evolutions.
    Print every grid (i.e. 0, 1, 2, 3, ... 12)
    */

    // -----------------
    // Conway Cell 20x29
    // -----------------

    cout << "*** Life<ConwayCell> 20x29 ***" << endl;
    {
    Life<ConwayCell> l = read_life_cc(cin);
    for(int i = 0;i < 29; ++i) {
        if(i%4 == 0)
            cout << "Generation = " << i 
                 << ", Population = " << l.population() << '.' << endl
                 << l << endl;
        l.round();
    }
    }
    /*
    Simulate 28 evolutions.
    Print every 4th grid (i.e. 0, 4, 8, ... 28)
    */

    // ------------------
    // Conway Cell 109x69
    // ------------------

    cout << "*** Life<ConwayCell> 109x69 ***" << endl;
    {
    Life<ConwayCell> l = read_life_cc(cin);
    for(int i = 0;i < 2501; ++i) {
        if(i<10 || i==282 || i==322 || i==2176)
            cout << "Generation = " << i 
                 << ", Population = " << l.population() << '.' << endl
                 << l << endl;
        l.round();
    }
    }
    /*
    Simulate 283 evolutions.
    Print the first 10 grids (i.e. 0, 1, 2, ... 9).
    Print the 283rd grid.
    Simulate 40 evolutions.
    Print the 323rd grid.
    Simulate 2177 evolutions.
    Print the 2500th grid.
    */

    // ------------------
    // Fredkin Cell 20x20
    // ------------------

    cout << "*** Life<FredkinCell> 20x20 ***" << endl;
    {
    Life<FredkinCell> l = read_life_fc(cin);
    for(int i = 0;i < 6; ++i) {
        cout << "Generation = " << i 
             << ", Population = " << l.population() << '.' << endl
             << l << endl;
        l.round();
    }
    }
    /*
    Simulate 5 evolutions.
    Print every grid (i.e. 0, 1, 2, ... 5)
    */

    // ----------
    // Cell 20x20
    // ----------

    cout << "*** Life<Cell> 20x20 ***" << endl;
    {
    Life<Cell> l = read_life_c(cin);
    for(int i = 0;i < 6; ++i) {
        cout << "Generation = " << i 
             << ", Population = " << l.population() << '.' << endl
             << l << endl;
        l.round();
    }
    }
    /*
    Simulate 5 evolutions.
    Print every grid (i.e. 0, 1, 2, ... 5)
    */

    return 0;}
