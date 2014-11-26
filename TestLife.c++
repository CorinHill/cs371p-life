#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include "gtest/gtest.h"
#include "Life.h"

using namespace std;

//ConwayCell test
TEST (ConwayCell, live1) {
  ConwayCell a(1);
  ASSERT_EQ(a.isAlive(),true);
}
TEST (ConwayCell, live2) {
  ConwayCell a(0);
  ASSERT_EQ(a.isAlive(),false);
}
TEST (ConwayCell, live3) {
  ConwayCell a;
  ASSERT_EQ(a.isAlive(),false);
}
TEST (ConwayCell, clone1) {
  ConwayCell a;
  ASSERT_EQ(a.isAlive(),false);
  ConwayCell* b = dynamic_cast<ConwayCell*>(a.clone());
  if(b==0) ASSERT_EQ(true,false);
  else ASSERT_EQ(b->isAlive(),false);
  delete b;
}
TEST (ConwayCell, clone2) {
  ConwayCell a(0);
  ASSERT_EQ(a.isAlive(),false);
  ConwayCell* b = dynamic_cast<ConwayCell*>(a.clone());
  if(b==0) ASSERT_EQ(true,false);
  else ASSERT_EQ(b->isAlive(),false);
  delete b;
}
TEST (ConwayCell, clone3) {
  ConwayCell a(1);
  ASSERT_EQ(a.isAlive(),true);
  ConwayCell* b = dynamic_cast<ConwayCell*>(a.clone());
  if(b==0) ASSERT_EQ(true,false);
  else ASSERT_EQ(b->isAlive(),true);
  delete b;
}
TEST (ConwayCell, agen1) {
  ConwayCell a;
  ASSERT_EQ(a.isAlive(),false);
  a.age(3);
  ASSERT_EQ(a.isAlive(),true);
}
TEST (ConwayCell, agen2) {
  ConwayCell a;
  ASSERT_EQ(a.isAlive(),false);
  a.age(0);
  ASSERT_EQ(a.isAlive(),false);
}
TEST (ConwayCell, agen3) {
  ConwayCell a;
  ASSERT_EQ(a.isAlive(),false);
  a.age(1);
  ASSERT_EQ(a.isAlive(),false);
}
TEST (ConwayCell, agen4) {
  ConwayCell a;
  ASSERT_EQ(a.isAlive(),false);
  a.age(2);
  ASSERT_EQ(a.isAlive(),false);
}
TEST (ConwayCell, agen5) {
  ConwayCell a;
  ASSERT_EQ(a.isAlive(),false);
  a.age(4);
  ASSERT_EQ(a.isAlive(),false);
}
TEST (ConwayCell, agen6) {
  ConwayCell a(1);
  ASSERT_EQ(a.isAlive(),true);
  a.age(3);
  ASSERT_EQ(a.isAlive(),true);
}
TEST (ConwayCell, agen7) {
  ConwayCell a(1);
  ASSERT_EQ(a.isAlive(),true);
  a.age(0);
  ASSERT_EQ(a.isAlive(),false);
}
TEST (ConwayCell, agen8) {
  ConwayCell a(1);
  ASSERT_EQ(a.isAlive(),true);
  a.age(1);
  ASSERT_EQ(a.isAlive(),false);
}

