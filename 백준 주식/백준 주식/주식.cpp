#include <iostream>
#define MAX 1000000
using namespace std;

long long A[MAX], Sub_Sum[MAX];
long long D[MAX][2], Profit, Current;

int cmp(const void *pa, const void *pb) {
	const long long *v1 = reinterpret_cast<const long long *>(pa);
	const long long *v2 = reinterpret_cast<const long long *>(pb);
	return v1[0] < v2[0];
}

int main() {
	int T, N;

	cin >> T;
	while (T > 0) {
		cin >> N;
		cin >> A[0];
		Sub_Sum[0] = A[0];
		D[0][0] = A[0], D[0][1] = 0;
		Profit = 0;

		for (int i = 1; i < N; ++i) {
			cin >> A[i];
			Sub_Sum[i] = Sub_Sum[i - 1] + A[i];
			D[i][0] = A[i], D[i][1] = i;
		}

		qsort(D, N, sizeof(long long) * 2, cmp);

		// Initial Profit
		Profit = D[0][0] * D[0][1] - Sub_Sum[D[0][1]] + D[0][0];
		Current = D[0][1];
		for (int i = 1; i < N; ++i) {
			if (D[i][1] > Current) {
				Profit += (D[i][0] * (D[i][1] - Current) - (Sub_Sum[D[i][1]] - Sub_Sum[Current]));
				Current = D[i][1];
			}
		}
		cout << Profit << endl;
		--T;
	}
}