#include <bits/stdc++.h>
using namespace std;
 
//data types
#define ll long long int
#define ull unsigned long long int
// #define l long int
#define ul unsigned long int
 
//stl
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> pii;
typedef map<ll,ll> mpll;
#define sz(a) (a).size()
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
 
//loops
#define loop(i,a,b) for(ll i=a;i<=b;i++)
#define loopr(i,a,b) for(ll i=a;i>=b;i--)
 
//others
#define isPowerOfTwo(S) !(S & (S - 1))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define nline cout<<endl
 
int main()
{
	std::ios::sync_with_stdio(false);
	ll n;
	ll dp[105][105], sum[105][105];
	while(cin>>n)
	{
		ll arr[n];
		for(ll i=0;i<n;i++)
			cin>>arr[i];

		for(ll i=0;i<n;i++)
		{
			sum[i][i] = arr[i];
			for(ll j=i+1;j<n;j++)
				sum[i][j] = (sum[i][j-1] + arr[j])%100;
		}

		for(ll i=n-1; i>=0; i--)
		{
			dp[i][i] = 0;

			for(ll j=i+1; j<n; j++)
			{
				dp[i][j] = INT_MAX;
				for(ll k=i;k<j;k++)
				{
					ll val = dp[i][k] + dp[k+1][j] + (sum[i][k]*sum[k+1][j]);
					dp[i][j] = min(dp[i][j], val);
				}
			}
		}
		cout<<dp[0][n-1]<<endl;		
	}
	return 0;
}