/*
	Code By - Abhishek Kumar
	College - NIT Durgapur
	Date - 13/09/2017
	Logic -	BFS
	Category - Medium
	Platform - SPOJ
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
#define MAXM 20005

ll parent[MAXM];
ll value[MAXM];

vector<ll> modifiedBFS(ll n)
{
	queue<ll> q;
	q.push(1);
	parent[1] = 0;

	while(!q.empty())
	{
		ll currEle = q.front();
		q.pop();

		if(currEle%n == 0)
		{
			vector<ll> v;
			//cout<<parent[currEle]<<endl;
			while(parent[currEle])
			{
				v.push_back(value[currEle]);
				currEle = parent[currEle];
			}
			v.push_back(1);
			reverse(v.begin(), v.end());
			return v;
		}

		ll temp = (currEle*10) % n;
		if(parent[temp] == -1)
		{
			q.push(temp);
			parent[temp] = currEle;
			value[temp] = 0;
		}

		temp = (currEle*10 + 1) % n;
		if(parent[temp] == -1)
		{
			q.push(temp);
			parent[temp] = currEle;
			value[temp] = 1;
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
		memset(parent, -1, sizeof(parent));
		ll n;
		cin>>n;

		vector<ll> ans;
		ans = modifiedBFS(n);
		for(ll i=0;i<ans.size(); i++)
			cout<<ans[i];
		cout<<endl;
	}
}