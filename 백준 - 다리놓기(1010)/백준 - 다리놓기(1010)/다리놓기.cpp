#include <cstdio>
using namespace std;
 
int main(){
    int T,N,M;
    scanf("%d",&T);
    
    for(int i=0;i<T;i++){
        scanf("%d %d",&N,&M);
        
        int dp[31][31]={0};
        
        for(int j=1;j<=M;j++)
            dp[1][j]=j;
        
        for(int n=2;n<=N;n++){
            for(int m=1;m<=M;m++){
                for(int k=n-1;k<m;k++)
                    dp[n][m]+=dp[n-1][k];
            }
        }
        
        printf("%d\n",dp[N][M]);
    }
    return 0;
}