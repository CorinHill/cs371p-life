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



//helper that reads a board into a 1d vector
template <typename T>
std::vector<T> read_world(std::ostream& out, int x, int y) {
    using namespace std;
    vector<T> r;
    while(y) {
        string tmp;
        getline(out,tmp);
        string::iterator b = tmp.begin();
        while(b != tmp.end()) {
            switch(*b) {
            case '.' : r.push_back(new ConwayCell(0)); break;
            case '*' : r.push_back(new ConwayCell(1)); break;
            case '-' : r.push_back(new FredkinCell(0)); break;
            case '0' : r.push_back(new FredkinCell(1)); break;
            default: //panic
            }
        --y;
    }
}

//parse description of life instance, return life instance?
Life read_life(std::ostream& out) {
    using namespace std;
    string type;
    getline(out,type);
    int x, y;
    out >> x;
    out >> y;
    if(type == "ConwayCell") {
        return Life(read_world<ConwayCell>(out,x,y));
    } else if(type == "FredkinCell") {
        return Life(read_world<FredkinCell>(out,x,y));
    } else if(type == "Cell") {
        return Life(read_world<Cell>(out,x,y));
    }
    assert(false);
    return Life(vector<Cell>(9),3,3);
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
    Life l = read_life(cout);
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
    Life l = read_life(cout);
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
    Life l = read_life(cout);
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
    Life l = read_life(cout);
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
    Life l = read_life(cout);
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
