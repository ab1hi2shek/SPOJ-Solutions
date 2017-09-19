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
#define ll int
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
#define MAXN 1005
#define MAXLEVEL 18

vector<ll> adj[MAXN];
int depth[MAXN];
int sparse[MAXN][MAXLEVEL];
int parent[MAXN];

void dfs(int curr, int prev, int dep)
{
	parent[curr] = prev;
	depth[curr] = dep;
	sparse[curr][0] = prev;

	for(int i=0; i<adj[curr].size(); i++)
	{
		if(adj[curr][i] != prev)
			dfs(adj[curr][i], curr, dep+1);
	}
}

void preprocessSparse(int n)
{
	loop(j,1,MAXLEVEL-1)
	{
		loop(i,1,n)
		{
			if(sparse[i][j-1] != -1)
				sparse[i][j] = sparse[sparse[i][j-1]][j-1];
		}
	}
}

int lca(int u, int v)
{
	if(depth[u] > depth[v])
		swap(u,v);

	int diff = depth[v] - depth[u];

	//step - 1
	while(diff > 0)
	{
		int x = log(diff);
		v = sparse[v][x];
		diff -= (1<<x);
	}

	if(u == v)
		return u;

	//step - 2
	for(int i=MAXLEVEL-1; i>=0;i--)
	{
		if(sparse[u][i] != sparse[v][i])
		{
			u = sparse[u][i];
			v = sparse[v][i];
		}
	}

	return parent[u];
}

 
int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	scanf("%d", &t);
	ll p = 1;
	while(t--)
	{
		loop(i,0,MAXN)
			adj[i].clear();
		ll n;
		scanf("%d", &n);

		loop(i,0,n-1)
		{
			ll size;
			scanf("%d", &size);

			while(size--)
			{
				ll x;
				scanf("%d", &x);
				adj[i+1].push_back(x);
			}
		}

		memset(sparse, -1, sizeof(sparse));
		dfs(1,-1,1);
		preprocessSparse(n);

		printf("Case %d:\n", p);
		p += 1;
		ll q;
		scanf("%d", &q);

		while(q--)
		{
			ll a,b;
			scanf("%d%d", &a, &b);

			cout<<lca(a,b)<<endl;
		}
	}
}