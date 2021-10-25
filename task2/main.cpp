//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию, 
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cstdlib> // для функций rand() и srand()
#include <cstring>
#include <chrono>

#include "container.h"

using namespace std::chrono;

void errMessage1() {
    cout << "Error: invalid command line!\n"
            "  Expected:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n";
}

void errMessage2() {
    cout << "Error: invalid mode!\n"
            "  Expected:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n";
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    if(argc != 5) {
        errMessage1();
        return 1;
    }
	auto start = high_resolution_clock::now();
    cout << "Start"<< endl;
    Container c;

    ////cout << "argv[1] = " << argv[1] << "\n";
    if(!strcmp(argv[1], "-f")) {
		cout << "Input from file start." << endl;
        ifstream ifst(argv[2]);
        c.In(ifst);
		cout << "Input from file done." << endl;
    }
    else if(!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if((size < 1) || (size > 10000)) { 
            cout << "incorrect numer of figures = "
                 << size
                 << ". Set 0 < number <= 10000\n";
            return 3;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел
        c.InRnd(size);
    }
    else {
        errMessage2();
        return 2;
    }

    // Первая часть задания: вывод в первый файл собранного контейнера и суммы объемов
    ofstream ofst1(argv[3]);
    ofst1 << "Filled container:\n";
    c.Out(ofst1);
	ofst1 << "Volume sum = " << c.Volume() << "\n";

    // Вторая часть задания: сортировка контейнера пузырьком по возрастанию объемов
	//и вывод во второй файл
    ofstream ofst2(argv[4]);
	c.BubbleSort();
    ofst2 << "Bubble Sorted container:\n";
	c.Out(ofst2);

    cout << "Stop"<< endl;
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Execution took " << duration.count() << " microseconds" << endl;
    return 1;
}
