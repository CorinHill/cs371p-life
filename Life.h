#ifndef  __LIFE_H__
#define  __LIFE_H__

#include <iostream>  //ostream
#include <algorithm> //swap
#include <vector>    //vector
#include <cassert>   //assert

class AbstractCell {
friend std::ostream& operator<<(std::ostream& lhs, const AbstractCell& rhs) {
    return rhs.write(lhs);
}
friend bool operator==(const AbstractCell& lhs, const AbstractCell& rhs) {
    return lhs.equals(rhs);
}
friend bool operator!=(const AbstractCell& lhs, const AbstractCell& rhs) {
    return !(lhs == rhs);
}
protected:
    virtual std::ostream& write(std::ostream& out) const = 0;
    virtual bool equals(const AbstractCell& that) const = 0;
public:
    virtual AbstractCell* clone() const = 0;
    virtual void age(const std::vector<AbstractCell>& n) = 0;
    virtual void age(int n) = 0;
    virtual bool isAlive() const = 0; //only kind of a getter
};


class  ConwayCell : public AbstractCell {
private:
    unsigned _s;
protected:
    virtual std::ostream& write(std::ostream& out) const {
        if(_s) out << '*';
        else   out << '.';
        return out;
    }
    virtual bool equals(const AbstractCell& that) const {
        if(const ConwayCell* const p = dynamic_cast<const ConwayCell*>(&that))
            return _s == p->_s;
        return false;
    }
public:
    ConwayCell(unsigned s = 0) : _s(s) {}
    virtual AbstractCell* clone() const {
        return new ConwayCell(_s);
    }
    virtual void age(const std::vector<AbstractCell>& n) {
        int sum = 0;
        for(int i = 0; i < n.size(); ++i ) {
            if( n[i].isAlive() ) ++sum;
        }
        age(sum);
    }
    virtual void age(int n) {
        if(_s) //alive
            if(n<2 || n>3) _s = 0;
        else   //dead
            if(n==3) _s = 1;
    }
    virtual bool isAlive() const { return _s!=0 ;}   
};

class FredkinCell : public AbstractCell {
private:
    unsigned _s;
protected:
    virtual std::ostream& write(std::ostream& out) const {
        if( _s > 10 ) out << '+';
        else if(_s)   out << _s;
        else          out << '-';
        return out;
    }
    virtual bool equals(const AbstractCell& that) const {
        if(const FredkinCell* p = dynamic_cast<const FredkinCell*>(&that))
            return _s == p->_s;
        return false;
    }
public:
    FredkinCell(unsigned s = 0) : _s(s) {}
    virtual AbstractCell* clone() const {
        return new FredkinCell(_s);
    }
    virtual void age(const std::vector<AbstractCell>& n) {
        int sum = 0;
        if( n[1].isAlive() ) ++sum;
        if( n[3].isAlive() ) ++sum;
        if( n[4].isAlive() ) ++sum;
        if( n[6].isAlive() ) ++sum;
        age(sum);
    }
    virtual void age(int n) {
        if( _s ) { //alive
            if(n&1) ++_s;  //1, 3 neighbors alive
            else  _s = 0;     //0, 2, 4 alive
        } else     //dead
            if(n&1) _s = 1;//1, 3 alive
    }
    virtual bool isAlive() const { return _s!=0 ;}
    bool isAdult() const { return _s >= 2;}
};

class Cell {
friend std::ostream& operator<<(std::ostream& lhs, const Cell& rhs) {
    return lhs << *rhs._c;
}
friend bool operator==(const Cell& lhs, const Cell& rhs) {
    return (*(lhs._c) == *(rhs._c));
}
friend bool operator!=(const Cell& lhs, const Cell& rhs) {
    return !(lhs == rhs);
}
private:
    AbstractCell* _c;
public:
    Cell(AbstractCell* c)  : _c(c) {}
    Cell(const Cell& that) : _c(that._c->clone()) {}
    Cell& operator=(Cell that) {
        std::swap(_c, that._c);
        return *this;
    }
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

        _c->age(sum);
        if( const FredkinCell* const p = dynamic_cast<const FredkinCell*>(_c) )
            if(p->isAdult()) *this = new ConwayCell(1);
    }
    bool isAlive() const { return _c->isAlive(); }
    ~Cell() {
        delete _c;
    }
};

template <typename T>
class Life {
friend std::ostream& operator<<(std::ostream& lhs, const Life& rhs) {
    rhs.print(lhs);
    return lhs;
}
private:
    const int _x, _y;
    std::vector<T> _w;               //world
    std::vector<std::vector<T> > _n; //neighborhoods
public:
    Life(int x, int y, const std::vector<T>& w ) :
        _x(x), _y(y), _w(w), _n(x*y) {
        assert( x*y == w.size() ); //Initial state must be consistent
    }
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
    void rounds(int num = 0) {
        for(int i = 0; i < num; ++i)
            round();
    }
    std::ostream& print(std::ostream& out) const {
        for(int j = 0; j < _y; ++j) {
            for(int i = 0; i < _x; ++i) {
                out <<  _w[j*_x + i];
            }
            out << std::endl;
        }
    }
};



#endif //__LIFE_H__
