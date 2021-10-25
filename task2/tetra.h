#ifndef __tetra__
#define __tetra__

//------------------------------------------------------------------------------
// tetra.h - содержит описание правильного тетраэдра
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"
#include "shape.h"

//------------------------------------------------------------------------------
// тетраэдр
class Tetra: public Shape {
public:
    virtual ~Tetra() {}
    // Ввод параметров тетраэдра из файла
    virtual void In(ifstream &ifst);
    // Случайный ввод параметров тетраэдра
    virtual void InRnd();
    // Вывод параметров тетраэдра в форматируемый поток
    virtual void Out(ofstream &ofst);
    // Вычисление периметра тетраэдра
    virtual double Volume();
private:
    int a; // сторона
	double dens; //плотность
};

#endif //__tetra__
