#include<stdio.h>
#include<string.h>
#include<math.h>
int main(void) {
	int x = 0, y = 0, c_x = 0, c_y = 0, test, state=0,ma_x=0,ma_y=0,mi_x=0,mi_y=0;
	char move[501];
	scanf("%d", &test);
	for (int i = 0; i < test; i++) {
		scanf("%s", move);
		state = 0;
		c_x = 0; c_y = 0;
		x = 0; y = 0;
		ma_x = 0; ma_y = 0; mi_x = 0; mi_y = 0;
		for (int j = 0; j < strlen(move); j++) {
			if (state < 0)
				state = state + 4;
			if (state > 3)
				state = state % 4;
			
			switch (move[j])
			{
			case 'F': 
				if (state == 0) {
					y++;
					c_y = 1;
					if (ma_y < y)
						ma_y = y;
					
				}
				else if (state == 1) {
					x++;
					c_x = 1;
					if (ma_x < x)
						ma_x = x;
				}
				else if (state == 2) {
					y--;
					c_y = 1;
					if (mi_y > y)
						mi_y = y;
				}
				else if (state == 3) {
					x--;
					c_x = 1;
					if (mi_x > x)
						mi_x = x;
				}
				break;
			case 'B' :
				if (state == 0) {
					y--;
					c_y = 1;
					if (mi_y > y)
						mi_y = y;
					
				}
				else if (state == 1) {
					x--;
					c_x = 1;
					if (mi_x > x)
						mi_x = x;
				}
				else if (state == 2) {
					y++;
					c_y = 1;
					if (ma_y < y)
						ma_y = y;

				}
				else if (state == 3) {
					x++;
					c_x = 1;
					if (ma_x < x)
						ma_x = x;
				}
				break;
			case 'R':
				state++;
				break;
			case 'L':
				state--;
				break;
			default:
				break;
			}
		}
		
		if (c_x == 0 || c_y == 0)
			printf("0\n");
		else
			printf("%d\n", (ma_x+abs(mi_x))*(ma_y+abs(mi_y)));
	}

	return 0;
}