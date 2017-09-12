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
#define MAXM 105

vector<pii> adj[MAXM];

ll dijkstra(ll vertex, ll time, ll source)
{
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	vector<ll> dist(vertex+1,INT_MAX);
	vector<bool> visited(vertex+1,false);

	pq.push(make_pair(0,source));
	dist[source] = 0;

	while(!pq.empty())
	{
		ll v = pq.top().second;
		pq.pop();
		visited[v] = true;

		for(ll i=0;i<adj[v].size(); i++)
		{
			ll temp = adj[v][i].second;
			ll wt = adj[v][i].first;

			if(visited[temp] == false && dist[temp] > dist[v] + wt)
			{
				dist[temp] = dist[v] + wt;
				pq.push(make_pair(dist[temp], temp));
			}
		}
	}

	ll count = 0;
	for(ll i=1;i<=vertex;i++)
	{
		if(dist[i] <= time)
			count++;
	}
	return count;
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	for(ll i=0;i<MAXM;i++)
		adj[i].clear();
	ll vertex,source,time,edges;
	cin>>vertex>>source>>time>>edges;

	loop(i,0,edges-1)
	{
		ll x,y,wt;
		cin>>x>>y>>wt;
		adj[y].push_back(make_pair(wt,x));
	}

	cout<<dijkstra(vertex,time,source)<<endl;
	return 0;
}