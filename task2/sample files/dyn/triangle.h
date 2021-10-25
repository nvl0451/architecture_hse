#ifndef __triangle__
#define __triangle__

//------------------------------------------------------------------------------
// triangle.h - содержит описание треугольника
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"
#include "shape.h"

//------------------------------------------------------------------------------
// треугольник
class Triangle: public Shape {
public:
    virtual ~Triangle() {}
    // Ввод параметров треугольника из файла
    virtual void In(ifstream &ifst);
    // Случайный ввод параметров треугольника
    virtual void InRnd();
    // Вывод параметров треугольника в форматируемый поток
    virtual void Out(ofstream &ofst);
    // Вычисление периметра треугольника
    virtual double Perimeter();
private:
    int a, b, c; // стороны
};

#endif //__triangle__
