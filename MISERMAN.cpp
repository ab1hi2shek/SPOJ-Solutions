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
 
int main()
{
	std::ios::sync_with_stdio(false);
	ll n,m;
	cin>>n>>m;

	if(n==0 || m==0)
	{
		cout<<"0"<<endl;
		return 0;
	}

	ll arr[n][m];
	ll sum = 0;
	loop(i,0,n-1)
	{
		loop(j,0,m-1)
		{
			cin>>arr[i][j];
			sum += arr[i][0];
		}
	}

	if(m==1)
	{
		cout<<sum<<endl;
		return 0;
	}

	ll dp[n][m];
	loop(i,0,m-1)
		dp[0][i] = arr[0][i];

	loop(i,1,n-1)
	{
		loop(j,0,m-1)
		{
			if(j==0)
				dp[i][j] = arr[i][j] +  min(dp[i-1][j], dp[i-1][j+1]);
			else if(j==m-1)
				dp[i][j] = arr[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
			else
				dp[i][j] = arr[i][j] + min(dp[i-1][j-1], min(dp[i-1][j], dp[i-1][j+1]));
		}
	}

	ll minm = dp[n-1][0];
	loop(i,1,m-1)
		minm = min(minm, dp[n-1][i]);

	// loop(i,0,n-1)
	// {
	// 	loop(j,0,m-1)
	// 		cout<<dp[i][j]<<" ";
	// 	cout<<endl;
	// }

	cout<<minm<<endl;
	return 0;
}