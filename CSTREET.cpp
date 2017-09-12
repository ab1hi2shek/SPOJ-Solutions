#include <bits/stdc++.h>
using namespace std;

/** PRIMS ALGO */
/*
#define MAXM 1005
typedef pair<int, int> pii;
bool marked[MAXM];
vector<pii> adj[MAXM];

int prim(int source)
{
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	int minCost = 0;
	pii temp_pair;

	pq.push(make_pair(0,source));

	while(!pq.empty())
	{
		temp_pair = pq.top();
		pq.pop();

		source = temp_pair.second;

		if(marked[source]==true)
			continue;
		marked[source] = true;
		minCost += temp_pair.first;

		for(int i=0;i<adj[source].size();i++)
		{
			int y = adj[source][i].second;

			if(marked[y]==false)
				pq.push(adj[source][i]);
		}
	}
	return minCost;
}

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int p,v,e;
		cin>>p>>v>>e;

		for(int i=0;i<e;i++){
			int x,y,wt;
			cin>>x>>y>>wt;
			adj[x].push_back(make_pair(wt,y));
			adj[y].push_back(make_pair(wt,x));
		}

		cout<<prim(1)*p<<endl;   //taking 1 as the source vetrex

	}	
	return 0;
}

*/
#define MAXM 1005

vector<pair<int, pair<int,int> > > edges;
vector<int> v(MAXM);
vector<int> size(MAXM);

void initialize()
{
	for(int i=0;i<MAXM;i++){
		v[i] = i;
		size[i] = 1;
	}
}

int root(int i)
{
	while(v[i] != i)
	{
		v[i] = v[v[i]];
		i = v[i];
	}
	return i;
}

void unionFind(int x, int y)
{
	int rootX = root(x);
	int rootY = root(y);

	if(size[rootX] < size[rootY])
	{
		v[rootX] = v[rootY];
		size[rootY] += size[rootX];
	}
	else
	{
		v[rootY] = v[rootX];
		size[rootX] += size[rootY];
	}
}

int kruskal(int n)
{
	int ans = 0;
	initialize();

	int i = 0;
	int k = 0;
	while(i<n-1)
	{
		int par_x = root(edges[k].second.first);
		int par_y = root(edges[k].second.second);

		if(par_x != par_y)
		{
			unionFind(par_x, par_y);
			ans += edges[k].first;
			i++;
		}
		k++; 
	}
	return ans;
}

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int p,v,e;
		cin>>p>>v>>e;

		for(int i=0;i<e;i++)
		{
			int x,y,wt;
			cin>>x>>y>>wt;
			edges.push_back(make_pair(wt,make_pair(x,y)));
		}

		sort(edges.begin(), edges.end());
		cout<<kruskal(v)*p<<endl;
	}
}