/*
	Code By - Abhishek Kumar
	College - NIT Durgapur
	Date -
	Logic -
	Category - 
	Platform
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
bool visited[MAXM];

void dfs(ll source)
{
	visited[source] = true;

	for(ll i=0;i<adj[source].size();i++)
	{
		if(!visited[adj[source][i]])
			dfs(adj[source][i]);
	}
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;

	while(t--)
	{
		ll n,e;
		cin>>n>>e;

		memset(visited, false, sizeof(visited));
		loop(i,0,n)
			adj[i].clear();

		while(e--)
		{
			ll a,b;
			cin>>a>>b;

			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		ll count = 0;
		loop(i,0,n-1)
		{
			if(!visited[i])
			{
				dfs(i);
				count++;
			}
		}
		cout<<count<<endl;
	}
}