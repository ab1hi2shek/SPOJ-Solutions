/*
	CODE BY - ABHISHEK KUMAR
			  NIT DURGAPUR
*/

#include <bits/stdc++.h>
using namespace std;
 
//data types
#define ll long long
#define ull unsigned long long
 
//stl
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> pii;
typedef map<ll,ll> mpll;
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
#define M0D 1000000007
#define MAXM 55

struct node{
	ll wt;
	ll val;
};

node arr[MAXM];
ll dp[MAXM][20*MAXM];

/* recursive 
ll knapsack(ll n, ll w)
{
	if(n == 0 || w == 0)
		return 0;
	if(dp[n][w]!=-1)
		return dp[n][w];
	if(arr[n-1].wt > w)
		return knapsack(n-1, w);
	else
		return dp[n][w] = max( knapsack(n-1, w), arr[n-1].val + knapsack(n-1, w - arr[n-1].wt));
}
*/

//iterative
ll knapsack(ll n, ll w)
{	
	loop(i,0,n)
	{
		loop(j,0,w)
		{
			//cout<<i<<" "<<j<<endl;
			if(i == 0 || j == 0)
				dp[i][j] = 0;
			else if(arr[i-1].wt > j)
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = max( dp[i-1][j], arr[i-1].val + dp[i-1][j - arr[i-1].wt]);
		}
	}

	return dp[n][w];
}

int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;

	while(t--)
	{
		memset(dp, -1, sizeof(dp));
		ll maxWt, n;
		cin>>maxWt>>n;

		loop(i,0,n-1)
			cin>>arr[i].wt>>arr[i].val;
		cout<<"Hey stupid robber, you can get "<<knapsack(n,maxWt)<<".\n";


	}
	return 0;
}