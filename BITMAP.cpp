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
#define MAXN 250

ll dist[MAXN][MAXN];

void bfs( pair<ll,ll> p, int n, int m)
{
	queue<pair<ll,ll> > q;

	q.push(p);

	while(!q.empty())
	{
		ll i = q.front().first;
		ll j = q.front().second;

		q.pop();

		if(i+1 < n && dist[i+1][j] > 1 + dist[i][j])
		{
			dist[i+1][j] = 1 + dist[i][j];
			q.push(make_pair(i+1,j));
		}

		if(i-1 >=0 && dist[i-1][j] > 1 + dist[i][j])
		{
			dist[i-1][j] = 1 + dist[i][j];
			q.push(make_pair(i-1,j));
		}

		if(j+1 < m && dist[i][j+1] > 1 + dist[i][j])
		{
			dist[i][j+1] = 1 + dist[i][j];
			q.push(make_pair(i,j+1));
		}

		if(j-1 >= 0 && dist[i][j-1] > 1 + dist[i][j])
		{
			dist[i][j-1] = 1 + dist[i][j];
			q.push(make_pair(i,j-1));
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;

	while(t--)
	{
		ll n,m;
		cin>>n>>m;

		vector<pair<ll,ll> > v;

		for(ll i=0;i<n;i++)
		{
			string s;
			cin>>s;

			for(ll j=0;j<m;j++)
			{
				dist[i][j] = LONG_MAX - 1000;
				ll a = s[j]-'0';

				if(a==1)
				{
			//		cout<<"i = "<<i<<" j = "<<j<<endl;
					dist[i][j] = 0;
					v.push_back(make_pair(i,j));
				}
			}
		}

		for(ll i=0;i<v.size();i++)
			bfs(v[i],n,m);

		for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<m;j++)
				cout<<dist[i][j]<<" ";
			cout<<endl;
		}

	}

	return 0;
}