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
#define all(c) (c).rbegin(),(c).rend()
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
#define MAXM 105

/*
	Algo - Topological sort
	method 1 - using modified DFS
*/

stack<int> s;
bool visited[MAXM];
vi  adj[MAXM];

void dfs(ll source)
{
	visited[source] = true;

	for(ll i=0; i<adj[source].size(); i++)
	{
		if(!visited[adj[source][i]])
			dfs(adj[source][i]);
	}

	s.push(source);
}

int main()
{
	std::ios::sync_with_stdio(false);
	ll n,m;
	cin>>n>>m;

	loop(i,0,m-1)
	{
		ll a,k;
		cin>>a>>k;

		while(k--)
		{
			ll b;
			cin>>b;
			adj[b].push_back(a);
		}
	}

	loop(i,1,n)
		sort(all(adj[i]));

	memset(visited, false, sizeof(visited));
	for(ll i=n; i>0; i--)
	{
		if(!visited[i])
			dfs(i);
	}

	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}

	return 0;
}