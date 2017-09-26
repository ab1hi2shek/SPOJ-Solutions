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
#define MAXM 50010

vector<pair<ll,ll> > adj[MAXM];

ll dikstra(ll source, ll n, ll flag)
{
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	bool visited[MAXM];
	ll dist[MAXM];
	memset(visited, false, sizeof(visited));
	memset(dist, 1000000007, sizeof(dist));

	pq.push(make_pair(0, source));
	dist[source] = 0;

	while(!pq.empty())
	{
		ll node = pq.top().second;
		visited[node] = true;
		pq.pop();

		for(ll i=0; i<adj[node].size(); i++)
		{
			ll curr = adj[node][i].second;
			ll wt = adj[node][i].first;

			if(dist[curr] > wt + dist[node])
			{
				dist[curr] = wt + dist[node];
				pq.push(make_pair(dist[curr], curr));
			}
		}
	}

	ll ans = 1;
	loop(i,2,n)
	{
		if(dist[i] > dist[ans])
			ans = i;
	}
	if(flag)
		ans = dist[ans];
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;

	while(t--)
	{
		ll n;
		cin>>n;
		loop(i,0,MAXM-1)
			adj[i].clear();
		loop(i,1,n-1)
		{
			ll a,b,c;
			cin>>a>>b>>c;

			adj[a].push_back(make_pair(c,b));
			adj[b].push_back(make_pair(c,a));
		};

		cout<<dikstra(dikstra(1, n, 0), n, 1)<<endl;

	}
	return 0;
}