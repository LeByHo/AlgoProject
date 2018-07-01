/*#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> h;
int max_S = 0;

void cal(int a, int b) {
	int min_s, size_s, index;
	min_s = *min_element(h.begin() + a, h.begin() + b);
	size_s = min_s * (b - a);
	if (max_S < size_s) {
		max_S = size_s;
	}
	for (int i = a; i < b; i++) {
		if (min_s == h[i]) {
			index = i;
			break;
		}
	}
	if (a != index)
		cal(a, index);
	if (b != index + 1)
		cal(index + 1, b);
}

int main() {
	int N, height;
	scanf("%d", &N);
	for (int i = 0; i<N; i++) {
		scanf("%d", &height);
		h.push_back(height);
	}
	cal(0, N);
	printf("%d", max_S);
}*/

#include<cstdio>
#include <stack>
using namespace std;

int h[100000];

int main(void)
{
	int n;
	scanf("%d", &n);
	stack<int> s;
	for (int i = 0; i < n; i++)
		scanf("%d", &h[i]);
	int area = 0, height, width;
	for (int i = 0; i < n; i++) {
		while (!s.empty() && h[s.top()] > h[i]) {
			height = h[s.top()];
			s.pop();
			width = i;
			if (!s.empty())
				width = i - s.top() - 1;
			if (width*height > area)
				area = width * height;
		}
		s.push(i);
	}

	while (!s.empty()) {
		height = h[s.top()];
		s.pop();
		width = n;
		if (!s.empty()) 
			width = n - s.top() - 1;
		if (width*height > area)
			area = width * height;
	}
	printf("%d", area);
	return 0;
}