TEST (ConwayCell, agen9) {
  ConwayCell a(1);
  ASSERT_EQ(a.isAlive(),true);
  a.age(2);
  ASSERT_EQ(a.isAlive(),true);
}
TEST (ConwayCell, agen10) {
  ConwayCell a(1);
  ASSERT_EQ(a.isAlive(),true);
  a.age(4);
  ASSERT_EQ(a.isAlive(),false);
}
TEST (ConwayCell, out1) {
  ConwayCell a;
  ASSERT_EQ(a.isAlive(),false);
  ostringstream out;
  out << a;
  string s(".");
  ASSERT_EQ(out.str(),s);
}
TEST (ConwayCell, out2) {
  ConwayCell a(1);
  ASSERT_EQ(a.isAlive(),true);
  ostringstream out;
  out << a;
  string s("*");
  ASSERT_EQ(out.str(),s);
}
TEST (ConwayCell, eq1) {
  ConwayCell a;
  ASSERT_EQ(a.isAlive(),false);
  ConwayCell b(1);
  ASSERT_EQ(b.isAlive(),true);
  ASSERT_EQ(a == b, false);
}
TEST (ConwayCell, eq2) {
  ConwayCell a;
  ASSERT_EQ(a.isAlive(),false);
  ConwayCell b;
  ASSERT_EQ(b.isAlive(),false);
  ASSERT_EQ(a == b, true);
}
TEST (ConwayCell, eq3) {
  ConwayCell a(1);
  ASSERT_EQ(a.isAlive(), true);
  ConwayCell b(1);
  ASSERT_EQ(b.isAlive(), true);
  ASSERT_EQ(a == b, true);
}
TEST (ConwayCell, eq4) {
  ConwayCell a(1);
  ASSERT_EQ(a.isAlive(), true);
  ConwayCell b;
  ASSERT_EQ(b.isAlive(), false);
  ASSERT_EQ(a == b, false);
}
TEST (ConwayCell, ne1) {
  ConwayCell a;
  ASSERT_EQ(a.isAlive(), false);
  ConwayCell b(1);
  ASSERT_EQ(b.isAlive(), true);
  ASSERT_EQ(a != b, true);
}
TEST (ConwayCell, ne2) {
  ConwayCell a;
  ASSERT_EQ(a.isAlive(), false);
  ConwayCell b;
  ASSERT_EQ(b.isAlive(), false);
  ASSERT_EQ(a != b, false);
}
TEST (ConwayCell, ne3) {
  ConwayCell a(1);
  ASSERT_EQ(a.isAlive(), true);
  ConwayCell b(1);
  ASSERT_EQ(b.isAlive(), true);
  ASSERT_EQ(a != b, false);
}
TEST (ConwayCell, ne4) {
  ConwayCell a(1);
  ASSERT_EQ(a.isAlive(), true);
  ConwayCell b;
  ASSERT_EQ(b.isAlive(), false);
  ASSERT_EQ(a != b, true);
}








