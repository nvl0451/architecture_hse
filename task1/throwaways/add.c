#include<stdio.h>
#include "add.h"

int main() {
	int a,b;
	scanf("%d %d", &a, &b);
	printf("%d", add(a,b));
}