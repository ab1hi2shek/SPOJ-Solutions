#include <bits/stdc++.h>
using namespace std;
 
//data types
#define ll long long int
#define ull unsigned long long int
#define l long int
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

ll dp[99][13];

void init()
{
	for(ll i=0;i<99;i++)
		dp[i][0] = 0;
	for(ll i=0;i<13;i++)
		dp[0][i] = 1;

	for(ll i=1;i<99;i++)
	{
		for(ll j=1;j<13;j++)
		{
			dp[i][j] = 0;
			ll m = i;
			ll len = 0;

			while(m >= 0 && len<j)
			{
				dp[i][j] += dp[m][j-1];
				m--;
				len++; 
			}
		}
	}

	// loop(i,0,5)
	// {
	// 	loop(j,0,5)
	// 		cout<<dp[i][j]<<" ";
	// 	cout<<endl;
	// }
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;
	init();
	while(t--)
	{
		ll n,k;
		cin>>n>>k;

		cout<<dp[k][n]<<endl;
	}
}