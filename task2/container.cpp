//------------------------------------------------------------------------------
// container.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"
#include <iostream>
#include <algorithm>

//------------------------------------------------------------------------------
// Конструктор контейнера
Container::Container(): len{0} { }

//------------------------------------------------------------------------------
// Деструктор контейнера
Container::~Container() {
    Clear();
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Container::Clear() {
    for(int i = 0; i < len; i++) {
        delete storage[i];
    }
    len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void Container::In(ifstream &ifst) {
    while(!ifst.eof()) {
        if((storage[len] = Shape::StaticIn(ifst)) != 0) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void Container::InRnd(int size) {
    while(len < size) {
        if((storage[len] = Shape::StaticInRnd()) != nullptr) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Container::Out(ofstream &ofst) {
    ofst << "Container of " << len << " elements.\n";
    for(int i = 0; i < len; i++) {
        ofst << i << ": ";
        storage[i]->Out(ofst);
    }
}

//------------------------------------------------------------------------------
// Вычисление суммы объемов всех фигур в контейнере
double Container::Volume() {
    double sum = 0.0;
    for(int i = 0; i < len; i++) {
        sum += storage[i]->vol;
    }
    return sum;
}

//------------------------------------------------------------------------------
// Сортировка пузырьком по возрастанию объемов всех фигур в контейнере
void Container::BubbleSort() {
	int iter1, iter2;
	Shape* tempShape;
	for (iter1 = 0; iter1 < len - 1; iter1++) {
		for (iter2 = 0; iter2 < len - iter1 - 1; iter2++) {
			if (storage[iter2]->vol > storage[iter2 + 1]->vol) {
				//tempShape = storage[iter2];
				//storage[iter2] = storage[iter2 + 1];
				//storage[iter2 + 1] = tempShape;
				std::swap(storage[iter2], storage[iter2 + 1]);
			}
		}
	}
}