//FredkinCell test
TEST (FredkinCell, live1) {
  FredkinCell a(1);
  ASSERT_EQ(a.isAlive(),true);
}
TEST (FredkinCell, live2) {
  FredkinCell a(0);
  ASSERT_EQ(a.isAlive(),false);
}
TEST (FredkinCell, live3) {
  FredkinCell a;
  ASSERT_EQ(a.isAlive(),false);
}
TEST (FredkinCell, clone1) {
  FredkinCell a;
  ASSERT_EQ(a.isAlive(),false);
  FredkinCell* b = dynamic_cast<FredkinCell*>(a.clone());
  if(b==0) ASSERT_EQ(true,false);
  else ASSERT_EQ(b->isAlive(),false);
  delete b;
}
TEST (FredkinCell, clone2) {
  FredkinCell a(0);
  ASSERT_EQ(a.isAlive(),false);
  FredkinCell* b = dynamic_cast<FredkinCell*>(a.clone());
  if(b==0) ASSERT_EQ(true,false);
  else ASSERT_EQ(b->isAlive(),false);
  delete b;
}
TEST (FredkinCell, clone3) {
  FredkinCell a(1);
  ASSERT_EQ(a.isAlive(),true);
  FredkinCell* b = dynamic_cast<FredkinCell*>(a.clone());
  if(b==0) ASSERT_EQ(true,false);
  else ASSERT_EQ(b->isAlive(),true);
  delete b;
}
TEST (FredkinCell, agen1) {
  FredkinCell a;
  ASSERT_EQ(a.isAlive(),false);
  a.age(3);
  ASSERT_EQ(a.isAlive(),true);
}
TEST (FredkinCell, agen2) {
  FredkinCell a;
  ASSERT_EQ(a.isAlive(),false);
  a.age(0);
  ASSERT_EQ(a.isAlive(),false);
}
TEST (FredkinCell, agen3) {
  FredkinCell a;
  ASSERT_EQ(a.isAlive(),false);
  a.age(1);
  ASSERT_EQ(a.isAlive(),true);
}
TEST (FredkinCell, agen4) {
  FredkinCell a;
  ASSERT_EQ(a.isAlive(),false);
  a.age(2);
  ASSERT_EQ(a.isAlive(),false);
}
TEST (FredkinCell, agen5) {
  FredkinCell a;
  ASSERT_EQ(a.isAlive(),false);
  a.age(4);
  ASSERT_EQ(a.isAlive(),false);
}
TEST (FredkinCell, agen6) {
  FredkinCell a(1);
  ASSERT_EQ(a.isAlive(),true);
  a.age(3);
  ASSERT_EQ(a.isAlive(),true);
}
TEST (FredkinCell, agen7) {
  FredkinCell a(1);
  ASSERT_EQ(a.isAlive(),true);
  a.age(0);
  ASSERT_EQ(a.isAlive(),false);
}
TEST (FredkinCell, agen8) {
  FredkinCell a(1);
  ASSERT_EQ(a.isAlive(),true);
  a.age(1);
  ASSERT_EQ(a.isAlive(),true);
}
TEST (FredkinCell, agen9) {
  FredkinCell a(1);
  ASSERT_EQ(a.isAlive(),true);
  a.age(2);
  ASSERT_EQ(a.isAlive(),false);
}
TEST (FredkinCell, agen10) {
  FredkinCell a(1);
  ASSERT_EQ(a.isAlive(),true);
  a.age(4);
  ASSERT_EQ(a.isAlive(),false);
}
TEST (FredkinCell, out1) {
  FredkinCell a;
  ASSERT_EQ(a.isAlive(),false);
  ostringstream out;
  out << a;
  string s("-");
  ASSERT_EQ(out.str(),s);
}
TEST (FredkinCell, out2) {
  FredkinCell a(1);
  ASSERT_EQ(a.isAlive(),true);
  ostringstream out;
  out << a;
  string s("0");
  ASSERT_EQ(out.str(),s);
}
TEST (FredkinCell, out3) {
  FredkinCell a(1);
  ASSERT_EQ(a.isAlive(),true);
  for(int i=0;i<15;++i)
    a.age(1);
  ostringstream out;
  out << a;
  string s("+");
  ASSERT_EQ(out.str(),s);
}
TEST (FredkinCell, eq1) {
  FredkinCell a;
  ASSERT_EQ(a.isAlive(),false);
  FredkinCell b(1);
  ASSERT_EQ(b.isAlive(),true);
  ASSERT_EQ(a == b, false);
}
TEST (FredkinCell, eq2) {
  FredkinCell a;
  ASSERT_EQ(a.isAlive(),false);
  FredkinCell b;
  ASSERT_EQ(b.isAlive(),false);
  ASSERT_EQ(a == b, true);
}
TEST (FredkinCell, eq3) {
  FredkinCell a(1);
  ASSERT_EQ(a.isAlive(), true);
  FredkinCell b(1);
  ASSERT_EQ(b.isAlive(), true);
  ASSERT_EQ(a == b, true);
}
TEST (FredkinCell, eq4) {
  FredkinCell a(1);
  ASSERT_EQ(a.isAlive(), true);
  FredkinCell b;
  ASSERT_EQ(b.isAlive(), false);
  ASSERT_EQ(a == b, false);
}
TEST (FredkinCell, ne1) {
  FredkinCell a;
  ASSERT_EQ(a.isAlive(), false);
  FredkinCell b(1);
  ASSERT_EQ(b.isAlive(), true);
  ASSERT_EQ(a != b, true);
}
TEST (FredkinCell, ne2) {
  FredkinCell a;
  ASSERT_EQ(a.isAlive(), false);
  FredkinCell b;
  ASSERT_EQ(b.isAlive(), false);
  ASSERT_EQ(a != b, false);
}
TEST (FredkinCell, ne3) {
  FredkinCell a(1);
  ASSERT_EQ(a.isAlive(), true);
  FredkinCell b(1);
  ASSERT_EQ(b.isAlive(), true);
  ASSERT_EQ(a != b, false);
}
TEST (FredkinCell, ne4) {
  FredkinCell a(1);
  ASSERT_EQ(a.isAlive(), true);
  FredkinCell b;
  ASSERT_EQ(b.isAlive(), false);
  ASSERT_EQ(a != b, true);
}









