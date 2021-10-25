#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "shape.h"

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
class Container {
public:
    Container();
    ~Container();

    // Ввод содержимого контейнера из указанного потока
    void In(ifstream &ifst);
    // Случайный ввод содержимого контейнера
    void InRnd(int size);
    // Вывод содержимого контейнера в указанный поток
    void Out(ofstream &ofst);
    // Вычисление суммы объемов всех фигур в контейнере
    double Volume();
	//сортировка пузырьком по возрастанию
	void BubbleSort();
private:
	int len; // текущая длина
    Shape* storage[10000];
    void Clear();    // Очистка контейнера от данных
};

#endif
