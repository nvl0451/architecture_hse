#ifndef __rectangle__
#define __rectangle__

//------------------------------------------------------------------------------
// rectangle.h - содержит описание прямоугольника  и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"
#include "shape.h"

// прямоугольник
class Rectangle: public Shape {
public:
    virtual ~Rectangle() {}
    // Ввод параметров прямоугольника из файла
    virtual void In(ifstream &ifst);
    // Случайный ввод параметров прямоугольника
    virtual void InRnd();
    // Вывод параметров прямоугольника в форматируемый поток
    virtual void Out(ofstream &ofst);
    // Вычисление периметра прямоугольника
    virtual double Perimeter();
private:
    int x, y; // ширина, высота
};

#endif //__rectangle__
