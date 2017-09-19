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
#define INFT 1000000007

vector<pii > adj[MAXM];

ll dijkstra(ll source, int destination, int n)
{
	bool visited[n+1];
	ll dist[n+1];
	memset(visited, false, sizeof(visited));
	loop(i,0,n)
		dist[i] = INFT;

	// loop(i,0,10)
	// 	cout<<dist[i]<<" ";
	// cout<<endl;

	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push(make_pair(0,source));
	dist[source] = 0;

	while(!pq.empty())
	{
		ll node = pq.top().second;
		pq.pop();
		visited[node] = true;

		for(ll i=0; i<adj[node].size(); i++)
		{
			ll wt = adj[node][i].first;
			ll curr = adj[node][i].second;

			if(!visited[curr] && dist[curr] > dist[node] + wt)
			{
				dist[curr] = dist[node]+wt;
				pq.push(make_pair(dist[curr], curr));
			}
		}
	}


	// loop(i,0,10)
	// 	cout<<dist[i]<<" ";
	// cout<<endl;

	return dist[destination];
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;

	while(t--)
	{
		loop(i,0,MAXM-1)
			adj[i].clear();
		ll n,m,s,e;
		cin>>n>>m>>s>>e;

		while(m--)
		{
			ll a,b,c;
			cin>>a>>b>>c;
			adj[a].push_back(make_pair(c,b));
			adj[b].push_back(make_pair(c,a));
		}

		ll ans = dijkstra(s,e,n);
		if(ans == INFT)
			cout<<"NONE"<<endl;
		else
			cout<<ans<<endl;
	}
	return 0;
}