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
#define MAXM 10005

vector<pii> adj[MAXM];
bool visited[MAXM];

ll prims(ll source)
{
	ll dist[MAXM];
	loop(i,0,MAXM-1)
		dist[i] = 1000000007;

	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push(make_pair(0, source));
	dist[source] = 0;

	ll count = 0;
	while(!pq.empty())
	{
		ll node = pq.top().second;
		ll pku = pq.top().first;
		pq.pop();
		if(visited[node])
			continue;
		count += pku;
		//cout<<"hahah " <<count<<" nodeba = "<<node<<endl;

		
		visited[node] = true;

		for(ll i=0;i<adj[node].size();i++)
		{
			ll wt = adj[node][i].first;
			ll curr = adj[node][i].second;

			if(!visited[curr] && dist[curr] > wt)
			{
				dist[curr] = wt;
				pq.push(make_pair(wt,curr));
			}
		}
	}

	return count; 
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

		memset(visited, false, sizeof(visited));
		loop(i,0,n)
			adj[i].clear();

		loop(i,0,n-1)
		{
			string s;
			cin>>s;
			ll k;
			cin>>k;
			while(k--)
			{
				ll a,b;
				cin>>a>>b;

				adj[i+1].push_back(make_pair(b,a));
			}
		}

		cout<<prims(1)<<endl;
	}
}