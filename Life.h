#ifndef  __LIFE_H__
#define  __LIFE_H__

// --------
// includes
// --------
#include <iostream>  //ostream
#include <algorithm> //swap
#include <vector>    //vector
#include <cassert>   //assert

/*
 * An abstract class that describes a general cell
 */
class AbstractCell {
// --------
//    <<
// --------
/**
 * output stream operator, calls dynamically bound member
 * @param lhs an ostream
 * @param rhs the cell to print
 * return the modified ostream
 */ 
friend std::ostream& operator<<(std::ostream& lhs, const AbstractCell& rhs) {
    return rhs.write(lhs);
}
// --------
//    ==
// --------
/**
 * equality operator
 * @param lhs the left hand cell
 * @param rhs the right hand cell
 * @return whether or not these cells are equivalent
 */
friend bool operator==(const AbstractCell& lhs, const AbstractCell& rhs) {
    return lhs.equals(rhs);
}
// --------
//    !=
// --------
/**
 * inequality operator, inverts equality
 * @param lhs the left hand cell
 * @param rhs the right hand cell
 * @return whether or not these cells are different
 */
friend bool operator!=(const AbstractCell& lhs, const AbstractCell& rhs) {
    return !(lhs == rhs);
}
protected:
// -------
//  write
// -------
/**
 * prints a cell to an output stream
 * @param out the stream to which this will be printed
 * @return the modified stream
 */
    virtual std::ostream& write(std::ostream& out) const = 0;
// --------
//  equals
// --------
/**
 * describes eqaulity between two cells
 * @param that the other cell
 * @return whether or not this and that are equivalent
 */
    virtual bool equals(const AbstractCell& that) const = 0;
public:
// -------
//  clone
// -------
/**
 * cloning abstraction
 * @return an equivalent cell
 */
    virtual AbstractCell* clone() const = 0;
// -----
//  age
// -----
/**
 * ages a cell given its neighborhood
 * @param n a vector containing a neighborhood
 */
    virtual void age(const std::vector<AbstractCell>& n) = 0;
// -----
//  age
// -----
/**
 * ages a cell given how many live cells surround it
 * @param n the number of living cells
 */
    virtual void age(int n) = 0;
// ---------
//  isAlive
// ---------
/**
 * describes the current state of the cell
 * @return whether or not this cell is alive
 */
    virtual bool isAlive() const = 0; //only kind of a getter
};

/**
 * a Conway cell
 */
class  ConwayCell : public AbstractCell {
private:
    unsigned _s;
protected:
// -------
//  write
// -------
/**
 * writes this Conway cell: '*' if alive, otherwise '.'
 * @param out the ostream to which will be written
 * @return the modified stream
 */
    virtual std::ostream& write(std::ostream& out) const {
        if(_s) out << '*';
        else   out << '.';
        return out;
    }
// --------
//  equals
// --------
/**
 * compares this Conway cell to another cell
 * @param that the other cell
 * @return whether or not this and that are equivalent
 */
    virtual bool equals(const AbstractCell& that) const {
        if(const ConwayCell* const p = dynamic_cast<const ConwayCell*>(&that))
            return _s == p->_s;
        return false;
    }
public:
// -----------
// constructor
// -----------
/**
 * constructs a conway cell with the given inital state
 * default state is dead
 * @param s the given state
 */
    ConwayCell(unsigned s = 0) : _s(s) {}
// -------
//  clone
// -------
/**
 * clones this cell
 * @return an equivalent Conway cell
 */
    virtual AbstractCell* clone() const {
        return new ConwayCell(_s);
    }
// -----
//  age
// -----
/**
 * ages a Conway cell given its neighborhood
 * @param n a vector containing the neighborhood
 */
    virtual void age(const std::vector<AbstractCell>& n) {
        int sum = 0;
        for(int i = 0; i < n.size(); ++i ) {
            if( n[i].isAlive() ) ++sum;
        }
        age(sum);
    }
// -----
//  age
// -----
/**
 * ages a cell given a count of the live cells in this neighborhood
 * @param n the number of live cells surrounding
 */
    virtual void age(int n) {
        if(_s) //alive
            if(n<2 || n>3) _s = 0;
        else   //dead
            if(n==3) _s = 1;
    }
// ---------
//  isAlive
// ---------
/**
 * describes the state of this Conway cell
 * @return whether or not this cell is alive
 */
    virtual bool isAlive() const { return _s!=0 ;}   
};




/**
 * A Fredkin cell template
 */
