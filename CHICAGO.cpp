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
typedef pair<ll,double> pii;
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
#define MAXM 105

double INF = -1000000007;

vector<pii> adj[MAXM];

double dijkstra(ll source, ll n)
{
	double dist[n+1];
	loop(i,1,n)
		dist[i] = INF;

	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push(make_pair(100,source));
	dist[source] = 100;

	while(!pq.empty())
	{
		ll curr = pq.top().second;
		pq.pop();

		for(ll i=0; i<adj[curr].size(); i++)
		{
			double wt = adj[curr][i].first;
			ll now = adj[curr][i].second; 
			if(dist[now] < (dist[curr] * wt) / 100)
			{
				dist[now] = (dist[curr] * wt) / 100;
				pq.push(make_pair(dist[now], now));
			}
		}
	}

	return dist[n];
}

int main()
{
//	std::ios::sync_with_stdio(false);
	ll n;

	while(1)
	{
		scanf("%lld", &n);
		if(n==0)
			break;
		loop(i,0,MAXM-1)
			adj[i].clear();
		ll e;
		scanf("%lld", &e);
		loop(i, 0, e-1)
		{
			ll x,y;
			double p;
			scanf("%lld%lld%lf", &x, &y, &p);
			adj[x].push_back(make_pair(p,y));
			adj[y].push_back(make_pair(p,x));
		}

		printf("%.6f percent\n", dijkstra(1, n));
	}
	return 0;
}