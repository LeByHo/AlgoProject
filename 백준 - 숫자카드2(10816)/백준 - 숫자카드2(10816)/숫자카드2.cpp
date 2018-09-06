#include<cstdio>
#include<algorithm>
using namespace std;
int number[500000];
int N;
long long flag = 0;

void confirm(int i, int left, int right, int mid) {
	if (left > right)
		return;
	if (number[mid]==i){
		//printf("%d ", (upper_bound(number, number + (N - 1), i) - number + 1));
		//printf("%d ", (lower_bound(number, number + (N - 1), i) - number ));
		flag= (upper_bound(number, number + N , i) - number+1) - (lower_bound(number, number + N , i) - number)-1;
	}
	else {
		if (number[mid] > i)
			confirm(i, left, mid - 1, (left + mid) / 2);
		else if(number[mid]<i)
			confirm(i, mid + 1, right, (right + mid) / 2 + 1);
		
	}
}
int main() {
	int M, num;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &number[i]);
	}
	sort(number, number + N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &num);
		flag = 0;
		confirm(num, 0, N - 1, N / 2);
		printf("%d ", flag);
	}
}