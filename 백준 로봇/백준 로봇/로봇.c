#include<stdio.h>
#include<string.h>
#include<math.h>
int main(void) {
	char string[5];
	int n, m,count=0, state =0,x=0,y=0;
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %d", &string, &count);
		if (strcmp(string, "TURN") == 0){
			if (count == 0)
				state++ ;
			else if(count == 1)
				state-- ;
			if (state < 0)
				state = 4 + state;
			if (state > 3)
				state = state % 4;	
		}
		else {
			switch (state) {
			case 0:
				x = x + count;
				break;
			case 1:
				y = y + count;
				break;
			case 2:
				x = x - count;
				break;
			case 3:
				y = y - count;
				break;
			default:
				break;
			}
		}
		if (x<0 || y<0 || x>m || y>m) {
			printf("-1");
			exit(0);
		}
	}
		printf("%d %d", x, y);
	return 0;
}