/*
	Code By - Abhishek Kumar
	College - NIT Durgapur
	Date - 14/09/2017
	Logic -	tree
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
#define MAXM 1005

/*
Method 1 - right but giving WA on spoj... unable to find out the bug.
using the normal tree traversal as we do in binary tree.
*/

/*
vector<int> adj[MAXM];

int lca(int source, int a, int b)
{
 	if(source == a || source == b)
 		return source;

 	int x = -1, y = -1;
	for(int i=0; i<adj[source].size();i++)
	{
		if(x==-1)
			x = lca(adj[source][i], a, b);
		else if(y==-1)
			y = lca(adj[source][i], a, b);
	}

	if(x != -1 && y!= -1)
		return source;
	else if(x!=-1)
		return x;
	else
		return y;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;

	int p = 1;
	while(t--)
	{
		cout<<"Case "<<p++<<":"<<endl;
		int n;
		cin>>n;

		for(int i=1;i<=n;i++)
		{
			int k;
			cin>>k;

			while(k--)
			{
				ll x;
				cin>>x;
				adj[i].push_back(x);
			}
		}

		int q;
		cin>>q;
		while(q--)
		{
			int a,b;
			cin>>a>>b;

			if(a > n && b > n)
			{
				cout<<"0"<<endl;
				continue;
 			}

 			if(a>n || b>n)
 			{
 				cout<<"-1"<<endl;
 				continue;
 			}

 			if(a==b)
 			{
 				cout<<a<<endl;
 				continue;
 			}

 			cout<<lca(1,a,b)<<endl;
 		}
 	}
 }

 */

/*
Method 2 - using marking of parents.
Pass on spoj but with O(NQ) time complexity
*/

/*
int parent[MAXM];
int visited[MAXM];

int lca(int a, int b, int n)
{
	loop(i,1,n)
		visited[i] = 0;

	visited[a] = 1;

	while(parent[a] != a)
	{
		visited[a] = 1;
		a = parent[a];
	}
	visited[a] = 1;
	while(visited[b] != 1)
		b = parent[b];

	return b;
}

int main()
{
	int t;
	cin>>t;
	int p = 1;
	while(t--)
	{
		cout<<"Case "<<p++<<":"<<endl;
		int n;
		cin>>n;
		loop(i,1,n)
			parent[i] = i;

		for(ll i=1;i<=n;i++)
		{
			int s;
			cin>>s;

			while(s--)
			{
				int a;
				cin>>a;
				parent[a] = i;
			}
		}

		int q;
		cin>>q;

		while(q--)
		{
			int a,b;
			cin>>a>>b;

			cout<<lca(a,b,n)<<endl;
		}
	}
}
*/

/*
Method 3 - using pressprocessing  - making parent and level array and then bringing th two nodes to the same
level
Pass on SPOJ with O(Q*log(N)) approach
*/

int depth[MAXM];
int parent[MAXM];
int p[MAXM];

vector<int> adj[MAXM];

void dfs(int curr, int prev)
{
	parent[curr] = prev;
	depth[curr] = depth[prev] + 1;
	for(int i=0;i<adj[curr].size();i++)
	{
		if(adj[curr][i] != prev)
			dfs(adj[curr][i], curr);
	}
}

void traverse(int node, int head, int prev_sec)
{
	int curr_sec = sqrt(depth[node]) + 1;
	if(curr_sec == 1)
		p[node] = 1;
	else
	{
		if(curr_sec == prev_sec + 1)
		{
			p[node] = parent[node];
			head = node;
		}
		else
			p[node] = parent[head];
	}

	for(int i=0;i<adj[node].size(); i++)
	{
		if(adj[node][i] != parent[node])
			traverse(adj[node][i], head, curr_sec);
	}
}

int lca(int u, int v)
{
	while(p[u] != p[v])
	{
		if(depth[u] > depth[v])
			u = p[u];
		else
			v = p[v];
	}

	while(u != v)
	{
		if(depth[u] > depth[v])
			u = parent[u];
		else
			v = parent[v];
	}
	return u;
}

int main()
{
	int t;
	cin>>t;
	int pk = 1;
	while(t--)
	{
		cout<<"Case "<<pk++<<":"<<endl;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int s;
			cin>>s;
			while(s--)
			{
				int a;
				cin>>a;
				adj[i].push_back(a);
			}
		}

		depth[0] = -1;
		dfs(1,0);
		traverse(1,1,-1);
		int q;
		cin>>q;
		while(q--)
		{
			int a,b;
			cin>>a>>b;
			cout<<lca(a,b)<<endl;
		}
	}
}