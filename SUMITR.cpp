#include <iostream>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		int v[n][n], dp[n][n], ans=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0; j<= i; j++)
			{
				cin>>v[i][j];
				if(i==0)
					dp[i][j] = v[i][j];
				else if(j==0)
					dp[i][j] = dp[i-1][j];
				else if(j==i)
					dp[i][j] = dp[i-1][j-1];
				else
					dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]);
				if(i!=0)
					dp[i][j] += v[i][j];
			}
		}
		for(int i=0;i<n;i++)
			ans = max(dp[n-1][i], ans);
		cout<<ans<<endl;
	}
}