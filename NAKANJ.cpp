/*
	Code By - Abhishek Kumar
	College - NIT Durgapur
	Date - 12/09/2017
	Logic -	Bfs...Graph
	Category - Easy-Medium
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

ll X[8] = {-2,-1,1,2,2,1,-1,-2};
ll Y[8] = {1,2,2,1,-1,-2,-2,-1};
bool visited[9][9];

ll bfs(ll sx, ll sy, ll dx, ll dy)
{
	memset(visited, false, sizeof(visited));

	queue<pair<int,int> > Q;
	Q.push(make_pair(sx,sy));
	Q.push(make_pair(-1,-1));

	visited[sx][sy] = true;
	ll ans = 0;

	while(!Q.empty())
	{
		ll vx = Q.front().first;
		ll vy = Q.front().second;
		Q.pop();

		if(vx == dx && vy == dy)
			return ans;
		if(vx == -1 && vy == -1 && !Q.empty())
		{
			Q.push(make_pair(-1,-1));
			ans++;
		}
		visited[vx][vy] = true;

		for(ll i=0;i<8;i++)
		{
			ll p = vx + X[i];
			ll q = vy + Y[i];

			if(p>=1 && p<=8 && q>=1 && q<=8 && visited[p][q] == false)
				Q.push(make_pair(p,q));	
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
		string a,b;
		cin>>a>>b;

		ll sx,sy,dx,dy;
		sx = (a[0] - 'a') + 1;
		sy = (a[1] - '0');
		dx = (b[0] - 'a') + 1;
		dy = b[1] - '0';

		cout<<bfs(sx,sy,dx,dy)<<endl; 
	}
	return 0;
}