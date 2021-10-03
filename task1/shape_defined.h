//this header defines what is a proper shape
//first, find out about basic shapes' existence

#include "basic_shapes.h"

//in addition to the shape itself, we also need enum data on its type
//get it from enum to str header

#include "enum_to_str.h"

//need math for volumes

#include<math.h>

//all set up for defining a shape, lets get it

struct shape {
	enum shapeType type;
	float dens;
	float vol;
	union {
		struct sphere s;
		struct paral p;
		struct tetra t;
	};
};

float volumeSphere(int r) {
	return 4 * 3.14 * pow(r,3) / 3;
}

float volumeParal(int a, int b, int c) {
	return a * b * c;
}

float volumeTetra(int a) {
	return pow(2,0.5) * pow(a,3) / 12;
}

float volume(struct shape *sp) {
	switch (sp->type) {
		case SPHERE:
			return volumeSphere(sp->s.radius);
		case PARAL:
			return volumeParal(sp->p.a, sp->p.b, sp->p.c);
		case TETRA:
			return volumeTetra(sp->t.a);
		default:
			return 0.0;
	}
	return 0.0;
}