//Cell handle
TEST (Cell, live1) {
  Cell a(new ConwayCell(1));
  ASSERT_EQ(a.isAlive(),true);
}
TEST (Cell, live2) {
  Cell a(new ConwayCell(0));
  ASSERT_EQ(a.isAlive(),false);
}
TEST (Cell, live3) {
  Cell a(new ConwayCell());
  ASSERT_EQ(a.isAlive(),false);
}
TEST (Cell, live4) {
  Cell a(new FredkinCell(1));
  ASSERT_EQ(a.isAlive(),true);
}
TEST (Cell, live5) {
  Cell a(new FredkinCell(0));
  ASSERT_EQ(a.isAlive(),false);
}
TEST (Cell, live6) {
  Cell a(new FredkinCell());
  ASSERT_EQ(a.isAlive(),false);
}
TEST (Cell, copy1) {
  Cell a(new ConwayCell());
  ASSERT_EQ(a.isAlive(),false);
  Cell b(a);
  ASSERT_EQ(b.isAlive(),false);
}
TEST (Cell, copy2) {
  Cell a(new ConwayCell(0));
  ASSERT_EQ(a.isAlive(),false);
  Cell b(a);
  ASSERT_EQ(b.isAlive(),false);
}
TEST (Cell, copy3) {
  Cell a(new ConwayCell(1));
  ASSERT_EQ(a.isAlive(),true);
  Cell b(a);
  ASSERT_EQ(b.isAlive(),true);
}
TEST (Cell, copy4) {
  Cell a(new FredkinCell());
  ASSERT_EQ(a.isAlive(),false);
  Cell b(a);
  ASSERT_EQ(b.isAlive(),false);
}
TEST (Cell, copy5) {
  Cell a(new FredkinCell(0));
  ASSERT_EQ(a.isAlive(),false);
  Cell b(a);
  ASSERT_EQ(b.isAlive(),false);
}
TEST (Cell, copy6) {
  Cell a(new FredkinCell(1));
  ASSERT_EQ(a.isAlive(),true);
  Cell b(a);
  ASSERT_EQ(b.isAlive(),true);
}
TEST (Cell, agen_conway1) {
  Cell a;
  ASSERT_EQ(a.isAlive(),false);
  a.age(3);
  ASSERT_EQ(a.isAlive(),true);
}
TEST (Cell, agen_conway2) {
  Cell a;
  ASSERT_EQ(a.isAlive(),false);
  a.age(0);
  ASSERT_EQ(a.isAlive(),false);
}
TEST (Cell, agen_conway3) {
  Cell a;
  ASSERT_EQ(a.isAlive(),false);
  a.age(1);
  ASSERT_EQ(a.isAlive(),false);
}
TEST (Cell, agen_conway4) {
  Cell a;
  ASSERT_EQ(a.isAlive(),false);
  a.age(2);
  ASSERT_EQ(a.isAlive(),false);
}
TEST (Cell, agen_conway5) {
  Cell a;
  ASSERT_EQ(a.isAlive(),false);
  a.age(4);
  ASSERT_EQ(a.isAlive(),false);
}
TEST (Cell, agen_conway6) {
  Cell a(new ConwayCell(1));
  ASSERT_EQ(a.isAlive(),true);
  a.age(3);
  ASSERT_EQ(a.isAlive(),true);
}
TEST (Cell, agen_conway7) {
  Cell a(new ConwayCell(1));
  ASSERT_EQ(a.isAlive(),true);
  a.age(0);
  ASSERT_EQ(a.isAlive(),false);
}
TEST (Cell, agen_conway8) {
  Cell a(new ConwayCell(1));
  ASSERT_EQ(a.isAlive(),true);
  a.age(1);
  ASSERT_EQ(a.isAlive(),false);
}

