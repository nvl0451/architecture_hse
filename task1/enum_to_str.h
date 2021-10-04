//this file defines enums and how to turn them to string
//define enums
#include<string.h>

enum shapeType {SPHERE, PARAL, TETRA, WRONG};

//translate shapeType to string and back

char *shapeToStr(enum shapeType type) {
	char *s = NULL;
	switch (type) {
		case SPHERE:
			s = "sphere";
			break;
		case PARAL:
			s = "paral";
			break;
		case TETRA:
			s = "tetra";
			break;
		default:
			break;
	}
	return s;
}

enum shapeType strToShape(char s[]) {
	if (strcmp(s, "sphere") == 0) {
		return SPHERE;
	}
	if (strcmp(s, "paral") == 0) {
		return PARAL;
	}
	if (strcmp(s, "tetra") == 0) {
		return TETRA;
	}
	return WRONG;
}

// variation on shapeToStr for output - with full shape names for user convenience
char *shapeToStrFull(enum shapeType type) {
	char *s = NULL;
	switch (type) {
		case SPHERE:
			s = "sphere";
			break;
		case PARAL:
			s = "rectangular parallelepiped";
			break;
		case TETRA:
			s = "regular tetrahedron";
			break;
		default:
			break;
	}
	return s;
}
