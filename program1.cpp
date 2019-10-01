#include <iostream>
#include "classes.h"
#include <vector>

using namespace classes;

int main(){
	float c;
	int længde = 8, højde = 8;

	Liste a(2);
	a.setTal(2.0f, 1);
	a.setTal(1.0f, 0);
	c = a.getTal(1);
	printf("%f \n", c);
	c = a.getTal(0);
	printf("%f \n", c);

	Liste b(2);
	b.setTal(4.0f, 1);
	b.setTal(3.0f, 0);
	c = b.getTal(1);
	printf("%f \n", c);
	c = b.getTal(0);
	printf("%f \n", c);

	Liste d(a+b);
	c = d.getTal(1);
	printf("%f \n", c);
	c = d.getTal(0);
	printf("%f \n", c);

	Box f = Box(d);

	Box boxes[8][8];
	for (int i = 0; i < højde; i++) {
		for (int j = 0; j < længde; j++) {
			Liste a(2);
			float y = (float)(i % højde);
			float x = (float)(j % længde);
			a.setTal(x, 0);
			a.setTal(y, 1);

			boxes[j][i] = Box(a);

		}
	}

	for (int i = 0; i < højde; i++) {
		char field[8];
		for (int j = 0; j < længde; j++) {
			if (boxes[j][i].getSnakeBool()) {
				field[j] = 's';
			}
		}
		for (int i = 0; i < længde; i++) {
			printf("%c", field[i]);
		}
		printf("\n");
	}


	return 0;
}