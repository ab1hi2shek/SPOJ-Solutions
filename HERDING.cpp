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
#define MAXM 1005

vector<string> arr;
int visited[MAXM][MAXM];



ll dfs(ll x, ll y, ll val)
{
	//cout<<" x = "<<x<<" y = "<<j<<" val = "<<val<<endl;
	if(visited[x][y] != 0)
	{
		if(visited[x][y] == val)
			return 1;
		else
			return 0;
	}
	visited[x][y] = val;

	if(arr[x][y] =='S')
		return dfs(x+1,y, val);
	else if(arr[x][y] =='N')
		return dfs(x-1,y, val);
	else if(arr[x][y] =='E')
		return dfs(x,y+1,val);
	else if(arr[x][y] =='W')
		return dfs(x,y-1,val);
}

int main()
{
	std::ios::sync_with_stdio(false);
	ll r,c;
	cin>>r>>c;

	memset(visited, 0, sizeof(visited));
	loop(i,0,r-1)
	{
		string s;
		cin>>s;
		arr.push_back(s);
	}

	ll val = 1;
	ll ans = 0;
	loop(i,0,r-1)
	{
		loop(j,0,c-1)
		{
			if(!visited[i][j])
			{
				ans += dfs(i,j,val++);
			}
		}
	}
	cout<<ans<<endl;

	return 0;
}