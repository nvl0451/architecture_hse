//------------------------------------------------------------------------------
// shape_In.cpp - содержит процедуру ввода параметров 
// дл€ уже созданной любой фигуры
//------------------------------------------------------------------------------

#include <iostream>
#include "shape_atd.h"

//------------------------------------------------------------------------------

using namespace std;

namespace simple_shapes {

//------------------------------------------------------------------------------


  // ¬вод параметров обобщенной фигуры из стандартного потока ввода
  shape* In()
  {
    shape *sp;
    cout << "Input key: for Rectangle is 1, for Triangle is 2, else break: ";
    int k;
    cin >> k;
    switch(k) {
    case 1:
      sp = new shape;
      sp->k = RECTANGLE;
      // In(sp->r);
      cout << "Input Rectangle: x, y = ";
      cin >> sp->r.x >> sp->r.y;
      return sp;
    case 2:
      sp = new shape;
      sp->k = TRIANGLE;
      // In(sp->t);
	  cout << "Input Triangle: a, b, c = ";
	  cin >> sp->t.a >> sp->t.b >> sp->t.c;
      return sp;
    default:
      return 0;
    }
  }

//------------------------------------------------------------------------------

} // end simple_shapes namespace