TEST (Cell, agen_conway9) {
  Cell a(new ConwayCell(1));
  ASSERT_EQ(a.isAlive(),true);
  a.age(2);
  ASSERT_EQ(a.isAlive(),true);
}
TEST (Cell, agen_conway10) {
  Cell a(new ConwayCell(1));
  ASSERT_EQ(a.isAlive(),true);
  a.age(4);
  ASSERT_EQ(a.isAlive(),false);
}
TEST (Cell, agen_fredkin1) {
  Cell a(new FredkinCell());
  ASSERT_EQ(a.isAlive(),false);
  a.age(3);
  ASSERT_EQ(a.isAlive(),true);
}
TEST (Cell, agen_fredkin2) {
  Cell a(new FredkinCell());
  ASSERT_EQ(a.isAlive(),false);
  a.age(0);
  ASSERT_EQ(a.isAlive(),false);
}
TEST (Cell, agen_fredkin3) {
  Cell a(new FredkinCell());
  ASSERT_EQ(a.isAlive(),false);
  a.age(1);
  ASSERT_EQ(a.isAlive(),true);
}
TEST (Cell, agen_fredkin4) {
  Cell a(new FredkinCell());
  ASSERT_EQ(a.isAlive(),false);
  a.age(2);
  ASSERT_EQ(a.isAlive(),false);
}
TEST (Cell, agen_fredkin5) {
  Cell a(new FredkinCell());
  ASSERT_EQ(a.isAlive(),false);
  a.age(4);
  ASSERT_EQ(a.isAlive(),false);
}
TEST (Cell, agen_fredkin6) {
  Cell a(new FredkinCell(1));
  ASSERT_EQ(a.isAlive(),true);
  a.age(3);
  ASSERT_EQ(a.isAlive(),true);
}
TEST (Cell, agen_fredkin7) {
  Cell a(new FredkinCell(1));
  ASSERT_EQ(a.isAlive(),true);
  a.age(0);
  ASSERT_EQ(a.isAlive(),false);
}
TEST (Cell, agen_fredkin8) {
  Cell a(new FredkinCell(1));
  ASSERT_EQ(a.isAlive(),true);
  a.age(1);
  ASSERT_EQ(a.isAlive(),true);
}
TEST (Cell, agen_fredkin9) {
  Cell a(new FredkinCell(1));
  ASSERT_EQ(a.isAlive(),true);
  a.age(2);
  ASSERT_EQ(a.isAlive(),false);
}
TEST (Cell, agen_fredkin10) {
  Cell a(new FredkinCell(1));
  ASSERT_EQ(a.isAlive(),true);
  a.age(4);
  ASSERT_EQ(a.isAlive(),false);
}
TEST (Cell, out_conway1) {
  Cell a;
  ASSERT_EQ(a.isAlive(),false);
  ostringstream out;
  out << a;
  string s(".");
  ASSERT_EQ(out.str(),s);
}
TEST (Cell, out_conway2) {
  Cell a(new ConwayCell(1));
  ASSERT_EQ(a.isAlive(),true);
  ostringstream out;
  out << a;
  string s("*");
  ASSERT_EQ(out.str(),s);
}
TEST (Cell, out_fredkin1) {
  Cell a(new FredkinCell());
  ASSERT_EQ(a.isAlive(),false);
  ostringstream out;
  out << a;
  string s("-");
  ASSERT_EQ(out.str(),s);
}
TEST (Cell, out_fredkin2) {
  Cell a(new FredkinCell(1));
  ASSERT_EQ(a.isAlive(),true);
  ostringstream out;
  out << a;
  string s("0");
  ASSERT_EQ(out.str(),s);
}
TEST (Cell, out_fredkin3) {
  Cell a(new FredkinCell(1));
  ASSERT_EQ(a.isAlive(),true);
  for(int i=0;i<15;++i)
    a.age(1);
  ostringstream out;
  out << a;
  string s("+");
  ASSERT_EQ(out.str(),s);
}
TEST (Cell, eq1) {
  Cell a;
  ASSERT_EQ(a.isAlive(),false);
  Cell b(new ConwayCell(1));
  ASSERT_EQ(b.isAlive(),true);
  ASSERT_EQ(a == b, false);
}
TEST (Cell, eq2) {
  Cell a;
  ASSERT_EQ(a.isAlive(),false);
  Cell b;
  ASSERT_EQ(b.isAlive(),false);
  ASSERT_EQ(a == b, true);
}
TEST (Cell, eq3) {
  Cell a(new ConwayCell(1));
  ASSERT_EQ(a.isAlive(), true);
  Cell b(new ConwayCell(1));
  ASSERT_EQ(b.isAlive(), true);
  ASSERT_EQ(a == b, true);
}
TEST (Cell, eq4) {
  Cell a(new ConwayCell(1));
  ASSERT_EQ(a.isAlive(), true);
  Cell b;
  ASSERT_EQ(b.isAlive(), false);
  ASSERT_EQ(a == b, false);
}
TEST (Cell, ne1) {
  Cell a;
  ASSERT_EQ(a.isAlive(), false);
  Cell b(new ConwayCell(1));
  ASSERT_EQ(b.isAlive(), true);
  ASSERT_EQ(a != b, true);
}
TEST (Cell, ne2) {
  Cell a;
  ASSERT_EQ(a.isAlive(), false);
  Cell b;
  ASSERT_EQ(b.isAlive(), false);
  ASSERT_EQ(a != b, false);
}
TEST (Cell, ne3) {
  Cell a(new ConwayCell(1));
  ASSERT_EQ(a.isAlive(), true);
  Cell b(new ConwayCell(1));
  ASSERT_EQ(b.isAlive(), true);
  ASSERT_EQ(a != b, false);
}
TEST (Cell, ne4) {
  Cell a(new ConwayCell(1));
  ASSERT_EQ(a.isAlive(), true);
  Cell b;
  ASSERT_EQ(b.isAlive(), false);
  ASSERT_EQ(a != b, true);
}

