#include <bits/stdc++.h>
using namespace std;
 
//data types
#define ll int
 
//stl
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

#define MAXM 10005

vector<pii > adj[MAXM];
map<string,int> mapping;
bool visited[MAXM];
vector<int> dist(MAXM);

void dijkstra(ll source, ll n)
{
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push(make_pair(0,source));
	for(ll i=0;i<MAXM;i++)
		dist[i] = INT_MAX;
	dist[source] = 0;

	while(!pq.empty())
	{
		ll v = pq.top().second;
		pq.pop();
		visited[v] = true;

		for(int i=0;i<adj[v].size();i++)
		{
			ll wt = adj[v][i].first;
			ll temp = adj[v][i].second;
			if(!visited[temp] && dist[temp] > dist[v] + wt){
				dist[temp] = dist[v] + wt;
				pq.push(make_pair(dist[temp], temp));
			}
		}
	}
	//return dist[destn];
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
		mapping.clear();
		for(ll i=0;i<MAXM;i++)
			adj[i].clear();

		for(ll i=0;i<n;i++)
		{
			string s;
			cin>>s;
			mapping[s] = i;

			ll p;
			cin>>p;

			while(p--)
			{
				ll x,wt;
				cin>>x>>wt;
				adj[i].push_back(make_pair(wt,x-1));
			}
		}

		// for(ll i=0;i<5;i++)
		// {
		// 	cout<<i<<" = ";
		// 	for(ll j=0;j<adj[i].size();j++)
		// 	{
		// 		cout<<adj[i][j].first<<" "<<adj[i][j].second<<endl;
		// 	}
		// 	cout<<" ########### ";
		// }

		ll r;
		cin>>r;

		while(r--)
		{
			string a,b;
			cin>>a>>b;

			ll indexA = mapping[a];
			ll indexB = mapping[b];

			dijkstra(indexA,n);

			memset(visited,false,sizeof(visited));
			//cout<<indexA<<" "<<indexB<<endl;

			cout<<dist[indexB]<<endl;
		}
	}
	return 0;
}