//------------------------------------------------------------------------------
// triangle_Out.cpp - �������� ��������� 
// ������ ���������� ������������
//------------------------------------------------------------------------------

#include <iostream>
#include "triangle_atd.h"

//------------------------------------------------------------------------------

using namespace std;

namespace simple_shapes {

//------------------------------------------------------------------------------

  // ����� ���������� ������������
  void Out(triangle &t)
  {
    cout << "It is Triangle: a = " 
      << t.a << ", b = " << t.b
      << ", c = " << t.c << endl;
  }

//------------------------------------------------------------------------------

} // end simple_shapes namespace