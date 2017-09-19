/*
	Code By - Abhishek Kumar
	College - NIT Durgapur
	Date -	14/09/2017
	Logic -	DP-Tree-DFS
	Category - Medium
	Platform - SPOJ
*/	  

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
#define MAXM 100005

vector<ll> adj[MAXM];
ll dp[MAXM][2];
ll comp = 1;

void modifiedDFS(ll source, ll parent)
{
	dp[source][1] = 1;

	for(ll i=0; i<adj[source].size(); i++)
	{
		ll temp = adj[source][i];
		if(temp == parent)
			continue;

		modifiedDFS(temp, source);

		dp[source][1] += min(dp[temp][0], dp[temp][1]);
		dp[source][0] += dp[temp][1];
	}
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	memset(dp,0,sizeof(dp));
	ll n;
	cin>>n;

	for(ll i=1;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;

		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	modifiedDFS(1,0);
	ll ans = min(dp[1][0], dp[1][1]);
	cout<<max(comp,ans)<<endl;
}