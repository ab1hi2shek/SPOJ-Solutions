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
#define MAXM 105

vi adj[MAXM];
vector<ll> ans;

void kahnAlgo(ll n)
{
	vi inDegree(n+1, 0);
	for(ll i=1; i<=n; i++)
	{
		for(ll j=0; j<adj[i].size(); j++)
			inDegree[adj[i][j]]++;
	}

	priority_queue<ll, vi, greater<ll> > q;
	for(ll i=1; i<=n; i++)
	{
		if(!inDegree[i])
			q.push(i);
	}

	while(!q.empty())
	{
		ll curr = q.top();
		ans.push_back(curr);
		q.pop();

		for(ll i=0;i<adj[curr].size();i++)
		{
			if(--inDegree[adj[curr][i]] == 0)
				q.push(adj[curr][i]);

		}
	}
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

	// loop(i,1,n-1)
	// 	sort(all(adj[i]));

	kahnAlgo(n);

	for(ll i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	cout<<endl;

	return 0;
}