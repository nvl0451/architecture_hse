#ifndef __paral__
#define __paral__

//------------------------------------------------------------------------------
// paral.h - содержит описание параллелипипеда  и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"
#include "shape.h"

// параллелипипед
class Paral: public Shape {
public:
    virtual ~Paral() {}
    // Ввод параметров параллелипипеда из файла
    virtual void In(ifstream &ifst);
    // Случайный ввод параметров параллелипипеда
    virtual void InRnd();
    // Вывод параметров параллелипипеда в форматируемый поток
    virtual void Out(ofstream &ofst);
    // Вычисление объема параллелипипеда
    virtual double Volume();
private:
    int x, y, z; // ширина, высота, длина
	double dens; //плотность
};

#endif //__paral__