class FredkinCell : public AbstractCell {
private:
    unsigned _s;
protected:
// --------
//  write
// -------
/**
 * outputs this Fredkin cell. '-' if dead
 * a number if alive and younger than 10, '+' otherwise
 * @param out the stream where this will be written
 * @return the modified stream
 */
    virtual std::ostream& write(std::ostream& out) const {
        if( _s > 10 ) out << '+';
        else if(_s)   out << _s;
        else          out << '-';
        return out;
    }
// --------
//  equals
// --------
/**
 * compares this Fredkin cell to another cell
 * @param that the other cell
 * @return whether or not this and that are equivalent
 */
    virtual bool equals(const AbstractCell& that) const {
        if(const FredkinCell* p = dynamic_cast<const FredkinCell*>(&that))
            return _s == p->_s;
        return false;
    }
public:
// -----------
// constructor
// -----------
/**
 * creates a Fredkin cell with the given state
 * default state is dead
 * @param s the given state
 */
    FredkinCell(unsigned s = 0) : _s(s) {}
// -------
//  clone
// -------
/**
 * clones this cell
 * @return an equivalent Fredkin cell
 */
    virtual AbstractCell* clone() const {
        return new FredkinCell(_s);
    }
// -----
//  age
// -----
/**
 * ages a Fredkin cell given its neighborhood
 * @param n a vector containing the neighborhood
 */
    virtual void age(const std::vector<AbstractCell>& n) {
        int sum = 0;
        if( n[1].isAlive() ) ++sum;
        if( n[3].isAlive() ) ++sum;
        if( n[4].isAlive() ) ++sum;
        if( n[6].isAlive() ) ++sum;
        age(sum);
    }
// -----
//  age
// -----
/**
 * ages a Fredkin cell given the number of living neighbors
 * @param n the number of living neightbors
 */
    virtual void age(int n) {
        if( _s ) { //alive
            if(n&1) ++_s;  //1, 3 neighbors alive
            else  _s = 0;     //0, 2, 4 alive
        } else     //dead
            if(n&1) _s = 1;//1, 3 alive
    }
// ---------
//  isAlive
// ---------
/**
 * describes this cells state
 * @return whether or not this cell is alive
 */
    virtual bool isAlive() const { return _s!=0 ;}
// ---------
//  isAdult
// ---------
/**
 * describes this cells age
 * @return whether this cell has reached adulthood or not (2 turns old)
 */
    bool isAdult() const { return _s >= 2;}
};





/**
 * a handle for descendents of AbstractCell
 */
class Cell {
// --------
//    <<
// --------
/**
 * output stream operator, prints a cell
 * @param lhs an ostream
 * @param rhs the cell to print
 * return the modified ostream
 */
friend std::ostream& operator<<(std::ostream& lhs, const Cell& rhs) {
    return lhs << *rhs._c;
}
// --------
//    ==
// --------
/**
 * equality operator
 * @param lhs the left hand cell
 * @param rhs the right hand cell
 * @return whether or not these cells are equivalent
 */
friend bool operator==(const Cell& lhs, const Cell& rhs) {
    return (*(lhs._c) == *(rhs._c));
}
// --------
//    !=
// --------
/**
 * inequality operator
 * @param lhs the left hand cell
 * @param rhs the right hand cell
 * @return whether or not these cells are not equivalent
 */
friend bool operator!=(const Cell& lhs, const Cell& rhs) {
    return !(lhs == rhs);
}
private:
    AbstractCell* _c;
// -----
//   =
// -----
/**
 * assignment operator
 * copies the other Cell on entry, swaps their data
 * @param that the other cell
 * @return this modified cell
 */
    Cell& operator=(Cell that) {
        std::swap(_c, that._c);
        return *this;
    }
public:
// -----------
// constructor
// -----------
/**
 * creates a new cell given a pointer to an AbstractCell
 * defaults to a dead Conway cell
 * @param the given pointer
 */
    Cell(AbstractCell* c = new ConwayCell())  : _c(c) {}
// -----------
// constructor
// -----------
/**
 * copy constructor clones the member
 * @param the Cell being copied
 */
    Cell(const Cell& that) : _c(that._c->clone()) {}
// -----
//  age
// -----
/**
 * ages the contained cell based on its neighborhood
 * @param n vector representing neighborhood
 */
    void age(const std::vector<Cell>& n) {
        int sum = 0;
        if( const FredkinCell* const p = dynamic_cast<const FredkinCell*>(_c) ) {
            if(n[1].isAlive()) ++sum;
            if(n[3].isAlive()) ++sum;
            if(n[4].isAlive()) ++sum;
            if(n[6].isAlive()) ++sum;
        } else
        if( const ConwayCell* const p = dynamic_cast<const ConwayCell*>(_c) ) {
            for(int i = 0; i < n.size(); ++i)
                if(n[i].isAlive()) ++sum;
        } //else //other subclass of AbstractCell, unknown behavior

        age(sum);
        if( const FredkinCell* const p = dynamic_cast<const FredkinCell*>(_c) )
            if(p->isAdult()) *this = new ConwayCell(1);
    }
// -----
//  age
// -----
/**
 * ages this cell given the number of surrounding live cells
 * only here to match public interface
 * @param n the number of living neighbors
 */
    void age(int n) { _c->age(n); }
// ---------
//  isAlive
// ---------
/**
 * describes this cell's state
 * @return whether or not this cell is alive
 */
    bool isAlive() const { return _c->isAlive(); }
// ----------
// destructor
// ----------
/**
 * removes managed memory
 */
    ~Cell() { delete _c; }
};




