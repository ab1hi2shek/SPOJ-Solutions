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
#define MAXM 100005


ll in[26];
ll out[26];
vi adj[26];
bool visited[26];

void isConnected(ll source)
{
	visited[source] = true;

	for(ll i=0; i<adj[source].size(); i++)
	{
		if(!visited[adj[source][i]])
			isConnected(adj[source][i]);
	}
}

bool isConnectedUtil()
{
	ll x = 0, y = -1;
	ll i=0;
	while(i <= 25)
	{
		if(in[i] - out[i] > 0)
		{
			x = i;
			break;
		}
		if(in[i] != 0)
			y = i;
		i++;
	}
	if(i==26)
		x = y;
	isConnected(x);
	loop(i,0,25)
	{
		if(!visited[i])
			return false;
	}

	return true;
}

bool hasEulerPath()
{
	if(!isConnectedUtil())
		return false;
	ll x = 0, y = 0;
	loop(i,0,25)
	{
		if(in[i] - out[i] == 1)
			x++;
		else if(out[i] - in[i] == 1)
			y++;
		else if(in[i] != out[i])
			return false;
	}

	if(x+y==0 || (x==1 && y==1))
		return true;
	return false;
}

int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin>>t;

	while(t--)
	{
		loop(i,0,25)
		{
			in[i] = out[i] = 0;
			visited[i] = true;
			adj[i].clear();
		}
		ll n;
		cin>>n;

		loop(i,0,n-1)
		{
			string s;
			cin>>s;
			
			ll u = s[0] - 'a';
			ll v = s[s.size() - 1] - 'a';	
			in[u] ++;
			out[v]++;
			adj[u].push_back(v);
			visited[u] = visited[v] = false;
		}
		if(hasEulerPath())
			cout<<"Ordering is possible.\n";
		else
		 	cout<<"The door cannot be opened.\n";
	}
	return 0;
}