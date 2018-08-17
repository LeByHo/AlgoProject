#include <iostream>

using namespace std;

int main(void)
{
	int C, C1;

	int m[100][1000];
	float aver[1000];
	float total[1000] = { 0, };
	float cnt[1000];
	cin >> C;
	cout << fixed;
	cout.precision(3);

	for (int i = 0; i < C; ++i) {
		float count = 0.0;
		cin >> C1;
		for (int j = 0; j < C1; ++j) {
			cin >> m[i][j];
			total[i] += m[i][j];
		}
		aver[i] = total[i] / (float)C1;
		for (int j = 0; j < C1; ++j)
			if (m[i][j] > aver[i])
				count++;
		cnt[i] = count / C1 * 100;
	}

	for (int i = 0; i < C; ++i)
		cout << cnt[i] << "%" << endl;


	return 0;




}