/**
 * templated class Life represents Conways game of life
 */
template <typename T>
class Life {
// ------
//   <<
// ------
/**
 * ostream operator, prints the whole world
 */
friend std::ostream& operator<<(std::ostream& lhs, const Life& rhs) {
    rhs.print(lhs);
    return lhs;
}
private:
    const int _x, _y;
    std::vector<T> _w;               //world
    std::vector<std::vector<T> > _n; //neighborhoods
// -------
//  print
// -------
/**
 * prints the current state of the world
 * @param out the location to which is printed
 * @return the modified ostream
 */
    std::ostream& print(std::ostream& out) const {
        for(int j = 0; j < _y; ++j) {
            for(int i = 0; i < _x; ++i) {
                out <<  _w[j*_x + i];
            }
            out << std::endl;
        }
    }
public:
// -----------
// constructor
// -----------
/**
 * initializes a game of life
 * @param x the horizontal dimension
 * @param y the vertical dimension
 * @param w the initial state of the game "board"
 */
    Life(int x, int y, const std::vector<T>& w ) :
        _x(x), _y(y), _w(w), _n(x*y) {
        assert( x*y == w.size() ); //Initial state must be consistent
    }
// -------
//  round
// -------
/**
 * acts out one round of life
 * 2 passes. the first fills an array with neighborhood for each cell
 * the latter then ages each cell based on these neighborhoods
 */
    void round() {
        for(int j = 0; j < _y; ++j) {
            for(int i = 0; i < _x; ++i) {
                int index = j*_x + i;
                if(j > 0) {
                    if(i > 0) _n[index].push_back( _w[index - _x - 1] );
                    else _n[index].push_back(ConwayCell());
                    _n[index].push_back( _w[index - _x] );
                    if(i < _x-1) _n[index].push_back( _w[index - _x + 1] );
                    else _n[index].push_back(ConwayCell());
                } else {
                    _n[index].push_back(ConwayCell());
                    _n[index].push_back(ConwayCell());
                    _n[index].push_back(ConwayCell());
                }

                if(i > 0) _n[index].push_back( _w[index - 1] );
                else _n[index].push_back(ConwayCell());
                if(i < _x-1) _n[index].push_back( _w[index + 1] );
                else _n[index].push_back(ConwayCell());

                if(j < _y-1) {
                    if(i > 0) _n[index].push_back( _w[index + _x - 1] );
                    else _n[index].push_back(ConwayCell());
                    _n[index].push_back( _w[index + _x] );
                    if(i < _x-1) _n[index].push_back( _w[index + _x + 1] );
                    else _n[index].push_back(ConwayCell());
                } else {
                    _n[index].push_back(ConwayCell());
                    _n[index].push_back(ConwayCell());
                    _n[index].push_back(ConwayCell());
                }
            }
        }
        for(int j = 0; j < _y; ++j)
            for(int i = 0; i < _x; ++i) {
                _w[j*_x + i].age( _n[j*_x + i] );
                _n[j*_x + i].clear();
            }
    }
// --------
//  rounds
// --------
/**
 * executes a given number of rounds
 * defaults to zero rounds
 * @param num the number of rounds to run
 */
    void rounds(int num = 0) {
        for(int i = 0; i < num; ++i)
            round();
    }
};



#endif //__LIFE_H__
