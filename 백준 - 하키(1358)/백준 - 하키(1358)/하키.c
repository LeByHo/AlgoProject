#include <stdio.h>
#include<math.h>
int w, h, x, y, p;

int main() {
	int px, py,count=0;
	scanf("%d %d %d %d %d",&w,&h,&x,&y,&p);

	for (int i = 0; i < p; i++) {
		scanf("%d %d", &px, &py);
		if (px >= x && px <= x + w) {
			if (py >= y && py <= y + h)
				count++;
			else
				continue;
		}
		else if (px < x) {
			if (sqrt(pow(px - x, 2) + pow(py - (y + h / 2), 2) )<= h/2)
				count++;
			else
				continue;
		}
		else if (px > x + w) {
			if (sqrt(pow(px -(x+w), 2) + pow(py - (y+h/2), 2) )<= h / 2)
				count++;
			else
				continue;
		}
	}
	printf("%d", count);
	return 0;
}