#include <cstdio> 
#include <cstring> 
#include <algorithm> 
#include <cmath>
using namespace std; 
int dp[1005][1005][2];
int arr[1005]; 
int n, m; 
int solve(int a, int b, int c) { 
	if(a == 0 && b == n) 
		return 0; 
	if(a < 0 || b > n) 
		return 1000000007; 
	int &ret = dp[a][b][c];
	if(ret != -1)
		return ret; 
	ret = 1000000007; 
	int cnt = n - (b-a); 
	if(c == 0){ 
		ret = min(solve(a-1,b,0) +cnt*abs(arr[a]-arr[a-1]), solve(a,b+1,1) +cnt*abs(arr[a]-arr[b+1]));
	}
	else{ 
		ret = min(solve(a-1,b,0) +cnt*abs(arr[b]-arr[a-1]), solve(a,b+1,1) +cnt*abs(arr[b]-arr[b+1]));
	} 
	return ret;
} 
int main() {
	memset(dp, -1, sizeof dp);
	scanf("%d %d", &n, &m);
	arr[0] = m;
	int temp = 0; 
	for(int i=1;i<=n;i++){ 
		scanf("%d", &temp); 
		arr[i] = temp;
	}
	sort(arr, arr+n+1); 
	int index;
	for(int i=0;i<=n;i++){ 
		if(arr[i] == m) 
			index = i; 
	} 
	printf("%d\n", solve(index,index,0)); 
	return 0; 
}
