#include <cstdio>
#include <string>
#include <cstring> 

using namespace std;

const int MOD = 1000000;
const int MAX = 1000 + 1;

int N;
int dp[MAX][MAX][3][2];
int fullAttendance(int days, int attend, int absent, int late)
{
	if (absent == 3 || late == 2)
		return 0;
	if (days == N) 
		return 1;
	int &result = dp[days][attend][absent][late];
	if (result != -1)
		return result;

	result = fullAttendance(days + 1, attend + 1, 0, late) + fullAttendance(days + 1, attend, absent + 1, late) + fullAttendance(days + 1, attend, 0, late + 1);
	result %= MOD; 
	return result;
}
int main(void)
{
	scanf("%d",&N);
	memset(dp, -1, sizeof(dp));
	printf("%d",fullAttendance(0, 0, 0, 0) % MOD);
	return 0;
}