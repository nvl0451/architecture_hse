//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию, 
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <iostream>
#include "shape_atd.h"


//------------------------------------------------------------------------------

namespace simple_shapes {
	shape* In();
	void Out(shape &s);
}
using namespace std;
using namespace simple_shapes;

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
//------------------------------------------------------------------------------

  int const max_len = 100; // максимальная длина
  struct container
  {
    int len; // текущая длина
    shape *cont[max_len];
  };

//------------------------------------------------------------------------------

int main()
{
	container c;
	//  Init(c);
	c.len = 0;

	// In(c);
    cout 
      << "Do you want to input next shape (yes=\'y\', no=other character)? " 
      << endl;
    char k;
    cin >> k;
    while(k == 'y')
    {
      cout << c.len << ": ";
      if((c.cont[c.len] = In()) != 0)
      {
        c.len++;
      }

      cout 
        << "Do you want to input next shape (yes=\'y\', no=other character)? " 
        << endl;
      cin >> k;
    }

	// Out(c);
    cout << "Container contents " << c.len << " elements." << endl;
    for(int i = 0; i < c.len; i++) {
      cout << i << ": ";
      Out(*(c.cont[i]));
    }

	// Clear(c);
    for(int i = 0; i < c.len; i++)
    {
      delete c.cont[i];
    }
    c.len = 0;
    return 0;
}
