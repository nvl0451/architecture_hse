#ifndef __sphere__
#define __sphere__

//------------------------------------------------------------------------------
// sphere.h - содержит описание сферы
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"
#include "shape.h"

//------------------------------------------------------------------------------
// сфера
class Sphere: public Shape {
public:
    virtual ~Sphere() {}
    // Ввод параметров сферы из файла
    virtual void In(ifstream &ifst);
    // Случайный ввод параметров сферы
    virtual void InRnd();
    // Вывод параметров сферы в форматируемый поток
    virtual void Out(ofstream &ofst);
    // Вычисление объема сферы
    virtual double Volume();
private:
    int radius; // радиус
	double dens; //плотность
};

#endif //__sphere__
