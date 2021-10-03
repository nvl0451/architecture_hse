#include <stdio.h>

struct point {
	int x, y;
};

struct triangle {
	struct point p1, p2, p3;
};

bool collinear(struct point p1, p2, p3) {
	return (p1.y - p2.y) * (p1.x - p3.x) == (p1.y - p3.y) * (p1.x - p2.x);
}

int main() {
	printf("lets roll bitch\n");
	int a, b;
	struct point dot1, dot2, dot3;
	struct triangle triangle;
	
	printf("input point 1\n");
	scanf("%d %d", &a, &b);
	dot1.x = a;
	dot1.y = b;
	
	printf("input point 2\n");
	scanf("%d %d", &a, &b);
	dot2.x = a;
	dot2.y = b;
	
	printf("input point 3\n");
	scanf("%d %d", &a, &b);
	dot3.x = a;
	dot3.y = b;
	
	printf("crafting triangle\n");
	triangle.p1 = dot1;
	triangle.p2 = dot2;
	triangle.p3 = dot3;
	printf("crafted triangle with dots: (%d, %d), (%d, %d), (%d, %d)",
	triangle.p1.x, triangle.p1.y, triangle.p2.x, triangle.p2.y,
	triangle.p3.x, triangle.p3.y);
	return 0;
}