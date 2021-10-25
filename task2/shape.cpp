//------------------------------------------------------------------------------
// shape.cpp - содержит процедуры связанные с обработкой обобщенной фигуры
// и создания произвольной фигуры
//------------------------------------------------------------------------------

#include "sphere.h"
#include "tetra.h"
#include "paral.h"

//------------------------------------------------------------------------------
Random Shape::rnd100(1, 100);
Random Shape::rnd3(1,3);

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из файла
Shape* Shape::StaticIn(ifstream &ifst) {
    int k;
    ifst >> k;
    Shape* sp = nullptr;
    switch(k) {
        case 1:
            sp = new Tetra;
            break;
        case 2:
            sp = new Paral;
            break;
		case 3:
            sp = new Sphere;
            break;
    }
    sp->In(ifst);
    return sp;
}

// Случайный ввод обобщенной фигуры
Shape *Shape::StaticInRnd() {
    auto k = Shape::rnd3.Get();
    Shape* sp = nullptr;
    switch(k) {
        case 1:
            sp = new Tetra;
            break;
        case 2:
            sp = new Paral;
            break;
		case 3:
            sp = new Sphere;
            break;
    }
    sp->InRnd();
    return sp;
}
