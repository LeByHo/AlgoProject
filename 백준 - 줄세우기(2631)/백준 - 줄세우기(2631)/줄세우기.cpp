#include <iostream>
using namespace std;

int n;
int arr[201] = { 0, };
int D[201] = { 0, };

int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		D[i] = 1;
		for (int j = 1; j <= i; j++) {
			if (arr[j]<arr[i] && D[j] + 1>D[i]) {
				D[i] = D[j] + 1;
			}
		}
	}
	int max = -1;
	for (int i = 1; i <= n; i++) {
		if (max == -1 || max < D[i]) {
			max = D[i];
		}
	}
	cout << n - max << endl;

	return 0;
}
